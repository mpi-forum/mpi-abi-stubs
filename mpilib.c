#include <stdarg.h>
#include <stdlib.h>
#include "mpi.h"

/* Basic runtime implementation */

static int stubs_is_initialized = 0;
static int stubs_is_finalized = 0;

static int stubs_MPI_Initialized(int *flag)
{
  if (flag) *flag = stubs_is_initialized;
  return 0;
}

static int stubs_MPI_Finalized(int *flag)
{
  if (flag) *flag = stubs_is_finalized;
  return 0;
}

static int stubs_MPI_Get_version(int *version, int *subversion)
{
  if (version) *version = MPI_VERSION;
  if (subversion) *subversion = MPI_SUBVERSION;
  return 0;
}

static int stubs_MPI_Abi_get_version(int *abi_major, int *abi_minor)
{
  if (abi_major) *abi_major = MPI_ABI_VERSION;
  if (abi_minor) *abi_minor = MPI_ABI_SUBVERSION;
  return 0;
}

static int stubs_MPI_Get_library_version(char *version, int *resultlen)
{
  unsigned i = 0;
  char str[] = "MPI ABI 0.0";
  while (str[i] != '0') i++;
  str[i++] += (char) MPI_ABI_VERSION;
  str[++i] += (char) MPI_ABI_SUBVERSION;
  if (version)
    for (i = 0; i < sizeof(str); i++)
      version[i] = str[i];
  if (resultlen)
    *resultlen = sizeof(str) - 1;
  return 0;
}

/* MPI ABI implementation */

#ifdef _MSC_VER
#pragma warning ( disable : 4068 )
#endif

#pragma weak MPI_Abi_get_fortran_booleans
int MPI_Abi_get_fortran_booleans(int logical_size, void *logical_true, void *logical_false, int *is_set) { return PMPI_Abi_get_fortran_booleans(logical_size, logical_true, logical_false, is_set); }
int PMPI_Abi_get_fortran_booleans(int logical_size, void *logical_true, void *logical_false, int *is_set) { abort(); return 0; }

#pragma weak MPI_Abi_get_fortran_info
int MPI_Abi_get_fortran_info(MPI_Info *info) { return PMPI_Abi_get_fortran_info(info); }
int PMPI_Abi_get_fortran_info(MPI_Info *info) { abort(); return 0; }

#pragma weak MPI_Abi_get_info
int MPI_Abi_get_info(MPI_Info *info) { return PMPI_Abi_get_info(info); }
int PMPI_Abi_get_info(MPI_Info *info) { abort(); return 0; }

#pragma weak MPI_Abi_get_version
int MPI_Abi_get_version(int *abi_major, int *abi_minor) { return PMPI_Abi_get_version(abi_major, abi_minor); }
int PMPI_Abi_get_version(int *abi_major, int *abi_minor) { return stubs_MPI_Abi_get_version(abi_major, abi_minor); }

#pragma weak MPI_Abi_set_fortran_booleans
int MPI_Abi_set_fortran_booleans(int logical_size, void *logical_true, void *logical_false) { return PMPI_Abi_set_fortran_booleans(logical_size, logical_true, logical_false); }
int PMPI_Abi_set_fortran_booleans(int logical_size, void *logical_true, void *logical_false) { abort(); return 0; }

#pragma weak MPI_Abi_set_fortran_info
int MPI_Abi_set_fortran_info(MPI_Info info) { return PMPI_Abi_set_fortran_info(info); }
int PMPI_Abi_set_fortran_info(MPI_Info info) { abort(); return 0; }

#pragma weak MPI_Abort
int MPI_Abort(MPI_Comm comm, int errorcode) { return PMPI_Abort(comm, errorcode); }
int PMPI_Abort(MPI_Comm comm, int errorcode) { abort(); return 0; }

#pragma weak MPI_Accumulate
int MPI_Accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { return PMPI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win); }
int PMPI_Accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Accumulate_c
int MPI_Accumulate_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { return PMPI_Accumulate_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win); }
int PMPI_Accumulate_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Add_error_class
int MPI_Add_error_class(int *errorclass) { return PMPI_Add_error_class(errorclass); }
int PMPI_Add_error_class(int *errorclass) { abort(); return 0; }

#pragma weak MPI_Add_error_code
int MPI_Add_error_code(int errorclass, int *errorcode) { return PMPI_Add_error_code(errorclass, errorcode); }
int PMPI_Add_error_code(int errorclass, int *errorcode) { abort(); return 0; }

#pragma weak MPI_Add_error_string
int MPI_Add_error_string(int errorcode, const char *string) { return PMPI_Add_error_string(errorcode, string); }
int PMPI_Add_error_string(int errorcode, const char *string) { abort(); return 0; }

#pragma weak MPI_Allgather
int MPI_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
int PMPI_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Allgather_c
int MPI_Allgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Allgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
int PMPI_Allgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Allgather_init
int MPI_Allgather_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Allgather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request); }
int PMPI_Allgather_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Allgather_init_c
int MPI_Allgather_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Allgather_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request); }
int PMPI_Allgather_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Allgatherv
int MPI_Allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm); }
int PMPI_Allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Allgatherv_c
int MPI_Allgatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm); }
int PMPI_Allgatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Allgatherv_init
int MPI_Allgatherv_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Allgatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request); }
int PMPI_Allgatherv_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Allgatherv_init_c
int MPI_Allgatherv_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Allgatherv_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request); }
int PMPI_Allgatherv_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Alloc_mem
int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr) { return PMPI_Alloc_mem(size, info, baseptr); }
int PMPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr) { abort(); return 0; }

#pragma weak MPI_Allreduce
int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return PMPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm); }
int PMPI_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Allreduce_c
int MPI_Allreduce_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return PMPI_Allreduce_c(sendbuf, recvbuf, count, datatype, op, comm); }
int PMPI_Allreduce_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Allreduce_init
int MPI_Allreduce_init(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Allreduce_init(sendbuf, recvbuf, count, datatype, op, comm, info, request); }
int PMPI_Allreduce_init(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Allreduce_init_c
int MPI_Allreduce_init_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Allreduce_init_c(sendbuf, recvbuf, count, datatype, op, comm, info, request); }
int PMPI_Allreduce_init_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Alltoall
int MPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
int PMPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Alltoall_c
int MPI_Alltoall_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Alltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
int PMPI_Alltoall_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Alltoall_init
int MPI_Alltoall_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Alltoall_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request); }
int PMPI_Alltoall_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Alltoall_init_c
int MPI_Alltoall_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Alltoall_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request); }
int PMPI_Alltoall_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Alltoallv
int MPI_Alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm); }
int PMPI_Alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Alltoallv_c
int MPI_Alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm); }
int PMPI_Alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Alltoallv_init
int MPI_Alltoallv_init(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Alltoallv_init(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request); }
int PMPI_Alltoallv_init(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Alltoallv_init_c
int MPI_Alltoallv_init_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Alltoallv_init_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request); }
int PMPI_Alltoallv_init_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Alltoallw
int MPI_Alltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) { return PMPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm); }
int PMPI_Alltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Alltoallw_c
int MPI_Alltoallw_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) { return PMPI_Alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm); }
int PMPI_Alltoallw_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Alltoallw_init
int MPI_Alltoallw_init(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request); }
int PMPI_Alltoallw_init(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Alltoallw_init_c
int MPI_Alltoallw_init_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Alltoallw_init_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request); }
int PMPI_Alltoallw_init_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Attr_delete
int MPI_Attr_delete(MPI_Comm comm, int keyval) { return PMPI_Attr_delete(comm, keyval); }
int PMPI_Attr_delete(MPI_Comm comm, int keyval) { abort(); return 0; }

#pragma weak MPI_Attr_get
int MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val, int *flag) { return PMPI_Attr_get(comm, keyval, attribute_val, flag); }
int PMPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val, int *flag) { abort(); return 0; }

#pragma weak MPI_Attr_put
int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val) { return PMPI_Attr_put(comm, keyval, attribute_val); }
int PMPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val) { abort(); return 0; }

#pragma weak MPI_Barrier
int MPI_Barrier(MPI_Comm comm) { return PMPI_Barrier(comm); }
int PMPI_Barrier(MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Barrier_init
int MPI_Barrier_init(MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Barrier_init(comm, info, request); }
int PMPI_Barrier_init(MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Bcast
int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm) { return PMPI_Bcast(buffer, count, datatype, root, comm); }
int PMPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Bcast_c
int MPI_Bcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype, int root, MPI_Comm comm) { return PMPI_Bcast_c(buffer, count, datatype, root, comm); }
int PMPI_Bcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Bcast_init
int MPI_Bcast_init(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Bcast_init(buffer, count, datatype, root, comm, info, request); }
int PMPI_Bcast_init(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Bcast_init_c
int MPI_Bcast_init_c(void *buffer, MPI_Count count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Bcast_init_c(buffer, count, datatype, root, comm, info, request); }
int PMPI_Bcast_init_c(void *buffer, MPI_Count count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Bsend
int MPI_Bsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return PMPI_Bsend(buf, count, datatype, dest, tag, comm); }
int PMPI_Bsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Bsend_c
int MPI_Bsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return PMPI_Bsend_c(buf, count, datatype, dest, tag, comm); }
int PMPI_Bsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Bsend_init
int MPI_Bsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Bsend_init(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Bsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Bsend_init_c
int MPI_Bsend_init_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Bsend_init_c(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Bsend_init_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Buffer_attach
int MPI_Buffer_attach(void *buffer, int size) { return PMPI_Buffer_attach(buffer, size); }
int PMPI_Buffer_attach(void *buffer, int size) { abort(); return 0; }

#pragma weak MPI_Buffer_attach_c
int MPI_Buffer_attach_c(void *buffer, MPI_Count size) { return PMPI_Buffer_attach_c(buffer, size); }
int PMPI_Buffer_attach_c(void *buffer, MPI_Count size) { abort(); return 0; }

#pragma weak MPI_Buffer_detach
int MPI_Buffer_detach(void *buffer_addr, int *size) { return PMPI_Buffer_detach(buffer_addr, size); }
int PMPI_Buffer_detach(void *buffer_addr, int *size) { abort(); return 0; }

#pragma weak MPI_Buffer_detach_c
int MPI_Buffer_detach_c(void *buffer_addr, MPI_Count *size) { return PMPI_Buffer_detach_c(buffer_addr, size); }
int PMPI_Buffer_detach_c(void *buffer_addr, MPI_Count *size) { abort(); return 0; }

#pragma weak MPI_Buffer_flush
int MPI_Buffer_flush(void) { return PMPI_Buffer_flush(); }
int PMPI_Buffer_flush(void) { abort(); return 0; }

#pragma weak MPI_Buffer_iflush
int MPI_Buffer_iflush(MPI_Request *request) { return PMPI_Buffer_iflush(request); }
int PMPI_Buffer_iflush(MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Cancel
int MPI_Cancel(MPI_Request *request) { return PMPI_Cancel(request); }
int PMPI_Cancel(MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Cart_coords
int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[]) { return PMPI_Cart_coords(comm, rank, maxdims, coords); }
int PMPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[]) { abort(); return 0; }

#pragma weak MPI_Cart_create
int MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[], const int periods[], int reorder, MPI_Comm *comm_cart) { return PMPI_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart); }
int PMPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[], const int periods[], int reorder, MPI_Comm *comm_cart) { abort(); return 0; }

#pragma weak MPI_Cart_get
int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[]) { return PMPI_Cart_get(comm, maxdims, dims, periods, coords); }
int PMPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[]) { abort(); return 0; }

#pragma weak MPI_Cart_map
int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank) { return PMPI_Cart_map(comm, ndims, dims, periods, newrank); }
int PMPI_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank) { abort(); return 0; }

#pragma weak MPI_Cart_rank
int MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank) { return PMPI_Cart_rank(comm, coords, rank); }
int PMPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank) { abort(); return 0; }

#pragma weak MPI_Cart_shift
int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest) { return PMPI_Cart_shift(comm, direction, disp, rank_source, rank_dest); }
int PMPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest) { abort(); return 0; }

#pragma weak MPI_Cart_sub
int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm) { return PMPI_Cart_sub(comm, remain_dims, newcomm); }
int PMPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm) { abort(); return 0; }

#pragma weak MPI_Cartdim_get
int MPI_Cartdim_get(MPI_Comm comm, int *ndims) { return PMPI_Cartdim_get(comm, ndims); }
int PMPI_Cartdim_get(MPI_Comm comm, int *ndims) { abort(); return 0; }

#pragma weak MPI_Close_port
int MPI_Close_port(const char *port_name) { return PMPI_Close_port(port_name); }
int PMPI_Close_port(const char *port_name) { abort(); return 0; }

#pragma weak MPI_Comm_accept
int MPI_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) { return PMPI_Comm_accept(port_name, info, root, comm, newcomm); }
int PMPI_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) { abort(); return 0; }

#pragma weak MPI_Comm_attach_buffer
int MPI_Comm_attach_buffer(MPI_Comm comm, void *buffer, int size) { return PMPI_Comm_attach_buffer(comm, buffer, size); }
int PMPI_Comm_attach_buffer(MPI_Comm comm, void *buffer, int size) { abort(); return 0; }

#pragma weak MPI_Comm_attach_buffer_c
int MPI_Comm_attach_buffer_c(MPI_Comm comm, void *buffer, MPI_Count size) { return PMPI_Comm_attach_buffer_c(comm, buffer, size); }
int PMPI_Comm_attach_buffer_c(MPI_Comm comm, void *buffer, MPI_Count size) { abort(); return 0; }

#pragma weak MPI_Comm_call_errhandler
int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode) { return PMPI_Comm_call_errhandler(comm, errorcode); }
int PMPI_Comm_call_errhandler(MPI_Comm comm, int errorcode) { abort(); return 0; }

#pragma weak MPI_Comm_compare
int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result) { return PMPI_Comm_compare(comm1, comm2, result); }
int PMPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result) { abort(); return 0; }

#pragma weak MPI_Comm_connect
int MPI_Comm_connect(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) { return PMPI_Comm_connect(port_name, info, root, comm, newcomm); }
int PMPI_Comm_connect(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) { abort(); return 0; }

#pragma weak MPI_Comm_create
int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm) { return PMPI_Comm_create(comm, group, newcomm); }
int PMPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm) { abort(); return 0; }

#pragma weak MPI_Comm_create_errhandler
int MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn, MPI_Errhandler *errhandler) { return PMPI_Comm_create_errhandler(comm_errhandler_fn, errhandler); }
int PMPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn, MPI_Errhandler *errhandler) { abort(); return 0; }

#pragma weak MPI_Comm_create_from_group
int MPI_Comm_create_from_group(MPI_Group group, const char *stringtag, MPI_Info info, MPI_Errhandler errhandler, MPI_Comm *newcomm) { return PMPI_Comm_create_from_group(group, stringtag, info, errhandler, newcomm); }
int PMPI_Comm_create_from_group(MPI_Group group, const char *stringtag, MPI_Info info, MPI_Errhandler errhandler, MPI_Comm *newcomm) { abort(); return 0; }

#pragma weak MPI_Comm_create_group
int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag, MPI_Comm *newcomm) { return PMPI_Comm_create_group(comm, group, tag, newcomm); }
int PMPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag, MPI_Comm *newcomm) { abort(); return 0; }

#pragma weak MPI_Comm_create_keyval
int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn, MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state) { return PMPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state); }
int PMPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn, MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state) { abort(); return 0; }

#pragma weak MPI_Comm_delete_attr
int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval) { return PMPI_Comm_delete_attr(comm, comm_keyval); }
int PMPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval) { abort(); return 0; }

#pragma weak MPI_Comm_detach_buffer
int MPI_Comm_detach_buffer(MPI_Comm comm, void *buffer_addr, int *size) { return PMPI_Comm_detach_buffer(comm, buffer_addr, size); }
int PMPI_Comm_detach_buffer(MPI_Comm comm, void *buffer_addr, int *size) { abort(); return 0; }

#pragma weak MPI_Comm_detach_buffer_c
int MPI_Comm_detach_buffer_c(MPI_Comm comm, void *buffer_addr, MPI_Count *size) { return PMPI_Comm_detach_buffer_c(comm, buffer_addr, size); }
int PMPI_Comm_detach_buffer_c(MPI_Comm comm, void *buffer_addr, MPI_Count *size) { abort(); return 0; }

#pragma weak MPI_Comm_disconnect
int MPI_Comm_disconnect(MPI_Comm *comm) { return PMPI_Comm_disconnect(comm); }
int PMPI_Comm_disconnect(MPI_Comm *comm) { abort(); return 0; }

#pragma weak MPI_Comm_dup
int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) { return PMPI_Comm_dup(comm, newcomm); }
int PMPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) { abort(); return 0; }

#pragma weak MPI_Comm_dup_with_info
int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm) { return PMPI_Comm_dup_with_info(comm, info, newcomm); }
int PMPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm) { abort(); return 0; }

#pragma weak MPI_Comm_flush_buffer
int MPI_Comm_flush_buffer(MPI_Comm comm) { return PMPI_Comm_flush_buffer(comm); }
int PMPI_Comm_flush_buffer(MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Comm_free
int MPI_Comm_free(MPI_Comm *comm) { return PMPI_Comm_free(comm); }
int PMPI_Comm_free(MPI_Comm *comm) { abort(); return 0; }

#pragma weak MPI_Comm_free_keyval
int MPI_Comm_free_keyval(int *comm_keyval) { return PMPI_Comm_free_keyval(comm_keyval); }
int PMPI_Comm_free_keyval(int *comm_keyval) { abort(); return 0; }

#pragma weak MPI_Comm_get_attr
int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag) { return PMPI_Comm_get_attr(comm, comm_keyval, attribute_val, flag); }
int PMPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag) { abort(); return 0; }

#pragma weak MPI_Comm_get_errhandler
int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler) { return PMPI_Comm_get_errhandler(comm, errhandler); }
int PMPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler) { abort(); return 0; }

#pragma weak MPI_Comm_get_info
int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used) { return PMPI_Comm_get_info(comm, info_used); }
int PMPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used) { abort(); return 0; }

#pragma weak MPI_Comm_get_name
int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen) { return PMPI_Comm_get_name(comm, comm_name, resultlen); }
int PMPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen) { abort(); return 0; }

#pragma weak MPI_Comm_get_parent
int MPI_Comm_get_parent(MPI_Comm *parent) { return PMPI_Comm_get_parent(parent); }
int PMPI_Comm_get_parent(MPI_Comm *parent) { abort(); return 0; }

#pragma weak MPI_Comm_group
int MPI_Comm_group(MPI_Comm comm, MPI_Group *group) { return PMPI_Comm_group(comm, group); }
int PMPI_Comm_group(MPI_Comm comm, MPI_Group *group) { abort(); return 0; }

#pragma weak MPI_Comm_idup
int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request) { return PMPI_Comm_idup(comm, newcomm, request); }
int PMPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Comm_idup_with_info
int MPI_Comm_idup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm, MPI_Request *request) { return PMPI_Comm_idup_with_info(comm, info, newcomm, request); }
int PMPI_Comm_idup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Comm_iflush_buffer
int MPI_Comm_iflush_buffer(MPI_Comm comm, MPI_Request *request) { return PMPI_Comm_iflush_buffer(comm, request); }
int PMPI_Comm_iflush_buffer(MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Comm_join
int MPI_Comm_join(int fd, MPI_Comm *intercomm) { return PMPI_Comm_join(fd, intercomm); }
int PMPI_Comm_join(int fd, MPI_Comm *intercomm) { abort(); return 0; }

#pragma weak MPI_Comm_rank
int MPI_Comm_rank(MPI_Comm comm, int *rank) { return PMPI_Comm_rank(comm, rank); }
int PMPI_Comm_rank(MPI_Comm comm, int *rank) { abort(); return 0; }

#pragma weak MPI_Comm_remote_group
int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group) { return PMPI_Comm_remote_group(comm, group); }
int PMPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group) { abort(); return 0; }

#pragma weak MPI_Comm_remote_size
int MPI_Comm_remote_size(MPI_Comm comm, int *size) { return PMPI_Comm_remote_size(comm, size); }
int PMPI_Comm_remote_size(MPI_Comm comm, int *size) { abort(); return 0; }

#pragma weak MPI_Comm_set_attr
int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val) { return PMPI_Comm_set_attr(comm, comm_keyval, attribute_val); }
int PMPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val) { abort(); return 0; }

#pragma weak MPI_Comm_set_errhandler
int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler) { return PMPI_Comm_set_errhandler(comm, errhandler); }
int PMPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler) { abort(); return 0; }

#pragma weak MPI_Comm_set_info
int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info) { return PMPI_Comm_set_info(comm, info); }
int PMPI_Comm_set_info(MPI_Comm comm, MPI_Info info) { abort(); return 0; }

#pragma weak MPI_Comm_set_name
int MPI_Comm_set_name(MPI_Comm comm, const char *comm_name) { return PMPI_Comm_set_name(comm, comm_name); }
int PMPI_Comm_set_name(MPI_Comm comm, const char *comm_name) { abort(); return 0; }

#pragma weak MPI_Comm_size
int MPI_Comm_size(MPI_Comm comm, int *size) { return PMPI_Comm_size(comm, size); }
int PMPI_Comm_size(MPI_Comm comm, int *size) { abort(); return 0; }

#pragma weak MPI_Comm_spawn
int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[]) { return PMPI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes); }
int PMPI_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[]) { abort(); return 0; }

#pragma weak MPI_Comm_spawn_multiple
int MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], const int array_of_maxprocs[], const MPI_Info array_of_info[], int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[]) { return PMPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes); }
int PMPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], const int array_of_maxprocs[], const MPI_Info array_of_info[], int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[]) { abort(); return 0; }

#pragma weak MPI_Comm_split
int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm) { return PMPI_Comm_split(comm, color, key, newcomm); }
int PMPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm) { abort(); return 0; }

#pragma weak MPI_Comm_split_type
int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info, MPI_Comm *newcomm) { return PMPI_Comm_split_type(comm, split_type, key, info, newcomm); }
int PMPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info, MPI_Comm *newcomm) { abort(); return 0; }

#pragma weak MPI_Comm_test_inter
int MPI_Comm_test_inter(MPI_Comm comm, int *flag) { return PMPI_Comm_test_inter(comm, flag); }
int PMPI_Comm_test_inter(MPI_Comm comm, int *flag) { abort(); return 0; }

#pragma weak MPI_Compare_and_swap
int MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win) { return PMPI_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win); }
int PMPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Dims_create
int MPI_Dims_create(int nnodes, int ndims, int dims[]) { return PMPI_Dims_create(nnodes, ndims, dims); }
int PMPI_Dims_create(int nnodes, int ndims, int dims[]) { abort(); return 0; }

#pragma weak MPI_Dist_graph_create
int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph) { return PMPI_Dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph); }
int PMPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph) { abort(); return 0; }

#pragma weak MPI_Dist_graph_create_adjacent
int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[], const int sourceweights[], int outdegree, const int destinations[], const int destweights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph) { return PMPI_Dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph); }
int PMPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[], const int sourceweights[], int outdegree, const int destinations[], const int destweights[], MPI_Info info, int reorder, MPI_Comm *comm_dist_graph) { abort(); return 0; }

#pragma weak MPI_Dist_graph_neighbors
int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree, int destinations[], int destweights[]) { return PMPI_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights); }
int PMPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree, int destinations[], int destweights[]) { abort(); return 0; }

#pragma weak MPI_Dist_graph_neighbors_count
int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree, int *outdegree, int *weighted) { return PMPI_Dist_graph_neighbors_count(comm, indegree, outdegree, weighted); }
int PMPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree, int *outdegree, int *weighted) { abort(); return 0; }

#pragma weak MPI_Errhandler_free
int MPI_Errhandler_free(MPI_Errhandler *errhandler) { return PMPI_Errhandler_free(errhandler); }
int PMPI_Errhandler_free(MPI_Errhandler *errhandler) { abort(); return 0; }

#pragma weak MPI_Error_class
int MPI_Error_class(int errorcode, int *errorclass) { return PMPI_Error_class(errorcode, errorclass); }
int PMPI_Error_class(int errorcode, int *errorclass) { abort(); return 0; }

#pragma weak MPI_Error_string
int MPI_Error_string(int errorcode, char *string, int *resultlen) { return PMPI_Error_string(errorcode, string, resultlen); }
int PMPI_Error_string(int errorcode, char *string, int *resultlen) { abort(); return 0; }

#pragma weak MPI_Exscan
int MPI_Exscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return PMPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm); }
int PMPI_Exscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Exscan_c
int MPI_Exscan_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return PMPI_Exscan_c(sendbuf, recvbuf, count, datatype, op, comm); }
int PMPI_Exscan_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Exscan_init
int MPI_Exscan_init(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Exscan_init(sendbuf, recvbuf, count, datatype, op, comm, info, request); }
int PMPI_Exscan_init(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Exscan_init_c
int MPI_Exscan_init_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Exscan_init_c(sendbuf, recvbuf, count, datatype, op, comm, info, request); }
int PMPI_Exscan_init_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Fetch_and_op
int MPI_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win) { return PMPI_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win); }
int PMPI_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_File_call_errhandler
int MPI_File_call_errhandler(MPI_File fh, int errorcode) { return PMPI_File_call_errhandler(fh, errorcode); }
int PMPI_File_call_errhandler(MPI_File fh, int errorcode) { abort(); return 0; }

#pragma weak MPI_File_close
int MPI_File_close(MPI_File *fh) { return PMPI_File_close(fh); }
int PMPI_File_close(MPI_File *fh) { abort(); return 0; }

#pragma weak MPI_File_create_errhandler
int MPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn, MPI_Errhandler *errhandler) { return PMPI_File_create_errhandler(file_errhandler_fn, errhandler); }
int PMPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn, MPI_Errhandler *errhandler) { abort(); return 0; }

#pragma weak MPI_File_delete
int MPI_File_delete(const char *filename, MPI_Info info) { return PMPI_File_delete(filename, info); }
int PMPI_File_delete(const char *filename, MPI_Info info) { abort(); return 0; }

#pragma weak MPI_File_get_amode
int MPI_File_get_amode(MPI_File fh, int *amode) { return PMPI_File_get_amode(fh, amode); }
int PMPI_File_get_amode(MPI_File fh, int *amode) { abort(); return 0; }

#pragma weak MPI_File_get_atomicity
int MPI_File_get_atomicity(MPI_File fh, int *flag) { return PMPI_File_get_atomicity(fh, flag); }
int PMPI_File_get_atomicity(MPI_File fh, int *flag) { abort(); return 0; }

#pragma weak MPI_File_get_byte_offset
int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp) { return PMPI_File_get_byte_offset(fh, offset, disp); }
int PMPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp) { abort(); return 0; }

#pragma weak MPI_File_get_errhandler
int MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler) { return PMPI_File_get_errhandler(file, errhandler); }
int PMPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler) { abort(); return 0; }

#pragma weak MPI_File_get_group
int MPI_File_get_group(MPI_File fh, MPI_Group *group) { return PMPI_File_get_group(fh, group); }
int PMPI_File_get_group(MPI_File fh, MPI_Group *group) { abort(); return 0; }

#pragma weak MPI_File_get_info
int MPI_File_get_info(MPI_File fh, MPI_Info *info_used) { return PMPI_File_get_info(fh, info_used); }
int PMPI_File_get_info(MPI_File fh, MPI_Info *info_used) { abort(); return 0; }

#pragma weak MPI_File_get_position
int MPI_File_get_position(MPI_File fh, MPI_Offset *offset) { return PMPI_File_get_position(fh, offset); }
int PMPI_File_get_position(MPI_File fh, MPI_Offset *offset) { abort(); return 0; }

#pragma weak MPI_File_get_position_shared
int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset) { return PMPI_File_get_position_shared(fh, offset); }
int PMPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset) { abort(); return 0; }

#pragma weak MPI_File_get_size
int MPI_File_get_size(MPI_File fh, MPI_Offset *size) { return PMPI_File_get_size(fh, size); }
int PMPI_File_get_size(MPI_File fh, MPI_Offset *size) { abort(); return 0; }

#pragma weak MPI_File_get_type_extent
int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent) { return PMPI_File_get_type_extent(fh, datatype, extent); }
int PMPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent) { abort(); return 0; }

#pragma weak MPI_File_get_type_extent_c
int MPI_File_get_type_extent_c(MPI_File fh, MPI_Datatype datatype, MPI_Count *extent) { return PMPI_File_get_type_extent_c(fh, datatype, extent); }
int PMPI_File_get_type_extent_c(MPI_File fh, MPI_Datatype datatype, MPI_Count *extent) { abort(); return 0; }

#pragma weak MPI_File_get_view
int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep) { return PMPI_File_get_view(fh, disp, etype, filetype, datarep); }
int PMPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep) { abort(); return 0; }

#pragma weak MPI_File_iread
int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iread(fh, buf, count, datatype, request); }
int PMPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iread_c
int MPI_File_iread_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iread_c(fh, buf, count, datatype, request); }
int PMPI_File_iread_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iread_all
int MPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iread_all(fh, buf, count, datatype, request); }
int PMPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iread_all_c
int MPI_File_iread_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iread_all_c(fh, buf, count, datatype, request); }
int PMPI_File_iread_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iread_at
int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iread_at(fh, offset, buf, count, datatype, request); }
int PMPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iread_at_c
int MPI_File_iread_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iread_at_c(fh, offset, buf, count, datatype, request); }
int PMPI_File_iread_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iread_at_all
int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iread_at_all(fh, offset, buf, count, datatype, request); }
int PMPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iread_at_all_c
int MPI_File_iread_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iread_at_all_c(fh, offset, buf, count, datatype, request); }
int PMPI_File_iread_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iread_shared
int MPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iread_shared(fh, buf, count, datatype, request); }
int PMPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iread_shared_c
int MPI_File_iread_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iread_shared_c(fh, buf, count, datatype, request); }
int PMPI_File_iread_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iwrite
int MPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iwrite(fh, buf, count, datatype, request); }
int PMPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iwrite_c
int MPI_File_iwrite_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iwrite_c(fh, buf, count, datatype, request); }
int PMPI_File_iwrite_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iwrite_all
int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iwrite_all(fh, buf, count, datatype, request); }
int PMPI_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iwrite_all_c
int MPI_File_iwrite_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iwrite_all_c(fh, buf, count, datatype, request); }
int PMPI_File_iwrite_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iwrite_at
int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iwrite_at(fh, offset, buf, count, datatype, request); }
int PMPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iwrite_at_c
int MPI_File_iwrite_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iwrite_at_c(fh, offset, buf, count, datatype, request); }
int PMPI_File_iwrite_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iwrite_at_all
int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iwrite_at_all(fh, offset, buf, count, datatype, request); }
int PMPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iwrite_at_all_c
int MPI_File_iwrite_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iwrite_at_all_c(fh, offset, buf, count, datatype, request); }
int PMPI_File_iwrite_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iwrite_shared
int MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iwrite_shared(fh, buf, count, datatype, request); }
int PMPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_iwrite_shared_c
int MPI_File_iwrite_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { return PMPI_File_iwrite_shared_c(fh, buf, count, datatype, request); }
int PMPI_File_iwrite_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_File_open
int MPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh) { return PMPI_File_open(comm, filename, amode, info, fh); }
int PMPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh) { abort(); return 0; }

#pragma weak MPI_File_preallocate
int MPI_File_preallocate(MPI_File fh, MPI_Offset size) { return PMPI_File_preallocate(fh, size); }
int PMPI_File_preallocate(MPI_File fh, MPI_Offset size) { abort(); return 0; }

#pragma weak MPI_File_read
int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read(fh, buf, count, datatype, status); }
int PMPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_c
int MPI_File_read_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read_c(fh, buf, count, datatype, status); }
int PMPI_File_read_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_all
int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read_all(fh, buf, count, datatype, status); }
int PMPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_all_c
int MPI_File_read_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read_all_c(fh, buf, count, datatype, status); }
int PMPI_File_read_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_all_begin
int MPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { return PMPI_File_read_all_begin(fh, buf, count, datatype); }
int PMPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_read_all_begin_c
int MPI_File_read_all_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype) { return PMPI_File_read_all_begin_c(fh, buf, count, datatype); }
int PMPI_File_read_all_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_read_all_end
int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status) { return PMPI_File_read_all_end(fh, buf, status); }
int PMPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_at
int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read_at(fh, offset, buf, count, datatype, status); }
int PMPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_at_c
int MPI_File_read_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read_at_c(fh, offset, buf, count, datatype, status); }
int PMPI_File_read_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_at_all
int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read_at_all(fh, offset, buf, count, datatype, status); }
int PMPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_at_all_c
int MPI_File_read_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read_at_all_c(fh, offset, buf, count, datatype, status); }
int PMPI_File_read_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_at_all_begin
int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype) { return PMPI_File_read_at_all_begin(fh, offset, buf, count, datatype); }
int PMPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_read_at_all_begin_c
int MPI_File_read_at_all_begin_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count, MPI_Datatype datatype) { return PMPI_File_read_at_all_begin_c(fh, offset, buf, count, datatype); }
int PMPI_File_read_at_all_begin_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_read_at_all_end
int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status) { return PMPI_File_read_at_all_end(fh, buf, status); }
int PMPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_ordered
int MPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read_ordered(fh, buf, count, datatype, status); }
int PMPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_ordered_c
int MPI_File_read_ordered_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read_ordered_c(fh, buf, count, datatype, status); }
int PMPI_File_read_ordered_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_ordered_begin
int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { return PMPI_File_read_ordered_begin(fh, buf, count, datatype); }
int PMPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_read_ordered_begin_c
int MPI_File_read_ordered_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype) { return PMPI_File_read_ordered_begin_c(fh, buf, count, datatype); }
int PMPI_File_read_ordered_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_read_ordered_end
int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status) { return PMPI_File_read_ordered_end(fh, buf, status); }
int PMPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_shared
int MPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read_shared(fh, buf, count, datatype, status); }
int PMPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_read_shared_c
int MPI_File_read_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_read_shared_c(fh, buf, count, datatype, status); }
int PMPI_File_read_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_seek
int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence) { return PMPI_File_seek(fh, offset, whence); }
int PMPI_File_seek(MPI_File fh, MPI_Offset offset, int whence) { abort(); return 0; }

#pragma weak MPI_File_seek_shared
int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence) { return PMPI_File_seek_shared(fh, offset, whence); }
int PMPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence) { abort(); return 0; }

#pragma weak MPI_File_set_atomicity
int MPI_File_set_atomicity(MPI_File fh, int flag) { return PMPI_File_set_atomicity(fh, flag); }
int PMPI_File_set_atomicity(MPI_File fh, int flag) { abort(); return 0; }

#pragma weak MPI_File_set_errhandler
int MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler) { return PMPI_File_set_errhandler(file, errhandler); }
int PMPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler) { abort(); return 0; }

#pragma weak MPI_File_set_info
int MPI_File_set_info(MPI_File fh, MPI_Info info) { return PMPI_File_set_info(fh, info); }
int PMPI_File_set_info(MPI_File fh, MPI_Info info) { abort(); return 0; }

#pragma weak MPI_File_set_size
int MPI_File_set_size(MPI_File fh, MPI_Offset size) { return PMPI_File_set_size(fh, size); }
int PMPI_File_set_size(MPI_File fh, MPI_Offset size) { abort(); return 0; }

#pragma weak MPI_File_set_view
int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, const char *datarep, MPI_Info info) { return PMPI_File_set_view(fh, disp, etype, filetype, datarep, info); }
int PMPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, const char *datarep, MPI_Info info) { abort(); return 0; }

#pragma weak MPI_File_sync
int MPI_File_sync(MPI_File fh) { return PMPI_File_sync(fh); }
int PMPI_File_sync(MPI_File fh) { abort(); return 0; }

#pragma weak MPI_File_write
int MPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write(fh, buf, count, datatype, status); }
int PMPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_c
int MPI_File_write_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write_c(fh, buf, count, datatype, status); }
int PMPI_File_write_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_all
int MPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write_all(fh, buf, count, datatype, status); }
int PMPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_all_c
int MPI_File_write_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write_all_c(fh, buf, count, datatype, status); }
int PMPI_File_write_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_all_begin
int MPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype) { return PMPI_File_write_all_begin(fh, buf, count, datatype); }
int PMPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_write_all_begin_c
int MPI_File_write_all_begin_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype) { return PMPI_File_write_all_begin_c(fh, buf, count, datatype); }
int PMPI_File_write_all_begin_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_write_all_end
int MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status) { return PMPI_File_write_all_end(fh, buf, status); }
int PMPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_at
int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write_at(fh, offset, buf, count, datatype, status); }
int PMPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_at_c
int MPI_File_write_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write_at_c(fh, offset, buf, count, datatype, status); }
int PMPI_File_write_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_at_all
int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write_at_all(fh, offset, buf, count, datatype, status); }
int PMPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_at_all_c
int MPI_File_write_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write_at_all_c(fh, offset, buf, count, datatype, status); }
int PMPI_File_write_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_at_all_begin
int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype) { return PMPI_File_write_at_all_begin(fh, offset, buf, count, datatype); }
int PMPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_write_at_all_begin_c
int MPI_File_write_at_all_begin_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count, MPI_Datatype datatype) { return PMPI_File_write_at_all_begin_c(fh, offset, buf, count, datatype); }
int PMPI_File_write_at_all_begin_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_write_at_all_end
int MPI_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status) { return PMPI_File_write_at_all_end(fh, buf, status); }
int PMPI_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_ordered
int MPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write_ordered(fh, buf, count, datatype, status); }
int PMPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_ordered_c
int MPI_File_write_ordered_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write_ordered_c(fh, buf, count, datatype, status); }
int PMPI_File_write_ordered_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_ordered_begin
int MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype) { return PMPI_File_write_ordered_begin(fh, buf, count, datatype); }
int PMPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_write_ordered_begin_c
int MPI_File_write_ordered_begin_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype) { return PMPI_File_write_ordered_begin_c(fh, buf, count, datatype); }
int PMPI_File_write_ordered_begin_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_File_write_ordered_end
int MPI_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status) { return PMPI_File_write_ordered_end(fh, buf, status); }
int PMPI_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_shared
int MPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write_shared(fh, buf, count, datatype, status); }
int PMPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_File_write_shared_c
int MPI_File_write_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { return PMPI_File_write_shared_c(fh, buf, count, datatype, status); }
int PMPI_File_write_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Finalize
int MPI_Finalize(void) { return PMPI_Finalize(); }
int PMPI_Finalize(void) { abort(); return 0; }

#pragma weak MPI_Finalized
int MPI_Finalized(int *flag) { return PMPI_Finalized(flag); }
int PMPI_Finalized(int *flag) { return stubs_MPI_Finalized(flag); }

#pragma weak MPI_Free_mem
int MPI_Free_mem(void *base) { return PMPI_Free_mem(base); }
int PMPI_Free_mem(void *base) { abort(); return 0; }

#pragma weak MPI_Gather
int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { return PMPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm); }
int PMPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Gather_c
int MPI_Gather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { return PMPI_Gather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm); }
int PMPI_Gather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Gather_init
int MPI_Gather_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Gather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request); }
int PMPI_Gather_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Gather_init_c
int MPI_Gather_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Gather_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request); }
int PMPI_Gather_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Gatherv
int MPI_Gatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm) { return PMPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm); }
int PMPI_Gatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Gatherv_c
int MPI_Gatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, int root, MPI_Comm comm) { return PMPI_Gatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm); }
int PMPI_Gatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Gatherv_init
int MPI_Gatherv_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Gatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, info, request); }
int PMPI_Gatherv_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Gatherv_init_c
int MPI_Gatherv_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Gatherv_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, info, request); }
int PMPI_Gatherv_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Get
int MPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win) { return PMPI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win); }
int PMPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Get_c
int MPI_Get_c(void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Win win) { return PMPI_Get_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win); }
int PMPI_Get_c(void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Get_accumulate
int MPI_Get_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { return PMPI_Get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win); }
int PMPI_Get_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Get_accumulate_c
int MPI_Get_accumulate_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, void *result_addr, MPI_Count result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { return PMPI_Get_accumulate_c(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win); }
int PMPI_Get_accumulate_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, void *result_addr, MPI_Count result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Get_address
int MPI_Get_address(const void *location, MPI_Aint *address) { return PMPI_Get_address(location, address); }
int PMPI_Get_address(const void *location, MPI_Aint *address) { abort(); return 0; }

#pragma weak MPI_Get_count
int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count) { return PMPI_Get_count(status, datatype, count); }
int PMPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count) { abort(); return 0; }

#pragma weak MPI_Get_count_c
int MPI_Get_count_c(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count) { return PMPI_Get_count_c(status, datatype, count); }
int PMPI_Get_count_c(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count) { abort(); return 0; }

#pragma weak MPI_Get_elements
int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count) { return PMPI_Get_elements(status, datatype, count); }
int PMPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count) { abort(); return 0; }

#pragma weak MPI_Get_elements_c
int MPI_Get_elements_c(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count) { return PMPI_Get_elements_c(status, datatype, count); }
int PMPI_Get_elements_c(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count) { abort(); return 0; }

#pragma weak MPI_Get_elements_x
int MPI_Get_elements_x(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count) { return PMPI_Get_elements_x(status, datatype, count); }
int PMPI_Get_elements_x(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count) { abort(); return 0; }

#pragma weak MPI_Get_hw_resource_info
int MPI_Get_hw_resource_info(MPI_Info *hw_info) { return PMPI_Get_hw_resource_info(hw_info); }
int PMPI_Get_hw_resource_info(MPI_Info *hw_info) { abort(); return 0; }

#pragma weak MPI_Get_library_version
int MPI_Get_library_version(char *version, int *resultlen) { return PMPI_Get_library_version(version, resultlen); }
int PMPI_Get_library_version(char *version, int *resultlen) { return stubs_MPI_Get_library_version(version, resultlen); }

#pragma weak MPI_Get_processor_name
int MPI_Get_processor_name(char *name, int *resultlen) { return PMPI_Get_processor_name(name, resultlen); }
int PMPI_Get_processor_name(char *name, int *resultlen) { abort(); return 0; }

#pragma weak MPI_Get_version
int MPI_Get_version(int *version, int *subversion) { return PMPI_Get_version(version, subversion); }
int PMPI_Get_version(int *version, int *subversion) { return stubs_MPI_Get_version(version, subversion); }

#pragma weak MPI_Graph_create
int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int indx[], const int edges[], int reorder, MPI_Comm *comm_graph) { return PMPI_Graph_create(comm_old, nnodes, indx, edges, reorder, comm_graph); }
int PMPI_Graph_create(MPI_Comm comm_old, int nnodes, const int indx[], const int edges[], int reorder, MPI_Comm *comm_graph) { abort(); return 0; }

#pragma weak MPI_Graph_get
int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int indx[], int edges[]) { return PMPI_Graph_get(comm, maxindex, maxedges, indx, edges); }
int PMPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int indx[], int edges[]) { abort(); return 0; }

#pragma weak MPI_Graph_map
int MPI_Graph_map(MPI_Comm comm, int nnodes, const int indx[], const int edges[], int *newrank) { return PMPI_Graph_map(comm, nnodes, indx, edges, newrank); }
int PMPI_Graph_map(MPI_Comm comm, int nnodes, const int indx[], const int edges[], int *newrank) { abort(); return 0; }

#pragma weak MPI_Graph_neighbors
int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int neighbors[]) { return PMPI_Graph_neighbors(comm, rank, maxneighbors, neighbors); }
int PMPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int neighbors[]) { abort(); return 0; }

#pragma weak MPI_Graph_neighbors_count
int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors) { return PMPI_Graph_neighbors_count(comm, rank, nneighbors); }
int PMPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors) { abort(); return 0; }

#pragma weak MPI_Graphdims_get
int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges) { return PMPI_Graphdims_get(comm, nnodes, nedges); }
int PMPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges) { abort(); return 0; }

#pragma weak MPI_Grequest_complete
int MPI_Grequest_complete(MPI_Request request) { return PMPI_Grequest_complete(request); }
int PMPI_Grequest_complete(MPI_Request request) { abort(); return 0; }

#pragma weak MPI_Grequest_start
int MPI_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, MPI_Request *request) { return PMPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, request); }
int PMPI_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Group_compare
int MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result) { return PMPI_Group_compare(group1, group2, result); }
int PMPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result) { abort(); return 0; }

#pragma weak MPI_Group_difference
int MPI_Group_difference(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { return PMPI_Group_difference(group1, group2, newgroup); }
int PMPI_Group_difference(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { abort(); return 0; }

#pragma weak MPI_Group_excl
int MPI_Group_excl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup) { return PMPI_Group_excl(group, n, ranks, newgroup); }
int PMPI_Group_excl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup) { abort(); return 0; }

#pragma weak MPI_Group_free
int MPI_Group_free(MPI_Group *group) { return PMPI_Group_free(group); }
int PMPI_Group_free(MPI_Group *group) { abort(); return 0; }

#pragma weak MPI_Group_from_session_pset
int MPI_Group_from_session_pset(MPI_Session session, const char *pset_name, MPI_Group *newgroup) { return PMPI_Group_from_session_pset(session, pset_name, newgroup); }
int PMPI_Group_from_session_pset(MPI_Session session, const char *pset_name, MPI_Group *newgroup) { abort(); return 0; }

#pragma weak MPI_Group_incl
int MPI_Group_incl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup) { return PMPI_Group_incl(group, n, ranks, newgroup); }
int PMPI_Group_incl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup) { abort(); return 0; }

#pragma weak MPI_Group_intersection
int MPI_Group_intersection(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { return PMPI_Group_intersection(group1, group2, newgroup); }
int PMPI_Group_intersection(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { abort(); return 0; }

#pragma weak MPI_Group_range_excl
int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup) { return PMPI_Group_range_excl(group, n, ranges, newgroup); }
int PMPI_Group_range_excl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup) { abort(); return 0; }

#pragma weak MPI_Group_range_incl
int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup) { return PMPI_Group_range_incl(group, n, ranges, newgroup); }
int PMPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup) { abort(); return 0; }

#pragma weak MPI_Group_rank
int MPI_Group_rank(MPI_Group group, int *rank) { return PMPI_Group_rank(group, rank); }
int PMPI_Group_rank(MPI_Group group, int *rank) { abort(); return 0; }

#pragma weak MPI_Group_size
int MPI_Group_size(MPI_Group group, int *size) { return PMPI_Group_size(group, size); }
int PMPI_Group_size(MPI_Group group, int *size) { abort(); return 0; }

#pragma weak MPI_Group_translate_ranks
int MPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2, int ranks2[]) { return PMPI_Group_translate_ranks(group1, n, ranks1, group2, ranks2); }
int PMPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2, int ranks2[]) { abort(); return 0; }

#pragma weak MPI_Group_union
int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { return PMPI_Group_union(group1, group2, newgroup); }
int PMPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { abort(); return 0; }

#pragma weak MPI_Iallgather
int MPI_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
int PMPI_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iallgather_c
int MPI_Iallgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Iallgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
int PMPI_Iallgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iallgatherv
int MPI_Iallgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request); }
int PMPI_Iallgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iallgatherv_c
int MPI_Iallgatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Iallgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request); }
int PMPI_Iallgatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iallreduce
int MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return PMPI_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request); }
int PMPI_Iallreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iallreduce_c
int MPI_Iallreduce_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return PMPI_Iallreduce_c(sendbuf, recvbuf, count, datatype, op, comm, request); }
int PMPI_Iallreduce_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ialltoall
int MPI_Ialltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
int PMPI_Ialltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ialltoall_c
int MPI_Ialltoall_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ialltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
int PMPI_Ialltoall_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ialltoallv
int MPI_Ialltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request); }
int PMPI_Ialltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ialltoallv_c
int MPI_Ialltoallv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ialltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request); }
int PMPI_Ialltoallv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ialltoallw
int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { return PMPI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request); }
int PMPI_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ialltoallw_c
int MPI_Ialltoallw_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { return PMPI_Ialltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request); }
int PMPI_Ialltoallw_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ibarrier
int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request) { return PMPI_Ibarrier(comm, request); }
int PMPI_Ibarrier(MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ibcast
int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Ibcast(buffer, count, datatype, root, comm, request); }
int PMPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ibcast_c
int MPI_Ibcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Ibcast_c(buffer, count, datatype, root, comm, request); }
int PMPI_Ibcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ibsend
int MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Ibsend(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Ibsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ibsend_c
int MPI_Ibsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Ibsend_c(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Ibsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iexscan
int MPI_Iexscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return PMPI_Iexscan(sendbuf, recvbuf, count, datatype, op, comm, request); }
int PMPI_Iexscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iexscan_c
int MPI_Iexscan_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return PMPI_Iexscan_c(sendbuf, recvbuf, count, datatype, op, comm, request); }
int PMPI_Iexscan_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Igather
int MPI_Igather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }
int PMPI_Igather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Igather_c
int MPI_Igather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Igather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }
int PMPI_Igather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Igatherv
int MPI_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request); }
int PMPI_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Igatherv_c
int MPI_Igatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Igatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request); }
int PMPI_Igatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Improbe
int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status) { return PMPI_Improbe(source, tag, comm, flag, message, status); }
int PMPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Imrecv
int MPI_Imrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request) { return PMPI_Imrecv(buf, count, datatype, message, request); }
int PMPI_Imrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Imrecv_c
int MPI_Imrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request) { return PMPI_Imrecv_c(buf, count, datatype, message, request); }
int PMPI_Imrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ineighbor_allgather
int MPI_Ineighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
int PMPI_Ineighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ineighbor_allgather_c
int MPI_Ineighbor_allgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ineighbor_allgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
int PMPI_Ineighbor_allgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ineighbor_allgatherv
int MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request); }
int PMPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ineighbor_allgatherv_c
int MPI_Ineighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ineighbor_allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request); }
int PMPI_Ineighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ineighbor_alltoall
int MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
int PMPI_Ineighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ineighbor_alltoall_c
int MPI_Ineighbor_alltoall_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ineighbor_alltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }
int PMPI_Ineighbor_alltoall_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ineighbor_alltoallv
int MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request); }
int PMPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ineighbor_alltoallv_c
int MPI_Ineighbor_alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { return PMPI_Ineighbor_alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request); }
int PMPI_Ineighbor_alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ineighbor_alltoallw
int MPI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { return PMPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request); }
int PMPI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ineighbor_alltoallw_c
int MPI_Ineighbor_alltoallw_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { return PMPI_Ineighbor_alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request); }
int PMPI_Ineighbor_alltoallw_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Info_create
int MPI_Info_create(MPI_Info *info) { return PMPI_Info_create(info); }
int PMPI_Info_create(MPI_Info *info) { abort(); return 0; }

#pragma weak MPI_Info_create_env
int MPI_Info_create_env(int argc, char *argv[], MPI_Info *info) { return PMPI_Info_create_env(argc, argv, info); }
int PMPI_Info_create_env(int argc, char *argv[], MPI_Info *info) { abort(); return 0; }

#pragma weak MPI_Info_delete
int MPI_Info_delete(MPI_Info info, const char *key) { return PMPI_Info_delete(info, key); }
int PMPI_Info_delete(MPI_Info info, const char *key) { abort(); return 0; }

#pragma weak MPI_Info_dup
int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo) { return PMPI_Info_dup(info, newinfo); }
int PMPI_Info_dup(MPI_Info info, MPI_Info *newinfo) { abort(); return 0; }

#pragma weak MPI_Info_free
int MPI_Info_free(MPI_Info *info) { return PMPI_Info_free(info); }
int PMPI_Info_free(MPI_Info *info) { abort(); return 0; }

#pragma weak MPI_Info_get
int MPI_Info_get(MPI_Info info, const char *key, int valuelen, char *value, int *flag) { return PMPI_Info_get(info, key, valuelen, value, flag); }
int PMPI_Info_get(MPI_Info info, const char *key, int valuelen, char *value, int *flag) { abort(); return 0; }

#pragma weak MPI_Info_get_nkeys
int MPI_Info_get_nkeys(MPI_Info info, int *nkeys) { return PMPI_Info_get_nkeys(info, nkeys); }
int PMPI_Info_get_nkeys(MPI_Info info, int *nkeys) { abort(); return 0; }

#pragma weak MPI_Info_get_nthkey
int MPI_Info_get_nthkey(MPI_Info info, int n, char *key) { return PMPI_Info_get_nthkey(info, n, key); }
int PMPI_Info_get_nthkey(MPI_Info info, int n, char *key) { abort(); return 0; }

#pragma weak MPI_Info_get_string
int MPI_Info_get_string(MPI_Info info, const char *key, int *buflen, char *value, int *flag) { return PMPI_Info_get_string(info, key, buflen, value, flag); }
int PMPI_Info_get_string(MPI_Info info, const char *key, int *buflen, char *value, int *flag) { abort(); return 0; }

#pragma weak MPI_Info_get_valuelen
int MPI_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen, int *flag) { return PMPI_Info_get_valuelen(info, key, valuelen, flag); }
int PMPI_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen, int *flag) { abort(); return 0; }

#pragma weak MPI_Info_set
int MPI_Info_set(MPI_Info info, const char *key, const char *value) { return PMPI_Info_set(info, key, value); }
int PMPI_Info_set(MPI_Info info, const char *key, const char *value) { abort(); return 0; }

#pragma weak MPI_Init
int MPI_Init(int *argc, char ***argv) { return PMPI_Init(argc, argv); }
int PMPI_Init(int *argc, char ***argv) { abort(); return 0; }

#pragma weak MPI_Init_thread
int MPI_Init_thread(int *argc, char ***argv, int required, int *provided) { return PMPI_Init_thread(argc, argv, required, provided); }
int PMPI_Init_thread(int *argc, char ***argv, int required, int *provided) { abort(); return 0; }

#pragma weak MPI_Initialized
int MPI_Initialized(int *flag) { return PMPI_Initialized(flag); }
int PMPI_Initialized(int *flag) { return stubs_MPI_Initialized(flag); }

#pragma weak MPI_Intercomm_create
int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *newintercomm) { return PMPI_Intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm); }
int PMPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *newintercomm) { abort(); return 0; }

#pragma weak MPI_Intercomm_create_from_groups
int MPI_Intercomm_create_from_groups(MPI_Group local_group, int local_leader, MPI_Group remote_group, int remote_leader, const char *stringtag, MPI_Info info, MPI_Errhandler errhandler, MPI_Comm *newintercomm) { return PMPI_Intercomm_create_from_groups(local_group, local_leader, remote_group, remote_leader, stringtag, info, errhandler, newintercomm); }
int PMPI_Intercomm_create_from_groups(MPI_Group local_group, int local_leader, MPI_Group remote_group, int remote_leader, const char *stringtag, MPI_Info info, MPI_Errhandler errhandler, MPI_Comm *newintercomm) { abort(); return 0; }

#pragma weak MPI_Intercomm_merge
int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm) { return PMPI_Intercomm_merge(intercomm, high, newintracomm); }
int PMPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm) { abort(); return 0; }

#pragma weak MPI_Iprobe
int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status) { return PMPI_Iprobe(source, tag, comm, flag, status); }
int PMPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Irecv
int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Irecv(buf, count, datatype, source, tag, comm, request); }
int PMPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Irecv_c
int MPI_Irecv_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Irecv_c(buf, count, datatype, source, tag, comm, request); }
int PMPI_Irecv_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ireduce
int MPI_Ireduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request); }
int PMPI_Ireduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ireduce_c
int MPI_Ireduce_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Ireduce_c(sendbuf, recvbuf, count, datatype, op, root, comm, request); }
int PMPI_Ireduce_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ireduce_scatter
int MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return PMPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request); }
int PMPI_Ireduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ireduce_scatter_c
int MPI_Ireduce_scatter_c(const void *sendbuf, void *recvbuf, const MPI_Count recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return PMPI_Ireduce_scatter_c(sendbuf, recvbuf, recvcounts, datatype, op, comm, request); }
int PMPI_Ireduce_scatter_c(const void *sendbuf, void *recvbuf, const MPI_Count recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ireduce_scatter_block
int MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return PMPI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request); }
int PMPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ireduce_scatter_block_c
int MPI_Ireduce_scatter_block_c(const void *sendbuf, void *recvbuf, MPI_Count recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return PMPI_Ireduce_scatter_block_c(sendbuf, recvbuf, recvcount, datatype, op, comm, request); }
int PMPI_Ireduce_scatter_block_c(const void *sendbuf, void *recvbuf, MPI_Count recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Irsend
int MPI_Irsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Irsend(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Irsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Irsend_c
int MPI_Irsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Irsend_c(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Irsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Is_thread_main
int MPI_Is_thread_main(int *flag) { return PMPI_Is_thread_main(flag); }
int PMPI_Is_thread_main(int *flag) { abort(); return 0; }

#pragma weak MPI_Iscan
int MPI_Iscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return PMPI_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request); }
int PMPI_Iscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iscan_c
int MPI_Iscan_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { return PMPI_Iscan_c(sendbuf, recvbuf, count, datatype, op, comm, request); }
int PMPI_Iscan_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iscatter
int MPI_Iscatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }
int PMPI_Iscatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iscatter_c
int MPI_Iscatter_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Iscatter_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }
int PMPI_Iscatter_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iscatterv
int MPI_Iscatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }
int PMPI_Iscatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Iscatterv_c
int MPI_Iscatterv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { return PMPI_Iscatterv_c(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }
int PMPI_Iscatterv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Isend
int MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Isend(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Isend_c
int MPI_Isend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Isend_c(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Isend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Isendrecv
int MPI_Isendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Request *request) { return PMPI_Isendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, request); }
int PMPI_Isendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Isendrecv_c
int MPI_Isendrecv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Request *request) { return PMPI_Isendrecv_c(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, request); }
int PMPI_Isendrecv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Isendrecv_replace
int MPI_Isendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Request *request) { return PMPI_Isendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, request); }
int PMPI_Isendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Isendrecv_replace_c
int MPI_Isendrecv_replace_c(void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Request *request) { return PMPI_Isendrecv_replace_c(buf, count, datatype, dest, sendtag, source, recvtag, comm, request); }
int PMPI_Isendrecv_replace_c(void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Issend
int MPI_Issend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Issend(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Issend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Issend_c
int MPI_Issend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Issend_c(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Issend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Keyval_create
int MPI_Keyval_create(MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval, void *extra_state) { return PMPI_Keyval_create(copy_fn, delete_fn, keyval, extra_state); }
int PMPI_Keyval_create(MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval, void *extra_state) { abort(); return 0; }

#pragma weak MPI_Keyval_free
int MPI_Keyval_free(int *keyval) { return PMPI_Keyval_free(keyval); }
int PMPI_Keyval_free(int *keyval) { abort(); return 0; }

#pragma weak MPI_Lookup_name
int MPI_Lookup_name(const char *service_name, MPI_Info info, char *port_name) { return PMPI_Lookup_name(service_name, info, port_name); }
int PMPI_Lookup_name(const char *service_name, MPI_Info info, char *port_name) { abort(); return 0; }

#pragma weak MPI_Mprobe
int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message, MPI_Status *status) { return PMPI_Mprobe(source, tag, comm, message, status); }
int PMPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Mrecv
int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Status *status) { return PMPI_Mrecv(buf, count, datatype, message, status); }
int PMPI_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Mrecv_c
int MPI_Mrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Message *message, MPI_Status *status) { return PMPI_Mrecv_c(buf, count, datatype, message, status); }
int PMPI_Mrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Message *message, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Neighbor_allgather
int MPI_Neighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
int PMPI_Neighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Neighbor_allgather_c
int MPI_Neighbor_allgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Neighbor_allgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
int PMPI_Neighbor_allgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Neighbor_allgather_init
int MPI_Neighbor_allgather_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Neighbor_allgather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request); }
int PMPI_Neighbor_allgather_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Neighbor_allgather_init_c
int MPI_Neighbor_allgather_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Neighbor_allgather_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request); }
int PMPI_Neighbor_allgather_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Neighbor_allgatherv
int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm); }
int PMPI_Neighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Neighbor_allgatherv_c
int MPI_Neighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Neighbor_allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm); }
int PMPI_Neighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Neighbor_allgatherv_init
int MPI_Neighbor_allgatherv_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Neighbor_allgatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request); }
int PMPI_Neighbor_allgatherv_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Neighbor_allgatherv_init_c
int MPI_Neighbor_allgatherv_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Neighbor_allgatherv_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request); }
int PMPI_Neighbor_allgatherv_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoall
int MPI_Neighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
int PMPI_Neighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoall_c
int MPI_Neighbor_alltoall_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Neighbor_alltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }
int PMPI_Neighbor_alltoall_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoall_init
int MPI_Neighbor_alltoall_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Neighbor_alltoall_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request); }
int PMPI_Neighbor_alltoall_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoall_init_c
int MPI_Neighbor_alltoall_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Neighbor_alltoall_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request); }
int PMPI_Neighbor_alltoall_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoallv
int MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm); }
int PMPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoallv_c
int MPI_Neighbor_alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { return PMPI_Neighbor_alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm); }
int PMPI_Neighbor_alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoallv_init
int MPI_Neighbor_alltoallv_init(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Neighbor_alltoallv_init(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request); }
int PMPI_Neighbor_alltoallv_init(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoallv_init_c
int MPI_Neighbor_alltoallv_init_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Neighbor_alltoallv_init_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request); }
int PMPI_Neighbor_alltoallv_init_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoallw
int MPI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) { return PMPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm); }
int PMPI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoallw_c
int MPI_Neighbor_alltoallw_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) { return PMPI_Neighbor_alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm); }
int PMPI_Neighbor_alltoallw_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoallw_init
int MPI_Neighbor_alltoallw_init(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Neighbor_alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request); }
int PMPI_Neighbor_alltoallw_init(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Neighbor_alltoallw_init_c
int MPI_Neighbor_alltoallw_init_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Neighbor_alltoallw_init_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request); }
int PMPI_Neighbor_alltoallw_init_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Op_commutative
int MPI_Op_commutative(MPI_Op op, int *commute) { return PMPI_Op_commutative(op, commute); }
int PMPI_Op_commutative(MPI_Op op, int *commute) { abort(); return 0; }

#pragma weak MPI_Op_create
int MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op) { return PMPI_Op_create(user_fn, commute, op); }
int PMPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op) { abort(); return 0; }

#pragma weak MPI_Op_create_c
int MPI_Op_create_c(MPI_User_function_c *user_fn, int commute, MPI_Op *op) { return PMPI_Op_create_c(user_fn, commute, op); }
int PMPI_Op_create_c(MPI_User_function_c *user_fn, int commute, MPI_Op *op) { abort(); return 0; }

#pragma weak MPI_Op_free
int MPI_Op_free(MPI_Op *op) { return PMPI_Op_free(op); }
int PMPI_Op_free(MPI_Op *op) { abort(); return 0; }

#pragma weak MPI_Open_port
int MPI_Open_port(MPI_Info info, char *port_name) { return PMPI_Open_port(info, port_name); }
int PMPI_Open_port(MPI_Info info, char *port_name) { abort(); return 0; }

#pragma weak MPI_Pack
int MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position, MPI_Comm comm) { return PMPI_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm); }
int PMPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Pack_c
int MPI_Pack_c(const void *inbuf, MPI_Count incount, MPI_Datatype datatype, void *outbuf, MPI_Count outsize, MPI_Count *position, MPI_Comm comm) { return PMPI_Pack_c(inbuf, incount, datatype, outbuf, outsize, position, comm); }
int PMPI_Pack_c(const void *inbuf, MPI_Count incount, MPI_Datatype datatype, void *outbuf, MPI_Count outsize, MPI_Count *position, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Pack_external
int MPI_Pack_external(const char *datarep, const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, MPI_Aint outsize, MPI_Aint *position) { return PMPI_Pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position); }
int PMPI_Pack_external(const char *datarep, const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, MPI_Aint outsize, MPI_Aint *position) { abort(); return 0; }

#pragma weak MPI_Pack_external_c
int MPI_Pack_external_c(const char *datarep, const void *inbuf, MPI_Count incount, MPI_Datatype datatype, void *outbuf, MPI_Count outsize, MPI_Count *position) { return PMPI_Pack_external_c(datarep, inbuf, incount, datatype, outbuf, outsize, position); }
int PMPI_Pack_external_c(const char *datarep, const void *inbuf, MPI_Count incount, MPI_Datatype datatype, void *outbuf, MPI_Count outsize, MPI_Count *position) { abort(); return 0; }

#pragma weak MPI_Pack_external_size
int MPI_Pack_external_size(const char *datarep, int incount, MPI_Datatype datatype, MPI_Aint *size) { return PMPI_Pack_external_size(datarep, incount, datatype, size); }
int PMPI_Pack_external_size(const char *datarep, int incount, MPI_Datatype datatype, MPI_Aint *size) { abort(); return 0; }

#pragma weak MPI_Pack_external_size_c
int MPI_Pack_external_size_c(const char *datarep, MPI_Count incount, MPI_Datatype datatype, MPI_Count *size) { return PMPI_Pack_external_size_c(datarep, incount, datatype, size); }
int PMPI_Pack_external_size_c(const char *datarep, MPI_Count incount, MPI_Datatype datatype, MPI_Count *size) { abort(); return 0; }

#pragma weak MPI_Pack_size
int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size) { return PMPI_Pack_size(incount, datatype, comm, size); }
int PMPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size) { abort(); return 0; }

#pragma weak MPI_Pack_size_c
int MPI_Pack_size_c(MPI_Count incount, MPI_Datatype datatype, MPI_Comm comm, MPI_Count *size) { return PMPI_Pack_size_c(incount, datatype, comm, size); }
int PMPI_Pack_size_c(MPI_Count incount, MPI_Datatype datatype, MPI_Comm comm, MPI_Count *size) { abort(); return 0; }

#pragma weak MPI_Parrived
int MPI_Parrived(MPI_Request request, int partition, int *flag) { return PMPI_Parrived(request, partition, flag); }
int PMPI_Parrived(MPI_Request request, int partition, int *flag) { abort(); return 0; }

#pragma weak MPI_Pcontrol
int MPI_Pcontrol(const int level, ...) { return PMPI_Pcontrol(level); }
int PMPI_Pcontrol(const int level, ...) { abort(); return 0; }

#pragma weak MPI_Pready
int MPI_Pready(int partition, MPI_Request request) { return PMPI_Pready(partition, request); }
int PMPI_Pready(int partition, MPI_Request request) { abort(); return 0; }

#pragma weak MPI_Pready_list
int MPI_Pready_list(int length, const int array_of_partitions[], MPI_Request request) { return PMPI_Pready_list(length, array_of_partitions, request); }
int PMPI_Pready_list(int length, const int array_of_partitions[], MPI_Request request) { abort(); return 0; }

#pragma weak MPI_Pready_range
int MPI_Pready_range(int partition_low, int partition_high, MPI_Request request) { return PMPI_Pready_range(partition_low, partition_high, request); }
int PMPI_Pready_range(int partition_low, int partition_high, MPI_Request request) { abort(); return 0; }

#pragma weak MPI_Precv_init
int MPI_Precv_init(void *buf, int partitions, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Precv_init(buf, partitions, count, datatype, dest, tag, comm, info, request); }
int PMPI_Precv_init(void *buf, int partitions, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Precv_init_c
int MPI_Precv_init_c(void *buf, int partitions, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Precv_init_c(buf, partitions, count, datatype, dest, tag, comm, info, request); }
int PMPI_Precv_init_c(void *buf, int partitions, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Probe
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) { return PMPI_Probe(source, tag, comm, status); }
int PMPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Psend_init
int MPI_Psend_init(const void *buf, int partitions, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Psend_init(buf, partitions, count, datatype, dest, tag, comm, info, request); }
int PMPI_Psend_init(const void *buf, int partitions, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Psend_init_c
int MPI_Psend_init_c(const void *buf, int partitions, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Psend_init_c(buf, partitions, count, datatype, dest, tag, comm, info, request); }
int PMPI_Psend_init_c(const void *buf, int partitions, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Publish_name
int MPI_Publish_name(const char *service_name, MPI_Info info, const char *port_name) { return PMPI_Publish_name(service_name, info, port_name); }
int PMPI_Publish_name(const char *service_name, MPI_Info info, const char *port_name) { abort(); return 0; }

#pragma weak MPI_Put
int MPI_Put(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win) { return PMPI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win); }
int PMPI_Put(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Put_c
int MPI_Put_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Win win) { return PMPI_Put_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win); }
int PMPI_Put_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Query_thread
int MPI_Query_thread(int *provided) { return PMPI_Query_thread(provided); }
int PMPI_Query_thread(int *provided) { abort(); return 0; }

#pragma weak MPI_Raccumulate
int MPI_Raccumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { return PMPI_Raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request); }
int PMPI_Raccumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Raccumulate_c
int MPI_Raccumulate_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { return PMPI_Raccumulate_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request); }
int PMPI_Raccumulate_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Recv
int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status) { return PMPI_Recv(buf, count, datatype, source, tag, comm, status); }
int PMPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Recv_c
int MPI_Recv_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status) { return PMPI_Recv_c(buf, count, datatype, source, tag, comm, status); }
int PMPI_Recv_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Recv_init
int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Recv_init(buf, count, datatype, source, tag, comm, request); }
int PMPI_Recv_init(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Recv_init_c
int MPI_Recv_init_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Recv_init_c(buf, count, datatype, source, tag, comm, request); }
int PMPI_Recv_init_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Reduce
int MPI_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm) { return PMPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm); }
int PMPI_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Reduce_c
int MPI_Reduce_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm) { return PMPI_Reduce_c(sendbuf, recvbuf, count, datatype, op, root, comm); }
int PMPI_Reduce_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Reduce_init
int MPI_Reduce_init(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Reduce_init(sendbuf, recvbuf, count, datatype, op, root, comm, info, request); }
int PMPI_Reduce_init(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Reduce_init_c
int MPI_Reduce_init_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Reduce_init_c(sendbuf, recvbuf, count, datatype, op, root, comm, info, request); }
int PMPI_Reduce_init_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Reduce_local
int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count, MPI_Datatype datatype, MPI_Op op) { return PMPI_Reduce_local(inbuf, inoutbuf, count, datatype, op); }
int PMPI_Reduce_local(const void *inbuf, void *inoutbuf, int count, MPI_Datatype datatype, MPI_Op op) { abort(); return 0; }

#pragma weak MPI_Reduce_local_c
int MPI_Reduce_local_c(const void *inbuf, void *inoutbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op) { return PMPI_Reduce_local_c(inbuf, inoutbuf, count, datatype, op); }
int PMPI_Reduce_local_c(const void *inbuf, void *inoutbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op) { abort(); return 0; }

#pragma weak MPI_Reduce_scatter
int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return PMPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm); }
int PMPI_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Reduce_scatter_c
int MPI_Reduce_scatter_c(const void *sendbuf, void *recvbuf, const MPI_Count recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return PMPI_Reduce_scatter_c(sendbuf, recvbuf, recvcounts, datatype, op, comm); }
int PMPI_Reduce_scatter_c(const void *sendbuf, void *recvbuf, const MPI_Count recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Reduce_scatter_block
int MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return PMPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm); }
int PMPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Reduce_scatter_block_c
int MPI_Reduce_scatter_block_c(const void *sendbuf, void *recvbuf, MPI_Count recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return PMPI_Reduce_scatter_block_c(sendbuf, recvbuf, recvcount, datatype, op, comm); }
int PMPI_Reduce_scatter_block_c(const void *sendbuf, void *recvbuf, MPI_Count recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Reduce_scatter_block_init
int MPI_Reduce_scatter_block_init(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Reduce_scatter_block_init(sendbuf, recvbuf, recvcount, datatype, op, comm, info, request); }
int PMPI_Reduce_scatter_block_init(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Reduce_scatter_block_init_c
int MPI_Reduce_scatter_block_init_c(const void *sendbuf, void *recvbuf, MPI_Count recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Reduce_scatter_block_init_c(sendbuf, recvbuf, recvcount, datatype, op, comm, info, request); }
int PMPI_Reduce_scatter_block_init_c(const void *sendbuf, void *recvbuf, MPI_Count recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Reduce_scatter_init
int MPI_Reduce_scatter_init(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Reduce_scatter_init(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request); }
int PMPI_Reduce_scatter_init(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Reduce_scatter_init_c
int MPI_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf, const MPI_Count recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Reduce_scatter_init_c(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request); }
int PMPI_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf, const MPI_Count recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Register_datarep
int MPI_Register_datarep(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) { return PMPI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state); }
int PMPI_Register_datarep(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) { abort(); return 0; }

#pragma weak MPI_Register_datarep_c
int MPI_Register_datarep_c(const char *datarep, MPI_Datarep_conversion_function_c *read_conversion_fn, MPI_Datarep_conversion_function_c *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) { return PMPI_Register_datarep_c(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state); }
int PMPI_Register_datarep_c(const char *datarep, MPI_Datarep_conversion_function_c *read_conversion_fn, MPI_Datarep_conversion_function_c *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) { abort(); return 0; }

#pragma weak MPI_Remove_error_class
int MPI_Remove_error_class(int errorclass) { return PMPI_Remove_error_class(errorclass); }
int PMPI_Remove_error_class(int errorclass) { abort(); return 0; }

#pragma weak MPI_Remove_error_code
int MPI_Remove_error_code(int errorcode) { return PMPI_Remove_error_code(errorcode); }
int PMPI_Remove_error_code(int errorcode) { abort(); return 0; }

#pragma weak MPI_Remove_error_string
int MPI_Remove_error_string(int errorcode) { return PMPI_Remove_error_string(errorcode); }
int PMPI_Remove_error_string(int errorcode) { abort(); return 0; }

#pragma weak MPI_Request_free
int MPI_Request_free(MPI_Request *request) { return PMPI_Request_free(request); }
int PMPI_Request_free(MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Request_get_status
int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status) { return PMPI_Request_get_status(request, flag, status); }
int PMPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Request_get_status_all
int MPI_Request_get_status_all(int count, const MPI_Request array_of_requests[], int *flag, MPI_Status *array_of_statuses) { return PMPI_Request_get_status_all(count, array_of_requests, flag, array_of_statuses); }
int PMPI_Request_get_status_all(int count, const MPI_Request array_of_requests[], int *flag, MPI_Status *array_of_statuses) { abort(); return 0; }

#pragma weak MPI_Request_get_status_any
int MPI_Request_get_status_any(int count, const MPI_Request array_of_requests[], int *indx, int *flag, MPI_Status *status) { return PMPI_Request_get_status_any(count, array_of_requests, indx, flag, status); }
int PMPI_Request_get_status_any(int count, const MPI_Request array_of_requests[], int *indx, int *flag, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Request_get_status_some
int MPI_Request_get_status_some(int incount, const MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status *array_of_statuses) { return PMPI_Request_get_status_some(incount, array_of_requests, outcount, array_of_indices, array_of_statuses); }
int PMPI_Request_get_status_some(int incount, const MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status *array_of_statuses) { abort(); return 0; }

#pragma weak MPI_Rget
int MPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) { return PMPI_Rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request); }
int PMPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Rget_c
int MPI_Rget_c(void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) { return PMPI_Rget_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request); }
int PMPI_Rget_c(void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Rget_accumulate
int MPI_Rget_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { return PMPI_Rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request); }
int PMPI_Rget_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Rget_accumulate_c
int MPI_Rget_accumulate_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, void *result_addr, MPI_Count result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { return PMPI_Rget_accumulate_c(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request); }
int PMPI_Rget_accumulate_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, void *result_addr, MPI_Count result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Rput
int MPI_Rput(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) { return PMPI_Rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request); }
int PMPI_Rput(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Rput_c
int MPI_Rput_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) { return PMPI_Rput_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request); }
int PMPI_Rput_c(const void *origin_addr, MPI_Count origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, MPI_Count target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Rsend
int MPI_Rsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return PMPI_Rsend(buf, count, datatype, dest, tag, comm); }
int PMPI_Rsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Rsend_c
int MPI_Rsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return PMPI_Rsend_c(buf, count, datatype, dest, tag, comm); }
int PMPI_Rsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Rsend_init
int MPI_Rsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Rsend_init(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Rsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Rsend_init_c
int MPI_Rsend_init_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Rsend_init_c(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Rsend_init_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Scan
int MPI_Scan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return PMPI_Scan(sendbuf, recvbuf, count, datatype, op, comm); }
int PMPI_Scan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Scan_c
int MPI_Scan_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { return PMPI_Scan_c(sendbuf, recvbuf, count, datatype, op, comm); }
int PMPI_Scan_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Scan_init
int MPI_Scan_init(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Scan_init(sendbuf, recvbuf, count, datatype, op, comm, info, request); }
int PMPI_Scan_init(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Scan_init_c
int MPI_Scan_init_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Scan_init_c(sendbuf, recvbuf, count, datatype, op, comm, info, request); }
int PMPI_Scan_init_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Scatter
int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { return PMPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm); }
int PMPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Scatter_c
int MPI_Scatter_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { return PMPI_Scatter_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm); }
int PMPI_Scatter_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Scatter_init
int MPI_Scatter_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Scatter_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request); }
int PMPI_Scatter_init(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Scatter_init_c
int MPI_Scatter_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Scatter_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request); }
int PMPI_Scatter_init_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Scatterv
int MPI_Scatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { return PMPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm); }
int PMPI_Scatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Scatterv_c
int MPI_Scatterv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { return PMPI_Scatterv_c(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm); }
int PMPI_Scatterv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Scatterv_init
int MPI_Scatterv_init(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Scatterv_init(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request); }
int PMPI_Scatterv_init(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Scatterv_init_c
int MPI_Scatterv_init_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { return PMPI_Scatterv_init_c(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request); }
int PMPI_Scatterv_init_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Info info, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Send
int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return PMPI_Send(buf, count, datatype, dest, tag, comm); }
int PMPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Send_c
int MPI_Send_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return PMPI_Send_c(buf, count, datatype, dest, tag, comm); }
int PMPI_Send_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Send_init
int MPI_Send_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Send_init(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Send_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Send_init_c
int MPI_Send_init_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Send_init_c(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Send_init_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Sendrecv
int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { return PMPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status); }
int PMPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Sendrecv_c
int MPI_Sendrecv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { return PMPI_Sendrecv_c(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status); }
int PMPI_Sendrecv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Sendrecv_replace
int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { return PMPI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status); }
int PMPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Sendrecv_replace_c
int MPI_Sendrecv_replace_c(void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { return PMPI_Sendrecv_replace_c(buf, count, datatype, dest, sendtag, source, recvtag, comm, status); }
int PMPI_Sendrecv_replace_c(void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Session_attach_buffer
int MPI_Session_attach_buffer(MPI_Session session, void *buffer, int size) { return PMPI_Session_attach_buffer(session, buffer, size); }
int PMPI_Session_attach_buffer(MPI_Session session, void *buffer, int size) { abort(); return 0; }

#pragma weak MPI_Session_attach_buffer_c
int MPI_Session_attach_buffer_c(MPI_Session session, void *buffer, MPI_Count size) { return PMPI_Session_attach_buffer_c(session, buffer, size); }
int PMPI_Session_attach_buffer_c(MPI_Session session, void *buffer, MPI_Count size) { abort(); return 0; }

#pragma weak MPI_Session_call_errhandler
int MPI_Session_call_errhandler(MPI_Session session, int errorcode) { return PMPI_Session_call_errhandler(session, errorcode); }
int PMPI_Session_call_errhandler(MPI_Session session, int errorcode) { abort(); return 0; }

#pragma weak MPI_Session_create_errhandler
int MPI_Session_create_errhandler(MPI_Session_errhandler_function *session_errhandler_fn, MPI_Errhandler *errhandler) { return PMPI_Session_create_errhandler(session_errhandler_fn, errhandler); }
int PMPI_Session_create_errhandler(MPI_Session_errhandler_function *session_errhandler_fn, MPI_Errhandler *errhandler) { abort(); return 0; }

#pragma weak MPI_Session_detach_buffer
int MPI_Session_detach_buffer(MPI_Session session, void *buffer_addr, int *size) { return PMPI_Session_detach_buffer(session, buffer_addr, size); }
int PMPI_Session_detach_buffer(MPI_Session session, void *buffer_addr, int *size) { abort(); return 0; }

#pragma weak MPI_Session_detach_buffer_c
int MPI_Session_detach_buffer_c(MPI_Session session, void *buffer_addr, MPI_Count *size) { return PMPI_Session_detach_buffer_c(session, buffer_addr, size); }
int PMPI_Session_detach_buffer_c(MPI_Session session, void *buffer_addr, MPI_Count *size) { abort(); return 0; }

#pragma weak MPI_Session_finalize
int MPI_Session_finalize(MPI_Session *session) { return PMPI_Session_finalize(session); }
int PMPI_Session_finalize(MPI_Session *session) { abort(); return 0; }

#pragma weak MPI_Session_flush_buffer
int MPI_Session_flush_buffer(MPI_Session session) { return PMPI_Session_flush_buffer(session); }
int PMPI_Session_flush_buffer(MPI_Session session) { abort(); return 0; }

#pragma weak MPI_Session_get_errhandler
int MPI_Session_get_errhandler(MPI_Session session, MPI_Errhandler *errhandler) { return PMPI_Session_get_errhandler(session, errhandler); }
int PMPI_Session_get_errhandler(MPI_Session session, MPI_Errhandler *errhandler) { abort(); return 0; }

#pragma weak MPI_Session_get_info
int MPI_Session_get_info(MPI_Session session, MPI_Info *info_used) { return PMPI_Session_get_info(session, info_used); }
int PMPI_Session_get_info(MPI_Session session, MPI_Info *info_used) { abort(); return 0; }

#pragma weak MPI_Session_get_nth_pset
int MPI_Session_get_nth_pset(MPI_Session session, MPI_Info info, int n, int *pset_len, char *pset_name) { return PMPI_Session_get_nth_pset(session, info, n, pset_len, pset_name); }
int PMPI_Session_get_nth_pset(MPI_Session session, MPI_Info info, int n, int *pset_len, char *pset_name) { abort(); return 0; }

#pragma weak MPI_Session_get_num_psets
int MPI_Session_get_num_psets(MPI_Session session, MPI_Info info, int *npset_names) { return PMPI_Session_get_num_psets(session, info, npset_names); }
int PMPI_Session_get_num_psets(MPI_Session session, MPI_Info info, int *npset_names) { abort(); return 0; }

#pragma weak MPI_Session_get_pset_info
int MPI_Session_get_pset_info(MPI_Session session, const char *pset_name, MPI_Info *info) { return PMPI_Session_get_pset_info(session, pset_name, info); }
int PMPI_Session_get_pset_info(MPI_Session session, const char *pset_name, MPI_Info *info) { abort(); return 0; }

#pragma weak MPI_Session_iflush_buffer
int MPI_Session_iflush_buffer(MPI_Session session, MPI_Request *request) { return PMPI_Session_iflush_buffer(session, request); }
int PMPI_Session_iflush_buffer(MPI_Session session, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Session_init
int MPI_Session_init(MPI_Info info, MPI_Errhandler errhandler, MPI_Session *session) { return PMPI_Session_init(info, errhandler, session); }
int PMPI_Session_init(MPI_Info info, MPI_Errhandler errhandler, MPI_Session *session) { abort(); return 0; }

#pragma weak MPI_Session_set_errhandler
int MPI_Session_set_errhandler(MPI_Session session, MPI_Errhandler errhandler) { return PMPI_Session_set_errhandler(session, errhandler); }
int PMPI_Session_set_errhandler(MPI_Session session, MPI_Errhandler errhandler) { abort(); return 0; }

#pragma weak MPI_Ssend
int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return PMPI_Ssend(buf, count, datatype, dest, tag, comm); }
int PMPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Ssend_c
int MPI_Ssend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { return PMPI_Ssend_c(buf, count, datatype, dest, tag, comm); }
int PMPI_Ssend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Ssend_init
int MPI_Ssend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Ssend_init(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Ssend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Ssend_init_c
int MPI_Ssend_init_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { return PMPI_Ssend_init_c(buf, count, datatype, dest, tag, comm, request); }
int PMPI_Ssend_init_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Start
int MPI_Start(MPI_Request *request) { return PMPI_Start(request); }
int PMPI_Start(MPI_Request *request) { abort(); return 0; }

#pragma weak MPI_Startall
int MPI_Startall(int count, MPI_Request array_of_requests[]) { return PMPI_Startall(count, array_of_requests); }
int PMPI_Startall(int count, MPI_Request array_of_requests[]) { abort(); return 0; }

#pragma weak MPI_Status_get_error
int MPI_Status_get_error(const MPI_Status *status, int *error) { return PMPI_Status_get_error(status, error); }
int PMPI_Status_get_error(const MPI_Status *status, int *error) { abort(); return 0; }

#pragma weak MPI_Status_get_source
int MPI_Status_get_source(const MPI_Status *status, int *source) { return PMPI_Status_get_source(status, source); }
int PMPI_Status_get_source(const MPI_Status *status, int *source) { abort(); return 0; }

#pragma weak MPI_Status_get_tag
int MPI_Status_get_tag(const MPI_Status *status, int *tag) { return PMPI_Status_get_tag(status, tag); }
int PMPI_Status_get_tag(const MPI_Status *status, int *tag) { abort(); return 0; }

#pragma weak MPI_Status_set_cancelled
int MPI_Status_set_cancelled(MPI_Status *status, int flag) { return PMPI_Status_set_cancelled(status, flag); }
int PMPI_Status_set_cancelled(MPI_Status *status, int flag) { abort(); return 0; }

#pragma weak MPI_Status_set_elements
int MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype, int count) { return PMPI_Status_set_elements(status, datatype, count); }
int PMPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype, int count) { abort(); return 0; }

#pragma weak MPI_Status_set_elements_c
int MPI_Status_set_elements_c(MPI_Status *status, MPI_Datatype datatype, MPI_Count count) { return PMPI_Status_set_elements_c(status, datatype, count); }
int PMPI_Status_set_elements_c(MPI_Status *status, MPI_Datatype datatype, MPI_Count count) { abort(); return 0; }

#pragma weak MPI_Status_set_elements_x
int MPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype, MPI_Count count) { return PMPI_Status_set_elements_x(status, datatype, count); }
int PMPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype, MPI_Count count) { abort(); return 0; }

#pragma weak MPI_Status_set_error
int MPI_Status_set_error(MPI_Status *status, int error) { return PMPI_Status_set_error(status, error); }
int PMPI_Status_set_error(MPI_Status *status, int error) { abort(); return 0; }

#pragma weak MPI_Status_set_source
int MPI_Status_set_source(MPI_Status *status, int source) { return PMPI_Status_set_source(status, source); }
int PMPI_Status_set_source(MPI_Status *status, int source) { abort(); return 0; }

#pragma weak MPI_Status_set_tag
int MPI_Status_set_tag(MPI_Status *status, int tag) { return PMPI_Status_set_tag(status, tag); }
int PMPI_Status_set_tag(MPI_Status *status, int tag) { abort(); return 0; }

#pragma weak MPI_Test
int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status) { return PMPI_Test(request, flag, status); }
int PMPI_Test(MPI_Request *request, int *flag, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Test_cancelled
int MPI_Test_cancelled(const MPI_Status *status, int *flag) { return PMPI_Test_cancelled(status, flag); }
int PMPI_Test_cancelled(const MPI_Status *status, int *flag) { abort(); return 0; }

#pragma weak MPI_Testall
int MPI_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status *array_of_statuses) { return PMPI_Testall(count, array_of_requests, flag, array_of_statuses); }
int PMPI_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status *array_of_statuses) { abort(); return 0; }

#pragma weak MPI_Testany
int MPI_Testany(int count, MPI_Request array_of_requests[], int *indx, int *flag, MPI_Status *status) { return PMPI_Testany(count, array_of_requests, indx, flag, status); }
int PMPI_Testany(int count, MPI_Request array_of_requests[], int *indx, int *flag, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Testsome
int MPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status *array_of_statuses) { return PMPI_Testsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses); }
int PMPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status *array_of_statuses) { abort(); return 0; }

#pragma weak MPI_Topo_test
int MPI_Topo_test(MPI_Comm comm, int *status) { return PMPI_Topo_test(comm, status); }
int PMPI_Topo_test(MPI_Comm comm, int *status) { abort(); return 0; }

#pragma weak MPI_Type_commit
int MPI_Type_commit(MPI_Datatype *datatype) { return PMPI_Type_commit(datatype); }
int PMPI_Type_commit(MPI_Datatype *datatype) { abort(); return 0; }

#pragma weak MPI_Type_contiguous
int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_contiguous(count, oldtype, newtype); }
int PMPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_contiguous_c
int MPI_Type_contiguous_c(MPI_Count count, MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_contiguous_c(count, oldtype, newtype); }
int PMPI_Type_contiguous_c(MPI_Count count, MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_darray
int MPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype); }
int PMPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_darray_c
int MPI_Type_create_darray_c(int size, int rank, int ndims, const MPI_Count array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_darray_c(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype); }
int PMPI_Type_create_darray_c(int size, int rank, int ndims, const MPI_Count array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_f90_complex
int MPI_Type_create_f90_complex(int p, int r, MPI_Datatype *newtype) { return PMPI_Type_create_f90_complex(p, r, newtype); }
int PMPI_Type_create_f90_complex(int p, int r, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_f90_integer
int MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype) { return PMPI_Type_create_f90_integer(r, newtype); }
int PMPI_Type_create_f90_integer(int r, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_f90_real
int MPI_Type_create_f90_real(int p, int r, MPI_Datatype *newtype) { return PMPI_Type_create_f90_real(p, r, newtype); }
int PMPI_Type_create_f90_real(int p, int r, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_hindexed
int MPI_Type_create_hindexed(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype); }
int PMPI_Type_create_hindexed(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_hindexed_c
int MPI_Type_create_hindexed_c(MPI_Count count, const MPI_Count array_of_blocklengths[], const MPI_Count array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_hindexed_c(count, array_of_blocklengths, array_of_displacements, oldtype, newtype); }
int PMPI_Type_create_hindexed_c(MPI_Count count, const MPI_Count array_of_blocklengths[], const MPI_Count array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_hindexed_block
int MPI_Type_create_hindexed_block(int count, int blocklength, const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_hindexed_block(count, blocklength, array_of_displacements, oldtype, newtype); }
int PMPI_Type_create_hindexed_block(int count, int blocklength, const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_hindexed_block_c
int MPI_Type_create_hindexed_block_c(MPI_Count count, MPI_Count blocklength, const MPI_Count array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_hindexed_block_c(count, blocklength, array_of_displacements, oldtype, newtype); }
int PMPI_Type_create_hindexed_block_c(MPI_Count count, MPI_Count blocklength, const MPI_Count array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_hvector
int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_hvector(count, blocklength, stride, oldtype, newtype); }
int PMPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_hvector_c
int MPI_Type_create_hvector_c(MPI_Count count, MPI_Count blocklength, MPI_Count stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_hvector_c(count, blocklength, stride, oldtype, newtype); }
int PMPI_Type_create_hvector_c(MPI_Count count, MPI_Count blocklength, MPI_Count stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_indexed_block
int MPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype); }
int PMPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_indexed_block_c
int MPI_Type_create_indexed_block_c(MPI_Count count, MPI_Count blocklength, const MPI_Count array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_indexed_block_c(count, blocklength, array_of_displacements, oldtype, newtype); }
int PMPI_Type_create_indexed_block_c(MPI_Count count, MPI_Count blocklength, const MPI_Count array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_keyval
int MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn, MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval, void *extra_state) { return PMPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state); }
int PMPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn, MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval, void *extra_state) { abort(); return 0; }

#pragma weak MPI_Type_create_resized
int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Datatype *newtype) { return PMPI_Type_create_resized(oldtype, lb, extent, newtype); }
int PMPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_resized_c
int MPI_Type_create_resized_c(MPI_Datatype oldtype, MPI_Count lb, MPI_Count extent, MPI_Datatype *newtype) { return PMPI_Type_create_resized_c(oldtype, lb, extent, newtype); }
int PMPI_Type_create_resized_c(MPI_Datatype oldtype, MPI_Count lb, MPI_Count extent, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_struct
int MPI_Type_create_struct(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], const MPI_Datatype array_of_types[], MPI_Datatype *newtype) { return PMPI_Type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype); }
int PMPI_Type_create_struct(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], const MPI_Datatype array_of_types[], MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_struct_c
int MPI_Type_create_struct_c(MPI_Count count, const MPI_Count array_of_blocklengths[], const MPI_Count array_of_displacements[], const MPI_Datatype array_of_types[], MPI_Datatype *newtype) { return PMPI_Type_create_struct_c(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype); }
int PMPI_Type_create_struct_c(MPI_Count count, const MPI_Count array_of_blocklengths[], const MPI_Count array_of_displacements[], const MPI_Datatype array_of_types[], MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_subarray
int MPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype); }
int PMPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_create_subarray_c
int MPI_Type_create_subarray_c(int ndims, const MPI_Count array_of_sizes[], const MPI_Count array_of_subsizes[], const MPI_Count array_of_starts[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_create_subarray_c(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype); }
int PMPI_Type_create_subarray_c(int ndims, const MPI_Count array_of_sizes[], const MPI_Count array_of_subsizes[], const MPI_Count array_of_starts[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_delete_attr
int MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval) { return PMPI_Type_delete_attr(datatype, type_keyval); }
int PMPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval) { abort(); return 0; }

#pragma weak MPI_Type_dup
int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_dup(oldtype, newtype); }
int PMPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_free
int MPI_Type_free(MPI_Datatype *datatype) { return PMPI_Type_free(datatype); }
int PMPI_Type_free(MPI_Datatype *datatype) { abort(); return 0; }

#pragma weak MPI_Type_free_keyval
int MPI_Type_free_keyval(int *type_keyval) { return PMPI_Type_free_keyval(type_keyval); }
int PMPI_Type_free_keyval(int *type_keyval) { abort(); return 0; }

#pragma weak MPI_Type_get_attr
int MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag) { return PMPI_Type_get_attr(datatype, type_keyval, attribute_val, flag); }
int PMPI_Type_get_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag) { abort(); return 0; }

#pragma weak MPI_Type_get_contents
int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses, int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Datatype array_of_datatypes[]) { return PMPI_Type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes); }
int PMPI_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses, int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Datatype array_of_datatypes[]) { abort(); return 0; }

#pragma weak MPI_Type_get_contents_c
int MPI_Type_get_contents_c(MPI_Datatype datatype, MPI_Count max_integers, MPI_Count max_addresses, MPI_Count max_large_counts, MPI_Count max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Count array_of_large_counts[], MPI_Datatype array_of_datatypes[]) { return PMPI_Type_get_contents_c(datatype, max_integers, max_addresses, max_large_counts, max_datatypes, array_of_integers, array_of_addresses, array_of_large_counts, array_of_datatypes); }
int PMPI_Type_get_contents_c(MPI_Datatype datatype, MPI_Count max_integers, MPI_Count max_addresses, MPI_Count max_large_counts, MPI_Count max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Count array_of_large_counts[], MPI_Datatype array_of_datatypes[]) { abort(); return 0; }

#pragma weak MPI_Type_get_envelope
int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner) { return PMPI_Type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner); }
int PMPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner) { abort(); return 0; }

#pragma weak MPI_Type_get_envelope_c
int MPI_Type_get_envelope_c(MPI_Datatype datatype, MPI_Count *num_integers, MPI_Count *num_addresses, MPI_Count *num_large_counts, MPI_Count *num_datatypes, int *combiner) { return PMPI_Type_get_envelope_c(datatype, num_integers, num_addresses, num_large_counts, num_datatypes, combiner); }
int PMPI_Type_get_envelope_c(MPI_Datatype datatype, MPI_Count *num_integers, MPI_Count *num_addresses, MPI_Count *num_large_counts, MPI_Count *num_datatypes, int *combiner) { abort(); return 0; }

#pragma weak MPI_Type_get_extent
int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent) { return PMPI_Type_get_extent(datatype, lb, extent); }
int PMPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent) { abort(); return 0; }

#pragma weak MPI_Type_get_extent_c
int MPI_Type_get_extent_c(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent) { return PMPI_Type_get_extent_c(datatype, lb, extent); }
int PMPI_Type_get_extent_c(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent) { abort(); return 0; }

#pragma weak MPI_Type_get_extent_x
int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent) { return PMPI_Type_get_extent_x(datatype, lb, extent); }
int PMPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent) { abort(); return 0; }

#pragma weak MPI_Type_get_name
int MPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen) { return PMPI_Type_get_name(datatype, type_name, resultlen); }
int PMPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen) { abort(); return 0; }

#pragma weak MPI_Type_get_true_extent
int MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent) { return PMPI_Type_get_true_extent(datatype, true_lb, true_extent); }
int PMPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent) { abort(); return 0; }

#pragma weak MPI_Type_get_true_extent_c
int MPI_Type_get_true_extent_c(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent) { return PMPI_Type_get_true_extent_c(datatype, true_lb, true_extent); }
int PMPI_Type_get_true_extent_c(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent) { abort(); return 0; }

#pragma weak MPI_Type_get_true_extent_x
int MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent) { return PMPI_Type_get_true_extent_x(datatype, true_lb, true_extent); }
int PMPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent) { abort(); return 0; }

#pragma weak MPI_Type_get_value_index
int MPI_Type_get_value_index(MPI_Datatype value_type, MPI_Datatype index_type, MPI_Datatype *pair_type) { return PMPI_Type_get_value_index(value_type, index_type, pair_type); }
int PMPI_Type_get_value_index(MPI_Datatype value_type, MPI_Datatype index_type, MPI_Datatype *pair_type) { abort(); return 0; }

#pragma weak MPI_Type_indexed
int MPI_Type_indexed(int count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype); }
int PMPI_Type_indexed(int count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_indexed_c
int MPI_Type_indexed_c(MPI_Count count, const MPI_Count array_of_blocklengths[], const MPI_Count array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_indexed_c(count, array_of_blocklengths, array_of_displacements, oldtype, newtype); }
int PMPI_Type_indexed_c(MPI_Count count, const MPI_Count array_of_blocklengths[], const MPI_Count array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_match_size
int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype) { return PMPI_Type_match_size(typeclass, size, datatype); }
int PMPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype) { abort(); return 0; }

#pragma weak MPI_Type_set_attr
int MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val) { return PMPI_Type_set_attr(datatype, type_keyval, attribute_val); }
int PMPI_Type_set_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val) { abort(); return 0; }

#pragma weak MPI_Type_set_name
int MPI_Type_set_name(MPI_Datatype datatype, const char *type_name) { return PMPI_Type_set_name(datatype, type_name); }
int PMPI_Type_set_name(MPI_Datatype datatype, const char *type_name) { abort(); return 0; }

#pragma weak MPI_Type_size
int MPI_Type_size(MPI_Datatype datatype, int *size) { return PMPI_Type_size(datatype, size); }
int PMPI_Type_size(MPI_Datatype datatype, int *size) { abort(); return 0; }

#pragma weak MPI_Type_size_c
int MPI_Type_size_c(MPI_Datatype datatype, MPI_Count *size) { return PMPI_Type_size_c(datatype, size); }
int PMPI_Type_size_c(MPI_Datatype datatype, MPI_Count *size) { abort(); return 0; }

#pragma weak MPI_Type_size_x
int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size) { return PMPI_Type_size_x(datatype, size); }
int PMPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size) { abort(); return 0; }

#pragma weak MPI_Type_vector
int MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_vector(count, blocklength, stride, oldtype, newtype); }
int PMPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Type_vector_c
int MPI_Type_vector_c(MPI_Count count, MPI_Count blocklength, MPI_Count stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { return PMPI_Type_vector_c(count, blocklength, stride, oldtype, newtype); }
int PMPI_Type_vector_c(MPI_Count count, MPI_Count blocklength, MPI_Count stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { abort(); return 0; }

#pragma weak MPI_Unpack
int MPI_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm) { return PMPI_Unpack(inbuf, insize, position, outbuf, outcount, datatype, comm); }
int PMPI_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Unpack_c
int MPI_Unpack_c(const void *inbuf, MPI_Count insize, MPI_Count *position, void *outbuf, MPI_Count outcount, MPI_Datatype datatype, MPI_Comm comm) { return PMPI_Unpack_c(inbuf, insize, position, outbuf, outcount, datatype, comm); }
int PMPI_Unpack_c(const void *inbuf, MPI_Count insize, MPI_Count *position, void *outbuf, MPI_Count outcount, MPI_Datatype datatype, MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Unpack_external
int MPI_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize, MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype) { return PMPI_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype); }
int PMPI_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize, MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_Unpack_external_c
int MPI_Unpack_external_c(const char datarep[], const void *inbuf, MPI_Count insize, MPI_Count *position, void *outbuf, MPI_Count outcount, MPI_Datatype datatype) { return PMPI_Unpack_external_c(datarep, inbuf, insize, position, outbuf, outcount, datatype); }
int PMPI_Unpack_external_c(const char datarep[], const void *inbuf, MPI_Count insize, MPI_Count *position, void *outbuf, MPI_Count outcount, MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_Unpublish_name
int MPI_Unpublish_name(const char *service_name, MPI_Info info, const char *port_name) { return PMPI_Unpublish_name(service_name, info, port_name); }
int PMPI_Unpublish_name(const char *service_name, MPI_Info info, const char *port_name) { abort(); return 0; }

#pragma weak MPI_Wait
int MPI_Wait(MPI_Request *request, MPI_Status *status) { return PMPI_Wait(request, status); }
int PMPI_Wait(MPI_Request *request, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Waitall
int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status *array_of_statuses) { return PMPI_Waitall(count, array_of_requests, array_of_statuses); }
int PMPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status *array_of_statuses) { abort(); return 0; }

#pragma weak MPI_Waitany
int MPI_Waitany(int count, MPI_Request array_of_requests[], int *indx, MPI_Status *status) { return PMPI_Waitany(count, array_of_requests, indx, status); }
int PMPI_Waitany(int count, MPI_Request array_of_requests[], int *indx, MPI_Status *status) { abort(); return 0; }

#pragma weak MPI_Waitsome
int MPI_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status *array_of_statuses) { return PMPI_Waitsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses); }
int PMPI_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status *array_of_statuses) { abort(); return 0; }

#pragma weak MPI_Win_allocate
int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { return PMPI_Win_allocate(size, disp_unit, info, comm, baseptr, win); }
int PMPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { abort(); return 0; }

#pragma weak MPI_Win_allocate_c
int MPI_Win_allocate_c(MPI_Aint size, MPI_Aint disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { return PMPI_Win_allocate_c(size, disp_unit, info, comm, baseptr, win); }
int PMPI_Win_allocate_c(MPI_Aint size, MPI_Aint disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { abort(); return 0; }

#pragma weak MPI_Win_allocate_shared
int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { return PMPI_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win); }
int PMPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { abort(); return 0; }

#pragma weak MPI_Win_allocate_shared_c
int MPI_Win_allocate_shared_c(MPI_Aint size, MPI_Aint disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { return PMPI_Win_allocate_shared_c(size, disp_unit, info, comm, baseptr, win); }
int PMPI_Win_allocate_shared_c(MPI_Aint size, MPI_Aint disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) { abort(); return 0; }

#pragma weak MPI_Win_attach
int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size) { return PMPI_Win_attach(win, base, size); }
int PMPI_Win_attach(MPI_Win win, void *base, MPI_Aint size) { abort(); return 0; }

#pragma weak MPI_Win_call_errhandler
int MPI_Win_call_errhandler(MPI_Win win, int errorcode) { return PMPI_Win_call_errhandler(win, errorcode); }
int PMPI_Win_call_errhandler(MPI_Win win, int errorcode) { abort(); return 0; }

#pragma weak MPI_Win_complete
int MPI_Win_complete(MPI_Win win) { return PMPI_Win_complete(win); }
int PMPI_Win_complete(MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_create
int MPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win) { return PMPI_Win_create(base, size, disp_unit, info, comm, win); }
int PMPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win) { abort(); return 0; }

#pragma weak MPI_Win_create_c
int MPI_Win_create_c(void *base, MPI_Aint size, MPI_Aint disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win) { return PMPI_Win_create_c(base, size, disp_unit, info, comm, win); }
int PMPI_Win_create_c(void *base, MPI_Aint size, MPI_Aint disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win) { abort(); return 0; }

#pragma weak MPI_Win_create_dynamic
int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win) { return PMPI_Win_create_dynamic(info, comm, win); }
int PMPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win) { abort(); return 0; }

#pragma weak MPI_Win_create_errhandler
int MPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn, MPI_Errhandler *errhandler) { return PMPI_Win_create_errhandler(win_errhandler_fn, errhandler); }
int PMPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn, MPI_Errhandler *errhandler) { abort(); return 0; }

#pragma weak MPI_Win_create_keyval
int MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval, void *extra_state) { return PMPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state); }
int PMPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval, void *extra_state) { abort(); return 0; }

#pragma weak MPI_Win_delete_attr
int MPI_Win_delete_attr(MPI_Win win, int win_keyval) { return PMPI_Win_delete_attr(win, win_keyval); }
int PMPI_Win_delete_attr(MPI_Win win, int win_keyval) { abort(); return 0; }

#pragma weak MPI_Win_detach
int MPI_Win_detach(MPI_Win win, const void *base) { return PMPI_Win_detach(win, base); }
int PMPI_Win_detach(MPI_Win win, const void *base) { abort(); return 0; }

#pragma weak MPI_Win_fence
int MPI_Win_fence(int assert, MPI_Win win) { return PMPI_Win_fence(assert, win); }
int PMPI_Win_fence(int assert, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_flush
int MPI_Win_flush(int rank, MPI_Win win) { return PMPI_Win_flush(rank, win); }
int PMPI_Win_flush(int rank, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_flush_all
int MPI_Win_flush_all(MPI_Win win) { return PMPI_Win_flush_all(win); }
int PMPI_Win_flush_all(MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_flush_local
int MPI_Win_flush_local(int rank, MPI_Win win) { return PMPI_Win_flush_local(rank, win); }
int PMPI_Win_flush_local(int rank, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_flush_local_all
int MPI_Win_flush_local_all(MPI_Win win) { return PMPI_Win_flush_local_all(win); }
int PMPI_Win_flush_local_all(MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_free
int MPI_Win_free(MPI_Win *win) { return PMPI_Win_free(win); }
int PMPI_Win_free(MPI_Win *win) { abort(); return 0; }

#pragma weak MPI_Win_free_keyval
int MPI_Win_free_keyval(int *win_keyval) { return PMPI_Win_free_keyval(win_keyval); }
int PMPI_Win_free_keyval(int *win_keyval) { abort(); return 0; }

#pragma weak MPI_Win_get_attr
int MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val, int *flag) { return PMPI_Win_get_attr(win, win_keyval, attribute_val, flag); }
int PMPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val, int *flag) { abort(); return 0; }

#pragma weak MPI_Win_get_errhandler
int MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler) { return PMPI_Win_get_errhandler(win, errhandler); }
int PMPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler) { abort(); return 0; }

#pragma weak MPI_Win_get_group
int MPI_Win_get_group(MPI_Win win, MPI_Group *group) { return PMPI_Win_get_group(win, group); }
int PMPI_Win_get_group(MPI_Win win, MPI_Group *group) { abort(); return 0; }

#pragma weak MPI_Win_get_info
int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used) { return PMPI_Win_get_info(win, info_used); }
int PMPI_Win_get_info(MPI_Win win, MPI_Info *info_used) { abort(); return 0; }

#pragma weak MPI_Win_get_name
int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen) { return PMPI_Win_get_name(win, win_name, resultlen); }
int PMPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen) { abort(); return 0; }

#pragma weak MPI_Win_lock
int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win) { return PMPI_Win_lock(lock_type, rank, assert, win); }
int PMPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_lock_all
int MPI_Win_lock_all(int assert, MPI_Win win) { return PMPI_Win_lock_all(assert, win); }
int PMPI_Win_lock_all(int assert, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_post
int MPI_Win_post(MPI_Group group, int assert, MPI_Win win) { return PMPI_Win_post(group, assert, win); }
int PMPI_Win_post(MPI_Group group, int assert, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_set_attr
int MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val) { return PMPI_Win_set_attr(win, win_keyval, attribute_val); }
int PMPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val) { abort(); return 0; }

#pragma weak MPI_Win_set_errhandler
int MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler) { return PMPI_Win_set_errhandler(win, errhandler); }
int PMPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler) { abort(); return 0; }

#pragma weak MPI_Win_set_info
int MPI_Win_set_info(MPI_Win win, MPI_Info info) { return PMPI_Win_set_info(win, info); }
int PMPI_Win_set_info(MPI_Win win, MPI_Info info) { abort(); return 0; }

#pragma weak MPI_Win_set_name
int MPI_Win_set_name(MPI_Win win, const char *win_name) { return PMPI_Win_set_name(win, win_name); }
int PMPI_Win_set_name(MPI_Win win, const char *win_name) { abort(); return 0; }

#pragma weak MPI_Win_shared_query
int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr) { return PMPI_Win_shared_query(win, rank, size, disp_unit, baseptr); }
int PMPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr) { abort(); return 0; }

#pragma weak MPI_Win_shared_query_c
int MPI_Win_shared_query_c(MPI_Win win, int rank, MPI_Aint *size, MPI_Aint *disp_unit, void *baseptr) { return PMPI_Win_shared_query_c(win, rank, size, disp_unit, baseptr); }
int PMPI_Win_shared_query_c(MPI_Win win, int rank, MPI_Aint *size, MPI_Aint *disp_unit, void *baseptr) { abort(); return 0; }

#pragma weak MPI_Win_start
int MPI_Win_start(MPI_Group group, int assert, MPI_Win win) { return PMPI_Win_start(group, assert, win); }
int PMPI_Win_start(MPI_Group group, int assert, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_sync
int MPI_Win_sync(MPI_Win win) { return PMPI_Win_sync(win); }
int PMPI_Win_sync(MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_test
int MPI_Win_test(MPI_Win win, int *flag) { return PMPI_Win_test(win, flag); }
int PMPI_Win_test(MPI_Win win, int *flag) { abort(); return 0; }

#pragma weak MPI_Win_unlock
int MPI_Win_unlock(int rank, MPI_Win win) { return PMPI_Win_unlock(rank, win); }
int PMPI_Win_unlock(int rank, MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_unlock_all
int MPI_Win_unlock_all(MPI_Win win) { return PMPI_Win_unlock_all(win); }
int PMPI_Win_unlock_all(MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Win_wait
int MPI_Win_wait(MPI_Win win) { return PMPI_Win_wait(win); }
int PMPI_Win_wait(MPI_Win win) { abort(); return 0; }

#pragma weak MPI_Aint_add
MPI_Aint MPI_Aint_add(MPI_Aint base, MPI_Aint disp) { return PMPI_Aint_add(base, disp); }
MPI_Aint PMPI_Aint_add(MPI_Aint base, MPI_Aint disp) { abort(); return 0; }

#pragma weak MPI_Aint_diff
MPI_Aint MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2) { return PMPI_Aint_diff(addr1, addr2); }
MPI_Aint PMPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2) { abort(); return 0; }

#pragma weak MPI_Wtick
double MPI_Wtick(void) { return PMPI_Wtick(); }
double PMPI_Wtick(void) { abort(); return 0; }

#pragma weak MPI_Wtime
double MPI_Wtime(void) { return PMPI_Wtime(); }
double PMPI_Wtime(void) { abort(); return 0; }

#pragma weak MPI_Comm_fromint
MPI_Comm MPI_Comm_fromint(int comm) { return PMPI_Comm_fromint(comm); }
MPI_Comm PMPI_Comm_fromint(int comm) { abort(); return (MPI_Comm)NULL; }

#pragma weak MPI_Comm_toint
int MPI_Comm_toint(MPI_Comm comm) { return PMPI_Comm_toint(comm); }
int PMPI_Comm_toint(MPI_Comm comm) { abort(); return 0; }

#pragma weak MPI_Errhandler_fromint
MPI_Errhandler MPI_Errhandler_fromint(int errhandler) { return PMPI_Errhandler_fromint(errhandler); }
MPI_Errhandler PMPI_Errhandler_fromint(int errhandler) { abort(); return (MPI_Errhandler)NULL; }

#pragma weak MPI_Errhandler_toint
int MPI_Errhandler_toint(MPI_Errhandler errhandler) { return PMPI_Errhandler_toint(errhandler); }
int PMPI_Errhandler_toint(MPI_Errhandler errhandler) { abort(); return 0; }

#pragma weak MPI_File_fromint
MPI_File MPI_File_fromint(int file) { return PMPI_File_fromint(file); }
MPI_File PMPI_File_fromint(int file) { abort(); return (MPI_File)NULL; }

#pragma weak MPI_File_toint
int MPI_File_toint(MPI_File file) { return PMPI_File_toint(file); }
int PMPI_File_toint(MPI_File file) { abort(); return 0; }

#pragma weak MPI_Group_fromint
MPI_Group MPI_Group_fromint(int group) { return PMPI_Group_fromint(group); }
MPI_Group PMPI_Group_fromint(int group) { abort(); return (MPI_Group)NULL; }

#pragma weak MPI_Group_toint
int MPI_Group_toint(MPI_Group group) { return PMPI_Group_toint(group); }
int PMPI_Group_toint(MPI_Group group) { abort(); return 0; }

#pragma weak MPI_Info_fromint
MPI_Info MPI_Info_fromint(int info) { return PMPI_Info_fromint(info); }
MPI_Info PMPI_Info_fromint(int info) { abort(); return (MPI_Info)NULL; }

#pragma weak MPI_Info_toint
int MPI_Info_toint(MPI_Info info) { return PMPI_Info_toint(info); }
int PMPI_Info_toint(MPI_Info info) { abort(); return 0; }

#pragma weak MPI_Message_fromint
MPI_Message MPI_Message_fromint(int message) { return PMPI_Message_fromint(message); }
MPI_Message PMPI_Message_fromint(int message) { abort(); return (MPI_Message)NULL; }

#pragma weak MPI_Message_toint
int MPI_Message_toint(MPI_Message message) { return PMPI_Message_toint(message); }
int PMPI_Message_toint(MPI_Message message) { abort(); return 0; }

#pragma weak MPI_Op_fromint
MPI_Op MPI_Op_fromint(int op) { return PMPI_Op_fromint(op); }
MPI_Op PMPI_Op_fromint(int op) { abort(); return (MPI_Op)NULL; }

#pragma weak MPI_Op_toint
int MPI_Op_toint(MPI_Op op) { return PMPI_Op_toint(op); }
int PMPI_Op_toint(MPI_Op op) { abort(); return 0; }

#pragma weak MPI_Request_fromint
MPI_Request MPI_Request_fromint(int request) { return PMPI_Request_fromint(request); }
MPI_Request PMPI_Request_fromint(int request) { abort(); return (MPI_Request)NULL; }

#pragma weak MPI_Request_toint
int MPI_Request_toint(MPI_Request request) { return PMPI_Request_toint(request); }
int PMPI_Request_toint(MPI_Request request) { abort(); return 0; }

#pragma weak MPI_Session_fromint
MPI_Session MPI_Session_fromint(int session) { return PMPI_Session_fromint(session); }
MPI_Session PMPI_Session_fromint(int session) { abort(); return (MPI_Session)NULL; }

#pragma weak MPI_Session_toint
int MPI_Session_toint(MPI_Session session) { return PMPI_Session_toint(session); }
int PMPI_Session_toint(MPI_Session session) { abort(); return 0; }

#pragma weak MPI_Type_fromint
MPI_Datatype MPI_Type_fromint(int datatype) { return PMPI_Type_fromint(datatype); }
MPI_Datatype PMPI_Type_fromint(int datatype) { abort(); return (MPI_Datatype)NULL; }

#pragma weak MPI_Type_toint
int MPI_Type_toint(MPI_Datatype datatype) { return PMPI_Type_toint(datatype); }
int PMPI_Type_toint(MPI_Datatype datatype) { abort(); return 0; }

#pragma weak MPI_Win_fromint
MPI_Win MPI_Win_fromint(int win) { return PMPI_Win_fromint(win); }
MPI_Win PMPI_Win_fromint(int win) { abort(); return (MPI_Win)NULL; }

#pragma weak MPI_Win_toint
int MPI_Win_toint(MPI_Win win) { return PMPI_Win_toint(win); }
int PMPI_Win_toint(MPI_Win win) { abort(); return 0; }

#pragma weak MPI_T_category_changed
int MPI_T_category_changed(int *update_number) { return PMPI_T_category_changed(update_number); }
int PMPI_T_category_changed(int *update_number) { abort(); return 0; }

#pragma weak MPI_T_category_get_categories
int MPI_T_category_get_categories(int cat_index, int len, int indices[]) { return PMPI_T_category_get_categories(cat_index, len, indices); }
int PMPI_T_category_get_categories(int cat_index, int len, int indices[]) { abort(); return 0; }

#pragma weak MPI_T_category_get_cvars
int MPI_T_category_get_cvars(int cat_index, int len, int indices[]) { return PMPI_T_category_get_cvars(cat_index, len, indices); }
int PMPI_T_category_get_cvars(int cat_index, int len, int indices[]) { abort(); return 0; }

#pragma weak MPI_T_category_get_events
int MPI_T_category_get_events(int cat_index, int len, int indices[]) { return PMPI_T_category_get_events(cat_index, len, indices); }
int PMPI_T_category_get_events(int cat_index, int len, int indices[]) { abort(); return 0; }

#pragma weak MPI_T_category_get_index
int MPI_T_category_get_index(const char *name, int *cat_index) { return PMPI_T_category_get_index(name, cat_index); }
int PMPI_T_category_get_index(const char *name, int *cat_index) { abort(); return 0; }

#pragma weak MPI_T_category_get_info
int MPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len, int *num_cvars, int *num_pvars, int *num_categories) { return PMPI_T_category_get_info(cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories); }
int PMPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len, int *num_cvars, int *num_pvars, int *num_categories) { abort(); return 0; }

#pragma weak MPI_T_category_get_num
int MPI_T_category_get_num(int *num_cat) { return PMPI_T_category_get_num(num_cat); }
int PMPI_T_category_get_num(int *num_cat) { abort(); return 0; }

#pragma weak MPI_T_category_get_num_events
int MPI_T_category_get_num_events(int cat_index, int *num_events) { return PMPI_T_category_get_num_events(cat_index, num_events); }
int PMPI_T_category_get_num_events(int cat_index, int *num_events) { abort(); return 0; }

#pragma weak MPI_T_category_get_pvars
int MPI_T_category_get_pvars(int cat_index, int len, int indices[]) { return PMPI_T_category_get_pvars(cat_index, len, indices); }
int PMPI_T_category_get_pvars(int cat_index, int len, int indices[]) { abort(); return 0; }

#pragma weak MPI_T_cvar_get_index
int MPI_T_cvar_get_index(const char *name, int *cvar_index) { return PMPI_T_cvar_get_index(name, cvar_index); }
int PMPI_T_cvar_get_index(const char *name, int *cvar_index) { abort(); return 0; }

#pragma weak MPI_T_cvar_get_info
int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *scope) { return PMPI_T_cvar_get_info(cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, bind, scope); }
int PMPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *scope) { abort(); return 0; }

#pragma weak MPI_T_cvar_get_num
int MPI_T_cvar_get_num(int *num_cvar) { return PMPI_T_cvar_get_num(num_cvar); }
int PMPI_T_cvar_get_num(int *num_cvar) { abort(); return 0; }

#pragma weak MPI_T_cvar_handle_alloc
int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle, MPI_T_cvar_handle *handle, int *count) { return PMPI_T_cvar_handle_alloc(cvar_index, obj_handle, handle, count); }
int PMPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle, MPI_T_cvar_handle *handle, int *count) { abort(); return 0; }

#pragma weak MPI_T_cvar_handle_free
int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle) { return PMPI_T_cvar_handle_free(handle); }
int PMPI_T_cvar_handle_free(MPI_T_cvar_handle *handle) { abort(); return 0; }

#pragma weak MPI_T_cvar_read
int MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf) { return PMPI_T_cvar_read(handle, buf); }
int PMPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf) { abort(); return 0; }

#pragma weak MPI_T_cvar_write
int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buf) { return PMPI_T_cvar_write(handle, buf); }
int PMPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buf) { abort(); return 0; }

#pragma weak MPI_T_enum_get_info
int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name, int *name_len) { return PMPI_T_enum_get_info(enumtype, num, name, name_len); }
int PMPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name, int *name_len) { abort(); return 0; }

#pragma weak MPI_T_enum_get_item
int MPI_T_enum_get_item(MPI_T_enum enumtype, int indx, int *value, char *name, int *name_len) { return PMPI_T_enum_get_item(enumtype, indx, value, name, name_len); }
int PMPI_T_enum_get_item(MPI_T_enum enumtype, int indx, int *value, char *name, int *name_len) { abort(); return 0; }

#pragma weak MPI_T_event_callback_get_info
int MPI_T_event_callback_get_info(MPI_T_event_registration event_registration, MPI_T_cb_safety cb_safety, MPI_Info *info_used) { return PMPI_T_event_callback_get_info(event_registration, cb_safety, info_used); }
int PMPI_T_event_callback_get_info(MPI_T_event_registration event_registration, MPI_T_cb_safety cb_safety, MPI_Info *info_used) { abort(); return 0; }

#pragma weak MPI_T_event_callback_set_info
int MPI_T_event_callback_set_info(MPI_T_event_registration event_registration, MPI_T_cb_safety cb_safety, MPI_Info info) { return PMPI_T_event_callback_set_info(event_registration, cb_safety, info); }
int PMPI_T_event_callback_set_info(MPI_T_event_registration event_registration, MPI_T_cb_safety cb_safety, MPI_Info info) { abort(); return 0; }

#pragma weak MPI_T_event_copy
int MPI_T_event_copy(MPI_T_event_instance event_instance, void *buffer) { return PMPI_T_event_copy(event_instance, buffer); }
int PMPI_T_event_copy(MPI_T_event_instance event_instance, void *buffer) { abort(); return 0; }

#pragma weak MPI_T_event_get_index
int MPI_T_event_get_index(const char *name, int *event_index) { return PMPI_T_event_get_index(name, event_index); }
int PMPI_T_event_get_index(const char *name, int *event_index) { abort(); return 0; }

#pragma weak MPI_T_event_get_info
int MPI_T_event_get_info(int event_index, char *name, int *name_len, int *verbosity, MPI_Datatype array_of_datatypes[], MPI_Aint array_of_displacements[], int *num_elements, MPI_T_enum *enumtype, MPI_Info *info, char *desc, int *desc_len, int *bind) { return PMPI_T_event_get_info(event_index, name, name_len, verbosity, array_of_datatypes, array_of_displacements, num_elements, enumtype, info, desc, desc_len, bind); }
int PMPI_T_event_get_info(int event_index, char *name, int *name_len, int *verbosity, MPI_Datatype array_of_datatypes[], MPI_Aint array_of_displacements[], int *num_elements, MPI_T_enum *enumtype, MPI_Info *info, char *desc, int *desc_len, int *bind) { abort(); return 0; }

#pragma weak MPI_T_event_get_num
int MPI_T_event_get_num(int *num_events) { return PMPI_T_event_get_num(num_events); }
int PMPI_T_event_get_num(int *num_events) { abort(); return 0; }

#pragma weak MPI_T_event_get_source
int MPI_T_event_get_source(MPI_T_event_instance event_instance, int *source_index) { return PMPI_T_event_get_source(event_instance, source_index); }
int PMPI_T_event_get_source(MPI_T_event_instance event_instance, int *source_index) { abort(); return 0; }

#pragma weak MPI_T_event_get_timestamp
int MPI_T_event_get_timestamp(MPI_T_event_instance event_instance, MPI_Count *event_timestamp) { return PMPI_T_event_get_timestamp(event_instance, event_timestamp); }
int PMPI_T_event_get_timestamp(MPI_T_event_instance event_instance, MPI_Count *event_timestamp) { abort(); return 0; }

#pragma weak MPI_T_event_handle_alloc
int MPI_T_event_handle_alloc(int event_index, void *obj_handle, MPI_Info info, MPI_T_event_registration *event_registration) { return PMPI_T_event_handle_alloc(event_index, obj_handle, info, event_registration); }
int PMPI_T_event_handle_alloc(int event_index, void *obj_handle, MPI_Info info, MPI_T_event_registration *event_registration) { abort(); return 0; }

#pragma weak MPI_T_event_handle_free
int MPI_T_event_handle_free(MPI_T_event_registration event_registration, void *user_data, MPI_T_event_free_cb_function free_cb_function) { return PMPI_T_event_handle_free(event_registration, user_data, free_cb_function); }
int PMPI_T_event_handle_free(MPI_T_event_registration event_registration, void *user_data, MPI_T_event_free_cb_function free_cb_function) { abort(); return 0; }

#pragma weak MPI_T_event_handle_get_info
int MPI_T_event_handle_get_info(MPI_T_event_registration event_registration, MPI_Info *info_used) { return PMPI_T_event_handle_get_info(event_registration, info_used); }
int PMPI_T_event_handle_get_info(MPI_T_event_registration event_registration, MPI_Info *info_used) { abort(); return 0; }

#pragma weak MPI_T_event_handle_set_info
int MPI_T_event_handle_set_info(MPI_T_event_registration event_registration, MPI_Info info) { return PMPI_T_event_handle_set_info(event_registration, info); }
int PMPI_T_event_handle_set_info(MPI_T_event_registration event_registration, MPI_Info info) { abort(); return 0; }

#pragma weak MPI_T_event_read
int MPI_T_event_read(MPI_T_event_instance event_instance, int element_index, void *buffer) { return PMPI_T_event_read(event_instance, element_index, buffer); }
int PMPI_T_event_read(MPI_T_event_instance event_instance, int element_index, void *buffer) { abort(); return 0; }

#pragma weak MPI_T_event_register_callback
int MPI_T_event_register_callback(MPI_T_event_registration event_registration, MPI_T_cb_safety cb_safety, MPI_Info info, void *user_data, MPI_T_event_cb_function event_cb_function) { return PMPI_T_event_register_callback(event_registration, cb_safety, info, user_data, event_cb_function); }
int PMPI_T_event_register_callback(MPI_T_event_registration event_registration, MPI_T_cb_safety cb_safety, MPI_Info info, void *user_data, MPI_T_event_cb_function event_cb_function) { abort(); return 0; }

#pragma weak MPI_T_event_set_dropped_handler
int MPI_T_event_set_dropped_handler(MPI_T_event_registration event_registration, MPI_T_event_dropped_cb_function dropped_cb_function) { return PMPI_T_event_set_dropped_handler(event_registration, dropped_cb_function); }
int PMPI_T_event_set_dropped_handler(MPI_T_event_registration event_registration, MPI_T_event_dropped_cb_function dropped_cb_function) { abort(); return 0; }

#pragma weak MPI_T_finalize
int MPI_T_finalize(void) { return PMPI_T_finalize(); }
int PMPI_T_finalize(void) { abort(); return 0; }

#pragma weak MPI_T_init_thread
int MPI_T_init_thread(int required, int *provided) { return PMPI_T_init_thread(required, provided); }
int PMPI_T_init_thread(int required, int *provided) { abort(); return 0; }

#pragma weak MPI_T_pvar_get_index
int MPI_T_pvar_get_index(const char *name, int var_class, int *pvar_index) { return PMPI_T_pvar_get_index(name, var_class, pvar_index); }
int PMPI_T_pvar_get_index(const char *name, int var_class, int *pvar_index) { abort(); return 0; }

#pragma weak MPI_T_pvar_get_info
int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *readonly, int *continuous, int *atomic) { return PMPI_T_pvar_get_info(pvar_index, name, name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, bind, readonly, continuous, atomic); }
int PMPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *readonly, int *continuous, int *atomic) { abort(); return 0; }

#pragma weak MPI_T_pvar_get_num
int MPI_T_pvar_get_num(int *num_pvar) { return PMPI_T_pvar_get_num(num_pvar); }
int PMPI_T_pvar_get_num(int *num_pvar) { abort(); return 0; }

#pragma weak MPI_T_pvar_handle_alloc
int MPI_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index, void *obj_handle, MPI_T_pvar_handle *handle, int *count) { return PMPI_T_pvar_handle_alloc(session, pvar_index, obj_handle, handle, count); }
int PMPI_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index, void *obj_handle, MPI_T_pvar_handle *handle, int *count) { abort(); return 0; }

#pragma weak MPI_T_pvar_handle_free
int MPI_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle) { return PMPI_T_pvar_handle_free(session, handle); }
int PMPI_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle) { abort(); return 0; }

#pragma weak MPI_T_pvar_read
int MPI_T_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf) { return PMPI_T_pvar_read(session, handle, buf); }
int PMPI_T_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf) { abort(); return 0; }

#pragma weak MPI_T_pvar_readreset
int MPI_T_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf) { return PMPI_T_pvar_readreset(session, handle, buf); }
int PMPI_T_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf) { abort(); return 0; }

#pragma weak MPI_T_pvar_reset
int MPI_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { return PMPI_T_pvar_reset(session, handle); }
int PMPI_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { abort(); return 0; }

#pragma weak MPI_T_pvar_session_create
int MPI_T_pvar_session_create(MPI_T_pvar_session *session) { return PMPI_T_pvar_session_create(session); }
int PMPI_T_pvar_session_create(MPI_T_pvar_session *session) { abort(); return 0; }

#pragma weak MPI_T_pvar_session_free
int MPI_T_pvar_session_free(MPI_T_pvar_session *session) { return PMPI_T_pvar_session_free(session); }
int PMPI_T_pvar_session_free(MPI_T_pvar_session *session) { abort(); return 0; }

#pragma weak MPI_T_pvar_start
int MPI_T_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { return PMPI_T_pvar_start(session, handle); }
int PMPI_T_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { abort(); return 0; }

#pragma weak MPI_T_pvar_stop
int MPI_T_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { return PMPI_T_pvar_stop(session, handle); }
int PMPI_T_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { abort(); return 0; }

#pragma weak MPI_T_pvar_write
int MPI_T_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle, const void *buf) { return PMPI_T_pvar_write(session, handle, buf); }
int PMPI_T_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle, const void *buf) { abort(); return 0; }

#pragma weak MPI_T_source_get_info
int MPI_T_source_get_info(int source_index, char *name, int *name_len, char *desc, int *desc_len, MPI_T_source_order *ordering, MPI_Count *ticks_per_second, MPI_Count *max_ticks, MPI_Info *info) { return PMPI_T_source_get_info(source_index, name, name_len, desc, desc_len, ordering, ticks_per_second, max_ticks, info); }
int PMPI_T_source_get_info(int source_index, char *name, int *name_len, char *desc, int *desc_len, MPI_T_source_order *ordering, MPI_Count *ticks_per_second, MPI_Count *max_ticks, MPI_Info *info) { abort(); return 0; }

#pragma weak MPI_T_source_get_num
int MPI_T_source_get_num(int *num_sources) { return PMPI_T_source_get_num(num_sources); }
int PMPI_T_source_get_num(int *num_sources) { abort(); return 0; }

#pragma weak MPI_T_source_get_timestamp
int MPI_T_source_get_timestamp(int source_index, MPI_Count *timestamp) { return PMPI_T_source_get_timestamp(source_index, timestamp); }
int PMPI_T_source_get_timestamp(int source_index, MPI_Count *timestamp) { abort(); return 0; }
