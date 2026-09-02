#ifndef MPI_LEGACY_H_ABI
#define MPI_LEGACY_H_ABI

#if !defined(MPI_ABI_static_inline)
#  if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__cplusplus)
#    define MPI_ABI_static_inline static inline
#  else
#    define MPI_ABI_static_inline static __inline
#  endif
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/* Removed MPI types and constants */

#define MPI_Copy_function              MPI_Comm_copy_attr_function
#define MPI_Delete_function            MPI_Comm_delete_attr_function
#define MPI_Handler_function           MPI_Comm_errhandler_function

#define MPI_DUP_FN                     MPI_COMM_DUP_FN
#define MPI_NULL_COPY_FN               MPI_COMM_NULL_COPY_FN
#define MPI_NULL_DELETE_FN             MPI_COMM_NULL_DELETE_FN

#define MPI_COMBINER_HVECTOR_INTEGER   MPI_COMBINER_HVECTOR
#define MPI_COMBINER_HINDEXED_INTEGER  MPI_COMBINER_HINDEXED
#define MPI_COMBINER_STRUCT_INTEGER    MPI_COMBINER_STRUCT

#define MPI_LB                         MPI_DATATYPE_NULL
#define MPI_UB                         MPI_DATATYPE_NULL

/* Removed MPI functions */

#define MPI_Address                    MPI_Get_address

#define MPI_Attr_delete                MPI_Comm_delete_attr
#define MPI_Attr_get                   MPI_Comm_get_attr
#define MPI_Attr_put                   MPI_Comm_set_attr

#define MPI_Errhandler_create          MPI_Comm_create_errhandler
#define MPI_Errhandler_get             MPI_Comm_get_errhandler
#define MPI_Errhandler_set             MPI_Comm_set_errhandler

#define MPI_Keyval_create              MPI_Comm_create_keyval
#define MPI_Keyval_free                MPI_Comm_free_keyval

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

/* Removed PMPI functions */

#define PMPI_Address                   PMPI_Get_Address

#define PMPI_Attr_delete               PMPI_Comm_delete_attr
#define PMPI_Attr_get                  PMPI_Comm_get_attr
#define PMPI_Attr_put                  PMPI_Comm_set_attr

#define PMPI_Errhandler_create         PMPI_Comm_create_Errhandler
#define PMPI_Errhandler_get            PMPI_Comm_get_errhandler
#define PMPI_Errhandler_set            PMPI_Comm_set_errhandler

#define PMPI_Keyval_create             PMPI_Comm_create_keyval
#define PMPI_Keyval_free               PMPI_Comm_free_keyval

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

#if defined(MPI_FORTRAN)

/* C <-> Fortran Handle Conversion */

#if !defined(MPI_ABI_Fint)
#define MPI_ABI_Fint int
#endif
typedef MPI_ABI_Fint MPI_Fint;
#undef  MPI_ABI_Fint

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

#endif /* MPI_FORTRAN */

#if defined(MPI_OVERRIDE_DEPRECATED)

/* Deprecated MPI types and constants */

#define MPI_HOST                       MPI_KEYVAL_INVALID
#define MPI_T_ERR_INVALID_ITEM         MPI_T_ERR_INVALID_INDEX

/* Deprecated MPI functions */

#define MPI_Get_elements_x             MPI_Get_elements_c
#define MPI_Status_set_elements_x      MPI_Status_set_elements_c

#define MPI_Type_get_extent_x          MPI_Type_get_extent_c
#define MPI_Type_get_true_extent_x     MPI_Type_get_true_extent_c
#define MPI_Type_size_x                MPI_Type_size_c

#define MPI_Info_get                   MPI_ABI_Info_get
#define MPI_Info_get_valuelen          MPI_ABI_Info_get_valuelen

MPI_ABI_static_inline int MPI_Info_get(MPI_Info MPI_info, const char *MPI_key, int MPI_valuelen, char *MPI_value, int *MPI_flag) {
  int MPI_buflen = MPI_valuelen + 1;
  return MPI_Info_get_string(MPI_info, MPI_key, &MPI_buflen, MPI_value, MPI_flag);
}

MPI_ABI_static_inline int MPI_Info_get_valuelen(MPI_Info MPI_info, const char *MPI_key, int *MPI_valuelen, int *MPI_flag) {
  int MPI_ierr; int MPI_buflen = 0; char MPI_value[1] = {0};
  MPI_ierr = MPI_Info_get_string(MPI_info, MPI_key, MPI_valuelen ? &MPI_buflen : MPI_valuelen, MPI_value, MPI_flag);
  if (MPI_ierr == MPI_SUCCESS && MPI_valuelen) *MPI_valuelen = MPI_buflen - 1;
  return MPI_ierr;
}

/* Deprecated PMPI functions */

#define PMPI_Get_elements_x            PMPI_Get_elements_c
#define PMPI_Status_set_elements_x     PMPI_Status_set_elements_c

#define PMPI_Type_get_extent_x         PMPI_Type_get_extent_c
#define PMPI_Type_get_true_extent_x    PMPI_Type_get_true_extent_c
#define PMPI_Type_size_x               PMPI_Type_size_c

#define PMPI_Info_get                  PMPI_ABI_Info_get
#define PMPI_Info_get_valuelen         PMPI_ABI_Info_get_valuelen

MPI_ABI_static_inline int PMPI_Info_get(MPI_Info MPI_info, const char *MPI_key, int MPI_valuelen, char *MPI_value, int *MPI_flag) {
  int MPI_buflen = MPI_valuelen + 1;
  return PMPI_Info_get_string(MPI_info, MPI_key, &MPI_buflen, MPI_value, MPI_flag);
}

MPI_ABI_static_inline int PMPI_Info_get_valuelen(MPI_Info MPI_info, const char *MPI_key, int *MPI_valuelen, int *MPI_flag) {
  int MPI_ierr; int MPI_buflen = 0; char MPI_value[1] = {0};
  MPI_ierr = PMPI_Info_get_string(MPI_info, MPI_key, MPI_valuelen ? &MPI_buflen : MPI_valuelen, MPI_value, MPI_flag);
  if (MPI_ierr == MPI_SUCCESS && MPI_valuelen) *MPI_valuelen = MPI_buflen - 1;
  return MPI_ierr;
}

#endif /* MPI_OVERRIDE_DEPRECATED */

#if defined(__cplusplus)
} /* extern "C" */
#endif

#endif /* MPI_LEGACY_H_ABI */
