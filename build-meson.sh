#!/bin/sh
set -eu
prefix=${PREFIX:-$PWD}
set -- --libdir=lib "$@"
meson setup build --prefix="$prefix" --buildtype=release "$@"
meson compile -C build
meson install -C build
