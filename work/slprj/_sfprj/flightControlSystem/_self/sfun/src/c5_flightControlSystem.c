/* Include files */

#include "flightControlSystem_sfun.h"
#include "c5_flightControlSystem.h"
#include <math.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c5_emlrtMCI = { 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c5_b_emlrtMCI = { 111,/* lineNo */
  5,                                   /* colNo */
  "svd",                               /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtMCInfo c5_c_emlrtMCI = { 45,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pName */
};

static emlrtMCInfo c5_d_emlrtMCI = { 48,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pName */
};

static emlrtMCInfo c5_e_emlrtMCI = { 269,/* lineNo */
  13,                                  /* colNo */
  "xzsvdc",                            /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pName */
};

static emlrtMCInfo c5_f_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtMCInfo c5_g_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c5_h_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c5_i_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtMCInfo c5_j_emlrtMCI = { 47,/* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pName */
};

static emlrtRSInfo c5_emlrtRSI = { 77, /* lineNo */
  "bwmorph",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/bwmorph.m"/* pathName */
};

static emlrtRSInfo c5_b_emlrtRSI = { 24,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c5_c_emlrtRSI = { 109,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c5_d_emlrtRSI = { 145,/* lineNo */
  "bwlookup",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/bwlookup.m"/* pathName */
};

static emlrtRSInfo c5_e_emlrtRSI = { 14,/* lineNo */
  "imgaussfilt",                       /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imgaussfilt.m"/* pathName */
};

static emlrtRSInfo c5_f_emlrtRSI = { 23,/* lineNo */
  "imgaussfilt",                       /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imgaussfilt.m"/* pathName */
};

static emlrtRSInfo c5_g_emlrtRSI = { 24,/* lineNo */
  "imgaussfilt",                       /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imgaussfilt.m"/* pathName */
};

static emlrtRSInfo c5_h_emlrtRSI = { 60,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_i_emlrtRSI = { 64,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_j_emlrtRSI = { 69,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_k_emlrtRSI = { 72,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_l_emlrtRSI = { 73,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_m_emlrtRSI = { 89,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_n_emlrtRSI = { 93,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_o_emlrtRSI = { 111,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_p_emlrtRSI = { 115,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_q_emlrtRSI = { 693,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_r_emlrtRSI = { 36,/* lineNo */
  "svd",                               /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/svd.m"/* pathName */
};

static emlrtRSInfo c5_s_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c5_t_emlrtRSI = { 52,/* lineNo */
  "svd",                               /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo c5_u_emlrtRSI = { 89,/* lineNo */
  "svd",                               /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo c5_v_emlrtRSI = { 81,/* lineNo */
  "svd",                               /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo c5_w_emlrtRSI = { 209,/* lineNo */
  "xgesdd",                            /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo c5_x_emlrtRSI = { 197,/* lineNo */
  "xgesvd",                            /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

static emlrtRSInfo c5_y_emlrtRSI = { 31,/* lineNo */
  "xgesvd",                            /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

static emlrtRSInfo c5_ab_emlrtRSI = { 282,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_bb_emlrtRSI = { 299,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_cb_emlrtRSI = { 428,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_db_emlrtRSI = { 23,/* lineNo */
  "xnrm2",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xnrm2.m"/* pathName */
};

static emlrtRSInfo c5_eb_emlrtRSI = { 38,/* lineNo */
  "xnrm2",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xnrm2.m"/* pathName */
};

static emlrtRSInfo c5_fb_emlrtRSI = { 21,/* lineNo */
  "scaleVectorByRecip",                /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/scaleVectorByRecip.m"/* pathName */
};

static emlrtRSInfo c5_gb_emlrtRSI = { 23,/* lineNo */
  "scaleVectorByRecip",                /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/scaleVectorByRecip.m"/* pathName */
};

static emlrtRSInfo c5_hb_emlrtRSI = { 31,/* lineNo */
  "xscal",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xscal.m"/* pathName */
};

static emlrtRSInfo c5_ib_emlrtRSI = { 18,/* lineNo */
  "xscal",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xscal.m"/* pathName */
};

static emlrtRSInfo c5_jb_emlrtRSI = { 32,/* lineNo */
  "xdotc",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xdotc.m"/* pathName */
};

static emlrtRSInfo c5_kb_emlrtRSI = { 35,/* lineNo */
  "xdot",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xdot.m"/* pathName */
};

static emlrtRSInfo c5_lb_emlrtRSI = { 15,/* lineNo */
  "xdot",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xdot.m"/* pathName */
};

static emlrtRSInfo c5_mb_emlrtRSI = { 42,/* lineNo */
  "xdotx",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xdotx.m"/* pathName */
};

static emlrtRSInfo c5_nb_emlrtRSI = { 47,/* lineNo */
  "xaxpy",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xaxpy.m"/* pathName */
};

static emlrtRSInfo c5_ob_emlrtRSI = { 32,/* lineNo */
  "xaxpy",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xaxpy.m"/* pathName */
};

static emlrtRSInfo c5_pb_emlrtRSI = { 21,/* lineNo */
  "xrotg",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xrotg.m"/* pathName */
};

static emlrtRSInfo c5_qb_emlrtRSI = { 23,/* lineNo */
  "xrotg",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xrotg.m"/* pathName */
};

static emlrtRSInfo c5_rb_emlrtRSI = { 32,/* lineNo */
  "xrotg",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xrotg.m"/* pathName */
};

static emlrtRSInfo c5_sb_emlrtRSI = { 32,/* lineNo */
  "xrotg",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xrotg.m"/* pathName */
};

static emlrtRSInfo c5_tb_emlrtRSI = { 859,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_ub_emlrtRSI = { 933,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_vb_emlrtRSI = { 1007,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_wb_emlrtRSI = { 1035,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_xb_emlrtRSI = { 1047,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c5_yb_emlrtRSI = { 33,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c5_ac_emlrtRSI = { 321,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c5_bc_emlrtRSI = { 322,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c5_cc_emlrtRSI = { 324,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c5_dc_emlrtRSI = { 325,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c5_ec_emlrtRSI = { 9,/* lineNo */
  "lutthin1",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/lutthin1.m"/* pathName */
};

static emlrtRSInfo c5_fc_emlrtRSI = { 9,/* lineNo */
  "lutthin2",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/lutthin2.m"/* pathName */
};

static emlrtRSInfo c5_gc_emlrtRSI = { 281,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c5_hc_emlrtRSI = { 289,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c5_ic_emlrtRSI = { 295,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c5_jc_emlrtRSI = { 301,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c5_kc_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c5_lc_emlrtRSI = { 138,/* lineNo */
  "find",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c5_mc_emlrtRSI = { 255,/* lineNo */
  "find",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c5_nc_emlrtRSI = { 254,/* lineNo */
  "find",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c5_oc_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c5_pc_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c5_qc_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo c5_rc_emlrtRSI = { 16,/* lineNo */
  "sqrt",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

static emlrtRSInfo c5_sc_emlrtRSI = { 33,/* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo c5_tc_emlrtRSI = { 13,/* lineNo */
  "all",                               /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/all.m"/* pathName */
};

static emlrtRSInfo c5_uc_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pathName */
};

static emlrtRSInfo c5_vc_emlrtRSI = { 37,/* lineNo */
  "sort",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/sort.m"/* pathName */
};

static emlrtRSInfo c5_wc_emlrtRSI = { 76,/* lineNo */
  "sort",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c5_xc_emlrtRSI = { 79,/* lineNo */
  "sort",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c5_yc_emlrtRSI = { 81,/* lineNo */
  "sort",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c5_ad_emlrtRSI = { 84,/* lineNo */
  "sort",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c5_bd_emlrtRSI = { 87,/* lineNo */
  "sort",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c5_cd_emlrtRSI = { 90,/* lineNo */
  "sort",                              /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c5_dd_emlrtRSI = { 55,/* lineNo */
  "prodsize",                          /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/shared/coder/coder/lib/+coder/+internal/prodsize.m"/* pathName */
};

static emlrtRSInfo c5_ed_emlrtRSI = { 105,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_fd_emlrtRSI = { 308,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_gd_emlrtRSI = { 316,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_hd_emlrtRSI = { 317,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_id_emlrtRSI = { 325,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_jd_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_kd_emlrtRSI = { 392,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ld_emlrtRSI = { 420,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_md_emlrtRSI = { 427,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_nd_emlrtRSI = { 587,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_od_emlrtRSI = { 589,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_pd_emlrtRSI = { 617,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_qd_emlrtRSI = { 499,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_rd_emlrtRSI = { 506,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_sd_emlrtRSI = { 507,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_td_emlrtRSI = { 514,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ud_emlrtRSI = { 561,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_vd_emlrtRSI = { 530,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_wd_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/mpower.m"/* pathName */
};

static emlrtRSInfo c5_xd_emlrtRSI = { 11,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_yd_emlrtRSI = { 21,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_ae_emlrtRSI = { 24,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_be_emlrtRSI = { 26,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_ce_emlrtRSI = { 35,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_de_emlrtRSI = { 48,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_ee_emlrtRSI = { 49,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_fe_emlrtRSI = { 58,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_ge_emlrtRSI = { 59,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_he_emlrtRSI = { 76,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_ie_emlrtRSI = { 81,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_je_emlrtRSI = { 82,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_ke_emlrtRSI = { 96,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_le_emlrtRSI = { 100,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_me_emlrtRSI = { 125,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRSInfo c5_ne_emlrtRSI = { 140,/* lineNo */
  "Image Processing System/send_only_points1",/* fcnName */
  "#flightControlSystem:2791"          /* pathName */
};

static emlrtRTEInfo c5_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c5_b_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c5_c_emlrtRTEI = { 38,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_d_emlrtRTEI = { 39,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_e_emlrtRTEI = { 58,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_f_emlrtRTEI = { 58,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_g_emlrtRTEI = { 48,/* lineNo */
  30,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_h_emlrtRTEI = { 59,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_i_emlrtRTEI = { 48,/* lineNo */
  66,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_j_emlrtRTEI = { 59,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_k_emlrtRTEI = { 49,/* lineNo */
  16,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_l_emlrtRTEI = { 76,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_m_emlrtRTEI = { 76,/* lineNo */
  54,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_n_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/sort.m"/* pName */
};

static emlrtRTEInfo c5_o_emlrtRTEI = { 82,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_p_emlrtRTEI = { 88,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_q_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_r_emlrtRTEI = { 89,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_s_emlrtRTEI = { 89,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_t_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "imgaussfilt",                       /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/imgaussfilt.m"/* pName */
};

static emlrtRTEInfo c5_u_emlrtRTEI = { 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c5_v_emlrtRTEI = { 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c5_w_emlrtRTEI = { 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c5_x_emlrtRTEI = { 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c5_y_emlrtRTEI = { 71,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo c5_ab_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "sqrt",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRTEInfo c5_bb_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c5_cb_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_db_emlrtRTEI = { 572,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_eb_emlrtRTEI = { 482,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_fb_emlrtRTEI = { 520,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_gb_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "isinf",                             /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/isinf.m"/* pName */
};

static emlrtRTEInfo c5_hb_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "isnan",                             /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/isnan.m"/* pName */
};

static emlrtRTEInfo c5_ib_emlrtRTEI = { 12,/* lineNo */
  37,                                  /* colNo */
  "sqrt",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRTEInfo c5_jb_emlrtRTEI = { 30,/* lineNo */
  42,                                  /* colNo */
  "sort",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c5_kb_emlrtRTEI = { 56,/* lineNo */
  24,                                  /* colNo */
  "sort",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c5_lb_emlrtRTEI = { 75,/* lineNo */
  26,                                  /* colNo */
  "sort",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c5_mb_emlrtRTEI = { 76,/* lineNo */
  39,                                  /* colNo */
  "sort",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c5_nb_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_ob_emlrtRTEI = { 267,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_pb_emlrtRTEI = { 385,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_qb_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_rb_emlrtRTEI = { 274,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_sb_emlrtRTEI = { 387,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_tb_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_ub_emlrtRTEI = { 87,/* lineNo */
  13,                                  /* colNo */
  "sort",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c5_vb_emlrtRTEI = { 87,/* lineNo */
  14,                                  /* colNo */
  "sort",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c5_wb_emlrtRTEI = { 87,/* lineNo */
  19,                                  /* colNo */
  "sort",                              /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c5_xb_emlrtRTEI = { 48,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_yb_emlrtRTEI = { 48,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_ac_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtBCInfo c5_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  40,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_emlrtDCI = { 48, /* lineNo */
  42,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  42,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  76,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_b_emlrtDCI = { 48,/* lineNo */
  78,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  78,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_emlrtECI = { 1,  /* nDims */
  48,                                  /* lineNo */
  29,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtBCInfo c5_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_c_emlrtDCI = { 58,/* lineNo */
  25,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  25,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_d_emlrtDCI = { 59,/* lineNo */
  25,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  25,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_b_emlrtECI = { 1,/* nDims */
  76,                                  /* lineNo */
  26,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtBCInfo c5_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  32,                                  /* colNo */
  "sortedIndices",                     /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_e_emlrtDCI = { 82,/* lineNo */
  34,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  34,                                  /* colNo */
  "sortedIndices",                     /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_f_emlrtDCI = { 88,/* lineNo */
  11,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_k_emlrtBCI = { 1,/* iFirst */
  40,                                  /* iLast */
  88,                                  /* lineNo */
  11,                                  /* colNo */
  "pointsx",                           /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_c_emlrtECI = { -1,/* nDims */
  88,                                  /* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtDCInfo c5_g_emlrtDCI = { 89,/* lineNo */
  11,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_l_emlrtBCI = { 1,/* iFirst */
  40,                                  /* iLast */
  89,                                  /* lineNo */
  11,                                  /* colNo */
  "pointsy",                           /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_d_emlrtECI = { -1,/* nDims */
  89,                                  /* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtRTEInfo c5_bc_emlrtRTEI = { 122,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791"          /* pName */
};

static emlrtDCInfo c5_h_emlrtDCI = { 129,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_m_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  129,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_i_emlrtDCI = { 129,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_n_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  129,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_j_emlrtDCI = { 130,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_o_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  130,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_k_emlrtDCI = { 130,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_p_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  130,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_l_emlrtDCI = { 131,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_q_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  131,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_m_emlrtDCI = { 131,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_r_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  131,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_n_emlrtDCI = { 38,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c5_o_emlrtDCI = { 38,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_p_emlrtDCI = { 39,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c5_q_emlrtDCI = { 39,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  33,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_r_emlrtDCI = { 45,/* lineNo */
  33,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  19,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_s_emlrtDCI = { 45,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  33,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_t_emlrtDCI = { 46,/* lineNo */
  33,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  19,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_u_emlrtDCI = { 46,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  56,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_v_emlrtDCI = { 48,/* lineNo */
  56,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  92,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_w_emlrtDCI = { 48,/* lineNo */
  92,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  37,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_x_emlrtDCI = { 51,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_y_emlrtDCI = { 51,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  37,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_ab_emlrtDCI = { 52,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_bb_emlrtDCI = { 52,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  47,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_cb_emlrtDCI = { 88,/* lineNo */
  47,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  47,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_db_emlrtDCI = { 89,/* lineNo */
  47,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_fb_emlrtBCI = { 0,/* iFirst */
  39,                                  /* iLast */
  93,                                  /* lineNo */
  27,                                  /* colNo */
  "pointsx",                           /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_eb_emlrtDCI = { 93,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_gb_emlrtBCI = { 0,/* iFirst */
  39,                                  /* iLast */
  94,                                  /* lineNo */
  27,                                  /* colNo */
  "pointsy",                           /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_fb_emlrtDCI = { 94,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_gb_emlrtDCI = { 101,/* lineNo */
  30,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  30,                                  /* colNo */
  "unsorted_validY",                   /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  126,                                 /* lineNo */
  31,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_hb_emlrtDCI = { 126,/* lineNo */
  31,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  127,                                 /* lineNo */
  31,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_ib_emlrtDCI = { 127,/* lineNo */
  31,                                  /* colNo */
  "Image Processing System/send_only_points1",/* fName */
  "#flightControlSystem:2791",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_kb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  156,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_lb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  156,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static char_T c5_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n', 'E',
  'r', 'r', 'o', 'r' };

static real_T c5_dv[289] = { 0.00019488687389578179, 0.00031142833774056212,
  0.00046750930690707231, 0.00065929379617042779, 0.00087342237269107809,
  0.0010869917053868189, 0.0012708220536009774, 0.0013957249774454289,
  0.0014400300441611551, 0.0013957249774454289, 0.0012708220536009774,
  0.0010869917053868189, 0.00087342237269107809, 0.00065929379617042779,
  0.00046750930690707231, 0.00031142833774056212, 0.00019488687389578179,
  0.00031142833774056212, 0.00049766106669510749, 0.0007470777452470756,
  0.0010535484864610237, 0.0013957249774454289, 0.0017370077993422159,
  0.0020307678593512817, 0.0022303621633402459, 0.0023011614583617352,
  0.0022303621633402459, 0.0020307678593512817, 0.0017370077993422159,
  0.0013957249774454289, 0.0010535484864610237, 0.0007470777452470756,
  0.00049766106669510749, 0.00031142833774056212, 0.00046750930690707231,
  0.0007470777452470756, 0.0011214965260390572, 0.0015815635990990187,
  0.00209523135104675, 0.0026075575467996021, 0.0030485436274119157,
  0.0033481701655666248, 0.0034544524955085437, 0.0033481701655666248,
  0.0030485436274119157, 0.0026075575467996021, 0.00209523135104675,
  0.0015815635990990187, 0.0011214965260390572, 0.0007470777452470756,
  0.00046750930690707231, 0.00065929379617042779, 0.0010535484864610237,
  0.0015815635990990187, 0.0022303621633402459, 0.0029547498004386975,
  0.0036772455400638166, 0.0042991355919831491, 0.0047216767368435811,
  0.00487155884558024, 0.0047216767368435811, 0.0042991355919831491,
  0.0036772455400638166, 0.0029547498004386975, 0.0022303621633402459,
  0.0015815635990990187, 0.0010535484864610237, 0.00065929379617042779,
  0.00087342237269107809, 0.0013957249774454289, 0.00209523135104675,
  0.0029547498004386975, 0.003914407501478344, 0.00487155884558024,
  0.0056954293079680756, 0.0062552053766150211, 0.0064537669098754889,
  0.0062552053766150211, 0.0056954293079680756, 0.00487155884558024,
  0.003914407501478344, 0.0029547498004386975, 0.00209523135104675,
  0.0013957249774454289, 0.00087342237269107809, 0.0010869917053868189,
  0.0017370077993422159, 0.0026075575467996021, 0.0036772455400638166,
  0.00487155884558024, 0.0060627529394903946, 0.0070880762961266046,
  0.0077847288694039831, 0.0080318426901755027, 0.0077847288694039831,
  0.0070880762961266046, 0.0060627529394903946, 0.00487155884558024,
  0.0036772455400638166, 0.0026075575467996021, 0.0017370077993422159,
  0.0010869917053868189, 0.0012708220536009774, 0.0020307678593512817,
  0.0030485436274119157, 0.0042991355919831491, 0.0056954293079680756,
  0.0070880762961266046, 0.008286800745658433, 0.0091012701196484681,
  0.0093901754458158761, 0.0091012701196484681, 0.008286800745658433,
  0.0070880762961266046, 0.0056954293079680756, 0.0042991355919831491,
  0.0030485436274119157, 0.0020307678593512817, 0.0012708220536009774,
  0.0013957249774454289, 0.0022303621633402459, 0.0033481701655666248,
  0.0047216767368435811, 0.0062552053766150211, 0.0077847288694039831,
  0.0091012701196484681, 0.00999578973033754, 0.010313090157022991,
  0.00999578973033754, 0.0091012701196484681, 0.0077847288694039831,
  0.0062552053766150211, 0.0047216767368435811, 0.0033481701655666248,
  0.0022303621633402459, 0.0013957249774454289, 0.0014400300441611551,
  0.0023011614583617352, 0.0034544524955085437, 0.00487155884558024,
  0.0064537669098754889, 0.0080318426901755027, 0.0093901754458158761,
  0.010313090157022991, 0.010640462780452355, 0.010313090157022991,
  0.0093901754458158761, 0.0080318426901755027, 0.0064537669098754889,
  0.00487155884558024, 0.0034544524955085437, 0.0023011614583617352,
  0.0014400300441611551, 0.0013957249774454289, 0.0022303621633402459,
  0.0033481701655666248, 0.0047216767368435811, 0.0062552053766150211,
  0.0077847288694039831, 0.0091012701196484681, 0.00999578973033754,
  0.010313090157022991, 0.00999578973033754, 0.0091012701196484681,
  0.0077847288694039831, 0.0062552053766150211, 0.0047216767368435811,
  0.0033481701655666248, 0.0022303621633402459, 0.0013957249774454289,
  0.0012708220536009774, 0.0020307678593512817, 0.0030485436274119157,
  0.0042991355919831491, 0.0056954293079680756, 0.0070880762961266046,
  0.008286800745658433, 0.0091012701196484681, 0.0093901754458158761,
  0.0091012701196484681, 0.008286800745658433, 0.0070880762961266046,
  0.0056954293079680756, 0.0042991355919831491, 0.0030485436274119157,
  0.0020307678593512817, 0.0012708220536009774, 0.0010869917053868189,
  0.0017370077993422159, 0.0026075575467996021, 0.0036772455400638166,
  0.00487155884558024, 0.0060627529394903946, 0.0070880762961266046,
  0.0077847288694039831, 0.0080318426901755027, 0.0077847288694039831,
  0.0070880762961266046, 0.0060627529394903946, 0.00487155884558024,
  0.0036772455400638166, 0.0026075575467996021, 0.0017370077993422159,
  0.0010869917053868189, 0.00087342237269107809, 0.0013957249774454289,
  0.00209523135104675, 0.0029547498004386975, 0.003914407501478344,
  0.00487155884558024, 0.0056954293079680756, 0.0062552053766150211,
  0.0064537669098754889, 0.0062552053766150211, 0.0056954293079680756,
  0.00487155884558024, 0.003914407501478344, 0.0029547498004386975,
  0.00209523135104675, 0.0013957249774454289, 0.00087342237269107809,
  0.00065929379617042779, 0.0010535484864610237, 0.0015815635990990187,
  0.0022303621633402459, 0.0029547498004386975, 0.0036772455400638166,
  0.0042991355919831491, 0.0047216767368435811, 0.00487155884558024,
  0.0047216767368435811, 0.0042991355919831491, 0.0036772455400638166,
  0.0029547498004386975, 0.0022303621633402459, 0.0015815635990990187,
  0.0010535484864610237, 0.00065929379617042779, 0.00046750930690707231,
  0.0007470777452470756, 0.0011214965260390572, 0.0015815635990990187,
  0.00209523135104675, 0.0026075575467996021, 0.0030485436274119157,
  0.0033481701655666248, 0.0034544524955085437, 0.0033481701655666248,
  0.0030485436274119157, 0.0026075575467996021, 0.00209523135104675,
  0.0015815635990990187, 0.0011214965260390572, 0.0007470777452470756,
  0.00046750930690707231, 0.00031142833774056212, 0.00049766106669510749,
  0.0007470777452470756, 0.0010535484864610237, 0.0013957249774454289,
  0.0017370077993422159, 0.0020307678593512817, 0.0022303621633402459,
  0.0023011614583617352, 0.0022303621633402459, 0.0020307678593512817,
  0.0017370077993422159, 0.0013957249774454289, 0.0010535484864610237,
  0.0007470777452470756, 0.00049766106669510749, 0.00031142833774056212,
  0.00019488687389578179, 0.00031142833774056212, 0.00046750930690707231,
  0.00065929379617042779, 0.00087342237269107809, 0.0010869917053868189,
  0.0012708220536009774, 0.0013957249774454289, 0.0014400300441611551,
  0.0013957249774454289, 0.0012708220536009774, 0.0010869917053868189,
  0.00087342237269107809, 0.00065929379617042779, 0.00046750930690707231,
  0.00031142833774056212, 0.00019488687389578179 };

/* Function Declarations */
static void initialize_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void enable_c5_flightControlSystem(SFc5_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_update_jit_animation_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_do_animation_call_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const mxArray *c5_st);
static void initSimStructsc5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void initSubchartIOPointersc5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_bwmorph(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_bwin[19200], boolean_T c5_bw[19200]);
static void c5_imgaussfilt(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, uint8_T c5_A[19200], uint8_T c5_B[19200]);
static void c5_svd(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c5_sp, real_T c5_U[289], real_T c5_S[289], real_T
                   c5_V[289]);
static void c5_check_forloop_overflow_error
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp);
static void c5_b_bwmorph(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, uint8_T c5_bwin[19200], boolean_T c5_bw[19200]);
static void c5_c_bwmorph(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_bwin[19200], boolean_T c5_bw[19200]);
static boolean_T c5_function_handle_parenReference
  (SFc5_flightControlSystemInstanceStruct *chartInstance, boolean_T
   c5_varargin_1, boolean_T c5_varargin_2);
static void c5_cat(SFc5_flightControlSystemInstanceStruct *chartInstance,
                   boolean_T c5_varargin_1[19200], boolean_T c5_varargin_2[19200],
                   boolean_T c5_varargin_3[19200], boolean_T c5_b_y[57600]);
static void c5_eml_find(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_x[19200], int32_T c5_i_data[], int32_T
  c5_i_size[1], int32_T c5_j_data[], int32_T c5_j_size[1]);
static void c5_indexShapeCheck(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_matrixSize, int32_T
  c5_indexSize[2]);
static void c5_power(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, real_T c5_a_data[], int32_T
                     c5_a_size[1], real_T c5_y_data[], int32_T c5_y_size[1]);
static real_T c5_b_function_handle_parenReference
  (SFc5_flightControlSystemInstanceStruct *chartInstance, real_T c5_varargin_1);
static void c5_sqrt(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T c5_x_size[1],
                    real_T c5_d_x_data[], int32_T c5_b_x_size[1]);
static boolean_T c5_all(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_c_x_data[], int32_T c5_x_size[1]);
static void c5_sort(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T c5_x_size[1],
                    real_T c5_d_x_data[], int32_T c5_b_x_size[1], int32_T
                    c5_idx_data[], int32_T c5_idx_size[1]);
static void c5_sortIdx(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T
  c5_idx_data[], int32_T c5_idx_size[1], real_T c5_d_x_data[], int32_T
  c5_b_x_size[1]);
static void c5_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_idx_data[], int32_T
  c5_idx_size[1], real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T c5_offset,
  int32_T c5_b_idx_data[], int32_T c5_b_idx_size[1], real_T c5_d_x_data[],
  int32_T c5_b_x_size[1]);
static void c5_merge_block(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, int32_T c5_idx_data[], int32_T c5_idx_size[1], real_T
  c5_c_x_data[], int32_T c5_x_size[1], int32_T c5_offset, int32_T c5_n, int32_T
  c5_preSortLevel, int32_T c5_b_iwork_data[], int32_T c5_iwork_size[1], real_T
  c5_b_xwork_data[], int32_T c5_xwork_size[1], int32_T c5_b_idx_data[], int32_T
  c5_b_idx_size[1], real_T c5_d_x_data[], int32_T c5_b_x_size[1], int32_T
  c5_c_iwork_data[], int32_T c5_b_iwork_size[1], real_T c5_c_xwork_data[],
  int32_T c5_b_xwork_size[1]);
static void c5_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, int32_T c5_idx_data[], int32_T
                     c5_idx_size[1], real_T c5_c_x_data[], int32_T c5_x_size[1],
                     int32_T c5_offset, int32_T c5_np, int32_T c5_nq, int32_T
                     c5_b_iwork_data[], int32_T c5_iwork_size[1], real_T
                     c5_b_xwork_data[], int32_T c5_xwork_size[1], int32_T
                     c5_b_idx_data[], int32_T c5_b_idx_size[1], real_T
                     c5_d_x_data[], int32_T c5_b_x_size[1], int32_T
                     c5_c_iwork_data[], int32_T c5_b_iwork_size[1], real_T
                     c5_c_xwork_data[], int32_T c5_b_xwork_size[1]);
static void c5_isfinite(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real_T c5_c_x_data[], int32_T c5_x_size[1], boolean_T c5_b_data[], int32_T
  c5_b_size[1]);
static void c5_b_sort(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T
                      c5_x_size[1], real_T c5_d_x_data[], int32_T c5_b_x_size[1],
                      int32_T c5_idx_data[], int32_T c5_idx_size[1]);
static real_T c5_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier,
  uint8_T c5_b_y[57600]);
static void c5_d_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  uint8_T c5_b_y[57600]);
static void c5_e_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier, real_T
  c5_b_y[40]);
static void c5_f_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[40]);
static real_T c5_g_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier,
  boolean_T *c5_svPtr);
static real_T c5_h_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  boolean_T *c5_svPtr);
static uint8_T c5_i_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier);
static uint8_T c5_j_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_slStringInitializeDynamicBuffers
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_chart_data_browse_helper(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_ssIdNumber, const mxArray **c5_mxData, uint8_T
  *c5_isValueTooBig);
static void c5_b_sqrt(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T
                      c5_x_size[1]);
static void c5_c_sort(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T
                      c5_x_size[1], int32_T c5_idx_data[], int32_T c5_idx_size[1]);
static void c5_b_sortIdx(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T
  c5_idx_data[], int32_T c5_idx_size[1]);
static void c5_b_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_idx_data[], real_T
  c5_c_x_data[], int32_T c5_offset);
static void c5_b_merge_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_idx_data[], real_T
  c5_c_x_data[], int32_T c5_offset, int32_T c5_n, int32_T c5_preSortLevel,
  int32_T c5_b_iwork_data[], real_T c5_b_xwork_data[]);
static void c5_b_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, int32_T c5_idx_data[], real_T c5_c_x_data[], int32_T
  c5_offset, int32_T c5_np, int32_T c5_nq, int32_T c5_b_iwork_data[], real_T
  c5_b_xwork_data[]);
static void c5_d_sort(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T
                      c5_x_size[1], int32_T c5_idx_data[], int32_T c5_idx_size[1]);
static void c5_plus(SFc5_flightControlSystemInstanceStruct *chartInstance,
                    real_T c5_b_in1_data[], int32_T c5_in1_size[1], real_T
                    c5_in2_data[], int32_T c5_in2_size[1]);
static void init_dsm_address_info(SFc5_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc5_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c5_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c5_st.tls = chartInstance->c5_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c5_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sf_is_first_init_cond(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c5_call_count_not_empty = false;
  chartInstance->c5_doneDoubleBufferReInit = false;
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  static const int32_T c5_b_postfixPredicateTree[7] = { 0, 1, -3, 2, -3, 3, -3 };

  static const int32_T c5_c_postfixPredicateTree[7] = { 0, 1, -3, 2, -3, 3, -3 };

  static const int32_T c5_b_condTxtEndIdx[4] = { 3789, 3811, 3820, 3842 };

  static const int32_T c5_b_condTxtStartIdx[4] = { 3784, 3793, 3815, 3824 };

  static const int32_T c5_c_condTxtEndIdx[4] = { 4316, 4338, 4347, 4369 };

  static const int32_T c5_c_condTxtStartIdx[4] = { 4311, 4320, 4342, 4351 };

  static const int32_T c5_d_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c5_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c5_condTxtEndIdx[2] = { 2752, 2786 };

  static const int32_T c5_condTxtStartIdx[2] = { 2724, 2756 };

  static const int32_T c5_d_condTxtEndIdx[2] = { 4724, 4742 };

  static const int32_T c5_d_condTxtStartIdx[2] = { 4708, 4728 };

  static const uint32_T c5_decisionTxtEndIdx = 0U;
  static const uint32_T c5_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, chartInstance->c5_JITStateAnimation,
                        chartInstance->c5_JITTransitionAnimation);
  setDataBrowseFcn(chartInstance->S, (void *)&c5_chart_data_browse_helper);
  chartInstance->c5_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c5_RuntimeVar,
    &chartInstance->c5_IsDebuggerActive,
    &chartInstance->c5_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c5_mlFcnLineNumber, &chartInstance->c5_IsHeatMapPresent, 0);
  covrtCreateStateflowInstanceData(chartInstance->c5_covrtInstance, 1U, 0U, 1U,
    60U);
  covrtChartInitFcn(chartInstance->c5_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c5_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c5_decisionTxtStartIdx, &c5_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c5_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c5_covrtInstance, "", 4U, 0U, 1U, 0U, 10U, 0U,
                  3U, 0U, 6U, 0U, 12U, 4U);
  covrtEmlFcnInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 4900);
  covrtEmlSaturationInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 3920,
    -1, 3966);
  covrtEmlSaturationInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 467, -1,
    489);
  covrtEmlSaturationInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 2U, 793, -1,
    851);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 132, 154, -1,
                    178, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 1037, 1050,
                    1154, 1422, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 2U, 1267, 1291, -1,
                    1414, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 3U, 2721, 2786, -1,
                    3463, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 4U, 3610, 3636, -1,
                    4079, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 5U, 3781, 3842, -1,
                    4063, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 6U, 4177, 4203, -1,
                    4579, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 7U, 4308, 4369, -1,
                    4563, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 8U, 4625, 4643,
                    4701, 4865, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 9U, 4701, 4742,
                    4801, 4865, false);
  covrtEmlForInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 1010, 1032,
                     1426);
  covrtEmlForInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 3510, 3537,
                     4103);
  covrtEmlForInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 2U, 3542, 3565,
                     4099);
  covrtEmlForInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 3U, 3574, 3597,
                     4091);
  covrtEmlForInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 4U, 4109, 4132,
                     4599);
  covrtEmlForInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 5U, 4141, 4164,
                     4591);
  covrtEmlMCDCInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 2724, 2786,
                      2U, 0U, c5_condTxtStartIdx, c5_condTxtEndIdx, 3U,
                      c5_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 3784, 3842,
                      4U, 2U, c5_b_condTxtStartIdx, c5_b_condTxtEndIdx, 7U,
                      c5_b_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 2U, 4311, 4369,
                      4U, 6U, c5_c_condTxtStartIdx, c5_c_condTxtEndIdx, 7U,
                      c5_c_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 3U, 4708, 4742,
                      2U, 10U, c5_d_condTxtStartIdx, c5_d_condTxtEndIdx, 3U,
                      c5_d_postfixPredicateTree, false);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 1040,
    1050, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 2724,
    2752, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 2U, 3613,
    3636, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 3U, 3784,
    3789, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 4U, 3793,
    3811, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 5U, 3815,
    3820, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 6U, 3824,
    3842, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 7U, 4180,
    4203, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 8U, 4311,
    4316, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 9U, 4320,
    4338, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 10U, 4342,
    4347, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 11U, 4351,
    4369, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 12U, 4628,
    4643, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 13U, 4708,
    4724, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 14U, 4728,
    4742, -1, 2U);
}

static void mdl_cleanup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c5_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c5_covrtInstance);
}

static void enable_c5_flightControlSystem(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c5_b_pointsx[40];
  real_T c5_b_pointsy[40];
  real_T c5_closestIndices_data[40];
  real_T c5_unsorted_validY_data[40];
  real_T c5_b_dv[2];
  real_T c5_b_c;
  real_T c5_b_distX;
  real_T c5_b_distY;
  real_T c5_b_dom_x;
  real_T c5_b_dom_y;
  real_T c5_b_k;
  real_T c5_b_roundFloatVar;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_c;
  real_T c5_c_c;
  real_T c5_c_dx;
  real_T c5_c_dy;
  real_T c5_c_i;
  real_T c5_c_roundFloatVar;
  real_T c5_c_x;
  real_T c5_c_y;
  real_T c5_count;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d10;
  real_T c5_d11;
  real_T c5_d12;
  real_T c5_d13;
  real_T c5_d14;
  real_T c5_d15;
  real_T c5_d16;
  real_T c5_d17;
  real_T c5_d18;
  real_T c5_d19;
  real_T c5_d2;
  real_T c5_d20;
  real_T c5_d21;
  real_T c5_d22;
  real_T c5_d23;
  real_T c5_d24;
  real_T c5_d25;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d5;
  real_T c5_d6;
  real_T c5_d7;
  real_T c5_d8;
  real_T c5_d9;
  real_T c5_d_a;
  real_T c5_d_b;
  real_T c5_d_c;
  real_T c5_d_roundFloatVar;
  real_T c5_d_y;
  real_T c5_e_a;
  real_T c5_e_y;
  real_T c5_f_a;
  real_T c5_f_y;
  real_T c5_g_a;
  real_T c5_g_y;
  real_T c5_h_a;
  real_T c5_h_y;
  real_T c5_i_a;
  real_T c5_j_a;
  real_T c5_k_a;
  real_T c5_l_a;
  real_T c5_m_a;
  real_T c5_n_a;
  real_T c5_o_a;
  real_T c5_p_a;
  real_T c5_q_a;
  real_T c5_r_a;
  real_T c5_roundFloatVar;
  real_T c5_s_a;
  real_T c5_t_a;
  real_T c5_u_a;
  real_T c5_v_a;
  real_T c5_varargin_2;
  real_T c5_w_a;
  real_T c5_x;
  real_T c5_xIdx;
  real_T c5_yIdx;
  int32_T c5_b_tmp_data[40];
  int32_T c5_c_iidx_data[40];
  int32_T c5_b_tmp_size[2];
  int32_T c5_iv[2];
  int32_T c5_iv1[2];
  int32_T c5_iv2[2];
  int32_T c5_iv3[2];
  int32_T c5_iv4[2];
  int32_T c5_b_filteredX_size[1];
  int32_T c5_b_filteredY_size[1];
  int32_T c5_b_minDistances_size[1];
  int32_T c5_c_filteredX_size[1];
  int32_T c5_c_filteredY_size[1];
  int32_T c5_c_tmp_size[1];
  int32_T c5_closestIndices_size[1];
  int32_T c5_d_filteredX_size[1];
  int32_T c5_d_filteredY_size[1];
  int32_T c5_filteredX_size[1];
  int32_T c5_filteredY_size[1];
  int32_T c5_ii_size[1];
  int32_T c5_iidx_size[1];
  int32_T c5_jj_size[1];
  int32_T c5_minDistances_size[1];
  int32_T c5_tmp_size[1];
  int32_T c5_unsorted_validY_size[1];
  int32_T c5_xIdx_size[1];
  int32_T c5_yIdx_size[1];
  int32_T c5_ab_loop_ub;
  int32_T c5_b_dx;
  int32_T c5_b_dy;
  int32_T c5_b_end;
  int32_T c5_b_fixedVar;
  int32_T c5_b_i;
  int32_T c5_b_loop_ub;
  int32_T c5_b_trueCount;
  int32_T c5_bb_loop_ub;
  int32_T c5_c_fixedVar;
  int32_T c5_c_loop_ub;
  int32_T c5_d_fixedVar;
  int32_T c5_d_i;
  int32_T c5_d_loop_ub;
  int32_T c5_dx;
  int32_T c5_dy;
  int32_T c5_e_i;
  int32_T c5_e_loop_ub;
  int32_T c5_end;
  int32_T c5_f_i;
  int32_T c5_f_loop_ub;
  int32_T c5_filteredX;
  int32_T c5_filteredY;
  int32_T c5_fixedVar;
  int32_T c5_g_i;
  int32_T c5_g_loop_ub;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  int32_T c5_i103;
  int32_T c5_i104;
  int32_T c5_i105;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i6;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i7;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i8;
  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i9;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i_loop_ub;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_k_loop_ub;
  int32_T c5_l_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_m_loop_ub;
  int32_T c5_n_loop_ub;
  int32_T c5_o_loop_ub;
  int32_T c5_p_loop_ub;
  int32_T c5_partialTrueCount;
  int32_T c5_q_loop_ub;
  int32_T c5_r_loop_ub;
  int32_T c5_s_loop_ub;
  int32_T c5_t_loop_ub;
  int32_T c5_trueCount;
  int32_T c5_u_loop_ub;
  int32_T c5_unsorted_validY;
  int32_T c5_v_loop_ub;
  int32_T c5_w_loop_ub;
  int32_T c5_x_loop_ub;
  int32_T c5_y_loop_ub;
  uint8_T c5_c_u;
  uint8_T c5_u1;
  uint8_T c5_u2;
  boolean_T c5_b_minDistances_data[19200];
  boolean_T c5_blueChannel[19200];
  boolean_T c5_bv1[19200];
  boolean_T c5_c_cleanedImage[19200];
  boolean_T c5_greenChannel[19200];
  boolean_T c5_redChannel[19200];
  boolean_T c5_bv2[40];
  boolean_T c5_c_tmp_data[40];
  boolean_T c5_b1;
  boolean_T c5_b10;
  boolean_T c5_b11;
  boolean_T c5_b12;
  boolean_T c5_b13;
  boolean_T c5_b14;
  boolean_T c5_b15;
  boolean_T c5_b16;
  boolean_T c5_b17;
  boolean_T c5_b18;
  boolean_T c5_b19;
  boolean_T c5_b2;
  boolean_T c5_b20;
  boolean_T c5_b21;
  boolean_T c5_b22;
  boolean_T c5_b23;
  boolean_T c5_b24;
  boolean_T c5_b25;
  boolean_T c5_b26;
  boolean_T c5_b27;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b6;
  boolean_T c5_b7;
  boolean_T c5_b8;
  boolean_T c5_b9;
  boolean_T c5_b_covSaturation = false;
  boolean_T c5_c_b;
  boolean_T c5_c_covSaturation = false;
  boolean_T c5_covSaturation = false;
  boolean_T c5_guard1;
  c5_st.tls = chartInstance->c5_fEmlrtCtx;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 0U, (real_T)
                      (*chartInstance->c5_b_u)[c5_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_JITTransitionAnimation[0] = 0U;
  chartInstance->c5_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c5_covrtInstance, 4U, 0, 0);
  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 0,
                     !chartInstance->c5_call_count_not_empty)) {
    chartInstance->c5_call_count = 1.0;
    chartInstance->c5_call_count_not_empty = true;
  }

  c5_b_st.site = &c5_xd_emlrtRSI;
  for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
    chartInstance->c5_bv[c5_i1] = (*chartInstance->c5_b_u)[c5_i1];
  }

  c5_bwmorph(chartInstance, chartInstance->c5_bv, chartInstance->c5_cleanedImage);
  for (c5_i2 = 0; c5_i2 < 19200; c5_i2++) {
    c5_d = muDoubleScalarRound((real_T)chartInstance->c5_cleanedImage[c5_i2] *
      255.0);
    c5_covSaturation = false;
    if (c5_d < 256.0) {
      if (c5_d >= 0.0) {
        c5_c_u = (uint8_T)c5_d;
      } else {
        c5_covSaturation = true;
        c5_c_u = 0U;
      }
    } else if (c5_d >= 256.0) {
      c5_covSaturation = true;
      c5_c_u = MAX_uint8_T;
    } else {
      c5_c_u = 0U;
    }

    covrtSaturationUpdateFcn(chartInstance->c5_covrtInstance, 4, 0, 1, 0,
      c5_covSaturation);
    chartInstance->c5_u[c5_i2] = c5_c_u;
  }

  c5_b_st.site = &c5_yd_emlrtRSI;
  c5_imgaussfilt(chartInstance, &c5_b_st, chartInstance->c5_u,
                 chartInstance->c5_b_cleanedImage);
  c5_b_st.site = &c5_ae_emlrtRSI;
  c5_b_bwmorph(chartInstance, &c5_b_st, chartInstance->c5_b_cleanedImage,
               chartInstance->c5_cleanedImage);
  for (c5_i3 = 0; c5_i3 < 19200; c5_i3++) {
    c5_c_cleanedImage[c5_i3] = chartInstance->c5_cleanedImage[c5_i3];
  }

  c5_b_st.site = &c5_be_emlrtRSI;
  c5_c_bwmorph(chartInstance, c5_c_cleanedImage, chartInstance->c5_cleanedImage);
  for (c5_i4 = 0; c5_i4 < 19200; c5_i4++) {
    c5_redChannel[c5_i4] = (chartInstance->c5_b_cleanedImage[c5_i4] != 0);
  }

  for (c5_i5 = 0; c5_i5 < 19200; c5_i5++) {
    c5_bv1[c5_i5] = !chartInstance->c5_cleanedImage[c5_i5];
  }

  for (c5_i6 = 0; c5_i6 < 19200; c5_i6++) {
    c5_redChannel[c5_i6] = (c5_redChannel[c5_i6] && c5_bv1[c5_i6]);
  }

  for (c5_i7 = 0; c5_i7 < 19200; c5_i7++) {
    c5_greenChannel[c5_i7] = (chartInstance->c5_b_cleanedImage[c5_i7] != 0);
  }

  for (c5_i8 = 0; c5_i8 < 19200; c5_i8++) {
    c5_bv1[c5_i8] = !chartInstance->c5_cleanedImage[c5_i8];
  }

  for (c5_i9 = 0; c5_i9 < 19200; c5_i9++) {
    c5_greenChannel[c5_i9] = (c5_greenChannel[c5_i9] && c5_bv1[c5_i9]);
  }

  for (c5_i10 = 0; c5_i10 < 19200; c5_i10++) {
    c5_blueChannel[c5_i10] = (chartInstance->c5_b_cleanedImage[c5_i10] != 0);
  }

  for (c5_i11 = 0; c5_i11 < 19200; c5_i11++) {
    c5_bv1[c5_i11] = !chartInstance->c5_cleanedImage[c5_i11];
  }

  for (c5_i12 = 0; c5_i12 < 19200; c5_i12++) {
    c5_blueChannel[c5_i12] = (c5_blueChannel[c5_i12] && c5_bv1[c5_i12]);
  }

  c5_cat(chartInstance, c5_redChannel, c5_greenChannel, c5_blueChannel,
         chartInstance->c5_b_a);
  for (c5_i13 = 0; c5_i13 < 57600; c5_i13++) {
    chartInstance->c5_y[c5_i13] = (real_T)chartInstance->c5_b_a[c5_i13] * 255.0;
  }

  for (c5_i14 = 0; c5_i14 < 57600; c5_i14++) {
    c5_d1 = muDoubleScalarRound(chartInstance->c5_y[c5_i14]);
    c5_b_covSaturation = false;
    if (c5_d1 < 256.0) {
      if (c5_d1 >= 0.0) {
        c5_u1 = (uint8_T)c5_d1;
      } else {
        c5_b_covSaturation = true;
        c5_u1 = 0U;
        sf_data_saturate_error(chartInstance->S, 1U, 793, 58);
      }
    } else if (c5_d1 >= 256.0) {
      c5_b_covSaturation = true;
      c5_u1 = MAX_uint8_T;
      sf_data_saturate_error(chartInstance->S, 1U, 793, 58);
    } else {
      c5_u1 = 0U;
    }

    covrtSaturationUpdateFcn(chartInstance->c5_covrtInstance, 4, 0, 2, 0,
      c5_b_covSaturation);
    chartInstance->c5_outt[c5_i14] = c5_u1;
  }

  c5_b_st.site = &c5_ce_emlrtRSI;
  c5_c_st.site = &c5_kc_emlrtRSI;
  c5_eml_find(chartInstance, &c5_c_st, chartInstance->c5_cleanedImage,
              chartInstance->c5_ii_data, c5_ii_size, chartInstance->c5_jj_data,
              c5_jj_size);
  c5_yIdx_size[0] = c5_ii_size[0];
  c5_loop_ub = c5_ii_size[0] - 1;
  for (c5_i15 = 0; c5_i15 <= c5_loop_ub; c5_i15++) {
    chartInstance->c5_yIdx_data[c5_i15] = (real_T)chartInstance->
      c5_ii_data[c5_i15];
  }

  c5_xIdx_size[0] = c5_jj_size[0];
  c5_b_loop_ub = c5_jj_size[0] - 1;
  for (c5_i16 = 0; c5_i16 <= c5_b_loop_ub; c5_i16++) {
    chartInstance->c5_xIdx_data[c5_i16] = (real_T)chartInstance->
      c5_jj_data[c5_i16];
  }

  c5_d2 = (real_T)c5_xIdx_size[0];
  if (!(c5_d2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c5_d2, &c5_n_emlrtDCI, &c5_st);
  }

  if (c5_d2 != (real_T)(int32_T)muDoubleScalarFloor(c5_d2)) {
    emlrtIntegerCheckR2012b(c5_d2, &c5_o_emlrtDCI, &c5_st);
  }

  c5_b_dv[0] = c5_d2;
  c5_d3 = trunc(c5_b_dv[0]);
  if (muDoubleScalarIsNaN(c5_d3) || muDoubleScalarIsInf(c5_d3)) {
    c5_d4 = 0.0;
  } else {
    c5_d4 = muDoubleScalarRem(c5_d3, 4.294967296E+9);
  }

  c5_roundFloatVar = trunc(c5_b_dv[0]);
  if (c5_d4 < 0.0) {
    c5_fixedVar = -(int32_T)(uint32_T)-c5_d4;
  } else {
    c5_fixedVar = (int32_T)(uint32_T)c5_d4;
  }

  if (c5_roundFloatVar < 0.0) {
    c5_d5 = muDoubleScalarCeil(c5_roundFloatVar);
  } else {
    c5_d5 = muDoubleScalarFloor(c5_roundFloatVar);
  }

  if ((real_T)c5_fixedVar != c5_d5) {
    sf_data_overflow_error(chartInstance->S, 1U, 936, 29);
  }

  c5_filteredX_size[0] = c5_fixedVar;
  c5_d6 = trunc(c5_b_dv[0]);
  if (muDoubleScalarIsNaN(c5_d6) || muDoubleScalarIsInf(c5_d6)) {
    c5_d7 = 0.0;
  } else {
    c5_d7 = muDoubleScalarRem(c5_d6, 4.294967296E+9);
  }

  c5_b_roundFloatVar = trunc(c5_b_dv[0]);
  if (c5_d7 < 0.0) {
    c5_b_fixedVar = -(int32_T)(uint32_T)-c5_d7;
  } else {
    c5_b_fixedVar = (int32_T)(uint32_T)c5_d7;
  }

  if (c5_b_roundFloatVar < 0.0) {
    c5_d8 = muDoubleScalarCeil(c5_b_roundFloatVar);
  } else {
    c5_d8 = muDoubleScalarFloor(c5_b_roundFloatVar);
  }

  if ((real_T)c5_b_fixedVar != c5_d8) {
    sf_data_overflow_error(chartInstance->S, 1U, 936, 29);
  }

  c5_c_loop_ub = c5_b_fixedVar - 1;
  for (c5_i17 = 0; c5_i17 <= c5_c_loop_ub; c5_i17++) {
    chartInstance->c5_filteredX_data[c5_i17] = 0.0;
  }

  c5_d9 = (real_T)c5_yIdx_size[0];
  if (!(c5_d9 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c5_d9, &c5_p_emlrtDCI, &c5_st);
  }

  if (c5_d9 != (real_T)(int32_T)muDoubleScalarFloor(c5_d9)) {
    emlrtIntegerCheckR2012b(c5_d9, &c5_q_emlrtDCI, &c5_st);
  }

  c5_b_dv[0] = c5_d9;
  c5_d10 = trunc(c5_b_dv[0]);
  if (muDoubleScalarIsNaN(c5_d10) || muDoubleScalarIsInf(c5_d10)) {
    c5_d11 = 0.0;
  } else {
    c5_d11 = muDoubleScalarRem(c5_d10, 4.294967296E+9);
  }

  c5_c_roundFloatVar = trunc(c5_b_dv[0]);
  if (c5_d11 < 0.0) {
    c5_c_fixedVar = -(int32_T)(uint32_T)-c5_d11;
  } else {
    c5_c_fixedVar = (int32_T)(uint32_T)c5_d11;
  }

  if (c5_c_roundFloatVar < 0.0) {
    c5_d12 = muDoubleScalarCeil(c5_c_roundFloatVar);
  } else {
    c5_d12 = muDoubleScalarFloor(c5_c_roundFloatVar);
  }

  if ((real_T)c5_c_fixedVar != c5_d12) {
    sf_data_overflow_error(chartInstance->S, 1U, 967, 29);
  }

  c5_filteredY_size[0] = c5_c_fixedVar;
  c5_d13 = trunc(c5_b_dv[0]);
  if (muDoubleScalarIsNaN(c5_d13) || muDoubleScalarIsInf(c5_d13)) {
    c5_d14 = 0.0;
  } else {
    c5_d14 = muDoubleScalarRem(c5_d13, 4.294967296E+9);
  }

  c5_d_roundFloatVar = trunc(c5_b_dv[0]);
  if (c5_d14 < 0.0) {
    c5_d_fixedVar = -(int32_T)(uint32_T)-c5_d14;
  } else {
    c5_d_fixedVar = (int32_T)(uint32_T)c5_d14;
  }

  if (c5_d_roundFloatVar < 0.0) {
    c5_d15 = muDoubleScalarCeil(c5_d_roundFloatVar);
  } else {
    c5_d15 = muDoubleScalarFloor(c5_d_roundFloatVar);
  }

  if ((real_T)c5_d_fixedVar != c5_d15) {
    sf_data_overflow_error(chartInstance->S, 1U, 967, 29);
  }

  c5_d_loop_ub = c5_d_fixedVar - 1;
  for (c5_i18 = 0; c5_i18 <= c5_d_loop_ub; c5_i18++) {
    chartInstance->c5_filteredY_data[c5_i18] = 0.0;
  }

  c5_count = 0.0;
  c5_d16 = (real_T)c5_xIdx_size[0];
  c5_i19 = (int32_T)c5_d16;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c5_d16, mxDOUBLE_CLASS, c5_i19,
    &c5_ac_emlrtRTEI, &c5_st);
  for (c5_b_i = 0; c5_b_i < c5_i19; c5_b_i++) {
    c5_c_i = 1.0 + (real_T)c5_b_i;
    covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 0, 1);
    if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 1,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c5_covrtInstance, 4U, 0U, 0U, c5_count,
                        0.0, -1, 0U, c5_count == 0.0))) {
      c5_count++;
      if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
        emlrtIntegerCheckR2012b(c5_c_i, &c5_r_emlrtDCI, &c5_st);
      }

      c5_i22 = (int32_T)c5_c_i;
      if ((c5_i22 < 1) || (c5_i22 > c5_xIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c5_i22, 1, c5_xIdx_size[0], &c5_s_emlrtBCI,
          &c5_st);
      }

      if (c5_count != (real_T)(int32_T)muDoubleScalarFloor(c5_count)) {
        emlrtIntegerCheckR2012b(c5_count, &c5_s_emlrtDCI, &c5_st);
      }

      c5_i27 = (int32_T)c5_count;
      if ((c5_i27 < 1) || (c5_i27 > c5_filteredX_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c5_i27, 1, c5_filteredX_size[0],
          &c5_t_emlrtBCI, &c5_st);
      }

      chartInstance->c5_filteredX_data[c5_i27 - 1] = chartInstance->
        c5_xIdx_data[c5_i22 - 1];
      if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
        emlrtIntegerCheckR2012b(c5_c_i, &c5_t_emlrtDCI, &c5_st);
      }

      c5_i31 = (int32_T)c5_c_i;
      if ((c5_i31 < 1) || (c5_i31 > c5_yIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c5_i31, 1, c5_yIdx_size[0], &c5_u_emlrtBCI,
          &c5_st);
      }

      if (c5_count != (real_T)(int32_T)muDoubleScalarFloor(c5_count)) {
        emlrtIntegerCheckR2012b(c5_count, &c5_u_emlrtDCI, &c5_st);
      }

      c5_i36 = (int32_T)c5_count;
      if ((c5_i36 < 1) || (c5_i36 > c5_filteredY_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c5_i36, 1, c5_filteredY_size[0],
          &c5_v_emlrtBCI, &c5_st);
      }

      chartInstance->c5_filteredY_data[c5_i36 - 1] = chartInstance->
        c5_yIdx_data[c5_i31 - 1];
    } else {
      c5_b3 = (c5_count < 1.0);
      c5_b5 = c5_b3;
      c5_b6 = false;
      c5_b7 = (c5_b5 || c5_b6);
      if (c5_b7) {
        c5_i25 = 1;
        c5_i26 = 0;
      } else {
        c5_i24 = 1;
        if ((c5_i24 < 1) || (c5_i24 > c5_filteredX_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c5_i24, 1, c5_filteredX_size[0],
            &c5_emlrtBCI, &c5_st);
        }

        c5_i25 = c5_i24;
        if (c5_count != (real_T)(int32_T)muDoubleScalarFloor(c5_count)) {
          emlrtIntegerCheckR2012b(c5_count, &c5_emlrtDCI, &c5_st);
        }

        c5_i29 = (int32_T)c5_count;
        if ((c5_i29 < 1) || (c5_i29 > c5_filteredX_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c5_i29, 1, c5_filteredX_size[0],
            &c5_b_emlrtBCI, &c5_st);
        }

        c5_i26 = c5_i29;
      }

      c5_iv1[0] = 1;
      c5_iv1[1] = (c5_i26 - c5_i25) + 1;
      c5_b_st.site = &c5_de_emlrtRSI;
      c5_indexShapeCheck(chartInstance, &c5_b_st, c5_filteredX_size[0], c5_iv1);
      c5_b8 = (c5_count < 1.0);
      c5_b9 = c5_b8;
      c5_b10 = false;
      c5_b11 = (c5_b9 || c5_b10);
      if (c5_b11) {
        c5_i34 = 1;
        c5_i35 = 0;
      } else {
        c5_i33 = 1;
        if ((c5_i33 < 1) || (c5_i33 > c5_filteredY_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c5_i33, 1, c5_filteredY_size[0],
            &c5_c_emlrtBCI, &c5_st);
        }

        c5_i34 = c5_i33;
        if (c5_count != (real_T)(int32_T)muDoubleScalarFloor(c5_count)) {
          emlrtIntegerCheckR2012b(c5_count, &c5_b_emlrtDCI, &c5_st);
        }

        c5_i39 = (int32_T)c5_count;
        if ((c5_i39 < 1) || (c5_i39 > c5_filteredY_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c5_i39, 1, c5_filteredY_size[0],
            &c5_d_emlrtBCI, &c5_st);
        }

        c5_i35 = c5_i39;
      }

      c5_iv2[0] = 1;
      c5_iv2[1] = (c5_i35 - c5_i34) + 1;
      c5_b_st.site = &c5_de_emlrtRSI;
      c5_indexShapeCheck(chartInstance, &c5_b_st, c5_filteredY_size[0], c5_iv2);
      if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
        emlrtIntegerCheckR2012b(c5_c_i, &c5_v_emlrtDCI, &c5_st);
      }

      c5_i41 = (int32_T)c5_c_i;
      if ((c5_i41 < 1) || (c5_i41 > c5_xIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c5_i41, 1, c5_xIdx_size[0], &c5_w_emlrtBCI,
          &c5_st);
      }

      c5_xIdx = chartInstance->c5_xIdx_data[c5_i41 - 1];
      c5_c_filteredX_size[0] = (c5_i26 - c5_i25) + 1;
      c5_h_loop_ub = c5_i26 - c5_i25;
      for (c5_i44 = 0; c5_i44 <= c5_h_loop_ub; c5_i44++) {
        chartInstance->c5_c_filteredX_data[c5_i44] =
          chartInstance->c5_filteredX_data[(c5_i25 + c5_i44) - 1] - c5_xIdx;
      }

      c5_b_st.site = &c5_de_emlrtRSI;
      c5_power(chartInstance, &c5_b_st, chartInstance->c5_c_filteredX_data,
               c5_c_filteredX_size, chartInstance->c5_minDistances_data,
               c5_minDistances_size);
      if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
        emlrtIntegerCheckR2012b(c5_c_i, &c5_w_emlrtDCI, &c5_st);
      }

      c5_i46 = (int32_T)c5_c_i;
      if ((c5_i46 < 1) || (c5_i46 > c5_yIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c5_i46, 1, c5_yIdx_size[0], &c5_x_emlrtBCI,
          &c5_st);
      }

      c5_yIdx = chartInstance->c5_yIdx_data[c5_i46 - 1];
      c5_c_filteredY_size[0] = (c5_i35 - c5_i34) + 1;
      c5_l_loop_ub = c5_i35 - c5_i34;
      for (c5_i49 = 0; c5_i49 <= c5_l_loop_ub; c5_i49++) {
        chartInstance->c5_c_filteredY_data[c5_i49] =
          chartInstance->c5_filteredY_data[(c5_i34 + c5_i49) - 1] - c5_yIdx;
      }

      c5_b_st.site = &c5_de_emlrtRSI;
      c5_power(chartInstance, &c5_b_st, chartInstance->c5_c_filteredY_data,
               c5_c_filteredY_size, chartInstance->c5_tmp_data, c5_tmp_size);
      if ((c5_minDistances_size[0] != c5_tmp_size[0]) && ((c5_minDistances_size
            [0] != 1) && (c5_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c5_minDistances_size[0], c5_tmp_size[0],
          &c5_emlrtECI, &c5_st);
      }

      if (c5_minDistances_size[0] == c5_tmp_size[0]) {
        c5_o_loop_ub = c5_minDistances_size[0] - 1;
        for (c5_i52 = 0; c5_i52 <= c5_o_loop_ub; c5_i52++) {
          chartInstance->c5_minDistances_data[c5_i52] +=
            chartInstance->c5_tmp_data[c5_i52];
        }
      } else {
        c5_plus(chartInstance, chartInstance->c5_minDistances_data,
                c5_minDistances_size, chartInstance->c5_tmp_data, c5_tmp_size);
      }

      c5_b_st.site = &c5_de_emlrtRSI;
      c5_b_sqrt(chartInstance, &c5_b_st, chartInstance->c5_minDistances_data,
                c5_minDistances_size);
      c5_b_minDistances_size[0] = c5_minDistances_size[0];
      c5_p_loop_ub = c5_minDistances_size[0] - 1;
      for (c5_i53 = 0; c5_i53 <= c5_p_loop_ub; c5_i53++) {
        c5_b_minDistances_data[c5_i53] = (chartInstance->
          c5_minDistances_data[c5_i53] > 7.0);
      }

      c5_b_st.site = &c5_ee_emlrtRSI;
      if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 2, c5_all
                         (chartInstance, &c5_b_st, c5_b_minDistances_data,
                          c5_b_minDistances_size))) {
        c5_count++;
        if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
          emlrtIntegerCheckR2012b(c5_c_i, &c5_x_emlrtDCI, &c5_st);
        }

        c5_i55 = (int32_T)c5_c_i;
        if ((c5_i55 < 1) || (c5_i55 > c5_xIdx_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c5_i55, 1, c5_xIdx_size[0],
            &c5_y_emlrtBCI, &c5_st);
        }

        if (c5_count != (real_T)(int32_T)muDoubleScalarFloor(c5_count)) {
          emlrtIntegerCheckR2012b(c5_count, &c5_y_emlrtDCI, &c5_st);
        }

        c5_i57 = (int32_T)c5_count;
        if ((c5_i57 < 1) || (c5_i57 > c5_filteredX_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c5_i57, 1, c5_filteredX_size[0],
            &c5_ab_emlrtBCI, &c5_st);
        }

        chartInstance->c5_filteredX_data[c5_i57 - 1] =
          chartInstance->c5_xIdx_data[c5_i55 - 1];
        if (c5_c_i != (real_T)(int32_T)muDoubleScalarFloor(c5_c_i)) {
          emlrtIntegerCheckR2012b(c5_c_i, &c5_ab_emlrtDCI, &c5_st);
        }

        c5_i58 = (int32_T)c5_c_i;
        if ((c5_i58 < 1) || (c5_i58 > c5_yIdx_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c5_i58, 1, c5_yIdx_size[0],
            &c5_bb_emlrtBCI, &c5_st);
        }

        if (c5_count != (real_T)(int32_T)muDoubleScalarFloor(c5_count)) {
          emlrtIntegerCheckR2012b(c5_count, &c5_bb_emlrtDCI, &c5_st);
        }

        c5_i59 = (int32_T)c5_count;
        if ((c5_i59 < 1) || (c5_i59 > c5_filteredY_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c5_i59, 1, c5_filteredY_size[0],
            &c5_cb_emlrtBCI, &c5_st);
        }

        chartInstance->c5_filteredY_data[c5_i59 - 1] =
          chartInstance->c5_yIdx_data[c5_i58 - 1];
      }
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 0, 0);
  c5_c_b = (c5_count < 1.0);
  c5_b1 = c5_c_b;
  c5_b2 = false;
  c5_b4 = (c5_b1 || c5_b2);
  if (c5_b4) {
    c5_i21 = 1;
    c5_i23 = 0;
  } else {
    c5_i20 = 1;
    if ((c5_i20 < 1) || (c5_i20 > c5_filteredX_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c5_i20, 1, c5_filteredX_size[0],
        &c5_e_emlrtBCI, &c5_st);
    }

    c5_i21 = c5_i20;
    if (c5_count != (real_T)(int32_T)muDoubleScalarFloor(c5_count)) {
      emlrtIntegerCheckR2012b(c5_count, &c5_c_emlrtDCI, &c5_st);
    }

    c5_i28 = (int32_T)c5_count;
    if ((c5_i28 < 1) || (c5_i28 > c5_filteredX_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c5_i28, 1, c5_filteredX_size[0],
        &c5_f_emlrtBCI, &c5_st);
    }

    c5_i23 = c5_i28;
  }

  c5_iv[0] = 1;
  c5_iv[1] = (c5_i23 - c5_i21) + 1;
  c5_b_st.site = &c5_fe_emlrtRSI;
  c5_indexShapeCheck(chartInstance, &c5_b_st, c5_filteredX_size[0], c5_iv);
  c5_b_filteredX_size[0] = (c5_i23 - c5_i21) + 1;
  c5_e_loop_ub = c5_i23 - c5_i21;
  for (c5_i30 = 0; c5_i30 <= c5_e_loop_ub; c5_i30++) {
    chartInstance->c5_b_filteredX_data[c5_i30] =
      chartInstance->c5_filteredX_data[(c5_i21 + c5_i30) - 1];
  }

  c5_filteredX_size[0] = c5_b_filteredX_size[0];
  c5_f_loop_ub = c5_b_filteredX_size[0] - 1;
  for (c5_i32 = 0; c5_i32 <= c5_f_loop_ub; c5_i32++) {
    chartInstance->c5_filteredX_data[c5_i32] =
      chartInstance->c5_b_filteredX_data[c5_i32];
  }

  c5_b12 = (c5_count < 1.0);
  c5_b13 = c5_b12;
  c5_b14 = false;
  c5_b15 = (c5_b13 || c5_b14);
  if (c5_b15) {
    c5_i38 = 1;
    c5_i40 = 0;
  } else {
    c5_i37 = 1;
    if ((c5_i37 < 1) || (c5_i37 > c5_filteredY_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c5_i37, 1, c5_filteredY_size[0],
        &c5_g_emlrtBCI, &c5_st);
    }

    c5_i38 = c5_i37;
    if (c5_count != (real_T)(int32_T)muDoubleScalarFloor(c5_count)) {
      emlrtIntegerCheckR2012b(c5_count, &c5_d_emlrtDCI, &c5_st);
    }

    c5_i42 = (int32_T)c5_count;
    if ((c5_i42 < 1) || (c5_i42 > c5_filteredY_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c5_i42, 1, c5_filteredY_size[0],
        &c5_h_emlrtBCI, &c5_st);
    }

    c5_i40 = c5_i42;
  }

  c5_iv3[0] = 1;
  c5_iv3[1] = (c5_i40 - c5_i38) + 1;
  c5_b_st.site = &c5_ge_emlrtRSI;
  c5_indexShapeCheck(chartInstance, &c5_b_st, c5_filteredY_size[0], c5_iv3);
  c5_b_filteredY_size[0] = (c5_i40 - c5_i38) + 1;
  c5_g_loop_ub = c5_i40 - c5_i38;
  for (c5_i43 = 0; c5_i43 <= c5_g_loop_ub; c5_i43++) {
    chartInstance->c5_b_filteredY_data[c5_i43] =
      chartInstance->c5_filteredY_data[(c5_i38 + c5_i43) - 1];
  }

  c5_filteredY_size[0] = c5_b_filteredY_size[0];
  c5_i_loop_ub = c5_b_filteredY_size[0] - 1;
  for (c5_i45 = 0; c5_i45 <= c5_i_loop_ub; c5_i45++) {
    chartInstance->c5_filteredY_data[c5_i45] =
      chartInstance->c5_b_filteredY_data[c5_i45];
  }

  c5_j_loop_ub = c5_filteredX_size[0] - 1;
  for (c5_i47 = 0; c5_i47 <= c5_j_loop_ub; c5_i47++) {
    chartInstance->c5_filteredX_data[c5_i47] -= 80.0;
  }

  c5_k_loop_ub = c5_filteredY_size[0] - 1;
  for (c5_i48 = 0; c5_i48 <= c5_k_loop_ub; c5_i48++) {
    chartInstance->c5_filteredY_data[c5_i48] -= 60.0;
  }

  c5_d_filteredX_size[0] = c5_filteredX_size[0];
  c5_m_loop_ub = c5_filteredX_size[0] - 1;
  for (c5_i50 = 0; c5_i50 <= c5_m_loop_ub; c5_i50++) {
    chartInstance->c5_d_filteredX_data[c5_i50] =
      chartInstance->c5_filteredX_data[c5_i50] - 80.0;
  }

  c5_b_st.site = &c5_he_emlrtRSI;
  c5_power(chartInstance, &c5_b_st, chartInstance->c5_d_filteredX_data,
           c5_d_filteredX_size, chartInstance->c5_yIdx_data, c5_yIdx_size);
  c5_d_filteredY_size[0] = c5_filteredY_size[0];
  c5_n_loop_ub = c5_filteredY_size[0] - 1;
  for (c5_i51 = 0; c5_i51 <= c5_n_loop_ub; c5_i51++) {
    chartInstance->c5_d_filteredY_data[c5_i51] =
      chartInstance->c5_filteredY_data[c5_i51] - 60.0;
  }

  c5_b_st.site = &c5_he_emlrtRSI;
  c5_power(chartInstance, &c5_b_st, chartInstance->c5_d_filteredY_data,
           c5_d_filteredY_size, chartInstance->c5_tmp_data, c5_tmp_size);
  if ((c5_yIdx_size[0] != c5_tmp_size[0]) && ((c5_yIdx_size[0] != 1) &&
       (c5_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c5_yIdx_size[0], c5_tmp_size[0], &c5_b_emlrtECI,
      &c5_st);
  }

  if (c5_yIdx_size[0] == c5_tmp_size[0]) {
    c5_q_loop_ub = c5_yIdx_size[0] - 1;
    for (c5_i54 = 0; c5_i54 <= c5_q_loop_ub; c5_i54++) {
      chartInstance->c5_yIdx_data[c5_i54] += chartInstance->c5_tmp_data[c5_i54];
    }
  } else {
    c5_plus(chartInstance, chartInstance->c5_yIdx_data, c5_yIdx_size,
            chartInstance->c5_tmp_data, c5_tmp_size);
  }

  c5_b_st.site = &c5_he_emlrtRSI;
  c5_b_sqrt(chartInstance, &c5_b_st, chartInstance->c5_yIdx_data, c5_yIdx_size);
  c5_b_st.site = &c5_ie_emlrtRSI;
  c5_c_st.site = &c5_vc_emlrtRSI;
  c5_c_sort(chartInstance, &c5_c_st, chartInstance->c5_yIdx_data, c5_yIdx_size,
            chartInstance->c5_ii_data, c5_ii_size);
  c5_yIdx_size[0] = c5_ii_size[0];
  c5_r_loop_ub = c5_ii_size[0] - 1;
  for (c5_i56 = 0; c5_i56 <= c5_r_loop_ub; c5_i56++) {
    chartInstance->c5_yIdx_data[c5_i56] = (real_T)chartInstance->
      c5_ii_data[c5_i56];
  }

  c5_varargin_2 = (real_T)c5_yIdx_size[0];
  c5_b_y = c5_varargin_2;
  c5_c_y = c5_b_y;
  c5_d_y = c5_c_y;
  c5_d_b = c5_d_y;
  c5_e_y = c5_d_b;
  c5_f_y = c5_e_y;
  c5_d17 = muDoubleScalarMin(40.0, c5_f_y);
  c5_b16 = (c5_d17 < 1.0);
  c5_b17 = c5_b16;
  c5_b18 = false;
  c5_b19 = (c5_b17 || c5_b18);
  if (c5_b19) {
    c5_i61 = 1;
    c5_i62 = 0;
  } else {
    c5_i60 = 1;
    if ((c5_i60 < 1) || (c5_i60 > c5_yIdx_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c5_i60, 1, c5_yIdx_size[0], &c5_i_emlrtBCI,
        &c5_st);
    }

    c5_i61 = c5_i60;
    if (c5_d17 != (real_T)(int32_T)muDoubleScalarFloor(c5_d17)) {
      emlrtIntegerCheckR2012b(c5_d17, &c5_e_emlrtDCI, &c5_st);
    }

    c5_i63 = (int32_T)c5_d17;
    if ((c5_i63 < 1) || (c5_i63 > c5_yIdx_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c5_i63, 1, c5_yIdx_size[0], &c5_j_emlrtBCI,
        &c5_st);
    }

    c5_i62 = c5_i63;
  }

  c5_iv4[0] = 1;
  c5_iv4[1] = (c5_i62 - c5_i61) + 1;
  c5_b_st.site = &c5_je_emlrtRSI;
  c5_indexShapeCheck(chartInstance, &c5_b_st, c5_yIdx_size[0], c5_iv4);
  c5_closestIndices_size[0] = (c5_i62 - c5_i61) + 1;
  c5_s_loop_ub = c5_i62 - c5_i61;
  for (c5_i64 = 0; c5_i64 <= c5_s_loop_ub; c5_i64++) {
    c5_closestIndices_data[c5_i64] = chartInstance->c5_yIdx_data[(c5_i61 +
      c5_i64) - 1];
  }

  for (c5_i65 = 0; c5_i65 < 40; c5_i65++) {
    c5_b_pointsx[c5_i65] = 999.0;
  }

  for (c5_i66 = 0; c5_i66 < 40; c5_i66++) {
    c5_b_pointsy[c5_i66] = 999.0;
  }

  c5_d18 = (real_T)c5_closestIndices_size[0];
  c5_b20 = (c5_d18 < 1.0);
  c5_b21 = c5_b20;
  c5_b22 = false;
  c5_b23 = (c5_b21 || c5_b22);
  if (c5_b23) {
    c5_i67 = 0;
    c5_i68 = 0;
  } else {
    c5_i67 = 0;
    if (c5_d18 != (real_T)(int32_T)muDoubleScalarFloor(c5_d18)) {
      emlrtIntegerCheckR2012b(c5_d18, &c5_f_emlrtDCI, &c5_st);
    }

    c5_i69 = (int32_T)c5_d18;
    if ((c5_i69 < 1) || (c5_i69 > 40)) {
      emlrtDynamicBoundsCheckR2012b(c5_i69, 1, 40, &c5_k_emlrtBCI, &c5_st);
    }

    c5_i68 = c5_i69;
  }

  c5_filteredX = c5_filteredX_size[0];
  c5_unsorted_validY_size[0] = c5_closestIndices_size[0];
  c5_t_loop_ub = c5_closestIndices_size[0] - 1;
  for (c5_i70 = 0; c5_i70 <= c5_t_loop_ub; c5_i70++) {
    if (c5_closestIndices_data[c5_i70] != (real_T)(int32_T)muDoubleScalarFloor
        (c5_closestIndices_data[c5_i70])) {
      emlrtIntegerCheckR2012b(c5_closestIndices_data[c5_i70], &c5_cb_emlrtDCI,
        &c5_st);
    }

    c5_i72 = (int32_T)c5_closestIndices_data[c5_i70];
    if ((c5_i72 < 1) || (c5_i72 > c5_filteredX)) {
      emlrtDynamicBoundsCheckR2012b(c5_i72, 1, c5_filteredX, &c5_db_emlrtBCI,
        &c5_st);
    }

    c5_unsorted_validY_data[c5_i70] = chartInstance->c5_filteredX_data[c5_i72 -
      1];
  }

  c5_i71 = c5_i68 - c5_i67;
  if (c5_i71 != c5_unsorted_validY_size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(c5_i71, c5_unsorted_validY_size[0],
      &c5_c_emlrtECI, &c5_st);
  }

  c5_i73 = c5_i67 + 1;
  c5_b_tmp_size[1] = (c5_i68 - c5_i73) + 1;
  c5_u_loop_ub = c5_i68 - c5_i73;
  for (c5_i74 = 0; c5_i74 <= c5_u_loop_ub; c5_i74++) {
    c5_b_tmp_data[c5_i74] = (c5_i73 + c5_i74) - 1;
  }

  c5_v_loop_ub = c5_b_tmp_size[1] - 1;
  for (c5_i75 = 0; c5_i75 <= c5_v_loop_ub; c5_i75++) {
    c5_b_pointsx[c5_b_tmp_data[c5_i75]] = c5_unsorted_validY_data[c5_i75];
  }

  c5_d19 = (real_T)c5_closestIndices_size[0];
  c5_b24 = (c5_d19 < 1.0);
  c5_b25 = c5_b24;
  c5_b26 = false;
  c5_b27 = (c5_b25 || c5_b26);
  if (c5_b27) {
    c5_i76 = 0;
    c5_i77 = 0;
  } else {
    c5_i76 = 0;
    if (c5_d19 != (real_T)(int32_T)muDoubleScalarFloor(c5_d19)) {
      emlrtIntegerCheckR2012b(c5_d19, &c5_g_emlrtDCI, &c5_st);
    }

    c5_i78 = (int32_T)c5_d19;
    if ((c5_i78 < 1) || (c5_i78 > 40)) {
      emlrtDynamicBoundsCheckR2012b(c5_i78, 1, 40, &c5_l_emlrtBCI, &c5_st);
    }

    c5_i77 = c5_i78;
  }

  c5_filteredY = c5_filteredY_size[0];
  c5_unsorted_validY_size[0] = c5_closestIndices_size[0];
  c5_w_loop_ub = c5_closestIndices_size[0] - 1;
  for (c5_i79 = 0; c5_i79 <= c5_w_loop_ub; c5_i79++) {
    if (c5_closestIndices_data[c5_i79] != (real_T)(int32_T)muDoubleScalarFloor
        (c5_closestIndices_data[c5_i79])) {
      emlrtIntegerCheckR2012b(c5_closestIndices_data[c5_i79], &c5_db_emlrtDCI,
        &c5_st);
    }

    c5_i81 = (int32_T)c5_closestIndices_data[c5_i79];
    if ((c5_i81 < 1) || (c5_i81 > c5_filteredY)) {
      emlrtDynamicBoundsCheckR2012b(c5_i81, 1, c5_filteredY, &c5_eb_emlrtBCI,
        &c5_st);
    }

    c5_unsorted_validY_data[c5_i79] = chartInstance->c5_filteredY_data[c5_i81 -
      1];
  }

  c5_i80 = c5_i77 - c5_i76;
  if (c5_i80 != c5_unsorted_validY_size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(c5_i80, c5_unsorted_validY_size[0],
      &c5_d_emlrtECI, &c5_st);
  }

  c5_i82 = c5_i76 + 1;
  c5_b_tmp_size[1] = (c5_i77 - c5_i82) + 1;
  c5_x_loop_ub = c5_i77 - c5_i82;
  for (c5_i83 = 0; c5_i83 <= c5_x_loop_ub; c5_i83++) {
    c5_b_tmp_data[c5_i83] = (c5_i82 + c5_i83) - 1;
  }

  c5_y_loop_ub = c5_b_tmp_size[1] - 1;
  for (c5_i84 = 0; c5_i84 <= c5_y_loop_ub; c5_i84++) {
    c5_b_pointsy[c5_b_tmp_data[c5_i84]] = c5_unsorted_validY_data[c5_i84];
  }

  for (c5_i85 = 0; c5_i85 < 40; c5_i85++) {
    c5_bv2[c5_i85] = (c5_b_pointsy[c5_i85] != 999.0);
  }

  c5_end = 40;
  c5_trueCount = 0;
  for (c5_d_i = 0; c5_d_i < c5_end; c5_d_i++) {
    if ((c5_b_pointsx[c5_d_i] != 999.0) && c5_bv2[c5_d_i]) {
      c5_trueCount++;
    }
  }

  c5_closestIndices_size[0] = c5_trueCount;
  c5_partialTrueCount = 0;
  for (c5_e_i = 0; c5_e_i < c5_end; c5_e_i++) {
    if ((c5_b_pointsx[c5_e_i] != 999.0) && c5_bv2[c5_e_i]) {
      c5_d20 = (real_T)c5_e_i;
      if (c5_d20 != (real_T)(int32_T)muDoubleScalarFloor(c5_d20)) {
        emlrtIntegerCheckR2012b(c5_d20, &c5_eb_emlrtDCI, &c5_st);
      }

      c5_i86 = (int32_T)muDoubleScalarFloor(c5_d20);
      if ((c5_i86 < 0) || (c5_i86 > 39)) {
        emlrtDynamicBoundsCheckR2012b(c5_i86, 0, 39, &c5_fb_emlrtBCI, &c5_st);
      }

      c5_closestIndices_data[c5_partialTrueCount] = c5_b_pointsx[c5_i86];
      c5_partialTrueCount++;
    }
  }

  c5_b_end = 40;
  c5_b_trueCount = 0;
  for (c5_f_i = 0; c5_f_i < c5_b_end; c5_f_i++) {
    if ((c5_b_pointsx[c5_f_i] != 999.0) && c5_bv2[c5_f_i]) {
      c5_b_trueCount++;
    }
  }

  c5_unsorted_validY_size[0] = c5_b_trueCount;
  for (c5_g_i = 0; c5_g_i < c5_b_end; c5_g_i++) {
    if ((c5_b_pointsx[c5_g_i] != 999.0) && c5_bv2[c5_g_i]) {
      c5_d21 = (real_T)c5_g_i;
      if (c5_d21 != (real_T)(int32_T)muDoubleScalarFloor(c5_d21)) {
        emlrtIntegerCheckR2012b(c5_d21, &c5_fb_emlrtDCI, &c5_st);
      }

      c5_i87 = (int32_T)muDoubleScalarFloor(c5_d21);
      if ((c5_i87 < 0) || (c5_i87 > 39)) {
        emlrtDynamicBoundsCheckR2012b(c5_i87, 0, 39, &c5_gb_emlrtBCI, &c5_st);
      }
    }
  }

  c5_guard1 = false;
  if (covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 0,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c5_covrtInstance, 4U, 0U, 1U, (real_T)
                        c5_closestIndices_size[0], 3.0, -1, 5U, (real_T)
                        c5_closestIndices_size[0] >= 3.0))) {
    c5_isfinite(chartInstance, c5_closestIndices_data, c5_closestIndices_size,
                c5_c_tmp_data, c5_c_tmp_size);
    c5_b_st.site = &c5_ke_emlrtRSI;
    if (covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 1, c5_all
                         (chartInstance, &c5_b_st, c5_c_tmp_data, c5_c_tmp_size)))
    {
      covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 0, true);
      covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 3, true);
      c5_b_st.site = &c5_le_emlrtRSI;
      c5_c_st.site = &c5_vc_emlrtRSI;
      c5_d_sort(chartInstance, &c5_c_st, c5_closestIndices_data,
                c5_closestIndices_size, c5_c_iidx_data, c5_iidx_size);
      c5_closestIndices_size[0] = c5_iidx_size[0];
      c5_ab_loop_ub = c5_iidx_size[0] - 1;
      for (c5_i89 = 0; c5_i89 <= c5_ab_loop_ub; c5_i89++) {
        c5_closestIndices_data[c5_i89] = (real_T)c5_c_iidx_data[c5_i89];
      }

      c5_unsorted_validY = c5_unsorted_validY_size[0];
      c5_bb_loop_ub = c5_closestIndices_size[0] - 1;
      for (c5_i90 = 0; c5_i90 <= c5_bb_loop_ub; c5_i90++) {
        if (c5_closestIndices_data[c5_i90] != (real_T)(int32_T)
            muDoubleScalarFloor(c5_closestIndices_data[c5_i90])) {
          emlrtIntegerCheckR2012b(c5_closestIndices_data[c5_i90],
            &c5_gb_emlrtDCI, &c5_st);
        }

        c5_i91 = (int32_T)c5_closestIndices_data[c5_i90];
        if ((c5_i91 < 1) || (c5_i91 > c5_unsorted_validY)) {
          emlrtDynamicBoundsCheckR2012b(c5_i91, 1, c5_unsorted_validY,
            &c5_hb_emlrtBCI, &c5_st);
        }
      }
    } else {
      c5_guard1 = true;
    }
  } else {
    c5_guard1 = true;
  }

  if (c5_guard1) {
    covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 0, false);
    covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 3, false);
  }

  c5_d22 = (real_T)c5_filteredX_size[0];
  c5_i88 = (int32_T)c5_d22;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c5_d22, mxDOUBLE_CLASS, c5_i88,
    &c5_bc_emlrtRTEI, &c5_st);
  for (c5_k = 0; c5_k < c5_i88; c5_k++) {
    c5_b_k = 1.0 + (real_T)c5_k;
    covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 1, 1);
    for (c5_b_dx = 0; c5_b_dx < 9; c5_b_dx++) {
      c5_c_dx = -4.0 + (real_T)c5_b_dx;
      covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 2, 1);
      for (c5_b_dy = 0; c5_b_dy < 9; c5_b_dy++) {
        c5_c_dy = -4.0 + (real_T)c5_b_dy;
        covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 3, 1);
        c5_b_st.site = &c5_me_emlrtRSI;
        c5_f_a = c5_c_dx;
        c5_h_a = c5_f_a;
        c5_j_a = c5_h_a;
        c5_l_a = c5_j_a;
        c5_m_a = c5_l_a;
        c5_b_c = c5_m_a * c5_m_a;
        c5_b_st.site = &c5_me_emlrtRSI;
        c5_p_a = c5_c_dy;
        c5_r_a = c5_p_a;
        c5_t_a = c5_r_a;
        c5_v_a = c5_t_a;
        c5_w_a = c5_v_a;
        c5_d_c = c5_w_a * c5_w_a;
        c5_d24 = c5_b_c + c5_d_c;
        c5_b_st.site = &c5_me_emlrtRSI;
        if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 4,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c5_covrtInstance, 4U, 0U, 2U, c5_d24,
                            16.0, -1, 3U, c5_d24 <= 16.0))) {
          if (c5_b_k != (real_T)(int32_T)muDoubleScalarFloor(c5_b_k)) {
            emlrtIntegerCheckR2012b(c5_b_k, &c5_hb_emlrtDCI, &c5_st);
          }

          c5_i97 = (int32_T)c5_b_k;
          if ((c5_i97 < 1) || (c5_i97 > c5_filteredX_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c5_i97, 1, c5_filteredX_size[0],
              &c5_ib_emlrtBCI, &c5_st);
          }

          c5_x = (chartInstance->c5_filteredX_data[c5_i97 - 1] + c5_c_dx) + 80.0;
          if (c5_b_k != (real_T)(int32_T)muDoubleScalarFloor(c5_b_k)) {
            emlrtIntegerCheckR2012b(c5_b_k, &c5_ib_emlrtDCI, &c5_st);
          }

          c5_i99 = (int32_T)c5_b_k;
          if ((c5_i99 < 1) || (c5_i99 > c5_filteredY_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c5_i99, 1, c5_filteredY_size[0],
              &c5_jb_emlrtBCI, &c5_st);
          }

          c5_g_y = (chartInstance->c5_filteredY_data[c5_i99 - 1] + c5_c_dy) +
            60.0;
          if (covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 2,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c5_covrtInstance, 4U, 0U, 3U,
                                c5_x, 0.0, -1, 4U, c5_x > 0.0)) &&
              covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 3,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c5_covrtInstance, 4U, 0U, 4U,
                                c5_x, 160.0, -1, 3U, c5_x <= 160.0)) &&
              covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 4,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c5_covrtInstance, 4U, 0U, 5U,
                                c5_g_y, 0.0, -1, 4U, c5_g_y > 0.0)) &&
              covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 5,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c5_covrtInstance, 4U, 0U, 6U,
                                c5_g_y, 120.0, -1, 3U, c5_g_y <= 120.0))) {
            covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 1, true);
            covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 5, true);
            if (c5_g_y != (real_T)(int32_T)muDoubleScalarFloor(c5_g_y)) {
              emlrtIntegerCheckR2012b(c5_g_y, &c5_h_emlrtDCI, &c5_st);
            }

            c5_i100 = (int32_T)c5_g_y;
            if ((c5_i100 < 1) || (c5_i100 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c5_i100, 1, 120, &c5_m_emlrtBCI,
                &c5_st);
            }

            if (c5_x != (real_T)(int32_T)muDoubleScalarFloor(c5_x)) {
              emlrtIntegerCheckR2012b(c5_x, &c5_i_emlrtDCI, &c5_st);
            }

            c5_i101 = (int32_T)c5_x;
            if ((c5_i101 < 1) || (c5_i101 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c5_i101, 1, 160, &c5_n_emlrtBCI,
                &c5_st);
            }

            chartInstance->c5_outt[(c5_i100 + 120 * (c5_i101 - 1)) - 1] = 0U;
            c5_b_x = 255.0 * c5_b_k / (real_T)c5_filteredX_size[0];
            c5_c_x = c5_b_x;
            c5_h_y = c5_c_x;
            c5_h_y = muDoubleScalarFloor(c5_h_y);
            if (c5_g_y != (real_T)(int32_T)muDoubleScalarFloor(c5_g_y)) {
              emlrtIntegerCheckR2012b(c5_g_y, &c5_j_emlrtDCI, &c5_st);
            }

            c5_i102 = (int32_T)c5_g_y;
            if ((c5_i102 < 1) || (c5_i102 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c5_i102, 1, 120, &c5_o_emlrtBCI,
                &c5_st);
            }

            if (c5_x != (real_T)(int32_T)muDoubleScalarFloor(c5_x)) {
              emlrtIntegerCheckR2012b(c5_x, &c5_k_emlrtDCI, &c5_st);
            }

            c5_i103 = (int32_T)c5_x;
            if ((c5_i103 < 1) || (c5_i103 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c5_i103, 1, 160, &c5_p_emlrtBCI,
                &c5_st);
            }

            c5_d25 = muDoubleScalarRound(c5_h_y);
            c5_c_covSaturation = false;
            if (c5_d25 < 256.0) {
              if (c5_d25 >= 0.0) {
                c5_u2 = (uint8_T)c5_d25;
              } else {
                c5_c_covSaturation = true;
                c5_u2 = 0U;
                sf_data_saturate_error(chartInstance->S, 1U, 3920, 46);
              }
            } else if (c5_d25 >= 256.0) {
              c5_c_covSaturation = true;
              c5_u2 = MAX_uint8_T;
              sf_data_saturate_error(chartInstance->S, 1U, 3920, 46);
            } else {
              c5_u2 = 0U;
            }

            covrtSaturationUpdateFcn(chartInstance->c5_covrtInstance, 4, 0, 0, 0,
              c5_c_covSaturation);
            chartInstance->c5_outt[(c5_i102 + 120 * (c5_i103 - 1)) + 19199] =
              c5_u2;
            if (c5_g_y != (real_T)(int32_T)muDoubleScalarFloor(c5_g_y)) {
              emlrtIntegerCheckR2012b(c5_g_y, &c5_l_emlrtDCI, &c5_st);
            }

            c5_i104 = (int32_T)c5_g_y;
            if ((c5_i104 < 1) || (c5_i104 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c5_i104, 1, 120, &c5_q_emlrtBCI,
                &c5_st);
            }

            if (c5_x != (real_T)(int32_T)muDoubleScalarFloor(c5_x)) {
              emlrtIntegerCheckR2012b(c5_x, &c5_m_emlrtDCI, &c5_st);
            }

            c5_i105 = (int32_T)c5_x;
            if ((c5_i105 < 1) || (c5_i105 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c5_i105, 1, 160, &c5_r_emlrtBCI,
                &c5_st);
            }

            chartInstance->c5_outt[(c5_i104 + 120 * (c5_i105 - 1)) + 38399] = 0U;
          } else {
            covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 1, false);
            covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 5, false);
          }
        }

        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 3, 0);
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 2, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 1, 0);
  for (c5_dx = 0; c5_dx < 9; c5_dx++) {
    c5_c_dx = -4.0 + (real_T)c5_dx;
    covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 4, 1);
    for (c5_dy = 0; c5_dy < 9; c5_dy++) {
      c5_c_dy = -4.0 + (real_T)c5_dy;
      covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 5, 1);
      c5_b_st.site = &c5_ne_emlrtRSI;
      c5_d_a = c5_c_dx;
      c5_e_a = c5_d_a;
      c5_g_a = c5_e_a;
      c5_i_a = c5_g_a;
      c5_k_a = c5_i_a;
      c5_c = c5_k_a * c5_k_a;
      c5_b_st.site = &c5_ne_emlrtRSI;
      c5_n_a = c5_c_dy;
      c5_o_a = c5_n_a;
      c5_q_a = c5_o_a;
      c5_s_a = c5_q_a;
      c5_u_a = c5_s_a;
      c5_c_c = c5_u_a * c5_u_a;
      c5_d23 = c5_c + c5_c_c;
      c5_b_st.site = &c5_ne_emlrtRSI;
      if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 6,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c5_covrtInstance, 4U, 0U, 7U, c5_d23,
                          16.0, -1, 3U, c5_d23 <= 16.0))) {
        covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 6,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c5_covrtInstance, 4U, 0U, 8U, 80.0, 0.0,
                          -1, 4U, 1));
        covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 7,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c5_covrtInstance, 4U, 0U, 9U, 80.0,
                          160.0, -1, 3U, 1));
        covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 8,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c5_covrtInstance, 4U, 0U, 10U, 60.0,
                          0.0, -1, 4U, 1));
        covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 9,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c5_covrtInstance, 4U, 0U, 11U, 60.0,
                          120.0, -1, 3U, 1));
        covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 2, true);
        covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 7, true);
        chartInstance->c5_outt[9539] = MAX_uint8_T;
        chartInstance->c5_outt[28739] = 0U;
        chartInstance->c5_outt[47939] = 0U;
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 5, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 4, 0);
  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 8,
                     covrtRelationalopUpdateFcn(chartInstance->c5_covrtInstance,
        4U, 0U, 12U, chartInstance->c5_call_count, 55.0, -1, 2U,
        chartInstance->c5_call_count < 55.0))) {
    c5_b_distX = 0.0;
    c5_b_distY = 20.0;
    c5_b_dom_x = 0.0;
    c5_b_dom_y = 1.0;
  } else if (covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 10,
              covrtRelationalopUpdateFcn(chartInstance->c5_covrtInstance, 4U, 0U,
    13U, chartInstance->c5_call_count, 60.0, -1, 5U,
               chartInstance->c5_call_count >= 60.0)) && covrtEmlCondEval
             (chartInstance->c5_covrtInstance, 4U, 0, 11,
              covrtRelationalopUpdateFcn(chartInstance->c5_covrtInstance, 4U, 0U,
    14U, chartInstance->c5_call_count, 100.0, -1, 2U,
               chartInstance->c5_call_count < 100.0))) {
    covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 3, true);
    covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 9, true);
    c5_b_distX = 20.0;
    c5_b_distY = 0.0;
    c5_b_dom_x = -1.0;
    c5_b_dom_y = 0.0;
  } else {
    covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 3, false);
    covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 9, false);
    c5_b_dom_x = 0.0;
    c5_b_dom_y = 0.0;
    c5_b_distX = 0.0;
    c5_b_distY = 0.0;
  }

  chartInstance->c5_call_count++;
  for (c5_i92 = 0; c5_i92 < 57600; c5_i92++) {
    (*chartInstance->c5_b_outt)[c5_i92] = chartInstance->c5_outt[c5_i92];
  }

  *chartInstance->c5_distX = c5_b_distX;
  *chartInstance->c5_distY = c5_b_distY;
  *chartInstance->c5_dom_x = c5_b_dom_x;
  *chartInstance->c5_dom_y = c5_b_dom_y;
  for (c5_i93 = 0; c5_i93 < 40; c5_i93++) {
    (*chartInstance->c5_pointsx)[c5_i93] = c5_b_pointsx[c5_i93];
  }

  for (c5_i94 = 0; c5_i94 < 40; c5_i94++) {
    (*chartInstance->c5_pointsy)[c5_i94] = c5_b_pointsy[c5_i94];
  }

  c5_do_animation_call_c5_flightControlSystem(chartInstance);
  for (c5_i95 = 0; c5_i95 < 57600; c5_i95++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 1U, (real_T)
                      (*chartInstance->c5_b_outt)[c5_i95]);
  }

  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 2U,
                    *chartInstance->c5_distX);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 3U,
                    *chartInstance->c5_distY);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 4U,
                    *chartInstance->c5_dom_x);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 5U,
                    *chartInstance->c5_dom_y);
  for (c5_i96 = 0; c5_i96 < 40; c5_i96++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 6U,
                      (*chartInstance->c5_pointsx)[c5_i96]);
  }

  for (c5_i98 = 0; c5_i98 < 40; c5_i98++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 7U,
                      (*chartInstance->c5_pointsy)[c5_i98]);
  }
}

static void ext_mode_exec_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_update_jit_animation_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_do_animation_call_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_st;
  c5_st = NULL;
  c5_st = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createcellmatrix(9, 1), false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", chartInstance->c5_distX, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c5_b_y, 0, c5_c_y);
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", chartInstance->c5_distY, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c5_b_y, 1, c5_d_y);
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", chartInstance->c5_dom_x, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c5_b_y, 2, c5_e_y);
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", chartInstance->c5_dom_y, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c5_b_y, 3, c5_f_y);
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", *chartInstance->c5_b_outt, 3, 0U, 1U,
    0U, 3, 120, 160, 3), false);
  sf_mex_setcell(c5_b_y, 4, c5_g_y);
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", *chartInstance->c5_pointsx, 0, 0U,
    1U, 0U, 2, 40, 1), false);
  sf_mex_setcell(c5_b_y, 5, c5_h_y);
  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", *chartInstance->c5_pointsy, 0, 0U,
    1U, 0U, 2, 40, 1), false);
  sf_mex_setcell(c5_b_y, 6, c5_i_y);
  c5_j_y = NULL;
  if (!chartInstance->c5_call_count_not_empty) {
    sf_mex_assign(&c5_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_j_y, sf_mex_create("y", &chartInstance->c5_call_count, 0,
      0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c5_b_y, 7, c5_j_y);
  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y",
    &chartInstance->c5_is_active_c5_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c5_b_y, 8, c5_k_y);
  sf_mex_assign(&c5_st, c5_b_y, false);
  return c5_st;
}

static void set_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_c_u;
  real_T c5_b_dv[40];
  real_T c5_dv1[40];
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  uint8_T c5_uv[57600];
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_c_u = sf_mex_dup(c5_st);
  *chartInstance->c5_distX = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_c_u, 0)), "distX");
  *chartInstance->c5_distY = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_c_u, 1)), "distY");
  *chartInstance->c5_dom_x = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_c_u, 2)), "dom_x");
  *chartInstance->c5_dom_y = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_c_u, 3)), "dom_y");
  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_c_u, 4)),
                        "outt", c5_uv);
  for (c5_i = 0; c5_i < 57600; c5_i++) {
    (*chartInstance->c5_b_outt)[c5_i] = c5_uv[c5_i];
  }

  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_c_u, 5)),
                        "pointsx", c5_b_dv);
  for (c5_i1 = 0; c5_i1 < 40; c5_i1++) {
    (*chartInstance->c5_pointsx)[c5_i1] = c5_b_dv[c5_i1];
  }

  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_c_u, 6)),
                        "pointsy", c5_dv1);
  for (c5_i2 = 0; c5_i2 < 40; c5_i2++) {
    (*chartInstance->c5_pointsy)[c5_i2] = c5_dv1[c5_i2];
  }

  chartInstance->c5_call_count = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_c_u, 7)), "call_count",
    &chartInstance->c5_call_count_not_empty);
  chartInstance->c5_is_active_c5_flightControlSystem = c5_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_c_u, 8)),
     "is_active_c5_flightControlSystem");
  sf_mex_destroy(&c5_c_u);
  sf_mex_destroy(&c5_st);
}

static void initSimStructsc5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSubchartIOPointersc5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_bwmorph(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_bwin[19200], boolean_T c5_bw[19200])
{
  static boolean_T c5_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true };

  real_T c5_sizeIn[2];
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  boolean_T c5_in[19200];
  (void)chartInstance;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    c5_bw[c5_i] = c5_bwin[c5_i];
  }

  for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
    c5_in[c5_i1] = c5_bw[c5_i1];
  }

  for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
    c5_sizeIn[c5_i2] = 120.0 + 40.0 * (real_T)c5_i2;
  }

  bwlookup_tbb_boolean(&c5_in[0], &c5_sizeIn[0], 2.0, &c5_lut[0], 512.0, &c5_bw
                       [0]);
}

static void c5_imgaussfilt(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, uint8_T c5_A[19200], uint8_T c5_B[19200])
{
  static int32_T c5_idxA[352] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8,
    9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
    28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
    47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65,
    66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84,
    85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102,
    103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117,
    118, 119, 120, 120, 120, 120, 120, 120, 120, 120, 120, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
    49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
    68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86,
    87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134,
    135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
    150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 160, 160, 160, 160,
    160, 160, 160, 160 };

  static char_T c5_b_cv[4] = { 's', 'q', 'r', 't' };

  static char_T c5_cv1[4] = { 's', 'q', 'r', 't' };

  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_i_y = NULL;
  real_T c5_a__1[289];
  real_T c5_a__2[289];
  real_T c5_s[289];
  real_T c5_b_s[17];
  real_T c5_hcol[17];
  real_T c5_hrow[17];
  real_T c5_nonzero_h_data[17];
  real_T c5_connDimsT[2];
  real_T c5_outSizeT[2];
  real_T c5_padSizeT[2];
  real_T c5_startT[2];
  real_T c5_b_numKernElem;
  real_T c5_b_x;
  real_T c5_c_j;
  real_T c5_c_x;
  real_T c5_d;
  real_T c5_d_j;
  real_T c5_d_x;
  real_T c5_e_i;
  real_T c5_e_x;
  real_T c5_ex;
  real_T c5_f_b;
  real_T c5_f_i;
  real_T c5_f_x;
  real_T c5_f_y;
  real_T c5_g_b;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_h_y;
  real_T c5_maxval;
  real_T c5_numKernElem;
  real_T c5_rank;
  real_T c5_tol;
  real_T c5_x;
  int32_T c5_nonzero_h_size[1];
  int32_T c5_b_end;
  int32_T c5_b_i;
  int32_T c5_b_j;
  int32_T c5_b_k;
  int32_T c5_b_partialTrueCount;
  int32_T c5_b_trueCount;
  int32_T c5_c_i;
  int32_T c5_c_k;
  int32_T c5_d_i;
  int32_T c5_d_k;
  int32_T c5_e_b;
  int32_T c5_e_k;
  int32_T c5_end;
  int32_T c5_f_k;
  int32_T c5_first;
  int32_T c5_g_i;
  int32_T c5_g_k;
  int32_T c5_h_i;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_i;
  int32_T c5_idx;
  int32_T c5_ix;
  int32_T c5_j;
  int32_T c5_j_i;
  int32_T c5_k;
  int32_T c5_k_i;
  int32_T c5_l_i;
  int32_T c5_nz;
  int32_T c5_partialTrueCount;
  int32_T c5_trueCount;
  int32_T c5_xoffset;
  uint8_T c5_c_u;
  boolean_T c5_b_conn[289];
  boolean_T c5_conn[17];
  boolean_T c5_b_densityFlag;
  boolean_T c5_b_modeFlag;
  boolean_T c5_b_p;
  boolean_T c5_b_tooBig;
  boolean_T c5_c_b;
  boolean_T c5_c_modeFlag;
  boolean_T c5_c_p;
  boolean_T c5_c_tooBig;
  boolean_T c5_d_b;
  boolean_T c5_d_modeFlag;
  boolean_T c5_d_p;
  boolean_T c5_densityFlag;
  boolean_T c5_e_modeFlag;
  boolean_T c5_e_p;
  boolean_T c5_exitg1;
  boolean_T c5_f_modeFlag;
  boolean_T c5_f_p;
  boolean_T c5_g_modeFlag;
  boolean_T c5_h_modeFlag;
  boolean_T c5_i_modeFlag;
  boolean_T c5_modeFlag;
  boolean_T c5_p;
  boolean_T c5_separable;
  boolean_T c5_tooBig;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_st.site = &c5_e_emlrtRSI;
  c5_b_st.site = &c5_f_emlrtRSI;
  c5_b_st.site = &c5_g_emlrtRSI;
  c5_c_st.site = &c5_h_emlrtRSI;
  c5_d_st.site = &c5_q_emlrtRSI;
  c5_svd(chartInstance, &c5_d_st, c5_a__1, c5_s, c5_a__2);
  c5_k = 0;
  for (c5_b_k = 0; c5_b_k < 17; c5_b_k++) {
    c5_b_s[c5_b_k] = c5_s[c5_k];
    c5_k += 18;
  }

  c5_x = c5_b_s[0];
  c5_b_x = c5_x;
  c5_c_b = muDoubleScalarIsNaN(c5_b_x);
  c5_p = !c5_c_b;
  if (c5_p) {
    c5_idx = 1;
  } else {
    c5_idx = 0;
    c5_c_k = 2;
    c5_exitg1 = false;
    while ((!c5_exitg1) && (c5_c_k < 18)) {
      c5_c_x = c5_b_s[c5_c_k - 1];
      c5_d_x = c5_c_x;
      c5_d_b = muDoubleScalarIsNaN(c5_d_x);
      c5_b_p = !c5_d_b;
      if (c5_b_p) {
        c5_idx = c5_c_k;
        c5_exitg1 = true;
      } else {
        c5_c_k++;
      }
    }
  }

  if (c5_idx == 0) {
    c5_maxval = c5_b_s[0];
  } else {
    c5_first = c5_idx - 1;
    c5_ex = c5_b_s[c5_first];
    c5_i = c5_first;
    for (c5_d_k = c5_i + 2; c5_d_k < 18; c5_d_k++) {
      if (c5_ex < c5_b_s[c5_d_k - 1]) {
        c5_ex = c5_b_s[c5_d_k - 1];
      }
    }

    c5_maxval = c5_ex;
  }

  c5_tol = 17.0 * c5_maxval * 2.2204460492503131E-16;
  for (c5_i1 = 0; c5_i1 < 17; c5_i1++) {
    c5_conn[c5_i1] = (c5_b_s[c5_i1] > c5_tol);
  }

  c5_nz = (int32_T)c5_conn[0];
  for (c5_e_k = 0; c5_e_k < 16; c5_e_k++) {
    c5_xoffset = c5_e_k;
    c5_ix = c5_xoffset;
    c5_e_b = (int32_T)c5_conn[c5_ix + 1];
    c5_nz += (c5_e_b != 0);
  }

  c5_rank = (real_T)c5_nz;
  if (c5_rank == 1.0) {
    c5_separable = true;
  } else {
    c5_separable = false;
  }

  if (c5_separable) {
    c5_c_st.site = &c5_i_emlrtRSI;
    c5_d_st.site = &c5_tb_emlrtRSI;
    for (c5_b_j = 0; c5_b_j < 176; c5_b_j++) {
      c5_d_j = (real_T)c5_b_j + 1.0;
      for (c5_c_i = 0; c5_c_i < 136; c5_c_i++) {
        c5_f_i = (real_T)c5_c_i + 1.0;
        if ((c5_idxA[(int32_T)c5_f_i - 1] < 1) || (c5_idxA[(int32_T)c5_f_i - 1] >
             120)) {
          emlrtDynamicBoundsCheckR2012b(c5_idxA[(int32_T)c5_f_i - 1], 1, 120,
            &c5_kb_emlrtBCI, &c5_d_st);
        }

        c5_i4 = c5_idxA[(int32_T)c5_d_j + 175];
        if ((c5_i4 < 1) || (c5_i4 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i4, 1, 160, &c5_lb_emlrtBCI, &c5_d_st);
        }

        chartInstance->c5_c_a[((int32_T)c5_f_i + 136 * ((int32_T)c5_d_j - 1)) -
          1] = c5_A[(c5_idxA[(int32_T)c5_f_i - 1] + 120 * (c5_i4 - 1)) - 1];
      }
    }

    c5_c_st.site = &c5_j_emlrtRSI;
    c5_svd(chartInstance, &c5_c_st, c5_a__1, c5_s, c5_a__2);
    c5_f_k = 0;
    for (c5_g_k = 0; c5_g_k < 17; c5_g_k++) {
      c5_b_s[c5_g_k] = c5_s[c5_f_k];
      c5_f_k += 18;
    }

    for (c5_i2 = 0; c5_i2 < 17; c5_i2++) {
      c5_hcol[c5_i2] = c5_a__1[c5_i2];
    }

    c5_c_st.site = &c5_k_emlrtRSI;
    c5_e_x = c5_b_s[0];
    c5_f_b = c5_e_x;
    c5_f_x = c5_f_b;
    if (c5_f_x < 0.0) {
      c5_c_p = true;
    } else {
      c5_c_p = false;
    }

    c5_d_p = c5_c_p;
    if (c5_d_p) {
      c5_b_y = NULL;
      sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c5_c_y = NULL;
      sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c5_d_y = NULL;
      sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1, 4),
                    false);
      sf_mex_call(&c5_c_st, &c5_f_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                  sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_c_st, NULL, "message", 1U, 2U, 14, c5_c_y, 14, c5_d_y)));
    }

    c5_f_b = muDoubleScalarSqrt(c5_f_b);
    for (c5_i12 = 0; c5_i12 < 17; c5_i12++) {
      c5_hcol[c5_i12] *= c5_f_b;
    }

    for (c5_i14 = 0; c5_i14 < 17; c5_i14++) {
      c5_hrow[c5_i14] = c5_a__2[c5_i14];
    }

    c5_c_st.site = &c5_l_emlrtRSI;
    c5_g_x = c5_b_s[0];
    c5_g_b = c5_g_x;
    c5_h_x = c5_g_b;
    if (c5_h_x < 0.0) {
      c5_e_p = true;
    } else {
      c5_e_p = false;
    }

    c5_f_p = c5_e_p;
    if (c5_f_p) {
      c5_e_y = NULL;
      sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c5_g_y = NULL;
      sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c5_i_y = NULL;
      sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv1, 10, 0U, 1U, 0U, 2, 1, 4),
                    false);
      sf_mex_call(&c5_c_st, &c5_f_emlrtMCI, "error", 0U, 2U, 14, c5_e_y, 14,
                  sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_c_st, NULL, "message", 1U, 2U, 14, c5_g_y, 14, c5_i_y)));
    }

    c5_g_b = muDoubleScalarSqrt(c5_g_b);
    c5_f_y = c5_g_b;
    c5_h_y = c5_f_y;
    for (c5_i15 = 0; c5_i15 < 17; c5_i15++) {
      c5_hrow[c5_i15] *= c5_h_y;
    }

    for (c5_i16 = 0; c5_i16 < 23936; c5_i16++) {
      chartInstance->c5_a[c5_i16] = (real_T)chartInstance->c5_c_a[c5_i16];
    }

    c5_c_st.site = &c5_m_emlrtRSI;
    for (c5_i17 = 0; c5_i17 < 17; c5_i17++) {
      c5_conn[c5_i17] = (c5_hrow[c5_i17] != 0.0);
    }

    for (c5_i18 = 0; c5_i18 < 17; c5_i18++) {
      c5_b_s[c5_i18] = c5_hrow[c5_i18];
    }

    c5_end = 17;
    c5_trueCount = 0;
    for (c5_g_i = 0; c5_g_i < c5_end; c5_g_i++) {
      if (c5_conn[c5_g_i]) {
        c5_trueCount++;
      }
    }

    c5_nonzero_h_size[0] = c5_trueCount;
    c5_partialTrueCount = 0;
    for (c5_h_i = 0; c5_h_i < c5_end; c5_h_i++) {
      if (c5_conn[c5_h_i]) {
        c5_nonzero_h_data[c5_partialTrueCount] = c5_b_s[c5_h_i];
        c5_partialTrueCount++;
      }
    }

    c5_densityFlag = false;
    if ((real_T)c5_nonzero_h_size[0] / 17.0 > 0.05) {
      c5_densityFlag = true;
    }

    c5_b_tooBig = true;
    for (c5_i_i = 0; c5_i_i < 2; c5_i_i++) {
      c5_b_tooBig = false;
    }

    if (c5_densityFlag && (!c5_b_tooBig)) {
      c5_d_modeFlag = true;
    } else {
      c5_d_modeFlag = false;
    }

    if (c5_d_modeFlag) {
      c5_e_modeFlag = true;
    } else {
      c5_e_modeFlag = false;
    }

    c5_f_modeFlag = c5_e_modeFlag;
    if (c5_f_modeFlag) {
      for (c5_i19 = 0; c5_i19 < 2; c5_i19++) {
        c5_padSizeT[c5_i19] = 136.0 + 40.0 * (real_T)c5_i19;
      }

      for (c5_i21 = 0; c5_i21 < 2; c5_i21++) {
        c5_outSizeT[c5_i21] = 136.0 + 24.0 * (real_T)c5_i21;
      }

      for (c5_i23 = 0; c5_i23 < 2; c5_i23++) {
        c5_connDimsT[c5_i23] = 1.0 + 16.0 * (real_T)c5_i23;
      }

      ippfilter_real64(&chartInstance->c5_a[0], &chartInstance->c5_b[0],
                       &c5_outSizeT[0], 2.0, &c5_padSizeT[0], &c5_hrow[0],
                       &c5_connDimsT[0], false);
    } else {
      c5_numKernElem = (real_T)c5_nonzero_h_size[0];
      for (c5_i20 = 0; c5_i20 < 2; c5_i20++) {
        c5_padSizeT[c5_i20] = 136.0 + 40.0 * (real_T)c5_i20;
      }

      for (c5_i22 = 0; c5_i22 < 2; c5_i22++) {
        c5_outSizeT[c5_i22] = 136.0 + 24.0 * (real_T)c5_i22;
      }

      for (c5_i24 = 0; c5_i24 < 2; c5_i24++) {
        c5_connDimsT[c5_i24] = 1.0 + 16.0 * (real_T)c5_i24;
      }

      for (c5_i25 = 0; c5_i25 < 2; c5_i25++) {
        c5_startT[c5_i25] = 8.0 * (real_T)c5_i25;
      }

      imfilter_real64(&chartInstance->c5_a[0], &chartInstance->c5_b[0], 2.0,
                      &c5_outSizeT[0], 2.0, &c5_padSizeT[0], &c5_nonzero_h_data
                      [0], c5_numKernElem, &c5_conn[0], 2.0, &c5_connDimsT[0],
                      &c5_startT[0], 2.0, true, false);
    }

    c5_c_st.site = &c5_n_emlrtRSI;
    for (c5_i26 = 0; c5_i26 < 17; c5_i26++) {
      c5_conn[c5_i26] = (c5_hcol[c5_i26] != 0.0);
    }

    c5_b_end = 17;
    c5_b_trueCount = 0;
    for (c5_j_i = 0; c5_j_i < c5_b_end; c5_j_i++) {
      if (c5_conn[c5_j_i]) {
        c5_b_trueCount++;
      }
    }

    c5_nonzero_h_size[0] = c5_b_trueCount;
    c5_b_partialTrueCount = 0;
    for (c5_k_i = 0; c5_k_i < c5_b_end; c5_k_i++) {
      if (c5_conn[c5_k_i]) {
        c5_nonzero_h_data[c5_b_partialTrueCount] = c5_hcol[c5_k_i];
        c5_b_partialTrueCount++;
      }
    }

    c5_b_densityFlag = false;
    if ((real_T)c5_nonzero_h_size[0] / 17.0 > 0.05) {
      c5_b_densityFlag = true;
    }

    c5_c_tooBig = true;
    for (c5_l_i = 0; c5_l_i < 2; c5_l_i++) {
      c5_c_tooBig = false;
    }

    if (c5_b_densityFlag && (!c5_c_tooBig)) {
      c5_g_modeFlag = true;
    } else {
      c5_g_modeFlag = false;
    }

    if (c5_g_modeFlag) {
      c5_h_modeFlag = true;
    } else {
      c5_h_modeFlag = false;
    }

    c5_i_modeFlag = c5_h_modeFlag;
    if (c5_i_modeFlag) {
      for (c5_i27 = 0; c5_i27 < 2; c5_i27++) {
        c5_padSizeT[c5_i27] = 136.0 + 24.0 * (real_T)c5_i27;
      }

      for (c5_i29 = 0; c5_i29 < 2; c5_i29++) {
        c5_outSizeT[c5_i29] = 120.0 + 40.0 * (real_T)c5_i29;
      }

      for (c5_i31 = 0; c5_i31 < 2; c5_i31++) {
        c5_connDimsT[c5_i31] = 17.0 + -16.0 * (real_T)c5_i31;
      }

      ippfilter_real64(&chartInstance->c5_b[0], &chartInstance->c5_b_b[0],
                       &c5_outSizeT[0], 2.0, &c5_padSizeT[0], &c5_hcol[0],
                       &c5_connDimsT[0], false);
    } else {
      c5_b_numKernElem = (real_T)c5_nonzero_h_size[0];
      for (c5_i28 = 0; c5_i28 < 2; c5_i28++) {
        c5_padSizeT[c5_i28] = 136.0 + 24.0 * (real_T)c5_i28;
      }

      for (c5_i30 = 0; c5_i30 < 2; c5_i30++) {
        c5_outSizeT[c5_i30] = 120.0 + 40.0 * (real_T)c5_i30;
      }

      for (c5_i32 = 0; c5_i32 < 2; c5_i32++) {
        c5_connDimsT[c5_i32] = 17.0 + -16.0 * (real_T)c5_i32;
      }

      for (c5_i33 = 0; c5_i33 < 2; c5_i33++) {
        c5_startT[c5_i33] = 8.0 + -8.0 * (real_T)c5_i33;
      }

      imfilter_real64(&chartInstance->c5_b[0], &chartInstance->c5_b_b[0], 2.0,
                      &c5_outSizeT[0], 2.0, &c5_padSizeT[0], &c5_nonzero_h_data
                      [0], c5_b_numKernElem, &c5_conn[0], 2.0, &c5_connDimsT[0],
                      &c5_startT[0], 2.0, true, false);
    }

    for (c5_i34 = 0; c5_i34 < 19200; c5_i34++) {
      c5_d = muDoubleScalarRound(chartInstance->c5_b_b[c5_i34]);
      if (c5_d < 256.0) {
        if (c5_d >= 0.0) {
          c5_c_u = (uint8_T)c5_d;
        } else {
          c5_c_u = 0U;
        }
      } else if (c5_d >= 256.0) {
        c5_c_u = MAX_uint8_T;
      } else {
        c5_c_u = 0U;
      }

      c5_B[c5_i34] = c5_c_u;
    }
  } else {
    c5_c_st.site = &c5_o_emlrtRSI;
    c5_d_st.site = &c5_tb_emlrtRSI;
    for (c5_j = 0; c5_j < 176; c5_j++) {
      c5_c_j = (real_T)c5_j + 1.0;
      for (c5_b_i = 0; c5_b_i < 136; c5_b_i++) {
        c5_e_i = (real_T)c5_b_i + 1.0;
        if ((c5_idxA[(int32_T)c5_e_i - 1] < 1) || (c5_idxA[(int32_T)c5_e_i - 1] >
             120)) {
          emlrtDynamicBoundsCheckR2012b(c5_idxA[(int32_T)c5_e_i - 1], 1, 120,
            &c5_kb_emlrtBCI, &c5_d_st);
        }

        c5_i3 = c5_idxA[(int32_T)c5_c_j + 175];
        if ((c5_i3 < 1) || (c5_i3 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i3, 1, 160, &c5_lb_emlrtBCI, &c5_d_st);
        }

        chartInstance->c5_c_a[((int32_T)c5_e_i + 136 * ((int32_T)c5_c_j - 1)) -
          1] = c5_A[(c5_idxA[(int32_T)c5_e_i - 1] + 120 * (c5_i3 - 1)) - 1];
      }
    }

    c5_c_st.site = &c5_p_emlrtRSI;
    c5_tooBig = true;
    for (c5_d_i = 0; c5_d_i < 2; c5_d_i++) {
      c5_tooBig = false;
    }

    if (!c5_tooBig) {
      c5_modeFlag = true;
    } else {
      c5_modeFlag = false;
    }

    if (c5_modeFlag) {
      c5_b_modeFlag = true;
    } else {
      c5_b_modeFlag = false;
    }

    c5_c_modeFlag = c5_b_modeFlag;
    if (c5_c_modeFlag) {
      for (c5_i6 = 0; c5_i6 < 2; c5_i6++) {
        c5_padSizeT[c5_i6] = 136.0 + 40.0 * (real_T)c5_i6;
      }

      for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
        c5_outSizeT[c5_i8] = 120.0 + 40.0 * (real_T)c5_i8;
      }

      for (c5_i10 = 0; c5_i10 < 2; c5_i10++) {
        c5_connDimsT[c5_i10] = 17.0;
      }

      ippfilter_uint8(&chartInstance->c5_c_a[0], &c5_B[0], &c5_outSizeT[0], 2.0,
                      &c5_padSizeT[0], &c5_dv[0], &c5_connDimsT[0], false);
    } else {
      for (c5_i5 = 0; c5_i5 < 289; c5_i5++) {
        c5_b_conn[c5_i5] = true;
      }

      for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
        c5_padSizeT[c5_i7] = 136.0 + 40.0 * (real_T)c5_i7;
      }

      for (c5_i9 = 0; c5_i9 < 2; c5_i9++) {
        c5_outSizeT[c5_i9] = 120.0 + 40.0 * (real_T)c5_i9;
      }

      for (c5_i11 = 0; c5_i11 < 2; c5_i11++) {
        c5_connDimsT[c5_i11] = 17.0;
      }

      for (c5_i13 = 0; c5_i13 < 2; c5_i13++) {
        c5_startT[c5_i13] = 8.0;
      }

      imfilter_uint8(&chartInstance->c5_c_a[0], &c5_B[0], 2.0, &c5_outSizeT[0],
                     2.0, &c5_padSizeT[0], &c5_dv[0], 289.0, &c5_b_conn[0], 2.0,
                     &c5_connDimsT[0], &c5_startT[0], 2.0, true, false);
    }
  }
}

static void c5_svd(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c5_sp, real_T c5_U[289], real_T c5_S[289], real_T
                   c5_V[289])
{
  static char_T c5_b_cv[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  static char_T c5_cv4[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  static char_T c5_cv3[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  static char_T c5_cv2[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
    'e', 's', 'd', 'd' };

  static char_T c5_cv6[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
    'e', 's', 'v', 'd' };

  static char_T c5_cv1[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  static char_T c5_cv5[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  ptrdiff_t c5_b_info_t;
  ptrdiff_t c5_b_lda_t;
  ptrdiff_t c5_b_ldu_t;
  ptrdiff_t c5_b_ldv_t;
  ptrdiff_t c5_b_m_t;
  ptrdiff_t c5_b_n_t;
  ptrdiff_t c5_info_t;
  ptrdiff_t c5_lda_t;
  ptrdiff_t c5_ldu_t;
  ptrdiff_t c5_ldv_t;
  ptrdiff_t c5_m_t;
  ptrdiff_t c5_n_t;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_n_y = NULL;
  const mxArray *c5_o_y = NULL;
  real_T c5_A[289];
  real_T c5_Vt[289];
  real_T c5_b_S[17];
  real_T c5_superb[16];
  int32_T c5_b_info;
  int32_T c5_b_k;
  int32_T c5_c_info;
  int32_T c5_d_info;
  int32_T c5_e_info;
  int32_T c5_f_info;
  int32_T c5_g_info;
  int32_T c5_h_info;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_info;
  int32_T c5_k;
  boolean_T c5_b_p;
  boolean_T c5_p;
  (void)chartInstance;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_st.site = &c5_r_emlrtRSI;
  c5_b_st.site = &c5_t_emlrtRSI;
  c5_c_st.site = &c5_v_emlrtRSI;
  for (c5_i = 0; c5_i < 289; c5_i++) {
    c5_A[c5_i] = c5_dv[c5_i];
  }

  c5_m_t = (ptrdiff_t)17;
  c5_n_t = (ptrdiff_t)17;
  c5_lda_t = (ptrdiff_t)17;
  c5_ldu_t = (ptrdiff_t)17;
  c5_ldv_t = (ptrdiff_t)17;
  c5_info_t = LAPACKE_dgesdd(102, 'A', c5_m_t, c5_n_t, &c5_A[0], c5_lda_t,
    &c5_b_S[0], &c5_U[0], c5_ldu_t, &c5_Vt[0], c5_ldv_t);
  c5_info = (int32_T)c5_info_t;
  c5_d_st.site = &c5_w_emlrtRSI;
  c5_b_info = c5_info;
  c5_c_info = c5_b_info;
  c5_p = (c5_c_info < 0);
  if (c5_p) {
    if (c5_b_info == -1010) {
      c5_c_y = NULL;
      sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv1, 10, 0U, 1U, 0U, 2, 1, 12),
                    false);
      c5_e_y = NULL;
      sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv1, 10, 0U, 1U, 0U, 2, 1, 12),
                    false);
      sf_mex_call(&c5_d_st, &c5_c_emlrtMCI, "error", 0U, 2U, 14, c5_c_y, 14,
                  sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_e_y)));
    } else {
      c5_b_y = NULL;
      sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1,
        33), false);
      c5_d_y = NULL;
      sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1,
        33), false);
      c5_f_y = NULL;
      sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv2, 10, 0U, 1U, 0U, 2, 1, 14),
                    false);
      c5_g_y = NULL;
      sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_b_info, 6, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call(&c5_d_st, &c5_d_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                  sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_d_st, NULL, "message", 1U, 3U, 14, c5_d_y, 14, c5_f_y,
                    14, c5_g_y)));
    }
  }

  c5_d_info = c5_info;
  if (c5_info > 0) {
    c5_c_st.site = &c5_u_emlrtRSI;
    c5_d_st.site = &c5_y_emlrtRSI;
    for (c5_i3 = 0; c5_i3 < 289; c5_i3++) {
      c5_A[c5_i3] = c5_dv[c5_i3];
    }

    c5_b_m_t = (ptrdiff_t)17;
    c5_b_n_t = (ptrdiff_t)17;
    c5_b_lda_t = (ptrdiff_t)17;
    c5_b_ldu_t = (ptrdiff_t)17;
    c5_b_ldv_t = (ptrdiff_t)17;
    c5_b_info_t = LAPACKE_dgesvd(102, 'A', 'A', c5_b_m_t, c5_b_n_t, &c5_A[0],
      c5_b_lda_t, &c5_b_S[0], &c5_U[0], c5_b_ldu_t, &c5_Vt[0], c5_b_ldv_t,
      &c5_superb[0]);
    c5_e_info = (int32_T)c5_b_info_t;
    c5_i7 = 0;
    for (c5_i8 = 0; c5_i8 < 17; c5_i8++) {
      c5_i9 = 0;
      for (c5_i10 = 0; c5_i10 < 17; c5_i10++) {
        c5_V[c5_i10 + c5_i7] = c5_Vt[c5_i9 + c5_i8];
        c5_i9 += 17;
      }

      c5_i7 += 17;
    }

    c5_e_st.site = &c5_x_emlrtRSI;
    c5_f_info = c5_e_info;
    c5_g_info = c5_f_info;
    c5_b_p = (c5_g_info < 0);
    if (c5_b_p) {
      if (c5_f_info == -1010) {
        c5_k_y = NULL;
        sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_cv5, 10, 0U, 1U, 0U, 2, 1,
          12), false);
        c5_m_y = NULL;
        sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_cv5, 10, 0U, 1U, 0U, 2, 1,
          12), false);
        sf_mex_call(&c5_e_st, &c5_c_emlrtMCI, "error", 0U, 2U, 14, c5_k_y, 14,
                    sf_mex_call(&c5_e_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_e_st, NULL, "message", 1U, 1U, 14, c5_m_y)));
      } else {
        c5_j_y = NULL;
        sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_cv4, 10, 0U, 1U, 0U, 2, 1,
          33), false);
        c5_l_y = NULL;
        sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_cv4, 10, 0U, 1U, 0U, 2, 1,
          33), false);
        c5_n_y = NULL;
        sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_cv6, 10, 0U, 1U, 0U, 2, 1,
          14), false);
        c5_o_y = NULL;
        sf_mex_assign(&c5_o_y, sf_mex_create("y", &c5_f_info, 6, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call(&c5_e_st, &c5_d_emlrtMCI, "error", 0U, 2U, 14, c5_j_y, 14,
                    sf_mex_call(&c5_e_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_e_st, NULL, "message", 1U, 3U, 14, c5_l_y, 14, c5_n_y,
                      14, c5_o_y)));
      }
    }

    c5_h_info = c5_e_info;
    c5_d_info = c5_h_info;
  } else {
    c5_i1 = 0;
    for (c5_i2 = 0; c5_i2 < 17; c5_i2++) {
      c5_i4 = 0;
      for (c5_i5 = 0; c5_i5 < 17; c5_i5++) {
        c5_V[c5_i5 + c5_i1] = c5_Vt[c5_i4 + c5_i2];
        c5_i4 += 17;
      }

      c5_i1 += 17;
    }
  }

  if (c5_d_info > 0) {
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c5_b_st, &c5_b_emlrtMCI, "error", 0U, 2U, 14, c5_h_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 1U, 14, c5_i_y)));
  }

  for (c5_i6 = 0; c5_i6 < 289; c5_i6++) {
    c5_S[c5_i6] = 0.0;
  }

  c5_k = 0;
  for (c5_b_k = 0; c5_b_k < 17; c5_b_k++) {
    c5_S[c5_k] = c5_b_S[c5_b_k];
    c5_k += 18;
  }
}

static void c5_check_forloop_overflow_error
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp)
{
  static char_T c5_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c5_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c5_sp, &c5_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14, sf_mex_call
              (c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c5_sp, NULL,
    "message", 1U, 2U, 14, c5_c_y, 14, c5_d_y)));
}

static void c5_b_bwmorph(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, uint8_T c5_bwin[19200], boolean_T c5_bw[19200])
{
  static real_T c5_b_x[512] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

  static real_T c5_d_x[512] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0,
    1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0 };

  static char_T c5_b_cv[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c5_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static boolean_T c5_b_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, false, true, false, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, false, false, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, false, true, true, true, false, false, true, true, false, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, false, false, true, false, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, false, true, true, true, false,
    false, true, true, false, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, false, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, false, false,
    true, false, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, false, true, true, true, false, false, true, true,
    false, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, false, true, false, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    false, true, true, true, false, false, true, true, false, true, true, true };

  static boolean_T c5_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, true, true, false, false, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, false,
    false, true, true, false, false, true, true, false, false, true, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, false, false, false, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, true, true, true, true, true,
    true, true, false, false, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, false, false, false, true, false, false, true, true, false, false,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, false, false, true, false, false, true, true, true, true,
    true, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true };

  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  real_T c5_sizeIn[2];
  real_T c5_b_k;
  real_T c5_c_x;
  real_T c5_d_k;
  real_T c5_f_k;
  real_T c5_x;
  int32_T c5_c_k;
  int32_T c5_e_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_k;
  boolean_T c5_image_iter1[19200];
  boolean_T c5_last_aout[19200];
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_c_p;
  boolean_T c5_d_b;
  boolean_T c5_exitg1;
  boolean_T c5_p;
  boolean_T c5_x1;
  boolean_T c5_x2;
  (void)chartInstance;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    c5_bw[c5_i] = ((real_T)c5_bwin[c5_i] != 0.0);
  }

  c5_st.site = &c5_emlrtRSI;
  do {
    for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
      c5_last_aout[c5_i1] = c5_bw[c5_i1];
    }

    c5_b_st.site = &c5_yb_emlrtRSI;
    c5_c_st.site = &c5_ac_emlrtRSI;
    c5_d_st.site = &c5_ec_emlrtRSI;
    for (c5_k = 0; c5_k < 512; c5_k++) {
      c5_b_k = (real_T)c5_k + 1.0;
      c5_x = c5_b_x[(int32_T)c5_b_k - 1];
      c5_c_b = muDoubleScalarIsNaN(c5_x);
      if (c5_c_b) {
        c5_b_y = NULL;
        sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        c5_c_y = NULL;
        sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        sf_mex_call(&c5_d_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                    sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
      }
    }

    c5_c_st.site = &c5_bc_emlrtRSI;
    c5_d_st.site = &c5_d_emlrtRSI;
    for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
      c5_sizeIn[c5_i2] = 120.0 + 40.0 * (real_T)c5_i2;
    }

    bwlookup_tbb_boolean(&c5_bw[0], &c5_sizeIn[0], 2.0, &c5_lut[0], 512.0,
                         &c5_image_iter1[0]);
    c5_c_st.site = &c5_cc_emlrtRSI;
    c5_d_st.site = &c5_fc_emlrtRSI;
    for (c5_c_k = 0; c5_c_k < 512; c5_c_k++) {
      c5_d_k = (real_T)c5_c_k + 1.0;
      c5_c_x = c5_d_x[(int32_T)c5_d_k - 1];
      c5_d_b = muDoubleScalarIsNaN(c5_c_x);
      if (c5_d_b) {
        c5_d_y = NULL;
        sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv1, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        c5_e_y = NULL;
        sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv1, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        sf_mex_call(&c5_d_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                    sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_e_y)));
      }
    }

    c5_c_st.site = &c5_dc_emlrtRSI;
    c5_d_st.site = &c5_d_emlrtRSI;
    for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
      c5_sizeIn[c5_i3] = 120.0 + 40.0 * (real_T)c5_i3;
    }

    bwlookup_tbb_boolean(&c5_image_iter1[0], &c5_sizeIn[0], 2.0, &c5_b_lut[0],
                         512.0, &c5_bw[0]);
    c5_p = false;
    c5_b_p = true;
    c5_e_k = 0;
    c5_exitg1 = false;
    while ((!c5_exitg1) && (c5_e_k < 19200)) {
      c5_f_k = (real_T)c5_e_k + 1.0;
      c5_x1 = c5_last_aout[(int32_T)c5_f_k - 1];
      c5_x2 = c5_bw[(int32_T)c5_f_k - 1];
      c5_c_p = ((int32_T)c5_x1 == (int32_T)c5_x2);
      if (!c5_c_p) {
        c5_b_p = false;
        c5_exitg1 = true;
      } else {
        c5_e_k++;
      }
    }

    if (c5_b_p) {
      c5_p = true;
    }
  } while (!c5_p);
}

static void c5_c_bwmorph(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_bwin[19200], boolean_T c5_bw[19200])
{
  static boolean_T c5_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    false, false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    false, false, false, false, false, false, false, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, false, false, false, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    false, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false
  };

  real_T c5_sizeIn[2];
  real_T c5_b_k;
  real_T c5_iter;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i6;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i7;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_k;
  boolean_T c5_endPoints[19200];
  boolean_T c5_last_aout[19200];
  boolean_T c5_newEndPoints[19200];
  boolean_T c5_b_y[4800];
  boolean_T c5_t[4800];
  boolean_T c5_b_p;
  boolean_T c5_c_p;
  boolean_T c5_exitg1;
  boolean_T c5_exitg2;
  boolean_T c5_p;
  boolean_T c5_x1;
  boolean_T c5_x2;
  c5_iter = 0.0;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    c5_bw[c5_i] = c5_bwin[c5_i];
  }

  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_iter < 20.0)) {
    for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
      c5_last_aout[c5_i1] = c5_bw[c5_i1];
    }

    for (c5_i2 = 0; c5_i2 < 19200; c5_i2++) {
      c5_bw[c5_i2] = !c5_bw[c5_i2];
    }

    for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
      c5_sizeIn[c5_i3] = 120.0 + 40.0 * (real_T)c5_i3;
    }

    bwlookup_tbb_boolean(&c5_bw[0], &c5_sizeIn[0], 2.0, &c5_lut[0], 512.0,
                         &c5_endPoints[0]);
    c5_i4 = 0;
    c5_i5 = 0;
    for (c5_i6 = 0; c5_i6 < 80; c5_i6++) {
      c5_i8 = 0;
      for (c5_i10 = 0; c5_i10 < 60; c5_i10++) {
        c5_b_y[c5_i10 + c5_i4] = c5_bw[c5_i8 + c5_i5];
        c5_i8 += 2;
      }

      c5_i4 += 60;
      c5_i5 += 240;
    }

    c5_i7 = 0;
    c5_i9 = 0;
    for (c5_i11 = 0; c5_i11 < 80; c5_i11++) {
      c5_i13 = 0;
      for (c5_i14 = 0; c5_i14 < 60; c5_i14++) {
        c5_t[c5_i14 + c5_i7] = c5_endPoints[c5_i13 + c5_i9];
        c5_i13 += 2;
      }

      c5_i7 += 60;
      c5_i9 += 240;
    }

    for (c5_i12 = 0; c5_i12 < 4800; c5_i12++) {
      c5_b_y[c5_i12] = c5_function_handle_parenReference(chartInstance,
        c5_b_y[c5_i12], c5_t[c5_i12]);
    }

    c5_i15 = 0;
    c5_i16 = 0;
    for (c5_i17 = 0; c5_i17 < 80; c5_i17++) {
      c5_i19 = 0;
      for (c5_i20 = 0; c5_i20 < 60; c5_i20++) {
        c5_bw[c5_i19 + c5_i15] = c5_b_y[c5_i20 + c5_i16];
        c5_i19 += 2;
      }

      c5_i15 += 240;
      c5_i16 += 60;
    }

    for (c5_i18 = 0; c5_i18 < 2; c5_i18++) {
      c5_sizeIn[c5_i18] = 120.0 + 40.0 * (real_T)c5_i18;
    }

    bwlookup_tbb_boolean(&c5_bw[0], &c5_sizeIn[0], 2.0, &c5_lut[0], 512.0,
                         &c5_newEndPoints[0]);
    for (c5_i21 = 0; c5_i21 < 19200; c5_i21++) {
      c5_newEndPoints[c5_i21] = (c5_endPoints[c5_i21] && c5_newEndPoints[c5_i21]);
    }

    c5_i22 = 0;
    c5_i23 = 0;
    for (c5_i24 = 0; c5_i24 < 80; c5_i24++) {
      c5_i26 = 0;
      for (c5_i28 = 0; c5_i28 < 60; c5_i28++) {
        c5_b_y[c5_i28 + c5_i22] = c5_bw[(c5_i26 + c5_i23) + 120];
        c5_i26 += 2;
      }

      c5_i22 += 60;
      c5_i23 += 240;
    }

    c5_i25 = 0;
    c5_i27 = 0;
    for (c5_i29 = 0; c5_i29 < 80; c5_i29++) {
      c5_i31 = 0;
      for (c5_i32 = 0; c5_i32 < 60; c5_i32++) {
        c5_t[c5_i32 + c5_i25] = c5_newEndPoints[(c5_i31 + c5_i27) + 120];
        c5_i31 += 2;
      }

      c5_i25 += 60;
      c5_i27 += 240;
    }

    for (c5_i30 = 0; c5_i30 < 4800; c5_i30++) {
      c5_b_y[c5_i30] = c5_function_handle_parenReference(chartInstance,
        c5_b_y[c5_i30], c5_t[c5_i30]);
    }

    c5_i33 = 0;
    c5_i34 = 0;
    for (c5_i35 = 0; c5_i35 < 80; c5_i35++) {
      c5_i37 = 0;
      for (c5_i38 = 0; c5_i38 < 60; c5_i38++) {
        c5_bw[(c5_i37 + c5_i33) + 120] = c5_b_y[c5_i38 + c5_i34];
        c5_i37 += 2;
      }

      c5_i33 += 240;
      c5_i34 += 60;
    }

    for (c5_i36 = 0; c5_i36 < 2; c5_i36++) {
      c5_sizeIn[c5_i36] = 120.0 + 40.0 * (real_T)c5_i36;
    }

    bwlookup_tbb_boolean(&c5_bw[0], &c5_sizeIn[0], 2.0, &c5_lut[0], 512.0,
                         &c5_newEndPoints[0]);
    for (c5_i39 = 0; c5_i39 < 19200; c5_i39++) {
      c5_newEndPoints[c5_i39] = (c5_endPoints[c5_i39] && c5_newEndPoints[c5_i39]);
    }

    c5_i40 = 0;
    c5_i41 = 0;
    for (c5_i42 = 0; c5_i42 < 80; c5_i42++) {
      c5_i44 = 0;
      for (c5_i46 = 0; c5_i46 < 60; c5_i46++) {
        c5_b_y[c5_i46 + c5_i40] = c5_bw[(c5_i44 + c5_i41) + 1];
        c5_i44 += 2;
      }

      c5_i40 += 60;
      c5_i41 += 240;
    }

    c5_i43 = 0;
    c5_i45 = 0;
    for (c5_i47 = 0; c5_i47 < 80; c5_i47++) {
      c5_i49 = 0;
      for (c5_i50 = 0; c5_i50 < 60; c5_i50++) {
        c5_t[c5_i50 + c5_i43] = c5_newEndPoints[(c5_i49 + c5_i45) + 1];
        c5_i49 += 2;
      }

      c5_i43 += 60;
      c5_i45 += 240;
    }

    for (c5_i48 = 0; c5_i48 < 4800; c5_i48++) {
      c5_b_y[c5_i48] = c5_function_handle_parenReference(chartInstance,
        c5_b_y[c5_i48], c5_t[c5_i48]);
    }

    c5_i51 = 0;
    c5_i52 = 0;
    for (c5_i53 = 0; c5_i53 < 80; c5_i53++) {
      c5_i55 = 0;
      for (c5_i56 = 0; c5_i56 < 60; c5_i56++) {
        c5_bw[(c5_i55 + c5_i51) + 1] = c5_b_y[c5_i56 + c5_i52];
        c5_i55 += 2;
      }

      c5_i51 += 240;
      c5_i52 += 60;
    }

    for (c5_i54 = 0; c5_i54 < 2; c5_i54++) {
      c5_sizeIn[c5_i54] = 120.0 + 40.0 * (real_T)c5_i54;
    }

    bwlookup_tbb_boolean(&c5_bw[0], &c5_sizeIn[0], 2.0, &c5_lut[0], 512.0,
                         &c5_newEndPoints[0]);
    for (c5_i57 = 0; c5_i57 < 19200; c5_i57++) {
      c5_newEndPoints[c5_i57] = (c5_endPoints[c5_i57] && c5_newEndPoints[c5_i57]);
    }

    c5_i58 = 0;
    c5_i59 = 0;
    for (c5_i60 = 0; c5_i60 < 80; c5_i60++) {
      c5_i62 = 0;
      for (c5_i64 = 0; c5_i64 < 60; c5_i64++) {
        c5_b_y[c5_i64 + c5_i58] = c5_bw[(c5_i62 + c5_i59) + 121];
        c5_i62 += 2;
      }

      c5_i58 += 60;
      c5_i59 += 240;
    }

    c5_i61 = 0;
    c5_i63 = 0;
    for (c5_i65 = 0; c5_i65 < 80; c5_i65++) {
      c5_i67 = 0;
      for (c5_i68 = 0; c5_i68 < 60; c5_i68++) {
        c5_t[c5_i68 + c5_i61] = c5_newEndPoints[(c5_i67 + c5_i63) + 121];
        c5_i67 += 2;
      }

      c5_i61 += 60;
      c5_i63 += 240;
    }

    for (c5_i66 = 0; c5_i66 < 4800; c5_i66++) {
      c5_b_y[c5_i66] = c5_function_handle_parenReference(chartInstance,
        c5_b_y[c5_i66], c5_t[c5_i66]);
    }

    c5_i69 = 0;
    c5_i70 = 0;
    for (c5_i71 = 0; c5_i71 < 80; c5_i71++) {
      c5_i73 = 0;
      for (c5_i74 = 0; c5_i74 < 60; c5_i74++) {
        c5_bw[(c5_i73 + c5_i69) + 121] = c5_b_y[c5_i74 + c5_i70];
        c5_i73 += 2;
      }

      c5_i69 += 240;
      c5_i70 += 60;
    }

    for (c5_i72 = 0; c5_i72 < 19200; c5_i72++) {
      c5_bw[c5_i72] = !c5_bw[c5_i72];
    }

    c5_iter++;
    c5_p = false;
    c5_b_p = true;
    c5_k = 0;
    c5_exitg2 = false;
    while ((!c5_exitg2) && (c5_k < 19200)) {
      c5_b_k = (real_T)c5_k + 1.0;
      c5_x1 = c5_last_aout[(int32_T)c5_b_k - 1];
      c5_x2 = c5_bw[(int32_T)c5_b_k - 1];
      c5_c_p = ((int32_T)c5_x1 == (int32_T)c5_x2);
      if (!c5_c_p) {
        c5_b_p = false;
        c5_exitg2 = true;
      } else {
        c5_k++;
      }
    }

    if (c5_b_p) {
      c5_p = true;
    }

    if (c5_p) {
      c5_exitg1 = true;
    }
  }
}

static boolean_T c5_function_handle_parenReference
  (SFc5_flightControlSystemInstanceStruct *chartInstance, boolean_T
   c5_varargin_1, boolean_T c5_varargin_2)
{
  boolean_T c5_b_varargin_1;
  boolean_T c5_b_varargin_2;
  boolean_T c5_b_y;
  boolean_T c5_c_b;
  boolean_T c5_d_a;
  boolean_T c5_d_b;
  boolean_T c5_e_a;
  boolean_T c5_x;
  (void)chartInstance;
  c5_x = c5_varargin_1;
  c5_b_y = c5_varargin_2;
  c5_b_varargin_1 = c5_x;
  c5_b_varargin_2 = c5_b_y;
  c5_d_a = c5_b_varargin_1;
  c5_c_b = c5_b_varargin_2;
  c5_e_a = c5_d_a;
  c5_d_b = c5_c_b;
  return (boolean_T)((int32_T)c5_e_a ^ (int32_T)c5_d_b);
}

static void c5_cat(SFc5_flightControlSystemInstanceStruct *chartInstance,
                   boolean_T c5_varargin_1[19200], boolean_T c5_varargin_2[19200],
                   boolean_T c5_varargin_3[19200], boolean_T c5_b_y[57600])
{
  int32_T c5_b_j;
  int32_T c5_c_j;
  int32_T c5_d_j;
  int32_T c5_iy;
  int32_T c5_j;
  (void)chartInstance;
  c5_iy = -1;
  for (c5_j = 0; c5_j < 19200; c5_j++) {
    c5_c_j = c5_j;
    c5_iy++;
    c5_b_y[c5_iy] = c5_varargin_1[c5_c_j];
  }

  for (c5_b_j = 0; c5_b_j < 19200; c5_b_j++) {
    c5_c_j = c5_b_j;
    c5_iy++;
    c5_b_y[c5_iy] = c5_varargin_2[c5_c_j];
  }

  for (c5_d_j = 0; c5_d_j < 19200; c5_d_j++) {
    c5_c_j = c5_d_j;
    c5_iy++;
    c5_b_y[c5_iy] = c5_varargin_3[c5_c_j];
  }
}

static void c5_eml_find(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_x[19200], int32_T c5_i_data[], int32_T
  c5_i_size[1], int32_T c5_j_data[], int32_T c5_j_size[1])
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  int32_T c5_iv[2];
  int32_T c5_iv1[2];
  int32_T c5_iv2[2];
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_idx;
  int32_T c5_ii;
  int32_T c5_jj;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_c_b;
  boolean_T c5_exitg1;
  boolean_T c5_guard1;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_lc_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_idx = 0;
  c5_ii = 1;
  c5_jj = 1;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_jj <= 160)) {
    c5_guard1 = false;
    if (c5_x[(c5_ii + 120 * (c5_jj - 1)) - 1]) {
      c5_idx++;
      c5_i_data[c5_idx - 1] = c5_ii;
      c5_j_data[c5_idx - 1] = c5_jj;
      if (c5_idx >= 19200) {
        c5_exitg1 = true;
      } else {
        c5_guard1 = true;
      }
    } else {
      c5_guard1 = true;
    }

    if (c5_guard1) {
      c5_ii++;
      if (c5_ii > 120) {
        c5_ii = 1;
        c5_jj++;
      }
    }
  }

  c5_c_b = (c5_idx < 1);
  if (c5_c_b) {
    c5_i = 0;
  } else {
    c5_i = c5_idx;
  }

  c5_iv[0] = 1;
  c5_iv[1] = c5_i;
  c5_b_st.site = &c5_oc_emlrtRSI;
  c5_indexShapeCheck(chartInstance, &c5_b_st, 19200, c5_iv);
  c5_i_size[0] = c5_i;
  c5_b1 = (c5_idx < 1);
  if (c5_b1) {
    c5_i1 = 0;
  } else {
    c5_i1 = c5_idx;
  }

  c5_iv1[0] = 1;
  c5_iv1[1] = c5_i1;
  c5_b_st.site = &c5_nc_emlrtRSI;
  c5_indexShapeCheck(chartInstance, &c5_b_st, 19200, c5_iv1);
  c5_j_size[0] = c5_i1;
  c5_b2 = (c5_idx < 1);
  if (c5_b2) {
    c5_i2 = 0;
  } else {
    c5_i2 = c5_idx;
  }

  c5_iv2[0] = 1;
  c5_iv2[1] = c5_i2;
  c5_b_st.site = &c5_mc_emlrtRSI;
  c5_indexShapeCheck(chartInstance, &c5_b_st, 19200, c5_iv2);
}

static void c5_indexShapeCheck(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_matrixSize, int32_T
  c5_indexSize[2])
{
  static char_T c5_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  int32_T c5_size1;
  boolean_T c5_b_c;
  boolean_T c5_c;
  boolean_T c5_c_b;
  boolean_T c5_d_b;
  boolean_T c5_nonSingletonDimFound;
  (void)chartInstance;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_size1 = c5_matrixSize;
  if (c5_size1 != 1) {
    c5_c_b = false;
  } else {
    c5_c_b = true;
  }

  if (c5_c_b) {
    c5_nonSingletonDimFound = false;
    if (c5_indexSize[1] != 1) {
      c5_nonSingletonDimFound = true;
    }

    c5_d_b = c5_nonSingletonDimFound;
    if (c5_d_b) {
      c5_c = true;
    } else {
      c5_c = false;
    }
  } else {
    c5_c = false;
  }

  c5_st.site = &c5_pc_emlrtRSI;
  c5_b_c = c5_c;
  if (c5_b_c) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c5_st, &c5_h_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
  }
}

static void c5_power(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, real_T c5_a_data[], int32_T
                     c5_a_size[1], real_T c5_y_data[], int32_T c5_y_size[1])
{
  static char_T c5_b_cv[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  int32_T c5_i;
  int32_T c5_loop_ub;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_qc_emlrtRSI;
  c5_p = false;
  if (c5_p) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c5_st, &c5_i_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
  }

  c5_y_size[0] = c5_a_size[0];
  c5_loop_ub = c5_a_size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_y_data[c5_i] = c5_b_function_handle_parenReference(chartInstance,
      c5_a_data[c5_i]);
  }
}

static real_T c5_b_function_handle_parenReference
  (SFc5_flightControlSystemInstanceStruct *chartInstance, real_T c5_varargin_1)
{
  real_T c5_d_a;
  real_T c5_x;
  (void)chartInstance;
  c5_x = c5_varargin_1;
  c5_d_a = c5_x;
  return c5_d_a * c5_d_a;
}

static void c5_sqrt(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T c5_x_size[1],
                    real_T c5_d_x_data[], int32_T c5_b_x_size[1])
{
  int32_T c5_i;
  int32_T c5_loop_ub;
  c5_b_x_size[0] = c5_x_size[0];
  c5_loop_ub = c5_x_size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_d_x_data[c5_i] = c5_c_x_data[c5_i];
  }

  c5_b_sqrt(chartInstance, c5_sp, c5_d_x_data, c5_b_x_size);
}

static boolean_T c5_all(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_c_x_data[], int32_T c5_x_size[1])
{
  static char_T c5_b_cv[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
    'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  real_T c5_d_a;
  real_T c5_vlen;
  int32_T c5_c;
  int32_T c5_d_b;
  int32_T c5_e_a;
  int32_T c5_e_b;
  int32_T c5_f_a;
  int32_T c5_f_b;
  int32_T c5_i2;
  int32_T c5_ix;
  int32_T c5_vspread;
  boolean_T c5_b_y;
  boolean_T c5_c_b;
  boolean_T c5_exitg1;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_st.site = &c5_tc_emlrtRSI;
  if ((c5_x_size[0] == 1) || ((real_T)c5_x_size[0] != 1.0)) {
    c5_c_b = true;
  } else {
    c5_c_b = false;
  }

  if (!c5_c_b) {
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c5_st, &c5_j_emlrtMCI, "error", 0U, 2U, 14, c5_c_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_d_y)));
  }

  c5_b_y = true;
  c5_vlen = (real_T)c5_x_size[0];
  c5_d_a = c5_vlen;
  c5_c = (int32_T)c5_d_a;
  c5_e_a = c5_c - 1;
  c5_vspread = c5_e_a;
  c5_d_b = c5_vspread;
  c5_i2 = c5_d_b;
  c5_f_a = c5_i2 + 1;
  c5_i2 = c5_f_a;
  c5_b_st.site = &c5_uc_emlrtRSI;
  c5_e_b = c5_i2;
  c5_f_b = c5_e_b;
  if (c5_f_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_f_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_s_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  c5_ix = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_ix + 1 <= c5_i2)) {
    if (!c5_c_x_data[c5_ix]) {
      c5_b_y = false;
      c5_exitg1 = true;
    } else {
      c5_ix++;
    }
  }

  return c5_b_y;
}

static void c5_sort(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T c5_x_size[1],
                    real_T c5_d_x_data[], int32_T c5_b_x_size[1], int32_T
                    c5_idx_data[], int32_T c5_idx_size[1])
{
  int32_T c5_i;
  int32_T c5_loop_ub;
  c5_b_x_size[0] = c5_x_size[0];
  c5_loop_ub = c5_x_size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_d_x_data[c5_i] = c5_c_x_data[c5_i];
  }

  c5_c_sort(chartInstance, c5_sp, c5_d_x_data, c5_b_x_size, c5_idx_data,
            c5_idx_size);
}

static void c5_sortIdx(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T
  c5_idx_data[], int32_T c5_idx_size[1], real_T c5_d_x_data[], int32_T
  c5_b_x_size[1])
{
  int32_T c5_i;
  int32_T c5_loop_ub;
  c5_b_x_size[0] = c5_x_size[0];
  c5_loop_ub = c5_x_size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_d_x_data[c5_i] = c5_c_x_data[c5_i];
  }

  c5_b_sortIdx(chartInstance, c5_sp, c5_d_x_data, c5_b_x_size, c5_idx_data,
               c5_idx_size);
}

static void c5_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_idx_data[], int32_T
  c5_idx_size[1], real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T c5_offset,
  int32_T c5_b_idx_data[], int32_T c5_b_idx_size[1], real_T c5_d_x_data[],
  int32_T c5_b_x_size[1])
{
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_loop_ub;
  c5_b_idx_size[0] = c5_idx_size[0];
  c5_loop_ub = c5_idx_size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_idx_data[c5_i] = c5_idx_data[c5_i];
  }

  c5_b_x_size[0] = c5_x_size[0];
  c5_b_loop_ub = c5_x_size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_d_x_data[c5_i1] = c5_c_x_data[c5_i1];
  }

  c5_b_merge_pow2_block(chartInstance, c5_sp, c5_b_idx_data, c5_d_x_data,
                        c5_offset);
}

static void c5_merge_block(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, int32_T c5_idx_data[], int32_T c5_idx_size[1], real_T
  c5_c_x_data[], int32_T c5_x_size[1], int32_T c5_offset, int32_T c5_n, int32_T
  c5_preSortLevel, int32_T c5_b_iwork_data[], int32_T c5_iwork_size[1], real_T
  c5_b_xwork_data[], int32_T c5_xwork_size[1], int32_T c5_b_idx_data[], int32_T
  c5_b_idx_size[1], real_T c5_d_x_data[], int32_T c5_b_x_size[1], int32_T
  c5_c_iwork_data[], int32_T c5_b_iwork_size[1], real_T c5_c_xwork_data[],
  int32_T c5_b_xwork_size[1])
{
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_loop_ub;
  c5_b_idx_size[0] = c5_idx_size[0];
  c5_loop_ub = c5_idx_size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_idx_data[c5_i] = c5_idx_data[c5_i];
  }

  c5_b_x_size[0] = c5_x_size[0];
  c5_b_loop_ub = c5_x_size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_d_x_data[c5_i1] = c5_c_x_data[c5_i1];
  }

  c5_b_iwork_size[0] = c5_iwork_size[0];
  c5_c_loop_ub = c5_iwork_size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_c_loop_ub; c5_i2++) {
    c5_c_iwork_data[c5_i2] = c5_b_iwork_data[c5_i2];
  }

  c5_b_xwork_size[0] = c5_xwork_size[0];
  c5_d_loop_ub = c5_xwork_size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_d_loop_ub; c5_i3++) {
    c5_c_xwork_data[c5_i3] = c5_b_xwork_data[c5_i3];
  }

  c5_b_merge_block(chartInstance, c5_sp, c5_b_idx_data, c5_d_x_data, c5_offset,
                   c5_n, c5_preSortLevel, c5_c_iwork_data, c5_c_xwork_data);
}

static void c5_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, int32_T c5_idx_data[], int32_T
                     c5_idx_size[1], real_T c5_c_x_data[], int32_T c5_x_size[1],
                     int32_T c5_offset, int32_T c5_np, int32_T c5_nq, int32_T
                     c5_b_iwork_data[], int32_T c5_iwork_size[1], real_T
                     c5_b_xwork_data[], int32_T c5_xwork_size[1], int32_T
                     c5_b_idx_data[], int32_T c5_b_idx_size[1], real_T
                     c5_d_x_data[], int32_T c5_b_x_size[1], int32_T
                     c5_c_iwork_data[], int32_T c5_b_iwork_size[1], real_T
                     c5_c_xwork_data[], int32_T c5_b_xwork_size[1])
{
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_loop_ub;
  c5_b_idx_size[0] = c5_idx_size[0];
  c5_loop_ub = c5_idx_size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_idx_data[c5_i] = c5_idx_data[c5_i];
  }

  c5_b_x_size[0] = c5_x_size[0];
  c5_b_loop_ub = c5_x_size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_d_x_data[c5_i1] = c5_c_x_data[c5_i1];
  }

  c5_b_iwork_size[0] = c5_iwork_size[0];
  c5_c_loop_ub = c5_iwork_size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_c_loop_ub; c5_i2++) {
    c5_c_iwork_data[c5_i2] = c5_b_iwork_data[c5_i2];
  }

  c5_b_xwork_size[0] = c5_xwork_size[0];
  c5_d_loop_ub = c5_xwork_size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_d_loop_ub; c5_i3++) {
    c5_c_xwork_data[c5_i3] = c5_b_xwork_data[c5_i3];
  }

  c5_b_merge(chartInstance, c5_sp, c5_b_idx_data, c5_d_x_data, c5_offset, c5_np,
             c5_nq, c5_c_iwork_data, c5_c_xwork_data);
}

static void c5_isfinite(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real_T c5_c_x_data[], int32_T c5_x_size[1], boolean_T c5_b_data[], int32_T
  c5_b_size[1])
{
  int32_T c5_b_b_size[1];
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_e_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_loop_ub;
  boolean_T c5_b_b_data[40];
  (void)chartInstance;
  c5_b_size[0] = c5_x_size[0];
  c5_loop_ub = c5_x_size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_data[c5_i] = muDoubleScalarIsInf(c5_c_x_data[c5_i]);
  }

  c5_b_loop_ub = c5_b_size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_b_data[c5_i1] = !c5_b_data[c5_i1];
  }

  c5_b_b_size[0] = c5_x_size[0];
  c5_c_loop_ub = c5_x_size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_c_loop_ub; c5_i2++) {
    c5_b_b_data[c5_i2] = muDoubleScalarIsNaN(c5_c_x_data[c5_i2]);
  }

  c5_d_loop_ub = c5_b_b_size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_d_loop_ub; c5_i3++) {
    c5_b_b_data[c5_i3] = !c5_b_b_data[c5_i3];
  }

  c5_e_loop_ub = c5_b_size[0] - 1;
  for (c5_i4 = 0; c5_i4 <= c5_e_loop_ub; c5_i4++) {
    c5_b_data[c5_i4] = (c5_b_data[c5_i4] && c5_b_b_data[c5_i4]);
  }
}

static void c5_b_sort(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T
                      c5_x_size[1], real_T c5_d_x_data[], int32_T c5_b_x_size[1],
                      int32_T c5_idx_data[], int32_T c5_idx_size[1])
{
  int32_T c5_i;
  int32_T c5_loop_ub;
  c5_b_x_size[0] = c5_x_size[0];
  c5_loop_ub = c5_x_size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_d_x_data[c5_i] = c5_c_x_data[c5_i];
  }

  c5_d_sort(chartInstance, c5_sp, c5_d_x_data, c5_b_x_size, c5_idx_data,
            c5_idx_size);
}

const mxArray *sf_c5_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static real_T c5_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier)
{
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nullptr),
    &c5_thisId);
  sf_mex_destroy(&c5_nullptr);
  return c5_b_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_b_y;
  real_T c5_d;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), &c5_d, 1, 0, 0U, 0, 0U, 0);
  c5_b_y = c5_d;
  sf_mex_destroy(&c5_c_u);
  return c5_b_y;
}

static void c5_c_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier,
  uint8_T c5_b_y[57600])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nullptr), &c5_thisId,
                        c5_b_y);
  sf_mex_destroy(&c5_nullptr);
}

static void c5_d_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  uint8_T c5_b_y[57600])
{
  int32_T c5_i;
  uint8_T c5_uv[57600];
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), c5_uv, 1, 3, 0U, 1, 0U, 3, 120,
                160, 3);
  for (c5_i = 0; c5_i < 57600; c5_i++) {
    c5_b_y[c5_i] = c5_uv[c5_i];
  }

  sf_mex_destroy(&c5_c_u);
}

static void c5_e_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier, real_T
  c5_b_y[40])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nullptr), &c5_thisId,
                        c5_b_y);
  sf_mex_destroy(&c5_nullptr);
}

static void c5_f_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[40])
{
  real_T c5_b_dv[40];
  int32_T c5_i;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), c5_b_dv, 1, 0, 0U, 1, 0U, 2, 40,
                1);
  for (c5_i = 0; c5_i < 40; c5_i++) {
    c5_b_y[c5_i] = c5_b_dv[c5_i];
  }

  sf_mex_destroy(&c5_c_u);
}

static real_T c5_g_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier,
  boolean_T *c5_svPtr)
{
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nullptr),
    &c5_thisId, c5_svPtr);
  sf_mex_destroy(&c5_nullptr);
  return c5_b_y;
}

static real_T c5_h_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  boolean_T *c5_svPtr)
{
  real_T c5_b_y;
  real_T c5_d;
  (void)chartInstance;
  if (mxIsEmpty(c5_c_u)) {
    *c5_svPtr = false;
  } else {
    *c5_svPtr = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), &c5_d, 1, 0, 0U, 0, 0U, 0);
    c5_b_y = c5_d;
  }

  sf_mex_destroy(&c5_c_u);
  return c5_b_y;
}

static uint8_T c5_i_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier)
{
  emlrtMsgIdentifier c5_thisId;
  uint8_T c5_b_y;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nullptr),
    &c5_thisId);
  sf_mex_destroy(&c5_nullptr);
  return c5_b_y;
}

static uint8_T c5_j_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_b_y;
  uint8_T c5_d_u;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), &c5_d_u, 1, 3, 0U, 0, 0U, 0);
  c5_b_y = c5_d_u;
  sf_mex_destroy(&c5_c_u);
  return c5_b_y;
}

static void c5_slStringInitializeDynamicBuffers
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_chart_data_browse_helper(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_ssIdNumber, const mxArray **c5_mxData, uint8_T
  *c5_isValueTooBig)
{
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d3;
  *c5_mxData = NULL;
  *c5_mxData = NULL;
  *c5_isValueTooBig = 0U;
  switch (c5_ssIdNumber) {
   case 4U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", *chartInstance->c5_b_u, 11,
      0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 5U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", *chartInstance->c5_b_outt,
      3, 0U, 1U, 0U, 3, 120, 160, 3), false);
    break;

   case 8U:
    c5_d = *chartInstance->c5_distX;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 9U:
    c5_d1 = *chartInstance->c5_distY;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 12U:
    c5_d2 = *chartInstance->c5_dom_x;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d2, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 13U:
    c5_d3 = *chartInstance->c5_dom_y;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d3, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 10U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", *chartInstance->c5_pointsx,
      0, 0U, 1U, 0U, 2, 40, 1), false);
    break;

   case 11U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", *chartInstance->c5_pointsy,
      0, 0U, 1U, 0U, 2, 40, 1), false);
    break;
  }
}

static void c5_b_sqrt(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T
                      c5_x_size[1])
{
  static char_T c5_b_cv[4] = { 's', 'q', 'r', 't' };

  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  real_T c5_b_k;
  real_T c5_b_x;
  real_T c5_d;
  real_T c5_x;
  int32_T c5_b_x_size[1];
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_k;
  int32_T c5_loop_ub;
  int32_T c5_nx;
  boolean_T c5_b_p;
  boolean_T c5_overflow;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_b_x_size[0] = c5_x_size[0];
  c5_loop_ub = c5_x_size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    chartInstance->c5_b_x_data[c5_i] = c5_c_x_data[c5_i];
  }

  c5_p = false;
  c5_d = (real_T)c5_b_x_size[0];
  c5_i1 = (int32_T)c5_d - 1;
  for (c5_k = 0; c5_k <= c5_i1; c5_k++) {
    c5_b_k = (real_T)c5_k + 1.0;
    if (c5_p || (chartInstance->c5_b_x_data[(int32_T)c5_b_k - 1] < 0.0)) {
      c5_b_p = true;
    } else {
      c5_b_p = false;
    }

    c5_p = c5_b_p;
  }

  if (c5_p) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c5_sp, &c5_f_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 2U, 14, c5_c_y, 14, c5_d_y)));
  }

  c5_st.site = &c5_rc_emlrtRSI;
  c5_nx = c5_x_size[0];
  c5_b_st.site = &c5_sc_emlrtRSI;
  c5_c_b = c5_nx;
  c5_d_b = c5_c_b;
  if (c5_d_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_d_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_s_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  c5_i2 = (uint16_T)c5_nx - 1;
  for (c5_c_k = 0; c5_c_k <= c5_i2; c5_c_k++) {
    c5_d_k = c5_c_k;
    c5_x = c5_c_x_data[c5_d_k];
    c5_b_x = c5_x;
    c5_b_x = muDoubleScalarSqrt(c5_b_x);
    c5_c_x_data[c5_d_k] = c5_b_x;
  }
}

static void c5_c_sort(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T
                      c5_x_size[1], int32_T c5_idx_data[], int32_T c5_idx_size[1])
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  real_T c5_b_dv[2];
  real_T c5_d;
  real_T c5_d1;
  int32_T c5_iv[2];
  int32_T c5_b_x_size[1];
  int32_T c5_iidx_size[1];
  int32_T c5_vwork_size[1];
  int32_T c5_b_dim;
  int32_T c5_b_i;
  int32_T c5_b_j;
  int32_T c5_b_k;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_dim;
  int32_T c5_e_b;
  int32_T c5_f_b;
  int32_T c5_g_b;
  int32_T c5_h_b;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i_b;
  int32_T c5_j;
  int32_T c5_j_b;
  int32_T c5_k;
  int32_T c5_upperDim;
  int32_T c5_vlen;
  int32_T c5_vstride;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_d_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_b_x_size[0] = c5_x_size[0];
  c5_dim = 2;
  if ((real_T)c5_b_x_size[0] != 1.0) {
    c5_dim = 1;
  }

  if (c5_dim <= 1) {
    c5_d = (real_T)c5_x_size[0];
  } else {
    c5_d = 1.0;
  }

  c5_vlen = (int32_T)c5_d;
  c5_iv[0] = c5_vlen;
  c5_vwork_size[0] = c5_iv[0];
  c5_b_dv[0] = (real_T)c5_x_size[0];
  c5_idx_size[0] = (int32_T)c5_b_dv[0];
  c5_st.site = &c5_wc_emlrtRSI;
  c5_b_x_size[0] = c5_x_size[0];
  c5_b_dim = c5_dim - 1;
  c5_vstride = 1;
  c5_upperDim = c5_b_dim;
  c5_b_st.site = &c5_dd_emlrtRSI;
  c5_c_b = c5_upperDim;
  c5_d_b = c5_c_b;
  if (c5_d_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_d_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_s_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  c5_i = (uint8_T)c5_upperDim - 1;
  for (c5_k = 0; c5_k <= c5_i; c5_k++) {
    c5_d1 = (real_T)c5_b_x_size[0];
    c5_vstride *= (int32_T)c5_d1;
  }

  c5_st.site = &c5_xc_emlrtRSI;
  for (c5_b_i = 0; c5_b_i < 1; c5_b_i++) {
    c5_st.site = &c5_yc_emlrtRSI;
    c5_e_b = c5_vstride;
    c5_f_b = c5_e_b;
    if (c5_f_b < 1) {
      c5_b_overflow = false;
    } else {
      c5_b_overflow = (c5_f_b > 2147483646);
    }

    if (c5_b_overflow) {
      c5_b_st.site = &c5_s_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_j = 0; c5_j < c5_vstride; c5_j++) {
      c5_b_j = c5_j;
      c5_st.site = &c5_ad_emlrtRSI;
      c5_g_b = c5_vlen;
      c5_h_b = c5_g_b;
      if (c5_h_b < 1) {
        c5_c_overflow = false;
      } else {
        c5_c_overflow = (c5_h_b > 2147483646);
      }

      if (c5_c_overflow) {
        c5_b_st.site = &c5_s_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
      }

      c5_i1 = (uint16_T)c5_vlen - 1;
      for (c5_b_k = 0; c5_b_k <= c5_i1; c5_b_k++) {
        c5_c_k = c5_b_k;
        chartInstance->c5_vwork_data[c5_c_k] = c5_c_x_data[c5_b_j + c5_c_k *
          c5_vstride];
      }

      c5_st.site = &c5_bd_emlrtRSI;
      c5_b_sortIdx(chartInstance, &c5_st, chartInstance->c5_vwork_data,
                   c5_vwork_size, chartInstance->c5_b_iidx_data, c5_iidx_size);
      c5_st.site = &c5_cd_emlrtRSI;
      c5_i_b = c5_vlen;
      c5_j_b = c5_i_b;
      if (c5_j_b < 1) {
        c5_d_overflow = false;
      } else {
        c5_d_overflow = (c5_j_b > 2147483646);
      }

      if (c5_d_overflow) {
        c5_b_st.site = &c5_s_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
      }

      c5_i2 = (uint16_T)c5_vlen - 1;
      for (c5_d_k = 0; c5_d_k <= c5_i2; c5_d_k++) {
        c5_c_k = c5_d_k;
        c5_c_x_data[c5_b_j + c5_c_k * c5_vstride] = chartInstance->
          c5_vwork_data[c5_c_k];
        c5_idx_data[c5_b_j + c5_c_k * c5_vstride] =
          chartInstance->c5_b_iidx_data[c5_c_k];
      }
    }
  }
}

static void c5_b_sortIdx(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T
  c5_idx_data[], int32_T c5_idx_size[1])
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  real_T c5_x4[4];
  real_T c5_b_dv[2];
  real_T c5_x;
  int32_T c5_idx4[4];
  int32_T c5_perm[4];
  int32_T c5_iv[1];
  int32_T c5_iwork[1];
  int32_T c5_iwork_size[1];
  int32_T c5_xwork[1];
  int32_T c5_xwork_size[1];
  int32_T c5_b_i1;
  int32_T c5_b_i2;
  int32_T c5_b_i3;
  int32_T c5_b_i4;
  int32_T c5_b_k;
  int32_T c5_b_loop_ub;
  int32_T c5_b_n;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_c_n;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_f_b;
  int32_T c5_g_b;
  int32_T c5_h_b;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i_b;
  int32_T c5_ib;
  int32_T c5_itmp;
  int32_T c5_j_b;
  int32_T c5_k;
  int32_T c5_k_b;
  int32_T c5_l_b;
  int32_T c5_loop_ub;
  int32_T c5_m;
  int32_T c5_m_b;
  int32_T c5_n;
  int32_T c5_nBlocks;
  int32_T c5_nLastBlock;
  int32_T c5_nNaNs;
  int32_T c5_nNonNaN;
  int32_T c5_preSortLevel;
  int32_T c5_quartetOffset;
  int32_T c5_tailOffset;
  int32_T c5_wOffset;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_d_overflow;
  boolean_T c5_e_b;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_b_dv[0] = (real_T)c5_x_size[0];
  c5_idx_size[0] = (int32_T)c5_b_dv[0];
  c5_loop_ub = (int32_T)c5_b_dv[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_idx_data[c5_i] = 0;
  }

  if (c5_x_size[0] != 0) {
    c5_st.site = &c5_ed_emlrtRSI;
    c5_n = c5_x_size[0];
    c5_b_st.site = &c5_fd_emlrtRSI;
    c5_b_n = c5_x_size[0];
    for (c5_i1 = 0; c5_i1 < 4; c5_i1++) {
      c5_x4[c5_i1] = 0.0;
    }

    for (c5_i2 = 0; c5_i2 < 4; c5_i2++) {
      c5_idx4[c5_i2] = 0;
    }

    c5_iwork_size[0] = c5_idx_size[0];
    c5_iv[0] = c5_iwork_size[0];
    c5_iwork_size[0] = c5_iv[0];
    c5_iwork[0] = c5_iwork_size[0];
    c5_b_loop_ub = c5_iwork[0] - 1;
    for (c5_i3 = 0; c5_i3 <= c5_b_loop_ub; c5_i3++) {
      chartInstance->c5_iwork_data[c5_i3] = 0;
    }

    c5_b_dv[0] = (real_T)c5_x_size[0];
    c5_xwork_size[0] = (int32_T)c5_b_dv[0];
    c5_iv[0] = c5_xwork_size[0];
    c5_xwork_size[0] = c5_iv[0];
    c5_xwork[0] = c5_xwork_size[0];
    c5_c_loop_ub = c5_xwork[0] - 1;
    for (c5_i4 = 0; c5_i4 <= c5_c_loop_ub; c5_i4++) {
      chartInstance->c5_xwork_data[c5_i4] = 0.0;
    }

    c5_nNaNs = 0;
    c5_ib = 0;
    c5_c_st.site = &c5_kd_emlrtRSI;
    c5_c_b = c5_b_n;
    c5_d_b = c5_c_b;
    if (c5_d_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_d_b > 2147483646);
    }

    if (c5_overflow) {
      c5_d_st.site = &c5_s_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
    }

    c5_i5 = (uint16_T)c5_b_n - 1;
    for (c5_k = 0; c5_k <= c5_i5; c5_k++) {
      c5_b_k = c5_k;
      c5_x = c5_c_x_data[c5_b_k];
      c5_e_b = muDoubleScalarIsNaN(c5_x);
      if (c5_e_b) {
        c5_idx_data[(c5_b_n - c5_nNaNs) - 1] = c5_b_k + 1;
        chartInstance->c5_xwork_data[(c5_b_n - c5_nNaNs) - 1] =
          c5_c_x_data[c5_b_k];
        c5_nNaNs++;
      } else {
        c5_ib++;
        c5_idx4[c5_ib - 1] = c5_b_k + 1;
        c5_x4[c5_ib - 1] = c5_c_x_data[c5_b_k];
        if (c5_ib == 4) {
          c5_quartetOffset = c5_b_k - c5_nNaNs;
          if (c5_x4[0] <= c5_x4[1]) {
            c5_b_i1 = 1;
            c5_b_i2 = 2;
          } else {
            c5_b_i1 = 2;
            c5_b_i2 = 1;
          }

          if (c5_x4[2] <= c5_x4[3]) {
            c5_b_i3 = 3;
            c5_b_i4 = 4;
          } else {
            c5_b_i3 = 4;
            c5_b_i4 = 3;
          }

          if (c5_x4[c5_b_i1 - 1] <= c5_x4[c5_b_i3 - 1]) {
            if (c5_x4[c5_b_i2 - 1] <= c5_x4[c5_b_i3 - 1]) {
              c5_perm[0] = c5_b_i1;
              c5_perm[1] = c5_b_i2;
              c5_perm[2] = c5_b_i3;
              c5_perm[3] = c5_b_i4;
            } else if (c5_x4[c5_b_i2 - 1] <= c5_x4[c5_b_i4 - 1]) {
              c5_perm[0] = c5_b_i1;
              c5_perm[1] = c5_b_i3;
              c5_perm[2] = c5_b_i2;
              c5_perm[3] = c5_b_i4;
            } else {
              c5_perm[0] = c5_b_i1;
              c5_perm[1] = c5_b_i3;
              c5_perm[2] = c5_b_i4;
              c5_perm[3] = c5_b_i2;
            }
          } else if (c5_x4[c5_b_i1 - 1] <= c5_x4[c5_b_i4 - 1]) {
            if (c5_x4[c5_b_i2 - 1] <= c5_x4[c5_b_i4 - 1]) {
              c5_perm[0] = c5_b_i3;
              c5_perm[1] = c5_b_i1;
              c5_perm[2] = c5_b_i2;
              c5_perm[3] = c5_b_i4;
            } else {
              c5_perm[0] = c5_b_i3;
              c5_perm[1] = c5_b_i1;
              c5_perm[2] = c5_b_i4;
              c5_perm[3] = c5_b_i2;
            }
          } else {
            c5_perm[0] = c5_b_i3;
            c5_perm[1] = c5_b_i4;
            c5_perm[2] = c5_b_i1;
            c5_perm[3] = c5_b_i2;
          }

          c5_idx_data[c5_quartetOffset - 3] = c5_idx4[c5_perm[0] - 1];
          c5_idx_data[c5_quartetOffset - 2] = c5_idx4[c5_perm[1] - 1];
          c5_idx_data[c5_quartetOffset - 1] = c5_idx4[c5_perm[2] - 1];
          c5_idx_data[c5_quartetOffset] = c5_idx4[c5_perm[3] - 1];
          c5_c_x_data[c5_quartetOffset - 3] = c5_x4[c5_perm[0] - 1];
          c5_c_x_data[c5_quartetOffset - 2] = c5_x4[c5_perm[1] - 1];
          c5_c_x_data[c5_quartetOffset - 1] = c5_x4[c5_perm[2] - 1];
          c5_c_x_data[c5_quartetOffset] = c5_x4[c5_perm[3] - 1];
          c5_ib = 0;
        }
      }
    }

    c5_wOffset = (c5_b_n - c5_nNaNs) - 1;
    if (c5_ib > 0) {
      c5_c_n = c5_ib;
      for (c5_i6 = 0; c5_i6 < 4; c5_i6++) {
        c5_perm[c5_i6] = 0;
      }

      if (c5_c_n == 1) {
        c5_perm[0] = 1;
      } else if (c5_c_n == 2) {
        if (c5_x4[0] <= c5_x4[1]) {
          c5_perm[0] = 1;
          c5_perm[1] = 2;
        } else {
          c5_perm[0] = 2;
          c5_perm[1] = 1;
        }
      } else if (c5_x4[0] <= c5_x4[1]) {
        if (c5_x4[1] <= c5_x4[2]) {
          c5_perm[0] = 1;
          c5_perm[1] = 2;
          c5_perm[2] = 3;
        } else if (c5_x4[0] <= c5_x4[2]) {
          c5_perm[0] = 1;
          c5_perm[1] = 3;
          c5_perm[2] = 2;
        } else {
          c5_perm[0] = 3;
          c5_perm[1] = 1;
          c5_perm[2] = 2;
        }
      } else if (c5_x4[0] <= c5_x4[2]) {
        c5_perm[0] = 2;
        c5_perm[1] = 1;
        c5_perm[2] = 3;
      } else if (c5_x4[1] <= c5_x4[2]) {
        c5_perm[0] = 2;
        c5_perm[1] = 3;
        c5_perm[2] = 1;
      } else {
        c5_perm[0] = 3;
        c5_perm[1] = 2;
        c5_perm[2] = 1;
      }

      c5_c_st.site = &c5_ld_emlrtRSI;
      c5_h_b = c5_ib;
      c5_i_b = c5_h_b;
      if (c5_i_b < 1) {
        c5_c_overflow = false;
      } else {
        c5_c_overflow = (c5_i_b > 2147483646);
      }

      if (c5_c_overflow) {
        c5_d_st.site = &c5_s_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
      }

      c5_i7 = (uint8_T)c5_ib - 1;
      for (c5_d_k = 0; c5_d_k <= c5_i7; c5_d_k++) {
        c5_b_k = c5_d_k;
        c5_idx_data[((c5_wOffset - c5_ib) + c5_b_k) + 1] =
          c5_idx4[c5_perm[c5_b_k] - 1];
        c5_c_x_data[((c5_wOffset - c5_ib) + c5_b_k) + 1] = c5_x4[c5_perm[c5_b_k]
          - 1];
      }
    }

    c5_m = c5_nNaNs >> 1;
    c5_c_st.site = &c5_md_emlrtRSI;
    c5_f_b = c5_m;
    c5_g_b = c5_f_b;
    if (c5_g_b < 1) {
      c5_b_overflow = false;
    } else {
      c5_b_overflow = (c5_g_b > 2147483646);
    }

    if (c5_b_overflow) {
      c5_d_st.site = &c5_s_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
    }

    for (c5_c_k = 0; c5_c_k < c5_m; c5_c_k++) {
      c5_b_k = c5_c_k + 1;
      c5_itmp = c5_idx_data[c5_wOffset + c5_b_k];
      c5_idx_data[c5_wOffset + c5_b_k] = c5_idx_data[c5_b_n - c5_b_k];
      c5_idx_data[c5_b_n - c5_b_k] = c5_itmp;
      c5_c_x_data[c5_wOffset + c5_b_k] = chartInstance->c5_xwork_data[c5_b_n -
        c5_b_k];
      c5_c_x_data[c5_b_n - c5_b_k] = chartInstance->c5_xwork_data[c5_wOffset +
        c5_b_k];
    }

    if ((c5_nNaNs & 1) != 0) {
      c5_c_x_data[(c5_wOffset + c5_m) + 1] = chartInstance->c5_xwork_data
        [(c5_wOffset + c5_m) + 1];
    }

    c5_nNonNaN = c5_n - c5_nNaNs;
    c5_preSortLevel = 2;
    if (c5_nNonNaN > 1) {
      if (c5_n >= 256) {
        c5_nBlocks = c5_nNonNaN >> 8;
        if (c5_nBlocks > 0) {
          c5_b_st.site = &c5_gd_emlrtRSI;
          c5_j_b = c5_nBlocks;
          c5_k_b = c5_j_b;
          if (c5_k_b < 1) {
            c5_d_overflow = false;
          } else {
            c5_d_overflow = (c5_k_b > 2147483646);
          }

          if (c5_d_overflow) {
            c5_c_st.site = &c5_s_emlrtRSI;
            c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
          }

          for (c5_l_b = 0; c5_l_b < c5_nBlocks; c5_l_b++) {
            c5_m_b = c5_l_b;
            c5_b_st.site = &c5_hd_emlrtRSI;
            c5_b_merge_pow2_block(chartInstance, &c5_b_st, c5_idx_data,
                                  c5_c_x_data, c5_m_b << 8);
          }

          c5_tailOffset = c5_nBlocks << 8;
          c5_nLastBlock = c5_nNonNaN - c5_tailOffset;
          if (c5_nLastBlock > 0) {
            c5_b_st.site = &c5_id_emlrtRSI;
            c5_b_merge_block(chartInstance, &c5_b_st, c5_idx_data, c5_c_x_data,
                             c5_tailOffset, c5_nLastBlock, 2,
                             chartInstance->c5_iwork_data,
                             chartInstance->c5_xwork_data);
          }

          c5_preSortLevel = 8;
        }
      }

      c5_b_st.site = &c5_jd_emlrtRSI;
      c5_b_merge_block(chartInstance, &c5_b_st, c5_idx_data, c5_c_x_data, 0,
                       c5_nNonNaN, c5_preSortLevel, chartInstance->c5_iwork_data,
                       chartInstance->c5_xwork_data);
    }
  }
}

static void c5_b_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_idx_data[], real_T
  c5_c_x_data[], int32_T c5_offset)
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_xwork[256];
  int32_T c5_iwork[256];
  int32_T c5_bLen;
  int32_T c5_bLen2;
  int32_T c5_b_j;
  int32_T c5_b_k;
  int32_T c5_blockOffset;
  int32_T c5_c_b;
  int32_T c5_c_j;
  int32_T c5_d_a;
  int32_T c5_d_b;
  int32_T c5_e_a;
  int32_T c5_e_b;
  int32_T c5_exitg1;
  int32_T c5_f_b;
  int32_T c5_g_b;
  int32_T c5_h_b;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i_b;
  int32_T c5_iout;
  int32_T c5_j;
  int32_T c5_k;
  int32_T c5_nPairs;
  int32_T c5_offset1;
  int32_T c5_p;
  int32_T c5_q;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  for (c5_c_b = 0; c5_c_b < 6; c5_c_b++) {
    c5_bLen = 1 << (c5_c_b + 2);
    c5_bLen2 = c5_bLen << 1;
    c5_nPairs = 256 >> (c5_c_b + 3);
    c5_st.site = &c5_nd_emlrtRSI;
    c5_d_b = c5_nPairs;
    c5_e_b = c5_d_b;
    if (c5_e_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_e_b > 2147483646);
    }

    if (c5_overflow) {
      c5_b_st.site = &c5_s_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    c5_i = (uint8_T)c5_nPairs - 1;
    for (c5_k = 0; c5_k <= c5_i; c5_k++) {
      c5_b_k = c5_k;
      c5_blockOffset = (c5_offset + c5_b_k * c5_bLen2) - 1;
      c5_st.site = &c5_od_emlrtRSI;
      c5_f_b = c5_bLen2;
      c5_g_b = c5_f_b;
      if (c5_g_b < 1) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_g_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_b_st.site = &c5_s_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
      }

      c5_i1 = (uint16_T)c5_bLen2 - 1;
      for (c5_j = 0; c5_j <= c5_i1; c5_j++) {
        c5_b_j = c5_j;
        c5_iwork[c5_b_j] = c5_idx_data[(c5_blockOffset + c5_b_j) + 1];
        c5_xwork[c5_b_j] = c5_c_x_data[(c5_blockOffset + c5_b_j) + 1];
      }

      c5_p = 0;
      c5_q = c5_bLen;
      c5_iout = c5_blockOffset;
      do {
        c5_exitg1 = 0;
        c5_iout++;
        if (c5_xwork[c5_p] <= c5_xwork[c5_q]) {
          c5_idx_data[c5_iout] = c5_iwork[c5_p];
          c5_c_x_data[c5_iout] = c5_xwork[c5_p];
          if (c5_p + 1 < c5_bLen) {
            c5_p++;
          } else {
            c5_exitg1 = 1;
          }
        } else {
          c5_idx_data[c5_iout] = c5_iwork[c5_q];
          c5_c_x_data[c5_iout] = c5_xwork[c5_q];
          if (c5_q + 1 < c5_bLen2) {
            c5_q++;
          } else {
            c5_offset1 = c5_iout - c5_p;
            c5_st.site = &c5_pd_emlrtRSI;
            c5_d_a = c5_p + 1;
            c5_h_b = c5_bLen;
            c5_e_a = c5_d_a;
            c5_i_b = c5_h_b;
            if (c5_e_a > c5_i_b) {
              c5_c_overflow = false;
            } else {
              c5_c_overflow = (c5_i_b > 2147483646);
            }

            if (c5_c_overflow) {
              c5_b_st.site = &c5_s_emlrtRSI;
              c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
            }

            for (c5_c_j = c5_p + 1; c5_c_j <= c5_bLen; c5_c_j++) {
              c5_idx_data[c5_offset1 + c5_c_j] = c5_iwork[c5_c_j - 1];
              c5_c_x_data[c5_offset1 + c5_c_j] = c5_xwork[c5_c_j - 1];
            }

            c5_exitg1 = 1;
          }
        }
      } while (c5_exitg1 == 0);
    }
  }
}

static void c5_b_merge_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_idx_data[], real_T
  c5_c_x_data[], int32_T c5_offset, int32_T c5_n, int32_T c5_preSortLevel,
  int32_T c5_b_iwork_data[], real_T c5_b_xwork_data[])
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  int32_T c5_bLen;
  int32_T c5_bLen2;
  int32_T c5_b_k;
  int32_T c5_c_b;
  int32_T c5_d_b;
  int32_T c5_k;
  int32_T c5_nBlocks;
  int32_T c5_nPairs;
  int32_T c5_nTail;
  int32_T c5_tailOffset;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_nBlocks = c5_n >> c5_preSortLevel;
  c5_bLen = 1 << c5_preSortLevel;
  while (c5_nBlocks > 1) {
    if ((c5_nBlocks & 1) != 0) {
      c5_nBlocks--;
      c5_tailOffset = c5_bLen * c5_nBlocks;
      c5_nTail = c5_n - c5_tailOffset;
      if (c5_nTail > c5_bLen) {
        c5_st.site = &c5_qd_emlrtRSI;
        c5_b_merge(chartInstance, &c5_st, c5_idx_data, c5_c_x_data, c5_offset +
                   c5_tailOffset, c5_bLen, c5_nTail - c5_bLen, c5_b_iwork_data,
                   c5_b_xwork_data);
      }
    }

    c5_bLen2 = c5_bLen << 1;
    c5_nPairs = c5_nBlocks >> 1;
    c5_st.site = &c5_rd_emlrtRSI;
    c5_c_b = c5_nPairs;
    c5_d_b = c5_c_b;
    if (c5_d_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_d_b > 2147483646);
    }

    if (c5_overflow) {
      c5_b_st.site = &c5_s_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_k = 0; c5_k < c5_nPairs; c5_k++) {
      c5_b_k = c5_k;
      c5_st.site = &c5_sd_emlrtRSI;
      c5_b_merge(chartInstance, &c5_st, c5_idx_data, c5_c_x_data, c5_offset +
                 c5_b_k * c5_bLen2, c5_bLen, c5_bLen, c5_b_iwork_data,
                 c5_b_xwork_data);
    }

    c5_bLen = c5_bLen2;
    c5_nBlocks = c5_nPairs;
  }

  if (c5_n > c5_bLen) {
    c5_st.site = &c5_td_emlrtRSI;
    c5_b_merge(chartInstance, &c5_st, c5_idx_data, c5_c_x_data, c5_offset,
               c5_bLen, c5_n - c5_bLen, c5_b_iwork_data, c5_b_xwork_data);
  }
}

static void c5_b_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, int32_T c5_idx_data[], real_T c5_c_x_data[], int32_T
  c5_offset, int32_T c5_np, int32_T c5_nq, int32_T c5_b_iwork_data[], real_T
  c5_b_xwork_data[])
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  int32_T c5_b_j;
  int32_T c5_c_b;
  int32_T c5_c_j;
  int32_T c5_d_a;
  int32_T c5_d_b;
  int32_T c5_e_a;
  int32_T c5_e_b;
  int32_T c5_exitg1;
  int32_T c5_f_b;
  int32_T c5_iout;
  int32_T c5_j;
  int32_T c5_n;
  int32_T c5_offset1;
  int32_T c5_p;
  int32_T c5_q;
  int32_T c5_qend;
  boolean_T c5_b_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  if (c5_nq != 0) {
    c5_n = c5_np + c5_nq;
    c5_st.site = &c5_vd_emlrtRSI;
    c5_c_b = c5_n;
    c5_d_b = c5_c_b;
    if (c5_d_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_d_b > 2147483646);
    }

    if (c5_overflow) {
      c5_b_st.site = &c5_s_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_j = 0; c5_j < c5_n; c5_j++) {
      c5_b_j = c5_j;
      c5_b_iwork_data[c5_b_j] = c5_idx_data[c5_offset + c5_b_j];
      c5_b_xwork_data[c5_b_j] = c5_c_x_data[c5_offset + c5_b_j];
    }

    c5_p = 0;
    c5_q = c5_np;
    c5_qend = c5_np + c5_nq;
    c5_iout = c5_offset - 1;
    do {
      c5_exitg1 = 0;
      c5_iout++;
      if (c5_b_xwork_data[c5_p] <= c5_b_xwork_data[c5_q]) {
        c5_idx_data[c5_iout] = c5_b_iwork_data[c5_p];
        c5_c_x_data[c5_iout] = c5_b_xwork_data[c5_p];
        if (c5_p + 1 < c5_np) {
          c5_p++;
        } else {
          c5_exitg1 = 1;
        }
      } else {
        c5_idx_data[c5_iout] = c5_b_iwork_data[c5_q];
        c5_c_x_data[c5_iout] = c5_b_xwork_data[c5_q];
        if (c5_q + 1 < c5_qend) {
          c5_q++;
        } else {
          c5_offset1 = c5_iout - c5_p;
          c5_st.site = &c5_ud_emlrtRSI;
          c5_d_a = c5_p + 1;
          c5_e_b = c5_np;
          c5_e_a = c5_d_a;
          c5_f_b = c5_e_b;
          if (c5_e_a > c5_f_b) {
            c5_b_overflow = false;
          } else {
            c5_b_overflow = (c5_f_b > 2147483646);
          }

          if (c5_b_overflow) {
            c5_b_st.site = &c5_s_emlrtRSI;
            c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
          }

          for (c5_c_j = c5_p + 1; c5_c_j <= c5_np; c5_c_j++) {
            c5_idx_data[c5_offset1 + c5_c_j] = c5_b_iwork_data[c5_c_j - 1];
            c5_c_x_data[c5_offset1 + c5_c_j] = c5_b_xwork_data[c5_c_j - 1];
          }

          c5_exitg1 = 1;
        }
      }
    } while (c5_exitg1 == 0);
  }
}

static void c5_d_sort(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T c5_c_x_data[], int32_T
                      c5_x_size[1], int32_T c5_idx_data[], int32_T c5_idx_size[1])
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  real_T c5_b_vwork_data[40];
  real_T c5_b_dv[2];
  real_T c5_d;
  real_T c5_d1;
  int32_T c5_c_iidx_data[40];
  int32_T c5_iv[2];
  int32_T c5_b_x_size[1];
  int32_T c5_iidx_size[1];
  int32_T c5_vwork_size[1];
  int32_T c5_b_dim;
  int32_T c5_b_i;
  int32_T c5_b_j;
  int32_T c5_b_k;
  int32_T c5_b_loop_ub;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_dim;
  int32_T c5_e_b;
  int32_T c5_f_b;
  int32_T c5_g_b;
  int32_T c5_h_b;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i_b;
  int32_T c5_j;
  int32_T c5_j_b;
  int32_T c5_k;
  int32_T c5_loop_ub;
  int32_T c5_upperDim;
  int32_T c5_vlen;
  int32_T c5_vstride;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_d_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_b_x_size[0] = c5_x_size[0];
  c5_dim = 2;
  if ((real_T)c5_b_x_size[0] != 1.0) {
    c5_dim = 1;
  }

  if (c5_dim <= 1) {
    c5_d = (real_T)c5_x_size[0];
  } else {
    c5_d = 1.0;
  }

  c5_vlen = (int32_T)c5_d;
  c5_iv[0] = c5_vlen;
  c5_vwork_size[0] = c5_iv[0];
  c5_b_dv[0] = (real_T)c5_x_size[0];
  c5_idx_size[0] = (int32_T)c5_b_dv[0];
  c5_st.site = &c5_wc_emlrtRSI;
  c5_b_x_size[0] = c5_x_size[0];
  c5_b_dim = c5_dim - 1;
  c5_vstride = 1;
  c5_upperDim = c5_b_dim;
  c5_b_st.site = &c5_dd_emlrtRSI;
  c5_c_b = c5_upperDim;
  c5_d_b = c5_c_b;
  if (c5_d_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_d_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_s_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  c5_i = (uint8_T)c5_upperDim - 1;
  for (c5_k = 0; c5_k <= c5_i; c5_k++) {
    c5_d1 = (real_T)c5_b_x_size[0];
    c5_vstride *= (int32_T)c5_d1;
  }

  c5_st.site = &c5_xc_emlrtRSI;
  for (c5_b_i = 0; c5_b_i < 1; c5_b_i++) {
    c5_st.site = &c5_yc_emlrtRSI;
    c5_e_b = c5_vstride;
    c5_f_b = c5_e_b;
    if (c5_f_b < 1) {
      c5_b_overflow = false;
    } else {
      c5_b_overflow = (c5_f_b > 2147483646);
    }

    if (c5_b_overflow) {
      c5_b_st.site = &c5_s_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_j = 0; c5_j < c5_vstride; c5_j++) {
      c5_b_j = c5_j;
      c5_st.site = &c5_ad_emlrtRSI;
      c5_g_b = c5_vlen;
      c5_h_b = c5_g_b;
      if (c5_h_b < 1) {
        c5_c_overflow = false;
      } else {
        c5_c_overflow = (c5_h_b > 2147483646);
      }

      if (c5_c_overflow) {
        c5_b_st.site = &c5_s_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
      }

      c5_i1 = (uint8_T)c5_vlen - 1;
      for (c5_b_k = 0; c5_b_k <= c5_i1; c5_b_k++) {
        c5_c_k = c5_b_k;
        c5_b_vwork_data[c5_c_k] = c5_c_x_data[c5_b_j + c5_c_k * c5_vstride];
      }

      c5_b_x_size[0] = c5_vwork_size[0];
      c5_loop_ub = c5_vwork_size[0] - 1;
      for (c5_i2 = 0; c5_i2 <= c5_loop_ub; c5_i2++) {
        chartInstance->c5_x_data[c5_i2] = c5_b_vwork_data[c5_i2];
      }

      c5_st.site = &c5_bd_emlrtRSI;
      c5_b_sortIdx(chartInstance, &c5_st, chartInstance->c5_x_data, c5_b_x_size,
                   chartInstance->c5_iidx_data, c5_iidx_size);
      c5_b_loop_ub = c5_iidx_size[0] - 1;
      for (c5_i3 = 0; c5_i3 <= c5_b_loop_ub; c5_i3++) {
        c5_c_iidx_data[c5_i3] = chartInstance->c5_iidx_data[c5_i3];
      }

      c5_vwork_size[0] = c5_b_x_size[0];
      c5_c_loop_ub = c5_b_x_size[0] - 1;
      for (c5_i4 = 0; c5_i4 <= c5_c_loop_ub; c5_i4++) {
        c5_b_vwork_data[c5_i4] = chartInstance->c5_x_data[c5_i4];
      }

      c5_st.site = &c5_cd_emlrtRSI;
      c5_i_b = c5_vlen;
      c5_j_b = c5_i_b;
      if (c5_j_b < 1) {
        c5_d_overflow = false;
      } else {
        c5_d_overflow = (c5_j_b > 2147483646);
      }

      if (c5_d_overflow) {
        c5_b_st.site = &c5_s_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
      }

      c5_i5 = (uint8_T)c5_vlen - 1;
      for (c5_d_k = 0; c5_d_k <= c5_i5; c5_d_k++) {
        c5_c_k = c5_d_k;
        c5_c_x_data[c5_b_j + c5_c_k * c5_vstride] = c5_b_vwork_data[c5_c_k];
        c5_idx_data[c5_b_j + c5_c_k * c5_vstride] = c5_c_iidx_data[c5_c_k];
      }
    }
  }
}

static void c5_plus(SFc5_flightControlSystemInstanceStruct *chartInstance,
                    real_T c5_b_in1_data[], int32_T c5_in1_size[1], real_T
                    c5_in2_data[], int32_T c5_in2_size[1])
{
  int32_T c5_b_in1_size[1];
  int32_T c5_aux_0_0;
  int32_T c5_aux_1_0;
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_loop_ub;
  int32_T c5_stride_0_0;
  int32_T c5_stride_1_0;
  if (c5_in2_size[0] == 1) {
    c5_b_in1_size[0] = c5_in1_size[0];
  } else {
    c5_b_in1_size[0] = c5_in2_size[0];
  }

  c5_stride_0_0 = (c5_in1_size[0] != 1);
  c5_stride_1_0 = (c5_in2_size[0] != 1);
  c5_aux_0_0 = 0;
  c5_aux_1_0 = 0;
  if (c5_in2_size[0] == 1) {
    c5_i = c5_in1_size[0];
  } else {
    c5_i = c5_in2_size[0];
  }

  c5_loop_ub = c5_i - 1;
  for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
    chartInstance->c5_in1_data[c5_i1] = c5_b_in1_data[c5_aux_0_0] +
      c5_in2_data[c5_aux_1_0];
    c5_aux_1_0 += c5_stride_1_0;
    c5_aux_0_0 += c5_stride_0_0;
  }

  c5_in1_size[0] = c5_b_in1_size[0];
  c5_b_loop_ub = c5_b_in1_size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_b_loop_ub; c5_i2++) {
    c5_b_in1_data[c5_i2] = chartInstance->c5_in1_data[c5_i2];
  }
}

static void init_dsm_address_info(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c5_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c5_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c5_b_u = (boolean_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_b_outt = (uint8_T (*)[57600])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_distX = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c5_distY = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c5_dom_x = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c5_dom_y = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c5_pointsx = (real_T (*)[40])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c5_pointsy = (real_T (*)[40])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c5_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3834625758U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(144727168U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3164325208U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(495428723U);
}

mxArray *sf_c5_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,5);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Bwlookup_tbb_Buildable"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.lapack.LAPACKApi"));
  mxSetCell(mxcell3p, 2, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  return(mxcell3p);
}

mxArray *sf_c5_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("bwlookup_tbb_boolean");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c5_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD24GBgYAPSQIqBiQECWKF8RiDmhNIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Cs4oOtnwaKfFUm/AJSfkllcEgENH1g4DZw/lC"
    "jyR+Sg8YcG+f7Iz42vGDT+0KLIH5WDxh8iYH8YEPAHC4o/WBjyS0tKBof7VYiKB3a0eADxC/Iz8"
    "0qKKwZJPKhR6I9KKvlDwIEy/RD7HQj4gwvNHyB+cmJOTnxyfmleCcKcCwz46yVGtHqJCcoH6clh"
    "yGQowOIebP5hQvOPAMwzDSEOEEY4VcKF8vhRoIo7AgjEjwJa/ID4mcXxicklmWWp8cmm8Wk5mek"
    "ZJc75eSVF+TnBlcUlqbkw/wEA0ZpJkw=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sIe3QndMbnhst5E081F6wvD";
}

static void sf_opaque_initialize_c5_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c5_flightControlSystem
    ((SFc5_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_flightControlSystem(void *chartInstanceVar)
{
  enable_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_flightControlSystem(void *chartInstanceVar)
{
  disable_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c5_flightControlSystem
    ((SFc5_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c5_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c5_flightControlSystem
      ((SFc5_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c5_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc5_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c5_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_flightControlSystem
      ((SFc5_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc5_flightControlSystem
      ((SFc5_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c5_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [23] = {
    "eNrlWc1v40QUn0Ztd1tB1QOCywoqBGiFhLRoWdQDWtrNB0RqaSDpLnApU/slHnU8485HmnDizoG",
    "/hzsHjnDjxr/AcY+8sZ1scE3rSYo2u1hynLHzm/d+b97XOGSlfUjw2MJz9CYh63i9jWeNZMdaPl",
    "6ZObP7q+STfPzrJiGBDGEAomv7fTYifoewcYcqGmvifwgaw1egJbeGSdEWfVkdy0QfFIgAJ0ikM",
    "l5yNYstZ+KsZUXgJOsnEQuibiQtDx/hhDQ8Enz8b3ITazooscEUBKYFEJpISTuIWpwOrraCMhf1",
    "CIIzbWNvW2kwXZs4qvrQcsMSDs0RBG2hDUUr6Gv4dg01UDcjPyM7vro7Qcs44YyK6raOqO5Cgt5",
    "h4DgJ8fPIGrReRbko75QJaqRilDdjXo+oqortcNTzEN2ae9vZxKYBp3YwYGLgrKtsDAL5o59UsF",
    "W/Loeg6ACOhJ/cwLFrjtIFnvplRaxhMTymaj9AP9AQ+sUgOrDuUlxa6OE0XlgQ9JRDW/cUG+Ia+",
    "eaNtgulufKGjTNP0nNhU7nNIa6qnlNuKxB1yrn2w/ZkcgBD4Kn8BjV0Dmwm3wOsNQt7Er3DRa5n",
    "9FvBzi3k2LoUIavulcMCKi0SX2DCrwBnsQsDCNHMU9WnE10XR1YbGdcx9BsHBxXlXca2hQHVpwF",
    "UzteKMg2ocOpXnnJDpl0gIRqtZFKWlWfIYnAuKNF9KxoXUp2hjX0LwzNbuUjwQ0M4gAYYSJNcE7",
    "37MeW2os6xxqzs3ONYY5b1k4tYFz9zgQMaRBC6Gsg4HGKexQmqLrF25XMf2Q6ZGTdAB4olVSPJY",
    "kLH4ues1BsncCzOhLwQLSXjbt7FXOFXAJg1qBJYyh5hKVXjFipfTWsF5700u/s2DM7O1HB66nzj",
    "MxBYDR1XV71pgFHVFNhuokKLYLvse2xHhGbaYAs4bqYxEKZ98OfkWR+8WtIHvz7TB2/n4+DBSZ+",
    "zQeSSjFGSd8c4b5z11fdm5nulQl896cevwpFLODLFTa53Z/ArJXLJzLUob6N2tZ41/LaS4/ZmcK",
    "8W5KwWcOu5zf78efe74/NfzI8fvftT7azz+yLyn97227ds5eM7k55pmqGHl5JYFX94o+APbqzbc",
    "P9LER6eikibB817ux+2Pr4YNrL5rtF3o6Dv5P6O69MwgNN8oIJ2mO9/3JjarC938+/O6Lt+jT02",
    "ZvyJkL8+XQy/s1fEl9lrrWCvtax+ma8L/vv8eLy9EI9vlobH3fl5yPhktDQ83l+Ix3hpeLy2V8x",
    "zZTxW/8FjlUhrzHLo/06ldbhVWAc3TiTDvdJoSdbhvQV5jG+Ix/beYvjL9beMx2aBx2bai3J+Ek",
    "g7eRXj5vmN+NXRWj52GE4YSUr0KeNTK/DZnpD5obeXfXlyI3ZZfH12bkSPzjXrs1NYn530PdAJd",
    "d0+nJR3lls30Lf54shLjlv5H/Krsh+ZF3eL/Hf7n5vELcrPd5/1ov/+qv6FFH6/vcQ8itd599vL",
    "xusPzzr+Vj5+OH3XW48YD0veNuWPD4D2y56+JP791NN+k/1/09kv/4Pt2/v7gvKxZtmrssntjnL",
    "/7UwfKaC6/B3e86gnZf1S1X3Wca/1we4Cdelvdf42eA==",
    ""
  };

  static char newstr [1621] = "";
  newstr[0] = '\0';
  for (i = 0; i < 23; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c5_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c5_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1614330335U));
  ssSetChecksum1(S,(1959031125U));
  ssSetChecksum2(S,(2401580171U));
  ssSetChecksum3(S,(3511708418U));
}

static void mdlRTW_c5_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c5_flightControlSystem(SimStruct *S)
{
  SFc5_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc5_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc5_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && sfHasContStates(S)> 0 &&
      !supportsLegacyBehaviorForPersistentVarInContinuousTime(S)) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c5_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c5_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c5_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c5_flightControlSystem(chartInstance);
}

void c5_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c5_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
