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
