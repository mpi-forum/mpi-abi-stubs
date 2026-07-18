project(
  'mpi-stubs',
  'c',
  version: files('VERSION'),
  license: 'MIT',
  meson_version: '>=1.1.0',
)

source_h = get_option('source_h')
source_c = get_option('source_c')

fs = import('fs')

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

prefix = get_option('prefix')
bindir = get_option('bindir')
includedir = get_option('includedir')
libdir = get_option('libdir')
if get_option('relocatable')
  d_prefix = '$(CDPATH=\'\' cd -- "$(dirname -- "$0")"/.. && pwd)'
  d_bindir = '$prefix' / bindir
  d_incdir = '$prefix' / includedir
  d_libdir = '$prefix' / libdir
else
  d_prefix = prefix
  d_bindir = fs.is_absolute(bindir) ? bindir : '$prefix' / bindir
  d_incdir = fs.is_absolute(includedir) ? includedir : '$prefix' / includedir
  d_libdir = fs.is_absolute(libdir) ? libdir : '$prefix' / libdir
endif
d_rpath = host_machine.system() == 'windows' ? '$bindir' : '$libdir'
conf_dirs = {
  'prefix': d_prefix,
  'bindir': d_bindir,
  'includedir': d_incdir,
  'libdir': d_libdir,
  'rpath': d_rpath,
}
conf_vars = {
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
    configuration: conf_dirs + conf_vars[prog],
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
soversion = host_machine.system() == 'windows' ? '' : f'@abi_major@'
shared_library(
  libname,
  files(source_c),
  soversion: soversion,
  darwin_versions: [0, 0],
  vs_module_defs: 'mpilib.def',
  install: true,
)

if host_machine.system() == 'darwin'
  meson.add_install_script(
    find_program('sh'),
    files('fix-dylib-id.sh'),
  )
endif
