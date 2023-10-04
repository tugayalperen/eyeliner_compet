/* Include files */

#include "flightControlSystem_sfun.h"
#include "c3_flightControlSystem.h"
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
static emlrtMCInfo c3_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c3_b_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtMCInfo c3_c_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtMCInfo c3_d_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c3_e_emlrtMCI = { 47,/* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pName */
};

static emlrtMCInfo c3_f_emlrtMCI = { 158,/* lineNo */
  17,                                  /* colNo */
  "eml_rand_mt19937ar",                /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"/* pName */
};

static emlrtMCInfo c3_g_emlrtMCI = { 28,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c3_h_emlrtMCI = { 130,/* lineNo */
  19,                                  /* colNo */
  "interp1",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pName */
};

static emlrtMCInfo c3_i_emlrtMCI = { 139,/* lineNo */
  23,                                  /* colNo */
  "interp1",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pName */
};

static emlrtMCInfo c3_j_emlrtMCI = { 166,/* lineNo */
  13,                                  /* colNo */
  "interp1",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pName */
};

static emlrtMCInfo c3_k_emlrtMCI = { 208,/* lineNo */
  13,                                  /* colNo */
  "interp1",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pName */
};

static emlrtRSInfo c3_emlrtRSI = { 77, /* lineNo */
  "bwmorph",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/images/images/eml/bwmorph.m"/* pathName */
};

static emlrtRSInfo c3_b_emlrtRSI = { 24,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c3_c_emlrtRSI = { 109,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c3_d_emlrtRSI = { 145,/* lineNo */
  "bwlookup",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/images/images/eml/bwlookup.m"/* pathName */
};

static emlrtRSInfo c3_e_emlrtRSI = { 33,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c3_f_emlrtRSI = { 322,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c3_g_emlrtRSI = { 325,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c3_h_emlrtRSI = { 281,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c3_i_emlrtRSI = { 289,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c3_j_emlrtRSI = { 295,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c3_k_emlrtRSI = { 301,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c3_l_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c3_m_emlrtRSI = { 138,/* lineNo */
  "find",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c3_n_emlrtRSI = { 255,/* lineNo */
  "find",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c3_o_emlrtRSI = { 254,/* lineNo */
  "find",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c3_p_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c3_q_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c3_r_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo c3_s_emlrtRSI = { 16,/* lineNo */
  "sqrt",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

static emlrtRSInfo c3_t_emlrtRSI = { 33,/* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo c3_u_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c3_v_emlrtRSI = { 13,/* lineNo */
  "all",                               /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/all.m"/* pathName */
};

static emlrtRSInfo c3_w_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pathName */
};

static emlrtRSInfo c3_x_emlrtRSI = { 37,/* lineNo */
  "sort",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/sort.m"/* pathName */
};

static emlrtRSInfo c3_y_emlrtRSI = { 76,/* lineNo */
  "sort",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c3_ab_emlrtRSI = { 79,/* lineNo */
  "sort",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c3_bb_emlrtRSI = { 81,/* lineNo */
  "sort",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c3_cb_emlrtRSI = { 84,/* lineNo */
  "sort",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c3_db_emlrtRSI = { 87,/* lineNo */
  "sort",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c3_eb_emlrtRSI = { 90,/* lineNo */
  "sort",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c3_fb_emlrtRSI = { 55,/* lineNo */
  "prodsize",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/lib/+coder/+internal/prodsize.m"/* pathName */
};

static emlrtRSInfo c3_gb_emlrtRSI = { 105,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_hb_emlrtRSI = { 308,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_ib_emlrtRSI = { 316,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_jb_emlrtRSI = { 317,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_kb_emlrtRSI = { 325,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_lb_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_mb_emlrtRSI = { 392,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_nb_emlrtRSI = { 420,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_ob_emlrtRSI = { 427,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_pb_emlrtRSI = { 587,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_qb_emlrtRSI = { 589,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_rb_emlrtRSI = { 617,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_sb_emlrtRSI = { 499,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_tb_emlrtRSI = { 506,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_ub_emlrtRSI = { 507,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_vb_emlrtRSI = { 514,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_wb_emlrtRSI = { 561,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_xb_emlrtRSI = { 530,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_yb_emlrtRSI = { 74,/* lineNo */
  "issorted",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/issorted.m"/* pathName */
};

static emlrtRSInfo c3_ac_emlrtRSI = { 112,/* lineNo */
  "issorted",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/issorted.m"/* pathName */
};

static emlrtRSInfo c3_bc_emlrtRSI = { 95,/* lineNo */
  "issorted",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/issorted.m"/* pathName */
};

static emlrtRSInfo c3_cc_emlrtRSI = { 119,/* lineNo */
  "randn",                             /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/randn.m"/* pathName */
};

static emlrtRSInfo c3_dc_emlrtRSI = { 40,/* lineNo */
  "eml_randn",                         /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/private/eml_randn.m"/* pathName */
};

static emlrtRSInfo c3_ec_emlrtRSI = { 45,/* lineNo */
  "eml_rand",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/private/eml_rand.m"/* pathName */
};

static emlrtRSInfo c3_fc_emlrtRSI = { 39,/* lineNo */
  "eml_rand_mt19937ar_stateful",       /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/private/eml_rand_mt19937ar_stateful.m"/* pathName */
};

static emlrtRSInfo c3_gc_emlrtRSI = { 56,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c3_hc_emlrtRSI = { 438,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c3_ic_emlrtRSI = { 447,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c3_jc_emlrtRSI = { 449,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c3_kc_emlrtRSI = { 48,/* lineNo */
  "string",                            /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/lib/+coder/+internal/string.m"/* pathName */
};

static emlrtRSInfo c3_lc_emlrtRSI = { 38,/* lineNo */
  "fprintf",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/iofun/fprintf.m"/* pathName */
};

static emlrtRSInfo c3_mc_emlrtRSI = { 66,/* lineNo */
  "fprintf",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/iofun/fprintf.m"/* pathName */
};

static emlrtRSInfo c3_nc_emlrtRSI = { 15,/* lineNo */
  "min",                               /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

static emlrtRSInfo c3_oc_emlrtRSI = { 46,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c3_pc_emlrtRSI = { 92,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c3_qc_emlrtRSI = { 15,/* lineNo */
  "max",                               /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo c3_rc_emlrtRSI = { 44,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c3_sc_emlrtRSI = { 79,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c3_tc_emlrtRSI = { 54,/* lineNo */
  "interp1",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pathName */
};

static emlrtRSInfo c3_uc_emlrtRSI = { 202,/* lineNo */
  "interp1",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pathName */
};

static emlrtRSInfo c3_vc_emlrtRSI = { 194,/* lineNo */
  "interp1",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pathName */
};

static emlrtRSInfo c3_wc_emlrtRSI = { 164,/* lineNo */
  "interp1",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pathName */
};

static emlrtRSInfo c3_xc_emlrtRSI = { 37,/* lineNo */
  "flip",                              /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/flip.m"/* pathName */
};

static emlrtRSInfo c3_yc_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/matfun/mpower.m"/* pathName */
};

static emlrtRSInfo c3_ad_emlrtRSI = { 9,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_bd_emlrtRSI = { 12,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_cd_emlrtRSI = { 17,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_dd_emlrtRSI = { 27,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_ed_emlrtRSI = { 40,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_fd_emlrtRSI = { 41,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_gd_emlrtRSI = { 50,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_hd_emlrtRSI = { 51,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_id_emlrtRSI = { 68,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_jd_emlrtRSI = { 71,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_kd_emlrtRSI = { 72,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_ld_emlrtRSI = { 88,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_md_emlrtRSI = { 92,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_nd_emlrtRSI = { 97,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_od_emlrtRSI = { 98,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_pd_emlrtRSI = { 103,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_qd_emlrtRSI = { 105,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_rd_emlrtRSI = { 121,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_sd_emlrtRSI = { 122,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_td_emlrtRSI = { 146,/* lineNo */
  "Image Processing System/new_version",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRTEInfo c3_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_b_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_c_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_d_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_e_emlrtRTEI = { 50,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_f_emlrtRTEI = { 50,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_g_emlrtRTEI = { 40,/* lineNo */
  30,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_h_emlrtRTEI = { 51,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_i_emlrtRTEI = { 40,/* lineNo */
  66,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_j_emlrtRTEI = { 51,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_k_emlrtRTEI = { 41,/* lineNo */
  16,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_l_emlrtRTEI = { 68,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_m_emlrtRTEI = { 68,/* lineNo */
  54,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_n_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/sort.m"/* pName */
};

static emlrtRTEInfo c3_o_emlrtRTEI = { 72,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_p_emlrtRTEI = { 78,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_q_emlrtRTEI = { 78,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_r_emlrtRTEI = { 79,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_s_emlrtRTEI = { 79,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_t_emlrtRTEI = { 93,/* lineNo */
  18,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_u_emlrtRTEI = { 93,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_v_emlrtRTEI = { 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_w_emlrtRTEI = { 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_x_emlrtRTEI = { 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_y_emlrtRTEI = { 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_ab_emlrtRTEI = { 71,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo c3_bb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "sqrt",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRTEInfo c3_cb_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_db_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_eb_emlrtRTEI = { 572,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_fb_emlrtRTEI = { 482,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_gb_emlrtRTEI = { 520,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_hb_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "isinf",                             /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/isinf.m"/* pName */
};

static emlrtRTEInfo c3_ib_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "isnan",                             /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/isnan.m"/* pName */
};

static emlrtRTEInfo c3_jb_emlrtRTEI = { 34,/* lineNo */
  42,                                  /* colNo */
  "issorted",                          /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/issorted.m"/* pName */
};

static emlrtRTEInfo c3_kb_emlrtRTEI = { 55,/* lineNo */
  9,                                   /* colNo */
  "interp1",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pName */
};

static emlrtRTEInfo c3_lb_emlrtRTEI = { 55,/* lineNo */
  33,                                  /* colNo */
  "interp1",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pName */
};

static emlrtRTEInfo c3_mb_emlrtRTEI = { 12,/* lineNo */
  37,                                  /* colNo */
  "sqrt",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRTEInfo c3_nb_emlrtRTEI = { 30,/* lineNo */
  42,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_ob_emlrtRTEI = { 56,/* lineNo */
  24,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_pb_emlrtRTEI = { 75,/* lineNo */
  26,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_qb_emlrtRTEI = { 76,/* lineNo */
  39,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_rb_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_sb_emlrtRTEI = { 267,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_tb_emlrtRTEI = { 385,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_ub_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_vb_emlrtRTEI = { 274,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_wb_emlrtRTEI = { 387,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_xb_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_yb_emlrtRTEI = { 87,/* lineNo */
  13,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_ac_emlrtRTEI = { 87,/* lineNo */
  14,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_bc_emlrtRTEI = { 87,/* lineNo */
  19,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_cc_emlrtRTEI = { 40,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_dc_emlrtRTEI = { 40,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_ec_emlrtRTEI = { 34,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtBCInfo c3_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  40,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_emlrtDCI = { 40, /* lineNo */
  42,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  42,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  76,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_b_emlrtDCI = { 40,/* lineNo */
  78,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  78,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c3_emlrtECI = { 1,  /* nDims */
  40,                                  /* lineNo */
  29,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtBCInfo c3_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_c_emlrtDCI = { 50,/* lineNo */
  25,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  25,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_d_emlrtDCI = { 51,/* lineNo */
  25,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  25,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c3_b_emlrtECI = { 1,/* nDims */
  68,                                  /* lineNo */
  26,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtBCInfo c3_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  32,                                  /* colNo */
  "sortedIndices",                     /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_e_emlrtDCI = { 72,/* lineNo */
  34,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  34,                                  /* colNo */
  "sortedIndices",                     /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_f_emlrtDCI = { 78,/* lineNo */
  11,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_k_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  78,                                  /* lineNo */
  11,                                  /* colNo */
  "pointsx",                           /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c3_c_emlrtECI = { -1,/* nDims */
  78,                                  /* lineNo */
  1,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtDCInfo c3_g_emlrtDCI = { 79,/* lineNo */
  11,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_l_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  79,                                  /* lineNo */
  11,                                  /* colNo */
  "pointsy",                           /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c3_d_emlrtECI = { -1,/* nDims */
  79,                                  /* lineNo */
  1,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_fc_emlrtRTEI = { 96,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtDCInfo c3_h_emlrtDCI = { 134,/* lineNo */
  18,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_m_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  134,                                 /* lineNo */
  18,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_i_emlrtDCI = { 134,/* lineNo */
  21,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_n_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  134,                                 /* lineNo */
  21,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_j_emlrtDCI = { 135,/* lineNo */
  18,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_o_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  135,                                 /* lineNo */
  18,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_k_emlrtDCI = { 135,/* lineNo */
  21,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_p_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  135,                                 /* lineNo */
  21,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_l_emlrtDCI = { 136,/* lineNo */
  18,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_q_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  136,                                 /* lineNo */
  18,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_m_emlrtDCI = { 136,/* lineNo */
  21,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_r_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  136,                                 /* lineNo */
  21,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo c3_gc_emlrtRTEI = { 143,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtDCInfo c3_n_emlrtDCI = { 150,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_s_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  150,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_o_emlrtDCI = { 150,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_t_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  150,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_p_emlrtDCI = { 151,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_u_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  151,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_q_emlrtDCI = { 151,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_v_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  151,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_r_emlrtDCI = { 152,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_w_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  152,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_s_emlrtDCI = { 152,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_x_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  152,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_t_emlrtDCI = { 30,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c3_u_emlrtDCI = { 30,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c3_v_emlrtDCI = { 31,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c3_w_emlrtDCI = { 31,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  33,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_x_emlrtDCI = { 37,/* lineNo */
  33,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  19,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_y_emlrtDCI = { 37,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  33,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_ab_emlrtDCI = { 38,/* lineNo */
  33,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  19,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_bb_emlrtDCI = { 38,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  56,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_cb_emlrtDCI = { 40,/* lineNo */
  56,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  92,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_db_emlrtDCI = { 40,/* lineNo */
  92,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  37,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_eb_emlrtDCI = { 43,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_fb_emlrtDCI = { 43,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  37,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_gb_emlrtDCI = { 44,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_hb_emlrtDCI = { 44,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  78,                                  /* lineNo */
  47,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_ib_emlrtDCI = { 78,/* lineNo */
  47,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_kb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  47,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_jb_emlrtDCI = { 79,/* lineNo */
  47,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_lb_emlrtBCI = { 0,/* iFirst */
  19,                                  /* iLast */
  83,                                  /* lineNo */
  18,                                  /* colNo */
  "pointsx",                           /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_kb_emlrtDCI = { 83,/* lineNo */
  18,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_mb_emlrtBCI = { 0,/* iFirst */
  19,                                  /* iLast */
  84,                                  /* lineNo */
  18,                                  /* colNo */
  "pointsy",                           /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_lb_emlrtDCI = { 84,/* lineNo */
  18,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_nb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  25,                                  /* colNo */
  "validY",                            /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_mb_emlrtDCI = { 93,/* lineNo */
  25,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_ob_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  28,                                  /* colNo */
  "validX",                            /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_nb_emlrtDCI = { 97,/* lineNo */
  28,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_pb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  16,                                  /* colNo */
  "validX",                            /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_ob_emlrtDCI = { 97,/* lineNo */
  16,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_qb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  98,                                  /* lineNo */
  28,                                  /* colNo */
  "validY",                            /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_pb_emlrtDCI = { 98,/* lineNo */
  28,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_rb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  98,                                  /* lineNo */
  16,                                  /* colNo */
  "validY",                            /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_qb_emlrtDCI = { 98,/* lineNo */
  16,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_sb_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  131,                                 /* lineNo */
  27,                                  /* colNo */
  "xValues",                           /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_rb_emlrtDCI = { 131,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_tb_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  132,                                 /* lineNo */
  27,                                  /* colNo */
  "yValues",                           /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_sb_emlrtDCI = { 132,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_ub_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  147,                                 /* lineNo */
  31,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_tb_emlrtDCI = { 147,/* lineNo */
  31,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_vb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  148,                                 /* lineNo */
  31,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_ub_emlrtDCI = { 148,/* lineNo */
  31,                                  /* colNo */
  "Image Processing System/new_version",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

/* Function Declarations */
static void initialize_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void enable_c3_flightControlSystem(SFc3_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void c3_update_jit_animation_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void c3_do_animation_call_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const mxArray *c3_st);
static void initSimStructsc3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void initSubchartIOPointersc3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void c3_bwmorph(SFc3_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c3_bwin[19200], boolean_T c3_bw[19200]);
static void c3_b_bwmorph(SFc3_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c3_bwin[19200], boolean_T c3_bw[19200]);
static void c3_c_bwmorph(SFc3_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c3_bwin[19200], boolean_T c3_bw[19200]);
static boolean_T c3_function_handle_parenReference
  (SFc3_flightControlSystemInstanceStruct *chartInstance, boolean_T
   c3_varargin_1, boolean_T c3_varargin_2);
static void c3_cat(SFc3_flightControlSystemInstanceStruct *chartInstance,
                   boolean_T c3_varargin_1[19200], boolean_T c3_varargin_2[19200],
                   boolean_T c3_varargin_3[19200], boolean_T c3_b_y[57600]);
static void c3_eml_find(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, boolean_T c3_x[19200], int32_T c3_i_data[], int32_T
  c3_i_size[1], int32_T c3_j_data[], int32_T c3_j_size[1]);
static void c3_indexShapeCheck(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_matrixSize, int32_T
  c3_indexSize[2]);
static void c3_power(SFc3_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c3_sp, real_T c3_a_data[], int32_T
                     c3_a_size[1], real_T c3_y_data[], int32_T c3_y_size[1]);
static real_T c3_b_function_handle_parenReference
  (SFc3_flightControlSystemInstanceStruct *chartInstance, real_T c3_varargin_1);
static void c3_sqrt(SFc3_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T c3_x_size[1],
                    real_T c3_d_x_data[], int32_T c3_b_x_size[1]);
static void c3_check_forloop_overflow_error
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c3_sp);
static boolean_T c3_all(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, boolean_T c3_c_x_data[], int32_T c3_x_size[1]);
static void c3_sort(SFc3_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T c3_x_size[1],
                    real_T c3_d_x_data[], int32_T c3_b_x_size[1], int32_T
                    c3_idx_data[], int32_T c3_idx_size[1]);
static void c3_sortIdx(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T c3_x_size[1], int32_T
  c3_idx_data[], int32_T c3_idx_size[1], real_T c3_d_x_data[], int32_T
  c3_b_x_size[1]);
static void c3_merge_pow2_block(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_idx_data[], int32_T
  c3_idx_size[1], real_T c3_c_x_data[], int32_T c3_x_size[1], int32_T c3_offset,
  int32_T c3_b_idx_data[], int32_T c3_b_idx_size[1], real_T c3_d_x_data[],
  int32_T c3_b_x_size[1]);
static void c3_merge_block(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, int32_T c3_idx_data[], int32_T c3_idx_size[1], real_T
  c3_c_x_data[], int32_T c3_x_size[1], int32_T c3_offset, int32_T c3_n, int32_T
  c3_preSortLevel, int32_T c3_b_iwork_data[], int32_T c3_iwork_size[1], real_T
  c3_b_xwork_data[], int32_T c3_xwork_size[1], int32_T c3_b_idx_data[], int32_T
  c3_b_idx_size[1], real_T c3_d_x_data[], int32_T c3_b_x_size[1], int32_T
  c3_c_iwork_data[], int32_T c3_b_iwork_size[1], real_T c3_c_xwork_data[],
  int32_T c3_b_xwork_size[1]);
static void c3_merge(SFc3_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c3_sp, int32_T c3_idx_data[], int32_T
                     c3_idx_size[1], real_T c3_c_x_data[], int32_T c3_x_size[1],
                     int32_T c3_offset, int32_T c3_np, int32_T c3_nq, int32_T
                     c3_b_iwork_data[], int32_T c3_iwork_size[1], real_T
                     c3_b_xwork_data[], int32_T c3_xwork_size[1], int32_T
                     c3_b_idx_data[], int32_T c3_b_idx_size[1], real_T
                     c3_d_x_data[], int32_T c3_b_x_size[1], int32_T
                     c3_c_iwork_data[], int32_T c3_b_iwork_size[1], real_T
                     c3_c_xwork_data[], int32_T c3_b_xwork_size[1]);
static void c3_isfinite(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_c_x_data[], int32_T c3_x_size[1], boolean_T c3_b_data[], int32_T
  c3_b_size[1]);
static boolean_T c3_issorted(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T
  c3_x_size[1]);
static void c3_b_sort(SFc3_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T
                      c3_x_size[1], real_T c3_d_x_data[], int32_T c3_b_x_size[1],
                      int32_T c3_idx_data[], int32_T c3_idx_size[1]);
static real_T c3_randn(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp);
static void c3_genrand_uint32_vector(SFc3_flightControlSystemInstanceStruct
  *chartInstance, uint32_T c3_mt[625], uint32_T c3_b_mt[625], uint32_T c3_b_u[2]);
static void c3_genrandu(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, uint32_T c3_mt[625], uint32_T c3_b_mt[625], real_T
  *c3_r);
static void c3_string_disp(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp);
static void c3_b_string_disp(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp);
static real_T c3_minimum(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_c_x_data[], int32_T c3_x_size[1]);
static real_T c3_maximum(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_c_x_data[], int32_T c3_x_size[1]);
static void c3_linspace(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_d1, real_T c3_d2, real_T c3_b_y[20]);
static void c3_interp1(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_varargin_1_data[], int32_T
  c3_varargin_1_size[1], real_T c3_varargin_2_data[], int32_T
  c3_varargin_2_size[1], real_T c3_varargin_3[20], real_T c3_Vq[20]);
static const mxArray *c3_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const real_T
   c3_u_data[], const int32_T c3_u_size[1]);
static real_T c3_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_a__output_of_feval_, const char_T
  *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_c_outt, const char_T *c3_identifier, uint8_T
  c3_b_y[57600]);
static void c3_d_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  uint8_T c3_b_y[57600]);
static void c3_e_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_pointsx, const char_T *c3_identifier,
  real_T c3_b_y[20]);
static void c3_f_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_b_y[20]);
static real_T c3_g_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_call_count, const char_T *c3_identifier,
  boolean_T *c3_svPtr);
static real_T c3_h_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr);
static uint32_T c3_i_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_c_method, const char_T *c3_identifier,
  boolean_T *c3_svPtr);
static uint32_T c3_j_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr);
static void c3_k_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_e_state, const char_T *c3_identifier,
  boolean_T *c3_svPtr, uint32_T c3_b_y[625]);
static void c3_l_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr, uint32_T c3_b_y[625]);
static void c3_m_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_e_state, const char_T *c3_identifier,
  boolean_T *c3_svPtr, uint32_T c3_b_y[2]);
static void c3_n_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr, uint32_T c3_b_y[2]);
static uint8_T c3_o_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_flightControlSystem, const
  char_T *c3_identifier);
static uint8_T c3_p_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_slStringInitializeDynamicBuffers
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void c3_chart_data_browse_helper(SFc3_flightControlSystemInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig);
static const mxArray *c3_feval(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1, const mxArray *c3_input2, const mxArray *c3_input3);
static const mxArray *c3_b_feval(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1, const mxArray *c3_input2, const mxArray *c3_input3);
static void c3_b_sqrt(SFc3_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T
                      c3_x_size[1]);
static void c3_c_sort(SFc3_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T
                      c3_x_size[1], int32_T c3_idx_data[], int32_T c3_idx_size[1]);
static void c3_b_sortIdx(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T c3_x_size[1], int32_T
  c3_idx_data[], int32_T c3_idx_size[1]);
static void c3_b_merge_pow2_block(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_idx_data[], real_T
  c3_c_x_data[], int32_T c3_offset);
static void c3_b_merge_block(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_idx_data[], real_T
  c3_c_x_data[], int32_T c3_offset, int32_T c3_n, int32_T c3_preSortLevel,
  int32_T c3_b_iwork_data[], real_T c3_b_xwork_data[]);
static void c3_b_merge(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, int32_T c3_idx_data[], real_T c3_c_x_data[], int32_T
  c3_offset, int32_T c3_np, int32_T c3_nq, int32_T c3_b_iwork_data[], real_T
  c3_b_xwork_data[]);
static void c3_d_sort(SFc3_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T
                      c3_x_size[1], int32_T c3_idx_data[], int32_T c3_idx_size[1]);
static void c3_b_genrand_uint32_vector(SFc3_flightControlSystemInstanceStruct
  *chartInstance, uint32_T c3_mt[625], uint32_T c3_b_u[2]);
static real_T c3_b_genrandu(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, uint32_T c3_mt[625]);
static void c3_plus(SFc3_flightControlSystemInstanceStruct *chartInstance,
                    real_T c3_b_in1_data[], int32_T c3_in1_size[1], real_T
                    c3_in2_data[], int32_T c3_in2_size[1]);
static int32_T c3__s32_d_(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_b, int32_T c3_EMLOvCount_src_loc, uint32_T c3_ssid_src_loc, int32_T
  c3_offset_src_loc, int32_T c3_length_src_loc);
static void init_dsm_address_info(SFc3_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c3_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c3_st.tls = chartInstance->c3_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c3_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_call_count_not_empty = false;
  chartInstance->c3_method_not_empty = false;
  chartInstance->c3_state_not_empty = false;
  chartInstance->c3_b_method_not_empty = false;
  chartInstance->c3_b_state_not_empty = false;
  chartInstance->c3_c_state_not_empty = false;
  chartInstance->c3_d_state_not_empty = false;
  chartInstance->c3_is_active_c3_flightControlSystem = 0U;
}

static void initialize_params_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  static const int32_T c3_b_postfixPredicateTree[7] = { 0, 1, -3, 2, -3, 3, -3 };

  static const int32_T c3_c_postfixPredicateTree[7] = { 0, 1, -3, 2, -3, 3, -3 };

  static const int32_T c3_b_condTxtEndIdx[4] = { 4396, 4418, 4427, 4449 };

  static const int32_T c3_b_condTxtStartIdx[4] = { 4391, 4400, 4422, 4431 };

  static const int32_T c3_c_condTxtEndIdx[4] = { 4949, 4971, 4980, 5002 };

  static const int32_T c3_c_condTxtStartIdx[4] = { 4944, 4953, 4975, 4984 };

  static const int32_T c3_d_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c3_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c3_condTxtEndIdx[2] = { 2662, 2682 };

  static const int32_T c3_condTxtStartIdx[2] = { 2641, 2666 };

  static const int32_T c3_d_condTxtEndIdx[2] = { 5309, 5327 };

  static const int32_T c3_d_condTxtStartIdx[2] = { 5293, 5313 };

  static const uint32_T c3_decisionTxtEndIdx = 0U;
  static const uint32_T c3_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c3_chart_data_browse_helper);
  chartInstance->c3_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c3_RuntimeVar,
    &chartInstance->c3_IsDebuggerActive,
    &chartInstance->c3_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c3_mlFcnLineNumber, &chartInstance->c3_IsHeatMapPresent, 0);
  covrtCreateStateflowInstanceData(chartInstance->c3_covrtInstance, 1U, 0U, 1U,
    17U);
  covrtChartInitFcn(chartInstance->c3_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c3_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c3_decisionTxtStartIdx, &c3_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c3_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c3_covrtInstance, "", 4U, 0U, 1U, 0U, 10U, 0U,
                  1U, 0U, 7U, 0U, 12U, 4U);
  covrtEmlFcnInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 5424);
  covrtEmlSaturationInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 674, -1,
    732);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 81, 103, -1,
                    127, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 918, 931, 1035,
                    1304, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 1148, 1173, -1,
                    1296, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 2551, 2573, -1,
                    4623, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 2638, 2682,
                    2718, 2875, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 4388, 4449, -1,
                    4611, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 6U, 4770, 4796, -1,
                    5212, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 7U, 4941, 5002, -1,
                    5196, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 8U, 5238, 5256,
                    5286, 5389, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 9U, 5286, 5327,
                    5355, 5389, false);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 442, 478, 528);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 891, 913, 1308);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 2881, 2905,
                     3003);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 4292, 4317,
                     4619);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 4670, 4697,
                     5236);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 4702, 4725,
                     5232);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 6U, 4734, 4757,
                     5224);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 2641, 2682,
                      2U, 0U, c3_condTxtStartIdx, c3_condTxtEndIdx, 3U,
                      c3_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 4391, 4449,
                      4U, 2U, c3_b_condTxtStartIdx, c3_b_condTxtEndIdx, 7U,
                      c3_b_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 4944, 5002,
                      4U, 6U, c3_c_condTxtStartIdx, c3_c_condTxtEndIdx, 7U,
                      c3_c_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 5293, 5327,
                      2U, 10U, c3_d_condTxtStartIdx, c3_d_condTxtEndIdx, 3U,
                      c3_d_postfixPredicateTree, false);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 921,
    931, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 2554,
    2573, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 4391,
    4396, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 4400,
    4418, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 4422,
    4427, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 4431,
    4449, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 6U, 4773,
    4796, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 7U, 4944,
    4949, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 8U, 4953,
    4971, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 9U, 4975,
    4980, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 10U, 4984,
    5002, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 11U, 5241,
    5256, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 12U, 5293,
    5309, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 13U, 5313,
    5327, -1, 2U);
}

static void mdl_cleanup_runtime_resources_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c3_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c3_covrtInstance);
}

static void enable_c3_flightControlSystem(SFc3_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c3_b_pointsx[20];
  real_T c3_b_pointsy[20];
  real_T c3_b_validY_data[20];
  real_T c3_closestIndices_data[20];
  real_T c3_sortIdx_data[20];
  real_T c3_validY_data[20];
  real_T c3_xValues[20];
  real_T c3_yValues[20];
  real_T c3_dv[2];
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_b_c;
  real_T c3_b_distX;
  real_T c3_b_distY;
  real_T c3_b_dx;
  real_T c3_b_dy;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c;
  real_T c3_c_a;
  real_T c3_c_i;
  real_T c3_c_k;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_count;
  real_T c3_d;
  real_T c3_d1;
  real_T c3_d10;
  real_T c3_d11;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  real_T c3_d7;
  real_T c3_d8;
  real_T c3_d9;
  real_T c3_d_a;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_e_a;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_f_a;
  real_T c3_f_y;
  real_T c3_g_a;
  real_T c3_g_y;
  real_T c3_h_a;
  real_T c3_i_a;
  real_T c3_j_a;
  real_T c3_k_a;
  real_T c3_maxval;
  real_T c3_minval;
  real_T c3_varargin_2;
  real_T c3_x;
  real_T c3_xIdx;
  real_T c3_yIdx;
  int32_T c3_b_tmp_data[20];
  int32_T c3_c_iidx_data[20];
  int32_T c3_b_tmp_size[2];
  int32_T c3_iv[2];
  int32_T c3_iv1[2];
  int32_T c3_iv2[2];
  int32_T c3_iv3[2];
  int32_T c3_iv4[2];
  int32_T c3_b_filteredX_size[1];
  int32_T c3_b_filteredY_size[1];
  int32_T c3_b_minDistances_size[1];
  int32_T c3_b_validY_size[1];
  int32_T c3_c_filteredX_size[1];
  int32_T c3_c_filteredY_size[1];
  int32_T c3_c_tmp_size[1];
  int32_T c3_closestIndices_size[1];
  int32_T c3_d_filteredX_size[1];
  int32_T c3_d_filteredY_size[1];
  int32_T c3_filteredX_size[1];
  int32_T c3_filteredY_size[1];
  int32_T c3_ii_size[1];
  int32_T c3_iidx_size[1];
  int32_T c3_jj_size[1];
  int32_T c3_minDistances_size[1];
  int32_T c3_sortIdx_size[1];
  int32_T c3_tmp_size[1];
  int32_T c3_validY_size[1];
  int32_T c3_xIdx_size[1];
  int32_T c3_yIdx_size[1];
  int32_T c3_ab_loop_ub;
  int32_T c3_b_end;
  int32_T c3_b_i;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
  int32_T c3_b_partialTrueCount;
  int32_T c3_b_trueCount;
  int32_T c3_bb_loop_ub;
  int32_T c3_c_loop_ub;
  int32_T c3_cb_loop_ub;
  int32_T c3_d_i;
  int32_T c3_d_loop_ub;
  int32_T c3_dx;
  int32_T c3_dy;
  int32_T c3_e_i;
  int32_T c3_e_loop_ub;
  int32_T c3_end;
  int32_T c3_f_i;
  int32_T c3_f_loop_ub;
  int32_T c3_filteredX;
  int32_T c3_filteredY;
  int32_T c3_g_i;
  int32_T c3_g_loop_ub;
  int32_T c3_h_i;
  int32_T c3_h_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i100;
  int32_T c3_i101;
  int32_T c3_i102;
  int32_T c3_i103;
  int32_T c3_i104;
  int32_T c3_i105;
  int32_T c3_i106;
  int32_T c3_i107;
  int32_T c3_i108;
  int32_T c3_i109;
  int32_T c3_i11;
  int32_T c3_i110;
  int32_T c3_i111;
  int32_T c3_i112;
  int32_T c3_i113;
  int32_T c3_i114;
  int32_T c3_i115;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i3;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i4;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i5;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  int32_T c3_i58;
  int32_T c3_i59;
  int32_T c3_i6;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  int32_T c3_i64;
  int32_T c3_i65;
  int32_T c3_i66;
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i7;
  int32_T c3_i70;
  int32_T c3_i71;
  int32_T c3_i72;
  int32_T c3_i73;
  int32_T c3_i74;
  int32_T c3_i75;
  int32_T c3_i76;
  int32_T c3_i77;
  int32_T c3_i78;
  int32_T c3_i79;
  int32_T c3_i8;
  int32_T c3_i80;
  int32_T c3_i81;
  int32_T c3_i82;
  int32_T c3_i83;
  int32_T c3_i84;
  int32_T c3_i85;
  int32_T c3_i86;
  int32_T c3_i87;
  int32_T c3_i88;
  int32_T c3_i89;
  int32_T c3_i9;
  int32_T c3_i90;
  int32_T c3_i91;
  int32_T c3_i92;
  int32_T c3_i93;
  int32_T c3_i94;
  int32_T c3_i95;
  int32_T c3_i96;
  int32_T c3_i97;
  int32_T c3_i98;
  int32_T c3_i99;
  int32_T c3_i_i;
  int32_T c3_i_loop_ub;
  int32_T c3_j_loop_ub;
  int32_T c3_k;
  int32_T c3_k_loop_ub;
  int32_T c3_l_loop_ub;
  int32_T c3_loop_ub;
  int32_T c3_m_loop_ub;
  int32_T c3_n_loop_ub;
  int32_T c3_o_loop_ub;
  int32_T c3_p_loop_ub;
  int32_T c3_partialTrueCount;
  int32_T c3_q_loop_ub;
  int32_T c3_r_loop_ub;
  int32_T c3_s_loop_ub;
  int32_T c3_t_loop_ub;
  int32_T c3_trueCount;
  int32_T c3_u_loop_ub;
  int32_T c3_v_loop_ub;
  int32_T c3_validY;
  int32_T c3_w_loop_ub;
  int32_T c3_x_loop_ub;
  int32_T c3_y_loop_ub;
  uint8_T c3_b_u;
  boolean_T c3_b_centerline[19200];
  boolean_T c3_b_minDistances_data[19200];
  boolean_T c3_blueChannel[19200];
  boolean_T c3_bv[19200];
  boolean_T c3_centerline[19200];
  boolean_T c3_cleanedImage[19200];
  boolean_T c3_greenChannel[19200];
  boolean_T c3_bv1[20];
  boolean_T c3_c_tmp_data[20];
  boolean_T c3_b;
  boolean_T c3_b1;
  boolean_T c3_b10;
  boolean_T c3_b11;
  boolean_T c3_b12;
  boolean_T c3_b13;
  boolean_T c3_b14;
  boolean_T c3_b15;
  boolean_T c3_b16;
  boolean_T c3_b17;
  boolean_T c3_b18;
  boolean_T c3_b19;
  boolean_T c3_b2;
  boolean_T c3_b20;
  boolean_T c3_b21;
  boolean_T c3_b22;
  boolean_T c3_b23;
  boolean_T c3_b24;
  boolean_T c3_b25;
  boolean_T c3_b26;
  boolean_T c3_b27;
  boolean_T c3_b3;
  boolean_T c3_b4;
  boolean_T c3_b5;
  boolean_T c3_b6;
  boolean_T c3_b7;
  boolean_T c3_b8;
  boolean_T c3_b9;
  boolean_T c3_covSaturation = false;
  boolean_T c3_guard1;
  c3_st.tls = chartInstance->c3_fEmlrtCtx;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  chartInstance->c3_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c3_i = 0; c3_i < 19200; c3_i++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 0U, (real_T)
                      (*chartInstance->c3_u)[c3_i]);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c3_covrtInstance, 4U, 0, 0);
  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 0,
                     !chartInstance->c3_call_count_not_empty)) {
    chartInstance->c3_call_count = 0.0;
    chartInstance->c3_call_count_not_empty = true;
  }

  c3_b_st.site = &c3_ad_emlrtRSI;
  for (c3_i1 = 0; c3_i1 < 19200; c3_i1++) {
    c3_bv[c3_i1] = (*chartInstance->c3_u)[c3_i1];
  }

  c3_bwmorph(chartInstance, c3_bv, c3_cleanedImage);
  c3_b_st.site = &c3_bd_emlrtRSI;
  c3_b_bwmorph(chartInstance, c3_cleanedImage, c3_centerline);
  for (c3_k = 0; c3_k < 15; c3_k++) {
    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 0, 1);
    for (c3_i3 = 0; c3_i3 < 19200; c3_i3++) {
      c3_b_centerline[c3_i3] = c3_centerline[c3_i3];
    }

    c3_b_st.site = &c3_cd_emlrtRSI;
    c3_c_bwmorph(chartInstance, c3_b_centerline, c3_centerline);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 0, 0);
  for (c3_i2 = 0; c3_i2 < 19200; c3_i2++) {
    c3_greenChannel[c3_i2] = !c3_centerline[c3_i2];
  }

  for (c3_i4 = 0; c3_i4 < 19200; c3_i4++) {
    c3_greenChannel[c3_i4] = (c3_cleanedImage[c3_i4] && c3_greenChannel[c3_i4]);
  }

  for (c3_i5 = 0; c3_i5 < 19200; c3_i5++) {
    c3_blueChannel[c3_i5] = !c3_centerline[c3_i5];
  }

  for (c3_i6 = 0; c3_i6 < 19200; c3_i6++) {
    c3_blueChannel[c3_i6] = (c3_cleanedImage[c3_i6] && c3_blueChannel[c3_i6]);
  }

  c3_cat(chartInstance, c3_cleanedImage, c3_greenChannel, c3_blueChannel,
         chartInstance->c3_a);
  for (c3_i7 = 0; c3_i7 < 57600; c3_i7++) {
    chartInstance->c3_y[c3_i7] = (real_T)chartInstance->c3_a[c3_i7] * 255.0;
  }

  for (c3_i8 = 0; c3_i8 < 57600; c3_i8++) {
    c3_d = muDoubleScalarRound(chartInstance->c3_y[c3_i8]);
    c3_covSaturation = false;
    if (c3_d < 256.0) {
      if (c3_d >= 0.0) {
        c3_b_u = (uint8_T)c3_d;
      } else {
        c3_covSaturation = true;
        c3_b_u = 0U;
        sf_data_saturate_error(chartInstance->S, 1U, 674, 58);
      }
    } else if (c3_d >= 256.0) {
      c3_covSaturation = true;
      c3_b_u = MAX_uint8_T;
      sf_data_saturate_error(chartInstance->S, 1U, 674, 58);
    } else {
      c3_b_u = 0U;
    }

    covrtSaturationUpdateFcn(chartInstance->c3_covrtInstance, 4, 0, 0, 0,
      c3_covSaturation);
    chartInstance->c3_outt[c3_i8] = c3_b_u;
  }

  c3_b_st.site = &c3_dd_emlrtRSI;
  c3_c_st.site = &c3_l_emlrtRSI;
  c3_eml_find(chartInstance, &c3_c_st, c3_centerline, chartInstance->c3_ii_data,
              c3_ii_size, chartInstance->c3_jj_data, c3_jj_size);
  c3_yIdx_size[0] = c3_ii_size[0];
  c3_loop_ub = c3_ii_size[0] - 1;
  for (c3_i9 = 0; c3_i9 <= c3_loop_ub; c3_i9++) {
    chartInstance->c3_yIdx_data[c3_i9] = (real_T)chartInstance->c3_ii_data[c3_i9];
  }

  c3_xIdx_size[0] = c3_jj_size[0];
  c3_b_loop_ub = c3_jj_size[0] - 1;
  for (c3_i10 = 0; c3_i10 <= c3_b_loop_ub; c3_i10++) {
    chartInstance->c3_xIdx_data[c3_i10] = (real_T)chartInstance->
      c3_jj_data[c3_i10];
  }

  c3_d1 = (real_T)c3_xIdx_size[0];
  if (!(c3_d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c3_d1, &c3_t_emlrtDCI, &c3_st);
  }

  if (c3_d1 != (real_T)(int32_T)muDoubleScalarFloor(c3_d1)) {
    emlrtIntegerCheckR2012b(c3_d1, &c3_u_emlrtDCI, &c3_st);
  }

  c3_dv[0] = c3_d1;
  c3_filteredX_size[0] = c3__s32_d_(chartInstance, trunc(c3_dv[0]), 0, 1U, 817,
    29);
  c3_c_loop_ub = c3__s32_d_(chartInstance, trunc(c3_dv[0]), 0, 1U, 817, 29) - 1;
  for (c3_i11 = 0; c3_i11 <= c3_c_loop_ub; c3_i11++) {
    chartInstance->c3_filteredX_data[c3_i11] = 0.0;
  }

  c3_d2 = (real_T)c3_yIdx_size[0];
  if (!(c3_d2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c3_d2, &c3_v_emlrtDCI, &c3_st);
  }

  if (c3_d2 != (real_T)(int32_T)muDoubleScalarFloor(c3_d2)) {
    emlrtIntegerCheckR2012b(c3_d2, &c3_w_emlrtDCI, &c3_st);
  }

  c3_dv[0] = c3_d2;
  c3_filteredY_size[0] = c3__s32_d_(chartInstance, trunc(c3_dv[0]), 0, 1U, 848,
    29);
  c3_d_loop_ub = c3__s32_d_(chartInstance, trunc(c3_dv[0]), 0, 1U, 848, 29) - 1;
  for (c3_i12 = 0; c3_i12 <= c3_d_loop_ub; c3_i12++) {
    chartInstance->c3_filteredY_data[c3_i12] = 0.0;
  }

  c3_count = 0.0;
  c3_d3 = (real_T)c3_xIdx_size[0];
  c3_i13 = (int32_T)c3_d3;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c3_d3, mxDOUBLE_CLASS, c3_i13,
    &c3_ec_emlrtRTEI, &c3_st);
  for (c3_b_i = 0; c3_b_i < c3_i13; c3_b_i++) {
    c3_c_i = 1.0 + (real_T)c3_b_i;
    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 1, 1);
    if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 1,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 0U, c3_count,
                        0.0, -1, 0U, c3_count == 0.0))) {
      c3_count++;
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_x_emlrtDCI, &c3_st);
      }

      c3_i16 = (int32_T)c3_c_i;
      if ((c3_i16 < 1) || (c3_i16 > c3_xIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i16, 1, c3_xIdx_size[0], &c3_y_emlrtBCI,
          &c3_st);
      }

      if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
        emlrtIntegerCheckR2012b(c3_count, &c3_y_emlrtDCI, &c3_st);
      }

      c3_i21 = (int32_T)c3_count;
      if ((c3_i21 < 1) || (c3_i21 > c3_filteredX_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i21, 1, c3_filteredX_size[0],
          &c3_ab_emlrtBCI, &c3_st);
      }

      chartInstance->c3_filteredX_data[c3_i21 - 1] = chartInstance->
        c3_xIdx_data[c3_i16 - 1];
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_ab_emlrtDCI, &c3_st);
      }

      c3_i25 = (int32_T)c3_c_i;
      if ((c3_i25 < 1) || (c3_i25 > c3_yIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i25, 1, c3_yIdx_size[0],
          &c3_bb_emlrtBCI, &c3_st);
      }

      if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
        emlrtIntegerCheckR2012b(c3_count, &c3_bb_emlrtDCI, &c3_st);
      }

      c3_i30 = (int32_T)c3_count;
      if ((c3_i30 < 1) || (c3_i30 > c3_filteredY_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i30, 1, c3_filteredY_size[0],
          &c3_cb_emlrtBCI, &c3_st);
      }

      chartInstance->c3_filteredY_data[c3_i30 - 1] = chartInstance->
        c3_yIdx_data[c3_i25 - 1];
    } else {
      c3_b3 = (c3_count < 1.0);
      c3_b5 = c3_b3;
      c3_b6 = false;
      c3_b7 = (c3_b5 || c3_b6);
      if (c3_b7) {
        c3_i19 = 1;
        c3_i20 = 0;
      } else {
        c3_i18 = 1;
        if ((c3_i18 < 1) || (c3_i18 > c3_filteredX_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i18, 1, c3_filteredX_size[0],
            &c3_emlrtBCI, &c3_st);
        }

        c3_i19 = c3_i18;
        if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
          emlrtIntegerCheckR2012b(c3_count, &c3_emlrtDCI, &c3_st);
        }

        c3_i23 = (int32_T)c3_count;
        if ((c3_i23 < 1) || (c3_i23 > c3_filteredX_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i23, 1, c3_filteredX_size[0],
            &c3_b_emlrtBCI, &c3_st);
        }

        c3_i20 = c3_i23;
      }

      c3_iv1[0] = 1;
      c3_iv1[1] = (c3_i20 - c3_i19) + 1;
      c3_b_st.site = &c3_ed_emlrtRSI;
      c3_indexShapeCheck(chartInstance, &c3_b_st, c3_filteredX_size[0], c3_iv1);
      c3_b8 = (c3_count < 1.0);
      c3_b9 = c3_b8;
      c3_b10 = false;
      c3_b11 = (c3_b9 || c3_b10);
      if (c3_b11) {
        c3_i28 = 1;
        c3_i29 = 0;
      } else {
        c3_i27 = 1;
        if ((c3_i27 < 1) || (c3_i27 > c3_filteredY_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i27, 1, c3_filteredY_size[0],
            &c3_c_emlrtBCI, &c3_st);
        }

        c3_i28 = c3_i27;
        if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
          emlrtIntegerCheckR2012b(c3_count, &c3_b_emlrtDCI, &c3_st);
        }

        c3_i33 = (int32_T)c3_count;
        if ((c3_i33 < 1) || (c3_i33 > c3_filteredY_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i33, 1, c3_filteredY_size[0],
            &c3_d_emlrtBCI, &c3_st);
        }

        c3_i29 = c3_i33;
      }

      c3_iv2[0] = 1;
      c3_iv2[1] = (c3_i29 - c3_i28) + 1;
      c3_b_st.site = &c3_ed_emlrtRSI;
      c3_indexShapeCheck(chartInstance, &c3_b_st, c3_filteredY_size[0], c3_iv2);
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_cb_emlrtDCI, &c3_st);
      }

      c3_i35 = (int32_T)c3_c_i;
      if ((c3_i35 < 1) || (c3_i35 > c3_xIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i35, 1, c3_xIdx_size[0],
          &c3_db_emlrtBCI, &c3_st);
      }

      c3_xIdx = chartInstance->c3_xIdx_data[c3_i35 - 1];
      c3_c_filteredX_size[0] = (c3_i20 - c3_i19) + 1;
      c3_h_loop_ub = c3_i20 - c3_i19;
      for (c3_i38 = 0; c3_i38 <= c3_h_loop_ub; c3_i38++) {
        chartInstance->c3_c_filteredX_data[c3_i38] =
          chartInstance->c3_filteredX_data[(c3_i19 + c3_i38) - 1] - c3_xIdx;
      }

      c3_b_st.site = &c3_ed_emlrtRSI;
      c3_power(chartInstance, &c3_b_st, chartInstance->c3_c_filteredX_data,
               c3_c_filteredX_size, chartInstance->c3_minDistances_data,
               c3_minDistances_size);
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_db_emlrtDCI, &c3_st);
      }

      c3_i40 = (int32_T)c3_c_i;
      if ((c3_i40 < 1) || (c3_i40 > c3_yIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i40, 1, c3_yIdx_size[0],
          &c3_eb_emlrtBCI, &c3_st);
      }

      c3_yIdx = chartInstance->c3_yIdx_data[c3_i40 - 1];
      c3_c_filteredY_size[0] = (c3_i29 - c3_i28) + 1;
      c3_l_loop_ub = c3_i29 - c3_i28;
      for (c3_i43 = 0; c3_i43 <= c3_l_loop_ub; c3_i43++) {
        chartInstance->c3_c_filteredY_data[c3_i43] =
          chartInstance->c3_filteredY_data[(c3_i28 + c3_i43) - 1] - c3_yIdx;
      }

      c3_b_st.site = &c3_ed_emlrtRSI;
      c3_power(chartInstance, &c3_b_st, chartInstance->c3_c_filteredY_data,
               c3_c_filteredY_size, chartInstance->c3_tmp_data, c3_tmp_size);
      if ((c3_minDistances_size[0] != c3_tmp_size[0]) && ((c3_minDistances_size
            [0] != 1) && (c3_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_minDistances_size[0], c3_tmp_size[0],
          &c3_emlrtECI, &c3_st);
      }

      if (c3_minDistances_size[0] == c3_tmp_size[0]) {
        c3_o_loop_ub = c3_minDistances_size[0] - 1;
        for (c3_i46 = 0; c3_i46 <= c3_o_loop_ub; c3_i46++) {
          chartInstance->c3_minDistances_data[c3_i46] +=
            chartInstance->c3_tmp_data[c3_i46];
        }
      } else {
        c3_plus(chartInstance, chartInstance->c3_minDistances_data,
                c3_minDistances_size, chartInstance->c3_tmp_data, c3_tmp_size);
      }

      c3_b_st.site = &c3_ed_emlrtRSI;
      c3_b_sqrt(chartInstance, &c3_b_st, chartInstance->c3_minDistances_data,
                c3_minDistances_size);
      c3_b_minDistances_size[0] = c3_minDistances_size[0];
      c3_p_loop_ub = c3_minDistances_size[0] - 1;
      for (c3_i47 = 0; c3_i47 <= c3_p_loop_ub; c3_i47++) {
        c3_b_minDistances_data[c3_i47] = (chartInstance->
          c3_minDistances_data[c3_i47] > 10.0);
      }

      c3_b_st.site = &c3_fd_emlrtRSI;
      if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 2, c3_all
                         (chartInstance, &c3_b_st, c3_b_minDistances_data,
                          c3_b_minDistances_size))) {
        c3_count++;
        if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
          emlrtIntegerCheckR2012b(c3_c_i, &c3_eb_emlrtDCI, &c3_st);
        }

        c3_i49 = (int32_T)c3_c_i;
        if ((c3_i49 < 1) || (c3_i49 > c3_xIdx_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i49, 1, c3_xIdx_size[0],
            &c3_fb_emlrtBCI, &c3_st);
        }

        if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
          emlrtIntegerCheckR2012b(c3_count, &c3_fb_emlrtDCI, &c3_st);
        }

        c3_i51 = (int32_T)c3_count;
        if ((c3_i51 < 1) || (c3_i51 > c3_filteredX_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i51, 1, c3_filteredX_size[0],
            &c3_gb_emlrtBCI, &c3_st);
        }

        chartInstance->c3_filteredX_data[c3_i51 - 1] =
          chartInstance->c3_xIdx_data[c3_i49 - 1];
        if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
          emlrtIntegerCheckR2012b(c3_c_i, &c3_gb_emlrtDCI, &c3_st);
        }

        c3_i52 = (int32_T)c3_c_i;
        if ((c3_i52 < 1) || (c3_i52 > c3_yIdx_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i52, 1, c3_yIdx_size[0],
            &c3_hb_emlrtBCI, &c3_st);
        }

        if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
          emlrtIntegerCheckR2012b(c3_count, &c3_hb_emlrtDCI, &c3_st);
        }

        c3_i53 = (int32_T)c3_count;
        if ((c3_i53 < 1) || (c3_i53 > c3_filteredY_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i53, 1, c3_filteredY_size[0],
            &c3_ib_emlrtBCI, &c3_st);
        }

        chartInstance->c3_filteredY_data[c3_i53 - 1] =
          chartInstance->c3_yIdx_data[c3_i52 - 1];
      }
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 1, 0);
  c3_b = (c3_count < 1.0);
  c3_b1 = c3_b;
  c3_b2 = false;
  c3_b4 = (c3_b1 || c3_b2);
  if (c3_b4) {
    c3_i15 = 1;
    c3_i17 = 0;
  } else {
    c3_i14 = 1;
    if ((c3_i14 < 1) || (c3_i14 > c3_filteredX_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i14, 1, c3_filteredX_size[0],
        &c3_e_emlrtBCI, &c3_st);
    }

    c3_i15 = c3_i14;
    if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
      emlrtIntegerCheckR2012b(c3_count, &c3_c_emlrtDCI, &c3_st);
    }

    c3_i22 = (int32_T)c3_count;
    if ((c3_i22 < 1) || (c3_i22 > c3_filteredX_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i22, 1, c3_filteredX_size[0],
        &c3_f_emlrtBCI, &c3_st);
    }

    c3_i17 = c3_i22;
  }

  c3_iv[0] = 1;
  c3_iv[1] = (c3_i17 - c3_i15) + 1;
  c3_b_st.site = &c3_gd_emlrtRSI;
  c3_indexShapeCheck(chartInstance, &c3_b_st, c3_filteredX_size[0], c3_iv);
  c3_b_filteredX_size[0] = (c3_i17 - c3_i15) + 1;
  c3_e_loop_ub = c3_i17 - c3_i15;
  for (c3_i24 = 0; c3_i24 <= c3_e_loop_ub; c3_i24++) {
    chartInstance->c3_b_filteredX_data[c3_i24] =
      chartInstance->c3_filteredX_data[(c3_i15 + c3_i24) - 1];
  }

  c3_filteredX_size[0] = c3_b_filteredX_size[0];
  c3_f_loop_ub = c3_b_filteredX_size[0] - 1;
  for (c3_i26 = 0; c3_i26 <= c3_f_loop_ub; c3_i26++) {
    chartInstance->c3_filteredX_data[c3_i26] =
      chartInstance->c3_b_filteredX_data[c3_i26];
  }

  c3_b12 = (c3_count < 1.0);
  c3_b13 = c3_b12;
  c3_b14 = false;
  c3_b15 = (c3_b13 || c3_b14);
  if (c3_b15) {
    c3_i32 = 1;
    c3_i34 = 0;
  } else {
    c3_i31 = 1;
    if ((c3_i31 < 1) || (c3_i31 > c3_filteredY_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i31, 1, c3_filteredY_size[0],
        &c3_g_emlrtBCI, &c3_st);
    }

    c3_i32 = c3_i31;
    if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
      emlrtIntegerCheckR2012b(c3_count, &c3_d_emlrtDCI, &c3_st);
    }

    c3_i36 = (int32_T)c3_count;
    if ((c3_i36 < 1) || (c3_i36 > c3_filteredY_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i36, 1, c3_filteredY_size[0],
        &c3_h_emlrtBCI, &c3_st);
    }

    c3_i34 = c3_i36;
  }

  c3_iv3[0] = 1;
  c3_iv3[1] = (c3_i34 - c3_i32) + 1;
  c3_b_st.site = &c3_hd_emlrtRSI;
  c3_indexShapeCheck(chartInstance, &c3_b_st, c3_filteredY_size[0], c3_iv3);
  c3_b_filteredY_size[0] = (c3_i34 - c3_i32) + 1;
  c3_g_loop_ub = c3_i34 - c3_i32;
  for (c3_i37 = 0; c3_i37 <= c3_g_loop_ub; c3_i37++) {
    chartInstance->c3_b_filteredY_data[c3_i37] =
      chartInstance->c3_filteredY_data[(c3_i32 + c3_i37) - 1];
  }

  c3_filteredY_size[0] = c3_b_filteredY_size[0];
  c3_i_loop_ub = c3_b_filteredY_size[0] - 1;
  for (c3_i39 = 0; c3_i39 <= c3_i_loop_ub; c3_i39++) {
    chartInstance->c3_filteredY_data[c3_i39] =
      chartInstance->c3_b_filteredY_data[c3_i39];
  }

  c3_j_loop_ub = c3_filteredX_size[0] - 1;
  for (c3_i41 = 0; c3_i41 <= c3_j_loop_ub; c3_i41++) {
    chartInstance->c3_filteredX_data[c3_i41] -= 80.0;
  }

  c3_k_loop_ub = c3_filteredY_size[0] - 1;
  for (c3_i42 = 0; c3_i42 <= c3_k_loop_ub; c3_i42++) {
    chartInstance->c3_filteredY_data[c3_i42] -= 60.0;
  }

  c3_d_filteredX_size[0] = c3_filteredX_size[0];
  c3_m_loop_ub = c3_filteredX_size[0] - 1;
  for (c3_i44 = 0; c3_i44 <= c3_m_loop_ub; c3_i44++) {
    chartInstance->c3_d_filteredX_data[c3_i44] =
      chartInstance->c3_filteredX_data[c3_i44] - 80.0;
  }

  c3_b_st.site = &c3_id_emlrtRSI;
  c3_power(chartInstance, &c3_b_st, chartInstance->c3_d_filteredX_data,
           c3_d_filteredX_size, chartInstance->c3_yIdx_data, c3_yIdx_size);
  c3_d_filteredY_size[0] = c3_filteredY_size[0];
  c3_n_loop_ub = c3_filteredY_size[0] - 1;
  for (c3_i45 = 0; c3_i45 <= c3_n_loop_ub; c3_i45++) {
    chartInstance->c3_d_filteredY_data[c3_i45] =
      chartInstance->c3_filteredY_data[c3_i45] - 60.0;
  }

  c3_b_st.site = &c3_id_emlrtRSI;
  c3_power(chartInstance, &c3_b_st, chartInstance->c3_d_filteredY_data,
           c3_d_filteredY_size, chartInstance->c3_tmp_data, c3_tmp_size);
  if ((c3_yIdx_size[0] != c3_tmp_size[0]) && ((c3_yIdx_size[0] != 1) &&
       (c3_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c3_yIdx_size[0], c3_tmp_size[0], &c3_b_emlrtECI,
      &c3_st);
  }

  if (c3_yIdx_size[0] == c3_tmp_size[0]) {
    c3_q_loop_ub = c3_yIdx_size[0] - 1;
    for (c3_i48 = 0; c3_i48 <= c3_q_loop_ub; c3_i48++) {
      chartInstance->c3_yIdx_data[c3_i48] += chartInstance->c3_tmp_data[c3_i48];
    }
  } else {
    c3_plus(chartInstance, chartInstance->c3_yIdx_data, c3_yIdx_size,
            chartInstance->c3_tmp_data, c3_tmp_size);
  }

  c3_b_st.site = &c3_id_emlrtRSI;
  c3_b_sqrt(chartInstance, &c3_b_st, chartInstance->c3_yIdx_data, c3_yIdx_size);
  c3_b_st.site = &c3_jd_emlrtRSI;
  c3_c_st.site = &c3_x_emlrtRSI;
  c3_c_sort(chartInstance, &c3_c_st, chartInstance->c3_yIdx_data, c3_yIdx_size,
            chartInstance->c3_ii_data, c3_ii_size);
  c3_yIdx_size[0] = c3_ii_size[0];
  c3_r_loop_ub = c3_ii_size[0] - 1;
  for (c3_i50 = 0; c3_i50 <= c3_r_loop_ub; c3_i50++) {
    chartInstance->c3_yIdx_data[c3_i50] = (real_T)chartInstance->
      c3_ii_data[c3_i50];
  }

  c3_varargin_2 = (real_T)c3_yIdx_size[0];
  c3_b_y = c3_varargin_2;
  c3_c_y = c3_b_y;
  c3_d_y = c3_c_y;
  c3_b_b = c3_d_y;
  c3_e_y = c3_b_b;
  c3_f_y = c3_e_y;
  c3_d4 = muDoubleScalarMin(20.0, c3_f_y);
  c3_b16 = (c3_d4 < 1.0);
  c3_b17 = c3_b16;
  c3_b18 = false;
  c3_b19 = (c3_b17 || c3_b18);
  if (c3_b19) {
    c3_i55 = 1;
    c3_i56 = 0;
  } else {
    c3_i54 = 1;
    if ((c3_i54 < 1) || (c3_i54 > c3_yIdx_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i54, 1, c3_yIdx_size[0], &c3_i_emlrtBCI,
        &c3_st);
    }

    c3_i55 = c3_i54;
    if (c3_d4 != (real_T)(int32_T)muDoubleScalarFloor(c3_d4)) {
      emlrtIntegerCheckR2012b(c3_d4, &c3_e_emlrtDCI, &c3_st);
    }

    c3_i57 = (int32_T)c3_d4;
    if ((c3_i57 < 1) || (c3_i57 > c3_yIdx_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i57, 1, c3_yIdx_size[0], &c3_j_emlrtBCI,
        &c3_st);
    }

    c3_i56 = c3_i57;
  }

  c3_iv4[0] = 1;
  c3_iv4[1] = (c3_i56 - c3_i55) + 1;
  c3_b_st.site = &c3_kd_emlrtRSI;
  c3_indexShapeCheck(chartInstance, &c3_b_st, c3_yIdx_size[0], c3_iv4);
  c3_closestIndices_size[0] = (c3_i56 - c3_i55) + 1;
  c3_s_loop_ub = c3_i56 - c3_i55;
  for (c3_i58 = 0; c3_i58 <= c3_s_loop_ub; c3_i58++) {
    c3_closestIndices_data[c3_i58] = chartInstance->c3_yIdx_data[(c3_i55 +
      c3_i58) - 1];
  }

  for (c3_i59 = 0; c3_i59 < 20; c3_i59++) {
    c3_b_pointsx[c3_i59] = 999.0;
  }

  for (c3_i60 = 0; c3_i60 < 20; c3_i60++) {
    c3_b_pointsy[c3_i60] = 999.0;
  }

  c3_d5 = (real_T)c3_closestIndices_size[0];
  c3_b20 = (c3_d5 < 1.0);
  c3_b21 = c3_b20;
  c3_b22 = false;
  c3_b23 = (c3_b21 || c3_b22);
  if (c3_b23) {
    c3_i61 = 0;
    c3_i62 = 0;
  } else {
    c3_i61 = 0;
    if (c3_d5 != (real_T)(int32_T)muDoubleScalarFloor(c3_d5)) {
      emlrtIntegerCheckR2012b(c3_d5, &c3_f_emlrtDCI, &c3_st);
    }

    c3_i63 = (int32_T)c3_d5;
    if ((c3_i63 < 1) || (c3_i63 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c3_i63, 1, 20, &c3_k_emlrtBCI, &c3_st);
    }

    c3_i62 = c3_i63;
  }

  c3_filteredX = c3_filteredX_size[0];
  c3_validY_size[0] = c3_closestIndices_size[0];
  c3_t_loop_ub = c3_closestIndices_size[0] - 1;
  for (c3_i64 = 0; c3_i64 <= c3_t_loop_ub; c3_i64++) {
    if (c3_closestIndices_data[c3_i64] != (real_T)(int32_T)muDoubleScalarFloor
        (c3_closestIndices_data[c3_i64])) {
      emlrtIntegerCheckR2012b(c3_closestIndices_data[c3_i64], &c3_ib_emlrtDCI,
        &c3_st);
    }

    c3_i66 = (int32_T)c3_closestIndices_data[c3_i64];
    if ((c3_i66 < 1) || (c3_i66 > c3_filteredX)) {
      emlrtDynamicBoundsCheckR2012b(c3_i66, 1, c3_filteredX, &c3_jb_emlrtBCI,
        &c3_st);
    }

    c3_validY_data[c3_i64] = chartInstance->c3_filteredX_data[c3_i66 - 1];
  }

  c3_i65 = c3_i62 - c3_i61;
  if (c3_i65 != c3_validY_size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_i65, c3_validY_size[0], &c3_c_emlrtECI,
      &c3_st);
  }

  c3_i67 = c3_i61 + 1;
  c3_b_tmp_size[1] = (c3_i62 - c3_i67) + 1;
  c3_u_loop_ub = c3_i62 - c3_i67;
  for (c3_i68 = 0; c3_i68 <= c3_u_loop_ub; c3_i68++) {
    c3_b_tmp_data[c3_i68] = (c3_i67 + c3_i68) - 1;
  }

  c3_v_loop_ub = c3_b_tmp_size[1] - 1;
  for (c3_i69 = 0; c3_i69 <= c3_v_loop_ub; c3_i69++) {
    c3_b_pointsx[c3_b_tmp_data[c3_i69]] = c3_validY_data[c3_i69];
  }

  c3_d6 = (real_T)c3_closestIndices_size[0];
  c3_b24 = (c3_d6 < 1.0);
  c3_b25 = c3_b24;
  c3_b26 = false;
  c3_b27 = (c3_b25 || c3_b26);
  if (c3_b27) {
    c3_i70 = 0;
    c3_i71 = 0;
  } else {
    c3_i70 = 0;
    if (c3_d6 != (real_T)(int32_T)muDoubleScalarFloor(c3_d6)) {
      emlrtIntegerCheckR2012b(c3_d6, &c3_g_emlrtDCI, &c3_st);
    }

    c3_i72 = (int32_T)c3_d6;
    if ((c3_i72 < 1) || (c3_i72 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c3_i72, 1, 20, &c3_l_emlrtBCI, &c3_st);
    }

    c3_i71 = c3_i72;
  }

  c3_filteredY = c3_filteredY_size[0];
  c3_validY_size[0] = c3_closestIndices_size[0];
  c3_w_loop_ub = c3_closestIndices_size[0] - 1;
  for (c3_i73 = 0; c3_i73 <= c3_w_loop_ub; c3_i73++) {
    if (c3_closestIndices_data[c3_i73] != (real_T)(int32_T)muDoubleScalarFloor
        (c3_closestIndices_data[c3_i73])) {
      emlrtIntegerCheckR2012b(c3_closestIndices_data[c3_i73], &c3_jb_emlrtDCI,
        &c3_st);
    }

    c3_i75 = (int32_T)c3_closestIndices_data[c3_i73];
    if ((c3_i75 < 1) || (c3_i75 > c3_filteredY)) {
      emlrtDynamicBoundsCheckR2012b(c3_i75, 1, c3_filteredY, &c3_kb_emlrtBCI,
        &c3_st);
    }

    c3_validY_data[c3_i73] = chartInstance->c3_filteredY_data[c3_i75 - 1];
  }

  c3_i74 = c3_i71 - c3_i70;
  if (c3_i74 != c3_validY_size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_i74, c3_validY_size[0], &c3_d_emlrtECI,
      &c3_st);
  }

  c3_i76 = c3_i70 + 1;
  c3_b_tmp_size[1] = (c3_i71 - c3_i76) + 1;
  c3_x_loop_ub = c3_i71 - c3_i76;
  for (c3_i77 = 0; c3_i77 <= c3_x_loop_ub; c3_i77++) {
    c3_b_tmp_data[c3_i77] = (c3_i76 + c3_i77) - 1;
  }

  c3_y_loop_ub = c3_b_tmp_size[1] - 1;
  for (c3_i78 = 0; c3_i78 <= c3_y_loop_ub; c3_i78++) {
    c3_b_pointsy[c3_b_tmp_data[c3_i78]] = c3_validY_data[c3_i78];
  }

  for (c3_i79 = 0; c3_i79 < 20; c3_i79++) {
    c3_bv1[c3_i79] = (c3_b_pointsy[c3_i79] != 999.0);
  }

  c3_end = 20;
  c3_trueCount = 0;
  for (c3_d_i = 0; c3_d_i < c3_end; c3_d_i++) {
    if ((c3_b_pointsx[c3_d_i] != 999.0) && c3_bv1[c3_d_i]) {
      c3_trueCount++;
    }
  }

  c3_closestIndices_size[0] = c3_trueCount;
  c3_partialTrueCount = 0;
  for (c3_e_i = 0; c3_e_i < c3_end; c3_e_i++) {
    if ((c3_b_pointsx[c3_e_i] != 999.0) && c3_bv1[c3_e_i]) {
      c3_d7 = (real_T)c3_e_i;
      if (c3_d7 != (real_T)(int32_T)muDoubleScalarFloor(c3_d7)) {
        emlrtIntegerCheckR2012b(c3_d7, &c3_kb_emlrtDCI, &c3_st);
      }

      c3_i80 = (int32_T)muDoubleScalarFloor(c3_d7);
      if ((c3_i80 < 0) || (c3_i80 > 19)) {
        emlrtDynamicBoundsCheckR2012b(c3_i80, 0, 19, &c3_lb_emlrtBCI, &c3_st);
      }

      c3_closestIndices_data[c3_partialTrueCount] = c3_b_pointsx[c3_i80];
      c3_partialTrueCount++;
    }
  }

  c3_b_end = 20;
  c3_b_trueCount = 0;
  for (c3_f_i = 0; c3_f_i < c3_b_end; c3_f_i++) {
    if ((c3_b_pointsx[c3_f_i] != 999.0) && c3_bv1[c3_f_i]) {
      c3_b_trueCount++;
    }
  }

  c3_validY_size[0] = c3_b_trueCount;
  c3_b_partialTrueCount = 0;
  for (c3_g_i = 0; c3_g_i < c3_b_end; c3_g_i++) {
    if ((c3_b_pointsx[c3_g_i] != 999.0) && c3_bv1[c3_g_i]) {
      c3_d8 = (real_T)c3_g_i;
      if (c3_d8 != (real_T)(int32_T)muDoubleScalarFloor(c3_d8)) {
        emlrtIntegerCheckR2012b(c3_d8, &c3_lb_emlrtDCI, &c3_st);
      }

      c3_i82 = (int32_T)muDoubleScalarFloor(c3_d8);
      if ((c3_i82 < 0) || (c3_i82 > 19)) {
        emlrtDynamicBoundsCheckR2012b(c3_i82, 0, 19, &c3_mb_emlrtBCI, &c3_st);
      }

      c3_validY_data[c3_b_partialTrueCount] = c3_b_pointsy[c3_i82];
      c3_b_partialTrueCount++;
    }
  }

  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 3,
                     covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
        4U, 0U, 1U, (real_T)c3_closestIndices_size[0], 3.0, -1, 5U, (real_T)
        c3_closestIndices_size[0] >= 3.0))) {
    c3_isfinite(chartInstance, c3_closestIndices_data, c3_closestIndices_size,
                c3_c_tmp_data, c3_c_tmp_size);
    c3_b_st.site = &c3_ld_emlrtRSI;
    c3_guard1 = false;
    if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 0, c3_all
                         (chartInstance, &c3_b_st, c3_c_tmp_data, c3_c_tmp_size)))
    {
      c3_b_st.site = &c3_ld_emlrtRSI;
      if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 1,
                           c3_issorted(chartInstance, &c3_b_st,
            c3_closestIndices_data, c3_closestIndices_size))) {
        covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 0, true);
        covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 4, true);
      } else {
        c3_guard1 = true;
      }
    } else {
      c3_guard1 = true;
    }

    if (c3_guard1) {
      covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 0, false);
      covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 4, false);
      c3_b_st.site = &c3_md_emlrtRSI;
      c3_c_st.site = &c3_x_emlrtRSI;
      c3_d_sort(chartInstance, &c3_c_st, c3_closestIndices_data,
                c3_closestIndices_size, c3_c_iidx_data, c3_iidx_size);
      c3_sortIdx_size[0] = c3_iidx_size[0];
      c3_ab_loop_ub = c3_iidx_size[0] - 1;
      for (c3_i85 = 0; c3_i85 <= c3_ab_loop_ub; c3_i85++) {
        c3_sortIdx_data[c3_i85] = (real_T)c3_c_iidx_data[c3_i85];
      }

      c3_validY = c3_validY_size[0];
      c3_b_validY_size[0] = c3_sortIdx_size[0];
      c3_bb_loop_ub = c3_sortIdx_size[0] - 1;
      for (c3_i89 = 0; c3_i89 <= c3_bb_loop_ub; c3_i89++) {
        if (c3_sortIdx_data[c3_i89] != (real_T)(int32_T)muDoubleScalarFloor
            (c3_sortIdx_data[c3_i89])) {
          emlrtIntegerCheckR2012b(c3_sortIdx_data[c3_i89], &c3_mb_emlrtDCI,
            &c3_st);
        }

        c3_i93 = (int32_T)c3_sortIdx_data[c3_i89];
        if ((c3_i93 < 1) || (c3_i93 > c3_validY)) {
          emlrtDynamicBoundsCheckR2012b(c3_i93, 1, c3_validY, &c3_nb_emlrtBCI,
            &c3_st);
        }

        c3_b_validY_data[c3_i89] = c3_validY_data[c3_i93 - 1];
      }

      c3_validY_size[0] = c3_b_validY_size[0];
      c3_cb_loop_ub = c3_b_validY_size[0] - 1;
      for (c3_i92 = 0; c3_i92 <= c3_cb_loop_ub; c3_i92++) {
        c3_validY_data[c3_i92] = c3_b_validY_data[c3_i92];
      }
    }

    c3_d10 = (real_T)c3_closestIndices_size[0];
    c3_i83 = (int32_T)c3_d10;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c3_d10, mxDOUBLE_CLASS, c3_i83,
      &c3_fc_emlrtRTEI, &c3_st);
    for (c3_h_i = 0; c3_h_i < c3_i83; c3_h_i++) {
      c3_c_i = 1.0 + (real_T)c3_h_i;
      covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 2, 1);
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_nb_emlrtDCI, &c3_st);
      }

      c3_i87 = (int32_T)c3_c_i;
      if ((c3_i87 < 1) || (c3_i87 > c3_closestIndices_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i87, 1, c3_closestIndices_size[0],
          &c3_ob_emlrtBCI, &c3_st);
      }

      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_ob_emlrtDCI, &c3_st);
      }

      c3_i91 = (int32_T)c3_c_i;
      if ((c3_i91 < 1) || (c3_i91 > c3_closestIndices_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i91, 1, c3_closestIndices_size[0],
          &c3_pb_emlrtBCI, &c3_st);
      }

      c3_b_st.site = &c3_nd_emlrtRSI;
      c3_closestIndices_data[c3_i91 - 1] = c3_closestIndices_data[c3_i87 - 1] +
        c3_randn(chartInstance, &c3_b_st) * 1.5;
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_pb_emlrtDCI, &c3_st);
      }

      c3_i98 = (int32_T)c3_c_i;
      if ((c3_i98 < 1) || (c3_i98 > c3_validY_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i98, 1, c3_validY_size[0],
          &c3_qb_emlrtBCI, &c3_st);
      }

      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_qb_emlrtDCI, &c3_st);
      }

      c3_i99 = (int32_T)c3_c_i;
      if ((c3_i99 < 1) || (c3_i99 > c3_validY_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i99, 1, c3_validY_size[0],
          &c3_rb_emlrtBCI, &c3_st);
      }

      c3_b_st.site = &c3_od_emlrtRSI;
      c3_validY_data[c3_i99 - 1] = c3_validY_data[c3_i98 - 1] + c3_randn
        (chartInstance, &c3_b_st) * 1.5;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 2, 0);
    c3_b_st.site = &c3_pd_emlrtRSI;
    c3_string_disp(chartInstance, &c3_b_st);
    sf_mex_call(&c3_st, NULL, "disp", 0U, 1U, 14, c3_emlrt_marshallOut
                (chartInstance, c3_closestIndices_data, c3_closestIndices_size));
    c3_b_st.site = &c3_qd_emlrtRSI;
    c3_b_string_disp(chartInstance, &c3_b_st);
    c3_b_st.site = &c3_rd_emlrtRSI;
    c3_minval = c3_minimum(chartInstance, c3_closestIndices_data,
      c3_closestIndices_size);
    c3_b_st.site = &c3_rd_emlrtRSI;
    c3_maxval = c3_maximum(chartInstance, c3_closestIndices_data,
      c3_closestIndices_size);
    c3_linspace(chartInstance, c3_minval, c3_maxval, c3_xValues);
    c3_b_st.site = &c3_sd_emlrtRSI;
    c3_interp1(chartInstance, &c3_b_st, c3_closestIndices_data,
               c3_closestIndices_size, c3_validY_data, c3_validY_size,
               c3_xValues, c3_yValues);
    for (c3_i95 = 0; c3_i95 < 20; c3_i95++) {
      c3_xValues[c3_i95] += 80.0;
    }

    for (c3_i97 = 0; c3_i97 < 20; c3_i97++) {
      c3_yValues[c3_i97] += 60.0;
    }

    for (c3_i_i = 0; c3_i_i < 20; c3_i_i++) {
      c3_c_i = 1.0 + (real_T)c3_i_i;
      covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 3, 1);
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_rb_emlrtDCI, &c3_st);
      }

      c3_i101 = (int32_T)c3_c_i;
      if ((c3_i101 < 1) || (c3_i101 > 20)) {
        emlrtDynamicBoundsCheckR2012b(c3_i101, 1, 20, &c3_sb_emlrtBCI, &c3_st);
      }

      c3_b_x = c3_xValues[c3_i101 - 1];
      c3_c_x = c3_b_x;
      c3_x = c3_c_x;
      c3_x = muDoubleScalarRound(c3_x);
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_sb_emlrtDCI, &c3_st);
      }

      c3_i103 = (int32_T)c3_c_i;
      if ((c3_i103 < 1) || (c3_i103 > 20)) {
        emlrtDynamicBoundsCheckR2012b(c3_i103, 1, 20, &c3_tb_emlrtBCI, &c3_st);
      }

      c3_d_x = c3_yValues[c3_i103 - 1];
      c3_e_x = c3_d_x;
      c3_g_y = c3_e_x;
      c3_g_y = muDoubleScalarRound(c3_g_y);
      if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 2,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 2U, c3_x,
                            0.0, -1, 4U, c3_x > 0.0)) && covrtEmlCondEval
          (chartInstance->c3_covrtInstance, 4U, 0, 3, covrtRelationalopUpdateFcn
           (chartInstance->c3_covrtInstance, 4U, 0U, 3U, c3_x, 160.0, -1, 3U,
            c3_x <= 160.0)) && covrtEmlCondEval(chartInstance->c3_covrtInstance,
           4U, 0, 4, covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
            4U, 0U, 4U, c3_g_y, 0.0, -1, 4U, c3_g_y > 0.0)) && covrtEmlCondEval
          (chartInstance->c3_covrtInstance, 4U, 0, 5, covrtRelationalopUpdateFcn
           (chartInstance->c3_covrtInstance, 4U, 0U, 5U, c3_g_y, 120.0, -1, 3U,
            c3_g_y <= 120.0))) {
        covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 1, true);
        covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 5, true);
        if (c3_g_y != (real_T)(int32_T)muDoubleScalarFloor(c3_g_y)) {
          emlrtIntegerCheckR2012b(c3_g_y, &c3_h_emlrtDCI, &c3_st);
        }

        c3_i106 = (int32_T)c3_g_y;
        if ((c3_i106 < 1) || (c3_i106 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c3_i106, 1, 120, &c3_m_emlrtBCI, &c3_st);
        }

        if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
          emlrtIntegerCheckR2012b(c3_x, &c3_i_emlrtDCI, &c3_st);
        }

        c3_i108 = (int32_T)c3_x;
        if ((c3_i108 < 1) || (c3_i108 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c3_i108, 1, 160, &c3_n_emlrtBCI, &c3_st);
        }

        chartInstance->c3_outt[(c3_i106 + 120 * (c3_i108 - 1)) - 1] = 0U;
        if (c3_g_y != (real_T)(int32_T)muDoubleScalarFloor(c3_g_y)) {
          emlrtIntegerCheckR2012b(c3_g_y, &c3_j_emlrtDCI, &c3_st);
        }

        c3_i110 = (int32_T)c3_g_y;
        if ((c3_i110 < 1) || (c3_i110 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c3_i110, 1, 120, &c3_o_emlrtBCI, &c3_st);
        }

        if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
          emlrtIntegerCheckR2012b(c3_x, &c3_k_emlrtDCI, &c3_st);
        }

        c3_i112 = (int32_T)c3_x;
        if ((c3_i112 < 1) || (c3_i112 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c3_i112, 1, 160, &c3_p_emlrtBCI, &c3_st);
        }

        chartInstance->c3_outt[(c3_i110 + 120 * (c3_i112 - 1)) + 19199] = 0U;
        if (c3_g_y != (real_T)(int32_T)muDoubleScalarFloor(c3_g_y)) {
          emlrtIntegerCheckR2012b(c3_g_y, &c3_l_emlrtDCI, &c3_st);
        }

        c3_i114 = (int32_T)c3_g_y;
        if ((c3_i114 < 1) || (c3_i114 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c3_i114, 1, 120, &c3_q_emlrtBCI, &c3_st);
        }

        if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
          emlrtIntegerCheckR2012b(c3_x, &c3_m_emlrtDCI, &c3_st);
        }

        c3_i115 = (int32_T)c3_x;
        if ((c3_i115 < 1) || (c3_i115 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c3_i115, 1, 160, &c3_r_emlrtBCI, &c3_st);
        }

        chartInstance->c3_outt[(c3_i114 + 120 * (c3_i115 - 1)) + 38399] =
          MAX_uint8_T;
      } else {
        covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 1, false);
        covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 5, false);
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 3, 0);
  }

  c3_d9 = (real_T)c3_filteredX_size[0];
  c3_i81 = (int32_T)c3_d9;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c3_d9, mxDOUBLE_CLASS, c3_i81,
    &c3_gc_emlrtRTEI, &c3_st);
  for (c3_b_k = 0; c3_b_k < c3_i81; c3_b_k++) {
    c3_c_k = 1.0 + (real_T)c3_b_k;
    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 4, 1);
    for (c3_dx = 0; c3_dx < 9; c3_dx++) {
      c3_b_dx = -4.0 + (real_T)c3_dx;
      covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 5, 1);
      for (c3_dy = 0; c3_dy < 9; c3_dy++) {
        c3_b_dy = -4.0 + (real_T)c3_dy;
        covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 6, 1);
        c3_b_st.site = &c3_td_emlrtRSI;
        c3_b_a = c3_b_dx;
        c3_c_a = c3_b_a;
        c3_d_a = c3_c_a;
        c3_e_a = c3_d_a;
        c3_f_a = c3_e_a;
        c3_c = c3_f_a * c3_f_a;
        c3_b_st.site = &c3_td_emlrtRSI;
        c3_g_a = c3_b_dy;
        c3_h_a = c3_g_a;
        c3_i_a = c3_h_a;
        c3_j_a = c3_i_a;
        c3_k_a = c3_j_a;
        c3_b_c = c3_k_a * c3_k_a;
        c3_d11 = c3_c + c3_b_c;
        c3_b_st.site = &c3_td_emlrtRSI;
        if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 6,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 6U, c3_d11,
                            16.0, -1, 3U, c3_d11 <= 16.0))) {
          if (c3_c_k != (real_T)(int32_T)muDoubleScalarFloor(c3_c_k)) {
            emlrtIntegerCheckR2012b(c3_c_k, &c3_tb_emlrtDCI, &c3_st);
          }

          c3_i100 = (int32_T)c3_c_k;
          if ((c3_i100 < 1) || (c3_i100 > c3_filteredX_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i100, 1, c3_filteredX_size[0],
              &c3_ub_emlrtBCI, &c3_st);
          }

          c3_x = (chartInstance->c3_filteredX_data[c3_i100 - 1] + c3_b_dx) +
            80.0;
          if (c3_c_k != (real_T)(int32_T)muDoubleScalarFloor(c3_c_k)) {
            emlrtIntegerCheckR2012b(c3_c_k, &c3_ub_emlrtDCI, &c3_st);
          }

          c3_i102 = (int32_T)c3_c_k;
          if ((c3_i102 < 1) || (c3_i102 > c3_filteredY_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i102, 1, c3_filteredY_size[0],
              &c3_vb_emlrtBCI, &c3_st);
          }

          c3_g_y = (chartInstance->c3_filteredY_data[c3_i102 - 1] + c3_b_dy) +
            60.0;
          if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 6,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c3_covrtInstance, 4U, 0U, 7U,
                                c3_x, 0.0, -1, 4U, c3_x > 0.0)) &&
              covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 7,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c3_covrtInstance, 4U, 0U, 8U,
                                c3_x, 160.0, -1, 3U, c3_x <= 160.0)) &&
              covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 8,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c3_covrtInstance, 4U, 0U, 9U,
                                c3_g_y, 0.0, -1, 4U, c3_g_y > 0.0)) &&
              covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 9,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c3_covrtInstance, 4U, 0U, 10U,
                                c3_g_y, 120.0, -1, 3U, c3_g_y <= 120.0))) {
            covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 2, true);
            covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 7, true);
            if (c3_g_y != (real_T)(int32_T)muDoubleScalarFloor(c3_g_y)) {
              emlrtIntegerCheckR2012b(c3_g_y, &c3_n_emlrtDCI, &c3_st);
            }

            c3_i104 = (int32_T)c3_g_y;
            if ((c3_i104 < 1) || (c3_i104 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c3_i104, 1, 120, &c3_s_emlrtBCI,
                &c3_st);
            }

            if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
              emlrtIntegerCheckR2012b(c3_x, &c3_o_emlrtDCI, &c3_st);
            }

            c3_i105 = (int32_T)c3_x;
            if ((c3_i105 < 1) || (c3_i105 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c3_i105, 1, 160, &c3_t_emlrtBCI,
                &c3_st);
            }

            chartInstance->c3_outt[(c3_i104 + 120 * (c3_i105 - 1)) - 1] = 0U;
            if (c3_g_y != (real_T)(int32_T)muDoubleScalarFloor(c3_g_y)) {
              emlrtIntegerCheckR2012b(c3_g_y, &c3_p_emlrtDCI, &c3_st);
            }

            c3_i107 = (int32_T)c3_g_y;
            if ((c3_i107 < 1) || (c3_i107 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c3_i107, 1, 120, &c3_u_emlrtBCI,
                &c3_st);
            }

            if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
              emlrtIntegerCheckR2012b(c3_x, &c3_q_emlrtDCI, &c3_st);
            }

            c3_i109 = (int32_T)c3_x;
            if ((c3_i109 < 1) || (c3_i109 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c3_i109, 1, 160, &c3_v_emlrtBCI,
                &c3_st);
            }

            chartInstance->c3_outt[(c3_i107 + 120 * (c3_i109 - 1)) + 19199] =
              MAX_uint8_T;
            if (c3_g_y != (real_T)(int32_T)muDoubleScalarFloor(c3_g_y)) {
              emlrtIntegerCheckR2012b(c3_g_y, &c3_r_emlrtDCI, &c3_st);
            }

            c3_i111 = (int32_T)c3_g_y;
            if ((c3_i111 < 1) || (c3_i111 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c3_i111, 1, 120, &c3_w_emlrtBCI,
                &c3_st);
            }

            if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
              emlrtIntegerCheckR2012b(c3_x, &c3_s_emlrtDCI, &c3_st);
            }

            c3_i113 = (int32_T)c3_x;
            if ((c3_i113 < 1) || (c3_i113 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c3_i113, 1, 160, &c3_x_emlrtBCI,
                &c3_st);
            }

            chartInstance->c3_outt[(c3_i111 + 120 * (c3_i113 - 1)) + 38399] = 0U;
          } else {
            covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 2, false);
            covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 7, false);
          }
        }

        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 6, 0);
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 5, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 4, 0);
  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 8,
                     covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
        4U, 0U, 11U, chartInstance->c3_call_count, 75.0, -1, 2U,
        chartInstance->c3_call_count < 75.0))) {
    c3_b_distX = -10.0;
    c3_b_distY = 10.0;
  } else if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 10,
              covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance, 4U, 0U,
    12U, chartInstance->c3_call_count, 60.0, -1, 5U,
               chartInstance->c3_call_count >= 60.0)) && covrtEmlCondEval
             (chartInstance->c3_covrtInstance, 4U, 0, 11,
              covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance, 4U, 0U,
    13U, chartInstance->c3_call_count, 120.0, -1, 2U,
               chartInstance->c3_call_count < 120.0))) {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 3, true);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 9, true);
    c3_b_distX = 0.0;
    c3_b_distY = 30.0;
  } else {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 3, false);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 9, false);
    c3_b_distX = 0.0;
    c3_b_distY = 0.0;
  }

  chartInstance->c3_call_count++;
  for (c3_i84 = 0; c3_i84 < 57600; c3_i84++) {
    (*chartInstance->c3_b_outt)[c3_i84] = chartInstance->c3_outt[c3_i84];
  }

  *chartInstance->c3_distX = c3_b_distX;
  *chartInstance->c3_distY = c3_b_distY;
  for (c3_i86 = 0; c3_i86 < 20; c3_i86++) {
    (*chartInstance->c3_pointsx)[c3_i86] = c3_b_pointsx[c3_i86];
  }

  for (c3_i88 = 0; c3_i88 < 20; c3_i88++) {
    (*chartInstance->c3_pointsy)[c3_i88] = c3_b_pointsy[c3_i88];
  }

  c3_do_animation_call_c3_flightControlSystem(chartInstance);
  for (c3_i90 = 0; c3_i90 < 57600; c3_i90++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 1U, (real_T)
                      (*chartInstance->c3_b_outt)[c3_i90]);
  }

  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 2U,
                    *chartInstance->c3_distX);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 3U,
                    *chartInstance->c3_distY);
  for (c3_i94 = 0; c3_i94 < 20; c3_i94++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 4U,
                      (*chartInstance->c3_pointsx)[c3_i94]);
  }

  for (c3_i96 = 0; c3_i96 < 20; c3_i96++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 5U,
                      (*chartInstance->c3_pointsy)[c3_i96]);
  }
}

static void ext_mode_exec_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_update_jit_animation_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_do_animation_call_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_i_y = NULL;
  const mxArray *c3_j_y = NULL;
  const mxArray *c3_k_y = NULL;
  const mxArray *c3_l_y = NULL;
  const mxArray *c3_m_y = NULL;
  const mxArray *c3_n_y = NULL;
  const mxArray *c3_o_y = NULL;
  const mxArray *c3_st;
  c3_st = NULL;
  c3_st = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createcellmatrix(13, 1), false);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", chartInstance->c3_distX, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_b_y, 0, c3_c_y);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", chartInstance->c3_distY, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_b_y, 1, c3_d_y);
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", *chartInstance->c3_b_outt, 3, 0U, 1U,
    0U, 3, 120, 160, 3), false);
  sf_mex_setcell(c3_b_y, 2, c3_e_y);
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", *chartInstance->c3_pointsx, 0, 0U,
    1U, 0U, 2, 20, 1), false);
  sf_mex_setcell(c3_b_y, 3, c3_f_y);
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", *chartInstance->c3_pointsy, 0, 0U,
    1U, 0U, 2, 20, 1), false);
  sf_mex_setcell(c3_b_y, 4, c3_g_y);
  c3_h_y = NULL;
  if (!chartInstance->c3_call_count_not_empty) {
    sf_mex_assign(&c3_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_h_y, sf_mex_create("y", &chartInstance->c3_call_count, 0,
      0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_b_y, 5, c3_h_y);
  c3_i_y = NULL;
  if (!chartInstance->c3_b_method_not_empty) {
    sf_mex_assign(&c3_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_i_y, sf_mex_create("y", &chartInstance->c3_b_method, 7, 0U,
      0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_b_y, 6, c3_i_y);
  c3_j_y = NULL;
  if (!chartInstance->c3_b_method_not_empty) {
    sf_mex_assign(&c3_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_j_y, sf_mex_create("y", &chartInstance->c3_method, 7, 0U,
      0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_b_y, 7, c3_j_y);
  c3_k_y = NULL;
  if (!chartInstance->c3_b_method_not_empty) {
    sf_mex_assign(&c3_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_k_y, sf_mex_create("y", &chartInstance->c3_b_state, 7, 0U,
      0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_b_y, 8, c3_k_y);
  c3_l_y = NULL;
  if (!chartInstance->c3_d_state_not_empty) {
    sf_mex_assign(&c3_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_l_y, sf_mex_create("y", chartInstance->c3_d_state, 7, 0U,
      1U, 0U, 1, 625), false);
  }

  sf_mex_setcell(c3_b_y, 9, c3_l_y);
  c3_m_y = NULL;
  if (!chartInstance->c3_c_state_not_empty) {
    sf_mex_assign(&c3_m_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_m_y, sf_mex_create("y", chartInstance->c3_c_state, 7, 0U,
      1U, 0U, 1, 2), false);
  }

  sf_mex_setcell(c3_b_y, 10, c3_m_y);
  c3_n_y = NULL;
  if (!chartInstance->c3_c_state_not_empty) {
    sf_mex_assign(&c3_n_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_n_y, sf_mex_create("y", chartInstance->c3_state, 7, 0U, 1U,
      0U, 1, 2), false);
  }

  sf_mex_setcell(c3_b_y, 11, c3_n_y);
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y",
    &chartInstance->c3_is_active_c3_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_b_y, 12, c3_o_y);
  sf_mex_assign(&c3_st, c3_b_y, false);
  return c3_st;
}

static void set_sim_state_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_b_u;
  real_T c3_dv[20];
  real_T c3_dv1[20];
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  uint32_T c3_uv1[625];
  uint32_T c3_uv2[2];
  uint32_T c3_uv3[2];
  uint8_T c3_uv[57600];
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_b_u = sf_mex_dup(c3_st);
  *chartInstance->c3_distX = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_b_u, 0)), "distX");
  *chartInstance->c3_distY = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_b_u, 1)), "distY");
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 2)),
                        "outt", c3_uv);
  for (c3_i = 0; c3_i < 57600; c3_i++) {
    (*chartInstance->c3_b_outt)[c3_i] = c3_uv[c3_i];
  }

  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 3)),
                        "pointsx", c3_dv);
  for (c3_i1 = 0; c3_i1 < 20; c3_i1++) {
    (*chartInstance->c3_pointsx)[c3_i1] = c3_dv[c3_i1];
  }

  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 4)),
                        "pointsy", c3_dv1);
  for (c3_i2 = 0; c3_i2 < 20; c3_i2++) {
    (*chartInstance->c3_pointsy)[c3_i2] = c3_dv1[c3_i2];
  }

  chartInstance->c3_call_count = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_b_u, 5)), "call_count",
    &chartInstance->c3_call_count_not_empty);
  chartInstance->c3_b_method = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_b_u, 6)), "method", &chartInstance->c3_b_method_not_empty);
  chartInstance->c3_method = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_b_u, 7)), "method", &chartInstance->c3_method_not_empty);
  chartInstance->c3_b_state = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_b_u, 8)), "state", &chartInstance->c3_b_state_not_empty);
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 9)),
                        "state", &chartInstance->c3_d_state_not_empty, c3_uv1);
  for (c3_i3 = 0; c3_i3 < 625; c3_i3++) {
    chartInstance->c3_d_state[c3_i3] = c3_uv1[c3_i3];
  }

  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 10)),
                        "state", &chartInstance->c3_c_state_not_empty, c3_uv2);
  for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
    chartInstance->c3_c_state[c3_i4] = c3_uv2[c3_i4];
  }

  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 11)),
                        "state", &chartInstance->c3_state_not_empty, c3_uv3);
  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    chartInstance->c3_state[c3_i5] = c3_uv3[c3_i5];
  }

  chartInstance->c3_is_active_c3_flightControlSystem = c3_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 12)),
     "is_active_c3_flightControlSystem");
  sf_mex_destroy(&c3_b_u);
  sf_mex_destroy(&c3_st);
}

static void initSimStructsc3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSubchartIOPointersc3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_bwmorph(SFc3_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c3_bwin[19200], boolean_T c3_bw[19200])
{
  static boolean_T c3_lut[512] = { false, false, false, false, false, false,
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

  real_T c3_sizeIn[2];
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  boolean_T c3_in[19200];
  (void)chartInstance;
  for (c3_i = 0; c3_i < 19200; c3_i++) {
    c3_bw[c3_i] = c3_bwin[c3_i];
  }

  for (c3_i1 = 0; c3_i1 < 19200; c3_i1++) {
    c3_in[c3_i1] = c3_bw[c3_i1];
  }

  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    c3_sizeIn[c3_i2] = 120.0 + 40.0 * (real_T)c3_i2;
  }

  bwlookup_tbb_boolean(&c3_in[0], &c3_sizeIn[0], 2.0, &c3_lut[0], 512.0, &c3_bw
                       [0]);
}

static void c3_b_bwmorph(SFc3_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c3_bwin[19200], boolean_T c3_bw[19200])
{
  static boolean_T c3_b_lut[512] = { false, false, false, false, false, false,
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

  static boolean_T c3_lut[512] = { false, false, false, false, false, false,
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

  real_T c3_sizeIn[2];
  real_T c3_b_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_k;
  boolean_T c3_image_iter1[19200];
  boolean_T c3_last_aout[19200];
  boolean_T c3_b_p;
  boolean_T c3_c_p;
  boolean_T c3_exitg1;
  boolean_T c3_p;
  boolean_T c3_x1;
  boolean_T c3_x2;
  (void)chartInstance;
  for (c3_i = 0; c3_i < 19200; c3_i++) {
    c3_bw[c3_i] = c3_bwin[c3_i];
  }

  do {
    for (c3_i1 = 0; c3_i1 < 19200; c3_i1++) {
      c3_last_aout[c3_i1] = c3_bw[c3_i1];
    }

    for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
      c3_sizeIn[c3_i2] = 120.0 + 40.0 * (real_T)c3_i2;
    }

    bwlookup_tbb_boolean(&c3_bw[0], &c3_sizeIn[0], 2.0, &c3_lut[0], 512.0,
                         &c3_image_iter1[0]);
    for (c3_i3 = 0; c3_i3 < 2; c3_i3++) {
      c3_sizeIn[c3_i3] = 120.0 + 40.0 * (real_T)c3_i3;
    }

    bwlookup_tbb_boolean(&c3_image_iter1[0], &c3_sizeIn[0], 2.0, &c3_b_lut[0],
                         512.0, &c3_bw[0]);
    c3_p = false;
    c3_b_p = true;
    c3_k = 0;
    c3_exitg1 = false;
    while ((!c3_exitg1) && (c3_k < 19200)) {
      c3_b_k = (real_T)c3_k + 1.0;
      c3_x1 = c3_last_aout[(int32_T)c3_b_k - 1];
      c3_x2 = c3_bw[(int32_T)c3_b_k - 1];
      c3_c_p = ((int32_T)c3_x1 == (int32_T)c3_x2);
      if (!c3_c_p) {
        c3_b_p = false;
        c3_exitg1 = true;
      } else {
        c3_k++;
      }
    }

    if (c3_b_p) {
      c3_p = true;
    }
  } while (!c3_p);
}

static void c3_c_bwmorph(SFc3_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c3_bwin[19200], boolean_T c3_bw[19200])
{
  static boolean_T c3_lut[512] = { false, false, false, false, false, false,
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

  real_T c3_sizeIn[2];
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i3;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i4;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i5;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  int32_T c3_i58;
  int32_T c3_i59;
  int32_T c3_i6;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  int32_T c3_i64;
  int32_T c3_i65;
  int32_T c3_i66;
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i7;
  int32_T c3_i70;
  int32_T c3_i71;
  int32_T c3_i72;
  int32_T c3_i73;
  int32_T c3_i8;
  int32_T c3_i9;
  boolean_T c3_endPoints[19200];
  boolean_T c3_newEndPoints[19200];
  boolean_T c3_b_y[4800];
  boolean_T c3_t[4800];
  for (c3_i = 0; c3_i < 19200; c3_i++) {
    c3_bw[c3_i] = c3_bwin[c3_i];
  }

  for (c3_i1 = 0; c3_i1 < 19200; c3_i1++) {
    c3_bw[c3_i1] = !c3_bw[c3_i1];
  }

  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    c3_sizeIn[c3_i2] = 120.0 + 40.0 * (real_T)c3_i2;
  }

  bwlookup_tbb_boolean(&c3_bw[0], &c3_sizeIn[0], 2.0, &c3_lut[0], 512.0,
                       &c3_endPoints[0]);
  c3_i3 = 0;
  c3_i4 = 0;
  for (c3_i5 = 0; c3_i5 < 80; c3_i5++) {
    c3_i7 = 0;
    for (c3_i9 = 0; c3_i9 < 60; c3_i9++) {
      c3_b_y[c3_i9 + c3_i3] = c3_bw[c3_i7 + c3_i4];
      c3_i7 += 2;
    }

    c3_i3 += 60;
    c3_i4 += 240;
  }

  c3_i6 = 0;
  c3_i8 = 0;
  for (c3_i10 = 0; c3_i10 < 80; c3_i10++) {
    c3_i12 = 0;
    for (c3_i13 = 0; c3_i13 < 60; c3_i13++) {
      c3_t[c3_i13 + c3_i6] = c3_endPoints[c3_i12 + c3_i8];
      c3_i12 += 2;
    }

    c3_i6 += 60;
    c3_i8 += 240;
  }

  for (c3_i11 = 0; c3_i11 < 4800; c3_i11++) {
    c3_b_y[c3_i11] = c3_function_handle_parenReference(chartInstance,
      c3_b_y[c3_i11], c3_t[c3_i11]);
  }

  c3_i14 = 0;
  c3_i15 = 0;
  for (c3_i16 = 0; c3_i16 < 80; c3_i16++) {
    c3_i18 = 0;
    for (c3_i19 = 0; c3_i19 < 60; c3_i19++) {
      c3_bw[c3_i18 + c3_i14] = c3_b_y[c3_i19 + c3_i15];
      c3_i18 += 2;
    }

    c3_i14 += 240;
    c3_i15 += 60;
  }

  for (c3_i17 = 0; c3_i17 < 2; c3_i17++) {
    c3_sizeIn[c3_i17] = 120.0 + 40.0 * (real_T)c3_i17;
  }

  bwlookup_tbb_boolean(&c3_bw[0], &c3_sizeIn[0], 2.0, &c3_lut[0], 512.0,
                       &c3_newEndPoints[0]);
  for (c3_i20 = 0; c3_i20 < 19200; c3_i20++) {
    c3_newEndPoints[c3_i20] = (c3_endPoints[c3_i20] && c3_newEndPoints[c3_i20]);
  }

  c3_i21 = 0;
  c3_i22 = 0;
  for (c3_i23 = 0; c3_i23 < 80; c3_i23++) {
    c3_i25 = 0;
    for (c3_i27 = 0; c3_i27 < 60; c3_i27++) {
      c3_b_y[c3_i27 + c3_i21] = c3_bw[(c3_i25 + c3_i22) + 120];
      c3_i25 += 2;
    }

    c3_i21 += 60;
    c3_i22 += 240;
  }

  c3_i24 = 0;
  c3_i26 = 0;
  for (c3_i28 = 0; c3_i28 < 80; c3_i28++) {
    c3_i30 = 0;
    for (c3_i31 = 0; c3_i31 < 60; c3_i31++) {
      c3_t[c3_i31 + c3_i24] = c3_newEndPoints[(c3_i30 + c3_i26) + 120];
      c3_i30 += 2;
    }

    c3_i24 += 60;
    c3_i26 += 240;
  }

  for (c3_i29 = 0; c3_i29 < 4800; c3_i29++) {
    c3_b_y[c3_i29] = c3_function_handle_parenReference(chartInstance,
      c3_b_y[c3_i29], c3_t[c3_i29]);
  }

  c3_i32 = 0;
  c3_i33 = 0;
  for (c3_i34 = 0; c3_i34 < 80; c3_i34++) {
    c3_i36 = 0;
    for (c3_i37 = 0; c3_i37 < 60; c3_i37++) {
      c3_bw[(c3_i36 + c3_i32) + 120] = c3_b_y[c3_i37 + c3_i33];
      c3_i36 += 2;
    }

    c3_i32 += 240;
    c3_i33 += 60;
  }

  for (c3_i35 = 0; c3_i35 < 2; c3_i35++) {
    c3_sizeIn[c3_i35] = 120.0 + 40.0 * (real_T)c3_i35;
  }

  bwlookup_tbb_boolean(&c3_bw[0], &c3_sizeIn[0], 2.0, &c3_lut[0], 512.0,
                       &c3_newEndPoints[0]);
  for (c3_i38 = 0; c3_i38 < 19200; c3_i38++) {
    c3_newEndPoints[c3_i38] = (c3_endPoints[c3_i38] && c3_newEndPoints[c3_i38]);
  }

  c3_i39 = 0;
  c3_i40 = 0;
  for (c3_i41 = 0; c3_i41 < 80; c3_i41++) {
    c3_i43 = 0;
    for (c3_i45 = 0; c3_i45 < 60; c3_i45++) {
      c3_b_y[c3_i45 + c3_i39] = c3_bw[(c3_i43 + c3_i40) + 1];
      c3_i43 += 2;
    }

    c3_i39 += 60;
    c3_i40 += 240;
  }

  c3_i42 = 0;
  c3_i44 = 0;
  for (c3_i46 = 0; c3_i46 < 80; c3_i46++) {
    c3_i48 = 0;
    for (c3_i49 = 0; c3_i49 < 60; c3_i49++) {
      c3_t[c3_i49 + c3_i42] = c3_newEndPoints[(c3_i48 + c3_i44) + 1];
      c3_i48 += 2;
    }

    c3_i42 += 60;
    c3_i44 += 240;
  }

  for (c3_i47 = 0; c3_i47 < 4800; c3_i47++) {
    c3_b_y[c3_i47] = c3_function_handle_parenReference(chartInstance,
      c3_b_y[c3_i47], c3_t[c3_i47]);
  }

  c3_i50 = 0;
  c3_i51 = 0;
  for (c3_i52 = 0; c3_i52 < 80; c3_i52++) {
    c3_i54 = 0;
    for (c3_i55 = 0; c3_i55 < 60; c3_i55++) {
      c3_bw[(c3_i54 + c3_i50) + 1] = c3_b_y[c3_i55 + c3_i51];
      c3_i54 += 2;
    }

    c3_i50 += 240;
    c3_i51 += 60;
  }

  for (c3_i53 = 0; c3_i53 < 2; c3_i53++) {
    c3_sizeIn[c3_i53] = 120.0 + 40.0 * (real_T)c3_i53;
  }

  bwlookup_tbb_boolean(&c3_bw[0], &c3_sizeIn[0], 2.0, &c3_lut[0], 512.0,
                       &c3_newEndPoints[0]);
  for (c3_i56 = 0; c3_i56 < 19200; c3_i56++) {
    c3_newEndPoints[c3_i56] = (c3_endPoints[c3_i56] && c3_newEndPoints[c3_i56]);
  }

  c3_i57 = 0;
  c3_i58 = 0;
  for (c3_i59 = 0; c3_i59 < 80; c3_i59++) {
    c3_i61 = 0;
    for (c3_i63 = 0; c3_i63 < 60; c3_i63++) {
      c3_b_y[c3_i63 + c3_i57] = c3_bw[(c3_i61 + c3_i58) + 121];
      c3_i61 += 2;
    }

    c3_i57 += 60;
    c3_i58 += 240;
  }

  c3_i60 = 0;
  c3_i62 = 0;
  for (c3_i64 = 0; c3_i64 < 80; c3_i64++) {
    c3_i66 = 0;
    for (c3_i67 = 0; c3_i67 < 60; c3_i67++) {
      c3_t[c3_i67 + c3_i60] = c3_newEndPoints[(c3_i66 + c3_i62) + 121];
      c3_i66 += 2;
    }

    c3_i60 += 60;
    c3_i62 += 240;
  }

  for (c3_i65 = 0; c3_i65 < 4800; c3_i65++) {
    c3_b_y[c3_i65] = c3_function_handle_parenReference(chartInstance,
      c3_b_y[c3_i65], c3_t[c3_i65]);
  }

  c3_i68 = 0;
  c3_i69 = 0;
  for (c3_i70 = 0; c3_i70 < 80; c3_i70++) {
    c3_i72 = 0;
    for (c3_i73 = 0; c3_i73 < 60; c3_i73++) {
      c3_bw[(c3_i72 + c3_i68) + 121] = c3_b_y[c3_i73 + c3_i69];
      c3_i72 += 2;
    }

    c3_i68 += 240;
    c3_i69 += 60;
  }

  for (c3_i71 = 0; c3_i71 < 19200; c3_i71++) {
    c3_bw[c3_i71] = !c3_bw[c3_i71];
  }
}

static boolean_T c3_function_handle_parenReference
  (SFc3_flightControlSystemInstanceStruct *chartInstance, boolean_T
   c3_varargin_1, boolean_T c3_varargin_2)
{
  boolean_T c3_b;
  boolean_T c3_b_a;
  boolean_T c3_b_b;
  boolean_T c3_b_varargin_1;
  boolean_T c3_b_varargin_2;
  boolean_T c3_b_y;
  boolean_T c3_c_a;
  boolean_T c3_x;
  (void)chartInstance;
  c3_x = c3_varargin_1;
  c3_b_y = c3_varargin_2;
  c3_b_varargin_1 = c3_x;
  c3_b_varargin_2 = c3_b_y;
  c3_b_a = c3_b_varargin_1;
  c3_b = c3_b_varargin_2;
  c3_c_a = c3_b_a;
  c3_b_b = c3_b;
  return (boolean_T)((int32_T)c3_c_a ^ (int32_T)c3_b_b);
}

static void c3_cat(SFc3_flightControlSystemInstanceStruct *chartInstance,
                   boolean_T c3_varargin_1[19200], boolean_T c3_varargin_2[19200],
                   boolean_T c3_varargin_3[19200], boolean_T c3_b_y[57600])
{
  int32_T c3_b_j;
  int32_T c3_c_j;
  int32_T c3_d_j;
  int32_T c3_iy;
  int32_T c3_j;
  (void)chartInstance;
  c3_iy = -1;
  for (c3_j = 0; c3_j < 19200; c3_j++) {
    c3_c_j = c3_j;
    c3_iy++;
    c3_b_y[c3_iy] = c3_varargin_1[c3_c_j];
  }

  for (c3_b_j = 0; c3_b_j < 19200; c3_b_j++) {
    c3_c_j = c3_b_j;
    c3_iy++;
    c3_b_y[c3_iy] = c3_varargin_2[c3_c_j];
  }

  for (c3_d_j = 0; c3_d_j < 19200; c3_d_j++) {
    c3_c_j = c3_d_j;
    c3_iy++;
    c3_b_y[c3_iy] = c3_varargin_3[c3_c_j];
  }
}

static void c3_eml_find(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, boolean_T c3_x[19200], int32_T c3_i_data[], int32_T
  c3_i_size[1], int32_T c3_j_data[], int32_T c3_j_size[1])
{
  emlrtStack c3_b_st;
  emlrtStack c3_st;
  int32_T c3_iv[2];
  int32_T c3_iv1[2];
  int32_T c3_iv2[2];
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_idx;
  int32_T c3_ii;
  int32_T c3_jj;
  boolean_T c3_b;
  boolean_T c3_b1;
  boolean_T c3_b2;
  boolean_T c3_exitg1;
  boolean_T c3_guard1;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_m_emlrtRSI;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_idx = 0;
  c3_ii = 1;
  c3_jj = 1;
  c3_exitg1 = false;
  while ((!c3_exitg1) && (c3_jj <= 160)) {
    c3_guard1 = false;
    if (c3_x[(c3_ii + 120 * (c3_jj - 1)) - 1]) {
      c3_idx++;
      c3_i_data[c3_idx - 1] = c3_ii;
      c3_j_data[c3_idx - 1] = c3_jj;
      if (c3_idx >= 19200) {
        c3_exitg1 = true;
      } else {
        c3_guard1 = true;
      }
    } else {
      c3_guard1 = true;
    }

    if (c3_guard1) {
      c3_ii++;
      if (c3_ii > 120) {
        c3_ii = 1;
        c3_jj++;
      }
    }
  }

  c3_b = (c3_idx < 1);
  if (c3_b) {
    c3_i = 0;
  } else {
    c3_i = c3_idx;
  }

  c3_iv[0] = 1;
  c3_iv[1] = c3_i;
  c3_b_st.site = &c3_p_emlrtRSI;
  c3_indexShapeCheck(chartInstance, &c3_b_st, 19200, c3_iv);
  c3_i_size[0] = c3_i;
  c3_b1 = (c3_idx < 1);
  if (c3_b1) {
    c3_i1 = 0;
  } else {
    c3_i1 = c3_idx;
  }

  c3_iv1[0] = 1;
  c3_iv1[1] = c3_i1;
  c3_b_st.site = &c3_o_emlrtRSI;
  c3_indexShapeCheck(chartInstance, &c3_b_st, 19200, c3_iv1);
  c3_j_size[0] = c3_i1;
  c3_b2 = (c3_idx < 1);
  if (c3_b2) {
    c3_i2 = 0;
  } else {
    c3_i2 = c3_idx;
  }

  c3_iv2[0] = 1;
  c3_iv2[1] = c3_i2;
  c3_b_st.site = &c3_n_emlrtRSI;
  c3_indexShapeCheck(chartInstance, &c3_b_st, 19200, c3_iv2);
}

static void c3_indexShapeCheck(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_matrixSize, int32_T
  c3_indexSize[2])
{
  static char_T c3_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  int32_T c3_size1;
  boolean_T c3_b;
  boolean_T c3_b_b;
  boolean_T c3_b_c;
  boolean_T c3_c;
  boolean_T c3_nonSingletonDimFound;
  (void)chartInstance;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_size1 = c3_matrixSize;
  if (c3_size1 != 1) {
    c3_b = false;
  } else {
    c3_b = true;
  }

  if (c3_b) {
    c3_nonSingletonDimFound = false;
    if (c3_indexSize[1] != 1) {
      c3_nonSingletonDimFound = true;
    }

    c3_b_b = c3_nonSingletonDimFound;
    if (c3_b_b) {
      c3_c = true;
    } else {
      c3_c = false;
    }
  } else {
    c3_c = false;
  }

  c3_st.site = &c3_q_emlrtRSI;
  c3_b_c = c3_c;
  if (c3_b_c) {
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c3_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_c_y)));
  }
}

static void c3_power(SFc3_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c3_sp, real_T c3_a_data[], int32_T
                     c3_a_size[1], real_T c3_y_data[], int32_T c3_y_size[1])
{
  static char_T c3_cv[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  int32_T c3_i;
  int32_T c3_loop_ub;
  boolean_T c3_p;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_r_emlrtRSI;
  c3_p = false;
  if (c3_p) {
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c3_st, &c3_b_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_c_y)));
  }

  c3_y_size[0] = c3_a_size[0];
  c3_loop_ub = c3_a_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_y_data[c3_i] = c3_b_function_handle_parenReference(chartInstance,
      c3_a_data[c3_i]);
  }
}

static real_T c3_b_function_handle_parenReference
  (SFc3_flightControlSystemInstanceStruct *chartInstance, real_T c3_varargin_1)
{
  real_T c3_b_a;
  real_T c3_x;
  (void)chartInstance;
  c3_x = c3_varargin_1;
  c3_b_a = c3_x;
  return c3_b_a * c3_b_a;
}

static void c3_sqrt(SFc3_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T c3_x_size[1],
                    real_T c3_d_x_data[], int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_d_x_data[c3_i] = c3_c_x_data[c3_i];
  }

  c3_b_sqrt(chartInstance, c3_sp, c3_d_x_data, c3_b_x_size);
}

static void c3_check_forloop_overflow_error
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c3_sp)
{
  static char_T c3_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c3_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c3_sp, &c3_d_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
              sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
    (c3_sp, NULL, "message", 1U, 2U, 14, c3_c_y, 14, c3_d_y)));
}

static boolean_T c3_all(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, boolean_T c3_c_x_data[], int32_T c3_x_size[1])
{
  static char_T c3_cv[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
    'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  real_T c3_b_a;
  real_T c3_vlen;
  int32_T c3_b_b;
  int32_T c3_c;
  int32_T c3_c_a;
  int32_T c3_c_b;
  int32_T c3_d_a;
  int32_T c3_d_b;
  int32_T c3_i2;
  int32_T c3_ix;
  int32_T c3_vspread;
  boolean_T c3_b;
  boolean_T c3_b_y;
  boolean_T c3_exitg1;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_st.site = &c3_v_emlrtRSI;
  if ((c3_x_size[0] == 1) || ((real_T)c3_x_size[0] != 1.0)) {
    c3_b = true;
  } else {
    c3_b = false;
  }

  if (!c3_b) {
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c3_st, &c3_e_emlrtMCI, "error", 0U, 2U, 14, c3_c_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_d_y)));
  }

  c3_b_y = true;
  c3_vlen = (real_T)c3_x_size[0];
  c3_b_a = c3_vlen;
  c3_c = (int32_T)c3_b_a;
  c3_c_a = c3_c - 1;
  c3_vspread = c3_c_a;
  c3_b_b = c3_vspread;
  c3_i2 = c3_b_b;
  c3_d_a = c3_i2 + 1;
  c3_i2 = c3_d_a;
  c3_b_st.site = &c3_w_emlrtRSI;
  c3_c_b = c3_i2;
  c3_d_b = c3_c_b;
  if (c3_d_b < 1) {
    c3_overflow = false;
  } else {
    c3_overflow = (c3_d_b > 2147483646);
  }

  if (c3_overflow) {
    c3_c_st.site = &c3_u_emlrtRSI;
    c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
  }

  c3_ix = 0;
  c3_exitg1 = false;
  while ((!c3_exitg1) && (c3_ix + 1 <= c3_i2)) {
    if (!c3_c_x_data[c3_ix]) {
      c3_b_y = false;
      c3_exitg1 = true;
    } else {
      c3_ix++;
    }
  }

  return c3_b_y;
}

static void c3_sort(SFc3_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T c3_x_size[1],
                    real_T c3_d_x_data[], int32_T c3_b_x_size[1], int32_T
                    c3_idx_data[], int32_T c3_idx_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_d_x_data[c3_i] = c3_c_x_data[c3_i];
  }

  c3_c_sort(chartInstance, c3_sp, c3_d_x_data, c3_b_x_size, c3_idx_data,
            c3_idx_size);
}

static void c3_sortIdx(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T c3_x_size[1], int32_T
  c3_idx_data[], int32_T c3_idx_size[1], real_T c3_d_x_data[], int32_T
  c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_d_x_data[c3_i] = c3_c_x_data[c3_i];
  }

  c3_b_sortIdx(chartInstance, c3_sp, c3_d_x_data, c3_b_x_size, c3_idx_data,
               c3_idx_size);
}

static void c3_merge_pow2_block(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_idx_data[], int32_T
  c3_idx_size[1], real_T c3_c_x_data[], int32_T c3_x_size[1], int32_T c3_offset,
  int32_T c3_b_idx_data[], int32_T c3_b_idx_size[1], real_T c3_d_x_data[],
  int32_T c3_b_x_size[1])
{
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_loop_ub;
  c3_b_idx_size[0] = c3_idx_size[0];
  c3_loop_ub = c3_idx_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_idx_data[c3_i] = c3_idx_data[c3_i];
  }

  c3_b_x_size[0] = c3_x_size[0];
  c3_b_loop_ub = c3_x_size[0] - 1;
  for (c3_i1 = 0; c3_i1 <= c3_b_loop_ub; c3_i1++) {
    c3_d_x_data[c3_i1] = c3_c_x_data[c3_i1];
  }

  c3_b_merge_pow2_block(chartInstance, c3_sp, c3_b_idx_data, c3_d_x_data,
                        c3_offset);
}

static void c3_merge_block(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, int32_T c3_idx_data[], int32_T c3_idx_size[1], real_T
  c3_c_x_data[], int32_T c3_x_size[1], int32_T c3_offset, int32_T c3_n, int32_T
  c3_preSortLevel, int32_T c3_b_iwork_data[], int32_T c3_iwork_size[1], real_T
  c3_b_xwork_data[], int32_T c3_xwork_size[1], int32_T c3_b_idx_data[], int32_T
  c3_b_idx_size[1], real_T c3_d_x_data[], int32_T c3_b_x_size[1], int32_T
  c3_c_iwork_data[], int32_T c3_b_iwork_size[1], real_T c3_c_xwork_data[],
  int32_T c3_b_xwork_size[1])
{
  int32_T c3_b_loop_ub;
  int32_T c3_c_loop_ub;
  int32_T c3_d_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_loop_ub;
  c3_b_idx_size[0] = c3_idx_size[0];
  c3_loop_ub = c3_idx_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_idx_data[c3_i] = c3_idx_data[c3_i];
  }

  c3_b_x_size[0] = c3_x_size[0];
  c3_b_loop_ub = c3_x_size[0] - 1;
  for (c3_i1 = 0; c3_i1 <= c3_b_loop_ub; c3_i1++) {
    c3_d_x_data[c3_i1] = c3_c_x_data[c3_i1];
  }

  c3_b_iwork_size[0] = c3_iwork_size[0];
  c3_c_loop_ub = c3_iwork_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_c_loop_ub; c3_i2++) {
    c3_c_iwork_data[c3_i2] = c3_b_iwork_data[c3_i2];
  }

  c3_b_xwork_size[0] = c3_xwork_size[0];
  c3_d_loop_ub = c3_xwork_size[0] - 1;
  for (c3_i3 = 0; c3_i3 <= c3_d_loop_ub; c3_i3++) {
    c3_c_xwork_data[c3_i3] = c3_b_xwork_data[c3_i3];
  }

  c3_b_merge_block(chartInstance, c3_sp, c3_b_idx_data, c3_d_x_data, c3_offset,
                   c3_n, c3_preSortLevel, c3_c_iwork_data, c3_c_xwork_data);
}

static void c3_merge(SFc3_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c3_sp, int32_T c3_idx_data[], int32_T
                     c3_idx_size[1], real_T c3_c_x_data[], int32_T c3_x_size[1],
                     int32_T c3_offset, int32_T c3_np, int32_T c3_nq, int32_T
                     c3_b_iwork_data[], int32_T c3_iwork_size[1], real_T
                     c3_b_xwork_data[], int32_T c3_xwork_size[1], int32_T
                     c3_b_idx_data[], int32_T c3_b_idx_size[1], real_T
                     c3_d_x_data[], int32_T c3_b_x_size[1], int32_T
                     c3_c_iwork_data[], int32_T c3_b_iwork_size[1], real_T
                     c3_c_xwork_data[], int32_T c3_b_xwork_size[1])
{
  int32_T c3_b_loop_ub;
  int32_T c3_c_loop_ub;
  int32_T c3_d_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_loop_ub;
  c3_b_idx_size[0] = c3_idx_size[0];
  c3_loop_ub = c3_idx_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_idx_data[c3_i] = c3_idx_data[c3_i];
  }

  c3_b_x_size[0] = c3_x_size[0];
  c3_b_loop_ub = c3_x_size[0] - 1;
  for (c3_i1 = 0; c3_i1 <= c3_b_loop_ub; c3_i1++) {
    c3_d_x_data[c3_i1] = c3_c_x_data[c3_i1];
  }

  c3_b_iwork_size[0] = c3_iwork_size[0];
  c3_c_loop_ub = c3_iwork_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_c_loop_ub; c3_i2++) {
    c3_c_iwork_data[c3_i2] = c3_b_iwork_data[c3_i2];
  }

  c3_b_xwork_size[0] = c3_xwork_size[0];
  c3_d_loop_ub = c3_xwork_size[0] - 1;
  for (c3_i3 = 0; c3_i3 <= c3_d_loop_ub; c3_i3++) {
    c3_c_xwork_data[c3_i3] = c3_b_xwork_data[c3_i3];
  }

  c3_b_merge(chartInstance, c3_sp, c3_b_idx_data, c3_d_x_data, c3_offset, c3_np,
             c3_nq, c3_c_iwork_data, c3_c_xwork_data);
}

static void c3_isfinite(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_c_x_data[], int32_T c3_x_size[1], boolean_T c3_b_data[], int32_T
  c3_b_size[1])
{
  int32_T c3_b_b_size[1];
  int32_T c3_b_loop_ub;
  int32_T c3_c_loop_ub;
  int32_T c3_d_loop_ub;
  int32_T c3_e_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_loop_ub;
  boolean_T c3_b_b_data[20];
  (void)chartInstance;
  c3_b_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_b_data[c3_i] = muDoubleScalarIsInf(c3_c_x_data[c3_i]);
  }

  c3_b_loop_ub = c3_b_size[0] - 1;
  for (c3_i1 = 0; c3_i1 <= c3_b_loop_ub; c3_i1++) {
    c3_b_data[c3_i1] = !c3_b_data[c3_i1];
  }

  c3_b_b_size[0] = c3_x_size[0];
  c3_c_loop_ub = c3_x_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_c_loop_ub; c3_i2++) {
    c3_b_b_data[c3_i2] = muDoubleScalarIsNaN(c3_c_x_data[c3_i2]);
  }

  c3_d_loop_ub = c3_b_b_size[0] - 1;
  for (c3_i3 = 0; c3_i3 <= c3_d_loop_ub; c3_i3++) {
    c3_b_b_data[c3_i3] = !c3_b_b_data[c3_i3];
  }

  c3_e_loop_ub = c3_b_size[0] - 1;
  for (c3_i4 = 0; c3_i4 <= c3_e_loop_ub; c3_i4++) {
    c3_b_data[c3_i4] = (c3_b_data[c3_i4] && c3_b_b_data[c3_i4]);
  }
}

static boolean_T c3_issorted(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T
  c3_x_size[1])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_st;
  real_T c3_v[2];
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_d;
  real_T c3_d1;
  real_T c3_d_a;
  real_T c3_e_b;
  real_T c3_f_b;
  real_T c3_g_b;
  real_T c3_x;
  real_T c3_x1;
  real_T c3_x2;
  int32_T c3_subs[2];
  int32_T c3_b_x_size[1];
  int32_T c3_b;
  int32_T c3_b_b;
  int32_T c3_b_dim;
  int32_T c3_b_k;
  int32_T c3_b_n;
  int32_T c3_c_b;
  int32_T c3_c_dim;
  int32_T c3_c_k;
  int32_T c3_d_b;
  int32_T c3_d_dim;
  int32_T c3_dim;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_k;
  int32_T c3_n;
  int32_T c3_nx;
  int32_T c3_varargin_1;
  boolean_T c3_b_overflow;
  boolean_T c3_b_p;
  boolean_T c3_b_y;
  boolean_T c3_exitg1;
  boolean_T c3_exitg2;
  boolean_T c3_h_b;
  boolean_T c3_i_b;
  boolean_T c3_overflow;
  boolean_T c3_p;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_b_y = true;
  c3_b_x_size[0] = c3_x_size[0];
  c3_dim = 2;
  if ((real_T)c3_b_x_size[0] != 1.0) {
    c3_dim = 1;
  }

  if (c3_dim <= 1) {
    c3_d = (real_T)c3_x_size[0];
  } else {
    c3_d = 1.0;
  }

  c3_nx = (int32_T)c3_d;
  if (c3_nx != 1) {
    c3_st.site = &c3_yb_emlrtRSI;
    c3_b_dim = c3_dim;
    if (c3_b_dim == 2) {
      c3_n = 0;
    } else {
      c3_n = 1;
    }

    c3_b_st.site = &c3_bc_emlrtRSI;
    c3_b = c3_n;
    c3_b_b = c3_b;
    if (c3_b_b < 1) {
      c3_overflow = false;
    } else {
      c3_overflow = (c3_b_b > 2147483646);
    }

    if (c3_overflow) {
      c3_c_st.site = &c3_u_emlrtRSI;
      c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
    }

    c3_i = (uint8_T)c3_n - 1;
    c3_k = 0;
    c3_exitg1 = false;
    while ((!c3_exitg1) && (c3_k <= c3_i)) {
      c3_b_st.site = &c3_ac_emlrtRSI;
      c3_c_dim = c3_b_dim;
      c3_b_y = true;
      if (c3_c_dim == 1) {
        c3_d1 = (real_T)c3_x_size[0];
        c3_b_n = (int32_T)c3_d1 - 1;
      } else {
        c3_b_n = c3_x_size[0];
      }

      c3_c_st.site = &c3_bc_emlrtRSI;
      c3_c_b = c3_b_n;
      c3_d_b = c3_c_b;
      if (c3_d_b < 1) {
        c3_b_overflow = false;
      } else {
        c3_b_overflow = (c3_d_b > 2147483646);
      }

      if (c3_b_overflow) {
        c3_d_st.site = &c3_u_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_d_st);
      }

      c3_i1 = (uint8_T)c3_b_n - 1;
      c3_b_k = 1;
      c3_exitg2 = false;
      while ((!c3_exitg2) && (c3_b_k - 1 <= c3_i1)) {
        c3_c_k = c3_b_k;
        c3_d_dim = c3_c_dim - 1;
        c3_varargin_1 = c3_c_k;
        c3_x1 = c3_c_x_data[c3_varargin_1 - 1];
        c3_subs[0] = c3_varargin_1;
        c3_subs[1] = 1;
        c3_subs[c3_d_dim]++;
        c3_x2 = c3_c_x_data[c3_subs[0] - 1];
        c3_v[0] = c3_x1;
        c3_v[1] = c3_x2;
        c3_b_a = c3_v[0];
        c3_e_b = c3_v[1];
        c3_c_a = c3_b_a;
        c3_f_b = c3_e_b;
        c3_d_a = c3_c_a;
        c3_g_b = c3_f_b;
        c3_p = (c3_d_a <= c3_g_b);
        if (c3_p) {
          c3_b_p = true;
        } else {
          c3_x = c3_f_b;
          c3_h_b = muDoubleScalarIsNaN(c3_x);
          if (c3_h_b) {
            c3_b_p = true;
          } else {
            c3_b_p = false;
          }
        }

        c3_i_b = c3_b_p;
        c3_b_y = c3_i_b;
        if (!c3_b_y) {
          c3_exitg2 = true;
        } else {
          c3_b_k++;
        }
      }

      if (!c3_b_y) {
        c3_exitg1 = true;
      } else {
        c3_k++;
      }
    }
  }

  return c3_b_y;
}

static void c3_b_sort(SFc3_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T
                      c3_x_size[1], real_T c3_d_x_data[], int32_T c3_b_x_size[1],
                      int32_T c3_idx_data[], int32_T c3_idx_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_d_x_data[c3_i] = c3_c_x_data[c3_i];
  }

  c3_d_sort(chartInstance, c3_sp, c3_d_x_data, c3_b_x_size, c3_idx_data,
            c3_idx_size);
}

static real_T c3_randn(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp)
{
  static real_T c3_dv[257] = { 0.0, 0.215241895984875, 0.286174591792068,
    0.335737519214422, 0.375121332878378, 0.408389134611989, 0.43751840220787,
    0.46363433679088, 0.487443966139235, 0.50942332960209, 0.529909720661557,
    0.549151702327164, 0.567338257053817, 0.584616766106378, 0.601104617755991,
    0.61689699000775, 0.63207223638606, 0.646695714894993, 0.660822574244419,
    0.674499822837293, 0.687767892795788, 0.700661841106814, 0.713212285190975,
    0.725446140909999, 0.737387211434295, 0.749056662017815, 0.760473406430107,
    0.771654424224568, 0.782615023307232, 0.793369058840623, 0.80392911698997,
    0.814306670135215, 0.824512208752291, 0.834555354086381, 0.844444954909153,
    0.854189171008163, 0.863795545553308, 0.87327106808886, 0.882622229585165,
    0.891855070732941, 0.900975224461221, 0.909987953496718, 0.91889818364959,
    0.927710533401999, 0.936429340286575, 0.945058684468165, 0.953602409881086,
    0.96206414322304, 0.970447311064224, 0.978755155294224, 0.986990747099062,
    0.99515699963509, 1.00325667954467, 1.01129241744, 1.01926671746548,
    1.02718196603564, 1.03504043983344, 1.04284431314415, 1.05059566459093,
    1.05829648333067, 1.06594867476212, 1.07355406579244, 1.0811144097034,
    1.08863139065398, 1.09610662785202, 1.10354167942464, 1.11093804601357,
    1.11829717411934, 1.12562045921553, 1.13290924865253, 1.14016484436815,
    1.14738850542085, 1.15458145035993, 1.16174485944561, 1.16887987673083,
    1.17598761201545, 1.18306914268269, 1.19012551542669, 1.19715774787944,
    1.20416683014438, 1.2111537262437, 1.21811937548548, 1.22506469375653,
    1.23199057474614, 1.23889789110569, 1.24578749554863, 1.2526602218949,
    1.25951688606371, 1.26635828701823, 1.27318520766536, 1.27999841571382,
    1.28679866449324, 1.29358669373695, 1.30036323033084, 1.30712898903073,
    1.31388467315022, 1.32063097522106, 1.32736857762793, 1.33409815321936,
    1.3408203658964, 1.34753587118059, 1.35424531676263, 1.36094934303328,
    1.36764858359748, 1.37434366577317, 1.38103521107586, 1.38772383568998,
    1.39441015092814, 1.40109476367925, 1.4077782768464, 1.41446128977547,
    1.42114439867531, 1.42782819703026, 1.43451327600589, 1.44120022484872,
    1.44788963128058, 1.45458208188841, 1.46127816251028, 1.46797845861808,
    1.47468355569786, 1.48139403962819, 1.48811049705745, 1.49483351578049,
    1.50156368511546, 1.50830159628131, 1.51504784277671, 1.521803020761,
    1.52856772943771, 1.53534257144151, 1.542128153229, 1.54892508547417,
    1.55573398346918, 1.56255546753104, 1.56939016341512, 1.57623870273591,
    1.58310172339603, 1.58997987002419, 1.59687379442279, 1.60378415602609,
    1.61071162236983, 1.61765686957301, 1.62462058283303, 1.63160345693487,
    1.63860619677555, 1.64562951790478, 1.65267414708306, 1.65974082285818,
    1.66683029616166, 1.67394333092612, 1.68108070472517, 1.68824320943719,
    1.69543165193456, 1.70264685479992, 1.7098896570713, 1.71716091501782,
    1.72446150294804, 1.73179231405296, 1.73915426128591, 1.74654827828172,
    1.75397532031767, 1.76143636531891, 1.76893241491127, 1.77646449552452,
    1.78403365954944, 1.79164098655216, 1.79928758454972, 1.80697459135082,
    1.81470317596628, 1.82247454009388, 1.83028991968276, 1.83815058658281,
    1.84605785028518, 1.8540130597602, 1.86201760539967, 1.87007292107127,
    1.878180486293, 1.88634182853678, 1.8945585256707, 1.90283220855043,
    1.91116456377125, 1.91955733659319, 1.92801233405266, 1.93653142827569,
    1.94511656000868, 1.95376974238465, 1.96249306494436, 1.97128869793366,
    1.98015889690048, 1.98910600761744, 1.99813247135842, 2.00724083056053,
    2.0164337349062, 2.02571394786385, 2.03508435372962, 2.04454796521753,
    2.05410793165065, 2.06376754781173, 2.07353026351874, 2.0833996939983,
    2.09337963113879, 2.10347405571488, 2.11368715068665, 2.12402331568952,
    2.13448718284602, 2.14508363404789, 2.15581781987674, 2.16669518035431,
    2.17772146774029, 2.18890277162636, 2.20024554661128, 2.21175664288416,
    2.22344334009251, 2.23531338492992, 2.24737503294739, 2.25963709517379,
    2.27210899022838, 2.28480080272449, 2.29772334890286, 2.31088825060137,
    2.32430801887113, 2.33799614879653, 2.35196722737914, 2.36623705671729,
    2.38082279517208, 2.39574311978193, 2.41101841390112, 2.42667098493715,
    2.44272531820036, 2.4592083743347, 2.47614993967052, 2.49358304127105,
    2.51154444162669, 2.53007523215985, 2.54922155032478, 2.56903545268184,
    2.58957598670829, 2.61091051848882, 2.63311639363158, 2.65628303757674,
    2.68051464328574, 2.70593365612306, 2.73268535904401, 2.76094400527999,
    2.79092117400193, 2.82287739682644, 2.85713873087322, 2.89412105361341,
    2.93436686720889, 2.97860327988184, 3.02783779176959, 3.08352613200214,
    3.147889289518, 3.2245750520478, 3.32024473383983, 3.44927829856143,
    3.65415288536101, 3.91075795952492 };

  static real_T c3_dv1[257] = { 1.0, 0.977101701267673, 0.959879091800108,
    0.9451989534423, 0.932060075959231, 0.919991505039348, 0.908726440052131,
    0.898095921898344, 0.887984660755834, 0.878309655808918, 0.869008688036857,
    0.860033621196332, 0.851346258458678, 0.842915653112205, 0.834716292986884,
    0.826726833946222, 0.818929191603703, 0.811307874312656, 0.803849483170964,
    0.796542330422959, 0.789376143566025, 0.782341832654803, 0.775431304981187,
    0.768637315798486, 0.761953346836795, 0.755373506507096, 0.748892447219157,
    0.742505296340151, 0.736207598126863, 0.729995264561476, 0.72386453346863,
    0.717811932630722, 0.711834248878248, 0.705928501332754, 0.700091918136512,
    0.694321916126117, 0.688616083004672, 0.682972161644995, 0.677388036218774,
    0.671861719897082, 0.66639134390875, 0.660975147776663, 0.655611470579697,
    0.650298743110817, 0.645035480820822, 0.639820277453057, 0.634651799287624,
    0.629528779924837, 0.624450015547027, 0.619414360605834, 0.614420723888914,
    0.609468064925773, 0.604555390697468, 0.599681752619125, 0.594846243767987,
    0.590047996332826, 0.585286179263371, 0.580559996100791, 0.575868682972354,
    0.571211506735253, 0.566587763256165, 0.561996775814525, 0.557437893618766,
    0.552910490425833, 0.548413963255266, 0.543947731190026, 0.539511234256952,
    0.535103932380458, 0.530725304403662, 0.526374847171684, 0.522052074672322,
    0.517756517229756, 0.513487720747327, 0.509245245995748, 0.505028667943468,
    0.500837575126149, 0.49667156905249, 0.492530263643869, 0.488413284705458,
    0.484320269426683, 0.480250865909047, 0.476204732719506, 0.47218153846773,
    0.468180961405694, 0.464202689048174, 0.460246417812843, 0.456311852678716,
    0.452398706861849, 0.448506701507203, 0.444635565395739, 0.440785034665804,
    0.436954852547985, 0.433144769112652, 0.429354541029442, 0.425583931338022,
    0.421832709229496, 0.418100649837848, 0.414387534040891, 0.410693148270188,
    0.407017284329473, 0.403359739221114, 0.399720314980197, 0.396098818515832,
    0.392495061459315, 0.388908860018789, 0.385340034840077, 0.381788410873393,
    0.378253817245619, 0.374736087137891, 0.371235057668239, 0.367750569779032,
    0.364282468129004, 0.360830600989648, 0.357394820145781, 0.353974980800077,
    0.350570941481406, 0.347182563956794, 0.343809713146851, 0.340452257044522,
    0.337110066637006, 0.333783015830718, 0.330470981379163, 0.327173842813601,
    0.323891482376391, 0.320623784956905, 0.317370638029914, 0.314131931596337,
    0.310907558126286, 0.307697412504292, 0.30450139197665, 0.301319396100803,
    0.298151326696685, 0.294997087799962, 0.291856585617095, 0.288729728482183,
    0.285616426815502, 0.282516593083708, 0.279430141761638, 0.276356989295668,
    0.273297054068577, 0.270250256365875, 0.267216518343561, 0.264195763997261,
    0.261187919132721, 0.258192911337619, 0.255210669954662, 0.252241126055942,
    0.249284212418529, 0.246339863501264, 0.24340801542275, 0.240488605940501,
    0.237581574431238, 0.23468686187233, 0.231804410824339, 0.228934165414681,
    0.226076071322381, 0.223230075763918, 0.220396127480152, 0.217574176724331,
    0.214764175251174, 0.211966076307031, 0.209179834621125, 0.206405406397881,
    0.203642749310335, 0.200891822494657, 0.198152586545776, 0.195425003514135,
    0.192709036903589, 0.190004651670465, 0.187311814223801, 0.1846304924268,
    0.181960655599523, 0.179302274522848, 0.176655321443735, 0.174019770081839,
    0.171395595637506, 0.168782774801212, 0.166181285764482, 0.163591108232366,
    0.161012223437511, 0.158444614155925, 0.15588826472448, 0.153343161060263,
    0.150809290681846, 0.148286642732575, 0.145775208005994, 0.143274978973514,
    0.140785949814445, 0.138308116448551, 0.135841476571254, 0.133386029691669,
    0.130941777173644, 0.12850872228, 0.126086870220186, 0.123676228201597,
    0.12127680548479, 0.11888861344291, 0.116511665625611, 0.114145977827839,
    0.111791568163838, 0.109448457146812, 0.107116667774684, 0.104796225622487,
    0.102487158941935, 0.10018949876881, 0.0979032790388625, 0.095628536713009,
    0.093365311912691, 0.0911136480663738, 0.0888735920682759,
    0.0866451944505581, 0.0844285095703535, 0.082223595813203,
    0.0800305158146631, 0.0778493367020961, 0.0756801303589272,
    0.0735229737139814, 0.0713779490588905, 0.0692451443970068,
    0.0671246538277886, 0.065016577971243, 0.0629210244377582, 0.06083810834954,
    0.0587679529209339, 0.0567106901062031, 0.0546664613248891,
    0.0526354182767924, 0.0506177238609479, 0.0486135532158687,
    0.0466230949019305, 0.0446465522512946, 0.0426841449164746,
    0.0407361106559411, 0.0388027074045262, 0.0368842156885674,
    0.0349809414617162, 0.0330932194585786, 0.0312214171919203,
    0.0293659397581334, 0.0275272356696031, 0.0257058040085489,
    0.0239022033057959, 0.0221170627073089, 0.0203510962300445,
    0.0186051212757247, 0.0168800831525432, 0.0151770883079353,
    0.0134974506017399, 0.0118427578579079, 0.0102149714397015,
    0.00861658276939875, 0.00705087547137324, 0.00552240329925101,
    0.00403797259336304, 0.00260907274610216, 0.0012602859304986,
    0.000477467764609386 };

  static uint32_T c3_uv[625] = { 5489U, 1301868182U, 2938499221U, 2950281878U,
    1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U, 219885934U,
    2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U, 3418470598U,
    951210697U, 3693558366U, 2923482051U, 1793174584U, 2982310801U, 1586906132U,
    1951078751U, 1808158765U, 1733897588U, 431328322U, 4202539044U, 530658942U,
    1714810322U, 3025256284U, 3342585396U, 1937033938U, 2640572511U, 1654299090U,
    3692403553U, 4233871309U, 3497650794U, 862629010U, 2943236032U, 2426458545U,
    1603307207U, 1133453895U, 3099196360U, 2208657629U, 2747653927U, 931059398U,
    761573964U, 3157853227U, 785880413U, 730313442U, 124945756U, 2937117055U,
    3295982469U, 1724353043U, 3021675344U, 3884886417U, 4010150098U, 4056961966U,
    699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U, 2376097373U,
    1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U, 3570962471U,
    4287636090U, 4087307012U, 3603343627U, 202242161U, 2995682783U, 1620962684U,
    3704723357U, 371613603U, 2814834333U, 2111005706U, 624778151U, 2094172212U,
    4284947003U, 1211977835U, 991917094U, 1570449747U, 2962370480U, 1259410321U,
    170182696U, 146300961U, 2836829791U, 619452428U, 2723670296U, 1881399711U,
    1161269684U, 1675188680U, 4132175277U, 780088327U, 3409462821U, 1036518241U,
    1834958505U, 3048448173U, 161811569U, 618488316U, 44795092U, 3918322701U,
    1924681712U, 3239478144U, 383254043U, 4042306580U, 2146983041U, 3992780527U,
    3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U, 2339662006U,
    501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U, 3393774360U,
    1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U, 819755096U,
    2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U, 1029741190U,
    2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U, 2701024045U,
    4117700889U, 759495121U, 3332270341U, 2313004527U, 2277067795U, 4131855432U,
    2722057515U, 1264804546U, 3848622725U, 2211267957U, 4100593547U, 959123777U,
    2130745407U, 3194437393U, 486673947U, 1377371204U, 17472727U, 352317554U,
    3955548058U, 159652094U, 1232063192U, 3835177280U, 49423123U, 3083993636U,
    733092U, 2120519771U, 2573409834U, 1112952433U, 3239502554U, 761045320U,
    1087580692U, 2540165110U, 641058802U, 1792435497U, 2261799288U, 1579184083U,
    627146892U, 2165744623U, 2200142389U, 2167590760U, 2381418376U, 1793358889U,
    3081659520U, 1663384067U, 2009658756U, 2689600308U, 739136266U, 2304581039U,
    3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U, 2076220115U,
    3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U, 12350217U,
    354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U, 2616064085U,
    1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U, 1684529556U,
    1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U, 171579916U,
    3878728600U, 2475806724U, 2030324028U, 3331164912U, 1708711359U, 1970023127U,
    2859691344U, 2588476477U, 2748146879U, 136111222U, 2967685492U, 909517429U,
    2835297809U, 3206906216U, 3186870716U, 341264097U, 2542035121U, 3353277068U,
    548223577U, 3170936588U, 1678403446U, 297435620U, 2337555430U, 466603495U,
    1132321815U, 1208589219U, 696392160U, 894244439U, 2562678859U, 470224582U,
    3306867480U, 201364898U, 2075966438U, 1767227936U, 2929737987U, 3674877796U,
    2654196643U, 3692734598U, 3528895099U, 2796780123U, 3048728353U, 842329300U,
    191554730U, 2922459673U, 3489020079U, 3979110629U, 1022523848U, 2202932467U,
    3583655201U, 3565113719U, 587085778U, 4176046313U, 3013713762U, 950944241U,
    396426791U, 3784844662U, 3477431613U, 3594592395U, 2782043838U, 3392093507U,
    3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U, 31522386U,
    2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U, 1521001832U,
    3605886097U, 2802786495U, 2728923319U, 3996284304U, 903417639U, 1171249804U,
    1020374987U, 2824535874U, 423621996U, 1988534473U, 2493544470U, 1008604435U,
    1756003503U, 1488867287U, 1386808992U, 732088248U, 1780630732U, 2482101014U,
    976561178U, 1543448953U, 2602866064U, 2021139923U, 1952599828U, 2360242564U,
    2117959962U, 2753061860U, 2388623612U, 4138193781U, 2962920654U, 2284970429U,
    766920861U, 3457264692U, 2879611383U, 815055854U, 2332929068U, 1254853997U,
    3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U, 686850534U,
    1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U, 4195430425U,
    607905174U, 3902331779U, 2454067926U, 1708133115U, 1170874362U, 2008609376U,
    3260320415U, 2211196135U, 433538229U, 2728786374U, 2189520818U, 262554063U,
    1182318347U, 3710237267U, 1221022450U, 715966018U, 2417068910U, 2591870721U,
    2870691989U, 3418190842U, 4238214053U, 1540704231U, 1575580968U, 2095917976U,
    4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U, 1123218514U,
    551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U, 422862282U,
    3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U, 1324564878U,
    1928816105U, 1786535431U, 2878099422U, 3290185549U, 539474248U, 1657512683U,
    552370646U, 1671741683U, 3655312128U, 1552739510U, 2605208763U, 1441755014U,
    181878989U, 3124053868U, 1447103986U, 3183906156U, 1728556020U, 3502241336U,
    3055466967U, 1013272474U, 818402132U, 1715099063U, 2900113506U, 397254517U,
    4194863039U, 1009068739U, 232864647U, 2540223708U, 2608288560U, 2415367765U,
    478404847U, 3455100648U, 3182600021U, 2115988978U, 434269567U, 4117179324U,
    3461774077U, 887256537U, 3545801025U, 286388911U, 3451742129U, 1981164769U,
    786667016U, 3310123729U, 3097811076U, 2224235657U, 2959658883U, 3370969234U,
    2514770915U, 3345656436U, 2677010851U, 2206236470U, 271648054U, 2342188545U,
    4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U, 1477814055U,
    4043852216U, 1876372354U, 3133294443U, 3871104810U, 3177020907U, 2074304428U,
    3479393793U, 759562891U, 164128153U, 1839069216U, 2114162633U, 3989947309U,
    3611054956U, 1333547922U, 835429831U, 494987340U, 171987910U, 1252001001U,
    370809172U, 3508925425U, 2535703112U, 1276855041U, 1922855120U, 835673414U,
    3030664304U, 613287117U, 171219893U, 3423096126U, 3376881639U, 2287770315U,
    1658692645U, 1262815245U, 3957234326U, 1168096164U, 2968737525U, 2655813712U,
    2132313144U, 3976047964U, 326516571U, 353088456U, 3679188938U, 3205649712U,
    2654036126U, 1249024881U, 880166166U, 691800469U, 2229503665U, 1673458056U,
    4032208375U, 1851778863U, 2563757330U, 376742205U, 1794655231U, 340247333U,
    1505873033U, 396524441U, 879666767U, 3335579166U, 3260764261U, 3335999539U,
    506221798U, 4214658741U, 975887814U, 2080536343U, 3360539560U, 571586418U,
    138896374U, 4234352651U, 2737620262U, 3928362291U, 1516365296U, 38056726U,
    3599462320U, 3585007266U, 3850961033U, 471667319U, 1536883193U, 2310166751U,
    1861637689U, 2530999841U, 4139843801U, 2710569485U, 827578615U, 2012334720U,
    2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U, 2478379033U,
    643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U, 3285177704U,
    1948416081U, 1311525291U, 1183517742U, 1739192232U, 3979815115U, 2567840007U,
    4116821529U, 213304419U, 4125718577U, 1473064925U, 2442436592U, 1893310111U,
    4195361916U, 3747569474U, 828465101U, 2991227658U, 750582866U, 1205170309U,
    1409813056U, 678418130U, 1171531016U, 3821236156U, 354504587U, 4202874632U,
    3882511497U, 1893248677U, 1903078632U, 26340130U, 2069166240U, 3657122492U,
    3725758099U, 831344905U, 811453383U, 3447711422U, 2434543565U, 4166886888U,
    3358210805U, 4142984013U, 2988152326U, 3527824853U, 982082992U, 2809155763U,
    190157081U, 3340214818U, 2365432395U, 2548636180U, 2894533366U, 3474657421U,
    2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U, 3186502468U,
    453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U, 3541393095U,
    4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U, 1795580598U,
    2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U, 705213300U,
    363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U, 2199989172U,
    1987356470U, 4026755612U, 2147252133U, 270400031U, 1367820199U, 2369854699U,
    2844269403U, 79981964U, 624U };

  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_e_st;
  emlrtStack c3_f_st;
  emlrtStack c3_st;
  real_T c3_b_r;
  real_T c3_b_u;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_u;
  real_T c3_c_x;
  real_T c3_d;
  real_T c3_d_u;
  real_T c3_d_x;
  real_T c3_e_u;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_x;
  int32_T c3_exitg1;
  int32_T c3_i;
  int32_T c3_i1;
  uint32_T c3_u32[2];
  uint32_T c3_b_i;
  uint32_T c3_ip1;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_cc_emlrtRSI;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_e_st.prev = &c3_d_st;
  c3_e_st.tls = c3_d_st.tls;
  c3_f_st.prev = &c3_e_st;
  c3_f_st.tls = c3_e_st.tls;
  if (!chartInstance->c3_method_not_empty) {
    chartInstance->c3_method = 0U;
    chartInstance->c3_method_not_empty = true;
    for (c3_i = 0; c3_i < 2; c3_i++) {
      chartInstance->c3_state[c3_i] = 362436069U + 158852560U * (uint32_T)c3_i;
    }

    chartInstance->c3_state_not_empty = true;
  }

  c3_b_st.site = &c3_dc_emlrtRSI;
  if (!chartInstance->c3_b_method_not_empty) {
    chartInstance->c3_b_method = 7U;
    chartInstance->c3_b_method_not_empty = true;
  }

  c3_c_st.site = &c3_ec_emlrtRSI;
  if (!chartInstance->c3_d_state_not_empty) {
    for (c3_i1 = 0; c3_i1 < 625; c3_i1++) {
      chartInstance->c3_d_state[c3_i1] = c3_uv[c3_i1];
    }

    chartInstance->c3_d_state_not_empty = true;
  }

  c3_d_st.site = &c3_fc_emlrtRSI;
  c3_e_st.site = &c3_gc_emlrtRSI;
  do {
    c3_exitg1 = 0;
    c3_b_genrand_uint32_vector(chartInstance, chartInstance->c3_d_state, c3_u32);
    c3_b_i = (c3_u32[1] >> 24U) + 1U;
    c3_ip1 = c3_b_i + 1U;
    c3_b_u = ((real_T)(c3_u32[0] >> 3U) * 1.6777216E+7 + (real_T)(c3_u32[1] &
               16777215U)) * 2.2204460492503131E-16 - 1.0;
    c3_b_r = c3_b_u * c3_dv[(int32_T)c3_ip1 - 1];
    c3_x = c3_b_r;
    c3_b_x = c3_x;
    c3_c_x = c3_b_x;
    c3_b_y = muDoubleScalarAbs(c3_c_x);
    if (c3_b_y <= c3_dv[(int32_T)c3_b_i - 1]) {
      c3_exitg1 = 1;
    } else if ((real_T)c3_b_i < 256.0) {
      c3_f_st.site = &c3_hc_emlrtRSI;
      c3_c_u = c3_b_genrandu(chartInstance, &c3_f_st, chartInstance->c3_d_state);
      c3_d_x = -0.5 * c3_b_r * c3_b_r;
      c3_f_x = c3_d_x;
      c3_f_x = muDoubleScalarExp(c3_f_x);
      if (c3_dv1[(int32_T)c3_ip1 - 1] + c3_c_u * (c3_dv1[(int32_T)c3_b_i - 1] -
           c3_dv1[(int32_T)c3_ip1 - 1]) < c3_f_x) {
        c3_exitg1 = 1;
      }
    } else {
      do {
        c3_f_st.site = &c3_ic_emlrtRSI;
        c3_d_u = c3_b_genrandu(chartInstance, &c3_f_st,
          chartInstance->c3_d_state);
        c3_e_x = muDoubleScalarLog(c3_d_u) * 0.273661237329758;
        c3_f_st.site = &c3_jc_emlrtRSI;
        c3_e_u = c3_b_genrandu(chartInstance, &c3_f_st,
          chartInstance->c3_d_state);
      } while (!(-2.0 * muDoubleScalarLog(c3_e_u) > c3_e_x * c3_e_x));

      if (c3_b_r < 0.0) {
        c3_b_r = c3_e_x - 3.65415288536101;
      } else {
        c3_b_r = 3.65415288536101 - c3_e_x;
      }

      c3_exitg1 = 1;
    }
  } while (c3_exitg1 == 0);

  c3_d = c3_b_r;
  return c3_d;
}

static void c3_genrand_uint32_vector(SFc3_flightControlSystemInstanceStruct
  *chartInstance, uint32_T c3_mt[625], uint32_T c3_b_mt[625], uint32_T c3_b_u[2])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 625; c3_i++) {
    c3_b_mt[c3_i] = c3_mt[c3_i];
  }

  c3_b_genrand_uint32_vector(chartInstance, c3_b_mt, c3_b_u);
}

static void c3_genrandu(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, uint32_T c3_mt[625], uint32_T c3_b_mt[625], real_T
  *c3_r)
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 625; c3_i++) {
    c3_b_mt[c3_i] = c3_mt[c3_i];
  }

  *c3_r = c3_b_genrandu(chartInstance, c3_sp, c3_b_mt);
}

static void c3_string_disp(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp)
{
  static char_T c3_cv[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  static char_T c3_varargin_1[5] = { 's', 't', 'a', 'r', 't' };

  static char_T c3_cv1[4] = { '%', 's', '\\', 'n' };

  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  real_T c3_b_u;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_st.site = &c3_kc_emlrtRSI;
  c3_b_st.site = &c3_lc_emlrtRSI;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c3_b_u = 1.0;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_varargin_1, 10, 0U, 1U, 0U, 2, 1,
    5), false);
  c3_c_st.site = &c3_mc_emlrtRSI;
  c3_emlrt_marshallIn(chartInstance, c3_feval(chartInstance, &c3_c_st, c3_b_y,
    c3_c_y, c3_d_y, c3_e_y), "<output of feval>");
}

static void c3_b_string_disp(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp)
{
  static char_T c3_cv[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  static char_T c3_varargin_1[6] = { 'f', 'i', 'n', 'i', 's', 'h' };

  static char_T c3_cv1[4] = { '%', 's', '\\', 'n' };

  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  real_T c3_b_u;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_st.site = &c3_kc_emlrtRSI;
  c3_b_st.site = &c3_lc_emlrtRSI;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c3_b_u = 1.0;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_varargin_1, 10, 0U, 1U, 0U, 2, 1,
    6), false);
  c3_c_st.site = &c3_mc_emlrtRSI;
  c3_emlrt_marshallIn(chartInstance, c3_b_feval(chartInstance, &c3_c_st, c3_b_y,
    c3_c_y, c3_d_y, c3_e_y), "<output of feval>");
}

static real_T c3_minimum(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_c_x_data[], int32_T c3_x_size[1])
{
  real_T c3_b_ex;
  int32_T c3_b_last;
  int32_T c3_k;
  int32_T c3_last;
  (void)chartInstance;
  c3_last = c3_x_size[0];
  c3_b_last = c3_last;
  c3_b_ex = c3_c_x_data[0];
  for (c3_k = 2; c3_k <= c3_b_last; c3_k++) {
    if (c3_b_ex > c3_c_x_data[c3_k - 1]) {
      c3_b_ex = c3_c_x_data[c3_k - 1];
    }
  }

  return c3_b_ex;
}

static real_T c3_maximum(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_c_x_data[], int32_T c3_x_size[1])
{
  real_T c3_b_ex;
  int32_T c3_b_last;
  int32_T c3_k;
  int32_T c3_last;
  (void)chartInstance;
  c3_last = c3_x_size[0];
  c3_b_last = c3_last;
  c3_b_ex = c3_c_x_data[0];
  for (c3_k = 2; c3_k <= c3_b_last; c3_k++) {
    if (c3_b_ex < c3_c_x_data[c3_k - 1]) {
      c3_b_ex = c3_c_x_data[c3_k - 1];
    }
  }

  return c3_b_ex;
}

static void c3_linspace(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_d1, real_T c3_d2, real_T c3_b_y[20])
{
  real_T c3_b_d1;
  real_T c3_b_d2;
  real_T c3_d2scaled;
  real_T c3_d_k;
  real_T c3_delta1;
  real_T c3_delta2;
  int32_T c3_b;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_c_y;
  int32_T c3_k;
  (void)chartInstance;
  c3_b_d1 = c3_d1;
  c3_b_d2 = c3_d2;
  c3_b_y[19] = c3_b_d2;
  c3_b_y[0] = c3_b_d1;
  if (c3_b_d1 == -c3_b_d2) {
    c3_d2scaled = c3_b_d2 / 19.0;
    for (c3_k = 0; c3_k < 18; c3_k++) {
      c3_b = c3_k + 2;
      c3_c_y = (c3_b << 1) - 21;
      c3_b_y[c3_k + 1] = (real_T)c3_c_y * c3_d2scaled;
    }
  } else if (((c3_b_d1 < 0.0) != (c3_b_d2 < 0.0)) && ((muDoubleScalarAbs(c3_b_d1)
    > 8.9884656743115785E+307) || (muDoubleScalarAbs(c3_b_d2) >
               8.9884656743115785E+307))) {
    c3_delta1 = c3_b_d1 / 19.0;
    c3_delta2 = c3_b_d2 / 19.0;
    for (c3_c_k = 0; c3_c_k < 18; c3_c_k++) {
      c3_d_k = (real_T)c3_c_k + 1.0;
      c3_b_y[(int32_T)(c3_d_k + 1.0) - 1] = (c3_b_d1 + c3_delta2 * c3_d_k) -
        c3_delta1 * c3_d_k;
    }
  } else {
    c3_delta1 = (c3_b_d2 - c3_b_d1) / 19.0;
    for (c3_b_k = 0; c3_b_k < 18; c3_b_k++) {
      c3_d_k = (real_T)c3_b_k + 1.0;
      c3_b_y[(int32_T)(c3_d_k + 1.0) - 1] = c3_b_d1 + c3_d_k * c3_delta1;
    }
  }
}

static void c3_interp1(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_varargin_1_data[], int32_T
  c3_varargin_1_size[1], real_T c3_varargin_2_data[], int32_T
  c3_varargin_2_size[1], real_T c3_varargin_3[20], real_T c3_Vq[20])
{
  static char_T c3_cv[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'v', 's', 'i',
    'z', 'e', 'M', 'a', 't', 'r', 'i', 'x', 'B', 'e', 'c', 'a', 'm', 'e', 'R',
    'o', 'w', 'V', 'e', 'c' };

  static char_T c3_cv1[36] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'Y', 'I', 'n', 'v',
    'a', 'l', 'i', 'd', 'N', 'u', 'm', 'R', 'o', 'w', 's' };

  static char_T c3_cv3[35] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'n', 'o', 'n',
    'M', 'o', 'n', 'o', 't', 'o', 'n', 'i', 'c', 'X' };

  static char_T c3_cv2[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 't',
    'e', 'r', 'p', '1', ':', 'N', 'a', 'N', 'i', 'n', 'X' };

  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_i_y = NULL;
  real_T c3_c_x_data[20];
  real_T c3_y_data[20];
  real_T c3_b_maxx;
  real_T c3_b_minx;
  real_T c3_b_penx;
  real_T c3_b_x;
  real_T c3_maxx;
  real_T c3_minx;
  real_T c3_onemr;
  real_T c3_penx;
  real_T c3_r;
  real_T c3_tmp;
  real_T c3_x;
  real_T c3_xi;
  real_T c3_xik;
  real_T c3_xn;
  real_T c3_xnp1;
  real_T c3_xtmp;
  real_T c3_y1;
  real_T c3_y2;
  int32_T c3_x_size[1];
  int32_T c3_y_size[1];
  int32_T c3_b_b;
  int32_T c3_b_high_i;
  int32_T c3_b_j1;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
  int32_T c3_b_low_i;
  int32_T c3_b_n;
  int32_T c3_b_nx;
  int32_T c3_b_nyrows;
  int32_T c3_c_b;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_e_b;
  int32_T c3_e_k;
  int32_T c3_exitg1;
  int32_T c3_f_b;
  int32_T c3_f_k;
  int32_T c3_g_k;
  int32_T c3_h_b;
  int32_T c3_h_k;
  int32_T c3_high_i;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i_b;
  int32_T c3_j1;
  int32_T c3_k;
  int32_T c3_loop_ub;
  int32_T c3_low_i;
  int32_T c3_low_ip1;
  int32_T c3_mid_i;
  int32_T c3_n;
  int32_T c3_nd2;
  int32_T c3_nx;
  int32_T c3_nyrows;
  int32_T c3_xend;
  boolean_T c3_b;
  boolean_T c3_b_overflow;
  boolean_T c3_c_overflow;
  boolean_T c3_d_b;
  boolean_T c3_g_b;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_st.site = &c3_tc_emlrtRSI;
  c3_y_size[0] = c3_varargin_2_size[0];
  c3_loop_ub = c3_varargin_2_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_y_data[c3_i] = c3_varargin_2_data[c3_i];
  }

  c3_x_size[0] = c3_varargin_1_size[0];
  c3_b_loop_ub = c3_varargin_1_size[0] - 1;
  for (c3_i1 = 0; c3_i1 <= c3_b_loop_ub; c3_i1++) {
    c3_c_x_data[c3_i1] = c3_varargin_1_data[c3_i1];
  }

  if ((c3_y_size[0] == 1) || ((real_T)c3_y_size[0] != 1.0)) {
    c3_b = true;
  } else {
    c3_b = false;
  }

  if (!c3_b) {
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 45),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 45),
                  false);
    sf_mex_call(&c3_st, &c3_h_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_c_y)));
  }

  c3_nyrows = c3_y_size[0];
  c3_nx = c3_x_size[0];
  if (c3_nx != c3_nyrows) {
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c3_e_y = NULL;
    sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c3_st, &c3_i_emlrtMCI, "error", 0U, 2U, 14, c3_d_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_e_y)));
  }

  c3_b_st.site = &c3_wc_emlrtRSI;
  c3_b_b = c3_nx;
  c3_c_b = c3_b_b;
  if (c3_c_b < 1) {
    c3_overflow = false;
  } else {
    c3_overflow = (c3_c_b > 2147483646);
  }

  if (c3_overflow) {
    c3_c_st.site = &c3_u_emlrtRSI;
    c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
  }

  c3_i2 = (uint8_T)c3_nx - 1;
  c3_k = 1;
  do {
    c3_exitg1 = 0;
    if (c3_k - 1 <= c3_i2) {
      c3_b_k = c3_k - 1;
      c3_x = c3_c_x_data[c3_b_k];
      c3_d_b = muDoubleScalarIsNaN(c3_x);
      if (c3_d_b) {
        c3_f_y = NULL;
        sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_cv2, 10, 0U, 1U, 0U, 2, 1,
          21), false);
        c3_h_y = NULL;
        sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_cv2, 10, 0U, 1U, 0U, 2, 1,
          21), false);
        sf_mex_call(&c3_st, &c3_j_emlrtMCI, "error", 0U, 2U, 14, c3_f_y, 14,
                    sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c3_st, NULL, "message", 1U, 1U, 14, c3_h_y)));
        c3_exitg1 = 1;
      } else {
        c3_k++;
      }
    } else {
      if (c3_c_x_data[1] < c3_c_x_data[0]) {
        c3_i3 = c3_nx >> 1;
        c3_b_st.site = &c3_vc_emlrtRSI;
        c3_e_b = c3_i3;
        c3_f_b = c3_e_b;
        if (c3_f_b < 1) {
          c3_b_overflow = false;
        } else {
          c3_b_overflow = (c3_f_b > 2147483646);
        }

        if (c3_b_overflow) {
          c3_c_st.site = &c3_u_emlrtRSI;
          c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
        }

        c3_i4 = (uint8_T)c3_i3 - 1;
        for (c3_j1 = 0; c3_j1 <= c3_i4; c3_j1++) {
          c3_b_j1 = c3_j1;
          c3_xtmp = c3_c_x_data[c3_b_j1];
          c3_c_x_data[c3_b_j1] = c3_c_x_data[(c3_nx - c3_b_j1) - 1];
          c3_c_x_data[(c3_nx - c3_b_j1) - 1] = c3_xtmp;
        }

        c3_b_st.site = &c3_uc_emlrtRSI;
        if ((c3_y_size[0] != 0) && ((real_T)c3_y_size[0] > 1.0)) {
          c3_n = c3_y_size[0];
          c3_nd2 = c3_n >> 1;
          c3_c_st.site = &c3_xc_emlrtRSI;
          c3_h_b = c3_nd2;
          c3_i_b = c3_h_b;
          if (c3_i_b < 1) {
            c3_c_overflow = false;
          } else {
            c3_c_overflow = (c3_i_b > 2147483646);
          }

          if (c3_c_overflow) {
            c3_d_st.site = &c3_u_emlrtRSI;
            c3_check_forloop_overflow_error(chartInstance, &c3_d_st);
          }

          c3_i5 = (uint8_T)c3_nd2 - 1;
          for (c3_g_k = 0; c3_g_k <= c3_i5; c3_g_k++) {
            c3_h_k = c3_g_k;
            c3_tmp = c3_y_data[c3_h_k];
            c3_y_data[c3_h_k] = c3_y_data[(c3_n - c3_h_k) - 1];
            c3_y_data[(c3_n - c3_h_k) - 1] = c3_tmp;
          }
        }
      }

      for (c3_c_k = 2; c3_c_k <= c3_nx; c3_c_k++) {
        if (c3_c_x_data[c3_c_k - 1] <= c3_c_x_data[c3_c_k - 2]) {
          c3_g_y = NULL;
          sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_cv3, 10, 0U, 1U, 0U, 2, 1,
            35), false);
          c3_i_y = NULL;
          sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_cv3, 10, 0U, 1U, 0U, 2, 1,
            35), false);
          sf_mex_call(&c3_st, &c3_k_emlrtMCI, "error", 0U, 2U, 14, c3_g_y, 14,
                      sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c3_st, NULL, "message", 1U, 1U, 14, c3_i_y)));
        }
      }

      c3_b_nyrows = c3_nyrows;
      c3_minx = c3_c_x_data[0];
      c3_penx = c3_c_x_data[(int32_T)((real_T)c3_x_size[0] - 1.0) - 1];
      c3_maxx = c3_c_x_data[c3_x_size[0] - 1];
      for (c3_d_k = 0; c3_d_k < 20; c3_d_k++) {
        c3_e_k = c3_d_k;
        c3_f_k = c3_e_k;
        c3_b_nx = c3_b_nyrows - 1;
        c3_b_minx = c3_minx;
        c3_b_penx = c3_penx;
        c3_b_maxx = c3_maxx;
        c3_xik = c3_varargin_3[c3_f_k];
        c3_b_x = c3_xik;
        c3_g_b = muDoubleScalarIsNaN(c3_b_x);
        if (c3_g_b) {
          c3_Vq[c3_f_k] = rtNaN;
        } else if (c3_xik > c3_b_maxx) {
          c3_r = (c3_xik - c3_b_maxx) / (c3_b_maxx - c3_b_penx);
          c3_Vq[c3_f_k] = c3_y_data[c3_b_nx] + c3_r * (c3_y_data[c3_b_nx] -
            c3_y_data[c3_b_nx - 1]);
        } else if (c3_xik < c3_b_minx) {
          c3_r = (c3_xik - c3_b_minx) / (c3_c_x_data[1] - c3_b_minx);
          c3_Vq[c3_f_k] = c3_y_data[0] + c3_r * (c3_y_data[1] - c3_y_data[0]);
        } else {
          c3_xi = c3_xik;
          c3_xend = c3_x_size[0];
          c3_low_i = 1;
          c3_low_ip1 = 1;
          c3_high_i = c3_xend;
          while (c3_high_i > c3_low_ip1 + 1) {
            c3_b_low_i = c3_low_i;
            c3_b_high_i = c3_high_i;
            c3_mid_i = (c3_b_low_i >> 1) + (c3_b_high_i >> 1);
            if (((c3_b_low_i & 1) == 1) && ((c3_b_high_i & 1) == 1)) {
              c3_mid_i++;
            }

            if (c3_xi >= c3_c_x_data[c3_mid_i - 1]) {
              c3_low_i = c3_mid_i;
              c3_low_ip1 = c3_mid_i;
            } else {
              c3_high_i = c3_mid_i;
            }
          }

          c3_b_n = c3_low_i;
          c3_xn = c3_c_x_data[c3_b_n - 1];
          c3_xnp1 = c3_c_x_data[c3_b_n];
          c3_r = (c3_xik - c3_xn) / (c3_xnp1 - c3_xn);
          c3_onemr = 1.0 - c3_r;
          if (c3_r == 0.0) {
            c3_y1 = c3_y_data[c3_b_n - 1];
            c3_Vq[c3_f_k] = c3_y1;
          } else if (c3_r == 1.0) {
            c3_y2 = c3_y_data[c3_b_n];
            c3_Vq[c3_f_k] = c3_y2;
          } else {
            c3_y1 = c3_y_data[c3_b_n - 1];
            c3_y2 = c3_y_data[c3_b_n];
            if (c3_y1 == c3_y2) {
              c3_Vq[c3_f_k] = c3_y1;
            } else {
              c3_Vq[c3_f_k] = c3_onemr * c3_y1 + c3_r * c3_y2;
            }
          }
        }
      }

      c3_exitg1 = 1;
    }
  } while (c3_exitg1 == 0);
}

const mxArray *sf_c3_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  const char_T *c3_data[5] = {
    "789ced54cb4ac340149d4805051f59f905dd290d15445c6ba581b6545b4414a9794c4de83cc264d4f62bf4335cfa09aefd2a9bc7b449ec90d0425d98bbe8bd97"
    "3373cf99937281a2b71500c01e88a2b913e5ddb857e3bc01d291c595cc39257d1c6c824aea9ec0dfe26c51c2e198470d31309cddb429768941787fe241c0a04f",
    "d10bb44364e822d87731ec259b4ed0e1cb04346b0228a8cf1d688d7acf1830c79f2b44c966e6c7a7e4bd95827eb4247ea819fc5e6fdd361eaad8e0c83019a5bc"
    "aa714a9149c71ac44843aea94598e65134193e13cd9d1ac6bc7a0d2b3dce5cf2d4a76dc81d6aeb1749fdef2bea3fcad12f708bda90d5424dc4405131556a7018",
    "d79138bf41a6be27f43d2ea92f1b327d2204dfd7927c62fe20874fe0c1f7ec2cfe9ebe6330686ba163f1ef619c847f711519a8fd32b08673fddb2ff89e6c9e9f"
    "df0ab3f7bd6d06795d7c22fe0bdf5832afe8fff140c2a766f0b6de3db981eee9dd59fbf8daa2ec0ad775d69cebe8e6f0e4e900927e5df33f24f78bfad894cc57",
    "33f82a7b3aae06af948dcafd9c8e723f2f7e4fb99fff96afdccfabcdff01e551edd5", "" };

  c3_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&c3_data[0], 3168U, &c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const real_T
   c3_u_data[], const int32_T c3_u_size[1])
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", (void *)c3_u_data, 0, 0U, 1U, 0U, 1,
    c3_u_size[0]), false);
  return c3_b_y;
}

static real_T c3_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_a__output_of_feval_, const char_T
  *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_a__output_of_feval_), &c3_thisId);
  sf_mex_destroy(&c3_a__output_of_feval_);
  return c3_b_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_b_y;
  real_T c3_d;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_d, 1, 0, 0U, 0, 0U, 0);
  c3_b_y = c3_d;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_c_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_c_outt, const char_T *c3_identifier, uint8_T
  c3_b_y[57600])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_c_outt), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_c_outt);
}

static void c3_d_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  uint8_T c3_b_y[57600])
{
  int32_T c3_i;
  uint8_T c3_uv[57600];
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_uv, 1, 3, 0U, 1, 0U, 3, 120,
                160, 3);
  for (c3_i = 0; c3_i < 57600; c3_i++) {
    c3_b_y[c3_i] = c3_uv[c3_i];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_e_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_pointsx, const char_T *c3_identifier,
  real_T c3_b_y[20])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_pointsx), &c3_thisId,
                        c3_b_y);
  sf_mex_destroy(&c3_b_pointsx);
}

static void c3_f_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_b_y[20])
{
  real_T c3_dv[20];
  int32_T c3_i;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_dv, 1, 0, 0U, 1, 0U, 2, 20,
                1);
  for (c3_i = 0; c3_i < 20; c3_i++) {
    c3_b_y[c3_i] = c3_dv[c3_i];
  }

  sf_mex_destroy(&c3_b_u);
}

static real_T c3_g_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_call_count, const char_T *c3_identifier,
  boolean_T *c3_svPtr)
{
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_call_count),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_call_count);
  return c3_b_y;
}

static real_T c3_h_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr)
{
  real_T c3_b_y;
  real_T c3_d;
  (void)chartInstance;
  if (mxIsEmpty(c3_b_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_d, 1, 0, 0U, 0, 0U, 0);
    c3_b_y = c3_d;
  }

  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static uint32_T c3_i_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_c_method, const char_T *c3_identifier,
  boolean_T *c3_svPtr)
{
  emlrtMsgIdentifier c3_thisId;
  uint32_T c3_b_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_c_method),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_c_method);
  return c3_b_y;
}

static uint32_T c3_j_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr)
{
  uint32_T c3_b_y;
  uint32_T c3_c_u;
  (void)chartInstance;
  if (mxIsEmpty(c3_b_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_c_u, 1, 7, 0U, 0, 0U, 0);
    c3_b_y = c3_c_u;
  }

  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_k_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_e_state, const char_T *c3_identifier,
  boolean_T *c3_svPtr, uint32_T c3_b_y[625])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_e_state), &c3_thisId,
                        c3_svPtr, c3_b_y);
  sf_mex_destroy(&c3_e_state);
}

static void c3_l_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr, uint32_T c3_b_y[625])
{
  int32_T c3_i;
  uint32_T c3_uv[625];
  (void)chartInstance;
  if (mxIsEmpty(c3_b_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_uv, 1, 7, 0U, 1, 0U, 1,
                  625);
    for (c3_i = 0; c3_i < 625; c3_i++) {
      c3_b_y[c3_i] = c3_uv[c3_i];
    }
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_m_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_e_state, const char_T *c3_identifier,
  boolean_T *c3_svPtr, uint32_T c3_b_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_e_state), &c3_thisId,
                        c3_svPtr, c3_b_y);
  sf_mex_destroy(&c3_e_state);
}

static void c3_n_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr, uint32_T c3_b_y[2])
{
  int32_T c3_i;
  uint32_T c3_uv[2];
  (void)chartInstance;
  if (mxIsEmpty(c3_b_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_uv, 1, 7, 0U, 1, 0U, 1, 2);
    for (c3_i = 0; c3_i < 2; c3_i++) {
      c3_b_y[c3_i] = c3_uv[c3_i];
    }
  }

  sf_mex_destroy(&c3_b_u);
}

static uint8_T c3_o_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_flightControlSystem, const
  char_T *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_b_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_flightControlSystem), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_flightControlSystem);
  return c3_b_y;
}

static uint8_T c3_p_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_y;
  uint8_T c3_c_u;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_c_u, 1, 3, 0U, 0, 0U, 0);
  c3_b_y = c3_c_u;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_slStringInitializeDynamicBuffers
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_chart_data_browse_helper(SFc3_flightControlSystemInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig)
{
  real_T c3_d;
  real_T c3_d1;
  *c3_mxData = NULL;
  *c3_mxData = NULL;
  *c3_isValueTooBig = 0U;
  switch (c3_ssIdNumber) {
   case 4U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_u, 11,
      0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 5U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_b_outt,
      3, 0U, 1U, 0U, 3, 120, 160, 3), false);
    break;

   case 8U:
    c3_d = *chartInstance->c3_distX;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 9U:
    c3_d1 = *chartInstance->c3_distY;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 10U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_pointsx,
      0, 0U, 1U, 0U, 2, 20, 1), false);
    break;

   case 11U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_pointsy,
      0, 0U, 1U, 0U, 2, 20, 1), false);
    break;
  }
}

static const mxArray *c3_feval(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1, const mxArray *c3_input2, const mxArray *c3_input3)
{
  const mxArray *c3_m = NULL;
  (void)chartInstance;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "feval", 1U, 4U, 14, sf_mex_dup
    (c3_input0), 14, sf_mex_dup(c3_input1), 14, sf_mex_dup(c3_input2), 14,
    sf_mex_dup(c3_input3)), false);
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
  sf_mex_destroy(&c3_input2);
  sf_mex_destroy(&c3_input3);
  return c3_m;
}

static const mxArray *c3_b_feval(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1, const mxArray *c3_input2, const mxArray *c3_input3)
{
  const mxArray *c3_m = NULL;
  (void)chartInstance;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "feval", 1U, 4U, 14, sf_mex_dup
    (c3_input0), 14, sf_mex_dup(c3_input1), 14, sf_mex_dup(c3_input2), 14,
    sf_mex_dup(c3_input3)), false);
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
  sf_mex_destroy(&c3_input2);
  sf_mex_destroy(&c3_input3);
  return c3_m;
}

static void c3_b_sqrt(SFc3_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T
                      c3_x_size[1])
{
  static char_T c3_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c3_cv1[4] = { 's', 'q', 'r', 't' };

  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  real_T c3_b_k;
  real_T c3_b_x;
  real_T c3_d;
  real_T c3_x;
  int32_T c3_b_x_size[1];
  int32_T c3_b;
  int32_T c3_b_b;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_k;
  int32_T c3_loop_ub;
  int32_T c3_nx;
  boolean_T c3_b_p;
  boolean_T c3_overflow;
  boolean_T c3_p;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    chartInstance->c3_b_x_data[c3_i] = c3_c_x_data[c3_i];
  }

  c3_p = false;
  c3_d = (real_T)c3_b_x_size[0];
  c3_i1 = (int32_T)c3_d - 1;
  for (c3_k = 0; c3_k <= c3_i1; c3_k++) {
    c3_b_k = (real_T)c3_k + 1.0;
    if (c3_p || (chartInstance->c3_b_x_data[(int32_T)c3_b_k - 1] < 0.0)) {
      c3_b_p = true;
    } else {
      c3_b_p = false;
    }

    c3_p = c3_b_p;
  }

  if (c3_p) {
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c3_sp, &c3_c_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c3_sp, NULL, "message", 1U, 2U, 14, c3_c_y, 14, c3_d_y)));
  }

  c3_st.site = &c3_s_emlrtRSI;
  c3_nx = c3_x_size[0];
  c3_b_st.site = &c3_t_emlrtRSI;
  c3_b = c3_nx;
  c3_b_b = c3_b;
  if (c3_b_b < 1) {
    c3_overflow = false;
  } else {
    c3_overflow = (c3_b_b > 2147483646);
  }

  if (c3_overflow) {
    c3_c_st.site = &c3_u_emlrtRSI;
    c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
  }

  c3_i2 = (uint16_T)c3_nx - 1;
  for (c3_c_k = 0; c3_c_k <= c3_i2; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_x = c3_c_x_data[c3_d_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarSqrt(c3_b_x);
    c3_c_x_data[c3_d_k] = c3_b_x;
  }
}

static void c3_c_sort(SFc3_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T
                      c3_x_size[1], int32_T c3_idx_data[], int32_T c3_idx_size[1])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  real_T c3_dv[2];
  real_T c3_d;
  real_T c3_d1;
  int32_T c3_iv[2];
  int32_T c3_b_x_size[1];
  int32_T c3_iidx_size[1];
  int32_T c3_vwork_size[1];
  int32_T c3_b;
  int32_T c3_b_b;
  int32_T c3_b_dim;
  int32_T c3_b_i;
  int32_T c3_b_j;
  int32_T c3_b_k;
  int32_T c3_c_b;
  int32_T c3_c_k;
  int32_T c3_d_b;
  int32_T c3_d_k;
  int32_T c3_dim;
  int32_T c3_e_b;
  int32_T c3_f_b;
  int32_T c3_g_b;
  int32_T c3_h_b;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_j;
  int32_T c3_k;
  int32_T c3_upperDim;
  int32_T c3_vlen;
  int32_T c3_vstride;
  boolean_T c3_b_overflow;
  boolean_T c3_c_overflow;
  boolean_T c3_d_overflow;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_b_x_size[0] = c3_x_size[0];
  c3_dim = 2;
  if ((real_T)c3_b_x_size[0] != 1.0) {
    c3_dim = 1;
  }

  if (c3_dim <= 1) {
    c3_d = (real_T)c3_x_size[0];
  } else {
    c3_d = 1.0;
  }

  c3_vlen = (int32_T)c3_d;
  c3_iv[0] = c3_vlen;
  c3_vwork_size[0] = c3_iv[0];
  c3_dv[0] = (real_T)c3_x_size[0];
  c3_idx_size[0] = (int32_T)c3_dv[0];
  c3_st.site = &c3_y_emlrtRSI;
  c3_b_x_size[0] = c3_x_size[0];
  c3_b_dim = c3_dim - 1;
  c3_vstride = 1;
  c3_upperDim = c3_b_dim;
  c3_b_st.site = &c3_fb_emlrtRSI;
  c3_b = c3_upperDim;
  c3_b_b = c3_b;
  if (c3_b_b < 1) {
    c3_overflow = false;
  } else {
    c3_overflow = (c3_b_b > 2147483646);
  }

  if (c3_overflow) {
    c3_c_st.site = &c3_u_emlrtRSI;
    c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
  }

  c3_i = (uint8_T)c3_upperDim - 1;
  for (c3_k = 0; c3_k <= c3_i; c3_k++) {
    c3_d1 = (real_T)c3_b_x_size[0];
    c3_vstride *= (int32_T)c3_d1;
  }

  c3_st.site = &c3_ab_emlrtRSI;
  for (c3_b_i = 0; c3_b_i < 1; c3_b_i++) {
    c3_st.site = &c3_bb_emlrtRSI;
    c3_c_b = c3_vstride;
    c3_d_b = c3_c_b;
    if (c3_d_b < 1) {
      c3_b_overflow = false;
    } else {
      c3_b_overflow = (c3_d_b > 2147483646);
    }

    if (c3_b_overflow) {
      c3_b_st.site = &c3_u_emlrtRSI;
      c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
    }

    for (c3_j = 0; c3_j < c3_vstride; c3_j++) {
      c3_b_j = c3_j;
      c3_st.site = &c3_cb_emlrtRSI;
      c3_e_b = c3_vlen;
      c3_f_b = c3_e_b;
      if (c3_f_b < 1) {
        c3_c_overflow = false;
      } else {
        c3_c_overflow = (c3_f_b > 2147483646);
      }

      if (c3_c_overflow) {
        c3_b_st.site = &c3_u_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
      }

      c3_i1 = (uint16_T)c3_vlen - 1;
      for (c3_b_k = 0; c3_b_k <= c3_i1; c3_b_k++) {
        c3_c_k = c3_b_k;
        chartInstance->c3_vwork_data[c3_c_k] = c3_c_x_data[c3_b_j + c3_c_k *
          c3_vstride];
      }

      c3_st.site = &c3_db_emlrtRSI;
      c3_b_sortIdx(chartInstance, &c3_st, chartInstance->c3_vwork_data,
                   c3_vwork_size, chartInstance->c3_b_iidx_data, c3_iidx_size);
      c3_st.site = &c3_eb_emlrtRSI;
      c3_g_b = c3_vlen;
      c3_h_b = c3_g_b;
      if (c3_h_b < 1) {
        c3_d_overflow = false;
      } else {
        c3_d_overflow = (c3_h_b > 2147483646);
      }

      if (c3_d_overflow) {
        c3_b_st.site = &c3_u_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
      }

      c3_i2 = (uint16_T)c3_vlen - 1;
      for (c3_d_k = 0; c3_d_k <= c3_i2; c3_d_k++) {
        c3_c_k = c3_d_k;
        c3_c_x_data[c3_b_j + c3_c_k * c3_vstride] = chartInstance->
          c3_vwork_data[c3_c_k];
        c3_idx_data[c3_b_j + c3_c_k * c3_vstride] =
          chartInstance->c3_b_iidx_data[c3_c_k];
      }
    }
  }
}

static void c3_b_sortIdx(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T c3_x_size[1], int32_T
  c3_idx_data[], int32_T c3_idx_size[1])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_st;
  real_T c3_x4[4];
  real_T c3_dv[2];
  real_T c3_x;
  int32_T c3_idx4[4];
  int32_T c3_perm[4];
  int32_T c3_iv[1];
  int32_T c3_iwork[1];
  int32_T c3_iwork_size[1];
  int32_T c3_xwork[1];
  int32_T c3_xwork_size[1];
  int32_T c3_b;
  int32_T c3_b_b;
  int32_T c3_b_i1;
  int32_T c3_b_i2;
  int32_T c3_b_i3;
  int32_T c3_b_i4;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
  int32_T c3_b_n;
  int32_T c3_c_k;
  int32_T c3_c_loop_ub;
  int32_T c3_c_n;
  int32_T c3_d_b;
  int32_T c3_d_k;
  int32_T c3_e_b;
  int32_T c3_f_b;
  int32_T c3_g_b;
  int32_T c3_h_b;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i_b;
  int32_T c3_ib;
  int32_T c3_itmp;
  int32_T c3_j_b;
  int32_T c3_k;
  int32_T c3_k_b;
  int32_T c3_loop_ub;
  int32_T c3_m;
  int32_T c3_n;
  int32_T c3_nBlocks;
  int32_T c3_nLastBlock;
  int32_T c3_nNaNs;
  int32_T c3_nNonNaN;
  int32_T c3_preSortLevel;
  int32_T c3_quartetOffset;
  int32_T c3_tailOffset;
  int32_T c3_wOffset;
  boolean_T c3_b_overflow;
  boolean_T c3_c_b;
  boolean_T c3_c_overflow;
  boolean_T c3_d_overflow;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_dv[0] = (real_T)c3_x_size[0];
  c3_idx_size[0] = (int32_T)c3_dv[0];
  c3_loop_ub = (int32_T)c3_dv[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_idx_data[c3_i] = 0;
  }

  if (c3_x_size[0] != 0) {
    c3_st.site = &c3_gb_emlrtRSI;
    c3_n = c3_x_size[0];
    c3_b_st.site = &c3_hb_emlrtRSI;
    c3_b_n = c3_x_size[0];
    for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
      c3_x4[c3_i1] = 0.0;
    }

    for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
      c3_idx4[c3_i2] = 0;
    }

    c3_iwork_size[0] = c3_idx_size[0];
    c3_iv[0] = c3_iwork_size[0];
    c3_iwork_size[0] = c3_iv[0];
    c3_iwork[0] = c3_iwork_size[0];
    c3_b_loop_ub = c3_iwork[0] - 1;
    for (c3_i3 = 0; c3_i3 <= c3_b_loop_ub; c3_i3++) {
      chartInstance->c3_iwork_data[c3_i3] = 0;
    }

    c3_dv[0] = (real_T)c3_x_size[0];
    c3_xwork_size[0] = (int32_T)c3_dv[0];
    c3_iv[0] = c3_xwork_size[0];
    c3_xwork_size[0] = c3_iv[0];
    c3_xwork[0] = c3_xwork_size[0];
    c3_c_loop_ub = c3_xwork[0] - 1;
    for (c3_i4 = 0; c3_i4 <= c3_c_loop_ub; c3_i4++) {
      chartInstance->c3_xwork_data[c3_i4] = 0.0;
    }

    c3_nNaNs = 0;
    c3_ib = 0;
    c3_c_st.site = &c3_mb_emlrtRSI;
    c3_b = c3_b_n;
    c3_b_b = c3_b;
    if (c3_b_b < 1) {
      c3_overflow = false;
    } else {
      c3_overflow = (c3_b_b > 2147483646);
    }

    if (c3_overflow) {
      c3_d_st.site = &c3_u_emlrtRSI;
      c3_check_forloop_overflow_error(chartInstance, &c3_d_st);
    }

    c3_i5 = (uint16_T)c3_b_n - 1;
    for (c3_k = 0; c3_k <= c3_i5; c3_k++) {
      c3_b_k = c3_k;
      c3_x = c3_c_x_data[c3_b_k];
      c3_c_b = muDoubleScalarIsNaN(c3_x);
      if (c3_c_b) {
        c3_idx_data[(c3_b_n - c3_nNaNs) - 1] = c3_b_k + 1;
        chartInstance->c3_xwork_data[(c3_b_n - c3_nNaNs) - 1] =
          c3_c_x_data[c3_b_k];
        c3_nNaNs++;
      } else {
        c3_ib++;
        c3_idx4[c3_ib - 1] = c3_b_k + 1;
        c3_x4[c3_ib - 1] = c3_c_x_data[c3_b_k];
        if (c3_ib == 4) {
          c3_quartetOffset = c3_b_k - c3_nNaNs;
          if (c3_x4[0] <= c3_x4[1]) {
            c3_b_i1 = 1;
            c3_b_i2 = 2;
          } else {
            c3_b_i1 = 2;
            c3_b_i2 = 1;
          }

          if (c3_x4[2] <= c3_x4[3]) {
            c3_b_i3 = 3;
            c3_b_i4 = 4;
          } else {
            c3_b_i3 = 4;
            c3_b_i4 = 3;
          }

          if (c3_x4[c3_b_i1 - 1] <= c3_x4[c3_b_i3 - 1]) {
            if (c3_x4[c3_b_i2 - 1] <= c3_x4[c3_b_i3 - 1]) {
              c3_perm[0] = c3_b_i1;
              c3_perm[1] = c3_b_i2;
              c3_perm[2] = c3_b_i3;
              c3_perm[3] = c3_b_i4;
            } else if (c3_x4[c3_b_i2 - 1] <= c3_x4[c3_b_i4 - 1]) {
              c3_perm[0] = c3_b_i1;
              c3_perm[1] = c3_b_i3;
              c3_perm[2] = c3_b_i2;
              c3_perm[3] = c3_b_i4;
            } else {
              c3_perm[0] = c3_b_i1;
              c3_perm[1] = c3_b_i3;
              c3_perm[2] = c3_b_i4;
              c3_perm[3] = c3_b_i2;
            }
          } else if (c3_x4[c3_b_i1 - 1] <= c3_x4[c3_b_i4 - 1]) {
            if (c3_x4[c3_b_i2 - 1] <= c3_x4[c3_b_i4 - 1]) {
              c3_perm[0] = c3_b_i3;
              c3_perm[1] = c3_b_i1;
              c3_perm[2] = c3_b_i2;
              c3_perm[3] = c3_b_i4;
            } else {
              c3_perm[0] = c3_b_i3;
              c3_perm[1] = c3_b_i1;
              c3_perm[2] = c3_b_i4;
              c3_perm[3] = c3_b_i2;
            }
          } else {
            c3_perm[0] = c3_b_i3;
            c3_perm[1] = c3_b_i4;
            c3_perm[2] = c3_b_i1;
            c3_perm[3] = c3_b_i2;
          }

          c3_idx_data[c3_quartetOffset - 3] = c3_idx4[c3_perm[0] - 1];
          c3_idx_data[c3_quartetOffset - 2] = c3_idx4[c3_perm[1] - 1];
          c3_idx_data[c3_quartetOffset - 1] = c3_idx4[c3_perm[2] - 1];
          c3_idx_data[c3_quartetOffset] = c3_idx4[c3_perm[3] - 1];
          c3_c_x_data[c3_quartetOffset - 3] = c3_x4[c3_perm[0] - 1];
          c3_c_x_data[c3_quartetOffset - 2] = c3_x4[c3_perm[1] - 1];
          c3_c_x_data[c3_quartetOffset - 1] = c3_x4[c3_perm[2] - 1];
          c3_c_x_data[c3_quartetOffset] = c3_x4[c3_perm[3] - 1];
          c3_ib = 0;
        }
      }
    }

    c3_wOffset = (c3_b_n - c3_nNaNs) - 1;
    if (c3_ib > 0) {
      c3_c_n = c3_ib;
      for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
        c3_perm[c3_i6] = 0;
      }

      if (c3_c_n == 1) {
        c3_perm[0] = 1;
      } else if (c3_c_n == 2) {
        if (c3_x4[0] <= c3_x4[1]) {
          c3_perm[0] = 1;
          c3_perm[1] = 2;
        } else {
          c3_perm[0] = 2;
          c3_perm[1] = 1;
        }
      } else if (c3_x4[0] <= c3_x4[1]) {
        if (c3_x4[1] <= c3_x4[2]) {
          c3_perm[0] = 1;
          c3_perm[1] = 2;
          c3_perm[2] = 3;
        } else if (c3_x4[0] <= c3_x4[2]) {
          c3_perm[0] = 1;
          c3_perm[1] = 3;
          c3_perm[2] = 2;
        } else {
          c3_perm[0] = 3;
          c3_perm[1] = 1;
          c3_perm[2] = 2;
        }
      } else if (c3_x4[0] <= c3_x4[2]) {
        c3_perm[0] = 2;
        c3_perm[1] = 1;
        c3_perm[2] = 3;
      } else if (c3_x4[1] <= c3_x4[2]) {
        c3_perm[0] = 2;
        c3_perm[1] = 3;
        c3_perm[2] = 1;
      } else {
        c3_perm[0] = 3;
        c3_perm[1] = 2;
        c3_perm[2] = 1;
      }

      c3_c_st.site = &c3_nb_emlrtRSI;
      c3_f_b = c3_ib;
      c3_g_b = c3_f_b;
      if (c3_g_b < 1) {
        c3_c_overflow = false;
      } else {
        c3_c_overflow = (c3_g_b > 2147483646);
      }

      if (c3_c_overflow) {
        c3_d_st.site = &c3_u_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_d_st);
      }

      c3_i7 = (uint8_T)c3_ib - 1;
      for (c3_d_k = 0; c3_d_k <= c3_i7; c3_d_k++) {
        c3_b_k = c3_d_k;
        c3_idx_data[((c3_wOffset - c3_ib) + c3_b_k) + 1] =
          c3_idx4[c3_perm[c3_b_k] - 1];
        c3_c_x_data[((c3_wOffset - c3_ib) + c3_b_k) + 1] = c3_x4[c3_perm[c3_b_k]
          - 1];
      }
    }

    c3_m = c3_nNaNs >> 1;
    c3_c_st.site = &c3_ob_emlrtRSI;
    c3_d_b = c3_m;
    c3_e_b = c3_d_b;
    if (c3_e_b < 1) {
      c3_b_overflow = false;
    } else {
      c3_b_overflow = (c3_e_b > 2147483646);
    }

    if (c3_b_overflow) {
      c3_d_st.site = &c3_u_emlrtRSI;
      c3_check_forloop_overflow_error(chartInstance, &c3_d_st);
    }

    for (c3_c_k = 0; c3_c_k < c3_m; c3_c_k++) {
      c3_b_k = c3_c_k + 1;
      c3_itmp = c3_idx_data[c3_wOffset + c3_b_k];
      c3_idx_data[c3_wOffset + c3_b_k] = c3_idx_data[c3_b_n - c3_b_k];
      c3_idx_data[c3_b_n - c3_b_k] = c3_itmp;
      c3_c_x_data[c3_wOffset + c3_b_k] = chartInstance->c3_xwork_data[c3_b_n -
        c3_b_k];
      c3_c_x_data[c3_b_n - c3_b_k] = chartInstance->c3_xwork_data[c3_wOffset +
        c3_b_k];
    }

    if ((c3_nNaNs & 1) != 0) {
      c3_c_x_data[(c3_wOffset + c3_m) + 1] = chartInstance->c3_xwork_data
        [(c3_wOffset + c3_m) + 1];
    }

    c3_nNonNaN = c3_n - c3_nNaNs;
    c3_preSortLevel = 2;
    if (c3_nNonNaN > 1) {
      if (c3_n >= 256) {
        c3_nBlocks = c3_nNonNaN >> 8;
        if (c3_nBlocks > 0) {
          c3_b_st.site = &c3_ib_emlrtRSI;
          c3_h_b = c3_nBlocks;
          c3_i_b = c3_h_b;
          if (c3_i_b < 1) {
            c3_d_overflow = false;
          } else {
            c3_d_overflow = (c3_i_b > 2147483646);
          }

          if (c3_d_overflow) {
            c3_c_st.site = &c3_u_emlrtRSI;
            c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
          }

          for (c3_j_b = 0; c3_j_b < c3_nBlocks; c3_j_b++) {
            c3_k_b = c3_j_b;
            c3_b_st.site = &c3_jb_emlrtRSI;
            c3_b_merge_pow2_block(chartInstance, &c3_b_st, c3_idx_data,
                                  c3_c_x_data, c3_k_b << 8);
          }

          c3_tailOffset = c3_nBlocks << 8;
          c3_nLastBlock = c3_nNonNaN - c3_tailOffset;
          if (c3_nLastBlock > 0) {
            c3_b_st.site = &c3_kb_emlrtRSI;
            c3_b_merge_block(chartInstance, &c3_b_st, c3_idx_data, c3_c_x_data,
                             c3_tailOffset, c3_nLastBlock, 2,
                             chartInstance->c3_iwork_data,
                             chartInstance->c3_xwork_data);
          }

          c3_preSortLevel = 8;
        }
      }

      c3_b_st.site = &c3_lb_emlrtRSI;
      c3_b_merge_block(chartInstance, &c3_b_st, c3_idx_data, c3_c_x_data, 0,
                       c3_nNonNaN, c3_preSortLevel, chartInstance->c3_iwork_data,
                       chartInstance->c3_xwork_data);
    }
  }
}

static void c3_b_merge_pow2_block(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_idx_data[], real_T
  c3_c_x_data[], int32_T c3_offset)
{
  emlrtStack c3_b_st;
  emlrtStack c3_st;
  real_T c3_xwork[256];
  int32_T c3_iwork[256];
  int32_T c3_b;
  int32_T c3_bLen;
  int32_T c3_bLen2;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_b_j;
  int32_T c3_b_k;
  int32_T c3_blockOffset;
  int32_T c3_c_a;
  int32_T c3_c_b;
  int32_T c3_c_j;
  int32_T c3_d_b;
  int32_T c3_e_b;
  int32_T c3_exitg1;
  int32_T c3_f_b;
  int32_T c3_g_b;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_iout;
  int32_T c3_j;
  int32_T c3_k;
  int32_T c3_nPairs;
  int32_T c3_offset1;
  int32_T c3_p;
  int32_T c3_q;
  boolean_T c3_b_overflow;
  boolean_T c3_c_overflow;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  for (c3_b = 0; c3_b < 6; c3_b++) {
    c3_bLen = 1 << (c3_b + 2);
    c3_bLen2 = c3_bLen << 1;
    c3_nPairs = 256 >> (c3_b + 3);
    c3_st.site = &c3_pb_emlrtRSI;
    c3_b_b = c3_nPairs;
    c3_c_b = c3_b_b;
    if (c3_c_b < 1) {
      c3_overflow = false;
    } else {
      c3_overflow = (c3_c_b > 2147483646);
    }

    if (c3_overflow) {
      c3_b_st.site = &c3_u_emlrtRSI;
      c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
    }

    c3_i = (uint8_T)c3_nPairs - 1;
    for (c3_k = 0; c3_k <= c3_i; c3_k++) {
      c3_b_k = c3_k;
      c3_blockOffset = (c3_offset + c3_b_k * c3_bLen2) - 1;
      c3_st.site = &c3_qb_emlrtRSI;
      c3_d_b = c3_bLen2;
      c3_e_b = c3_d_b;
      if (c3_e_b < 1) {
        c3_b_overflow = false;
      } else {
        c3_b_overflow = (c3_e_b > 2147483646);
      }

      if (c3_b_overflow) {
        c3_b_st.site = &c3_u_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
      }

      c3_i1 = (uint16_T)c3_bLen2 - 1;
      for (c3_j = 0; c3_j <= c3_i1; c3_j++) {
        c3_b_j = c3_j;
        c3_iwork[c3_b_j] = c3_idx_data[(c3_blockOffset + c3_b_j) + 1];
        c3_xwork[c3_b_j] = c3_c_x_data[(c3_blockOffset + c3_b_j) + 1];
      }

      c3_p = 0;
      c3_q = c3_bLen;
      c3_iout = c3_blockOffset;
      do {
        c3_exitg1 = 0;
        c3_iout++;
        if (c3_xwork[c3_p] <= c3_xwork[c3_q]) {
          c3_idx_data[c3_iout] = c3_iwork[c3_p];
          c3_c_x_data[c3_iout] = c3_xwork[c3_p];
          if (c3_p + 1 < c3_bLen) {
            c3_p++;
          } else {
            c3_exitg1 = 1;
          }
        } else {
          c3_idx_data[c3_iout] = c3_iwork[c3_q];
          c3_c_x_data[c3_iout] = c3_xwork[c3_q];
          if (c3_q + 1 < c3_bLen2) {
            c3_q++;
          } else {
            c3_offset1 = c3_iout - c3_p;
            c3_st.site = &c3_rb_emlrtRSI;
            c3_b_a = c3_p + 1;
            c3_f_b = c3_bLen;
            c3_c_a = c3_b_a;
            c3_g_b = c3_f_b;
            if (c3_c_a > c3_g_b) {
              c3_c_overflow = false;
            } else {
              c3_c_overflow = (c3_g_b > 2147483646);
            }

            if (c3_c_overflow) {
              c3_b_st.site = &c3_u_emlrtRSI;
              c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
            }

            for (c3_c_j = c3_p + 1; c3_c_j <= c3_bLen; c3_c_j++) {
              c3_idx_data[c3_offset1 + c3_c_j] = c3_iwork[c3_c_j - 1];
              c3_c_x_data[c3_offset1 + c3_c_j] = c3_xwork[c3_c_j - 1];
            }

            c3_exitg1 = 1;
          }
        }
      } while (c3_exitg1 == 0);
    }
  }
}

static void c3_b_merge_block(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, int32_T c3_idx_data[], real_T
  c3_c_x_data[], int32_T c3_offset, int32_T c3_n, int32_T c3_preSortLevel,
  int32_T c3_b_iwork_data[], real_T c3_b_xwork_data[])
{
  emlrtStack c3_b_st;
  emlrtStack c3_st;
  int32_T c3_b;
  int32_T c3_bLen;
  int32_T c3_bLen2;
  int32_T c3_b_b;
  int32_T c3_b_k;
  int32_T c3_k;
  int32_T c3_nBlocks;
  int32_T c3_nPairs;
  int32_T c3_nTail;
  int32_T c3_tailOffset;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_nBlocks = c3_n >> c3_preSortLevel;
  c3_bLen = 1 << c3_preSortLevel;
  while (c3_nBlocks > 1) {
    if ((c3_nBlocks & 1) != 0) {
      c3_nBlocks--;
      c3_tailOffset = c3_bLen * c3_nBlocks;
      c3_nTail = c3_n - c3_tailOffset;
      if (c3_nTail > c3_bLen) {
        c3_st.site = &c3_sb_emlrtRSI;
        c3_b_merge(chartInstance, &c3_st, c3_idx_data, c3_c_x_data, c3_offset +
                   c3_tailOffset, c3_bLen, c3_nTail - c3_bLen, c3_b_iwork_data,
                   c3_b_xwork_data);
      }
    }

    c3_bLen2 = c3_bLen << 1;
    c3_nPairs = c3_nBlocks >> 1;
    c3_st.site = &c3_tb_emlrtRSI;
    c3_b = c3_nPairs;
    c3_b_b = c3_b;
    if (c3_b_b < 1) {
      c3_overflow = false;
    } else {
      c3_overflow = (c3_b_b > 2147483646);
    }

    if (c3_overflow) {
      c3_b_st.site = &c3_u_emlrtRSI;
      c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
    }

    for (c3_k = 0; c3_k < c3_nPairs; c3_k++) {
      c3_b_k = c3_k;
      c3_st.site = &c3_ub_emlrtRSI;
      c3_b_merge(chartInstance, &c3_st, c3_idx_data, c3_c_x_data, c3_offset +
                 c3_b_k * c3_bLen2, c3_bLen, c3_bLen, c3_b_iwork_data,
                 c3_b_xwork_data);
    }

    c3_bLen = c3_bLen2;
    c3_nBlocks = c3_nPairs;
  }

  if (c3_n > c3_bLen) {
    c3_st.site = &c3_vb_emlrtRSI;
    c3_b_merge(chartInstance, &c3_st, c3_idx_data, c3_c_x_data, c3_offset,
               c3_bLen, c3_n - c3_bLen, c3_b_iwork_data, c3_b_xwork_data);
  }
}

static void c3_b_merge(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, int32_T c3_idx_data[], real_T c3_c_x_data[], int32_T
  c3_offset, int32_T c3_np, int32_T c3_nq, int32_T c3_b_iwork_data[], real_T
  c3_b_xwork_data[])
{
  emlrtStack c3_b_st;
  emlrtStack c3_st;
  int32_T c3_b;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_b_j;
  int32_T c3_c_a;
  int32_T c3_c_b;
  int32_T c3_c_j;
  int32_T c3_d_b;
  int32_T c3_exitg1;
  int32_T c3_iout;
  int32_T c3_j;
  int32_T c3_n;
  int32_T c3_offset1;
  int32_T c3_p;
  int32_T c3_q;
  int32_T c3_qend;
  boolean_T c3_b_overflow;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  if (c3_nq != 0) {
    c3_n = c3_np + c3_nq;
    c3_st.site = &c3_xb_emlrtRSI;
    c3_b = c3_n;
    c3_b_b = c3_b;
    if (c3_b_b < 1) {
      c3_overflow = false;
    } else {
      c3_overflow = (c3_b_b > 2147483646);
    }

    if (c3_overflow) {
      c3_b_st.site = &c3_u_emlrtRSI;
      c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
    }

    for (c3_j = 0; c3_j < c3_n; c3_j++) {
      c3_b_j = c3_j;
      c3_b_iwork_data[c3_b_j] = c3_idx_data[c3_offset + c3_b_j];
      c3_b_xwork_data[c3_b_j] = c3_c_x_data[c3_offset + c3_b_j];
    }

    c3_p = 0;
    c3_q = c3_np;
    c3_qend = c3_np + c3_nq;
    c3_iout = c3_offset - 1;
    do {
      c3_exitg1 = 0;
      c3_iout++;
      if (c3_b_xwork_data[c3_p] <= c3_b_xwork_data[c3_q]) {
        c3_idx_data[c3_iout] = c3_b_iwork_data[c3_p];
        c3_c_x_data[c3_iout] = c3_b_xwork_data[c3_p];
        if (c3_p + 1 < c3_np) {
          c3_p++;
        } else {
          c3_exitg1 = 1;
        }
      } else {
        c3_idx_data[c3_iout] = c3_b_iwork_data[c3_q];
        c3_c_x_data[c3_iout] = c3_b_xwork_data[c3_q];
        if (c3_q + 1 < c3_qend) {
          c3_q++;
        } else {
          c3_offset1 = c3_iout - c3_p;
          c3_st.site = &c3_wb_emlrtRSI;
          c3_b_a = c3_p + 1;
          c3_c_b = c3_np;
          c3_c_a = c3_b_a;
          c3_d_b = c3_c_b;
          if (c3_c_a > c3_d_b) {
            c3_b_overflow = false;
          } else {
            c3_b_overflow = (c3_d_b > 2147483646);
          }

          if (c3_b_overflow) {
            c3_b_st.site = &c3_u_emlrtRSI;
            c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
          }

          for (c3_c_j = c3_p + 1; c3_c_j <= c3_np; c3_c_j++) {
            c3_idx_data[c3_offset1 + c3_c_j] = c3_b_iwork_data[c3_c_j - 1];
            c3_c_x_data[c3_offset1 + c3_c_j] = c3_b_xwork_data[c3_c_j - 1];
          }

          c3_exitg1 = 1;
        }
      }
    } while (c3_exitg1 == 0);
  }
}

static void c3_d_sort(SFc3_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T
                      c3_x_size[1], int32_T c3_idx_data[], int32_T c3_idx_size[1])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  real_T c3_b_vwork_data[20];
  real_T c3_dv[2];
  real_T c3_d;
  real_T c3_d1;
  int32_T c3_c_iidx_data[20];
  int32_T c3_iv[2];
  int32_T c3_b_x_size[1];
  int32_T c3_iidx_size[1];
  int32_T c3_vwork_size[1];
  int32_T c3_b;
  int32_T c3_b_b;
  int32_T c3_b_dim;
  int32_T c3_b_i;
  int32_T c3_b_j;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
  int32_T c3_c_b;
  int32_T c3_c_k;
  int32_T c3_c_loop_ub;
  int32_T c3_d_b;
  int32_T c3_d_k;
  int32_T c3_dim;
  int32_T c3_e_b;
  int32_T c3_f_b;
  int32_T c3_g_b;
  int32_T c3_h_b;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_j;
  int32_T c3_k;
  int32_T c3_loop_ub;
  int32_T c3_upperDim;
  int32_T c3_vlen;
  int32_T c3_vstride;
  boolean_T c3_b_overflow;
  boolean_T c3_c_overflow;
  boolean_T c3_d_overflow;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_b_x_size[0] = c3_x_size[0];
  c3_dim = 2;
  if ((real_T)c3_b_x_size[0] != 1.0) {
    c3_dim = 1;
  }

  if (c3_dim <= 1) {
    c3_d = (real_T)c3_x_size[0];
  } else {
    c3_d = 1.0;
  }

  c3_vlen = (int32_T)c3_d;
  c3_iv[0] = c3_vlen;
  c3_vwork_size[0] = c3_iv[0];
  c3_dv[0] = (real_T)c3_x_size[0];
  c3_idx_size[0] = (int32_T)c3_dv[0];
  c3_st.site = &c3_y_emlrtRSI;
  c3_b_x_size[0] = c3_x_size[0];
  c3_b_dim = c3_dim - 1;
  c3_vstride = 1;
  c3_upperDim = c3_b_dim;
  c3_b_st.site = &c3_fb_emlrtRSI;
  c3_b = c3_upperDim;
  c3_b_b = c3_b;
  if (c3_b_b < 1) {
    c3_overflow = false;
  } else {
    c3_overflow = (c3_b_b > 2147483646);
  }

  if (c3_overflow) {
    c3_c_st.site = &c3_u_emlrtRSI;
    c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
  }

  c3_i = (uint8_T)c3_upperDim - 1;
  for (c3_k = 0; c3_k <= c3_i; c3_k++) {
    c3_d1 = (real_T)c3_b_x_size[0];
    c3_vstride *= (int32_T)c3_d1;
  }

  c3_st.site = &c3_ab_emlrtRSI;
  for (c3_b_i = 0; c3_b_i < 1; c3_b_i++) {
    c3_st.site = &c3_bb_emlrtRSI;
    c3_c_b = c3_vstride;
    c3_d_b = c3_c_b;
    if (c3_d_b < 1) {
      c3_b_overflow = false;
    } else {
      c3_b_overflow = (c3_d_b > 2147483646);
    }

    if (c3_b_overflow) {
      c3_b_st.site = &c3_u_emlrtRSI;
      c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
    }

    for (c3_j = 0; c3_j < c3_vstride; c3_j++) {
      c3_b_j = c3_j;
      c3_st.site = &c3_cb_emlrtRSI;
      c3_e_b = c3_vlen;
      c3_f_b = c3_e_b;
      if (c3_f_b < 1) {
        c3_c_overflow = false;
      } else {
        c3_c_overflow = (c3_f_b > 2147483646);
      }

      if (c3_c_overflow) {
        c3_b_st.site = &c3_u_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
      }

      c3_i1 = (uint8_T)c3_vlen - 1;
      for (c3_b_k = 0; c3_b_k <= c3_i1; c3_b_k++) {
        c3_c_k = c3_b_k;
        c3_b_vwork_data[c3_c_k] = c3_c_x_data[c3_b_j + c3_c_k * c3_vstride];
      }

      c3_b_x_size[0] = c3_vwork_size[0];
      c3_loop_ub = c3_vwork_size[0] - 1;
      for (c3_i2 = 0; c3_i2 <= c3_loop_ub; c3_i2++) {
        chartInstance->c3_x_data[c3_i2] = c3_b_vwork_data[c3_i2];
      }

      c3_st.site = &c3_db_emlrtRSI;
      c3_b_sortIdx(chartInstance, &c3_st, chartInstance->c3_x_data, c3_b_x_size,
                   chartInstance->c3_iidx_data, c3_iidx_size);
      c3_b_loop_ub = c3_iidx_size[0] - 1;
      for (c3_i3 = 0; c3_i3 <= c3_b_loop_ub; c3_i3++) {
        c3_c_iidx_data[c3_i3] = chartInstance->c3_iidx_data[c3_i3];
      }

      c3_vwork_size[0] = c3_b_x_size[0];
      c3_c_loop_ub = c3_b_x_size[0] - 1;
      for (c3_i4 = 0; c3_i4 <= c3_c_loop_ub; c3_i4++) {
        c3_b_vwork_data[c3_i4] = chartInstance->c3_x_data[c3_i4];
      }

      c3_st.site = &c3_eb_emlrtRSI;
      c3_g_b = c3_vlen;
      c3_h_b = c3_g_b;
      if (c3_h_b < 1) {
        c3_d_overflow = false;
      } else {
        c3_d_overflow = (c3_h_b > 2147483646);
      }

      if (c3_d_overflow) {
        c3_b_st.site = &c3_u_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
      }

      c3_i5 = (uint8_T)c3_vlen - 1;
      for (c3_d_k = 0; c3_d_k <= c3_i5; c3_d_k++) {
        c3_c_k = c3_d_k;
        c3_c_x_data[c3_b_j + c3_c_k * c3_vstride] = c3_b_vwork_data[c3_c_k];
        c3_idx_data[c3_b_j + c3_c_k * c3_vstride] = c3_c_iidx_data[c3_c_k];
      }
    }
  }
}

static void c3_b_genrand_uint32_vector(SFc3_flightControlSystemInstanceStruct
  *chartInstance, uint32_T c3_mt[625], uint32_T c3_b_u[2])
{
  real_T c3_b_j;
  real_T c3_c_kk;
  int32_T c3_b_kk;
  int32_T c3_j;
  int32_T c3_kk;
  uint32_T c3_b_y;
  uint32_T c3_c_y;
  uint32_T c3_d_y;
  uint32_T c3_e_y;
  uint32_T c3_f_y;
  uint32_T c3_g_y;
  uint32_T c3_h_y;
  uint32_T c3_mti;
  (void)chartInstance;
  for (c3_j = 0; c3_j < 2; c3_j++) {
    c3_b_j = (real_T)c3_j + 1.0;
    c3_mti = c3_mt[624] + 1U;
    if ((real_T)c3_mti >= 625.0) {
      for (c3_kk = 0; c3_kk < 227; c3_kk++) {
        c3_c_kk = (real_T)c3_kk + 1.0;
        c3_b_y = (c3_mt[(int32_T)c3_c_kk - 1] & 2147483648U) | (c3_mt[(int32_T)
          (c3_c_kk + 1.0) - 1] & 2147483647U);
        c3_c_y = c3_b_y;
        c3_e_y = c3_c_y;
        if ((c3_e_y & 1U) == 0U) {
          c3_e_y >>= 1U;
        } else {
          c3_e_y = c3_e_y >> 1U ^ 2567483615U;
        }

        c3_mt[(int32_T)c3_c_kk - 1] = c3_mt[(int32_T)(c3_c_kk + 397.0) - 1] ^
          c3_e_y;
      }

      for (c3_b_kk = 0; c3_b_kk < 396; c3_b_kk++) {
        c3_c_kk = (real_T)c3_b_kk + 228.0;
        c3_b_y = (c3_mt[(int32_T)c3_c_kk - 1] & 2147483648U) | (c3_mt[(int32_T)
          (c3_c_kk + 1.0) - 1] & 2147483647U);
        c3_g_y = c3_b_y;
        c3_h_y = c3_g_y;
        if ((c3_h_y & 1U) == 0U) {
          c3_h_y >>= 1U;
        } else {
          c3_h_y = c3_h_y >> 1U ^ 2567483615U;
        }

        c3_mt[(int32_T)c3_c_kk - 1] = c3_mt[(int32_T)((c3_c_kk + 1.0) - 228.0) -
          1] ^ c3_h_y;
      }

      c3_b_y = (c3_mt[623] & 2147483648U) | (c3_mt[0] & 2147483647U);
      c3_d_y = c3_b_y;
      c3_f_y = c3_d_y;
      if ((c3_f_y & 1U) == 0U) {
        c3_f_y >>= 1U;
      } else {
        c3_f_y = c3_f_y >> 1U ^ 2567483615U;
      }

      c3_mt[623] = c3_mt[396] ^ c3_f_y;
      c3_mti = 1U;
    }

    c3_b_y = c3_mt[(int32_T)c3_mti - 1];
    c3_mt[624] = c3_mti;
    c3_b_y ^= c3_b_y >> 11U;
    c3_b_y ^= c3_b_y << 7U & 2636928640U;
    c3_b_y ^= c3_b_y << 15U & 4022730752U;
    c3_b_y ^= c3_b_y >> 18U;
    c3_b_u[(int32_T)c3_b_j - 1] = c3_b_y;
  }
}

static real_T c3_b_genrandu(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, uint32_T c3_mt[625])
{
  static char_T c3_cv[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  real_T c3_r;
  int32_T c3_b_a;
  int32_T c3_exitg1;
  int32_T c3_i;
  int32_T c3_k;
  uint32_T c3_b_mt[625];
  uint32_T c3_b_u[2];
  boolean_T c3_b_isvalid;
  boolean_T c3_exitg2;
  boolean_T c3_isvalid;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    c3_exitg1 = 0;
    c3_b_genrand_uint32_vector(chartInstance, c3_mt, c3_b_u);
    c3_b_u[0] >>= 5U;
    c3_b_u[1] >>= 6U;
    c3_r = 1.1102230246251565E-16 * ((real_T)c3_b_u[0] * 6.7108864E+7 + (real_T)
      c3_b_u[1]);
    if (c3_r == 0.0) {
      for (c3_i = 0; c3_i < 625; c3_i++) {
        c3_b_mt[c3_i] = c3_mt[c3_i];
      }

      if (((real_T)c3_b_mt[624] >= 1.0) && ((real_T)c3_b_mt[624] < 625.0)) {
        c3_isvalid = true;
      } else {
        c3_isvalid = false;
      }

      c3_b_isvalid = c3_isvalid;
      if (c3_isvalid) {
        c3_b_isvalid = false;
        c3_k = 0;
        c3_exitg2 = false;
        while ((!c3_exitg2) && (c3_k + 1 < 625)) {
          if ((real_T)c3_b_mt[c3_k] == 0.0) {
            c3_b_a = c3_k + 1;
            c3_k = c3_b_a;
          } else {
            c3_b_isvalid = true;
            c3_exitg2 = true;
          }
        }
      }

      if (!c3_b_isvalid) {
        c3_b_y = NULL;
        sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1,
          37), false);
        c3_c_y = NULL;
        sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1,
          37), false);
        sf_mex_call(c3_sp, &c3_f_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                    sf_mex_call(c3_sp, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(c3_sp, NULL, "message", 1U, 1U, 14, c3_c_y)));
      }
    } else {
      c3_exitg1 = 1;
    }
  } while (c3_exitg1 == 0);

  return c3_r;
}

static void c3_plus(SFc3_flightControlSystemInstanceStruct *chartInstance,
                    real_T c3_b_in1_data[], int32_T c3_in1_size[1], real_T
                    c3_in2_data[], int32_T c3_in2_size[1])
{
  int32_T c3_b_in1_size[1];
  int32_T c3_aux_0_0;
  int32_T c3_aux_1_0;
  int32_T c3_b_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_stride_0_0;
  int32_T c3_stride_1_0;
  if (c3_in2_size[0] == 1) {
    c3_b_in1_size[0] = c3_in1_size[0];
  } else {
    c3_b_in1_size[0] = c3_in2_size[0];
  }

  c3_stride_0_0 = (c3_in1_size[0] != 1);
  c3_stride_1_0 = (c3_in2_size[0] != 1);
  c3_aux_0_0 = 0;
  c3_aux_1_0 = 0;
  if (c3_in2_size[0] == 1) {
    c3_i = c3_in1_size[0];
  } else {
    c3_i = c3_in2_size[0];
  }

  c3_loop_ub = c3_i - 1;
  for (c3_i1 = 0; c3_i1 <= c3_loop_ub; c3_i1++) {
    chartInstance->c3_in1_data[c3_i1] = c3_b_in1_data[c3_aux_0_0] +
      c3_in2_data[c3_aux_1_0];
    c3_aux_1_0 += c3_stride_1_0;
    c3_aux_0_0 += c3_stride_0_0;
  }

  c3_in1_size[0] = c3_b_in1_size[0];
  c3_b_loop_ub = c3_b_in1_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_b_loop_ub; c3_i2++) {
    c3_b_in1_data[c3_i2] = chartInstance->c3_in1_data[c3_i2];
  }
}

static int32_T c3__s32_d_(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_b, int32_T c3_EMLOvCount_src_loc, uint32_T c3_ssid_src_loc, int32_T
  c3_offset_src_loc, int32_T c3_length_src_loc)
{
  real_T c3_d;
  int32_T c3_b_a;
  (void)c3_EMLOvCount_src_loc;
  c3_b_a = (int32_T)c3_b;
  if (c3_b < 0.0) {
    c3_d = muDoubleScalarCeil(c3_b);
  } else {
    c3_d = muDoubleScalarFloor(c3_b);
  }

  if ((real_T)c3_b_a != c3_d) {
    sf_data_overflow_error(chartInstance->S, c3_ssid_src_loc, c3_offset_src_loc,
      c3_length_src_loc);
  }

  return c3_b_a;
}

static void init_dsm_address_info(SFc3_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c3_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_u = (boolean_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_b_outt = (uint8_T (*)[57600])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_distX = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_distY = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_pointsx = (real_T (*)[20])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_pointsy = (real_T (*)[20])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c3_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(799066861U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2984585618U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(977238898U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(372599011U);
}

mxArray *sf_c3_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Bwlookup_tbb_Buildable"));
  return(mxcell3p);
}

mxArray *sf_c3_flightControlSystem_jit_fallback_info(void)
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

mxArray *sf_c3_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNrtmM9P2zAUx52qdD8kpkrsD6gmtCMpVBpwIoVTpSFB2aE7Za6TtpYcO0peUHvrBYkjxx133J/"
    "AcX/C/hT+hMWJC8yKlokaWlAtWdZ71XPz/b5PLafI6hyjdLxL588NhGrp+jqdFZSPNRVb6VxXa5"
    "6v3uYb6YRJ6Mt8HJGOl64cB1mMk3GHD0S2/x66279WsL91b/83Kp+Pm4P56huOXl8tqF+7V19Xs"
    "Udj6Cl/Zj4tTseHuXR8XRod7zMdzRId1b90VJFIAJbj+Tf/qw+vtD7IOBSUQzxekj58nFPHxJCO"
    "ujNfff79TomOt5oOGRPMmEtEwuFun9/o3+egpZ2DFRXLGoYoCguep0hPRdNTv1Vz6mTL9MyIL8v"
    "SnzLOalp/ZBz4MBJeXt+zFtyX3jTvy+XUMfG7vSzx41TzQ8Z2OwwZJRio4LF93P7yuX3odneaOy"
    "28hcPQBiFYX4xtP2A2o307wMBw344w9wYJt8OInmPw5ceuzG0FKz4M8nGh+Lh4Ej66mh9d83zwG"
    "SDPgY+ie08MqRxVP1o0H1Mv56PhG+Hje4kfRPODmOfDDchw+9Nec9fNjB4kTAGz4sUAL78UL9+e"
    "hhdP88N7DF5ge3+/tYsjDZgVLwZ4+aF4cV7O+RKPohYRfPgSz5eF31eu1H3lenVfKfu/6CF8nJT"
    "40dD8kDGNXUyAnvsuabkDRocjOBIcIsHOJjH4wex97g+xY0x5"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sSFfOtAjS0okH9jZnnbtDoG";
}

static void sf_opaque_initialize_c3_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c3_flightControlSystem
    ((SFc3_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c3_flightControlSystem((SFc3_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_flightControlSystem(void *chartInstanceVar)
{
  enable_c3_flightControlSystem((SFc3_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_flightControlSystem(void *chartInstanceVar)
{
  disable_c3_flightControlSystem((SFc3_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c3_flightControlSystem((SFc3_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c3_flightControlSystem
    ((SFc3_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c3_flightControlSystem((SFc3_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c3_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c3_flightControlSystem
      ((SFc3_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c3_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c3_flightControlSystem((SFc3_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc3_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c3_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c3_flightControlSystem((SFc3_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_flightControlSystem
      ((SFc3_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc3_flightControlSystem
      ((SFc3_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c3_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [33] = {
    "eNrtWs1v3EQU90ZJIIWUSlT0ABIRKhUSJZs0gjYSKkn2o1lpt0njTUiL0HbWnl1PM55xZ8abXcQ",
    "hl6JyokcuSD3yJ3DsFU4c+Q+4cuSCxIzt3RhnG9u722RpY2nXHttv3tfvvXkzHi1TqmjyOC9/F5",
    "Y0bVqeX5e/Cc0/poJ2JvTz709qnwftb9/QNIOasAmJ7jYaqK2lO4hrbwIGbK6lPwiw4RbkFLsCU",
    "VIiDZqcFpEGZJAYsgOHMpGKL0e2ixHZK7rEUJz5lxYyLN2iLjbXZIfA3CC48zy+jis2Jcc8YtAQ",
    "RQhNYTHqNq0iBs3jrcDEfs6Cxh537dS24lDorqNU5RUXC+RgWGhDo0S4ANIKPEZfXQABc6Kdzsh",
    "KX653qantYARIcltbgOvQkegQcNsx5f+GK6T1EtEaFmBiDVqgBXkZ7XncKYGJuCMu364jAgRlCO",
    "CCjXOqt4T6bmKpY0WGBE7rI6nvGoNgz6GIiJQBoRelnQsE1DHMw7rbTMlXhw9dFQ07CO5Dls6/j",
    "RxtQQaacIOkk9nzUaHtgbIXSwlpBbLhDmCrhsQuh2a6vCGDjutAwhFWZTepaKFn4hKvMtSS2Eib",
    "60oq/AfKda7to58PROvxLbRgalz1+BYNkgMY83S0VeqUYQtij38eCDAArc8/BTHnyKxSiQ6VbVJ",
    "mLJcgGQkBbY4SEyVHZStC5Q1st+UglYAc2SoMoCnN3BO911FcHLlcUDsnU06+XE7I7yhtiQjIGs",
    "CAiccYBhCHUmAPVyn5moirQJLU0krC0zJxD34MDkSq8YZL8vuU7Ukbpx3MDm2lIiEdNTSbMjEL6",
    "CW5gkT3DsBuQplt3pTxI+GxzWWWTcdX0qr4GYjYAIYFTTVyIgwrMs/KDpK6mKshf1Vq20Kik4fc",
    "YMhJGkmuTOhy0FVWqnYcuE32CN0nRUZtPai8jsEVhDJrAEYQaa7JIZx1ilL4ZFIz+LDqZfe0RY6",
    "yMxAY1BU2bkEiR0Olq6oagCGjqkBkiSwFGoZWR9/IIoZwxIUcqDv+UO+Pe6p+X9cO6/fJPvX7O6",
    "H6/ULQNpZqDYyalko0glGsd2Tftt/fQqi/NxPMB7pyPH3t+HnERIRuNmj/oOSRYsC2OCzuD71Kb",
    "elLIhQcpJtkyd8KdG8gfxDXw43bqmUXQ496DfVIXXtJTpdJjlkhcOBww9PnIMau5YhdVfurUnm3",
    "8PVl362MUnE5KyjFddrOQhtnMapn/WdZh+KOTEhZpHKvszhvZ3TBpLOrtAKFRc1SvivH/Rg5rkb",
    "kuKr58zI27/VNAPYvJEcZmMG1z4SrQOvyWTiGT/cI8+nSPYmRrxahqwV2ut3fTlzCH5pZT4Pg/+",
    "Pg1NUnuPIVyh5RaN725LoRkuutGBzPBved32bqXb0GoQ/j57TpB8kLldLmpzsQXb+3XLm2ZVB2x",
    "14ssXW/v49C/WX69BfGxyDvt2PkXY/Iuz5kvAVXNVUSnMXZWZy9KnE2KF0YtzMTx9tpQl5lArqV",
    "EN1shM9khG46sNGViZ++//P+PzffvXr30oe/fvdsGP67F9Otb54P2u911yl6s6LWkYlDEv9fivh",
    "ftblebGyI1Qf6At1bX35wj5C6yNNbXn8/v328vLMRebv359TaiKqSVP/MKJmhUgq4/vpdFO/TMf",
    "aY+Q/e//piOPq5lSh9P3tNRew15c8ZxW4Ev6enxwdD6XF3bPS4uBI3HmVCMerrMalRV4jxkP9yI",
    "j+8FvGDavvrrO0x8cOVIfXojEiPCyvD0R/N9/30OBfR45y33oBxzaBud5Fe9fO7li5vd+eXigZr",
    "SHP6yDMdMy+dCdVcmnZnxTsd6COxy7j4Jw5n0xH/qLbtVX3BeJo5Zb/sHvh+eXywMoq4fRxjjzs",
    "Re6h2dtVxMDK89RqeraxWy6trta1rC9eWwDxwnOdNQhggppqEOAy1VEktH9fUvXn7DB8jxMejAB",
    "+PTgQfWxF7bI0eH6QLkP8DPvrVPd6acEBvnTY+DkwfH3NwJPj4McYeRsQexujxUbON5uJnNxau1",
    "zxDN1wcAOYMLyPAy7MAL/dPBi9mxB7mi8CLWFxeXroOWAQwZ3gZAV6eBnhZeXnyC7fYkkFJ82XM",
    "L6derzwJ6pVfzuqVuPWiQfCxGWOPuYg95ry9TTWgvmDDWv8vpedHsC6alk47oxsLuswrqF+SfQC",
    "D0k1pw+07OCm6YfV70d91xu39Qb9zjpse0fNx/teO+H989foj5frq+0H7Zm+fZc5C2Oyz0yt4XI",
    "ag0e/pCen3JOb9TOT9k/r+n1aPv1P6qfu9saD8FGz8v7e0KuXrcORvcure3mRq/3bvEYOA99+nd",
    "xrj1jD1/Xa1+MmNIca/fwFox0QP",
    ""
  };

  static char newstr [2353] = "";
  newstr[0] = '\0';
  for (i = 0; i < 33; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c3_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c3_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2308768294U));
  ssSetChecksum1(S,(1056792807U));
  ssSetChecksum2(S,(391719963U));
  ssSetChecksum3(S,(3230058789U));
}

static void mdlRTW_c3_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c3_flightControlSystem(SimStruct *S)
{
  SFc3_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc3_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && sfHasContStates(S)> 0 &&
      !supportsLegacyBehaviorForPersistentVarInContinuousTime(S)) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c3_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c3_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c3_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c3_JITStateAnimation,
    chartInstance->c3_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c3_flightControlSystem(chartInstance);
}

void c3_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c3_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
