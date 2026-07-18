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
    set -- -DCMAKE_INSTALL_RPATH_USE_LINK_PATH=TRUE "$@"
fi

rm -rf build install
cmake -B build --install-prefix="$(pwd)"/install "$@"
cmake --build build --config Release
cmake --install build --config Release

export LD_LIBRARY_PATH="$PREFIX/$LIBDIR"
install/bin/mpi-version
