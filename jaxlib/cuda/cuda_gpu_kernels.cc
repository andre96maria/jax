/* Copyright 2021 Google LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

// This file is not used by JAX itself, but exists to assist with running
// JAX-generated HLO code from outside of JAX.

#include "jaxlib/cuda/cublas_kernels.h"
#include "jaxlib/cuda/cuda_lu_pivot_kernels.h"
#include "jaxlib/cuda/cuda_prng_kernels.h"
#include "jaxlib/cuda/cusolver_kernels.h"
#include "jaxlib/cuda/cusparse_kernels.h"
#include "tensorflow/compiler/xla/service/custom_call_target_registry.h"

namespace jax {
namespace {

XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cublas_trsm_batched", TrsmBatched,
                                         "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cublas_getrf_batched", GetrfBatched,
                                         "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cuda_lu_pivots_to_permutation",
                                         CudaLuPivotsToPermutation, "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cuda_threefry2x32", CudaThreeFry2x32,
                                         "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusolver_potrf", Potrf, "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusolver_getrf", Getrf, "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusolver_geqrf", Geqrf, "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusolver_csrlsvqr", Csrlsvqr, "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusolver_orgqr", Orgqr, "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusolver_syevd", Syevd, "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusolver_syevj", Syevj, "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusolver_gesvd", Gesvd, "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusolver_gesvdj", Gesvdj, "CUDA");

#if JAX_CUSPARSE_11300
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusparse_csr_todense", CsrToDense,
                                         "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusparse_csr_fromdense", CsrFromDense,
                                         "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusparse_csr_matvec", CsrMatvec,
                                         "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusparse_csr_matmat", CsrMatmat,
                                         "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusparse_coo_todense", CooToDense,
                                         "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusparse_coo_fromdense", CooFromDense,
                                         "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusparse_coo_matvec", CooMatvec,
                                         "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusparse_coo_matmat", CooMatmat,
                                         "CUDA");
#endif
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusparse_gtsv2_f32", gtsv2_f32,
                                         "CUDA");
XLA_REGISTER_CUSTOM_CALL_TARGET_WITH_SYM("cusparse_gtsv2_f64", gtsv2_f64,
                                         "CUDA");

}  // namespace
}  // namespace jax
