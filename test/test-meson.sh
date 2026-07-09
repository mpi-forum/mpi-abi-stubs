#!/bin/sh
set -eu

: "${MPI_ABI_STUBS:=$(realpath "$PWD"/..)}"
: "${MPI_ROOT:=$MPI_ABI_STUBS}"

export PATH="$MPI_ROOT"/bin:"$PATH"

if [ "$(uname)" = "Darwin" ]; then
    set -- -Dinstall_rpath="$MPI_ROOT"/lib "$@"
fi

rm -rf build install
meson setup build --prefix="$PWD"/install "$@"
meson compile -C build
meson install -C build

export LD_LIBRARY_PATH="$MPI_ROOT"/lib
install/bin/mpi-version
