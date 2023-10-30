/* Include files */

#include "flightControlSystem_sfun.h"
#include "c1_flightControlSystem.h"
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
static void *c1_fcnDataPtrs[15];
static const char_T *c1_dataNames[15];
static uint32_T c1_ssIds[15];
static uint32_T c1_statuses[15];
static void *c1_outMexFcns[15];
static void *c1_inMexFcns[15];
static emlrtRSInfo c1_emlrtRSI = { 51, /* lineNo */
  "rgb2hsv",                           /* fcnName */
  "/home/fuda/Installed/MATLAB/R2023b/toolbox/eml/lib/matlab/images/rgb2hsv.m"/* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 4,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2820"          /* pathName */
};

/* Function Declarations */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st);
static void initSimStructsc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initSubchartIOPointersc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T c1_c_y[19200]);
static void c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T c1_c_y[19200]);
static uint8_T c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_slStringInitializeDynamicBuffers
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *c1_sf_marshallOut_matrix120x160_uint8_T(void
  *chartInstanceVoid, void *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  uint8_T c1_c_y[19200]);
static void c1_sf_marshallIn_matrix120x160_uint8_T(void *chartInstanceVoid,
  const mxArray *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_sf_marshallOut_matrix120x160_boolean_T(void
  *chartInstanceVoid, void *c1_inData);
static void c1_sf_marshallIn_matrix120x160_boolean_T(void *chartInstanceVoid,
  const mxArray *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_sf_marshallOut_matrix120x160x3_uint8_T(void
  *chartInstanceVoid, void *c1_inData);
static void c1_f_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  uint8_T c1_c_y[57600]);
static void c1_sf_marshallIn_matrix120x160x3_uint8_T(void *chartInstanceVoid,
  const mxArray *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_sf_marshallOut_matrix120x160x3_real_T(void
  *chartInstanceVoid, void *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_c_y[57600]);
static void c1_sf_marshallIn_matrix120x160x3_real_T(void *chartInstanceVoid,
  const mxArray *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_sf_marshallOut_matrix120x160_real_T(void
  *chartInstanceVoid, void *c1_inData);
static void c1_h_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_c_y[19200]);
static void c1_sf_marshallIn_matrix120x160_real_T(void *chartInstanceVoid, const
  mxArray *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_sf_marshallOut_real_T(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_i_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn_real_T(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_chart_data_browse_helper(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig);
static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerReportChartEnableDisable(chartInstance->c1_RuntimeVar, &_sfTime_, 13);
  sf_is_first_init_cond(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_doneDoubleBufferReInit = false;
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, chartInstance->c1_JITStateAnimation,
                        chartInstance->c1_JITTransitionAnimation);
  setDataBrowseFcn(chartInstance->S, (void *)&c1_chart_data_browse_helper);
  chartInstance->c1_RuntimeVar = sfListenerInitializeUsingSimStruct
    (chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c1_RuntimeVar,
    &chartInstance->c1_IsDebuggerActive,
    &chartInstance->c1_IsSequenceViewerPresent, 1, 0,
    &chartInstance->c1_mlFcnLineNumber, &chartInstance->c1_IsHeatMapPresent, 0);
  chartInstance->c1_SequenceViewerOptimization = 1;
  sfListenerInitializeIsStmtByStmtModeVar(chartInstance->c1_RuntimeVar,
    &chartInstance->c1_IsStmtByStmtMode);
  sfListenerInitializeRuntimeFcnVarsJitOff(chartInstance->c1_RuntimeVar,
    &chartInstance->c1_numFcnVars, c1_dataNames, c1_ssIds, c1_fcnDataPtrs,
    c1_outMexFcns, c1_inMexFcns, c1_statuses);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    47U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 476);
}

static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerTerminate(chartInstance->c1_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  sfListenerReportChartEnableDisable(chartInstance->c1_RuntimeVar, &_sfTime_, 13);
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerReportChartEnableDisable(chartInstance->c1_RuntimeVar, &_sfTime_, 14);
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  int32_T c1_b_j;
  int32_T c1_c_j;
  int32_T c1_d_j;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_iy;
  int32_T c1_j;
  uint8_T c1_varargin_1[19200];
  uint8_T c1_varargin_2[19200];
  uint8_T c1_varargin_3[19200];
  boolean_T c1_b_mask[19200];
  boolean_T c1_b_mask1[19200];
  boolean_T c1_b_mask2[19200];
  boolean_T c1_mask1[19200];
  boolean_T c1_mask2[19200];
  boolean_T c1_s_tresh[19200];
  boolean_T c1_v_tresh[19200];
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 2U, (real_T)
                      (*chartInstance->c1_b_B)[c1_i]);
  }

  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, (real_T)
                      (*chartInstance->c1_b_G)[c1_i1]);
  }

  for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                      (*chartInstance->c1_b_R)[c1_i2]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  chartInstance->c1_sfEvent = CALL_EVENT;
  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportStartingSection(chartInstance->c1_RuntimeVar, 0, 1);
  }

  for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
    chartInstance->c1_R[c1_i3] = (*chartInstance->c1_b_R)[c1_i3];
  }

  for (c1_i4 = 0; c1_i4 < 19200; c1_i4++) {
    chartInstance->c1_G[c1_i4] = (*chartInstance->c1_b_G)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 19200; c1_i5++) {
    chartInstance->c1_B[c1_i5] = (*chartInstance->c1_b_B)[c1_i5];
  }

  chartInstance->c1_numFcnVars = 15U;
  c1_fcnDataPtrs[0] = (void *)&chartInstance->c1_R;
  c1_fcnDataPtrs[1] = (void *)&chartInstance->c1_G;
  c1_fcnDataPtrs[2] = (void *)&chartInstance->c1_B;
  c1_fcnDataPtrs[3] = (void *)&c1_b_mask;
  c1_fcnDataPtrs[4] = (void *)&chartInstance->c1_rgb_im;
  c1_fcnDataPtrs[5] = (void *)&chartInstance->c1_hsv;
  c1_fcnDataPtrs[6] = (void *)&chartInstance->c1_H;
  c1_fcnDataPtrs[7] = (void *)&chartInstance->c1_S;
  c1_fcnDataPtrs[8] = (void *)&chartInstance->c1_V;
  c1_fcnDataPtrs[9] = (void *)&c1_s_tresh;
  c1_fcnDataPtrs[10] = (void *)&c1_v_tresh;
  c1_fcnDataPtrs[11] = (void *)&c1_mask1;
  c1_fcnDataPtrs[12] = (void *)&c1_mask2;
  c1_fcnDataPtrs[13] = (void *)&c1_nargin;
  c1_fcnDataPtrs[14] = (void *)&c1_nargout;
  c1_statuses[0] = 0U;
  c1_statuses[1] = 0U;
  c1_statuses[2] = 0U;
  c1_statuses[3] = 0U;
  c1_statuses[4] = 0U;
  c1_statuses[5] = 0U;
  c1_statuses[6] = 0U;
  c1_statuses[7] = 0U;
  c1_statuses[8] = 0U;
  c1_statuses[9] = 0U;
  c1_statuses[10] = 0U;
  c1_statuses[11] = 0U;
  c1_statuses[12] = 0U;
  c1_statuses[13] = 0U;
  c1_statuses[14] = 0U;
  c1_inMexFcns[0] = (void *)&c1_sf_marshallIn_matrix120x160_uint8_T;
  c1_inMexFcns[1] = (void *)&c1_sf_marshallIn_matrix120x160_uint8_T;
  c1_inMexFcns[2] = (void *)&c1_sf_marshallIn_matrix120x160_uint8_T;
  c1_inMexFcns[3] = (void *)&c1_sf_marshallIn_matrix120x160_boolean_T;
  c1_inMexFcns[4] = (void *)&c1_sf_marshallIn_matrix120x160x3_uint8_T;
  c1_inMexFcns[5] = (void *)&c1_sf_marshallIn_matrix120x160x3_real_T;
  c1_inMexFcns[6] = (void *)&c1_sf_marshallIn_matrix120x160_real_T;
  c1_inMexFcns[7] = (void *)&c1_sf_marshallIn_matrix120x160_real_T;
  c1_inMexFcns[8] = (void *)&c1_sf_marshallIn_matrix120x160_real_T;
  c1_inMexFcns[9] = (void *)&c1_sf_marshallIn_matrix120x160_boolean_T;
  c1_inMexFcns[10] = (void *)&c1_sf_marshallIn_matrix120x160_boolean_T;
  c1_inMexFcns[11] = (void *)&c1_sf_marshallIn_matrix120x160_boolean_T;
  c1_inMexFcns[12] = (void *)&c1_sf_marshallIn_matrix120x160_boolean_T;
  c1_inMexFcns[13] = (void *)&c1_sf_marshallIn_real_T;
  c1_inMexFcns[14] = (void *)&c1_sf_marshallIn_real_T;
  c1_outMexFcns[0] = (void *)&c1_sf_marshallOut_matrix120x160_uint8_T;
  c1_outMexFcns[1] = (void *)&c1_sf_marshallOut_matrix120x160_uint8_T;
  c1_outMexFcns[2] = (void *)&c1_sf_marshallOut_matrix120x160_uint8_T;
  c1_outMexFcns[3] = (void *)&c1_sf_marshallOut_matrix120x160_boolean_T;
  c1_outMexFcns[4] = (void *)&c1_sf_marshallOut_matrix120x160x3_uint8_T;
  c1_outMexFcns[5] = (void *)&c1_sf_marshallOut_matrix120x160x3_real_T;
  c1_outMexFcns[6] = (void *)&c1_sf_marshallOut_matrix120x160_real_T;
  c1_outMexFcns[7] = (void *)&c1_sf_marshallOut_matrix120x160_real_T;
  c1_outMexFcns[8] = (void *)&c1_sf_marshallOut_matrix120x160_real_T;
  c1_outMexFcns[9] = (void *)&c1_sf_marshallOut_matrix120x160_boolean_T;
  c1_outMexFcns[10] = (void *)&c1_sf_marshallOut_matrix120x160_boolean_T;
  c1_outMexFcns[11] = (void *)&c1_sf_marshallOut_matrix120x160_boolean_T;
  c1_outMexFcns[12] = (void *)&c1_sf_marshallOut_matrix120x160_boolean_T;
  c1_outMexFcns[13] = (void *)&c1_sf_marshallOut_real_T;
  c1_outMexFcns[14] = (void *)&c1_sf_marshallOut_real_T;
  c1_ssIds[0] = 0U;
  c1_ssIds[1] = 0U;
  c1_ssIds[2] = 0U;
  c1_ssIds[3] = 0U;
  c1_ssIds[4] = 0U;
  c1_ssIds[5] = 0U;
  c1_ssIds[6] = 0U;
  c1_ssIds[7] = 0U;
  c1_ssIds[8] = 0U;
  c1_ssIds[9] = 0U;
  c1_ssIds[10] = 0U;
  c1_ssIds[11] = 0U;
  c1_ssIds[12] = 0U;
  c1_ssIds[13] = 0U;
  c1_ssIds[14] = 0U;
  c1_dataNames[0] = "R";
  c1_dataNames[1] = "G";
  c1_dataNames[2] = "B";
  c1_dataNames[3] = "mask";
  c1_dataNames[4] = "rgb_im";
  c1_dataNames[5] = "hsv";
  c1_dataNames[6] = "H";
  c1_dataNames[7] = "S";
  c1_dataNames[8] = "V";
  c1_dataNames[9] = "s_tresh";
  c1_dataNames[10] = "v_tresh";
  c1_dataNames[11] = "mask1";
  c1_dataNames[12] = "mask2";
  c1_dataNames[13] = "nargin";
  c1_dataNames[14] = "nargout";
  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportStartingSection(chartInstance->c1_RuntimeVar, 0, 4);
  }

  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 2);
  }

  for (c1_i6 = 0; c1_i6 < 19200; c1_i6++) {
    c1_varargin_1[c1_i6] = chartInstance->c1_R[c1_i6];
  }

  for (c1_i7 = 0; c1_i7 < 19200; c1_i7++) {
    c1_varargin_2[c1_i7] = chartInstance->c1_G[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 19200; c1_i8++) {
    c1_varargin_3[c1_i8] = chartInstance->c1_B[c1_i8];
  }

  c1_iy = -1;
  for (c1_j = 0; c1_j < 19200; c1_j++) {
    c1_c_j = c1_j;
    c1_iy++;
    chartInstance->c1_rgb_im[c1_iy] = c1_varargin_1[c1_c_j];
  }

  for (c1_b_j = 0; c1_b_j < 19200; c1_b_j++) {
    c1_c_j = c1_b_j;
    c1_iy++;
    chartInstance->c1_rgb_im[c1_iy] = c1_varargin_2[c1_c_j];
  }

  for (c1_d_j = 0; c1_d_j < 19200; c1_d_j++) {
    c1_c_j = c1_d_j;
    c1_iy++;
    chartInstance->c1_rgb_im[c1_iy] = c1_varargin_3[c1_c_j];
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 4);
  }

  for (c1_i9 = 0; c1_i9 < 57600; c1_i9++) {
    chartInstance->c1_X[c1_i9] = chartInstance->c1_rgb_im[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 57600; c1_i10++) {
    chartInstance->c1_outputImage[c1_i10] = chartInstance->c1_hsv[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 57600; c1_i11++) {
    chartInstance->c1_hsv[c1_i11] = chartInstance->c1_outputImage[c1_i11];
  }

  rgb2hsv_tbb_uint8(&chartInstance->c1_X[0], 19200.0, &chartInstance->c1_hsv[0],
                    true);
  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 5);
  }

  c1_i12 = 0;
  for (c1_i13 = 0; c1_i13 < 160; c1_i13++) {
    for (c1_i14 = 0; c1_i14 < 120; c1_i14++) {
      chartInstance->c1_H[c1_i14 + c1_i12] = chartInstance->c1_hsv[c1_i14 +
        c1_i12];
    }

    c1_i12 += 120;
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 6);
  }

  c1_i15 = 0;
  for (c1_i16 = 0; c1_i16 < 160; c1_i16++) {
    for (c1_i17 = 0; c1_i17 < 120; c1_i17++) {
      chartInstance->c1_S[c1_i17 + c1_i15] = chartInstance->c1_hsv[(c1_i17 +
        c1_i15) + 19200];
    }

    c1_i15 += 120;
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 7);
  }

  c1_i18 = 0;
  for (c1_i19 = 0; c1_i19 < 160; c1_i19++) {
    for (c1_i20 = 0; c1_i20 < 120; c1_i20++) {
      chartInstance->c1_V[c1_i20 + c1_i18] = chartInstance->c1_hsv[(c1_i20 +
        c1_i18) + 38400];
    }

    c1_i18 += 120;
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 9);
  }

  for (c1_i21 = 0; c1_i21 < 19200; c1_i21++) {
    c1_s_tresh[c1_i21] = (chartInstance->c1_S[c1_i21] > 0.4);
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 10);
  }

  for (c1_i22 = 0; c1_i22 < 19200; c1_i22++) {
    c1_v_tresh[c1_i22] = (chartInstance->c1_V[c1_i22] > 0.2);
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 13);
  }

  for (c1_i23 = 0; c1_i23 < 19200; c1_i23++) {
    c1_b_mask1[c1_i23] = (chartInstance->c1_H[c1_i23] >= 0.0);
  }

  for (c1_i24 = 0; c1_i24 < 19200; c1_i24++) {
    c1_b_mask2[c1_i24] = (chartInstance->c1_H[c1_i24] <= 0.055555555555555552);
  }

  for (c1_i25 = 0; c1_i25 < 19200; c1_i25++) {
    c1_mask1[c1_i25] = (c1_b_mask1[c1_i25] && c1_b_mask2[c1_i25]);
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 14);
  }

  for (c1_i26 = 0; c1_i26 < 19200; c1_i26++) {
    c1_b_mask1[c1_i26] = (chartInstance->c1_H[c1_i26] >= 0.63888888888888884);
  }

  for (c1_i27 = 0; c1_i27 < 19200; c1_i27++) {
    c1_b_mask2[c1_i27] = (chartInstance->c1_H[c1_i27] <= 1.0);
  }

  for (c1_i28 = 0; c1_i28 < 19200; c1_i28++) {
    c1_mask2[c1_i28] = (c1_b_mask1[c1_i28] && c1_b_mask2[c1_i28]);
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 15);
  }

  for (c1_i29 = 0; c1_i29 < 19200; c1_i29++) {
    c1_b_mask1[c1_i29] = c1_mask1[c1_i29];
  }

  for (c1_i30 = 0; c1_i30 < 19200; c1_i30++) {
    c1_b_mask2[c1_i30] = c1_mask2[c1_i30];
  }

  for (c1_i31 = 0; c1_i31 < 19200; c1_i31++) {
    c1_b_mask[c1_i31] = (c1_b_mask1[c1_i31] || c1_b_mask2[c1_i31]);
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 23);
  }

  for (c1_i32 = 0; c1_i32 < 19200; c1_i32++) {
    (*chartInstance->c1_mask)[c1_i32] = c1_b_mask[c1_i32];
  }

  for (c1_i33 = 0; c1_i33 < 19200; c1_i33++) {
    c1_b_mask1[c1_i33] = c1_s_tresh[c1_i33];
  }

  for (c1_i34 = 0; c1_i34 < 19200; c1_i34++) {
    (*chartInstance->c1_mask)[c1_i34] = ((*chartInstance->c1_mask)[c1_i34] &&
      c1_b_mask1[c1_i34]);
  }

  for (c1_i35 = 0; c1_i35 < 19200; c1_i35++) {
    c1_b_mask1[c1_i35] = c1_v_tresh[c1_i35];
  }

  for (c1_i36 = 0; c1_i36 < 19200; c1_i36++) {
    c1_b_mask[c1_i36] = ((*chartInstance->c1_mask)[c1_i36] && c1_b_mask1[c1_i36]);
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, 24);
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c1_RuntimeVar, 0, -24);
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportEndingSection(chartInstance->c1_RuntimeVar, 0, 4);
  }

  for (c1_i37 = 0; c1_i37 < 19200; c1_i37++) {
    (*chartInstance->c1_mask)[c1_i37] = c1_b_mask[c1_i37];
  }

  if ((chartInstance->c1_IsDebuggerActive == 1) ||
      (chartInstance->c1_IsSequenceViewerPresent == 1) ||
      (chartInstance->c1_IsHeatMapPresent == 1)) {
    sfListenerReportEndingSection(chartInstance->c1_RuntimeVar, 0, 1);
  }

  c1_do_animation_call_c1_flightControlSystem(chartInstance);
  for (c1_i38 = 0; c1_i38 < 19200; c1_i38++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 3U, (real_T)
                      (*chartInstance->c1_mask)[c1_i38]);
  }
}

static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_st;
  c1_st = NULL;
  c1_st = NULL;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_createcellmatrix(2, 1), false);
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", *chartInstance->c1_mask, 11, 0U, 1U,
    0U, 2, 120, 160), false);
  sf_mex_setcell(c1_c_y, 0, c1_d_y);
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y",
    &chartInstance->c1_is_active_c1_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_c_y, 1, c1_e_y);
  sf_mex_assign(&c1_st, c1_c_y, false);
  return c1_st;
}

static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_b_u;
  int32_T c1_i;
  boolean_T c1_bv[19200];
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_b_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 0)),
                      "mask", c1_bv);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    (*chartInstance->c1_mask)[c1_i] = c1_bv[c1_i];
  }

  chartInstance->c1_is_active_c1_flightControlSystem = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 1)),
     "is_active_c1_flightControlSystem");
  sf_mex_destroy(&c1_b_u);
  sf_mex_destroy(&c1_st);
}

static void initSimStructsc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSubchartIOPointersc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T c1_c_y[19200])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId,
                        c1_c_y);
  sf_mex_destroy(&c1_nullptr);
}

static void c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T c1_c_y[19200])
{
  int32_T c1_i;
  boolean_T c1_bv[19200];
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_bv, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_c_y[c1_i] = c1_bv[c1_i];
  }

  sf_mex_destroy(&c1_b_u);
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_c_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_c_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr),
    &c1_thisId);
  sf_mex_destroy(&c1_nullptr);
  return c1_c_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_c_u;
  uint8_T c1_c_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_c_u, 1, 3, 0U, 0, 0U, 0);
  c1_c_y = c1_c_u;
  sf_mex_destroy(&c1_b_u);
  return c1_c_y;
}

static void c1_slStringInitializeDynamicBuffers
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c1_sf_marshallOut_matrix120x160_uint8_T(void
  *chartInstanceVoid, void *c1_inData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  uint8_T c1_b_u[19200];
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i = 0;
  for (c1_i1 = 0; c1_i1 < 160; c1_i1++) {
    for (c1_i2 = 0; c1_i2 < 120; c1_i2++) {
      c1_b_u[c1_i2 + c1_i] = (*(uint8_T (*)[19200])c1_inData)[c1_i2 + c1_i];
    }

    c1_i += 120;
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 3, 0U, 1U, 0U, 2, 120, 160),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_c_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  uint8_T c1_c_y[19200])
{
  int32_T c1_i;
  uint8_T c1_uv[19200];
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_uv, 1, 3, 0U, 1, 0U, 2, 120,
                160);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_c_y[c1_i] = c1_uv[c1_i];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_sf_marshallIn_matrix120x160_uint8_T(void *chartInstanceVoid,
  const mxArray *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  emlrtMsgIdentifier c1_thisId;
  const mxArray *c1_nullptr;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  const char_T *c1_identifier;
  uint8_T c1_c_y[19200];
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_nullptr = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId,
                        c1_c_y);
  sf_mex_destroy(&c1_nullptr);
  c1_i = 0;
  for (c1_i1 = 0; c1_i1 < 160; c1_i1++) {
    for (c1_i2 = 0; c1_i2 < 120; c1_i2++) {
      (*(uint8_T (*)[19200])c1_outData)[c1_i2 + c1_i] = c1_c_y[c1_i2 + c1_i];
    }

    c1_i += 120;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_sf_marshallOut_matrix120x160_boolean_T(void
  *chartInstanceVoid, void *c1_inData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  boolean_T c1_b_u[19200];
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i = 0;
  for (c1_i1 = 0; c1_i1 < 160; c1_i1++) {
    for (c1_i2 = 0; c1_i2 < 120; c1_i2++) {
      c1_b_u[c1_i2 + c1_i] = (*(boolean_T (*)[19200])c1_inData)[c1_i2 + c1_i];
    }

    c1_i += 120;
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 11, 0U, 1U, 0U, 2, 120, 160),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_c_y, false);
  return c1_mxArrayOutData;
}

static void c1_sf_marshallIn_matrix120x160_boolean_T(void *chartInstanceVoid,
  const mxArray *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  emlrtMsgIdentifier c1_thisId;
  const mxArray *c1_nullptr;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  const char_T *c1_identifier;
  boolean_T c1_c_y[19200];
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_nullptr = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId,
                        c1_c_y);
  sf_mex_destroy(&c1_nullptr);
  c1_i = 0;
  for (c1_i1 = 0; c1_i1 < 160; c1_i1++) {
    for (c1_i2 = 0; c1_i2 < 120; c1_i2++) {
      (*(boolean_T (*)[19200])c1_outData)[c1_i2 + c1_i] = c1_c_y[c1_i2 + c1_i];
    }

    c1_i += 120;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_sf_marshallOut_matrix120x160x3_uint8_T(void
  *chartInstanceVoid, void *c1_inData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  uint8_T c1_b_u[57600];
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i = 0;
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_i2 = 0;
    for (c1_i3 = 0; c1_i3 < 160; c1_i3++) {
      for (c1_i4 = 0; c1_i4 < 120; c1_i4++) {
        c1_b_u[(c1_i4 + c1_i2) + c1_i] = (*(uint8_T (*)[57600])c1_inData)[(c1_i4
          + c1_i2) + c1_i];
      }

      c1_i2 += 120;
    }

    c1_i += 19200;
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 3, 0U, 1U, 0U, 3, 120, 160,
    3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_c_y, false);
  return c1_mxArrayOutData;
}

static void c1_f_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  uint8_T c1_c_y[57600])
{
  int32_T c1_i;
  uint8_T c1_uv[57600];
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_uv, 1, 3, 0U, 1, 0U, 3, 120,
                160, 3);
  for (c1_i = 0; c1_i < 57600; c1_i++) {
    c1_c_y[c1_i] = c1_uv[c1_i];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_sf_marshallIn_matrix120x160x3_uint8_T(void *chartInstanceVoid,
  const mxArray *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  emlrtMsgIdentifier c1_thisId;
  const mxArray *c1_nullptr;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  const char_T *c1_identifier;
  uint8_T c1_c_y[57600];
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_nullptr = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId,
                        c1_c_y);
  sf_mex_destroy(&c1_nullptr);
  c1_i = 0;
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_i2 = 0;
    for (c1_i3 = 0; c1_i3 < 160; c1_i3++) {
      for (c1_i4 = 0; c1_i4 < 120; c1_i4++) {
        (*(uint8_T (*)[57600])c1_outData)[(c1_i4 + c1_i2) + c1_i] = c1_c_y
          [(c1_i4 + c1_i2) + c1_i];
      }

      c1_i2 += 120;
    }

    c1_i += 19200;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_sf_marshallOut_matrix120x160x3_real_T(void
  *chartInstanceVoid, void *c1_inData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i = 0;
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_i2 = 0;
    for (c1_i3 = 0; c1_i3 < 160; c1_i3++) {
      for (c1_i4 = 0; c1_i4 < 120; c1_i4++) {
        chartInstance->c1_u[(c1_i4 + c1_i2) + c1_i] = (*(real_T (*)[57600])
          c1_inData)[(c1_i4 + c1_i2) + c1_i];
      }

      c1_i2 += 120;
    }

    c1_i += 19200;
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", chartInstance->c1_u, 0, 0U, 1U, 0U,
    3, 120, 160, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_c_y, false);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_c_y[57600])
{
  int32_T c1_i;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), chartInstance->c1_dv, 1, 0, 0U,
                1, 0U, 3, 120, 160, 3);
  for (c1_i = 0; c1_i < 57600; c1_i++) {
    c1_c_y[c1_i] = chartInstance->c1_dv[c1_i];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_sf_marshallIn_matrix120x160x3_real_T(void *chartInstanceVoid,
  const mxArray *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  emlrtMsgIdentifier c1_thisId;
  const mxArray *c1_nullptr;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  const char_T *c1_identifier;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_nullptr = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId,
                        chartInstance->c1_y);
  sf_mex_destroy(&c1_nullptr);
  c1_i = 0;
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_i2 = 0;
    for (c1_i3 = 0; c1_i3 < 160; c1_i3++) {
      for (c1_i4 = 0; c1_i4 < 120; c1_i4++) {
        (*(real_T (*)[57600])c1_outData)[(c1_i4 + c1_i2) + c1_i] =
          chartInstance->c1_y[(c1_i4 + c1_i2) + c1_i];
      }

      c1_i2 += 120;
    }

    c1_i += 19200;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_sf_marshallOut_matrix120x160_real_T(void
  *chartInstanceVoid, void *c1_inData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_mxArrayOutData;
  real_T c1_b_u[19200];
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i = 0;
  for (c1_i1 = 0; c1_i1 < 160; c1_i1++) {
    for (c1_i2 = 0; c1_i2 < 120; c1_i2++) {
      c1_b_u[c1_i2 + c1_i] = (*(real_T (*)[19200])c1_inData)[c1_i2 + c1_i];
    }

    c1_i += 120;
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 2, 120, 160),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_c_y, false);
  return c1_mxArrayOutData;
}

static void c1_h_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_c_y[19200])
{
  real_T c1_b_dv[19200];
  int32_T c1_i;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_b_dv, 1, 0, 0U, 1, 0U, 2,
                120, 160);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_c_y[c1_i] = c1_b_dv[c1_i];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_sf_marshallIn_matrix120x160_real_T(void *chartInstanceVoid, const
  mxArray *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  emlrtMsgIdentifier c1_thisId;
  const mxArray *c1_nullptr;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  const char_T *c1_identifier;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_nullptr = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId,
                        chartInstance->c1_b_y);
  sf_mex_destroy(&c1_nullptr);
  c1_i = 0;
  for (c1_i1 = 0; c1_i1 < 160; c1_i1++) {
    for (c1_i2 = 0; c1_i2 < 120; c1_i2++) {
      (*(real_T (*)[19200])c1_outData)[c1_i2 + c1_i] = chartInstance->
        c1_b_y[c1_i2 + c1_i];
    }

    c1_i += 120;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_sf_marshallOut_real_T(void *chartInstanceVoid, void
  *c1_inData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_mxArrayOutData;
  real_T c1_b_u;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(real_T *)c1_inData;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_c_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_i_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_c_y;
  real_T c1_d;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_d, 1, 0, 0U, 0, 0U, 0);
  c1_c_y = c1_d;
  sf_mex_destroy(&c1_b_u);
  return c1_c_y;
}

static void c1_sf_marshallIn_real_T(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  emlrtMsgIdentifier c1_thisId;
  const mxArray *c1_nullptr;
  real_T c1_c_y;
  const char_T *c1_identifier;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c1_nullptr = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_c_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr),
    &c1_thisId);
  sf_mex_destroy(&c1_nullptr);
  *(real_T *)c1_outData = c1_c_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_chart_data_browse_helper(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig)
{
  *c1_mxData = NULL;
  *c1_mxData = NULL;
  *c1_isValueTooBig = 0U;
  switch (c1_ssIdNumber) {
   case 4U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_b_R, 3,
      0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 5U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_mask, 11,
      0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 10U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_b_G, 3,
      0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 11U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_b_B, 3,
      0U, 1U, 0U, 2, 120, 160), false);
    break;
  }
}

static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_b_R = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_mask = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_b_G = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_b_B = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1105102032U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2778332869U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4153152092U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3593854079U);
}

mxArray *sf_c1_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2hsvBuildable"));
  return(mxcell3p);
}

mxArray *sf_c1_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rgb2hsv_tbb_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lmw6GdB0i8A5OUmFmfzQfmU2a/gQJ"
    "l+iP0BBNyvgOJ+CD+zOD4xuSSzLDU+2TA+LSczPaPEOT+vpCg/J7iyuCQ1F+Y/AISuHe4="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sI2vnTQWrzlTMBOAMvWDlwD";
}

static void sf_opaque_initialize_c1_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_flightControlSystem(void *chartInstanceVar)
{
  enable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_flightControlSystem(void *chartInstanceVar)
{
  disable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc1_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c1_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWE1vG0UYnk3diFYQVQgBBwQ5ckGicOkBQRJ/gKWYGNZpJC7RZPe1d/Ds7HY+HLtXDnDjwJE",
    "rh/4UfgI/g2OPvLNeu+7G2DNrqYSutNnM2s8877zzfjxjEnR7BK8DvD9+n5B9fL6B9x6ZX3fLcb",
    "Byz983yBfl+M/7hERZDCMQoRkO2ZT4XcKkfSppqoj/JWgK34PKuNEsE10xzNyxTAxBgohwgjyT2",
    "otXsdRwJsYdIyLLrC4SFiVhkhken+CEND4TfPZvvLnRfWRsMQmR7gDEOpGZGSUdTkebvSD1dTOB",
    "aKxM6u0rBTo0uV2q6hmuWc6hPYWoK5Sm6AW1Zb2hphqaeurnZLteFS7QWZpzRoW7rxOqQsgxOjS",
    "c5zH+PTMavefIi3xXTFCdSUZ5O+XNhEpXbJ+jnT0Ma+7tZ53qFlyZ0YiJkfWuNCkIXD/GiYOvhs",
    "1sApKO4Ez48UZ2de1pscHLuHTEapbCYyqPI4wDBbFfDmIAq5Di1sIAp/HCgqBXHLpqINkE98i3b",
    "nRtKtWqGyadR5KqhS142xPcVVWTtxOJJuVc+WEHWX4KE+AFf4tqWgM75/cAK8XiQYbRYTPXM/uN",
    "YE8MlNhmJmLmHpWTCqpoEt9iwXeAs9SmAcTo5qXpy4m25ZFROkubmPqt01NHvpvYrtAghzQC53o",
    "tKVOABhdx5ckbM2UTCdHoJV2s0nmGeQ7WghI1NKJ1nckx+ti3Mbzwlc0EPzTEI2iBhqLItTG6H1",
    "NuHG1OFVZlGx7nCqusHy9ibf7UAkc0SiC2PZBx6GGdxQlct1jZ9nmMq50wPWuBiiTLXTPJYEHH5",
    "me9NJjlcC7GIrsWHZmlYaliNsQVAFYNKgW2shNspXLWQePdrJbwZFBUd1/BYP1MNadXNja+BoHd",
    "0K7Vdm8aYVa1BcpNNGgXbMieohwRiimNEnDWLnIgLnTwN+SFDm6s0cHvrujgB+U4eng55GyU2CK",
    "jZcbDGc6bznX1pyvzvemgqxd6fBOO3MCRJW6p51fwwRpesvKs8t3be/n7dyp8e/gmCIICd7SCe6",
    "vC06jg9kufffjjr380Hga/PPv9/k8//zZ9ext/cIM/KP63uGd7fueWg3L8wUIzLSv05EYRc4mH9",
    "yrxYMeq+9lEDL67kE/5oHdydtybXLT4dauY73mw2d69ir2L94dWp2ECF/VARt24PP/YMTVzXW7n",
    "f7Ri7/4Wf9xbiSdC/v5qN/w7R9V9XOevxkv+amC+qvFq3NbnPzzaDT/n72+x/7Cy34eFbr+ktjr",
    "D5fpKcOCYZ5vi3Bf3uvO9ajvJLfCLS/+4UxNXl4+8Ytyu6/Pti//372+qx6Ty/Qe3eB3VZ119dN",
    "vW9Rfx0y8fleMvl2fzZsJ4vOZ0UH6MAn647tPXJL6fe/pvodfa1n/lD6I/fH4sKJ/hcWB+3Cpf9",
    "6X9LW75kQSq1p+5/ot+sk4vrdMrdyv5bcfng84nj3boS/8AJcoJXA==",
    ""
  };

  static char newstr [1481] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c1_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2760862238U));
  ssSetChecksum1(S,(2281779460U));
  ssSetChecksum2(S,(2198510504U));
  ssSetChecksum3(S,(309891975U));
}

static void mdlRTW_c1_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_flightControlSystem(SimStruct *S)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc1_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_flightControlSystem;
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

  mdl_setup_runtime_resources_c1_flightControlSystem(chartInstance);
}

void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
