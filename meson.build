project(
  'mpi-stubs',
  'c',
  version: '5.0',
  license: 'MIT',
  meson_version: '>=1.1.0',
)

source_h = 'mpi.h'
source_c = 'mpistubs.c'

fs = import('fs')
prefix = get_option('prefix')
bindir = get_option('bindir')
includedir = get_option('includedir')
libdir = get_option('libdir')

abi_major = -1
abi_minor = -1
foreach line : fs.read(files(source_h)).split('\n')
  if line.contains('MPI_ABI_VERSION')
    abi_major = line.strip().split(' ')[-1].to_int()
  endif
  if line.contains('MPI_ABI_SUBVERSION')
    abi_minor = line.strip().split(' ')[-1].to_int()
  endif
  if abi_major >= 1 and abi_minor >= 0
    break
  endif
endforeach
assert(abi_major >= 1, f'MPI_ABI_VERSION not found in @source_h@')
assert(abi_minor >= 0, f'MPI_ABI_SUBVERSION not found in @source_h@')

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
foreach prog: ['mpicc', 'mpicxx']
  configure_file(
    input: 'mpicc.in',
    configuration: prog_dirs + prog_vars[prog],
    output: prog,
    install: true,
    install_dir: bindir,
    install_mode: 'rwxr-xr-x',
  )
endforeach

install_headers(
  files(source_h),
)

libname = 'mpi_abi'
version = f'@abi_major@.@abi_minor@'
soversion = f'@abi_major@'
shared_library(
  libname,
  files(source_c),
  soversion: soversion,
  darwin_versions: [0, 0],
  install: true,
)

if host_machine.system() == 'darwin'
  meson.add_install_script(
    find_program('sh'),
    files('fix-dylib-id.sh'),
  )
endif
