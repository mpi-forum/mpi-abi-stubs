#!/bin/sh
set -eu
CDPATH="" cd -- "$(dirname -- "$0")"

: "${MPI_ABI_STUBS:=$(cd .. && pwd)}"
: "${MPI_ROOT:=$MPI_ABI_STUBS}"
: "${PREFIX:=$MPI_ROOT}"
: "${BINDIR:=bin}"
: "${LIBDIR:=lib}"

export PATH="$PREFIX/$BINDIR":"$PATH"

if [ "$(uname)" = "Darwin" ]; then
    set -- -Dinstall_rpath="$PREFIX/$LIBDIR" "$@"
fi

rm -rf build install
meson setup build --prefix="$(pwd)"/install "$@"
meson compile -C build
meson install -C build

export LD_LIBRARY_PATH="$PREFIX/$LIBDIR"
install/bin/mpi-version
