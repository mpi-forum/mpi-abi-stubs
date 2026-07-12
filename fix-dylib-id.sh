#!/bin/sh
set -eu
test "$(uname)" = "Darwin" || exit 0
libdir=$MESON_INSTALL_DESTDIR_PREFIX/lib
for lib in "$libdir"/lib*.*.dylib; do
    install_name_tool -id "@rpath/$(basename "$lib")" "$lib"
done
