#!/bin/bash
set -euo pipefail

prefix=${PREFIX:-$PWD}
export PATH=${prefix}/bin:$PATH

case "$(uname)" in
    Linux)
        lib="lib"
        so=".so"
        ;;
    Darwin)
        ldd () { otool -L "$1"; }
        lib="lib"
        so=".dylib"
        ;;
    *_NT-*)
        lib=""
        so=".dll"
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
echo "$(mpicc -show-libdir)/$lib$(mpicc -show-libs)$so":
ldd "$(mpicc -show-libdir)/$lib$(mpicc -show-libs)$so"

set -x

mpicc -show
mpicc -show-incdir
mpicc -show-libdir
mpicc -show-libs
for cc in gcc clang; do
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
mpicxx -show-libs
for cxx in g++ clang++; do
    "$cxx" -v  > cxx.log 2>&1
    mpicxx -cxx="$cxx" -v  > mpicxx.log 2>&1
    diff cxx.log mpicxx.log
    mpicxx -cxx="$cxx" ./helloworld.cxx -c
    test -f helloworld.o && rm helloworld.o
    mpicxx -cxx="$cxx" ./helloworld.cxx -o hw.exe
    ldd hw.exe && rm hw.exe
done
