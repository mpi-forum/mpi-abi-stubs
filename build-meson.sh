#!/bin/sh
set -eu
: "${PREFIX=$(pwd)}"
set -- --libdir=lib "$@"
meson setup build --prefix="$PREFIX" --buildtype=release "$@"
meson compile -C build
meson install -C build
