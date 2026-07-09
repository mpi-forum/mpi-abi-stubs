cmake_minimum_required(VERSION 3.10.0...4.3.0)
project(mpi-version VERSION 1.0.0 LANGUAGES C CXX)

find_package(MPI REQUIRED COMPONENTS C CXX)

add_executable(mpi-version mpi-version.c)
target_link_libraries(mpi-version PRIVATE MPI::MPI_C)
install(TARGETS mpi-version)
