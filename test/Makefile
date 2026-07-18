MPI_ABI_STUBS = $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/..)
MPI_ROOT = $(MPI_ABI_STUBS)
PREFIX = $(MPI_ROOT)
BINDIR = bin
LIBDIR = lib

MPICC = $(PREFIX)/$(BINDIR)/mpicc
RPATH = $(PREFIX)/$(LIBDIR)

CC = $(MPICC)
LDFLAGS = -Wl,-rpath,$(RPATH)

.PHONY: default
default: build test clean

.PHONY: build
build: mpi-version

.PHONY: test
test: build
	./mpi-version

.PHONY: clean
clean:
	-${RM} mpi-version
	-${RM} -r build install
