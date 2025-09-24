#!/bin/sh
set -eu
prefix=${PREFIX:-$PWD}
meson setup build --prefix="$prefix" --buildtype=release
meson compile -C build
meson install -C build
(test -d lib64 && ln -f -s lib64 lib) || true
