cmake_minimum_required(VERSION 3.5.0...4.1.0)
project(mpi-abi-stubs VERSION 5.0 LANGUAGES C)

option(BUILD_SHARED_LIBS "Build libraries as SHARED" TRUE)

add_library(mpi_abi mpistubs.c)
set_target_properties(mpi_abi PROPERTIES VERSION 0)
set_target_properties(mpi_abi PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS 1)

include(GNUInstallDirs)
install(FILES mpi.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS mpi_abi DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(includedir ${CMAKE_INSTALL_FULL_INCLUDEDIR})
set(libdir ${CMAKE_INSTALL_FULL_LIBDIR})
set(permissions
  OWNER_READ OWNER_WRITE OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
)
set(CC CC)
set(cc cc)
set(op cc)
configure_file(mpicc.in mpicc @ONLY)
install(
  FILES ${CMAKE_BINARY_DIR}/mpicc
  PERMISSIONS ${permissions}
  DESTINATION ${CMAKE_INSTALL_BINDIR}
)
set(CC CXX)
set(cc c++)
set(op cxx)
configure_file(mpicc.in mpicxx @ONLY)
install(
  FILES ${CMAKE_BINARY_DIR}/mpicxx
  PERMISSIONS ${permissions}
  DESTINATION ${CMAKE_INSTALL_BINDIR}
)
