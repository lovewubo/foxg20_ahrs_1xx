/* Include files */

#include "blascompat32.h"
#include "ekffede_sfun.h"
#include "c20_ekffede.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ekffede_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c20_debug_family_names[8] = { "mn", "me", "nargin",
  "nargout", "mag", "phi", "theta", "psi" };

/* Function Declarations */
static void initialize_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance);
static void initialize_params_c20_ekffede(SFc20_ekffedeInstanceStruct
  *chartInstance);
static void enable_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance);
static void disable_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance);
static void c20_update_debugger_state_c20_ekffede(SFc20_ekffedeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c20_ekffede(SFc20_ekffedeInstanceStruct
  *chartInstance);
static void set_sim_state_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_st);
static void finalize_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance);
static void sf_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance);
static void initSimStructsc20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_emlrt_marshallIn(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_psi, const char_T *c20_identifier);
static real_T c20_b_emlrt_marshallIn(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_c_emlrt_marshallIn(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static uint8_T c20_d_emlrt_marshallIn(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_b_is_active_c20_ekffede, const char_T *c20_identifier);
static uint8_T c20_e_emlrt_marshallIn(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void init_dsm_address_info(SFc20_ekffedeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance)
{
  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c20_is_active_c20_ekffede = 0U;
}

static void initialize_params_c20_ekffede(SFc20_ekffedeInstanceStruct
  *chartInstance)
{
}

static void enable_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c20_update_debugger_state_c20_ekffede(SFc20_ekffedeInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c20_ekffede(SFc20_ekffedeInstanceStruct
  *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  real_T c20_hoistedGlobal;
  real_T c20_u;
  const mxArray *c20_b_y = NULL;
  uint8_T c20_b_hoistedGlobal;
  uint8_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  real_T *c20_psi;
  c20_psi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellarray(2));
  c20_hoistedGlobal = *c20_psi;
  c20_u = c20_hoistedGlobal;
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_hoistedGlobal = chartInstance->c20_is_active_c20_ekffede;
  c20_b_u = c20_b_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c20_y, 1, c20_c_y);
  sf_mex_assign(&c20_st, c20_y);
  return c20_st;
}

static void set_sim_state_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_st)
{
  const mxArray *c20_u;
  real_T *c20_psi;
  c20_psi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c20_doneDoubleBufferReInit = TRUE;
  c20_u = sf_mex_dup(c20_st);
  *c20_psi = c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u,
    0)), "psi");
  chartInstance->c20_is_active_c20_ekffede = c20_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)),
     "is_active_c20_ekffede");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_ekffede(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance)
{
}

static void sf_c20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance)
{
  int32_T c20_i0;
  real_T c20_hoistedGlobal;
  real_T c20_b_hoistedGlobal;
  int32_T c20_i1;
  real_T c20_mag[3];
  real_T c20_phi;
  real_T c20_theta;
  uint32_T c20_debug_family_var_map[8];
  real_T c20_mn;
  real_T c20_me;
  real_T c20_nargin = 3.0;
  real_T c20_nargout = 1.0;
  real_T c20_psi;
  real_T c20_x;
  real_T c20_b_x;
  real_T c20_a;
  real_T c20_b;
  real_T c20_y;
  real_T c20_c_x;
  real_T c20_d_x;
  real_T c20_e_x;
  real_T c20_f_x;
  real_T c20_b_a;
  real_T c20_b_b;
  real_T c20_b_y;
  real_T c20_c_a;
  real_T c20_c_b;
  real_T c20_c_y;
  real_T c20_g_x;
  real_T c20_h_x;
  real_T c20_i_x;
  real_T c20_j_x;
  real_T c20_d_a;
  real_T c20_d_b;
  real_T c20_d_y;
  real_T c20_e_a;
  real_T c20_e_b;
  real_T c20_e_y;
  real_T c20_k_x;
  real_T c20_l_x;
  real_T c20_f_a;
  real_T c20_f_b;
  real_T c20_f_y;
  real_T c20_m_x;
  real_T c20_n_x;
  real_T c20_g_a;
  real_T c20_g_b;
  real_T c20_g_y;
  real_T c20_h_y;
  real_T c20_o_x;
  real_T c20_i_y;
  real_T c20_p_x;
  real_T c20_r;
  real_T *c20_b_psi;
  real_T *c20_b_phi;
  real_T *c20_b_theta;
  real_T (*c20_b_mag)[3];
  c20_b_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c20_b_phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c20_b_psi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_b_mag = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  for (c20_i0 = 0; c20_i0 < 3; c20_i0++) {
    _SFD_DATA_RANGE_CHECK((*c20_b_mag)[c20_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c20_b_psi, 1U);
  _SFD_DATA_RANGE_CHECK(*c20_b_phi, 2U);
  _SFD_DATA_RANGE_CHECK(*c20_b_theta, 3U);
  chartInstance->c20_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  c20_hoistedGlobal = *c20_b_phi;
  c20_b_hoistedGlobal = *c20_b_theta;
  for (c20_i1 = 0; c20_i1 < 3; c20_i1++) {
    c20_mag[c20_i1] = (*c20_b_mag)[c20_i1];
  }

  c20_phi = c20_hoistedGlobal;
  c20_theta = c20_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c20_debug_family_names,
    c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c20_mn, 0U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c20_me, 1U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c20_nargin, 2U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c20_nargout, 3U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c20_mag, 4U, c20_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c20_phi, 5U, c20_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c20_theta, 6U, c20_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c20_psi, 7U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 3);
  c20_x = c20_theta;
  c20_b_x = c20_x;
  c20_b_x = muDoubleScalarCos(c20_b_x);
  c20_a = c20_b_x;
  c20_b = c20_mag[0];
  c20_y = c20_a * c20_b;
  c20_c_x = c20_phi;
  c20_d_x = c20_c_x;
  c20_d_x = muDoubleScalarSin(c20_d_x);
  c20_e_x = c20_theta;
  c20_f_x = c20_e_x;
  c20_f_x = muDoubleScalarSin(c20_f_x);
  c20_b_a = c20_d_x;
  c20_b_b = c20_f_x;
  c20_b_y = c20_b_a * c20_b_b;
  c20_c_a = c20_b_y;
  c20_c_b = c20_mag[1];
  c20_c_y = c20_c_a * c20_c_b;
  c20_g_x = c20_phi;
  c20_h_x = c20_g_x;
  c20_h_x = muDoubleScalarCos(c20_h_x);
  c20_i_x = c20_theta;
  c20_j_x = c20_i_x;
  c20_j_x = muDoubleScalarSin(c20_j_x);
  c20_d_a = c20_h_x;
  c20_d_b = c20_j_x;
  c20_d_y = c20_d_a * c20_d_b;
  c20_e_a = c20_d_y;
  c20_e_b = c20_mag[2];
  c20_e_y = c20_e_a * c20_e_b;
  c20_mn = (c20_y + c20_c_y) + c20_e_y;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_k_x = c20_phi;
  c20_l_x = c20_k_x;
  c20_l_x = muDoubleScalarCos(c20_l_x);
  c20_f_a = c20_l_x;
  c20_f_b = c20_mag[1];
  c20_f_y = c20_f_a * c20_f_b;
  c20_m_x = c20_phi;
  c20_n_x = c20_m_x;
  c20_n_x = muDoubleScalarSin(c20_n_x);
  c20_g_a = -c20_n_x;
  c20_g_b = c20_mag[2];
  c20_g_y = c20_g_a * c20_g_b;
  c20_me = c20_f_y + c20_g_y;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 10);
  c20_h_y = c20_me;
  c20_o_x = c20_mn;
  c20_i_y = c20_h_y;
  c20_p_x = c20_o_x;
  c20_r = muDoubleScalarAtan2(c20_i_y, c20_p_x);
  c20_psi = -c20_r;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, -10);
  sf_debug_symbol_scope_pop();
  *c20_b_psi = c20_psi;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  sf_debug_check_for_state_inconsistency(_ekffedeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc20_ekffede(SFc20_ekffedeInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber)
{
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc20_ekffedeInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c20_mxArrayOutData, c20_y);
  return c20_mxArrayOutData;
}

static real_T c20_emlrt_marshallIn(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_psi, const char_T *c20_identifier)
{
  real_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_psi), &c20_thisId);
  sf_mex_destroy(&c20_psi);
  return c20_y;
}

static real_T c20_b_emlrt_marshallIn(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_psi;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc20_ekffedeInstanceStruct *)chartInstanceVoid;
  c20_psi = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_psi), &c20_thisId);
  sf_mex_destroy(&c20_psi);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i2;
  real_T c20_b_inData[3];
  int32_T c20_i3;
  real_T c20_u[3];
  const mxArray *c20_y = NULL;
  SFc20_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc20_ekffedeInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i2 = 0; c20_i2 < 3; c20_i2++) {
    c20_b_inData[c20_i2] = (*(real_T (*)[3])c20_inData)[c20_i2];
  }

  for (c20_i3 = 0; c20_i3 < 3; c20_i3++) {
    c20_u[c20_i3] = c20_b_inData[c20_i3];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c20_mxArrayOutData, c20_y);
  return c20_mxArrayOutData;
}

const mxArray *sf_c20_ekffede_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo;
  c20_ResolvedFunctionInfo c20_info[9];
  c20_ResolvedFunctionInfo (*c20_b_info)[9];
  const mxArray *c20_m0 = NULL;
  int32_T c20_i4;
  c20_ResolvedFunctionInfo *c20_r0;
  c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  c20_b_info = (c20_ResolvedFunctionInfo (*)[9])c20_info;
  (*c20_b_info)[0].context = "";
  (*c20_b_info)[0].name = "cos";
  (*c20_b_info)[0].dominantType = "double";
  (*c20_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c20_b_info)[0].fileTimeLo = 467391744U;
  (*c20_b_info)[0].fileTimeHi = 30108011U;
  (*c20_b_info)[0].mFileTimeLo = 0U;
  (*c20_b_info)[0].mFileTimeHi = 0U;
  (*c20_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c20_b_info)[1].name = "eml_scalar_cos";
  (*c20_b_info)[1].dominantType = "double";
  (*c20_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c20_b_info)[1].fileTimeLo = 627391744U;
  (*c20_b_info)[1].fileTimeHi = 30108011U;
  (*c20_b_info)[1].mFileTimeLo = 0U;
  (*c20_b_info)[1].mFileTimeHi = 0U;
  (*c20_b_info)[2].context = "";
  (*c20_b_info)[2].name = "mtimes";
  (*c20_b_info)[2].dominantType = "double";
  (*c20_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c20_b_info)[2].fileTimeLo = 3573034496U;
  (*c20_b_info)[2].fileTimeHi = 30114299U;
  (*c20_b_info)[2].mFileTimeLo = 0U;
  (*c20_b_info)[2].mFileTimeHi = 0U;
  (*c20_b_info)[3].context = "";
  (*c20_b_info)[3].name = "sin";
  (*c20_b_info)[3].dominantType = "double";
  (*c20_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c20_b_info)[3].fileTimeLo = 907391744U;
  (*c20_b_info)[3].fileTimeHi = 30108011U;
  (*c20_b_info)[3].mFileTimeLo = 0U;
  (*c20_b_info)[3].mFileTimeHi = 0U;
  (*c20_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c20_b_info)[4].name = "eml_scalar_sin";
  (*c20_b_info)[4].dominantType = "double";
  (*c20_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c20_b_info)[4].fileTimeLo = 767391744U;
  (*c20_b_info)[4].fileTimeHi = 30108011U;
  (*c20_b_info)[4].mFileTimeLo = 0U;
  (*c20_b_info)[4].mFileTimeHi = 0U;
  (*c20_b_info)[5].context = "";
  (*c20_b_info)[5].name = "atan2";
  (*c20_b_info)[5].dominantType = "double";
  (*c20_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  (*c20_b_info)[5].fileTimeLo = 447391744U;
  (*c20_b_info)[5].fileTimeHi = 30108011U;
  (*c20_b_info)[5].mFileTimeLo = 0U;
  (*c20_b_info)[5].mFileTimeHi = 0U;
  (*c20_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  (*c20_b_info)[6].name = "eml_scalar_eg";
  (*c20_b_info)[6].dominantType = "double";
  (*c20_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c20_b_info)[6].fileTimeLo = 1367391744U;
  (*c20_b_info)[6].fileTimeHi = 30108011U;
  (*c20_b_info)[6].mFileTimeLo = 0U;
  (*c20_b_info)[6].mFileTimeHi = 0U;
  (*c20_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  (*c20_b_info)[7].name = "eml_scalexp_alloc";
  (*c20_b_info)[7].dominantType = "double";
  (*c20_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c20_b_info)[7].fileTimeLo = 1367391744U;
  (*c20_b_info)[7].fileTimeHi = 30108011U;
  (*c20_b_info)[7].mFileTimeLo = 0U;
  (*c20_b_info)[7].mFileTimeHi = 0U;
  (*c20_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  (*c20_b_info)[8].name = "eml_scalar_atan2";
  (*c20_b_info)[8].dominantType = "double";
  (*c20_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  (*c20_b_info)[8].fileTimeLo = 607391744U;
  (*c20_b_info)[8].fileTimeHi = 30108011U;
  (*c20_b_info)[8].mFileTimeLo = 0U;
  (*c20_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c20_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9));
  for (c20_i4 = 0; c20_i4 < 9; c20_i4++) {
    c20_r0 = &c20_info[c20_i4];
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->context)), "context", "nameCaptureInfo",
                    c20_i4);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->name)), "name", "nameCaptureInfo", c20_i4);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      c20_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c20_i4);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->resolved)), "resolved",
                    "nameCaptureInfo", c20_i4);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c20_i4);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c20_i4);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      &c20_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c20_i4);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      &c20_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c20_i4);
  }

  sf_mex_assign(&c20_nameCaptureInfo, c20_m0);
  return c20_nameCaptureInfo;
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc20_ekffedeInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c20_mxArrayOutData, c20_y);
  return c20_mxArrayOutData;
}

static int32_T c20_c_emlrt_marshallIn(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i5;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i5, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i5;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc20_ekffedeInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static uint8_T c20_d_emlrt_marshallIn(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_b_is_active_c20_ekffede, const char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_active_c20_ekffede), &c20_thisId);
  sf_mex_destroy(&c20_b_is_active_c20_ekffede);
  return c20_y;
}

static uint8_T c20_e_emlrt_marshallIn(SFc20_ekffedeInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void init_dsm_address_info(SFc20_ekffedeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c20_ekffede_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1204753171U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(241515626U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1527460187U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2321229890U);
}

mxArray *sf_c20_ekffede_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(251521276U);
    pr[1] = (double)(1380976228U);
    pr[2] = (double)(2440448689U);
    pr[3] = (double)(3217758193U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c20_ekffede(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"psi\",},{M[8],M[0],T\"is_active_c20_ekffede\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_ekffede_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_ekffedeInstanceStruct *chartInstance;
    chartInstance = (SFc20_ekffedeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_ekffedeMachineNumber_,
          20,
          1,
          1,
          4,
          0,
          0,
          0,
          0,
          0,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_ekffedeMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_ekffedeMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_ekffedeMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"mag");
          _SFD_SET_DATA_PROPS(1,2,0,1,"psi");
          _SFD_SET_DATA_PROPS(2,1,1,0,"phi");
          _SFD_SET_DATA_PROPS(3,1,1,0,"theta");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,247);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c20_psi;
          real_T *c20_phi;
          real_T *c20_theta;
          real_T (*c20_mag)[3];
          c20_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c20_phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c20_psi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c20_mag = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c20_mag);
          _SFD_SET_DATA_VALUE_PTR(1U, c20_psi);
          _SFD_SET_DATA_VALUE_PTR(2U, c20_phi);
          _SFD_SET_DATA_VALUE_PTR(3U, c20_theta);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ekffedeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c20_ekffede(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_ekffedeInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c20_ekffede((SFc20_ekffedeInstanceStruct*) chartInstanceVar);
  initialize_c20_ekffede((SFc20_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c20_ekffede(void *chartInstanceVar)
{
  enable_c20_ekffede((SFc20_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c20_ekffede(void *chartInstanceVar)
{
  disable_c20_ekffede((SFc20_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c20_ekffede(void *chartInstanceVar)
{
  sf_c20_ekffede((SFc20_ekffedeInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c20_ekffede(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_ekffede((SFc20_ekffedeInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_ekffede();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c20_ekffede(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_ekffede();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_ekffede((SFc20_ekffedeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c20_ekffede(SimStruct* S)
{
  return sf_internal_get_sim_state_c20_ekffede(S);
}

static void sf_opaque_set_sim_state_c20_ekffede(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c20_ekffede(S, st);
}

static void sf_opaque_terminate_c20_ekffede(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_ekffedeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c20_ekffede((SFc20_ekffedeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc20_ekffede((SFc20_ekffedeInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_ekffede(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c20_ekffede((SFc20_ekffedeInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_ekffede(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ekffede","ekffede",20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ekffede","ekffede",20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ekffede","ekffede",20,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ekffede","ekffede",20,3);
      sf_mark_chart_reusable_outputs(S,"ekffede","ekffede",20,1);
    }

    sf_set_rtw_dwork_info(S,"ekffede","ekffede",20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3564003690U));
  ssSetChecksum1(S,(1904739345U));
  ssSetChecksum2(S,(292547652U));
  ssSetChecksum3(S,(3665572922U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c20_ekffede(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ekffede", "ekffede",20);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_ekffede(SimStruct *S)
{
  SFc20_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc20_ekffedeInstanceStruct *)malloc(sizeof
    (SFc20_ekffedeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_ekffedeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c20_ekffede;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c20_ekffede;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c20_ekffede;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c20_ekffede;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c20_ekffede;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c20_ekffede;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c20_ekffede;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c20_ekffede;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_ekffede;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_ekffede;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c20_ekffede;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c20_ekffede_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_ekffede(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_ekffede(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_ekffede(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_ekffede_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
