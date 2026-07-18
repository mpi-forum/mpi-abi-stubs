cmake_minimum_required(VERSION 3.10.0...4.3.0)
project(mpi-abi-stubs VERSION 5.0 LANGUAGES C)

set(SOURCE_H mpi.h    CACHE FILEPATH "MPI ABI implementation header")
set(SOURCE_C mpilib.c CACHE FILEPATH "MPI ABI implementation source")

function(get_version header name outvar)
  set(regex "^[ \t]*#[ \t]*define[ \t]+${name}[ \t]+([0-9]+)[ \t]*$")
  file(STRINGS ${header} value REGEX ${regex})
  if("${value}" STREQUAL "")
    message(FATAL_ERROR "${name} not found in ${header}")
  endif()
  string(REGEX REPLACE ${regex} "\\1" value ${value})
  set(${outvar} ${value} PARENT_SCOPE)
endfunction()
get_version(${SOURCE_H} MPI_ABI_VERSION    ABI_MAJOR)
get_version(${SOURCE_H} MPI_ABI_SUBVERSION ABI_MINOR)

include(GNUInstallDirs)
option(RELOCATABLE "Relocatable install" FALSE)
if(RELOCATABLE)
  set(prefix "$(CDPATH='' cd -- \"$(dirname -- \"$0\")\"/.. && pwd)")
  set(bindir $prefix/${CMAKE_INSTALL_BINDIR})
  set(includedir $prefix/${CMAKE_INSTALL_INCLUDEDIR})
  set(libdir $prefix/${CMAKE_INSTALL_LIBDIR})
else()
  set(prefix ${CMAKE_INSTALL_PREFIX})
  set(bindir ${CMAKE_INSTALL_FULL_BINDIR})
  set(includedir ${CMAKE_INSTALL_FULL_INCLUDEDIR})
  set(libdir ${CMAKE_INSTALL_FULL_LIBDIR})
endif()

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

install(FILES ${SOURCE_H} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set(LIBNAME mpi_abi)
set(VERSION ${ABI_MAJOR}.${ABI_MINOR})
set(SOVERSION ${ABI_MAJOR})
add_library(${LIBNAME} SHARED ${SOURCE_C})
set_target_properties(
  ${LIBNAME} PROPERTIES
  SOVERSION ${SOVERSION}
  MACHO_COMPATIBILITY_VERSION 0
  MACHO_CURRENT_VERSION 0
  DLL_NAME_WITH_SOVERSION FALSE
  WINDOWS_EXPORT_ALL_SYMBOLS TRUE
)
install(TARGETS ${LIBNAME} DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(APPLE AND CMAKE_VERSION VERSION_LESS 3.17.0)
  get_target_property(v1 ${LIBNAME} MACHO_COMPATIBILITY_VERSION)
  get_target_property(v2 ${LIBNAME} MACHO_CURRENT_VERSION)
  set(ldflags "-compatibility_version,${v1},-current_version,${v2}")
  if(CMAKE_VERSION VERSION_LESS 3.12.0)
    set_target_properties(${LIBNAME} PROPERTIES LINK_FLAGS "-Wl,${ldflags}")
  else()
    target_link_options( ${LIBNAME} PRIVATE "LINKER:${ldflags}")
  endif()
endif()

if(WIN32 AND CMAKE_VERSION VERSION_LESS 3.27.0)
  get_target_property(versioned_dll_name ${LIBNAME} DLL_NAME_WITH_SOVERSION)
  if(versioned_dll_name)
    set_target_properties(
      ${LIBNAME} PROPERTIES
      ARCHIVE_OUTPUT_NAME ${LIBNAME}
      RUNTIME_OUTPUT_NAME ${LIBNAME}-${SOVERSION}
    )
  endif()
endif()
