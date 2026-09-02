cmake_minimum_required(VERSION 3.10.0...4.3.0)
file(STRINGS "VERSION" PROJECT_VERSION LIMIT_COUNT 1)
string(STRIP ${PROJECT_VERSION} PROJECT_VERSION)
project(mpi-abi-stubs VERSION ${PROJECT_VERSION} LANGUAGES C)

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
  set(incdir $prefix/${CMAKE_INSTALL_INCLUDEDIR})
  set(libdir $prefix/${CMAKE_INSTALL_LIBDIR})
else()
  set(prefix \"${CMAKE_INSTALL_PREFIX}\")
  if(IS_ABSOLUTE ${CMAKE_INSTALL_BINDIR})
    set(bindir \"${CMAKE_INSTALL_FULL_BINDIR}\")
  else()
    set(bindir $prefix/${CMAKE_INSTALL_BINDIR})
  endif()
  if(IS_ABSOLUTE ${CMAKE_INSTALL_INCLUDEDIR})
    set(incdir \"${CMAKE_INSTALL_FULL_INCLUDEDIR}\")
  else()
    set(incdir $prefix/${CMAKE_INSTALL_INCLUDEDIR})
  endif()
  if(IS_ABSOLUTE ${CMAKE_INSTALL_LIBDIR})
    set(libdir \"${CMAKE_INSTALL_FULL_LIBDIR}\")
  else()
    set(libdir $prefix/${CMAKE_INSTALL_LIBDIR})
  endif()
endif()
if(WIN32)
  set(rpath $bindir)
else()
  set(rpath $libdir)
endif()

set(mpicc.CC CC)
set(mpicc.cc cc)
set(mpicc.op cc)
set(mpicxx.CC CXX)
set(mpicxx.cc c++)
set(mpicxx.op cxx)
set(permissions
  OWNER_READ OWNER_WRITE OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
)
foreach(script mpicc mpicxx)
  set(CC ${${script}.CC})
  set(cc ${${script}.cc})
  set(op ${${script}.op})
  configure_file(mpicc.in ${script} @ONLY)
  install(
    FILES ${CMAKE_BINARY_DIR}/${script}
    PERMISSIONS ${permissions}
    DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
  if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.14.0)
    file(CREATE_LINK
      ${script} ${CMAKE_BINARY_DIR}/${script}_abi
      SYMBOLIC COPY_ON_ERROR
    )
  else()
    set(create_symlink create_symlink)
    if(WIN32 AND CMAKE_VERSION VERSION_LESS 3.13.0)
      set(create_symlink copy)
    endif()
    add_custom_target(${script}_abi ALL VERBATIM
      DEPENDS ${CMAKE_BINARY_DIR}/${script}
      BYPRODUCTS ${CMAKE_BINARY_DIR}/${script}_abi
      COMMAND ${CMAKE_COMMAND} -E ${create_symlink}
      ${script} ${CMAKE_BINARY_DIR}/${script}_abi
    )
  endif()
  install(
    FILES ${CMAKE_BINARY_DIR}/${script}_abi
    PERMISSIONS ${permissions}
    DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
endforeach()

install(
  FILES ${SOURCE_H} mpi_legacy.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

set(LIBNAME mpi_abi)
set(SOVERSION ${ABI_MAJOR})
add_library(${LIBNAME} SHARED ${SOURCE_C} $<$<PLATFORM_ID:Windows>:mpilib.def>)
set_target_properties(
  ${LIBNAME} PROPERTIES
  SOVERSION ${SOVERSION}
  MACHO_COMPATIBILITY_VERSION 0
  MACHO_CURRENT_VERSION 0
  DLL_NAME_WITH_SOVERSION FALSE
)
install(
  TARGETS ${LIBNAME}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

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

if(WIN32 AND SKBUILD)
  set(template ${CMAKE_BINARY_DIR}/wrapper.in)
  file(WRITE ${template} [[
#!/bin/sh
venvdir=$(CDPATH='' cd -- "$(dirname -- "$0")"/.. && pwd)
exec "$venvdir/Library/bin/@script@" "$@"
]])
  foreach(script mpicc mpicxx mpicc_abi mpicxx_abi)
    set(wrapper ${CMAKE_BINARY_DIR}/${script}-wrapper)
    configure_file(${template} ${wrapper} @ONLY)
    install(
      FILES ${wrapper} RENAME ${script}
      PERMISSIONS ${permissions}
      DESTINATION ${SKBUILD_SCRIPTS_DIR}
    )
  endforeach()
endif()
