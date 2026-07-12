#!/bin/sh
set -eu
: "${PREFIX=$PWD}"
set -- --libdir=lib "$@"
meson setup build --prefix="$PREFIX" --buildtype=release "$@"
meson compile -C build
meson install -C build
