#!/bin/sh
set -eu
prefix="${PREFIX:-$PWD}"
cmake -B build -DCMAKE_INSTALL_PREFIX="$prefix"
cmake --build build
cmake --install build
(cd "$prefix" && test -d lib64 && ln -f -s lib64 lib) || true
