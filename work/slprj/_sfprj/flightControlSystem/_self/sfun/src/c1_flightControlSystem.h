#ifndef __c1_flightControlSystem_h__
#define __c1_flightControlSystem_h__

/* Forward Declarations */
#ifndef typedef_c1_cell_1
#define typedef_c1_cell_1

typedef struct c1_tag_lfyg79q6Kpk0jaJgYJuk8C c1_cell_1;

#endif                                 /* typedef_c1_cell_1 */

#ifndef typedef_c1_cell_wrap_2
#define typedef_c1_cell_wrap_2

typedef struct c1_tag_uwJsGEKtvfiUxcdf0z0AYH c1_cell_wrap_2;

#endif                                 /* typedef_c1_cell_wrap_2 */

#ifndef typedef_c1_s_WSTEAPgNJmllMDXoFTifcF
#define typedef_c1_s_WSTEAPgNJmllMDXoFTifcF

typedef struct c1_tag_WSTEAPgNJmllMDXoFTifcF c1_s_WSTEAPgNJmllMDXoFTifcF;

#endif                                 /* typedef_c1_s_WSTEAPgNJmllMDXoFTifcF */

#ifndef typedef_c1_s_MY3jsqmREaTzOC09vCGedD
#define typedef_c1_s_MY3jsqmREaTzOC09vCGedD

typedef struct c1_tag_MY3jsqmREaTzOC09vCGedD c1_s_MY3jsqmREaTzOC09vCGedD;

#endif                                 /* typedef_c1_s_MY3jsqmREaTzOC09vCGedD */

/* Type Definitions */
#ifndef struct_c1_tag_lfyg79q6Kpk0jaJgYJuk8C
#define struct_c1_tag_lfyg79q6Kpk0jaJgYJuk8C

struct c1_tag_lfyg79q6Kpk0jaJgYJuk8C
{
  char_T f1[5];
  char_T f2[6];
  char_T f3[6];
  char_T f4[6];
};

#endif                                 /* struct_c1_tag_lfyg79q6Kpk0jaJgYJuk8C */

#ifndef typedef_c1_cell_1
#define typedef_c1_cell_1

typedef struct c1_tag_lfyg79q6Kpk0jaJgYJuk8C c1_cell_1;

#endif                                 /* typedef_c1_cell_1 */

#ifndef struct_c1_tag_uwJsGEKtvfiUxcdf0z0AYH
#define struct_c1_tag_uwJsGEKtvfiUxcdf0z0AYH

struct c1_tag_uwJsGEKtvfiUxcdf0z0AYH
{
  char_T f1[4];
};

#endif                                 /* struct_c1_tag_uwJsGEKtvfiUxcdf0z0AYH */

#ifndef typedef_c1_cell_wrap_2
#define typedef_c1_cell_wrap_2

typedef struct c1_tag_uwJsGEKtvfiUxcdf0z0AYH c1_cell_wrap_2;

#endif                                 /* typedef_c1_cell_wrap_2 */

#ifndef struct_c1_tag_WSTEAPgNJmllMDXoFTifcF
#define struct_c1_tag_WSTEAPgNJmllMDXoFTifcF

struct c1_tag_WSTEAPgNJmllMDXoFTifcF
{
  c1_cell_1 _data;
};

#endif                                 /* struct_c1_tag_WSTEAPgNJmllMDXoFTifcF */

#ifndef typedef_c1_s_WSTEAPgNJmllMDXoFTifcF
#define typedef_c1_s_WSTEAPgNJmllMDXoFTifcF

typedef struct c1_tag_WSTEAPgNJmllMDXoFTifcF c1_s_WSTEAPgNJmllMDXoFTifcF;

#endif                                 /* typedef_c1_s_WSTEAPgNJmllMDXoFTifcF */

#ifndef struct_c1_tag_MY3jsqmREaTzOC09vCGedD
#define struct_c1_tag_MY3jsqmREaTzOC09vCGedD

struct c1_tag_MY3jsqmREaTzOC09vCGedD
{
  c1_cell_wrap_2 _data;
};

#endif                                 /* struct_c1_tag_MY3jsqmREaTzOC09vCGedD */

#ifndef typedef_c1_s_MY3jsqmREaTzOC09vCGedD
#define typedef_c1_s_MY3jsqmREaTzOC09vCGedD

typedef struct c1_tag_MY3jsqmREaTzOC09vCGedD c1_s_MY3jsqmREaTzOC09vCGedD;

#endif                                 /* typedef_c1_s_MY3jsqmREaTzOC09vCGedD */

#ifndef typedef_SFc1_flightControlSystemInstanceStruct
#define typedef_SFc1_flightControlSystemInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_flightControlSystem;
  uint8_T c1_JITStateAnimation[1];
  uint8_T c1_JITTransitionAnimation[1];
  void *c1_RuntimeVar;
  int32_T c1_IsDebuggerActive;
  int32_T c1_IsSequenceViewerPresent;
  int32_T c1_SequenceViewerOptimization;
  int32_T c1_IsHeatMapPresent;
  int32_T c1_IsStmtByStmtMode;
  uint32_T c1_mlFcnLineNumber;
  uint32_T c1_numFcnVars;
  real_T c1_hsv[57600];
  real_T c1_outputImage[57600];
  real_T c1_H[19200];
  real_T c1_S[19200];
  real_T c1_V[19200];
  uint8_T c1_rgb_im[57600];
  uint8_T c1_X[57600];
  uint8_T c1_R[19200];
  uint8_T c1_G[19200];
  uint8_T c1_B[19200];
  real_T c1_y[57600];
  real_T c1_dv[57600];
  real_T c1_u[57600];
  real_T c1_b_y[19200];
  CovrtStateflowInstance *c1_covrtInstance;
  void *c1_fEmlrtCtx;
  uint8_T (*c1_b_R)[19200];
  boolean_T (*c1_mask)[19200];
  uint8_T (*c1_b_G)[19200];
  uint8_T (*c1_b_B)[19200];
} SFc1_flightControlSystemInstanceStruct;

#endif                                 /* typedef_SFc1_flightControlSystemInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[]);
extern void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
