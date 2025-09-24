#!/bin/sh
set -eu
prefix="${PREFIX:-$PWD}"
meson setup build --prefix="$prefix"
meson compile -C build
meson install -C build
(cd "$prefix" && test -d lib64 && ln -f -s lib64 lib) || true
