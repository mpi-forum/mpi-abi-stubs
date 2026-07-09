#!/bin/sh
set -eu

: "${MPI_ABI_STUBS:=$(realpath "$PWD"/..)}"
: "${MPI_ROOT:=$MPI_ABI_STUBS}"

export PATH="$MPI_ROOT"/bin:"$PATH"

if [ "$(uname)" = "Darwin" ]; then
    set -- -DCMAKE_INSTALL_RPATH_USE_LINK_PATH=TRUE "$@"
fi

rm -rf build install
cmake -B build --install-prefix="$PWD"/install "$@"
cmake --build build --config Release
cmake --install build --config Release

export LD_LIBRARY_PATH="$MPI_ROOT"/lib
install/bin/mpi-version
