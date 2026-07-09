#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  char version[MPI_MAX_LIBRARY_VERSION_STRING];
  int std_minor, abi_major, abi_minor, std_major, resultlen;

  MPI_Get_version(&std_major, &std_minor);
  MPI_Abi_get_version(&abi_major, &abi_minor);
  MPI_Get_library_version(version, &resultlen);

  printf("MPI std version: %d.%d\n", std_major, std_minor);
  printf("MPI ABI version: %d.%d\n", abi_major, abi_minor);
  printf("Library version: %s\n", version);

  return 0;
}
