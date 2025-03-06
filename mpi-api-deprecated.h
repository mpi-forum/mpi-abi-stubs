#pragma once

#if !defined(MPI_ABI_static_inline)
#  if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__cplusplus)
#    define MPI_ABI_static_inline static inline
#  else
#    define MPI_ABI_static_inline static __inline
#  endif
#endif

/* MPI deprecated types and constants */

#define MPI_Copy_function              MPI_Comm_copy_attr_function
#define MPI_Delete_function            MPI_Comm_delete_attr_function
#define MPI_DUP_FN                     MPI_COMM_DUP_FN
#define MPI_NULL_COPY_FN               MPI_COMM_NULL_COPY_FN
#define MPI_NULL_DELETE_FN             MPI_COMM_NULL_DELETE_FN

#define MPI_HOST                       MPI_KEYVAL_INVALID
#define MPI_T_ERR_INVALID_ITEM         MPI_T_ERR_INVALID_INDEX

/* MPI deprecated functions */

#define MPI_Attr_delete                MPI_Comm_delete_attr
#define MPI_Attr_get                   MPI_Comm_get_attr
#define MPI_Attr_put                   MPI_Comm_set_attr

#define MPI_Keyval_create              MPI_Comm_create_keyval
#define MPI_Keyval_free                MPI_Comm_free_keyval

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

/* PMPI deprecated functions */

#define PMPI_Attr_delete               PMPI_Comm_delete_attr
#define PMPI_Attr_get                  PMPI_Comm_get_attr
#define PMPI_Attr_put                  PMPI_Comm_set_attr

#define PMPI_Keyval_create             PMPI_Comm_create_keyval
#define PMPI_Keyval_free               PMPI_Comm_free_keyval

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
