project(
  'mpi-stubs',
  'c',
  version: '5.0',
  license: 'MIT',
  meson_version: '>=1.0.0',
)

fs = import('fs')
prefix = get_option('prefix')
bindir = get_option('bindir')
includedir = get_option('includedir')
libdir = get_option('libdir')
prog_dirs = {
  'includedir':
    fs.is_absolute(includedir) ?
    includedir : prefix / includedir,
  'libdir':
    fs.is_absolute(libdir) ?
    libdir : prefix / libdir,
}
prog_vars = {
  'mpicc': {
    'CC': 'CC',
    'cc': 'cc',
    'op': 'cc',
  },
  'mpicxx': {
    'CC': 'CXX',
    'cc': 'c++',
    'op': 'cxx',
  },
}
foreach script: ['mpicc', 'mpicxx']
  configure_file(
    input: 'mpicc.in',
    configuration: prog_dirs + prog_vars[script],
    output: script,
    install: true,
    install_dir: bindir,
    install_mode: 'rwxr-xr-x',
  )
  install_symlink(
    script + '_abi',
    pointing_to : script,
    install_dir : bindir,
  )
endforeach

install_headers(
  'mpi.h'
)

library(
  'mpi_abi',
  'mpistubs.c',
  version: '0',
  install : true,
)
