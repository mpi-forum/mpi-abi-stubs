project(
  'mpi-version',
  'c', 'cpp',
  version: '1.0.0',
  meson_version: '>=1.5.1',
)

mpi = dependency('mpi', required: true)
build_rpath = get_option('build_rpath')
install_rpath = get_option('install_rpath')

executable(
  'mpi-version',
  sources: 'mpi-version.c',
  dependencies: [mpi],
  build_rpath: build_rpath,
  install_rpath: install_rpath,
  install: true,
)
