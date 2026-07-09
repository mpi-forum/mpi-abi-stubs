#!/bin/sh
set -eu
prefix=${PREFIX:-$PWD}
set -- -DCMAKE_INSTALL_LIBDIR=lib "$@"
cmake -B build --install-prefix="$prefix" "$@"
cmake --build build --config Release
cmake --install build --config Release
