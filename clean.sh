#!/bin/sh
set -eu
CDPATH="" cd -- "$(dirname -- "$0")"
rm -fr build install bin include lib
