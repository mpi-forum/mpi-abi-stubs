#!/bin/bash
set -euo pipefail

topdir=$(CDPATH="" cd -- "$(dirname -- "$0")" && pwd)
: "${PREFIX:="$topdir"}"
: "${BINDIR:=bin}"

if test -d "${PREFIX}/${BINDIR}"; then
    export PATH="${PREFIX}/${BINDIR}${PATH:+:${PATH}}"
fi

abi_major=$(awk '/MPI_ABI_VERSION/{print $NF}' "$(mpicc -show-incdir)/mpi.h")

case "$(uname)" in
    Linux)
        lib="lib"
        mod=".so"
        dll=".so.$abi_major"
        ;;
    Darwin)
        ldd () { otool -L "$1"; }
        lib="lib"
        mod=".dylib"
        dll=".$abi_major.dylib"
        ;;
    *_NT-*)
        command -v ldd >/dev/null 2>&1 || ldd() { test -f "$1"; }
        lib=""
        mod=".lib"
        dll=".dll"
        ;;
esac

tempdir="$(mktemp -d)"
trap 'rm -rf $tempdir' EXIT
cd "$tempdir" || exit

cat > helloworld.c << EOF
#include <mpi.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
  int size, rank, len;
  char name[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(name, &len);
  printf("Hello, World! I am process %d of %d on %s.\n", rank, size, name);
  MPI_Finalize();
  return 0;
}
EOF
ln -s helloworld.c helloworld.cxx

command -v mpicc
command -v mpicxx
echo "$(mpicc -show-incdir)/mpi.h":
grep -E 'MPI_(SUB)?VERSION' "$(mpicc -show-incdir)/mpi.h"
grep -E 'MPI_ABI_(SUB)?VERSION' "$(mpicc -show-incdir)/mpi.h"
ls  "$(mpicc -show-libdir)/$lib$(mpicc -show-libs)$mod"
echo "$(mpicc -show-rpath)/$lib$(mpicc -show-libs)$dll":
ldd  "$(mpicc -show-rpath)/$lib$(mpicc -show-libs)$dll"

RPATH="$(mpicc -show-rpath)"
export LD_LIBRARY_PATH="${RPATH}${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}"
export DYLD_LIBRARY_PATH="${RPATH}${DYLD_LIBRARY_PATH:+:${DYLD_LIBRARY_PATH}}"

set -x

mpicc -show
mpicc -show-incdir
mpicc -show-libdir
mpicc -show-bindir
mpicc -show-rpath
mpicc -show-libs
for cc in gcc clang; do
    command -v "$cc" || continue
    "$cc" -v > cc.log 2>&1
    mpicc -cc="$cc" -v > mpicc.log 2>&1
    diff cc.log mpicc.log
    mpicc -cc="$cc" ./helloworld.c -c
    test -f helloworld.o && rm helloworld.o
    mpicc -cc="$cc" ./helloworld.c -o hw.exe
    ldd hw.exe && rm hw.exe
done

mpicxx -show
mpicxx -show-incdir
mpicxx -show-libdir
mpicxx -show-bindir
mpicxx -show-rpath
mpicxx -show-libs
for cxx in g++ clang++; do
    command -v "$cxx" || continue
    "$cxx" -v  > cxx.log 2>&1
    mpicxx -cxx="$cxx" -v  > mpicxx.log 2>&1
    diff cxx.log mpicxx.log
    mpicxx -cxx="$cxx" ./helloworld.cxx -c
    test -f helloworld.o && rm helloworld.o
    mpicxx -cxx="$cxx" ./helloworld.cxx -o hw.exe
    ldd hw.exe && rm hw.exe
done
