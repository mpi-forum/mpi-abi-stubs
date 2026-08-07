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
        linkname() { printf "lib%s.so\n" "$@"; }
        dyldname() { printf "lib%s.so.$abi_major\n" "$@"; }
        lds() { nm -PD "$1" | awk '{print $1,$2}'; }
        ldd() { command ldd "$1"; }
        ;;
    Darwin)
        linkname() { printf "lib%s.dylib\n" "$@"; }
        dyldname() { printf "lib%s.$abi_major.dylib\n" "$@" ; }
        lds() { dyld_info -exports "$1" | awk 'NR<=3{next}{print $2,$3}'; }
        ldd() { otool -L "$1"; }
        ;;
    *_NT-*)
        linkname() { printf "%s.lib\n" "$@"; }
        dyldname() { printf "%s.dll\n" "$@"; }
        if command -v nm awk >/dev/null 2>&1; then
        lds() { nm -P "$1" | awk '{print $1,$2}'; }; else
        lds() { test -f "$1"; echo "MPI_ABI_version X"; }; fi
        if command -v ldd >/dev/null 2>&1; then
        ldd() { command ldd "$1"; }; else
        ldd() { test -f "$1"; }; fi
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
command -v mpicc_abi
command -v mpicxx_abi

header="$(mpicc -show-incdir)/mpi.h"
echo "$header":
grep -E 'MPI_(SUB)?VERSION' "$header"
grep -E 'MPI_ABI_(SUB)?VERSION' "$header"

ldlib="$(mpicc -show-libdir)/$(linkname "$(mpicc -show-libs)")"
echo "$ldlib":
lds  "$ldlib" | grep -E '_?P?MPI_[A-Za-z_]+_version'

dyldlib="$(mpicc -show-rpath)/$(dyldname "$(mpicc -show-libs)")"
echo "$dyldlib":
ldd  "$dyldlib"

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
    ldd hw.exe
    rm hw.exe
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
    ldd hw.exe
    rm hw.exe
done
