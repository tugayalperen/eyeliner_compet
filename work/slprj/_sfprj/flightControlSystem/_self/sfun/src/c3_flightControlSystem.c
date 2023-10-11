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

static emlrtRSInfo c3_hb_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_ib_emlrtRSI = { 325,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_jb_emlrtRSI = { 317,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_kb_emlrtRSI = { 316,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_lb_emlrtRSI = { 308,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_mb_emlrtRSI = { 427,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_nb_emlrtRSI = { 420,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c3_ob_emlrtRSI = { 392,/* lineNo */
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

static emlrtRSInfo c3_yb_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/matfun/mpower.m"/* pathName */
};

static emlrtRSInfo c3_ac_emlrtRSI = { 11,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_bc_emlrtRSI = { 14,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_cc_emlrtRSI = { 19,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_dc_emlrtRSI = { 29,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_ec_emlrtRSI = { 42,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_fc_emlrtRSI = { 43,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_gc_emlrtRSI = { 52,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_hc_emlrtRSI = { 53,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_ic_emlrtRSI = { 70,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_jc_emlrtRSI = { 73,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_kc_emlrtRSI = { 74,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_lc_emlrtRSI = { 88,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_mc_emlrtRSI = { 92,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_nc_emlrtRSI = { 117,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_oc_emlrtRSI = { 99,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_pc_emlrtRSI = { 101,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_qc_emlrtRSI = { 104,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_rc_emlrtRSI = { 108,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_sc_emlrtRSI = { 107,/* lineNo */
  "Image Processing System/send_only_points",/* fcnName */
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

static emlrtRTEInfo c3_c_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_d_emlrtRTEI = { 33,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_e_emlrtRTEI = { 52,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_f_emlrtRTEI = { 52,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_g_emlrtRTEI = { 42,/* lineNo */
  30,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_h_emlrtRTEI = { 53,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_i_emlrtRTEI = { 42,/* lineNo */
  66,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_j_emlrtRTEI = { 53,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_k_emlrtRTEI = { 43,/* lineNo */
  16,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_l_emlrtRTEI = { 70,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_m_emlrtRTEI = { 70,/* lineNo */
  54,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_n_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/sort.m"/* pName */
};

static emlrtRTEInfo c3_o_emlrtRTEI = { 74,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_p_emlrtRTEI = { 80,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_q_emlrtRTEI = { 80,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_r_emlrtRTEI = { 81,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_s_emlrtRTEI = { 81,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_t_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_u_emlrtRTEI = { 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_v_emlrtRTEI = { 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_w_emlrtRTEI = { 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_x_emlrtRTEI = { 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_y_emlrtRTEI = { 71,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo c3_ab_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "sqrt",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRTEInfo c3_bb_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_cb_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_db_emlrtRTEI = { 572,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_eb_emlrtRTEI = { 482,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_fb_emlrtRTEI = { 520,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_gb_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "isinf",                             /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/isinf.m"/* pName */
};

static emlrtRTEInfo c3_hb_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "isnan",                             /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/isnan.m"/* pName */
};

static emlrtRTEInfo c3_ib_emlrtRTEI = { 12,/* lineNo */
  37,                                  /* colNo */
  "sqrt",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRTEInfo c3_jb_emlrtRTEI = { 30,/* lineNo */
  42,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_kb_emlrtRTEI = { 56,/* lineNo */
  24,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_lb_emlrtRTEI = { 75,/* lineNo */
  26,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_mb_emlrtRTEI = { 76,/* lineNo */
  39,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_nb_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_ob_emlrtRTEI = { 267,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_pb_emlrtRTEI = { 385,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_qb_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_rb_emlrtRTEI = { 274,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_sb_emlrtRTEI = { 387,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_tb_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c3_ub_emlrtRTEI = { 87,/* lineNo */
  13,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_vb_emlrtRTEI = { 87,/* lineNo */
  14,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_wb_emlrtRTEI = { 87,/* lineNo */
  19,                                  /* colNo */
  "sort",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c3_xb_emlrtRTEI = { 42,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_yb_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_ac_emlrtRTEI = { 36,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtBCInfo c3_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  40,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_emlrtDCI = { 42, /* lineNo */
  42,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  42,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  76,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_b_emlrtDCI = { 42,/* lineNo */
  78,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  78,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c3_emlrtECI = { 1,  /* nDims */
  42,                                  /* lineNo */
  29,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtBCInfo c3_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_c_emlrtDCI = { 52,/* lineNo */
  25,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  25,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_d_emlrtDCI = { 53,/* lineNo */
  25,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  25,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c3_b_emlrtECI = { 1,/* nDims */
  70,                                  /* lineNo */
  26,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtBCInfo c3_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  32,                                  /* colNo */
  "sortedIndices",                     /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_e_emlrtDCI = { 74,/* lineNo */
  34,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  34,                                  /* colNo */
  "sortedIndices",                     /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_f_emlrtDCI = { 80,/* lineNo */
  11,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_k_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  80,                                  /* lineNo */
  11,                                  /* colNo */
  "pointsx",                           /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c3_c_emlrtECI = { -1,/* nDims */
  80,                                  /* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtDCInfo c3_g_emlrtDCI = { 81,/* lineNo */
  11,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_l_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  81,                                  /* lineNo */
  11,                                  /* colNo */
  "pointsy",                           /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c3_d_emlrtECI = { -1,/* nDims */
  81,                                  /* lineNo */
  1,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_bc_emlrtRTEI = { 114,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtDCInfo c3_h_emlrtDCI = { 121,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_m_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  121,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_i_emlrtDCI = { 121,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_n_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  121,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_j_emlrtDCI = { 122,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_o_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  122,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_k_emlrtDCI = { 122,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_p_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  122,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_l_emlrtDCI = { 123,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_q_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  123,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_m_emlrtDCI = { 123,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_r_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  123,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_n_emlrtDCI = { 32,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c3_o_emlrtDCI = { 32,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c3_p_emlrtDCI = { 33,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c3_q_emlrtDCI = { 33,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  33,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_r_emlrtDCI = { 39,/* lineNo */
  33,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  19,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_s_emlrtDCI = { 39,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  33,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_t_emlrtDCI = { 40,/* lineNo */
  33,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  19,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_u_emlrtDCI = { 40,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  56,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_v_emlrtDCI = { 42,/* lineNo */
  56,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  92,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_w_emlrtDCI = { 42,/* lineNo */
  92,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  37,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_x_emlrtDCI = { 45,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_y_emlrtDCI = { 45,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  37,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_ab_emlrtDCI = { 46,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_bb_emlrtDCI = { 46,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  47,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_cb_emlrtDCI = { 80,/* lineNo */
  47,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  47,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_db_emlrtDCI = { 81,/* lineNo */
  47,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_fb_emlrtBCI = { 0,/* iFirst */
  19,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "pointsx",                           /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_eb_emlrtDCI = { 85,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_gb_emlrtBCI = { 0,/* iFirst */
  19,                                  /* iLast */
  86,                                  /* lineNo */
  27,                                  /* colNo */
  "pointsy",                           /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_fb_emlrtDCI = { 86,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  30,                                  /* colNo */
  "unsorted_validY",                   /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_gb_emlrtDCI = { 93,/* lineNo */
  30,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  31,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_hb_emlrtDCI = { 118,/* lineNo */
  31,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  119,                                 /* lineNo */
  31,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/send_only_points",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_ib_emlrtDCI = { 119,/* lineNo */
  31,                                  /* colNo */
  "Image Processing System/send_only_points",/* fName */
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
static void c3_b_sort(SFc3_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_c_x_data[], int32_T
                      c3_x_size[1], real_T c3_d_x_data[], int32_T c3_b_x_size[1],
                      int32_T c3_idx_data[], int32_T c3_idx_size[1]);
static boolean_T c3_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_a__output_of_isempty_, const char_T
  *c3_identifier);
static boolean_T c3_b_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *c3_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u[6]);
static const mxArray *c3_b_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const real_T
   c3_u_data[], const int32_T c3_u_size[1]);
static const mxArray *c3_c_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const real_T c3_b_u[4]);
static real_T c3_c_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_distX, const char_T *c3_identifier);
static real_T c3_d_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_c_outt, const char_T *c3_identifier, uint8_T
  c3_b_y[57600]);
static void c3_f_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  uint8_T c3_b_y[57600]);
static void c3_g_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_pointsx, const char_T *c3_identifier,
  real_T c3_b_y[20]);
static void c3_h_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_b_y[20]);
static real_T c3_i_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_call_count, const char_T *c3_identifier,
  boolean_T *c3_svPtr);
static real_T c3_j_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr);
static const mxArray *c3_k_emlrt_marshallIn
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const mxArray
   *c3_b_hAx, boolean_T *c3_svPtr);
static const mxArray *c3_l_emlrt_marshallIn
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const mxArray *c3_b_u,
   boolean_T *c3_svPtr);
static uint8_T c3_m_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_flightControlSystem, const
  char_T *c3_identifier);
static uint8_T c3_n_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_slStringInitializeDynamicBuffers
  (SFc3_flightControlSystemInstanceStruct *chartInstance);
static void c3_chart_data_browse_helper(SFc3_flightControlSystemInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig);
static const mxArray *c3_figure(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp);
static const mxArray *c3_isempty(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0);
static const mxArray *c3_axes(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1);
static const mxArray *c3_b_isempty(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0);
static void c3_b_figure(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, const mxArray *c3_input0);
static void c3_axis(SFc3_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray
                    *c3_input1);
static const mxArray *c3_scatter(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1);
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
  chartInstance->c3_hFig = NULL;
  chartInstance->c3_hFig_not_empty = false;
  chartInstance->c3_hAx = NULL;
  chartInstance->c3_hAx_not_empty = false;
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

  static const int32_T c3_b_condTxtEndIdx[4] = { 3654, 3676, 3685, 3707 };

  static const int32_T c3_b_condTxtStartIdx[4] = { 3649, 3658, 3680, 3689 };

  static const int32_T c3_c_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c3_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c3_c_condTxtEndIdx[2] = { 4041, 4059 };

  static const int32_T c3_c_condTxtStartIdx[2] = { 4025, 4045 };

  static const int32_T c3_condTxtEndIdx[2] = { 2647, 2681 };

  static const int32_T c3_condTxtStartIdx[2] = { 2619, 2651 };

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
    23U);
  covrtChartInitFcn(chartInstance->c3_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c3_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c3_decisionTxtStartIdx, &c3_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c3_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c3_covrtInstance, "", 4U, 0U, 1U, 0U, 9U, 0U,
                  2U, 0U, 5U, 0U, 8U, 3U);
  covrtEmlFcnInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 4156);
  covrtEmlSaturationInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 3785,
    -1, 3831);
  covrtEmlSaturationInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 721, -1,
    779);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 114, 136, -1,
                    160, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 965, 978, 1082,
                    1351, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 1195, 1220, -1,
                    1343, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 2616, 2681, -1,
                    3328, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 2970, 2986,
                    3168, 3262, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 3475, 3501, -1,
                    3944, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 6U, 3646, 3707, -1,
                    3928, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 7U, 3970, 3988,
                    4018, 4121, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 8U, 4018, 4059,
                    4087, 4121, false);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 475, 511, 561);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 938, 960, 1355);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 3375, 3402,
                     3968);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 3407, 3430,
                     3964);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 3439, 3462,
                     3956);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 2619, 2681,
                      2U, 0U, c3_condTxtStartIdx, c3_condTxtEndIdx, 3U,
                      c3_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 3649, 3707,
                      4U, 2U, c3_b_condTxtStartIdx, c3_b_condTxtEndIdx, 7U,
                      c3_b_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 4025, 4059,
                      2U, 6U, c3_c_condTxtStartIdx, c3_c_condTxtEndIdx, 3U,
                      c3_c_postfixPredicateTree, false);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 968,
    978, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 2619,
    2647, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 3478,
    3501, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 3649,
    3654, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 3658,
    3676, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 3680,
    3685, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 6U, 3689,
    3707, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 7U, 3973,
    3988, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 8U, 4025,
    4041, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 9U, 4045,
    4059, -1, 2U);
}

static void mdl_cleanup_runtime_resources_c3_flightControlSystem
  (SFc3_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c3_RuntimeVar);
  sf_mex_destroy(&chartInstance->c3_hFig);
  sf_mex_destroy(&chartInstance->c3_hAx);
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
  static real_T c3_dv1[4] = { -60.0, 60.0, -80.0, 80.0 };

  static char_T c3_cv[6] = { 'P', 'a', 'r', 'e', 'n', 't' };

  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c3_b_pointsx[20];
  real_T c3_b_pointsy[20];
  real_T c3_closestIndices_data[20];
  real_T c3_sortIdx_data[20];
  real_T c3_unsorted_validY_data[20];
  real_T c3_validY_data[20];
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
  real_T c3_d_y;
  real_T c3_e_a;
  real_T c3_e_y;
  real_T c3_f_a;
  real_T c3_f_y;
  real_T c3_g_a;
  real_T c3_g_y;
  real_T c3_h_a;
  real_T c3_h_y;
  real_T c3_i_a;
  real_T c3_j_a;
  real_T c3_k_a;
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
  int32_T c3_unsorted_validY_size[1];
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
  int32_T c3_h_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i100;
  int32_T c3_i101;
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
  int32_T c3_unsorted_validY;
  int32_T c3_v_loop_ub;
  int32_T c3_w_loop_ub;
  int32_T c3_x_loop_ub;
  int32_T c3_y_loop_ub;
  uint8_T c3_b_u;
  uint8_T c3_u1;
  boolean_T c3_b_centerline[19200];
  boolean_T c3_b_minDistances_data[19200];
  boolean_T c3_bv1[19200];
  boolean_T c3_centerline[19200];
  boolean_T c3_cleanedImage[19200];
  boolean_T c3_greenChannel[19200];
  boolean_T c3_redChannel[19200];
  boolean_T c3_bv2[20];
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
  boolean_T c3_b_covSaturation = false;
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
    chartInstance->c3_call_count = 1.0;
    chartInstance->c3_call_count_not_empty = true;
  }

  c3_b_st.site = &c3_ac_emlrtRSI;
  for (c3_i1 = 0; c3_i1 < 19200; c3_i1++) {
    chartInstance->c3_bv[c3_i1] = (*chartInstance->c3_u)[c3_i1];
  }

  c3_bwmorph(chartInstance, chartInstance->c3_bv, c3_cleanedImage);
  c3_b_st.site = &c3_bc_emlrtRSI;
  c3_b_bwmorph(chartInstance, c3_cleanedImage, c3_centerline);
  for (c3_k = 0; c3_k < 15; c3_k++) {
    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 0, 1);
    for (c3_i3 = 0; c3_i3 < 19200; c3_i3++) {
      c3_b_centerline[c3_i3] = c3_centerline[c3_i3];
    }

    c3_b_st.site = &c3_cc_emlrtRSI;
    c3_c_bwmorph(chartInstance, c3_b_centerline, c3_centerline);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 0, 0);
  for (c3_i2 = 0; c3_i2 < 19200; c3_i2++) {
    c3_redChannel[c3_i2] = !c3_centerline[c3_i2];
  }

  for (c3_i4 = 0; c3_i4 < 19200; c3_i4++) {
    c3_redChannel[c3_i4] = (c3_cleanedImage[c3_i4] && c3_redChannel[c3_i4]);
  }

  for (c3_i5 = 0; c3_i5 < 19200; c3_i5++) {
    c3_greenChannel[c3_i5] = !c3_centerline[c3_i5];
  }

  for (c3_i6 = 0; c3_i6 < 19200; c3_i6++) {
    c3_greenChannel[c3_i6] = (c3_cleanedImage[c3_i6] && c3_greenChannel[c3_i6]);
  }

  for (c3_i7 = 0; c3_i7 < 19200; c3_i7++) {
    c3_bv1[c3_i7] = !c3_centerline[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 19200; c3_i8++) {
    c3_cleanedImage[c3_i8] = (c3_cleanedImage[c3_i8] && c3_bv1[c3_i8]);
  }

  c3_cat(chartInstance, c3_redChannel, c3_greenChannel, c3_cleanedImage,
         chartInstance->c3_a);
  for (c3_i9 = 0; c3_i9 < 57600; c3_i9++) {
    chartInstance->c3_y[c3_i9] = (real_T)chartInstance->c3_a[c3_i9] * 255.0;
  }

  for (c3_i10 = 0; c3_i10 < 57600; c3_i10++) {
    c3_d = muDoubleScalarRound(chartInstance->c3_y[c3_i10]);
    c3_covSaturation = false;
    if (c3_d < 256.0) {
      if (c3_d >= 0.0) {
        c3_b_u = (uint8_T)c3_d;
      } else {
        c3_covSaturation = true;
        c3_b_u = 0U;
        sf_data_saturate_error(chartInstance->S, 1U, 721, 58);
      }
    } else if (c3_d >= 256.0) {
      c3_covSaturation = true;
      c3_b_u = MAX_uint8_T;
      sf_data_saturate_error(chartInstance->S, 1U, 721, 58);
    } else {
      c3_b_u = 0U;
    }

    covrtSaturationUpdateFcn(chartInstance->c3_covrtInstance, 4, 0, 1, 0,
      c3_covSaturation);
    chartInstance->c3_outt[c3_i10] = c3_b_u;
  }

  c3_b_st.site = &c3_dc_emlrtRSI;
  c3_c_st.site = &c3_l_emlrtRSI;
  c3_eml_find(chartInstance, &c3_c_st, c3_centerline, chartInstance->c3_ii_data,
              c3_ii_size, chartInstance->c3_jj_data, c3_jj_size);
  c3_yIdx_size[0] = c3_ii_size[0];
  c3_loop_ub = c3_ii_size[0] - 1;
  for (c3_i11 = 0; c3_i11 <= c3_loop_ub; c3_i11++) {
    chartInstance->c3_yIdx_data[c3_i11] = (real_T)chartInstance->
      c3_ii_data[c3_i11];
  }

  c3_xIdx_size[0] = c3_jj_size[0];
  c3_b_loop_ub = c3_jj_size[0] - 1;
  for (c3_i12 = 0; c3_i12 <= c3_b_loop_ub; c3_i12++) {
    chartInstance->c3_xIdx_data[c3_i12] = (real_T)chartInstance->
      c3_jj_data[c3_i12];
  }

  c3_d1 = (real_T)c3_xIdx_size[0];
  if (!(c3_d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c3_d1, &c3_n_emlrtDCI, &c3_st);
  }

  if (c3_d1 != (real_T)(int32_T)muDoubleScalarFloor(c3_d1)) {
    emlrtIntegerCheckR2012b(c3_d1, &c3_o_emlrtDCI, &c3_st);
  }

  c3_dv[0] = c3_d1;
  c3_filteredX_size[0] = c3__s32_d_(chartInstance, trunc(c3_dv[0]), 0, 1U, 864,
    29);
  c3_c_loop_ub = c3__s32_d_(chartInstance, trunc(c3_dv[0]), 0, 1U, 864, 29) - 1;
  for (c3_i13 = 0; c3_i13 <= c3_c_loop_ub; c3_i13++) {
    chartInstance->c3_filteredX_data[c3_i13] = 0.0;
  }

  c3_d2 = (real_T)c3_yIdx_size[0];
  if (!(c3_d2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c3_d2, &c3_p_emlrtDCI, &c3_st);
  }

  if (c3_d2 != (real_T)(int32_T)muDoubleScalarFloor(c3_d2)) {
    emlrtIntegerCheckR2012b(c3_d2, &c3_q_emlrtDCI, &c3_st);
  }

  c3_dv[0] = c3_d2;
  c3_filteredY_size[0] = c3__s32_d_(chartInstance, trunc(c3_dv[0]), 0, 1U, 895,
    29);
  c3_d_loop_ub = c3__s32_d_(chartInstance, trunc(c3_dv[0]), 0, 1U, 895, 29) - 1;
  for (c3_i14 = 0; c3_i14 <= c3_d_loop_ub; c3_i14++) {
    chartInstance->c3_filteredY_data[c3_i14] = 0.0;
  }

  c3_count = 0.0;
  c3_d3 = (real_T)c3_xIdx_size[0];
  c3_i15 = (int32_T)c3_d3;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c3_d3, mxDOUBLE_CLASS, c3_i15,
    &c3_ac_emlrtRTEI, &c3_st);
  for (c3_b_i = 0; c3_b_i < c3_i15; c3_b_i++) {
    c3_c_i = 1.0 + (real_T)c3_b_i;
    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 1, 1);
    if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 1,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 0U, c3_count,
                        0.0, -1, 0U, c3_count == 0.0))) {
      c3_count++;
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_r_emlrtDCI, &c3_st);
      }

      c3_i18 = (int32_T)c3_c_i;
      if ((c3_i18 < 1) || (c3_i18 > c3_xIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i18, 1, c3_xIdx_size[0], &c3_s_emlrtBCI,
          &c3_st);
      }

      if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
        emlrtIntegerCheckR2012b(c3_count, &c3_s_emlrtDCI, &c3_st);
      }

      c3_i23 = (int32_T)c3_count;
      if ((c3_i23 < 1) || (c3_i23 > c3_filteredX_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i23, 1, c3_filteredX_size[0],
          &c3_t_emlrtBCI, &c3_st);
      }

      chartInstance->c3_filteredX_data[c3_i23 - 1] = chartInstance->
        c3_xIdx_data[c3_i18 - 1];
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_t_emlrtDCI, &c3_st);
      }

      c3_i27 = (int32_T)c3_c_i;
      if ((c3_i27 < 1) || (c3_i27 > c3_yIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i27, 1, c3_yIdx_size[0], &c3_u_emlrtBCI,
          &c3_st);
      }

      if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
        emlrtIntegerCheckR2012b(c3_count, &c3_u_emlrtDCI, &c3_st);
      }

      c3_i32 = (int32_T)c3_count;
      if ((c3_i32 < 1) || (c3_i32 > c3_filteredY_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i32, 1, c3_filteredY_size[0],
          &c3_v_emlrtBCI, &c3_st);
      }

      chartInstance->c3_filteredY_data[c3_i32 - 1] = chartInstance->
        c3_yIdx_data[c3_i27 - 1];
    } else {
      c3_b3 = (c3_count < 1.0);
      c3_b5 = c3_b3;
      c3_b6 = false;
      c3_b7 = (c3_b5 || c3_b6);
      if (c3_b7) {
        c3_i21 = 1;
        c3_i22 = 0;
      } else {
        c3_i20 = 1;
        if ((c3_i20 < 1) || (c3_i20 > c3_filteredX_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i20, 1, c3_filteredX_size[0],
            &c3_emlrtBCI, &c3_st);
        }

        c3_i21 = c3_i20;
        if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
          emlrtIntegerCheckR2012b(c3_count, &c3_emlrtDCI, &c3_st);
        }

        c3_i25 = (int32_T)c3_count;
        if ((c3_i25 < 1) || (c3_i25 > c3_filteredX_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i25, 1, c3_filteredX_size[0],
            &c3_b_emlrtBCI, &c3_st);
        }

        c3_i22 = c3_i25;
      }

      c3_iv1[0] = 1;
      c3_iv1[1] = (c3_i22 - c3_i21) + 1;
      c3_b_st.site = &c3_ec_emlrtRSI;
      c3_indexShapeCheck(chartInstance, &c3_b_st, c3_filteredX_size[0], c3_iv1);
      c3_b8 = (c3_count < 1.0);
      c3_b9 = c3_b8;
      c3_b10 = false;
      c3_b11 = (c3_b9 || c3_b10);
      if (c3_b11) {
        c3_i30 = 1;
        c3_i31 = 0;
      } else {
        c3_i29 = 1;
        if ((c3_i29 < 1) || (c3_i29 > c3_filteredY_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i29, 1, c3_filteredY_size[0],
            &c3_c_emlrtBCI, &c3_st);
        }

        c3_i30 = c3_i29;
        if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
          emlrtIntegerCheckR2012b(c3_count, &c3_b_emlrtDCI, &c3_st);
        }

        c3_i35 = (int32_T)c3_count;
        if ((c3_i35 < 1) || (c3_i35 > c3_filteredY_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i35, 1, c3_filteredY_size[0],
            &c3_d_emlrtBCI, &c3_st);
        }

        c3_i31 = c3_i35;
      }

      c3_iv2[0] = 1;
      c3_iv2[1] = (c3_i31 - c3_i30) + 1;
      c3_b_st.site = &c3_ec_emlrtRSI;
      c3_indexShapeCheck(chartInstance, &c3_b_st, c3_filteredY_size[0], c3_iv2);
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_v_emlrtDCI, &c3_st);
      }

      c3_i37 = (int32_T)c3_c_i;
      if ((c3_i37 < 1) || (c3_i37 > c3_xIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i37, 1, c3_xIdx_size[0], &c3_w_emlrtBCI,
          &c3_st);
      }

      c3_xIdx = chartInstance->c3_xIdx_data[c3_i37 - 1];
      c3_c_filteredX_size[0] = (c3_i22 - c3_i21) + 1;
      c3_h_loop_ub = c3_i22 - c3_i21;
      for (c3_i40 = 0; c3_i40 <= c3_h_loop_ub; c3_i40++) {
        chartInstance->c3_c_filteredX_data[c3_i40] =
          chartInstance->c3_filteredX_data[(c3_i21 + c3_i40) - 1] - c3_xIdx;
      }

      c3_b_st.site = &c3_ec_emlrtRSI;
      c3_power(chartInstance, &c3_b_st, chartInstance->c3_c_filteredX_data,
               c3_c_filteredX_size, chartInstance->c3_minDistances_data,
               c3_minDistances_size);
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_w_emlrtDCI, &c3_st);
      }

      c3_i42 = (int32_T)c3_c_i;
      if ((c3_i42 < 1) || (c3_i42 > c3_yIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i42, 1, c3_yIdx_size[0], &c3_x_emlrtBCI,
          &c3_st);
      }

      c3_yIdx = chartInstance->c3_yIdx_data[c3_i42 - 1];
      c3_c_filteredY_size[0] = (c3_i31 - c3_i30) + 1;
      c3_l_loop_ub = c3_i31 - c3_i30;
      for (c3_i45 = 0; c3_i45 <= c3_l_loop_ub; c3_i45++) {
        chartInstance->c3_c_filteredY_data[c3_i45] =
          chartInstance->c3_filteredY_data[(c3_i30 + c3_i45) - 1] - c3_yIdx;
      }

      c3_b_st.site = &c3_ec_emlrtRSI;
      c3_power(chartInstance, &c3_b_st, chartInstance->c3_c_filteredY_data,
               c3_c_filteredY_size, chartInstance->c3_tmp_data, c3_tmp_size);
      if ((c3_minDistances_size[0] != c3_tmp_size[0]) && ((c3_minDistances_size
            [0] != 1) && (c3_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_minDistances_size[0], c3_tmp_size[0],
          &c3_emlrtECI, &c3_st);
      }

      if (c3_minDistances_size[0] == c3_tmp_size[0]) {
        c3_o_loop_ub = c3_minDistances_size[0] - 1;
        for (c3_i48 = 0; c3_i48 <= c3_o_loop_ub; c3_i48++) {
          chartInstance->c3_minDistances_data[c3_i48] +=
            chartInstance->c3_tmp_data[c3_i48];
        }
      } else {
        c3_plus(chartInstance, chartInstance->c3_minDistances_data,
                c3_minDistances_size, chartInstance->c3_tmp_data, c3_tmp_size);
      }

      c3_b_st.site = &c3_ec_emlrtRSI;
      c3_b_sqrt(chartInstance, &c3_b_st, chartInstance->c3_minDistances_data,
                c3_minDistances_size);
      c3_b_minDistances_size[0] = c3_minDistances_size[0];
      c3_p_loop_ub = c3_minDistances_size[0] - 1;
      for (c3_i49 = 0; c3_i49 <= c3_p_loop_ub; c3_i49++) {
        c3_b_minDistances_data[c3_i49] = (chartInstance->
          c3_minDistances_data[c3_i49] > 10.0);
      }

      c3_b_st.site = &c3_fc_emlrtRSI;
      if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 2, c3_all
                         (chartInstance, &c3_b_st, c3_b_minDistances_data,
                          c3_b_minDistances_size))) {
        c3_count++;
        if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
          emlrtIntegerCheckR2012b(c3_c_i, &c3_x_emlrtDCI, &c3_st);
        }

        c3_i51 = (int32_T)c3_c_i;
        if ((c3_i51 < 1) || (c3_i51 > c3_xIdx_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i51, 1, c3_xIdx_size[0],
            &c3_y_emlrtBCI, &c3_st);
        }

        if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
          emlrtIntegerCheckR2012b(c3_count, &c3_y_emlrtDCI, &c3_st);
        }

        c3_i53 = (int32_T)c3_count;
        if ((c3_i53 < 1) || (c3_i53 > c3_filteredX_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i53, 1, c3_filteredX_size[0],
            &c3_ab_emlrtBCI, &c3_st);
        }

        chartInstance->c3_filteredX_data[c3_i53 - 1] =
          chartInstance->c3_xIdx_data[c3_i51 - 1];
        if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
          emlrtIntegerCheckR2012b(c3_c_i, &c3_ab_emlrtDCI, &c3_st);
        }

        c3_i54 = (int32_T)c3_c_i;
        if ((c3_i54 < 1) || (c3_i54 > c3_yIdx_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i54, 1, c3_yIdx_size[0],
            &c3_bb_emlrtBCI, &c3_st);
        }

        if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
          emlrtIntegerCheckR2012b(c3_count, &c3_bb_emlrtDCI, &c3_st);
        }

        c3_i55 = (int32_T)c3_count;
        if ((c3_i55 < 1) || (c3_i55 > c3_filteredY_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i55, 1, c3_filteredY_size[0],
            &c3_cb_emlrtBCI, &c3_st);
        }

        chartInstance->c3_filteredY_data[c3_i55 - 1] =
          chartInstance->c3_yIdx_data[c3_i54 - 1];
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
    c3_i17 = 1;
    c3_i19 = 0;
  } else {
    c3_i16 = 1;
    if ((c3_i16 < 1) || (c3_i16 > c3_filteredX_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i16, 1, c3_filteredX_size[0],
        &c3_e_emlrtBCI, &c3_st);
    }

    c3_i17 = c3_i16;
    if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
      emlrtIntegerCheckR2012b(c3_count, &c3_c_emlrtDCI, &c3_st);
    }

    c3_i24 = (int32_T)c3_count;
    if ((c3_i24 < 1) || (c3_i24 > c3_filteredX_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i24, 1, c3_filteredX_size[0],
        &c3_f_emlrtBCI, &c3_st);
    }

    c3_i19 = c3_i24;
  }

  c3_iv[0] = 1;
  c3_iv[1] = (c3_i19 - c3_i17) + 1;
  c3_b_st.site = &c3_gc_emlrtRSI;
  c3_indexShapeCheck(chartInstance, &c3_b_st, c3_filteredX_size[0], c3_iv);
  c3_b_filteredX_size[0] = (c3_i19 - c3_i17) + 1;
  c3_e_loop_ub = c3_i19 - c3_i17;
  for (c3_i26 = 0; c3_i26 <= c3_e_loop_ub; c3_i26++) {
    chartInstance->c3_b_filteredX_data[c3_i26] =
      chartInstance->c3_filteredX_data[(c3_i17 + c3_i26) - 1];
  }

  c3_filteredX_size[0] = c3_b_filteredX_size[0];
  c3_f_loop_ub = c3_b_filteredX_size[0] - 1;
  for (c3_i28 = 0; c3_i28 <= c3_f_loop_ub; c3_i28++) {
    chartInstance->c3_filteredX_data[c3_i28] =
      chartInstance->c3_b_filteredX_data[c3_i28];
  }

  c3_b12 = (c3_count < 1.0);
  c3_b13 = c3_b12;
  c3_b14 = false;
  c3_b15 = (c3_b13 || c3_b14);
  if (c3_b15) {
    c3_i34 = 1;
    c3_i36 = 0;
  } else {
    c3_i33 = 1;
    if ((c3_i33 < 1) || (c3_i33 > c3_filteredY_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i33, 1, c3_filteredY_size[0],
        &c3_g_emlrtBCI, &c3_st);
    }

    c3_i34 = c3_i33;
    if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
      emlrtIntegerCheckR2012b(c3_count, &c3_d_emlrtDCI, &c3_st);
    }

    c3_i38 = (int32_T)c3_count;
    if ((c3_i38 < 1) || (c3_i38 > c3_filteredY_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i38, 1, c3_filteredY_size[0],
        &c3_h_emlrtBCI, &c3_st);
    }

    c3_i36 = c3_i38;
  }

  c3_iv3[0] = 1;
  c3_iv3[1] = (c3_i36 - c3_i34) + 1;
  c3_b_st.site = &c3_hc_emlrtRSI;
  c3_indexShapeCheck(chartInstance, &c3_b_st, c3_filteredY_size[0], c3_iv3);
  c3_b_filteredY_size[0] = (c3_i36 - c3_i34) + 1;
  c3_g_loop_ub = c3_i36 - c3_i34;
  for (c3_i39 = 0; c3_i39 <= c3_g_loop_ub; c3_i39++) {
    chartInstance->c3_b_filteredY_data[c3_i39] =
      chartInstance->c3_filteredY_data[(c3_i34 + c3_i39) - 1];
  }

  c3_filteredY_size[0] = c3_b_filteredY_size[0];
  c3_i_loop_ub = c3_b_filteredY_size[0] - 1;
  for (c3_i41 = 0; c3_i41 <= c3_i_loop_ub; c3_i41++) {
    chartInstance->c3_filteredY_data[c3_i41] =
      chartInstance->c3_b_filteredY_data[c3_i41];
  }

  c3_j_loop_ub = c3_filteredX_size[0] - 1;
  for (c3_i43 = 0; c3_i43 <= c3_j_loop_ub; c3_i43++) {
    chartInstance->c3_filteredX_data[c3_i43] -= 80.0;
  }

  c3_k_loop_ub = c3_filteredY_size[0] - 1;
  for (c3_i44 = 0; c3_i44 <= c3_k_loop_ub; c3_i44++) {
    chartInstance->c3_filteredY_data[c3_i44] -= 60.0;
  }

  c3_d_filteredX_size[0] = c3_filteredX_size[0];
  c3_m_loop_ub = c3_filteredX_size[0] - 1;
  for (c3_i46 = 0; c3_i46 <= c3_m_loop_ub; c3_i46++) {
    chartInstance->c3_d_filteredX_data[c3_i46] =
      chartInstance->c3_filteredX_data[c3_i46] - 80.0;
  }

  c3_b_st.site = &c3_ic_emlrtRSI;
  c3_power(chartInstance, &c3_b_st, chartInstance->c3_d_filteredX_data,
           c3_d_filteredX_size, chartInstance->c3_yIdx_data, c3_yIdx_size);
  c3_d_filteredY_size[0] = c3_filteredY_size[0];
  c3_n_loop_ub = c3_filteredY_size[0] - 1;
  for (c3_i47 = 0; c3_i47 <= c3_n_loop_ub; c3_i47++) {
    chartInstance->c3_d_filteredY_data[c3_i47] =
      chartInstance->c3_filteredY_data[c3_i47] - 60.0;
  }

  c3_b_st.site = &c3_ic_emlrtRSI;
  c3_power(chartInstance, &c3_b_st, chartInstance->c3_d_filteredY_data,
           c3_d_filteredY_size, chartInstance->c3_tmp_data, c3_tmp_size);
  if ((c3_yIdx_size[0] != c3_tmp_size[0]) && ((c3_yIdx_size[0] != 1) &&
       (c3_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c3_yIdx_size[0], c3_tmp_size[0], &c3_b_emlrtECI,
      &c3_st);
  }

  if (c3_yIdx_size[0] == c3_tmp_size[0]) {
    c3_q_loop_ub = c3_yIdx_size[0] - 1;
    for (c3_i50 = 0; c3_i50 <= c3_q_loop_ub; c3_i50++) {
      chartInstance->c3_yIdx_data[c3_i50] += chartInstance->c3_tmp_data[c3_i50];
    }
  } else {
    c3_plus(chartInstance, chartInstance->c3_yIdx_data, c3_yIdx_size,
            chartInstance->c3_tmp_data, c3_tmp_size);
  }

  c3_b_st.site = &c3_ic_emlrtRSI;
  c3_b_sqrt(chartInstance, &c3_b_st, chartInstance->c3_yIdx_data, c3_yIdx_size);
  c3_b_st.site = &c3_jc_emlrtRSI;
  c3_c_st.site = &c3_x_emlrtRSI;
  c3_c_sort(chartInstance, &c3_c_st, chartInstance->c3_yIdx_data, c3_yIdx_size,
            chartInstance->c3_ii_data, c3_ii_size);
  c3_yIdx_size[0] = c3_ii_size[0];
  c3_r_loop_ub = c3_ii_size[0] - 1;
  for (c3_i52 = 0; c3_i52 <= c3_r_loop_ub; c3_i52++) {
    chartInstance->c3_yIdx_data[c3_i52] = (real_T)chartInstance->
      c3_ii_data[c3_i52];
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
    c3_i57 = 1;
    c3_i58 = 0;
  } else {
    c3_i56 = 1;
    if ((c3_i56 < 1) || (c3_i56 > c3_yIdx_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i56, 1, c3_yIdx_size[0], &c3_i_emlrtBCI,
        &c3_st);
    }

    c3_i57 = c3_i56;
    if (c3_d4 != (real_T)(int32_T)muDoubleScalarFloor(c3_d4)) {
      emlrtIntegerCheckR2012b(c3_d4, &c3_e_emlrtDCI, &c3_st);
    }

    c3_i59 = (int32_T)c3_d4;
    if ((c3_i59 < 1) || (c3_i59 > c3_yIdx_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i59, 1, c3_yIdx_size[0], &c3_j_emlrtBCI,
        &c3_st);
    }

    c3_i58 = c3_i59;
  }

  c3_iv4[0] = 1;
  c3_iv4[1] = (c3_i58 - c3_i57) + 1;
  c3_b_st.site = &c3_kc_emlrtRSI;
  c3_indexShapeCheck(chartInstance, &c3_b_st, c3_yIdx_size[0], c3_iv4);
  c3_closestIndices_size[0] = (c3_i58 - c3_i57) + 1;
  c3_s_loop_ub = c3_i58 - c3_i57;
  for (c3_i60 = 0; c3_i60 <= c3_s_loop_ub; c3_i60++) {
    c3_closestIndices_data[c3_i60] = chartInstance->c3_yIdx_data[(c3_i57 +
      c3_i60) - 1];
  }

  for (c3_i61 = 0; c3_i61 < 20; c3_i61++) {
    c3_b_pointsx[c3_i61] = 999.0;
  }

  for (c3_i62 = 0; c3_i62 < 20; c3_i62++) {
    c3_b_pointsy[c3_i62] = 999.0;
  }

  c3_d5 = (real_T)c3_closestIndices_size[0];
  c3_b20 = (c3_d5 < 1.0);
  c3_b21 = c3_b20;
  c3_b22 = false;
  c3_b23 = (c3_b21 || c3_b22);
  if (c3_b23) {
    c3_i63 = 0;
    c3_i64 = 0;
  } else {
    c3_i63 = 0;
    if (c3_d5 != (real_T)(int32_T)muDoubleScalarFloor(c3_d5)) {
      emlrtIntegerCheckR2012b(c3_d5, &c3_f_emlrtDCI, &c3_st);
    }

    c3_i65 = (int32_T)c3_d5;
    if ((c3_i65 < 1) || (c3_i65 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c3_i65, 1, 20, &c3_k_emlrtBCI, &c3_st);
    }

    c3_i64 = c3_i65;
  }

  c3_filteredX = c3_filteredX_size[0];
  c3_unsorted_validY_size[0] = c3_closestIndices_size[0];
  c3_t_loop_ub = c3_closestIndices_size[0] - 1;
  for (c3_i66 = 0; c3_i66 <= c3_t_loop_ub; c3_i66++) {
    if (c3_closestIndices_data[c3_i66] != (real_T)(int32_T)muDoubleScalarFloor
        (c3_closestIndices_data[c3_i66])) {
      emlrtIntegerCheckR2012b(c3_closestIndices_data[c3_i66], &c3_cb_emlrtDCI,
        &c3_st);
    }

    c3_i68 = (int32_T)c3_closestIndices_data[c3_i66];
    if ((c3_i68 < 1) || (c3_i68 > c3_filteredX)) {
      emlrtDynamicBoundsCheckR2012b(c3_i68, 1, c3_filteredX, &c3_db_emlrtBCI,
        &c3_st);
    }

    c3_unsorted_validY_data[c3_i66] = chartInstance->c3_filteredX_data[c3_i68 -
      1];
  }

  c3_i67 = c3_i64 - c3_i63;
  if (c3_i67 != c3_unsorted_validY_size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_i67, c3_unsorted_validY_size[0],
      &c3_c_emlrtECI, &c3_st);
  }

  c3_i69 = c3_i63 + 1;
  c3_b_tmp_size[1] = (c3_i64 - c3_i69) + 1;
  c3_u_loop_ub = c3_i64 - c3_i69;
  for (c3_i70 = 0; c3_i70 <= c3_u_loop_ub; c3_i70++) {
    c3_b_tmp_data[c3_i70] = (c3_i69 + c3_i70) - 1;
  }

  c3_v_loop_ub = c3_b_tmp_size[1] - 1;
  for (c3_i71 = 0; c3_i71 <= c3_v_loop_ub; c3_i71++) {
    c3_b_pointsx[c3_b_tmp_data[c3_i71]] = c3_unsorted_validY_data[c3_i71];
  }

  c3_d6 = (real_T)c3_closestIndices_size[0];
  c3_b24 = (c3_d6 < 1.0);
  c3_b25 = c3_b24;
  c3_b26 = false;
  c3_b27 = (c3_b25 || c3_b26);
  if (c3_b27) {
    c3_i72 = 0;
    c3_i73 = 0;
  } else {
    c3_i72 = 0;
    if (c3_d6 != (real_T)(int32_T)muDoubleScalarFloor(c3_d6)) {
      emlrtIntegerCheckR2012b(c3_d6, &c3_g_emlrtDCI, &c3_st);
    }

    c3_i74 = (int32_T)c3_d6;
    if ((c3_i74 < 1) || (c3_i74 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c3_i74, 1, 20, &c3_l_emlrtBCI, &c3_st);
    }

    c3_i73 = c3_i74;
  }

  c3_filteredY = c3_filteredY_size[0];
  c3_unsorted_validY_size[0] = c3_closestIndices_size[0];
  c3_w_loop_ub = c3_closestIndices_size[0] - 1;
  for (c3_i75 = 0; c3_i75 <= c3_w_loop_ub; c3_i75++) {
    if (c3_closestIndices_data[c3_i75] != (real_T)(int32_T)muDoubleScalarFloor
        (c3_closestIndices_data[c3_i75])) {
      emlrtIntegerCheckR2012b(c3_closestIndices_data[c3_i75], &c3_db_emlrtDCI,
        &c3_st);
    }

    c3_i77 = (int32_T)c3_closestIndices_data[c3_i75];
    if ((c3_i77 < 1) || (c3_i77 > c3_filteredY)) {
      emlrtDynamicBoundsCheckR2012b(c3_i77, 1, c3_filteredY, &c3_eb_emlrtBCI,
        &c3_st);
    }

    c3_unsorted_validY_data[c3_i75] = chartInstance->c3_filteredY_data[c3_i77 -
      1];
  }

  c3_i76 = c3_i73 - c3_i72;
  if (c3_i76 != c3_unsorted_validY_size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_i76, c3_unsorted_validY_size[0],
      &c3_d_emlrtECI, &c3_st);
  }

  c3_i78 = c3_i72 + 1;
  c3_b_tmp_size[1] = (c3_i73 - c3_i78) + 1;
  c3_x_loop_ub = c3_i73 - c3_i78;
  for (c3_i79 = 0; c3_i79 <= c3_x_loop_ub; c3_i79++) {
    c3_b_tmp_data[c3_i79] = (c3_i78 + c3_i79) - 1;
  }

  c3_y_loop_ub = c3_b_tmp_size[1] - 1;
  for (c3_i80 = 0; c3_i80 <= c3_y_loop_ub; c3_i80++) {
    c3_b_pointsy[c3_b_tmp_data[c3_i80]] = c3_unsorted_validY_data[c3_i80];
  }

  for (c3_i81 = 0; c3_i81 < 20; c3_i81++) {
    c3_bv2[c3_i81] = (c3_b_pointsy[c3_i81] != 999.0);
  }

  c3_end = 20;
  c3_trueCount = 0;
  for (c3_d_i = 0; c3_d_i < c3_end; c3_d_i++) {
    if ((c3_b_pointsx[c3_d_i] != 999.0) && c3_bv2[c3_d_i]) {
      c3_trueCount++;
    }
  }

  c3_closestIndices_size[0] = c3_trueCount;
  c3_partialTrueCount = 0;
  for (c3_e_i = 0; c3_e_i < c3_end; c3_e_i++) {
    if ((c3_b_pointsx[c3_e_i] != 999.0) && c3_bv2[c3_e_i]) {
      c3_d7 = (real_T)c3_e_i;
      if (c3_d7 != (real_T)(int32_T)muDoubleScalarFloor(c3_d7)) {
        emlrtIntegerCheckR2012b(c3_d7, &c3_eb_emlrtDCI, &c3_st);
      }

      c3_i82 = (int32_T)muDoubleScalarFloor(c3_d7);
      if ((c3_i82 < 0) || (c3_i82 > 19)) {
        emlrtDynamicBoundsCheckR2012b(c3_i82, 0, 19, &c3_fb_emlrtBCI, &c3_st);
      }

      c3_closestIndices_data[c3_partialTrueCount] = c3_b_pointsx[c3_i82];
      c3_partialTrueCount++;
    }
  }

  c3_b_end = 20;
  c3_b_trueCount = 0;
  for (c3_f_i = 0; c3_f_i < c3_b_end; c3_f_i++) {
    if ((c3_b_pointsx[c3_f_i] != 999.0) && c3_bv2[c3_f_i]) {
      c3_b_trueCount++;
    }
  }

  c3_unsorted_validY_size[0] = c3_b_trueCount;
  c3_b_partialTrueCount = 0;
  for (c3_g_i = 0; c3_g_i < c3_b_end; c3_g_i++) {
    if ((c3_b_pointsx[c3_g_i] != 999.0) && c3_bv2[c3_g_i]) {
      c3_d8 = (real_T)c3_g_i;
      if (c3_d8 != (real_T)(int32_T)muDoubleScalarFloor(c3_d8)) {
        emlrtIntegerCheckR2012b(c3_d8, &c3_fb_emlrtDCI, &c3_st);
      }

      c3_i83 = (int32_T)muDoubleScalarFloor(c3_d8);
      if ((c3_i83 < 0) || (c3_i83 > 19)) {
        emlrtDynamicBoundsCheckR2012b(c3_i83, 0, 19, &c3_gb_emlrtBCI, &c3_st);
      }

      c3_unsorted_validY_data[c3_b_partialTrueCount] = c3_b_pointsy[c3_i83];
      c3_b_partialTrueCount++;
    }
  }

  c3_guard1 = false;
  if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 0,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 1U, (real_T)
                        c3_closestIndices_size[0], 3.0, -1, 5U, (real_T)
                        c3_closestIndices_size[0] >= 3.0))) {
    c3_isfinite(chartInstance, c3_closestIndices_data, c3_closestIndices_size,
                c3_c_tmp_data, c3_c_tmp_size);
    c3_b_st.site = &c3_lc_emlrtRSI;
    if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 1, c3_all
                         (chartInstance, &c3_b_st, c3_c_tmp_data, c3_c_tmp_size)))
    {
      covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 0, true);
      covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 3, true);
      c3_b_st.site = &c3_mc_emlrtRSI;
      c3_c_st.site = &c3_x_emlrtRSI;
      c3_d_sort(chartInstance, &c3_c_st, c3_closestIndices_data,
                c3_closestIndices_size, c3_c_iidx_data, c3_iidx_size);
      c3_sortIdx_size[0] = c3_iidx_size[0];
      c3_ab_loop_ub = c3_iidx_size[0] - 1;
      for (c3_i85 = 0; c3_i85 <= c3_ab_loop_ub; c3_i85++) {
        c3_sortIdx_data[c3_i85] = (real_T)c3_c_iidx_data[c3_i85];
      }

      c3_unsorted_validY = c3_unsorted_validY_size[0];
      c3_validY_size[0] = c3_sortIdx_size[0];
      c3_bb_loop_ub = c3_sortIdx_size[0] - 1;
      for (c3_i87 = 0; c3_i87 <= c3_bb_loop_ub; c3_i87++) {
        if (c3_sortIdx_data[c3_i87] != (real_T)(int32_T)muDoubleScalarFloor
            (c3_sortIdx_data[c3_i87])) {
          emlrtIntegerCheckR2012b(c3_sortIdx_data[c3_i87], &c3_gb_emlrtDCI,
            &c3_st);
        }

        c3_i89 = (int32_T)c3_sortIdx_data[c3_i87];
        if ((c3_i89 < 1) || (c3_i89 > c3_unsorted_validY)) {
          emlrtDynamicBoundsCheckR2012b(c3_i89, 1, c3_unsorted_validY,
            &c3_hb_emlrtBCI, &c3_st);
        }

        c3_validY_data[c3_i87] = c3_unsorted_validY_data[c3_i89 - 1];
      }

      if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 4,
                         !chartInstance->c3_hFig_not_empty)) {
        c3_b_st.site = &c3_oc_emlrtRSI;
        sf_mex_assign(&chartInstance->c3_hFig, c3_figure(chartInstance, &c3_b_st),
                      true);
        chartInstance->c3_hFig_not_empty = true;
        c3_b_st.site = &c3_oc_emlrtRSI;
        chartInstance->c3_hFig_not_empty = !c3_emlrt_marshallIn(chartInstance,
          c3_isempty(chartInstance, &c3_b_st, sf_mex_dup(chartInstance->c3_hFig)),
          "<output of isempty>");
        c3_b_st.site = &c3_pc_emlrtRSI;
        sf_mex_assign(&chartInstance->c3_hAx, c3_axes(chartInstance, &c3_b_st,
          c3_emlrt_marshallOut(chartInstance, c3_cv), sf_mex_dup
          (chartInstance->c3_hFig)), true);
        chartInstance->c3_hAx_not_empty = true;
        c3_b_st.site = &c3_pc_emlrtRSI;
        chartInstance->c3_hAx_not_empty = !c3_emlrt_marshallIn(chartInstance,
          c3_b_isempty(chartInstance, &c3_b_st, sf_mex_dup(chartInstance->c3_hAx)),
          "<output of isempty>");
      } else {
        c3_b_st.site = &c3_qc_emlrtRSI;
        c3_b_figure(chartInstance, &c3_b_st, sf_mex_dup(chartInstance->c3_hFig));
      }

      c3_b_st.site = &c3_sc_emlrtRSI;
      c3_scatter(chartInstance, &c3_b_st, c3_b_emlrt_marshallOut(chartInstance,
                  c3_closestIndices_data, c3_closestIndices_size),
                 c3_b_emlrt_marshallOut(chartInstance, c3_validY_data,
                  c3_validY_size));
      c3_b_st.site = &c3_rc_emlrtRSI;
      c3_axis(chartInstance, &c3_b_st, sf_mex_dup(chartInstance->c3_hAx),
              c3_c_emlrt_marshallOut(chartInstance, c3_dv1));
    } else {
      c3_guard1 = true;
    }
  } else {
    c3_guard1 = true;
  }

  if (c3_guard1) {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 0, false);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 3, false);
  }

  c3_d9 = (real_T)c3_filteredX_size[0];
  c3_i84 = (int32_T)c3_d9;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c3_d9, mxDOUBLE_CLASS, c3_i84,
    &c3_bc_emlrtRTEI, &c3_st);
  for (c3_b_k = 0; c3_b_k < c3_i84; c3_b_k++) {
    c3_c_k = 1.0 + (real_T)c3_b_k;
    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 2, 1);
    for (c3_dx = 0; c3_dx < 9; c3_dx++) {
      c3_b_dx = -4.0 + (real_T)c3_dx;
      covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 3, 1);
      for (c3_dy = 0; c3_dy < 9; c3_dy++) {
        c3_b_dy = -4.0 + (real_T)c3_dy;
        covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 4, 1);
        c3_b_st.site = &c3_nc_emlrtRSI;
        c3_b_a = c3_b_dx;
        c3_c_a = c3_b_a;
        c3_d_a = c3_c_a;
        c3_e_a = c3_d_a;
        c3_f_a = c3_e_a;
        c3_c = c3_f_a * c3_f_a;
        c3_b_st.site = &c3_nc_emlrtRSI;
        c3_g_a = c3_b_dy;
        c3_h_a = c3_g_a;
        c3_i_a = c3_h_a;
        c3_j_a = c3_i_a;
        c3_k_a = c3_j_a;
        c3_b_c = c3_k_a * c3_k_a;
        c3_d10 = c3_c + c3_b_c;
        c3_b_st.site = &c3_nc_emlrtRSI;
        if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 5,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 2U, c3_d10,
                            16.0, -1, 3U, c3_d10 <= 16.0))) {
          if (c3_c_k != (real_T)(int32_T)muDoubleScalarFloor(c3_c_k)) {
            emlrtIntegerCheckR2012b(c3_c_k, &c3_hb_emlrtDCI, &c3_st);
          }

          c3_i94 = (int32_T)c3_c_k;
          if ((c3_i94 < 1) || (c3_i94 > c3_filteredX_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i94, 1, c3_filteredX_size[0],
              &c3_ib_emlrtBCI, &c3_st);
          }

          c3_x = (chartInstance->c3_filteredX_data[c3_i94 - 1] + c3_b_dx) + 80.0;
          if (c3_c_k != (real_T)(int32_T)muDoubleScalarFloor(c3_c_k)) {
            emlrtIntegerCheckR2012b(c3_c_k, &c3_ib_emlrtDCI, &c3_st);
          }

          c3_i95 = (int32_T)c3_c_k;
          if ((c3_i95 < 1) || (c3_i95 > c3_filteredY_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c3_i95, 1, c3_filteredY_size[0],
              &c3_jb_emlrtBCI, &c3_st);
          }

          c3_g_y = (chartInstance->c3_filteredY_data[c3_i95 - 1] + c3_b_dy) +
            60.0;
          if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 2,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c3_covrtInstance, 4U, 0U, 3U,
                                c3_x, 0.0, -1, 4U, c3_x > 0.0)) &&
              covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 3,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c3_covrtInstance, 4U, 0U, 4U,
                                c3_x, 160.0, -1, 3U, c3_x <= 160.0)) &&
              covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 4,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c3_covrtInstance, 4U, 0U, 5U,
                                c3_g_y, 0.0, -1, 4U, c3_g_y > 0.0)) &&
              covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 5,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c3_covrtInstance, 4U, 0U, 6U,
                                c3_g_y, 120.0, -1, 3U, c3_g_y <= 120.0))) {
            covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 1, true);
            covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 6, true);
            if (c3_g_y != (real_T)(int32_T)muDoubleScalarFloor(c3_g_y)) {
              emlrtIntegerCheckR2012b(c3_g_y, &c3_h_emlrtDCI, &c3_st);
            }

            c3_i96 = (int32_T)c3_g_y;
            if ((c3_i96 < 1) || (c3_i96 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c3_i96, 1, 120, &c3_m_emlrtBCI,
                &c3_st);
            }

            if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
              emlrtIntegerCheckR2012b(c3_x, &c3_i_emlrtDCI, &c3_st);
            }

            c3_i97 = (int32_T)c3_x;
            if ((c3_i97 < 1) || (c3_i97 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c3_i97, 1, 160, &c3_n_emlrtBCI,
                &c3_st);
            }

            chartInstance->c3_outt[(c3_i96 + 120 * (c3_i97 - 1)) - 1] = 0U;
            c3_b_x = 255.0 * c3_c_k / (real_T)c3_filteredX_size[0];
            c3_c_x = c3_b_x;
            c3_h_y = c3_c_x;
            c3_h_y = muDoubleScalarFloor(c3_h_y);
            if (c3_g_y != (real_T)(int32_T)muDoubleScalarFloor(c3_g_y)) {
              emlrtIntegerCheckR2012b(c3_g_y, &c3_j_emlrtDCI, &c3_st);
            }

            c3_i98 = (int32_T)c3_g_y;
            if ((c3_i98 < 1) || (c3_i98 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c3_i98, 1, 120, &c3_o_emlrtBCI,
                &c3_st);
            }

            if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
              emlrtIntegerCheckR2012b(c3_x, &c3_k_emlrtDCI, &c3_st);
            }

            c3_i99 = (int32_T)c3_x;
            if ((c3_i99 < 1) || (c3_i99 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c3_i99, 1, 160, &c3_p_emlrtBCI,
                &c3_st);
            }

            c3_d11 = muDoubleScalarRound(c3_h_y);
            c3_b_covSaturation = false;
            if (c3_d11 < 256.0) {
              if (c3_d11 >= 0.0) {
                c3_u1 = (uint8_T)c3_d11;
              } else {
                c3_b_covSaturation = true;
                c3_u1 = 0U;
                sf_data_saturate_error(chartInstance->S, 1U, 3785, 46);
              }
            } else if (c3_d11 >= 256.0) {
              c3_b_covSaturation = true;
              c3_u1 = MAX_uint8_T;
              sf_data_saturate_error(chartInstance->S, 1U, 3785, 46);
            } else {
              c3_u1 = 0U;
            }

            covrtSaturationUpdateFcn(chartInstance->c3_covrtInstance, 4, 0, 0, 0,
              c3_b_covSaturation);
            chartInstance->c3_outt[(c3_i98 + 120 * (c3_i99 - 1)) + 19199] =
              c3_u1;
            if (c3_g_y != (real_T)(int32_T)muDoubleScalarFloor(c3_g_y)) {
              emlrtIntegerCheckR2012b(c3_g_y, &c3_l_emlrtDCI, &c3_st);
            }

            c3_i100 = (int32_T)c3_g_y;
            if ((c3_i100 < 1) || (c3_i100 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c3_i100, 1, 120, &c3_q_emlrtBCI,
                &c3_st);
            }

            if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
              emlrtIntegerCheckR2012b(c3_x, &c3_m_emlrtDCI, &c3_st);
            }

            c3_i101 = (int32_T)c3_x;
            if ((c3_i101 < 1) || (c3_i101 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c3_i101, 1, 160, &c3_r_emlrtBCI,
                &c3_st);
            }

            chartInstance->c3_outt[(c3_i100 + 120 * (c3_i101 - 1)) + 38399] = 0U;
          } else {
            covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 1, false);
            covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 6, false);
          }
        }

        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 4, 0);
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 3, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 2, 0);
  if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 7,
                     covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance,
        4U, 0U, 7U, chartInstance->c3_call_count, 75.0, -1, 2U,
        chartInstance->c3_call_count < 75.0))) {
    c3_b_distX = -10.0;
    c3_b_distY = 10.0;
  } else if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 6,
              covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance, 4U, 0U,
    8U, chartInstance->c3_call_count, 60.0, -1, 5U, chartInstance->c3_call_count
    >= 60.0)) && covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 7,
              covrtRelationalopUpdateFcn(chartInstance->c3_covrtInstance, 4U, 0U,
    9U, chartInstance->c3_call_count, 120.0, -1, 2U,
               chartInstance->c3_call_count < 120.0))) {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 2, true);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 8, true);
    c3_b_distX = 0.0;
    c3_b_distY = 30.0;
  } else {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 2, false);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 8, false);
    c3_b_distX = 0.0;
    c3_b_distY = 0.0;
  }

  chartInstance->c3_call_count++;
  for (c3_i86 = 0; c3_i86 < 57600; c3_i86++) {
    (*chartInstance->c3_b_outt)[c3_i86] = chartInstance->c3_outt[c3_i86];
  }

  *chartInstance->c3_distX = c3_b_distX;
  *chartInstance->c3_distY = c3_b_distY;
  for (c3_i88 = 0; c3_i88 < 20; c3_i88++) {
    (*chartInstance->c3_pointsx)[c3_i88] = c3_b_pointsx[c3_i88];
  }

  for (c3_i90 = 0; c3_i90 < 20; c3_i90++) {
    (*chartInstance->c3_pointsy)[c3_i90] = c3_b_pointsy[c3_i90];
  }

  c3_do_animation_call_c3_flightControlSystem(chartInstance);
  for (c3_i91 = 0; c3_i91 < 57600; c3_i91++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 1U, (real_T)
                      (*chartInstance->c3_b_outt)[c3_i91]);
  }

  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 2U,
                    *chartInstance->c3_distX);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 3U,
                    *chartInstance->c3_distY);
  for (c3_i92 = 0; c3_i92 < 20; c3_i92++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 4U,
                      (*chartInstance->c3_pointsx)[c3_i92]);
  }

  for (c3_i93 = 0; c3_i93 < 20; c3_i93++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 5U,
                      (*chartInstance->c3_pointsy)[c3_i93]);
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
  const mxArray *c3_b_u;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_u;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_i_y = NULL;
  const mxArray *c3_j_y = NULL;
  const mxArray *c3_k_y = NULL;
  const mxArray *c3_st;
  c3_st = NULL;
  c3_st = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createcellmatrix(9, 1), false);
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
  c3_b_u = chartInstance->c3_hAx;
  c3_i_y = NULL;
  if (!chartInstance->c3_hAx_not_empty) {
    sf_mex_assign(&c3_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_i_y, sf_mex_duplicatearraysafe(&c3_b_u), false);
  }

  sf_mex_setcell(c3_b_y, 6, c3_i_y);
  c3_c_u = chartInstance->c3_hFig;
  c3_j_y = NULL;
  if (!chartInstance->c3_hAx_not_empty) {
    sf_mex_assign(&c3_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_j_y, sf_mex_duplicatearraysafe(&c3_c_u), false);
  }

  sf_mex_setcell(c3_b_y, 7, c3_j_y);
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y",
    &chartInstance->c3_is_active_c3_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_b_y, 8, c3_k_y);
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
  uint8_T c3_uv[57600];
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_b_u = sf_mex_dup(c3_st);
  *chartInstance->c3_distX = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_b_u, 0)), "distX");
  *chartInstance->c3_distY = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_b_u, 1)), "distY");
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 2)),
                        "outt", c3_uv);
  for (c3_i = 0; c3_i < 57600; c3_i++) {
    (*chartInstance->c3_b_outt)[c3_i] = c3_uv[c3_i];
  }

  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 3)),
                        "pointsx", c3_dv);
  for (c3_i1 = 0; c3_i1 < 20; c3_i1++) {
    (*chartInstance->c3_pointsx)[c3_i1] = c3_dv[c3_i1];
  }

  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 4)),
                        "pointsy", c3_dv1);
  for (c3_i2 = 0; c3_i2 < 20; c3_i2++) {
    (*chartInstance->c3_pointsy)[c3_i2] = c3_dv1[c3_i2];
  }

  chartInstance->c3_call_count = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_b_u, 5)), "call_count",
    &chartInstance->c3_call_count_not_empty);
  sf_mex_assign(&chartInstance->c3_hAx, c3_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_b_u, 6)), &chartInstance->c3_hAx_not_empty),
                true);
  sf_mex_assign(&chartInstance->c3_hFig, c3_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_b_u, 7)), &chartInstance->c3_hFig_not_empty),
                true);
  chartInstance->c3_is_active_c3_flightControlSystem = c3_m_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 8)),
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

const mxArray *sf_c3_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static boolean_T c3_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_a__output_of_isempty_, const char_T
  *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_b_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_a__output_of_isempty_), &c3_thisId);
  sf_mex_destroy(&c3_a__output_of_isempty_);
  return c3_b_y;
}

static boolean_T c3_b_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_b;
  boolean_T c3_b_y;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_b, 1, 11, 0U, 0, 0U, 0);
  c3_b_y = c3_b;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static const mxArray *c3_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u[6])
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 6),
                false);
  return c3_b_y;
}

static const mxArray *c3_b_emlrt_marshallOut
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

static const mxArray *c3_c_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const real_T c3_b_u[4])
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  return c3_b_y;
}

static real_T c3_c_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_distX, const char_T *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_distX),
    &c3_thisId);
  sf_mex_destroy(&c3_b_distX);
  return c3_b_y;
}

static real_T c3_d_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
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

static void c3_e_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_c_outt, const char_T *c3_identifier, uint8_T
  c3_b_y[57600])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_c_outt), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_c_outt);
}

static void c3_f_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
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

static void c3_g_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_pointsx, const char_T *c3_identifier,
  real_T c3_b_y[20])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_pointsx), &c3_thisId,
                        c3_b_y);
  sf_mex_destroy(&c3_b_pointsx);
}

static void c3_h_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
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

static real_T c3_i_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_call_count, const char_T *c3_identifier,
  boolean_T *c3_svPtr)
{
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_call_count),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_call_count);
  return c3_b_y;
}

static real_T c3_j_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
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

static const mxArray *c3_k_emlrt_marshallIn
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const mxArray
   *c3_b_hAx, boolean_T *c3_svPtr)
{
  const mxArray *c3_b_y = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_hAx), c3_svPtr), true);
  sf_mex_destroy(&c3_b_hAx);
  return c3_b_y;
}

static const mxArray *c3_l_emlrt_marshallIn
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const mxArray *c3_b_u,
   boolean_T *c3_svPtr)
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  if (mxIsEmpty(c3_b_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_assign(&c3_b_y, sf_mex_duplicatearraysafe(&c3_b_u), true);
  }

  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static uint8_T c3_m_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_flightControlSystem, const
  char_T *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_b_y;
  c3_thisId.fIdentifier = (const char_T *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_flightControlSystem), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_flightControlSystem);
  return c3_b_y;
}

static uint8_T c3_n_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
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

static const mxArray *c3_figure(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp)
{
  const mxArray *c3_m = NULL;
  (void)chartInstance;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "figure", 1U, 0U), false);
  return c3_m;
}

static const mxArray *c3_isempty(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0)
{
  const mxArray *c3_m = NULL;
  (void)chartInstance;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "isempty", 1U, 1U, 14,
    sf_mex_dup(c3_input0)), false);
  sf_mex_destroy(&c3_input0);
  return c3_m;
}

static const mxArray *c3_axes(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1)
{
  const mxArray *c3_m = NULL;
  (void)chartInstance;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "axes", 1U, 2U, 14, sf_mex_dup
    (c3_input0), 14, sf_mex_dup(c3_input1)), false);
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
  return c3_m;
}

static const mxArray *c3_b_isempty(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0)
{
  const mxArray *c3_m = NULL;
  (void)chartInstance;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "isempty", 1U, 1U, 14,
    sf_mex_dup(c3_input0)), false);
  sf_mex_destroy(&c3_input0);
  return c3_m;
}

static void c3_b_figure(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, const mxArray *c3_input0)
{
  (void)chartInstance;
  sf_mex_call(c3_sp, NULL, "figure", 0U, 1U, 14, sf_mex_dup(c3_input0));
  sf_mex_destroy(&c3_input0);
}

static void c3_axis(SFc3_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray
                    *c3_input1)
{
  (void)chartInstance;
  sf_mex_call(c3_sp, NULL, "axis", 0U, 2U, 14, sf_mex_dup(c3_input0), 14,
              sf_mex_dup(c3_input1));
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
}

static const mxArray *c3_scatter(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1)
{
  const mxArray *c3_m = NULL;
  (void)chartInstance;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "scatter", 0U, 2U, 14,
    sf_mex_dup(c3_input0), 14, sf_mex_dup(c3_input1)), false);
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
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
  int32_T c3_c_b;
  int32_T c3_c_k;
  int32_T c3_c_loop_ub;
  int32_T c3_c_n;
  int32_T c3_d_b;
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
  int32_T c3_i8;
  int32_T c3_ib;
  int32_T c3_k;
  int32_T c3_loop_ub;
  int32_T c3_n;
  int32_T c3_nBlocks;
  int32_T c3_nLastBlock;
  int32_T c3_preSortLevel;
  int32_T c3_quartetOffset;
  int32_T c3_tailOffset;
  boolean_T c3_b_overflow;
  boolean_T c3_c_overflow;
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
    c3_b_st.site = &c3_lb_emlrtRSI;
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

    c3_ib = 0;
    c3_c_st.site = &c3_ob_emlrtRSI;
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
      c3_ib++;
      c3_idx4[c3_ib - 1] = c3_b_k + 1;
      c3_x4[c3_ib - 1] = c3_c_x_data[c3_b_k];
      if (c3_ib == 4) {
        c3_quartetOffset = c3_b_k;
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
      c3_c_b = c3_ib;
      c3_e_b = c3_c_b;
      if (c3_e_b < 1) {
        c3_b_overflow = false;
      } else {
        c3_b_overflow = (c3_e_b > 2147483646);
      }

      if (c3_b_overflow) {
        c3_d_st.site = &c3_u_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_d_st);
      }

      c3_i7 = (uint8_T)c3_ib - 1;
      for (c3_c_k = 0; c3_c_k <= c3_i7; c3_c_k++) {
        c3_b_k = c3_c_k;
        c3_idx_data[(c3_b_n - c3_ib) + c3_b_k] = c3_idx4[c3_perm[c3_b_k] - 1];
        c3_c_x_data[(c3_b_n - c3_ib) + c3_b_k] = c3_x4[c3_perm[c3_b_k] - 1];
      }
    }

    c3_c_st.site = &c3_mb_emlrtRSI;
    c3_preSortLevel = 2;
    if (c3_n > 1) {
      if (c3_n >= 256) {
        c3_nBlocks = c3_n >> 8;
        if (c3_nBlocks > 0) {
          c3_b_st.site = &c3_kb_emlrtRSI;
          c3_d_b = c3_nBlocks;
          c3_f_b = c3_d_b;
          if (c3_f_b < 1) {
            c3_c_overflow = false;
          } else {
            c3_c_overflow = (c3_f_b > 2147483646);
          }

          if (c3_c_overflow) {
            c3_c_st.site = &c3_u_emlrtRSI;
            c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
          }

          c3_i8 = (uint8_T)c3_nBlocks - 1;
          for (c3_g_b = 0; c3_g_b <= c3_i8; c3_g_b++) {
            c3_h_b = c3_g_b;
            c3_b_st.site = &c3_jb_emlrtRSI;
            c3_b_merge_pow2_block(chartInstance, &c3_b_st, c3_idx_data,
                                  c3_c_x_data, c3_h_b << 8);
          }

          c3_tailOffset = c3_nBlocks << 8;
          c3_nLastBlock = c3_n - c3_tailOffset;
          if (c3_nLastBlock > 0) {
            c3_b_st.site = &c3_ib_emlrtRSI;
            c3_b_merge_block(chartInstance, &c3_b_st, c3_idx_data, c3_c_x_data,
                             c3_tailOffset, c3_nLastBlock, 2,
                             chartInstance->c3_iwork_data,
                             chartInstance->c3_xwork_data);
          }

          c3_preSortLevel = 8;
        }
      }

      c3_b_st.site = &c3_hb_emlrtRSI;
      c3_b_merge_block(chartInstance, &c3_b_st, c3_idx_data, c3_c_x_data, 0,
                       c3_n, c3_preSortLevel, chartInstance->c3_iwork_data,
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
  int32_T c3_i;
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

    c3_i = (uint16_T)c3_nPairs - 1;
    for (c3_k = 0; c3_k <= c3_i; c3_k++) {
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
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2874281358U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3502618667U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(742364018U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1085781529U);
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
    "eNpjYPT0ZQACPiC+wcnAwAakOYCYiQECWKF8RiDmhNIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Cs4oOtnwaKfFUm/AJSfkllcEgENH1g4DZw/lC"
    "jyR+Sg8YcI2B8GBPzBguIPFob80pKSweF+FaLigR0tHkD8gvzMvJLiikESD2oU+qOSSv4QcKBMP"
    "8R+BwL+4ELzB4ifnJiTE5+cX5pXgjDnAgP+cpARrRxkgvJBenIYMhkKsLgHm3+Y0PwjAPdNoAOY"
    "agimSrgMlvghlN+ZUeKHmSHDsWKQxEc0JD4ORI+o+EAvfzPcMtMHRXwcCIPGR/ggiQ8FqrgjgEB"
    "8KKCVXyB+ZnF8YnJJZllqfLJxfFpOZnpGiXN+XklRfk5wZXFJai7MfwByJVFA"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sWeVdZqvsYIavMLVYl7L9FE";
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
  const char* encStrCodegen [25] = {
    "eNrtWc9u40QYn3TbQgtUPSC4IFEQQkjAaqU9sEgI2qYJREppwWlLdw9lan+JRx3PuDPjNEEcOO6",
    "RJ+ABkHgDDvsInNBK3LmtxJEj39hONuuGxpMUNmix5NgT+zff/z8zJpXGLsFjDc9f3iBkGa/P47",
    "lAsmMpH1dGzuz/RfJRPv72BUJ8GUAHhJe026xH3A6RRPtU0UgT90PQCL4ELXlimBQN0ZblsUy0Q",
    "YHwcYJYKuNEV7Mo4Uyc1RPhW8r6KGR+6IUy4cE2TkiDPcH7f0c3Tsw+UtxhCnxTBwhMqGTSCeuc",
    "dq7WgjIX1RD8M51EzrrSYLwktqLq3YQbFnOo9cBvCG0oakFPkNcz1EDV9NyUbOXV3gAto5gzKsr",
    "rOqTagxi9w8BBHODvXmJQe6WwfkiV2YaQdkE32VlKXQooRZ1pfPuUCWqkYpTXIl61s5WUd5+jjL",
    "sYEtzVRijvtgJ6FksmjGNAeHXUc03QUw47cJp0HOl6cJ7YaDhkcAHKzb7tquyCoh3YE248pzaq9",
    "VKnHMZSSaxhERxSteWj72oI3PIGBp32KLojtHAaJyykKm7olmJd9A3XXNew4T9VrkuizPv1VNiU",
    "bq0Lzn41pFv3RZVyrt2wLRk3oQs8pb9DDZ0Cm9F3AGvNgpZE77DZxjFjJYJhJOTYqhQBK++V3QI",
    "qLWyfY5EqAWeRDQMIUM1D1ocTTYqjRBsZVTHl7DSbJeldxjaEAdWmPpSuMYoyDchw6leOdAOmbS",
    "AhGrVkUilLz5DF4FRQotuJ2LmQ6gx17FrMHuvKRoIbGoIOJmYDaZKroXcfUp6U5DnSHYwfdI8Dj",
    "VnWjS5ibfxMBfapH0JgKyfjsIt5Ficoa2JtS/4WSttlpr8D2lcsLhtJCSZ0LLpWS61+DAfiTMgL",
    "UVcy8vLO6wq/AsCsQZVgorONJVz168h8Oa4VnLfS7O7a5Fg9U8PpqfWNT0FgNbSy2q6B+hhVNYE",
    "tMjI0C9Zj32ATIzTTBgt1Pyv1Wd2z/ftn5HH/vjimf39lpH9fz8f+7ZM2Z53QJhqjJPf6OHeUzX",
    "drZL4XS6wHBnxchSOXcGSIG1zfGcFXxtAlI9civZWFq/lcwLtKjtscwb1UoLNYwC3nOvvp3fs3f",
    "3706w/yN3Hx4/Hvj2ahf3/Vbb21lo9fG/RNwyzdvZTIyvjDqwV/sGN9BIfB3fOuPm7Q7m7z8Jh/",
    "0PywXkvne7hyNb8rBX4H/2/YXg2DOM0Jym8E+brNjmmSrSfs/HdG+F2eoI+VEX8i5I9PZsNvbBb",
    "x4/S1VNDXUlbDzFcF/316crw5kxzHcyPHy5vFuBonx+ITciwSmRgzH/y/VcoOzxXsYMfZuq83J3",
    "Z4e0Y5+tckx/rmbPjL+X6cHKsFOVbT/ofzE18mg02DdJ+MuOXthXxsMZwwEo/hZ5w8CwV51ofSf",
    "LGZXr7zrkUv82KfSfF+4wn73CDhVm9O7HEvs8eDe8+UPYr5N6yzzlzY48Fhbo+jObHHxrXwsT/B",
    "HhuF/LWR7s2dULsCg5Pxnf7aNfTRrjjyP24ucJVnUL4y69hpcUvkn1s3XyduVvlc1+f/9fevqoO",
    "k8P76HMtRvE67TzNvcj107Ddez8cfD78TVEPGgzE7lfnjJtD2uKf/knzfT3i/Unj/6wl9wnsFf7",
    "Vj+/1e3WR2/19Qnt3EklMD+f0umFAG2m7ITivHn452GuxP1ayd8g/Xd29vIX99zbLt3MHf+8p+f",
    "xw+UkD1+H3mp1G3xvWPZfdlDlr19+/MUP/+AleyZdk=",
    ""
  };

  static char newstr [1769] = "";
  newstr[0] = '\0';
  for (i = 0; i < 25; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c3_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c3_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(780676013U));
  ssSetChecksum1(S,(2664885692U));
  ssSetChecksum2(S,(2003753839U));
  ssSetChecksum3(S,(3991296426U));
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
