# -*- mode: makefile-gmake -*-
.PHONY: default
default: install

SOURCE_H = mpi.h
SOURCE_C = mpilib.c

ABI_MAJOR := $(shell awk '/MPI_ABI_VERSION/{print $$NF}' ${SOURCE_H})
ABI_MINOR := $(shell awk '/MPI_ABI_SUBVERSION/{print $$NF}' ${SOURCE_H})
$(if $(ABI_MAJOR),,$(error MPI_ABI_VERSION not found in $(SOURCE_H)))
$(if $(ABI_MINOR),,$(error MPI_ABI_SUBVERSION not found in $(SOURCE_H)))

UNAME_S := $(shell uname -s)

PREFIX = .
BINDIR = bin
INCDIR = include
LIBDIR = lib
ifdef RELOCATABLE
  prefix = $$(CDPATH='\'''\'' cd -- "$$(dirname -- "$$0")"/.. \&\& pwd)
else
  prefix = "$(abspath $(PREFIX))"
endif
bindir = $$prefix/$(BINDIR)
incdir = $$prefix/$(INCDIR)
libdir = $$prefix/$(LIBDIR)
rpath  = $(if $(findstring _NT-,$(UNAME_S)),$$bindir,$$libdir)

BUILD = build

LN = ln -f
LN_S = $(LN) -s
MKDIR = mkdir -p
RANLIB = ranlib

LIBNAME = mpi_abi
VERSION = $(ABI_MAJOR).$(ABI_MINOR)
SOVERSION = $(ABI_MAJOR)
ifeq ($(UNAME_S),Linux)
  SED_I = sed -i
  libfilename = lib$1.so.$2
  soname = -Wl,-soname,$(notdir $1)
endif
ifeq ($(UNAME_S),Darwin)
  SED_I = sed -i''
  libfilename = lib$1.$2.dylib
  soname = -Wl,-install_name,@rpath/$(notdir $1)
  soname += -Wl,-compatibility_version,0
  soname += -Wl,-current_version,0
endif
LIBFILE = $(call libfilename,$(LIBNAME),$(SOVERSION))
LIBLINK = $(subst .$(SOVERSION),,$(LIBFILE))

ifndef CFLAGS
  cc_std = c89
  cc_version := $(shell $(CC) --version)
  cc_is_gnu  := $(if $(findstring Free Software Foundation,$(cc_version)),1)
  cc_is_llvm := $(if $(findstring clang,$(cc_version)),1)
  ifdef cc_is_gnu
    CFLAGS  = $(if $(cc_std),-std=$(cc_std))
    CFLAGS += -pedantic -Wall -Wextra -Werror
    CFLAGS += -Wno-long-long
    CFLAGS += -Wno-unused-parameter
    CFLAGS += -Wno-unreachable-code-return
  endif
  ifdef cc_is_llvm
    CFLAGS  = $(if $(cc_std),-std=$(cc_std))
    CFLAGS += -pedantic -Weverything -Werror
    CFLAGS += -Wno-long-long
    CFLAGS += -Wno-poison-system-directories
    CFLAGS += -Wno-unused-parameter
    CFLAGS += -Wno-unreachable-code-return
    CFLAGS += -Wno-unsafe-buffer-usage
  endif
endif
cc-check = $(CC) $1 -S -o /dev/null -x c /dev/null > /dev/null 2>&1
cc-option = $(shell $(call cc-check,$1) && echo "$1")
override CFLAGS += $(call cc-option,-fPIC)

.SECONDEXPANSION: # to expand $$(@D)/.DIR

SCRIPTS = mpicc mpicxx

$(BUILD)/mpicc:  override CC := CC
$(BUILD)/mpicc:  override cc := cc
$(BUILD)/mpicc:  override op := cc
$(BUILD)/mpicxx: override CC := CXX
$(BUILD)/mpicxx: override cc := c++
$(BUILD)/mpicxx: override op := cxx
$(BUILD)/mpicc $(BUILD)/mpicxx : mpicc.in | $$(@D)/.DIR
	cp $< $@
	$(SED_I) -e 's:@prefix@:$(prefix):' $@
	$(SED_I) -e 's:@bindir@:$(bindir):' $@
	$(SED_I) -e 's:@incdir@:$(incdir):' $@
	$(SED_I) -e 's:@libdir@:$(libdir):' $@
	$(SED_I) -e 's:@rpath@:$(rpath):' $@
	$(SED_I) -e 's/@CC@/$(CC)/g' $@
	$(SED_I) -e 's/@cc@/$(cc)/g' $@
	$(SED_I) -e 's/@op@/$(op)/g' $@

$(BUILD)/$(LIBFILE): $(SOURCE_C) $(SOURCE_H) | $$(@D)/.DIR
	$(LINK.c) -shared $(call soname,$@) -o $@ $<

%/.DIR :
	$(MKDIR) $(@D)
	touch $@

$(DESTDIR)$(PREFIX)/%/.:
	$(MKDIR) $@

.PHONY: build
build: $(foreach f,$(SCRIPTS),$(BUILD)/$(f))
build: $(BUILD)/$(LIBFILE)

DESTBINDIR = $(DESTDIR)$(PREFIX)/$(BINDIR)
DESTINCDIR = $(DESTDIR)$(PREFIX)/$(INCDIR)
DESTLIBDIR = $(DESTDIR)$(PREFIX)/$(LIBDIR)

.PHONY: install install-scripts install-headers install-library
install: install-scripts install-headers install-library
install-scripts: $(foreach f,$(SCRIPTS),$(BUILD)/$(f)) | $(DESTBINDIR)/.
	install -c -m 755 $^ $(DESTBINDIR)
install-headers: $(SOURCE_H) | $(DESTINCDIR)/.
	install -c -m 644 $^ $(DESTINCDIR)
install-library: $(BUILD)/$(LIBFILE) | $(DESTLIBDIR)/.
	install -c $^ $(DESTLIBDIR)
	cd $(DESTLIBDIR) && $(LN_S) $(LIBFILE) $(LIBLINK)

.PHONY: uninstall uninstall-scripts uninstall-headers uninstall-library
uninstall: uninstall-scripts uninstall-headers uninstall-library
uninstall-scripts:
	-$(RM) -r $(foreach f,$(SCRIPTS),$(DESTBINDIR)/$(f))
uninstall-headers:
	-$(RM) -r $(foreach f,$(SOURCE_H),$(DESTINCDIR)/$(f))
uninstall-library:
	-$(RM) $(DESTLIBDIR)/$(LIBFILE)
	-$(RM) $(DESTLIBDIR)/$(LIBLINK)

.PHONY: clean
clean:
	-$(RM) -r build install bin include lib
