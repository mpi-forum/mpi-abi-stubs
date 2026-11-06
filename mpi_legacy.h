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

#if defined(MPI_ABI_OVERRIDE_DEPRECATED)

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

#endif /* MPI_ABI_OVERRIDE_DEPRECATED */

#if defined(__cplusplus)
} /* extern "C" */
#endif

#endif /* MPI_LEGACY_H_ABI */
