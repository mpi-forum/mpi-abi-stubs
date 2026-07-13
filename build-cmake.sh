#!/bin/sh
set -eu
: "${PREFIX=$PWD}"
set -- -DCMAKE_BUILD_TYPE=Release "$@"
set -- -DCMAKE_INSTALL_LIBDIR=lib "$@"
cmake -B build --install-prefix="$PREFIX" "$@"
cmake --build build --config Release
cmake --install build --config Release
