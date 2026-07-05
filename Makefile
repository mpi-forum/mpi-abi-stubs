# -*- mode: makefile-gmake -*-
.PHONY: default
default: install

SCRIPTS  = mpicc mpicxx
SOURCE_H = mpi.h
SOURCE_C = mpistubs.c
LIBNAME  = mpi_abi
VERSION  = 0

PREFIX = .
BINDIR = bin
INCDIR = include
LIBDIR = lib

BUILD = build

CP = cp
CP_P = $(CP) -P
LN = ln -f
LN_S = $(LN) -s
MKDIR = mkdir -p
RANLIB = ranlib

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  SED_I = sed -i
  libfilename = lib$1.so.$2
  soname = -Wl,-soname,$1
endif
ifeq ($(UNAME_S),Darwin)
  SED_I = sed -i''
  libfilename = lib$1.$2.dylib
  soname = -Wl,-install_name,@rpath/$1
endif
LIBFILE = $(call libfilename,$(LIBNAME),$(VERSION))
LIBLINK = $(subst .$(VERSION),,$(LIBFILE))

ifndef CFLAGS
  cc_std = c89
  cc_version := $(shell $(CC) --version)
  cc_is_gnu  := $(if $(findstring Free Software Foundation,$(cc_version)),1)
  ifdef cc_is_gnu
    CFLAGS  = $(if $(cc_std),-std=$(cc_std))
    CFLAGS += -pedantic -Wall -Wextra
    CFLAGS += -Wno-unused-parameter
    CFLAGS += -Wno-unreachable-code-return
  else
    CFLAGS  = $(if $(cc_std),-std=$(cc_std))
    CFLAGS += -pedantic -Weverything
    CFLAGS += -Wno-unused-parameter
    CFLAGS += -Wno-unreachable-code-return
  endif
endif

.SECONDEXPANSION: # to expand $$(@D)/.DIR

$(BUILD)/mpicc:  override CC := CC
$(BUILD)/mpicc:  override cc := cc
$(BUILD)/mpicc:  override op := cc
$(BUILD)/mpicxx: override CC := CXX
$(BUILD)/mpicxx: override cc := c++
$(BUILD)/mpicxx: override op := cxx
$(BUILD)/mpicc $(BUILD)/mpicxx : mpicc.in | $$(@D)/.DIR
	cp $< $@
	$(SED_I) -e 's:@includedir@:$(abspath $(PREFIX))/$(INCDIR):' $@
	$(SED_I) -e 's:@libdir@:$(abspath $(PREFIX))/$(LIBDIR):' $@
	$(SED_I) -e 's/@CC@/$(CC)/g' $@
	$(SED_I) -e 's/@cc@/$(cc)/g' $@
	$(SED_I) -e 's/@op@/$(op)/g' $@
$(BUILD)/mpicc_abi $(BUILD)/mpicxx_abi: | $$(@D)/.DIR
	cd $(@D) && $(LN_S) $(@F:_abi=) $(@F)

$(BUILD)/$(LIBFILE): $(SOURCE_C) $(SOURCE_H) | $$(@D)/.DIR
	$(LINK.c) -shared $(call soname,$(notdir $@)) -o $@ $<

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
scripts = $(foreach f,$(SCRIPTS),$(BUILD)/$(f))
install-scripts: $(scripts) | $(DESTBINDIR)/. $(addsuffix _abi,$(scripts))
	install -c -m 755 $^ $(DESTBINDIR)
	$(CP_P) $(addsuffix _abi,$^) $(DESTBINDIR)
install-headers: $(SOURCE_H) | $(DESTINCDIR)/.
	install -c -m 644 $^ $(DESTINCDIR)
install-library: $(BUILD)/$(LIBFILE) | $(DESTLIBDIR)/.
	install -c $^ $(DESTLIBDIR)
	cd $(DESTLIBDIR) && $(LN_S) $(LIBFILE) $(LIBLINK)

.PHONY: uninstall uninstall-scripts uninstall-headers uninstall-library
uninstall: uninstall-scripts uninstall-headers uninstall-library
uninstall-scripts:
	-$(RM) $(foreach f,$(SCRIPTS),$(DESTBINDIR)/$(f))
	-$(RM) $(foreach f,$(SCRIPTS),$(DESTBINDIR)/$(f)_abi)
uninstall-headers:
	-$(RM) $(foreach f,$(SOURCE_H),$(DESTINCDIR)/$(f))
uninstall-library:
	-$(RM) $(DESTLIBDIR)/$(LIBFILE)
	-$(RM) $(DESTLIBDIR)/$(LIBLINK)

.PHONY: clean
clean:
	-$(RM) -r build install bin include lib lib64
