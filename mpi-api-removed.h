#pragma once

#if !defined(MPI_ABI_static_inline)
#  if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__cplusplus)
#    define MPI_ABI_static_inline static inline
#  else
#    define MPI_ABI_static_inline static __inline
#  endif
#endif

/* MPI removed types and constants */

#define MPI_Handler_function           MPI_Comm_errhandler_function

#define MPI_LB                         MPI_DATATYPE_NULL
#define MPI_UB                         MPI_DATATYPE_NULL

#define MPI_COMBINER_HVECTOR_INTEGER   MPI_UNDEFINED
#define MPI_COMBINER_HINDEXED_INTEGER  MPI_UNDEFINED
#define MPI_COMBINER_STRUCT_INTEGER    MPI_UNDEFINED

/* MPI removed functions */

#define MPI_Address                    MPI_Get_address

#define MPI_Errhandler_create          MPI_Comm_create_errhandler
#define MPI_Errhandler_get             MPI_Comm_get_errhandler
#define MPI_Errhandler_set             MPI_Comm_set_errhandler

#define MPI_Type_hindexed              MPI_Type_create_hindexed
#define MPI_Type_hvector               MPI_Type_create_hvector
#define MPI_Type_struct                MPI_Type_create_struct

#define MPI_Type_extent                MPI_ABI_Type_extent
#define MPI_Type_lb                    MPI_ABI_Type_lb
#define MPI_Type_ub                    MPI_ABI_Type_ub

MPI_ABI_static_inline int MPI_Type_extent(MPI_Datatype MPI_datatype, MPI_Aint *MPI_extent)
{
  MPI_Aint MPI_lb;
  return MPI_Type_get_extent(MPI_datatype, &MPI_lb, MPI_extent);
}

MPI_ABI_static_inline int MPI_Type_lb(MPI_Datatype MPI_datatype, MPI_Aint *MPI_lb)
{
  MPI_Aint MPI_extent;
  return MPI_Type_get_extent(MPI_datatype, MPI_lb, &MPI_extent);
}

MPI_ABI_static_inline int MPI_Type_ub(MPI_Datatype MPI_datatype, MPI_Aint *MPI_ub)
{
  MPI_Aint MPI_lb; int MPI_ierr;
  MPI_ierr = MPI_Type_get_extent(MPI_datatype, &MPI_lb, MPI_ub);
  if (MPI_ierr == MPI_SUCCESS && MPI_ub) *MPI_ub += MPI_lb;
  return MPI_ierr;
}

/* PMPI removed functions */

#define PMPI_Address                   PMPI_Get_Address

#define PMPI_Errhandler_create         PMPI_Comm_create_Errhandler
#define PMPI_Errhandler_get            PMPI_Comm_get_errhandler
#define PMPI_Errhandler_set            PMPI_Comm_set_errhandler

#define PMPI_Type_hindexed             PMPI_Type_create_hindexed
#define PMPI_Type_hvector              PMPI_Type_create_hvector
#define PMPI_Type_struct               PMPI_Type_create_struct

#define PMPI_Type_extent               PMPI_ABI_Type_extent
#define PMPI_Type_lb                   PMPI_ABI_Type_lb
#define PMPI_Type_ub                   PMPI_ABI_Type_ub

MPI_ABI_static_inline int PMPI_Type_extent(MPI_Datatype MPI_datatype, MPI_Aint *MPI_extent)
{
  MPI_Aint MPI_lb;
  return PMPI_Type_get_extent(MPI_datatype, &MPI_lb, MPI_extent);
}

MPI_ABI_static_inline int PMPI_Type_lb(MPI_Datatype MPI_datatype, MPI_Aint *MPI_lb)
{
  MPI_Aint MPI_extent;
  return PMPI_Type_get_extent(MPI_datatype, MPI_lb, &MPI_extent);
}

MPI_ABI_static_inline int PMPI_Type_ub(MPI_Datatype MPI_datatype, MPI_Aint *MPI_ub)
{
  MPI_Aint MPI_lb; int MPI_ierr;
  MPI_ierr = PMPI_Type_get_extent(MPI_datatype, &MPI_lb, MPI_ub);
  if (MPI_ierr == MPI_SUCCESS && MPI_ub) *MPI_ub += MPI_lb;
  return MPI_ierr;
}

/* C <-> Fortran Handle Conversion */

#define MPI_Fint int

MPI_ABI_static_inline int MPIX_ABI_Status_c2f(const MPI_Status *c_status, MPI_Fint *f_status)
{
  int MPI_pos = 0;
  enum { MPI_off = 3, MPI_len = sizeof(c_status->MPI_internal)/sizeof(MPI_Fint) };
  f_status[MPI_pos++] = c_status->MPI_SOURCE;
  f_status[MPI_pos++] = c_status->MPI_TAG;
  f_status[MPI_pos++] = c_status->MPI_ERROR;
  for (MPI_pos = 0; MPI_pos < MPI_len; MPI_pos++)
    f_status[MPI_off + MPI_pos] = c_status->MPI_internal[MPI_pos];
  return MPI_SUCCESS;
}

MPI_ABI_static_inline int MPIX_ABI_Status_f2c(const MPI_Fint *f_status, MPI_Status *c_status)
{
  int MPI_pos = 0;
  enum { MPI_off = 3, MPI_len = sizeof(c_status->MPI_internal)/sizeof(MPI_Fint) };
  c_status->MPI_SOURCE = f_status[MPI_pos++];
  c_status->MPI_TAG    = f_status[MPI_pos++];
  c_status->MPI_ERROR  = f_status[MPI_pos++];
  for (MPI_pos = 0; MPI_pos < MPI_len; MPI_pos++)
    c_status->MPI_internal[MPI_pos] = f_status[MPI_off + MPI_pos];
  return MPI_SUCCESS;
}

#define MPI_Comm_c2f        MPI_Comm_toint
#define MPI_Errhandler_c2f  MPI_Errhandler_toint
#define MPI_File_c2f        MPI_File_toint
#define MPI_Group_c2f       MPI_Group_toint
#define MPI_Info_c2f        MPI_Info_toint
#define MPI_Message_c2f     MPI_Message_toint
#define MPI_Op_c2f          MPI_Op_toint
#define MPI_Request_c2f     MPI_Request_toint
#define MPI_Session_c2f     MPI_Session_toint
#define MPI_Status_c2f      MPIX_ABI_Status_c2f
#define MPI_Type_c2f        MPI_Type_toint
#define MPI_Win_c2f         MPI_Win_toint

#define MPI_Comm_f2c        MPI_Comm_fromint
#define MPI_Errhandler_f2c  MPI_Errhandler_fromint
#define MPI_File_f2c        MPI_File_fromint
#define MPI_Group_f2c       MPI_Group_fromint
#define MPI_Info_f2c        MPI_Info_fromint
#define MPI_Message_f2c     MPI_Message_fromint
#define MPI_Op_f2c          MPI_Op_fromint
#define MPI_Request_f2c     MPI_Request_fromint
#define MPI_Session_f2c     MPI_Session_fromint
#define MPI_Status_f2c      MPIX_ABI_Status_f2c
#define MPI_Type_f2c        MPI_Type_fromint
#define MPI_Win_f2c         MPI_Win_fromint

#define PMPI_Comm_c2f       PMPI_Comm_toint
#define PMPI_Errhandler_c2f PMPI_Errhandler_toint
#define PMPI_File_c2f       PMPI_File_toint
#define PMPI_Group_c2f      PMPI_Group_toint
#define PMPI_Info_c2f       PMPI_Info_toint
#define PMPI_Message_c2f    PMPI_Message_toint
#define PMPI_Op_c2f         PMPI_Op_toint
#define PMPI_Request_c2f    PMPI_Request_toint
#define PMPI_Session_c2f    PMPI_Session_toint
#define PMPI_Status_c2f     MPIX_ABI_Status_c2f
#define PMPI_Type_c2f       PMPI_Type_toint
#define PMPI_Win_c2f        PMPI_Win_toint

#define PMPI_Comm_f2c       PMPI_Comm_fromint
#define PMPI_Errhandler_f2c PMPI_Errhandler_fromint
#define PMPI_File_f2c       PMPI_File_fromint
#define PMPI_Group_f2c      PMPI_Group_fromint
#define PMPI_Info_f2c       PMPI_Info_fromint
#define PMPI_Message_f2c    PMPI_Message_fromint
#define PMPI_Op_f2c         PMPI_Op_fromint
#define PMPI_Request_f2c    PMPI_Request_fromint
#define PMPI_Session_f2c    PMPI_Session_fromint
#define PMPI_Status_f2c     MPIX_ABI_Status_f2c
#define PMPI_Type_f2c       PMPI_Type_fromint
#define PMPI_Win_f2c        PMPI_Win_fromint
