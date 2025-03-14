#!/bin/sh
set -eu
cmake -B build -DCMAKE_INSTALL_PREFIX="${PREFIX:-$PWD}"
cmake --build build --config Release
cmake --install build --config Release
(test -d lib64 && ln -f -s lib64 lib) || true
