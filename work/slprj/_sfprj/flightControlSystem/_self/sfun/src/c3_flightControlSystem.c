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

static emlrtMCInfo c3_f_emlrtMCI = { 28,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c3_g_emlrtMCI = { 134,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c3_h_emlrtMCI = { 85,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c3_i_emlrtMCI = { 158,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
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

static emlrtRSInfo c3_s_emlrtRSI = { 13,/* lineNo */
  "all",                               /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/all.m"/* pathName */
};

static emlrtRSInfo c3_t_emlrtRSI = { 17,/* lineNo */
  "min",                               /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

static emlrtRSInfo c3_u_emlrtRSI = { 40,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c3_v_emlrtRSI = { 90,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c3_w_emlrtRSI = { 13,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c3_x_emlrtRSI = { 17,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c3_y_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/matfun/mpower.m"/* pathName */
};

static emlrtRSInfo c3_ab_emlrtRSI = { 11,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_bb_emlrtRSI = { 14,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_cb_emlrtRSI = { 19,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_db_emlrtRSI = { 29,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_eb_emlrtRSI = { 42,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_fb_emlrtRSI = { 43,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_gb_emlrtRSI = { 52,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_hb_emlrtRSI = { 53,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_ib_emlrtRSI = { 80,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_jb_emlrtRSI = { 83,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_kb_emlrtRSI = { 93,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_lb_emlrtRSI = { 94,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_mb_emlrtRSI = { 110,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_nb_emlrtRSI = { 144,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_ob_emlrtRSI = { 121,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_pb_emlrtRSI = { 123,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_qb_emlrtRSI = { 126,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_rb_emlrtRSI = { 130,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_sb_emlrtRSI = { 134,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
  "#flightControlSystem:2699"          /* pathName */
};

static emlrtRSInfo c3_tb_emlrtRSI = { 129,/* lineNo */
  "Image Processing System/tugay_deneme",/* fcnName */
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
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_d_emlrtRTEI = { 33,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_e_emlrtRTEI = { 52,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_f_emlrtRTEI = { 52,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_g_emlrtRTEI = { 42,/* lineNo */
  30,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_h_emlrtRTEI = { 53,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_i_emlrtRTEI = { 42,/* lineNo */
  66,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_j_emlrtRTEI = { 53,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_k_emlrtRTEI = { 43,/* lineNo */
  16,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_l_emlrtRTEI = { 80,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_m_emlrtRTEI = { 80,/* lineNo */
  70,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_n_emlrtRTEI = { 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_o_emlrtRTEI = { 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_p_emlrtRTEI = { 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_q_emlrtRTEI = { 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_r_emlrtRTEI = { 71,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo c3_s_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "sqrt",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRTEInfo c3_t_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c3_u_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "isinf",                             /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/isinf.m"/* pName */
};

static emlrtRTEInfo c3_v_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "isnan",                             /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/isnan.m"/* pName */
};

static emlrtRTEInfo c3_w_emlrtRTEI = { 12,/* lineNo */
  37,                                  /* colNo */
  "sqrt",                              /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRTEInfo c3_x_emlrtRTEI = { 13,/* lineNo */
  21,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c3_y_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c3_ab_emlrtRTEI = { 42,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_bb_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtRTEInfo c3_cb_emlrtRTEI = { 36,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtBCInfo c3_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  40,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_emlrtDCI = { 42, /* lineNo */
  42,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  42,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  76,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_b_emlrtDCI = { 42,/* lineNo */
  78,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  78,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c3_emlrtECI = { 1,  /* nDims */
  42,                                  /* lineNo */
  29,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtBCInfo c3_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_c_emlrtDCI = { 52,/* lineNo */
  25,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  25,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c3_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_d_emlrtDCI = { 53,/* lineNo */
  25,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  25,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c3_b_emlrtECI = { 1,/* nDims */
  80,                                  /* lineNo */
  22,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699"          /* pName */
};

static emlrtDCInfo c3_e_emlrtDCI = { 148,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_i_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  148,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_f_emlrtDCI = { 148,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_j_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  148,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_g_emlrtDCI = { 149,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_k_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  149,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_h_emlrtDCI = { 149,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_l_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  149,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_i_emlrtDCI = { 150,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_m_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  150,                                 /* lineNo */
  26,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_j_emlrtDCI = { 150,/* lineNo */
  29,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_n_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  150,                                 /* lineNo */
  29,                                  /* colNo */
  "outt",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c3_o_emlrtBCI = { 0,/* iFirst */
  19,                                  /* iLast */
  108,                                 /* lineNo */
  27,                                  /* colNo */
  "pointsy",                           /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_k_emlrtDCI = { 108,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c3_l_emlrtDCI = { 32,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c3_m_emlrtDCI = { 32,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c3_n_emlrtDCI = { 33,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c3_o_emlrtDCI = { 33,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  33,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_p_emlrtDCI = { 39,/* lineNo */
  33,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  19,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_q_emlrtDCI = { 39,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  33,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_r_emlrtDCI = { 40,/* lineNo */
  33,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  19,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_s_emlrtDCI = { 40,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  56,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_t_emlrtDCI = { 42,/* lineNo */
  56,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  92,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_u_emlrtDCI = { 42,/* lineNo */
  92,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_v_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  80,                                  /* lineNo */
  37,                                  /* colNo */
  "sortedPointsX",                     /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_v_emlrtDCI = { 80,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  37,                                  /* colNo */
  "xIdx",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_w_emlrtDCI = { 45,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_x_emlrtDCI = { 45,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  37,                                  /* colNo */
  "yIdx",                              /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_y_emlrtDCI = { 46,/* lineNo */
  37,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  23,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_ab_emlrtDCI = { 46,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_bb_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  80,                                  /* lineNo */
  84,                                  /* colNo */
  "sortedPointsY",                     /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_bb_emlrtDCI = { 80,/* lineNo */
  84,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_cb_emlrtBCI = { 0,/* iFirst */
  19,                                  /* iLast */
  107,                                 /* lineNo */
  27,                                  /* colNo */
  "pointsx",                           /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_cb_emlrtDCI = { 107,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  45,                                  /* colNo */
  "filteredX",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_db_emlrtDCI = { 89,/* lineNo */
  45,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_eb_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  89,                                  /* lineNo */
  19,                                  /* colNo */
  "sortedPointsX",                     /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_eb_emlrtDCI = { 89,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  45,                                  /* colNo */
  "filteredY",                         /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_fb_emlrtDCI = { 90,/* lineNo */
  45,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_gb_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  90,                                  /* lineNo */
  19,                                  /* colNo */
  "sortedPointsY",                     /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c3_gb_emlrtDCI = { 90,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_hb_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  134,                                 /* lineNo */
  22,                                  /* colNo */
  "pointsx",                           /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_hb_emlrtDCI = { 134,/* lineNo */
  22,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_ib_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  134,                                 /* lineNo */
  34,                                  /* colNo */
  "pointsy",                           /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_ib_emlrtDCI = { 134,/* lineNo */
  34,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_jb_emlrtBCI = { 1,/* iFirst */
  31,                                  /* iLast */
  134,                                 /* lineNo */
  45,                                  /* colNo */
  "labels",                            /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_jb_emlrtDCI = { 134,/* lineNo */
  45,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_kb_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  145,                                 /* lineNo */
  35,                                  /* colNo */
  "sortedPointsX",                     /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_kb_emlrtDCI = { 145,/* lineNo */
  35,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_lb_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  146,                                 /* lineNo */
  35,                                  /* colNo */
  "sortedPointsY",                     /* aName */
  "Image Processing System/tugay_deneme",/* fName */
  "#flightControlSystem:2699",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_lb_emlrtDCI = { 146,/* lineNo */
  35,                                  /* colNo */
  "Image Processing System/tugay_deneme",/* fName */
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
                    emlrtStack *c3_sp, real_T c3_b_x_data[], int32_T c3_x_size[1],
                    real_T c3_c_x_data[], int32_T c3_b_x_size[1]);
static boolean_T c3_all(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, boolean_T c3_b_x_data[], int32_T c3_x_size[1]);
static void c3_minimum(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_b_x_data[], int32_T c3_x_size[1], real_T
  *c3_ex, int32_T *c3_idx);
static void c3_nullAssignment(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_b_x_data[], int32_T
  c3_x_size[1], int32_T c3_idx, real_T c3_c_x_data[], int32_T c3_b_x_size[1]);
static void c3_isfinite(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_b_x_data[], int32_T c3_x_size[1], boolean_T c3_b_data[], int32_T
  c3_b_size[1]);
static boolean_T c3_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_a__output_of_isempty_, const char_T
  *c3_identifier);
static boolean_T c3_b_emlrt_marshallIn(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *c3_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u[6]);
static const mxArray *c3_b_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const real_T c3_b_u[20]);
static const mxArray *c3_c_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const real_T c3_b_u[4]);
static const mxArray *c3_d_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const real_T c3_b_u);
static const mxArray *c3_e_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u);
static const mxArray *c3_f_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u[19]);
static const mxArray *c3_g_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u[4]);
static const mxArray *c3_h_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u[17]);
static const mxArray *c3_i_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u[3]);
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
static void c3_text(SFc3_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray
                    *c3_input1, const mxArray *c3_input2, const mxArray
                    *c3_input3, const mxArray *c3_input4, const mxArray
                    *c3_input5, const mxArray *c3_input6);
static const mxArray *c3_scatter(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1);
static void c3_b_sqrt(SFc3_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c3_sp, real_T c3_b_x_data[], int32_T
                      c3_x_size[1]);
static void c3_b_nullAssignment(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_b_x_data[], int32_T
  c3_x_size[1], int32_T c3_idx);
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

  static const int32_T c3_b_condTxtEndIdx[4] = { 4648, 4670, 4679, 4701 };

  static const int32_T c3_b_condTxtStartIdx[4] = { 4643, 4652, 4674, 4683 };

  static const int32_T c3_c_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c3_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c3_c_condTxtEndIdx[2] = { 5039, 5057 };

  static const int32_T c3_c_condTxtStartIdx[2] = { 5023, 5043 };

  static const int32_T c3_condTxtEndIdx[2] = { 3350, 3384 };

  static const int32_T c3_condTxtStartIdx[2] = { 3322, 3354 };

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
    29U);
  covrtChartInitFcn(chartInstance->c3_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c3_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c3_decisionTxtStartIdx, &c3_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c3_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c3_covrtInstance, "", 4U, 0U, 1U, 0U, 9U, 0U,
                  2U, 0U, 6U, 1U, 8U, 3U);
  covrtEmlFcnInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 5155);
  covrtEmlSaturationInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 4779,
    -1, 4829);
  covrtEmlSaturationInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 721, -1,
    779);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 114, 136, -1,
                    160, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 965, 978, 1082,
                    1351, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 1195, 1220, -1,
                    1343, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 3319, 3384, -1,
                    4310, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 3677, 3693,
                    3875, 3969, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 4461, 4487, -1,
                    4942, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 6U, 4640, 4701, -1,
                    4926, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 7U, 4968, 4986,
                    5016, 5120, false);
  covrtEmlIfInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 8U, 5016, 5057,
                    5086, 5120, false);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 475, 511, 561);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 938, 960, 1355);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 4164, 4189,
                     4305);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 4357, 4388,
                     4966);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 4393, 4416,
                     4962);
  covrtEmlForInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 4425, 4448,
                     4954);
  covrtEmlWhileInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 2125, 2171,
                       2820);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 3322, 3384,
                      2U, 0U, c3_condTxtStartIdx, c3_condTxtEndIdx, 3U,
                      c3_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 4643, 4701,
                      4U, 2U, c3_b_condTxtStartIdx, c3_b_condTxtEndIdx, 7U,
                      c3_b_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 5023, 5057,
                      2U, 6U, c3_c_condTxtStartIdx, c3_c_condTxtEndIdx, 3U,
                      c3_c_postfixPredicateTree, false);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 968,
    978, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U, 3322,
    3350, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 2U, 4464,
    4487, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 3U, 4643,
    4648, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 4U, 4652,
    4670, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 5U, 4674,
    4679, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 6U, 4683,
    4701, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 7U, 4971,
    4986, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 8U, 5023,
    5039, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 9U, 5043,
    5057, -1, 2U);
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

  static char_T c3_cv1[31] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '1',
    '0', '1', '1', '1', '2', '1', '3', '1', '4', '1', '5', '1', '6', '1', '7',
    '1', '8', '1', '9', '2', '0' };

  static char_T c3_cv2[19] = { 'H', 'o', 'r', 'i', 'z', 'o', 'n', 't', 'a', 'l',
    'A', 'l', 'i', 'g', 'n', 'm', 'e', 'n', 't' };

  static char_T c3_cv4[17] = { 'V', 'e', 'r', 't', 'i', 'c', 'a', 'l', 'A', 'l',
    'i', 'g', 'n', 'm', 'e', 'n', 't' };

  static char_T c3_cv[6] = { 'P', 'a', 'r', 'e', 'n', 't' };

  static char_T c3_cv3[4] = { 'l', 'e', 'f', 't' };

  static char_T c3_cv5[3] = { 't', 'o', 'p' };

  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c3_b_pointsx[20];
  real_T c3_b_pointsy[20];
  real_T c3_sortedPointsX[20];
  real_T c3_sortedPointsY[20];
  real_T c3_unsorted_validX_data[20];
  real_T c3_dv[2];
  real_T c3_b_a;
  real_T c3_b_c;
  real_T c3_b_closestIdx;
  real_T c3_b_distX;
  real_T c3_b_distY;
  real_T c3_b_dx;
  real_T c3_b_dy;
  real_T c3_b_sortedPointsX;
  real_T c3_b_sortedPointsY;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c;
  real_T c3_c_a;
  real_T c3_c_i;
  real_T c3_c_k;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_closestIdx;
  real_T c3_count;
  real_T c3_d;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  real_T c3_d7;
  real_T c3_d_a;
  real_T c3_e_a;
  real_T c3_ex;
  real_T c3_f_a;
  real_T c3_g_a;
  real_T c3_h_a;
  real_T c3_i_a;
  real_T c3_j_a;
  real_T c3_k_a;
  real_T c3_sorted_count;
  real_T c3_x;
  real_T c3_xIdx;
  real_T c3_yIdx;
  int32_T c3_iv[2];
  int32_T c3_iv1[2];
  int32_T c3_iv2[2];
  int32_T c3_iv3[2];
  int32_T c3_b_filteredX_size[1];
  int32_T c3_b_filteredY_size[1];
  int32_T c3_b_minDistances_size[1];
  int32_T c3_b_tmp_size[1];
  int32_T c3_c_filteredX_size[1];
  int32_T c3_c_filteredY_size[1];
  int32_T c3_filteredX_size[1];
  int32_T c3_filteredY_size[1];
  int32_T c3_ii_size[1];
  int32_T c3_jj_size[1];
  int32_T c3_minDistances_size[1];
  int32_T c3_sortedPointsX_size[1];
  int32_T c3_sortedPointsY_size[1];
  int32_T c3_tmp_size[1];
  int32_T c3_unsorted_validX_size[1];
  int32_T c3_xIdx_size[1];
  int32_T c3_yIdx_size[1];
  int32_T c3_b_end;
  int32_T c3_b_i;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
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
  int32_T c3_g_i;
  int32_T c3_g_loop_ub;
  int32_T c3_h_loop_ub;
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
  int32_T c3_i9;
  int32_T c3_i_loop_ub;
  int32_T c3_idx;
  int32_T c3_iindx;
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
  int32_T c3_trueCount;
  uint8_T c3_b_u;
  uint8_T c3_u1;
  boolean_T c3_b_centerline[19200];
  boolean_T c3_b_minDistances_data[19200];
  boolean_T c3_bv1[19200];
  boolean_T c3_centerline[19200];
  boolean_T c3_cleanedImage[19200];
  boolean_T c3_greenChannel[19200];
  boolean_T c3_redChannel[19200];
  boolean_T c3_b_tmp_data[20];
  boolean_T c3_bv2[20];
  boolean_T c3_b;
  boolean_T c3_b1;
  boolean_T c3_b10;
  boolean_T c3_b11;
  boolean_T c3_b12;
  boolean_T c3_b13;
  boolean_T c3_b14;
  boolean_T c3_b15;
  boolean_T c3_b2;
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
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
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

  c3_b_st.site = &c3_ab_emlrtRSI;
  for (c3_i1 = 0; c3_i1 < 19200; c3_i1++) {
    chartInstance->c3_bv[c3_i1] = (*chartInstance->c3_u)[c3_i1];
  }

  c3_bwmorph(chartInstance, chartInstance->c3_bv, c3_cleanedImage);
  c3_b_st.site = &c3_bb_emlrtRSI;
  c3_b_bwmorph(chartInstance, c3_cleanedImage, c3_centerline);
  for (c3_k = 0; c3_k < 15; c3_k++) {
    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 0, 1);
    for (c3_i3 = 0; c3_i3 < 19200; c3_i3++) {
      c3_b_centerline[c3_i3] = c3_centerline[c3_i3];
    }

    c3_b_st.site = &c3_cb_emlrtRSI;
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

  c3_b_st.site = &c3_db_emlrtRSI;
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
    emlrtNonNegativeCheckR2012b(c3_d1, &c3_l_emlrtDCI, &c3_st);
  }

  if (c3_d1 != (real_T)(int32_T)muDoubleScalarFloor(c3_d1)) {
    emlrtIntegerCheckR2012b(c3_d1, &c3_m_emlrtDCI, &c3_st);
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
    emlrtNonNegativeCheckR2012b(c3_d2, &c3_n_emlrtDCI, &c3_st);
  }

  if (c3_d2 != (real_T)(int32_T)muDoubleScalarFloor(c3_d2)) {
    emlrtIntegerCheckR2012b(c3_d2, &c3_o_emlrtDCI, &c3_st);
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
    &c3_cb_emlrtRTEI, &c3_st);
  for (c3_b_i = 0; c3_b_i < c3_i15; c3_b_i++) {
    c3_c_i = 1.0 + (real_T)c3_b_i;
    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 1, 1);
    if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 1,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 0U, c3_count,
                        0.0, -1, 0U, c3_count == 0.0))) {
      c3_count++;
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_p_emlrtDCI, &c3_st);
      }

      c3_i18 = (int32_T)c3_c_i;
      if ((c3_i18 < 1) || (c3_i18 > c3_xIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i18, 1, c3_xIdx_size[0], &c3_p_emlrtBCI,
          &c3_st);
      }

      if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
        emlrtIntegerCheckR2012b(c3_count, &c3_q_emlrtDCI, &c3_st);
      }

      c3_i23 = (int32_T)c3_count;
      if ((c3_i23 < 1) || (c3_i23 > c3_filteredX_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i23, 1, c3_filteredX_size[0],
          &c3_q_emlrtBCI, &c3_st);
      }

      chartInstance->c3_filteredX_data[c3_i23 - 1] = chartInstance->
        c3_xIdx_data[c3_i18 - 1];
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_r_emlrtDCI, &c3_st);
      }

      c3_i27 = (int32_T)c3_c_i;
      if ((c3_i27 < 1) || (c3_i27 > c3_yIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i27, 1, c3_yIdx_size[0], &c3_r_emlrtBCI,
          &c3_st);
      }

      if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
        emlrtIntegerCheckR2012b(c3_count, &c3_s_emlrtDCI, &c3_st);
      }

      c3_i32 = (int32_T)c3_count;
      if ((c3_i32 < 1) || (c3_i32 > c3_filteredY_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i32, 1, c3_filteredY_size[0],
          &c3_s_emlrtBCI, &c3_st);
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
      c3_b_st.site = &c3_eb_emlrtRSI;
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
      c3_b_st.site = &c3_eb_emlrtRSI;
      c3_indexShapeCheck(chartInstance, &c3_b_st, c3_filteredY_size[0], c3_iv2);
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_t_emlrtDCI, &c3_st);
      }

      c3_i37 = (int32_T)c3_c_i;
      if ((c3_i37 < 1) || (c3_i37 > c3_xIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i37, 1, c3_xIdx_size[0], &c3_t_emlrtBCI,
          &c3_st);
      }

      c3_xIdx = chartInstance->c3_xIdx_data[c3_i37 - 1];
      c3_c_filteredX_size[0] = (c3_i22 - c3_i21) + 1;
      c3_h_loop_ub = c3_i22 - c3_i21;
      for (c3_i40 = 0; c3_i40 <= c3_h_loop_ub; c3_i40++) {
        chartInstance->c3_c_filteredX_data[c3_i40] =
          chartInstance->c3_filteredX_data[(c3_i21 + c3_i40) - 1] - c3_xIdx;
      }

      c3_b_st.site = &c3_eb_emlrtRSI;
      c3_power(chartInstance, &c3_b_st, chartInstance->c3_c_filteredX_data,
               c3_c_filteredX_size, chartInstance->c3_minDistances_data,
               c3_minDistances_size);
      if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
        emlrtIntegerCheckR2012b(c3_c_i, &c3_u_emlrtDCI, &c3_st);
      }

      c3_i42 = (int32_T)c3_c_i;
      if ((c3_i42 < 1) || (c3_i42 > c3_yIdx_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c3_i42, 1, c3_yIdx_size[0], &c3_u_emlrtBCI,
          &c3_st);
      }

      c3_yIdx = chartInstance->c3_yIdx_data[c3_i42 - 1];
      c3_c_filteredY_size[0] = (c3_i31 - c3_i30) + 1;
      c3_l_loop_ub = c3_i31 - c3_i30;
      for (c3_i46 = 0; c3_i46 <= c3_l_loop_ub; c3_i46++) {
        chartInstance->c3_c_filteredY_data[c3_i46] =
          chartInstance->c3_filteredY_data[(c3_i30 + c3_i46) - 1] - c3_yIdx;
      }

      c3_b_st.site = &c3_eb_emlrtRSI;
      c3_power(chartInstance, &c3_b_st, chartInstance->c3_c_filteredY_data,
               c3_c_filteredY_size, chartInstance->c3_tmp_data, c3_tmp_size);
      if ((c3_minDistances_size[0] != c3_tmp_size[0]) && ((c3_minDistances_size
            [0] != 1) && (c3_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c3_minDistances_size[0], c3_tmp_size[0],
          &c3_emlrtECI, &c3_st);
      }

      if (c3_minDistances_size[0] == c3_tmp_size[0]) {
        c3_m_loop_ub = c3_minDistances_size[0] - 1;
        for (c3_i48 = 0; c3_i48 <= c3_m_loop_ub; c3_i48++) {
          chartInstance->c3_minDistances_data[c3_i48] +=
            chartInstance->c3_tmp_data[c3_i48];
        }
      } else {
        c3_plus(chartInstance, chartInstance->c3_minDistances_data,
                c3_minDistances_size, chartInstance->c3_tmp_data, c3_tmp_size);
      }

      c3_b_st.site = &c3_eb_emlrtRSI;
      c3_b_sqrt(chartInstance, &c3_b_st, chartInstance->c3_minDistances_data,
                c3_minDistances_size);
      c3_b_minDistances_size[0] = c3_minDistances_size[0];
      c3_n_loop_ub = c3_minDistances_size[0] - 1;
      for (c3_i52 = 0; c3_i52 <= c3_n_loop_ub; c3_i52++) {
        c3_b_minDistances_data[c3_i52] = (chartInstance->
          c3_minDistances_data[c3_i52] > 10.0);
      }

      c3_b_st.site = &c3_fb_emlrtRSI;
      if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 2, c3_all
                         (chartInstance, &c3_b_st, c3_b_minDistances_data,
                          c3_b_minDistances_size))) {
        c3_count++;
        if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
          emlrtIntegerCheckR2012b(c3_c_i, &c3_w_emlrtDCI, &c3_st);
        }

        c3_i55 = (int32_T)c3_c_i;
        if ((c3_i55 < 1) || (c3_i55 > c3_xIdx_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i55, 1, c3_xIdx_size[0],
            &c3_w_emlrtBCI, &c3_st);
        }

        if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
          emlrtIntegerCheckR2012b(c3_count, &c3_x_emlrtDCI, &c3_st);
        }

        c3_i57 = (int32_T)c3_count;
        if ((c3_i57 < 1) || (c3_i57 > c3_filteredX_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i57, 1, c3_filteredX_size[0],
            &c3_x_emlrtBCI, &c3_st);
        }

        chartInstance->c3_filteredX_data[c3_i57 - 1] =
          chartInstance->c3_xIdx_data[c3_i55 - 1];
        if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
          emlrtIntegerCheckR2012b(c3_c_i, &c3_y_emlrtDCI, &c3_st);
        }

        c3_i61 = (int32_T)c3_c_i;
        if ((c3_i61 < 1) || (c3_i61 > c3_yIdx_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i61, 1, c3_yIdx_size[0],
            &c3_y_emlrtBCI, &c3_st);
        }

        if (c3_count != (real_T)(int32_T)muDoubleScalarFloor(c3_count)) {
          emlrtIntegerCheckR2012b(c3_count, &c3_ab_emlrtDCI, &c3_st);
        }

        c3_i62 = (int32_T)c3_count;
        if ((c3_i62 < 1) || (c3_i62 > c3_filteredY_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c3_i62, 1, c3_filteredY_size[0],
            &c3_ab_emlrtBCI, &c3_st);
        }

        chartInstance->c3_filteredY_data[c3_i62 - 1] =
          chartInstance->c3_yIdx_data[c3_i61 - 1];
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
  c3_b_st.site = &c3_gb_emlrtRSI;
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
  c3_b_st.site = &c3_hb_emlrtRSI;
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

  for (c3_i45 = 0; c3_i45 < 20; c3_i45++) {
    c3_sortedPointsX[c3_i45] = 999.0;
  }

  for (c3_i47 = 0; c3_i47 < 20; c3_i47++) {
    c3_sortedPointsY[c3_i47] = 999.0;
  }

  c3_sorted_count = 1.0;
  c3_sortedPointsX[0] = 80.0;
  c3_sortedPointsY[0] = 60.0;
  while ((c3_filteredX_size[0] != 0) && (c3_sorted_count < 20.0)) {
    covrtEmlWhileEval(chartInstance->c3_covrtInstance, 4U, 0, 0, true);
    if (c3_sorted_count != (real_T)(int32_T)muDoubleScalarFloor(c3_sorted_count))
    {
      emlrtIntegerCheckR2012b(c3_sorted_count, &c3_v_emlrtDCI, &c3_st);
    }

    c3_i51 = (int32_T)c3_sorted_count;
    if ((c3_i51 < 1) || (c3_i51 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c3_i51, 1, 20, &c3_v_emlrtBCI, &c3_st);
    }

    c3_b_sortedPointsX = c3_sortedPointsX[c3_i51 - 1];
    c3_sortedPointsX_size[0] = c3_filteredX_size[0];
    c3_o_loop_ub = c3_filteredX_size[0] - 1;
    for (c3_i54 = 0; c3_i54 <= c3_o_loop_ub; c3_i54++) {
      chartInstance->c3_sortedPointsX_data[c3_i54] = c3_b_sortedPointsX -
        chartInstance->c3_filteredX_data[c3_i54];
    }

    c3_b_st.site = &c3_ib_emlrtRSI;
    c3_power(chartInstance, &c3_b_st, chartInstance->c3_sortedPointsX_data,
             c3_sortedPointsX_size, chartInstance->c3_yIdx_data, c3_yIdx_size);
    if (c3_sorted_count != (real_T)(int32_T)muDoubleScalarFloor(c3_sorted_count))
    {
      emlrtIntegerCheckR2012b(c3_sorted_count, &c3_bb_emlrtDCI, &c3_st);
    }

    c3_i56 = (int32_T)c3_sorted_count;
    if ((c3_i56 < 1) || (c3_i56 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c3_i56, 1, 20, &c3_bb_emlrtBCI, &c3_st);
    }

    c3_b_sortedPointsY = c3_sortedPointsY[c3_i56 - 1];
    c3_sortedPointsY_size[0] = c3_filteredY_size[0];
    c3_p_loop_ub = c3_filteredY_size[0] - 1;
    for (c3_i59 = 0; c3_i59 <= c3_p_loop_ub; c3_i59++) {
      chartInstance->c3_sortedPointsY_data[c3_i59] = c3_b_sortedPointsY -
        chartInstance->c3_filteredY_data[c3_i59];
    }

    c3_b_st.site = &c3_ib_emlrtRSI;
    c3_power(chartInstance, &c3_b_st, chartInstance->c3_sortedPointsY_data,
             c3_sortedPointsY_size, chartInstance->c3_tmp_data, c3_tmp_size);
    if ((c3_yIdx_size[0] != c3_tmp_size[0]) && ((c3_yIdx_size[0] != 1) &&
         (c3_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c3_yIdx_size[0], c3_tmp_size[0],
        &c3_b_emlrtECI, &c3_st);
    }

    if (c3_yIdx_size[0] == c3_tmp_size[0]) {
      c3_q_loop_ub = c3_yIdx_size[0] - 1;
      for (c3_i63 = 0; c3_i63 <= c3_q_loop_ub; c3_i63++) {
        chartInstance->c3_yIdx_data[c3_i63] += chartInstance->c3_tmp_data[c3_i63];
      }
    } else {
      c3_plus(chartInstance, chartInstance->c3_yIdx_data, c3_yIdx_size,
              chartInstance->c3_tmp_data, c3_tmp_size);
    }

    c3_b_st.site = &c3_ib_emlrtRSI;
    c3_b_sqrt(chartInstance, &c3_b_st, chartInstance->c3_yIdx_data, c3_yIdx_size);
    c3_b_st.site = &c3_jb_emlrtRSI;
    c3_c_st.site = &c3_t_emlrtRSI;
    c3_d_st.site = &c3_u_emlrtRSI;
    c3_minimum(chartInstance, &c3_d_st, chartInstance->c3_yIdx_data,
               c3_yIdx_size, &c3_ex, &c3_idx);
    c3_iindx = c3_idx;
    c3_closestIdx = (real_T)c3_iindx;
    c3_b_closestIdx = c3_closestIdx;
    c3_sorted_count++;
    if (c3_b_closestIdx != (real_T)(int32_T)muDoubleScalarFloor(c3_b_closestIdx))
    {
      emlrtIntegerCheckR2012b(c3_b_closestIdx, &c3_db_emlrtDCI, &c3_st);
    }

    c3_i69 = (int32_T)c3_b_closestIdx;
    if ((c3_i69 < 1) || (c3_i69 > c3_filteredX_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i69, 1, c3_filteredX_size[0],
        &c3_db_emlrtBCI, &c3_st);
    }

    if (c3_sorted_count != (real_T)(int32_T)muDoubleScalarFloor(c3_sorted_count))
    {
      emlrtIntegerCheckR2012b(c3_sorted_count, &c3_eb_emlrtDCI, &c3_st);
    }

    c3_i73 = (int32_T)c3_sorted_count;
    if ((c3_i73 < 1) || (c3_i73 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c3_i73, 1, 20, &c3_eb_emlrtBCI, &c3_st);
    }

    c3_sortedPointsX[c3_i73 - 1] = chartInstance->c3_filteredX_data[c3_i69 - 1];
    if (c3_b_closestIdx != (real_T)(int32_T)muDoubleScalarFloor(c3_b_closestIdx))
    {
      emlrtIntegerCheckR2012b(c3_b_closestIdx, &c3_fb_emlrtDCI, &c3_st);
    }

    c3_i75 = (int32_T)c3_b_closestIdx;
    if ((c3_i75 < 1) || (c3_i75 > c3_filteredY_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c3_i75, 1, c3_filteredY_size[0],
        &c3_fb_emlrtBCI, &c3_st);
    }

    if (c3_sorted_count != (real_T)(int32_T)muDoubleScalarFloor(c3_sorted_count))
    {
      emlrtIntegerCheckR2012b(c3_sorted_count, &c3_gb_emlrtDCI, &c3_st);
    }

    c3_i77 = (int32_T)c3_sorted_count;
    if ((c3_i77 < 1) || (c3_i77 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c3_i77, 1, 20, &c3_gb_emlrtBCI, &c3_st);
    }

    c3_sortedPointsY[c3_i77 - 1] = chartInstance->c3_filteredY_data[c3_i75 - 1];
    c3_b_st.site = &c3_kb_emlrtRSI;
    c3_b_nullAssignment(chartInstance, &c3_b_st,
                        chartInstance->c3_filteredX_data, c3_filteredX_size,
                        (int32_T)c3_b_closestIdx);
    c3_b_st.site = &c3_lb_emlrtRSI;
    c3_b_nullAssignment(chartInstance, &c3_b_st,
                        chartInstance->c3_filteredY_data, c3_filteredY_size,
                        (int32_T)c3_b_closestIdx);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlWhileEval(chartInstance->c3_covrtInstance, 4U, 0, 0, false);
  for (c3_i49 = 0; c3_i49 < 20; c3_i49++) {
    c3_b_pointsx[c3_i49] = c3_sortedPointsX[c3_i49];
  }

  for (c3_i50 = 0; c3_i50 < 20; c3_i50++) {
    c3_b_pointsy[c3_i50] = c3_sortedPointsY[c3_i50];
  }

  for (c3_i53 = 0; c3_i53 < 20; c3_i53++) {
    c3_bv2[c3_i53] = (c3_b_pointsy[c3_i53] != 999.0);
  }

  c3_end = 20;
  c3_trueCount = 0;
  for (c3_d_i = 0; c3_d_i < c3_end; c3_d_i++) {
    if ((c3_b_pointsx[c3_d_i] != 999.0) && c3_bv2[c3_d_i]) {
      c3_trueCount++;
    }
  }

  c3_unsorted_validX_size[0] = c3_trueCount;
  c3_partialTrueCount = 0;
  for (c3_e_i = 0; c3_e_i < c3_end; c3_e_i++) {
    if ((c3_b_pointsx[c3_e_i] != 999.0) && c3_bv2[c3_e_i]) {
      c3_d4 = (real_T)c3_e_i;
      if (c3_d4 != (real_T)(int32_T)muDoubleScalarFloor(c3_d4)) {
        emlrtIntegerCheckR2012b(c3_d4, &c3_cb_emlrtDCI, &c3_st);
      }

      c3_i58 = (int32_T)muDoubleScalarFloor(c3_d4);
      if ((c3_i58 < 0) || (c3_i58 > 19)) {
        emlrtDynamicBoundsCheckR2012b(c3_i58, 0, 19, &c3_cb_emlrtBCI, &c3_st);
      }

      c3_unsorted_validX_data[c3_partialTrueCount] = c3_b_pointsx[c3_i58];
      c3_partialTrueCount++;
    }
  }

  c3_b_end = 20;
  for (c3_f_i = 0; c3_f_i < c3_b_end; c3_f_i++) {
    if ((c3_b_pointsx[c3_f_i] != 999.0) && c3_bv2[c3_f_i]) {
      c3_d5 = (real_T)c3_f_i;
      if (c3_d5 != (real_T)(int32_T)muDoubleScalarFloor(c3_d5)) {
        emlrtIntegerCheckR2012b(c3_d5, &c3_k_emlrtDCI, &c3_st);
      }

      c3_i60 = (int32_T)muDoubleScalarFloor(c3_d5);
      if ((c3_i60 < 0) || (c3_i60 > 19)) {
        emlrtDynamicBoundsCheckR2012b(c3_i60, 0, 19, &c3_o_emlrtBCI, &c3_st);
      }
    }
  }

  c3_guard1 = false;
  if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 0,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c3_covrtInstance, 4U, 0U, 1U, (real_T)
                        c3_unsorted_validX_size[0], 3.0, -1, 5U, (real_T)
                        c3_unsorted_validX_size[0] >= 3.0))) {
    c3_isfinite(chartInstance, c3_unsorted_validX_data, c3_unsorted_validX_size,
                c3_b_tmp_data, c3_b_tmp_size);
    c3_b_st.site = &c3_mb_emlrtRSI;
    if (covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 1, c3_all
                         (chartInstance, &c3_b_st, c3_b_tmp_data, c3_b_tmp_size)))
    {
      covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 0, true);
      covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 3, true);
      if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 4,
                         !chartInstance->c3_hFig_not_empty)) {
        c3_b_st.site = &c3_ob_emlrtRSI;
        sf_mex_assign(&chartInstance->c3_hFig, c3_figure(chartInstance, &c3_b_st),
                      true);
        chartInstance->c3_hFig_not_empty = true;
        c3_b_st.site = &c3_ob_emlrtRSI;
        chartInstance->c3_hFig_not_empty = !c3_emlrt_marshallIn(chartInstance,
          c3_isempty(chartInstance, &c3_b_st, sf_mex_dup(chartInstance->c3_hFig)),
          "<output of isempty>");
        c3_b_st.site = &c3_pb_emlrtRSI;
        sf_mex_assign(&chartInstance->c3_hAx, c3_axes(chartInstance, &c3_b_st,
          c3_emlrt_marshallOut(chartInstance, c3_cv), sf_mex_dup
          (chartInstance->c3_hFig)), true);
        chartInstance->c3_hAx_not_empty = true;
        c3_b_st.site = &c3_pb_emlrtRSI;
        chartInstance->c3_hAx_not_empty = !c3_emlrt_marshallIn(chartInstance,
          c3_b_isempty(chartInstance, &c3_b_st, sf_mex_dup(chartInstance->c3_hAx)),
          "<output of isempty>");
      } else {
        c3_b_st.site = &c3_qb_emlrtRSI;
        c3_b_figure(chartInstance, &c3_b_st, sf_mex_dup(chartInstance->c3_hFig));
      }

      c3_b_st.site = &c3_tb_emlrtRSI;
      c3_scatter(chartInstance, &c3_b_st, c3_b_emlrt_marshallOut(chartInstance,
                  c3_b_pointsx), c3_b_emlrt_marshallOut(chartInstance,
                  c3_b_pointsy));
      c3_b_st.site = &c3_rb_emlrtRSI;
      c3_axis(chartInstance, &c3_b_st, sf_mex_dup(chartInstance->c3_hAx),
              c3_c_emlrt_marshallOut(chartInstance, c3_dv1));
      for (c3_g_i = 0; c3_g_i < 20; c3_g_i++) {
        c3_c_i = 1.0 + (real_T)c3_g_i;
        covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 2, 1);
        if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
          emlrtIntegerCheckR2012b(c3_c_i, &c3_hb_emlrtDCI, &c3_st);
        }

        c3_i67 = (int32_T)c3_c_i;
        if ((c3_i67 < 1) || (c3_i67 > 20)) {
          emlrtDynamicBoundsCheckR2012b(c3_i67, 1, 20, &c3_hb_emlrtBCI, &c3_st);
        }

        if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
          emlrtIntegerCheckR2012b(c3_c_i, &c3_ib_emlrtDCI, &c3_st);
        }

        c3_i70 = (int32_T)c3_c_i;
        if ((c3_i70 < 1) || (c3_i70 > 20)) {
          emlrtDynamicBoundsCheckR2012b(c3_i70, 1, 20, &c3_ib_emlrtBCI, &c3_st);
        }

        if (c3_c_i != (real_T)(int32_T)muDoubleScalarFloor(c3_c_i)) {
          emlrtIntegerCheckR2012b(c3_c_i, &c3_jb_emlrtDCI, &c3_st);
        }

        c3_i74 = (int32_T)c3_c_i;
        if ((c3_i74 < 1) || (c3_i74 > 31)) {
          emlrtDynamicBoundsCheckR2012b(c3_i74, 1, 31, &c3_jb_emlrtBCI, &c3_st);
        }

        c3_b_st.site = &c3_sb_emlrtRSI;
        c3_text(chartInstance, &c3_b_st, c3_d_emlrt_marshallOut(chartInstance,
                 c3_b_pointsx[c3_i67 - 1]), c3_d_emlrt_marshallOut(chartInstance,
                 c3_b_pointsy[c3_i70 - 1]), c3_e_emlrt_marshallOut(chartInstance,
                 c3_cv1[c3_i74 - 1]), c3_f_emlrt_marshallOut(chartInstance,
                 c3_cv2), c3_g_emlrt_marshallOut(chartInstance, c3_cv3),
                c3_h_emlrt_marshallOut(chartInstance, c3_cv4),
                c3_i_emlrt_marshallOut(chartInstance, c3_cv5));
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 2, 0);
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

  for (c3_b_k = 0; c3_b_k < 19; c3_b_k++) {
    c3_c_k = 2.0 + (real_T)c3_b_k;
    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 3, 1);
    for (c3_dx = 0; c3_dx < 9; c3_dx++) {
      c3_b_dx = -4.0 + (real_T)c3_dx;
      covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 4, 1);
      for (c3_dy = 0; c3_dy < 9; c3_dy++) {
        c3_b_dy = -4.0 + (real_T)c3_dy;
        covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 5, 1);
        c3_b_st.site = &c3_nb_emlrtRSI;
        c3_b_a = c3_b_dx;
        c3_c_st.site = &c3_y_emlrtRSI;
        c3_c_a = c3_b_a;
        c3_d_a = c3_c_a;
        c3_e_a = c3_d_a;
        c3_f_a = c3_e_a;
        c3_c = c3_f_a * c3_f_a;
        c3_b_st.site = &c3_nb_emlrtRSI;
        c3_g_a = c3_b_dy;
        c3_c_st.site = &c3_y_emlrtRSI;
        c3_h_a = c3_g_a;
        c3_i_a = c3_h_a;
        c3_j_a = c3_i_a;
        c3_k_a = c3_j_a;
        c3_b_c = c3_k_a * c3_k_a;
        c3_d6 = c3_c + c3_b_c;
        c3_b_st.site = &c3_nb_emlrtRSI;
        c3_c_st.site = &c3_y_emlrtRSI;
        if (covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 5,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c3_covrtInstance, 4U, 0U, 2U, c3_d6,
                            16.0, -1, 3U, c3_d6 <= 16.0))) {
          if (c3_c_k != (real_T)(int32_T)muDoubleScalarFloor(c3_c_k)) {
            emlrtIntegerCheckR2012b(c3_c_k, &c3_kb_emlrtDCI, &c3_st);
          }

          c3_i76 = (int32_T)c3_c_k;
          if ((c3_i76 < 1) || (c3_i76 > 20)) {
            emlrtDynamicBoundsCheckR2012b(c3_i76, 1, 20, &c3_kb_emlrtBCI, &c3_st);
          }

          c3_x = (c3_sortedPointsX[c3_i76 - 1] + c3_b_dx) + 80.0;
          if (c3_c_k != (real_T)(int32_T)muDoubleScalarFloor(c3_c_k)) {
            emlrtIntegerCheckR2012b(c3_c_k, &c3_lb_emlrtDCI, &c3_st);
          }

          c3_i78 = (int32_T)c3_c_k;
          if ((c3_i78 < 1) || (c3_i78 > 20)) {
            emlrtDynamicBoundsCheckR2012b(c3_i78, 1, 20, &c3_lb_emlrtBCI, &c3_st);
          }

          c3_b_y = (c3_sortedPointsY[c3_i78 - 1] + c3_b_dy) + 60.0;
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
                                c3_b_y, 0.0, -1, 4U, c3_b_y > 0.0)) &&
              covrtEmlCondEval(chartInstance->c3_covrtInstance, 4U, 0, 5,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c3_covrtInstance, 4U, 0U, 6U,
                                c3_b_y, 120.0, -1, 3U, c3_b_y <= 120.0))) {
            covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 1, true);
            covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 6, true);
            if (c3_b_y != (real_T)(int32_T)muDoubleScalarFloor(c3_b_y)) {
              emlrtIntegerCheckR2012b(c3_b_y, &c3_e_emlrtDCI, &c3_st);
            }

            c3_i79 = (int32_T)c3_b_y;
            if ((c3_i79 < 1) || (c3_i79 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c3_i79, 1, 120, &c3_i_emlrtBCI,
                &c3_st);
            }

            if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
              emlrtIntegerCheckR2012b(c3_x, &c3_f_emlrtDCI, &c3_st);
            }

            c3_i80 = (int32_T)c3_x;
            if ((c3_i80 < 1) || (c3_i80 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c3_i80, 1, 160, &c3_j_emlrtBCI,
                &c3_st);
            }

            chartInstance->c3_outt[(c3_i79 + 120 * (c3_i80 - 1)) - 1] = 0U;
            c3_b_x = 255.0 * c3_c_k / 20.0;
            c3_c_x = c3_b_x;
            c3_c_y = c3_c_x;
            c3_c_y = muDoubleScalarFloor(c3_c_y);
            if (c3_b_y != (real_T)(int32_T)muDoubleScalarFloor(c3_b_y)) {
              emlrtIntegerCheckR2012b(c3_b_y, &c3_g_emlrtDCI, &c3_st);
            }

            c3_i81 = (int32_T)c3_b_y;
            if ((c3_i81 < 1) || (c3_i81 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c3_i81, 1, 120, &c3_k_emlrtBCI,
                &c3_st);
            }

            if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
              emlrtIntegerCheckR2012b(c3_x, &c3_h_emlrtDCI, &c3_st);
            }

            c3_i82 = (int32_T)c3_x;
            if ((c3_i82 < 1) || (c3_i82 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c3_i82, 1, 160, &c3_l_emlrtBCI,
                &c3_st);
            }

            c3_d7 = muDoubleScalarRound(c3_c_y);
            c3_b_covSaturation = false;
            if (c3_d7 < 256.0) {
              if (c3_d7 >= 0.0) {
                c3_u1 = (uint8_T)c3_d7;
              } else {
                c3_b_covSaturation = true;
                c3_u1 = 0U;
                sf_data_saturate_error(chartInstance->S, 1U, 4779, 50);
              }
            } else if (c3_d7 >= 256.0) {
              c3_b_covSaturation = true;
              c3_u1 = MAX_uint8_T;
              sf_data_saturate_error(chartInstance->S, 1U, 4779, 50);
            } else {
              c3_u1 = 0U;
            }

            covrtSaturationUpdateFcn(chartInstance->c3_covrtInstance, 4, 0, 0, 0,
              c3_b_covSaturation);
            chartInstance->c3_outt[(c3_i81 + 120 * (c3_i82 - 1)) + 19199] =
              c3_u1;
            if (c3_b_y != (real_T)(int32_T)muDoubleScalarFloor(c3_b_y)) {
              emlrtIntegerCheckR2012b(c3_b_y, &c3_i_emlrtDCI, &c3_st);
            }

            c3_i83 = (int32_T)c3_b_y;
            if ((c3_i83 < 1) || (c3_i83 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c3_i83, 1, 120, &c3_m_emlrtBCI,
                &c3_st);
            }

            if (c3_x != (real_T)(int32_T)muDoubleScalarFloor(c3_x)) {
              emlrtIntegerCheckR2012b(c3_x, &c3_j_emlrtDCI, &c3_st);
            }

            c3_i84 = (int32_T)c3_x;
            if ((c3_i84 < 1) || (c3_i84 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c3_i84, 1, 160, &c3_n_emlrtBCI,
                &c3_st);
            }

            chartInstance->c3_outt[(c3_i83 + 120 * (c3_i84 - 1)) + 38399] = 0U;
          } else {
            covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 1, false);
            covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 6, false);
          }
        }

        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 5, 0);
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 4, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c3_covrtInstance, 4U, 0, 3, 0);
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
    c3_b_distX = 10.0;
    c3_b_distY = 10.0;
  } else {
    covrtEmlMcdcEval(chartInstance->c3_covrtInstance, 4U, 0, 2, false);
    covrtEmlIfEval(chartInstance->c3_covrtInstance, 4U, 0, 8, false);
    c3_b_distX = 0.0;
    c3_b_distY = 0.0;
  }

  chartInstance->c3_call_count++;
  for (c3_i64 = 0; c3_i64 < 57600; c3_i64++) {
    (*chartInstance->c3_b_outt)[c3_i64] = chartInstance->c3_outt[c3_i64];
  }

  *chartInstance->c3_distX = c3_b_distX;
  *chartInstance->c3_distY = c3_b_distY;
  for (c3_i65 = 0; c3_i65 < 20; c3_i65++) {
    (*chartInstance->c3_pointsx)[c3_i65] = c3_b_pointsx[c3_i65];
  }

  for (c3_i66 = 0; c3_i66 < 20; c3_i66++) {
    (*chartInstance->c3_pointsy)[c3_i66] = c3_b_pointsy[c3_i66];
  }

  c3_do_animation_call_c3_flightControlSystem(chartInstance);
  for (c3_i68 = 0; c3_i68 < 57600; c3_i68++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 1U, (real_T)
                      (*chartInstance->c3_b_outt)[c3_i68]);
  }

  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 2U,
                    *chartInstance->c3_distX);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 3U,
                    *chartInstance->c3_distY);
  for (c3_i71 = 0; c3_i71 < 20; c3_i71++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 4U,
                      (*chartInstance->c3_pointsx)[c3_i71]);
  }

  for (c3_i72 = 0; c3_i72 < 20; c3_i72++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 5U,
                      (*chartInstance->c3_pointsy)[c3_i72]);
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
                    emlrtStack *c3_sp, real_T c3_b_x_data[], int32_T c3_x_size[1],
                    real_T c3_c_x_data[], int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_c_x_data[c3_i] = c3_b_x_data[c3_i];
  }

  c3_b_sqrt(chartInstance, c3_sp, c3_c_x_data, c3_b_x_size);
}

static boolean_T c3_all(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, boolean_T c3_b_x_data[], int32_T c3_x_size[1])
{
  static char_T c3_cv[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
    'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c3_st;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  real_T c3_b_a;
  real_T c3_vlen;
  int32_T c3_b_b;
  int32_T c3_c;
  int32_T c3_c_a;
  int32_T c3_d_a;
  int32_T c3_i2;
  int32_T c3_ix;
  int32_T c3_vspread;
  boolean_T c3_b;
  boolean_T c3_b_y;
  boolean_T c3_exitg1;
  (void)chartInstance;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_s_emlrtRSI;
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
  c3_ix = 0;
  c3_exitg1 = false;
  while ((!c3_exitg1) && (c3_ix + 1 <= c3_i2)) {
    if (!c3_b_x_data[c3_ix]) {
      c3_b_y = false;
      c3_exitg1 = true;
    } else {
      c3_ix++;
    }
  }

  return c3_b_y;
}

static void c3_minimum(SFc3_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_b_x_data[], int32_T c3_x_size[1], real_T
  *c3_ex, int32_T *c3_idx)
{
  static char_T c3_cv1[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  static char_T c3_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  real_T c3_b_ex;
  real_T c3_b_x;
  real_T c3_c_ex;
  real_T c3_c_x;
  real_T c3_d_ex;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_x;
  int32_T c3_b_a;
  int32_T c3_b_idx;
  int32_T c3_b_k;
  int32_T c3_b_last;
  int32_T c3_c;
  int32_T c3_c_idx;
  int32_T c3_c_last;
  int32_T c3_d_idx;
  int32_T c3_first;
  int32_T c3_i;
  int32_T c3_k;
  int32_T c3_last;
  int32_T c3_nx;
  boolean_T c3_b;
  boolean_T c3_b_b;
  boolean_T c3_b_p;
  boolean_T c3_c_b;
  boolean_T c3_d_b;
  boolean_T c3_e_b;
  boolean_T c3_exitg1;
  boolean_T c3_guard1;
  boolean_T c3_guard2;
  boolean_T c3_p;
  (void)chartInstance;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_v_emlrtRSI;
  if ((c3_x_size[0] == 1) || ((real_T)c3_x_size[0] != 1.0)) {
    c3_b = true;
  } else {
    c3_b = false;
  }

  if (!c3_b) {
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c3_st, &c3_f_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_d_y)));
  }

  if (!((real_T)c3_x_size[0] >= 1.0)) {
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c3_e_y = NULL;
    sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c3_st, &c3_g_emlrtMCI, "error", 0U, 2U, 14, c3_c_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_e_y)));
  }

  c3_last = c3_x_size[0] - 1;
  c3_b_a = c3_last;
  c3_c = (uint16_T)c3_b_a + 1;
  c3_nx = c3_c;
  if (c3_nx <= 2) {
    if (c3_nx == 1) {
      c3_b_ex = c3_b_x_data[0];
      c3_b_idx = 1;
    } else {
      c3_guard1 = false;
      c3_guard2 = false;
      if (c3_b_x_data[0] > c3_b_x_data[c3_last]) {
        c3_guard2 = true;
      } else {
        c3_c_x = c3_b_x_data[0];
        c3_c_b = muDoubleScalarIsNaN(c3_c_x);
        if (c3_c_b) {
          c3_d_x = c3_b_x_data[c3_last];
          c3_d_b = muDoubleScalarIsNaN(c3_d_x);
          if (!c3_d_b) {
            c3_guard2 = true;
          } else {
            c3_guard1 = true;
          }
        } else {
          c3_guard1 = true;
        }
      }

      if (c3_guard2) {
        c3_b_ex = c3_b_x_data[c3_last];
        c3_b_idx = c3_last + 1;
      }

      if (c3_guard1) {
        c3_b_ex = c3_b_x_data[0];
        c3_b_idx = 1;
      }
    }
  } else {
    c3_b_last = c3_last + 1;
    c3_x = c3_b_x_data[0];
    c3_b_x = c3_x;
    c3_b_b = muDoubleScalarIsNaN(c3_b_x);
    c3_p = !c3_b_b;
    if (c3_p) {
      c3_b_idx = 1;
    } else {
      c3_b_idx = 0;
      c3_k = 2;
      c3_exitg1 = false;
      while ((!c3_exitg1) && (c3_k <= c3_b_last)) {
        c3_e_x = c3_b_x_data[c3_k - 1];
        c3_f_x = c3_e_x;
        c3_e_b = muDoubleScalarIsNaN(c3_f_x);
        c3_b_p = !c3_e_b;
        if (c3_b_p) {
          c3_b_idx = c3_k;
          c3_exitg1 = true;
        } else {
          c3_k++;
        }
      }
    }

    if (c3_b_idx == 0) {
      c3_b_ex = c3_b_x_data[0];
      c3_b_idx = 1;
    } else {
      c3_first = c3_b_idx;
      c3_c_last = c3_last + 1;
      c3_d_ex = c3_b_x_data[c3_first - 1];
      c3_d_idx = c3_first;
      c3_i = c3_first;
      for (c3_b_k = c3_i + 1; c3_b_k <= c3_c_last; c3_b_k++) {
        if (c3_d_ex > c3_b_x_data[c3_b_k - 1]) {
          c3_d_ex = c3_b_x_data[c3_b_k - 1];
          c3_d_idx = c3_b_k;
        }
      }

      c3_b_ex = c3_d_ex;
      c3_b_idx = c3_d_idx;
    }
  }

  c3_c_ex = c3_b_ex;
  c3_c_idx = c3_b_idx;
  *c3_ex = c3_c_ex;
  *c3_idx = c3_c_idx;
}

static void c3_nullAssignment(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_b_x_data[], int32_T
  c3_x_size[1], int32_T c3_idx, real_T c3_c_x_data[], int32_T c3_b_x_size[1])
{
  int32_T c3_i;
  int32_T c3_loop_ub;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    c3_c_x_data[c3_i] = c3_b_x_data[c3_i];
  }

  c3_b_nullAssignment(chartInstance, c3_sp, c3_c_x_data, c3_b_x_size, c3_idx);
}

static void c3_isfinite(SFc3_flightControlSystemInstanceStruct *chartInstance,
  real_T c3_b_x_data[], int32_T c3_x_size[1], boolean_T c3_b_data[], int32_T
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
    c3_b_data[c3_i] = muDoubleScalarIsInf(c3_b_x_data[c3_i]);
  }

  c3_b_loop_ub = c3_b_size[0] - 1;
  for (c3_i1 = 0; c3_i1 <= c3_b_loop_ub; c3_i1++) {
    c3_b_data[c3_i1] = !c3_b_data[c3_i1];
  }

  c3_b_b_size[0] = c3_x_size[0];
  c3_c_loop_ub = c3_x_size[0] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_c_loop_ub; c3_i2++) {
    c3_b_b_data[c3_i2] = muDoubleScalarIsNaN(c3_b_x_data[c3_i2]);
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
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const real_T c3_b_u[20])
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 20), false);
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

static const mxArray *c3_d_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const real_T c3_b_u)
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  return c3_b_y;
}

static const mxArray *c3_e_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u)
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 10, 0U, 0U, 0U, 0), false);
  return c3_b_y;
}

static const mxArray *c3_f_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u[19])
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 19),
                false);
  return c3_b_y;
}

static const mxArray *c3_g_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u[4])
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  return c3_b_y;
}

static const mxArray *c3_h_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u[17])
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 17),
                false);
  return c3_b_y;
}

static const mxArray *c3_i_emlrt_marshallOut
  (SFc3_flightControlSystemInstanceStruct *chartInstance, const char_T c3_b_u[3])
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 3),
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

static void c3_text(SFc3_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray
                    *c3_input1, const mxArray *c3_input2, const mxArray
                    *c3_input3, const mxArray *c3_input4, const mxArray
                    *c3_input5, const mxArray *c3_input6)
{
  (void)chartInstance;
  sf_mex_call(c3_sp, NULL, "text", 0U, 7U, 14, sf_mex_dup(c3_input0), 14,
              sf_mex_dup(c3_input1), 14, sf_mex_dup(c3_input2), 14, sf_mex_dup
              (c3_input3), 14, sf_mex_dup(c3_input4), 14, sf_mex_dup(c3_input5),
              14, sf_mex_dup(c3_input6));
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
  sf_mex_destroy(&c3_input2);
  sf_mex_destroy(&c3_input3);
  sf_mex_destroy(&c3_input4);
  sf_mex_destroy(&c3_input5);
  sf_mex_destroy(&c3_input6);
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
                      const emlrtStack *c3_sp, real_T c3_b_x_data[], int32_T
                      c3_x_size[1])
{
  static char_T c3_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c3_cv1[4] = { 's', 'q', 'r', 't' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  real_T c3_b_k;
  real_T c3_b_x;
  real_T c3_d;
  real_T c3_x;
  int32_T c3_b_x_size[1];
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_k;
  int32_T c3_loop_ub;
  int32_T c3_nx;
  boolean_T c3_b_p;
  boolean_T c3_p;
  c3_b_x_size[0] = c3_x_size[0];
  c3_loop_ub = c3_x_size[0] - 1;
  for (c3_i = 0; c3_i <= c3_loop_ub; c3_i++) {
    chartInstance->c3_x_data[c3_i] = c3_b_x_data[c3_i];
  }

  c3_p = false;
  c3_d = (real_T)c3_b_x_size[0];
  c3_i1 = (int32_T)c3_d - 1;
  for (c3_k = 0; c3_k <= c3_i1; c3_k++) {
    c3_b_k = (real_T)c3_k + 1.0;
    if (c3_p || (chartInstance->c3_x_data[(int32_T)c3_b_k - 1] < 0.0)) {
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

  c3_nx = c3_x_size[0];
  c3_i2 = (uint16_T)c3_nx - 1;
  for (c3_c_k = 0; c3_c_k <= c3_i2; c3_c_k++) {
    c3_d_k = c3_c_k;
    c3_x = c3_b_x_data[c3_d_k];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarSqrt(c3_b_x);
    c3_b_x_data[c3_d_k] = c3_b_x;
  }
}

static void c3_b_nullAssignment(SFc3_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_b_x_data[], int32_T
  c3_x_size[1], int32_T c3_idx)
{
  static char_T c3_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  static char_T c3_cv[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  emlrtStack c3_st;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  int32_T c3_b_x_size[1];
  int32_T c3_b_idx;
  int32_T c3_b_y;
  int32_T c3_c_idx;
  int32_T c3_d_idx;
  int32_T c3_i;
  int32_T c3_k;
  int32_T c3_n;
  int32_T c3_nrowx;
  int32_T c3_nxin;
  int32_T c3_nxout;
  int32_T c3_x;
  boolean_T c3_b;
  boolean_T c3_p;
  (void)chartInstance;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_w_emlrtRSI;
  c3_b_x_size[0] = c3_x_size[0];
  c3_b_idx = c3_idx;
  c3_c_idx = c3_b_idx;
  c3_n = c3_b_x_size[0];
  c3_p = true;
  if (c3_c_idx > c3_n) {
    c3_p = false;
  } else {
    c3_x = c3_c_idx;
    c3_b_y = c3_x;
    if (c3_c_idx != c3_b_y) {
      c3_p = false;
    }
  }

  if (!c3_p) {
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call(&c3_st, &c3_h_emlrtMCI, "error", 0U, 2U, 14, c3_c_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_d_y)));
  }

  c3_st.site = &c3_x_emlrtRSI;
  c3_d_idx = c3_idx;
  c3_nxin = c3_x_size[0] - 1;
  c3_nrowx = c3_x_size[0];
  c3_nxout = c3_nxin;
  for (c3_k = c3_d_idx; c3_k <= c3_nxout; c3_k++) {
    c3_b_x_data[c3_k - 1] = c3_b_x_data[c3_k];
  }

  if (!(c3_nxout <= c3_nrowx)) {
    c3_e_y = NULL;
    sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_f_y = NULL;
    sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c3_st, &c3_i_emlrtMCI, "error", 0U, 2U, 14, c3_e_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 1U, 14, c3_f_y)));
  }

  c3_b = (c3_nxout < 1);
  if (c3_b) {
    c3_i = -1;
  } else {
    c3_i = c3_nxout - 1;
  }

  c3_x_size[0] = c3_i + 1;
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
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3111663566U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2992996818U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1397083607U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1014399029U);
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
  return "syW9vsorRqz5TOlzKFx9cfD";
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
  const char* encStrCodegen [24] = {
    "eNrtWU1vG0UYnqRJIKFUOSC4IBEQAi5IRRVSKyFI4g9qkZDQdRKgSNFk97V35NmZzcysY0ccOHL",
    "nJ/ADOHPrhTvHSvwJjhx5Z3ftupsl2bFT1VBW2mzG9vN+f80sWWjtErxu4R2+TcgKPl/Ge5Fk13",
    "K+Xpi4s8+XyCf5+vtXCPFlAF0QXtLpsAFxu0QS7VNFI03cL0EjeABa8sQwKVqiI6tjmeiAAuEjg",
    "Vgq48RXsyjhTPSaifAtZ30UMj/0QpnwYBsJ0mBP8OE/8Y0Ts48c60yBb5oAgQmVTLphk9Pu5VZQ",
    "5qwWgt/TSeRsKw3GS2Krqt5NuGExh8YA/JbQhqIV9BX6eoYaqJmBm5GtvtoboWUUc0ZFdVuHVHs",
    "QY3QYOIgD/LuXGLReJawfUmW2IaR90Dusl3KXAipxZxp/fcIENVIxyhsRr1lqFfXd56jjLqYEd/",
    "UR6rutgPZiyYRxTAiviXZuCHrCoQ4nSdeRrwenic2GQwZnoNz826nJPijahT3hJnPqo8YgDcpxL",
    "lXEGhbBIVVbPsauhsCtbmDSaY9iOEIbyThhITVxS7cV62NsuNa6lk3/qWpdEmXRr6fCpnwbfXCO",
    "qzHfpi9qlHPthm3LeAf6wFP+dWroFNiMvwNYaxa0JUaHrTaOFSsRDDMhx9akCFj1qOwXUGlj+xK",
    "bVAU4i2waQIBmHos+JnRVHiXayKiGJae+s1OR30VsSxhQHepD5R6jKNOAAqdx5cg3YNomEqLRSi",
    "bVsjKFLAenghLdSUT9TKoe2ti1mT2xlc0ENzQEXSzMBtIi18DoPqQ8qShzpLuYPxgeBxqrrBtfx",
    "Nr8mQrsUz+EwHZOxmEX6ywSqOpibVv+FmrbZ2ZYB+0rFlfNpAQLOjZda6X2MIYD0RPyTDSVjLx8",
    "8rokrgCwalAlmOhuYwtXwyYKX01qBafttLq7DjnWztRwemJj43MQ2A2trnZqoD5mVUPgiIwCzYL",
    "12DkOMUIzbbBRD7NWn/U9O7/fJ0/m96WS+f31ifl9PV/7d447nHVDW2iMktwbIu0oo3d7gt7NCv",
    "uBkRyX4cgFHBnjRs8PJvALJXzJxLPIb3XxcjkX8b+FHLc5gXu1wGepgFvJbfbzTx/9us1++eO39",
    "+9/592Gm7Pw/3HNbb91K1+/OZqbxlW6f6GQVYmHNwrxYNd6eHSvr6V6cHr+cXuPn3/RHNzzO/WU",
    "3uPVy+VdLcg7+nzDzmqYxGlNUH4ryPdtdk2TbD9h6d+dkHflCnusTsQTIX9+Nht+Y7OIL7PXcsF",
    "ey1kPM18X4vf56fHOTHp8Mzd6vLZZzKsyPZae0mOJyMSY+ZD/3Up+eKngB7vO9n2DOfHDezPqMb",
    "wmPdY3Z8NfrPdleqwV9FhL5x/Oj32ZjA4NLJ3fiVvdXszXFsMJI3GJPGX6LBb0WR9r89Vm+vjBu",
    "xa7zIt/rsr3G0/55wYJtwZz4o+HmT8ePXyh/FGsv2GTdefCH48Oc38czYk/Nq5Fjv0r/LFRqF8b",
    "6dncMbU7MDgun/RvXcMc7Yoj/+PmArfwAupXZR87LW6ZPLt983XiZtXPdX/+b//9ZX2QFH6/Psd",
    "6FJ/TntPMm16PHeeNt/L1p+P3BLWQ8aDkpDL/egdop+zb/0h8/+Vov9G5UcPaL3+h/O2dLUH5UL",
    "PsmHX08b6y7wXHXymguvz893n0k7K5rup5yUG7+eHdGfrS33nVUCM=",
    ""
  };

  static char newstr [1705] = "";
  newstr[0] = '\0';
  for (i = 0; i < 24; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c3_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c3_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(3107034019U));
  ssSetChecksum1(S,(3685706050U));
  ssSetChecksum2(S,(1548232645U));
  ssSetChecksum3(S,(207958099U));
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
