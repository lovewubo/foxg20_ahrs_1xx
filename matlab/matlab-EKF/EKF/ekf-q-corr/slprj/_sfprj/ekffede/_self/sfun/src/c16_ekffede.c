/* Include files */

#include "blascompat32.h"
#include "ekffede_sfun.h"
#include "c16_ekffede.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ekffede_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c16_debug_family_names[6] = { "omega", "nargin", "nargout",
  "gyro", "quat", "quat_dot" };

/* Function Declarations */
static void initialize_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance);
static void initialize_params_c16_ekffede(SFc16_ekffedeInstanceStruct
  *chartInstance);
static void enable_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance);
static void disable_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance);
static void c16_update_debugger_state_c16_ekffede(SFc16_ekffedeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c16_ekffede(SFc16_ekffedeInstanceStruct
  *chartInstance);
static void set_sim_state_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_st);
static void finalize_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance);
static void sf_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance);
static void c16_chartstep_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance);
static void initSimStructsc16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_quat_dot, const char_T *c16_identifier, real_T c16_y[4]);
static void c16_b_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[4]);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_c_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_d_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[16]);
static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static void c16_eml_scalar_eg(SFc16_ekffedeInstanceStruct *chartInstance);
static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_e_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static uint8_T c16_f_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_b_is_active_c16_ekffede, const char_T *c16_identifier);
static uint8_T c16_g_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void init_dsm_address_info(SFc16_ekffedeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c16_is_active_c16_ekffede = 0U;
}

static void initialize_params_c16_ekffede(SFc16_ekffedeInstanceStruct
  *chartInstance)
{
}

static void enable_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c16_update_debugger_state_c16_ekffede(SFc16_ekffedeInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c16_ekffede(SFc16_ekffedeInstanceStruct
  *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  int32_T c16_i0;
  real_T c16_u[4];
  const mxArray *c16_b_y = NULL;
  uint8_T c16_hoistedGlobal;
  uint8_T c16_b_u;
  const mxArray *c16_c_y = NULL;
  real_T (*c16_quat_dot)[4];
  c16_quat_dot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellarray(2));
  for (c16_i0 = 0; c16_i0 < 4; c16_i0++) {
    c16_u[c16_i0] = (*c16_quat_dot)[c16_i0];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_hoistedGlobal = chartInstance->c16_is_active_c16_ekffede;
  c16_b_u = c16_hoistedGlobal;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c16_y, 1, c16_c_y);
  sf_mex_assign(&c16_st, c16_y);
  return c16_st;
}

static void set_sim_state_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_st)
{
  const mxArray *c16_u;
  real_T c16_dv0[4];
  int32_T c16_i1;
  real_T (*c16_quat_dot)[4];
  c16_quat_dot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c16_doneDoubleBufferReInit = TRUE;
  c16_u = sf_mex_dup(c16_st);
  c16_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 0)),
                       "quat_dot", c16_dv0);
  for (c16_i1 = 0; c16_i1 < 4; c16_i1++) {
    (*c16_quat_dot)[c16_i1] = c16_dv0[c16_i1];
  }

  chartInstance->c16_is_active_c16_ekffede = c16_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 1)),
     "is_active_c16_ekffede");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_ekffede(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance)
{
}

static void sf_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance)
{
  int32_T c16_i2;
  int32_T c16_i3;
  int32_T c16_i4;
  real_T (*c16_quat)[4];
  real_T (*c16_quat_dot)[4];
  real_T (*c16_gyro)[3];
  c16_quat = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c16_quat_dot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_gyro = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  for (c16_i2 = 0; c16_i2 < 3; c16_i2++) {
    _SFD_DATA_RANGE_CHECK((*c16_gyro)[c16_i2], 0U);
  }

  for (c16_i3 = 0; c16_i3 < 4; c16_i3++) {
    _SFD_DATA_RANGE_CHECK((*c16_quat_dot)[c16_i3], 1U);
  }

  for (c16_i4 = 0; c16_i4 < 4; c16_i4++) {
    _SFD_DATA_RANGE_CHECK((*c16_quat)[c16_i4], 2U);
  }

  chartInstance->c16_sfEvent = CALL_EVENT;
  c16_chartstep_c16_ekffede(chartInstance);
  sf_debug_check_for_state_inconsistency(_ekffedeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c16_chartstep_c16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance)
{
  int32_T c16_i5;
  real_T c16_gyro[3];
  int32_T c16_i6;
  real_T c16_quat[4];
  uint32_T c16_debug_family_var_map[6];
  real_T c16_omega[16];
  real_T c16_nargin = 2.0;
  real_T c16_nargout = 1.0;
  real_T c16_quat_dot[4];
  int32_T c16_i7;
  real_T c16_b[16];
  int32_T c16_i8;
  int32_T c16_i9;
  real_T c16_b_b[4];
  int32_T c16_i10;
  int32_T c16_i11;
  int32_T c16_i12;
  real_T c16_C[4];
  int32_T c16_i13;
  int32_T c16_i14;
  int32_T c16_i15;
  int32_T c16_i16;
  int32_T c16_i17;
  int32_T c16_i18;
  int32_T c16_i19;
  real_T (*c16_b_quat_dot)[4];
  real_T (*c16_b_quat)[4];
  real_T (*c16_b_gyro)[3];
  c16_b_quat = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c16_b_quat_dot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_b_gyro = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  for (c16_i5 = 0; c16_i5 < 3; c16_i5++) {
    c16_gyro[c16_i5] = (*c16_b_gyro)[c16_i5];
  }

  for (c16_i6 = 0; c16_i6 < 4; c16_i6++) {
    c16_quat[c16_i6] = (*c16_b_quat)[c16_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c16_debug_family_names,
    c16_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c16_omega, 0U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c16_nargin, 1U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c16_nargout, 2U,
    c16_c_sf_marshallOut, c16_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c16_gyro, 3U, c16_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c16_quat, 4U, c16_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c16_quat_dot, 5U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 2);
  c16_omega[0] = 0.0;
  c16_omega[4] = -c16_gyro[0];
  c16_omega[8] = -c16_gyro[1];
  c16_omega[12] = -c16_gyro[2];
  c16_omega[1] = c16_gyro[0];
  c16_omega[5] = 0.0;
  c16_omega[9] = c16_gyro[2];
  c16_omega[13] = -c16_gyro[1];
  c16_omega[2] = c16_gyro[1];
  c16_omega[6] = -c16_gyro[2];
  c16_omega[10] = 0.0;
  c16_omega[14] = c16_gyro[0];
  c16_omega[3] = c16_gyro[2];
  c16_omega[7] = c16_gyro[1];
  c16_omega[11] = -c16_gyro[0];
  c16_omega[15] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 7);
  for (c16_i7 = 0; c16_i7 < 16; c16_i7++) {
    c16_b[c16_i7] = c16_omega[c16_i7];
  }

  for (c16_i8 = 0; c16_i8 < 16; c16_i8++) {
    c16_b[c16_i8] *= 0.5;
  }

  for (c16_i9 = 0; c16_i9 < 4; c16_i9++) {
    c16_b_b[c16_i9] = c16_quat[c16_i9];
  }

  c16_eml_scalar_eg(chartInstance);
  c16_eml_scalar_eg(chartInstance);
  for (c16_i10 = 0; c16_i10 < 4; c16_i10++) {
    c16_quat_dot[c16_i10] = 0.0;
  }

  for (c16_i11 = 0; c16_i11 < 4; c16_i11++) {
    c16_quat_dot[c16_i11] = 0.0;
  }

  for (c16_i12 = 0; c16_i12 < 4; c16_i12++) {
    c16_C[c16_i12] = c16_quat_dot[c16_i12];
  }

  for (c16_i13 = 0; c16_i13 < 4; c16_i13++) {
    c16_quat_dot[c16_i13] = c16_C[c16_i13];
  }

  for (c16_i14 = 0; c16_i14 < 4; c16_i14++) {
    c16_C[c16_i14] = c16_quat_dot[c16_i14];
  }

  for (c16_i15 = 0; c16_i15 < 4; c16_i15++) {
    c16_quat_dot[c16_i15] = c16_C[c16_i15];
  }

  for (c16_i16 = 0; c16_i16 < 4; c16_i16++) {
    c16_quat_dot[c16_i16] = 0.0;
    c16_i17 = 0;
    for (c16_i18 = 0; c16_i18 < 4; c16_i18++) {
      c16_quat_dot[c16_i16] += c16_b[c16_i17 + c16_i16] * c16_b_b[c16_i18];
      c16_i17 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -7);
  sf_debug_symbol_scope_pop();
  for (c16_i19 = 0; c16_i19 < 4; c16_i19++) {
    (*c16_b_quat_dot)[c16_i19] = c16_quat_dot[c16_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
}

static void initSimStructsc16_ekffede(SFc16_ekffedeInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber)
{
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i20;
  real_T c16_b_inData[4];
  int32_T c16_i21;
  real_T c16_u[4];
  const mxArray *c16_y = NULL;
  SFc16_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc16_ekffedeInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  for (c16_i20 = 0; c16_i20 < 4; c16_i20++) {
    c16_b_inData[c16_i20] = (*(real_T (*)[4])c16_inData)[c16_i20];
  }

  for (c16_i21 = 0; c16_i21 < 4; c16_i21++) {
    c16_u[c16_i21] = c16_b_inData[c16_i21];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c16_mxArrayOutData, c16_y);
  return c16_mxArrayOutData;
}

static void c16_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_quat_dot, const char_T *c16_identifier, real_T c16_y[4])
{
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_quat_dot), &c16_thisId,
    c16_y);
  sf_mex_destroy(&c16_quat_dot);
}

static void c16_b_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[4])
{
  real_T c16_dv1[4];
  int32_T c16_i22;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c16_i22 = 0; c16_i22 < 4; c16_i22++) {
    c16_y[c16_i22] = c16_dv1[c16_i22];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_quat_dot;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[4];
  int32_T c16_i23;
  SFc16_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc16_ekffedeInstanceStruct *)chartInstanceVoid;
  c16_quat_dot = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_quat_dot), &c16_thisId,
    c16_y);
  sf_mex_destroy(&c16_quat_dot);
  for (c16_i23 = 0; c16_i23 < 4; c16_i23++) {
    (*(real_T (*)[4])c16_outData)[c16_i23] = c16_y[c16_i23];
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i24;
  real_T c16_b_inData[3];
  int32_T c16_i25;
  real_T c16_u[3];
  const mxArray *c16_y = NULL;
  SFc16_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc16_ekffedeInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  for (c16_i24 = 0; c16_i24 < 3; c16_i24++) {
    c16_b_inData[c16_i24] = (*(real_T (*)[3])c16_inData)[c16_i24];
  }

  for (c16_i25 = 0; c16_i25 < 3; c16_i25++) {
    c16_u[c16_i25] = c16_b_inData[c16_i25];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c16_mxArrayOutData, c16_y);
  return c16_mxArrayOutData;
}

static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc16_ekffedeInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c16_mxArrayOutData, c16_y);
  return c16_mxArrayOutData;
}

static real_T c16_c_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d0, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_nargout;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc16_ekffedeInstanceStruct *)chartInstanceVoid;
  c16_nargout = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_nargout),
    &c16_thisId);
  sf_mex_destroy(&c16_nargout);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i26;
  int32_T c16_i27;
  int32_T c16_i28;
  real_T c16_b_inData[16];
  int32_T c16_i29;
  int32_T c16_i30;
  int32_T c16_i31;
  real_T c16_u[16];
  const mxArray *c16_y = NULL;
  SFc16_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc16_ekffedeInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_i26 = 0;
  for (c16_i27 = 0; c16_i27 < 4; c16_i27++) {
    for (c16_i28 = 0; c16_i28 < 4; c16_i28++) {
      c16_b_inData[c16_i28 + c16_i26] = (*(real_T (*)[16])c16_inData)[c16_i28 +
        c16_i26];
    }

    c16_i26 += 4;
  }

  c16_i29 = 0;
  for (c16_i30 = 0; c16_i30 < 4; c16_i30++) {
    for (c16_i31 = 0; c16_i31 < 4; c16_i31++) {
      c16_u[c16_i31 + c16_i29] = c16_b_inData[c16_i31 + c16_i29];
    }

    c16_i29 += 4;
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c16_mxArrayOutData, c16_y);
  return c16_mxArrayOutData;
}

static void c16_d_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId, real_T c16_y[16])
{
  real_T c16_dv2[16];
  int32_T c16_i32;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv2, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c16_i32 = 0; c16_i32 < 16; c16_i32++) {
    c16_y[c16_i32] = c16_dv2[c16_i32];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_omega;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[16];
  int32_T c16_i33;
  int32_T c16_i34;
  int32_T c16_i35;
  SFc16_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc16_ekffedeInstanceStruct *)chartInstanceVoid;
  c16_omega = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_omega), &c16_thisId,
    c16_y);
  sf_mex_destroy(&c16_omega);
  c16_i33 = 0;
  for (c16_i34 = 0; c16_i34 < 4; c16_i34++) {
    for (c16_i35 = 0; c16_i35 < 4; c16_i35++) {
      (*(real_T (*)[16])c16_outData)[c16_i35 + c16_i33] = c16_y[c16_i35 +
        c16_i33];
    }

    c16_i33 += 4;
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray *sf_c16_ekffede_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo;
  c16_ResolvedFunctionInfo c16_info[12];
  c16_ResolvedFunctionInfo (*c16_b_info)[12];
  const mxArray *c16_m0 = NULL;
  int32_T c16_i36;
  c16_ResolvedFunctionInfo *c16_r0;
  c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  c16_b_info = (c16_ResolvedFunctionInfo (*)[12])c16_info;
  (*c16_b_info)[0].context = "";
  (*c16_b_info)[0].name = "mtimes";
  (*c16_b_info)[0].dominantType = "double";
  (*c16_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c16_b_info)[0].fileTimeLo = 3573034496U;
  (*c16_b_info)[0].fileTimeHi = 30114299U;
  (*c16_b_info)[0].mFileTimeLo = 0U;
  (*c16_b_info)[0].mFileTimeHi = 0U;
  (*c16_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c16_b_info)[1].name = "eml_index_class";
  (*c16_b_info)[1].dominantType = "";
  (*c16_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c16_b_info)[1].fileTimeLo = 1187391744U;
  (*c16_b_info)[1].fileTimeHi = 30108011U;
  (*c16_b_info)[1].mFileTimeLo = 0U;
  (*c16_b_info)[1].mFileTimeHi = 0U;
  (*c16_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c16_b_info)[2].name = "eml_scalar_eg";
  (*c16_b_info)[2].dominantType = "double";
  (*c16_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c16_b_info)[2].fileTimeLo = 1367391744U;
  (*c16_b_info)[2].fileTimeHi = 30108011U;
  (*c16_b_info)[2].mFileTimeLo = 0U;
  (*c16_b_info)[2].mFileTimeHi = 0U;
  (*c16_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c16_b_info)[3].name = "eml_xgemm";
  (*c16_b_info)[3].dominantType = "int32";
  (*c16_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c16_b_info)[3].fileTimeLo = 507391744U;
  (*c16_b_info)[3].fileTimeHi = 30108011U;
  (*c16_b_info)[3].mFileTimeLo = 0U;
  (*c16_b_info)[3].mFileTimeHi = 0U;
  (*c16_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  (*c16_b_info)[4].name = "length";
  (*c16_b_info)[4].dominantType = "double";
  (*c16_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c16_b_info)[4].fileTimeLo = 1007391744U;
  (*c16_b_info)[4].fileTimeHi = 30108011U;
  (*c16_b_info)[4].mFileTimeLo = 0U;
  (*c16_b_info)[4].mFileTimeHi = 0U;
  (*c16_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  (*c16_b_info)[5].name = "min";
  (*c16_b_info)[5].dominantType = "double";
  (*c16_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c16_b_info)[5].fileTimeLo = 367391744U;
  (*c16_b_info)[5].fileTimeHi = 30108011U;
  (*c16_b_info)[5].mFileTimeLo = 0U;
  (*c16_b_info)[5].mFileTimeHi = 0U;
  (*c16_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c16_b_info)[6].name = "eml_min_or_max";
  (*c16_b_info)[6].dominantType = "char";
  (*c16_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c16_b_info)[6].fileTimeLo = 1287391744U;
  (*c16_b_info)[6].fileTimeHi = 30108011U;
  (*c16_b_info)[6].mFileTimeLo = 0U;
  (*c16_b_info)[6].mFileTimeHi = 0U;
  (*c16_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c16_b_info)[7].name = "eml_scalexp_alloc";
  (*c16_b_info)[7].dominantType = "double";
  (*c16_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c16_b_info)[7].fileTimeLo = 1367391744U;
  (*c16_b_info)[7].fileTimeHi = 30108011U;
  (*c16_b_info)[7].mFileTimeLo = 0U;
  (*c16_b_info)[7].mFileTimeHi = 0U;
  (*c16_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c16_b_info)[8].name = "eml_refblas_xgemm";
  (*c16_b_info)[8].dominantType = "int32";
  (*c16_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c16_b_info)[8].fileTimeLo = 1227391744U;
  (*c16_b_info)[8].fileTimeHi = 30108011U;
  (*c16_b_info)[8].mFileTimeLo = 0U;
  (*c16_b_info)[8].mFileTimeHi = 0U;
  (*c16_b_info)[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c16_b_info)[9].name = "eml_index_minus";
  (*c16_b_info)[9].dominantType = "int32";
  (*c16_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  (*c16_b_info)[9].fileTimeLo = 1187391744U;
  (*c16_b_info)[9].fileTimeHi = 30108011U;
  (*c16_b_info)[9].mFileTimeLo = 0U;
  (*c16_b_info)[9].mFileTimeHi = 0U;
  (*c16_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c16_b_info)[10].name = "eml_index_times";
  (*c16_b_info)[10].dominantType = "int32";
  (*c16_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c16_b_info)[10].fileTimeLo = 1207391744U;
  (*c16_b_info)[10].fileTimeHi = 30108011U;
  (*c16_b_info)[10].mFileTimeLo = 0U;
  (*c16_b_info)[10].mFileTimeHi = 0U;
  (*c16_b_info)[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c16_b_info)[11].name = "eml_index_plus";
  (*c16_b_info)[11].dominantType = "int32";
  (*c16_b_info)[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c16_b_info)[11].fileTimeLo = 1187391744U;
  (*c16_b_info)[11].fileTimeHi = 30108011U;
  (*c16_b_info)[11].mFileTimeLo = 0U;
  (*c16_b_info)[11].mFileTimeHi = 0U;
  sf_mex_assign(&c16_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12));
  for (c16_i36 = 0; c16_i36 < 12; c16_i36++) {
    c16_r0 = &c16_info[c16_i36];
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c16_r0->context)), "context", "nameCaptureInfo",
                    c16_i36);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c16_r0->name)), "name", "nameCaptureInfo",
                    c16_i36);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      c16_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c16_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c16_i36);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c16_r0->resolved)), "resolved",
                    "nameCaptureInfo", c16_i36);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c16_i36);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c16_i36);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      &c16_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c16_i36);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      &c16_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c16_i36);
  }

  sf_mex_assign(&c16_nameCaptureInfo, c16_m0);
  return c16_nameCaptureInfo;
}

static void c16_eml_scalar_eg(SFc16_ekffedeInstanceStruct *chartInstance)
{
}

static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc16_ekffedeInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c16_mxArrayOutData, c16_y);
  return c16_mxArrayOutData;
}

static int32_T c16_e_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i37;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i37, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i37;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc16_ekffedeInstanceStruct *)chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static uint8_T c16_f_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_b_is_active_c16_ekffede, const char_T *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_ekffede), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_ekffede);
  return c16_y;
}

static uint8_T c16_g_emlrt_marshallIn(SFc16_ekffedeInstanceStruct *chartInstance,
  const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void init_dsm_address_info(SFc16_ekffedeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c16_ekffede_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(485398008U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3692320824U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2269835470U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(223517925U);
}

mxArray *sf_c16_ekffede_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4163931232U);
    pr[1] = (double)(3819223279U);
    pr[2] = (double)(889691284U);
    pr[3] = (double)(2848223U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      pr[0] = (double)(4);
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
      pr[0] = (double)(4);
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

static const mxArray *sf_get_sim_state_info_c16_ekffede(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"quat_dot\",},{M[8],M[0],T\"is_active_c16_ekffede\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_ekffede_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_ekffedeInstanceStruct *chartInstance;
    chartInstance = (SFc16_ekffedeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_ekffedeMachineNumber_,
          16,
          1,
          1,
          3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"gyro");
          _SFD_SET_DATA_PROPS(1,2,0,1,"quat_dot");
          _SFD_SET_DATA_PROPS(2,1,1,0,"quat");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,271);
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
            1.0,0,0,(MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)
            c16_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c16_gyro)[3];
          real_T (*c16_quat_dot)[4];
          real_T (*c16_quat)[4];
          c16_quat = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c16_quat_dot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S,
            1);
          c16_gyro = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c16_gyro);
          _SFD_SET_DATA_VALUE_PTR(1U, *c16_quat_dot);
          _SFD_SET_DATA_VALUE_PTR(2U, *c16_quat);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ekffedeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c16_ekffede(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_ekffedeInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c16_ekffede((SFc16_ekffedeInstanceStruct*) chartInstanceVar);
  initialize_c16_ekffede((SFc16_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c16_ekffede(void *chartInstanceVar)
{
  enable_c16_ekffede((SFc16_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c16_ekffede(void *chartInstanceVar)
{
  disable_c16_ekffede((SFc16_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c16_ekffede(void *chartInstanceVar)
{
  sf_c16_ekffede((SFc16_ekffedeInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c16_ekffede(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c16_ekffede((SFc16_ekffedeInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_ekffede();/* state var info */
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

extern void sf_internal_set_sim_state_c16_ekffede(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_ekffede();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c16_ekffede((SFc16_ekffedeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c16_ekffede(SimStruct* S)
{
  return sf_internal_get_sim_state_c16_ekffede(S);
}

static void sf_opaque_set_sim_state_c16_ekffede(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c16_ekffede(S, st);
}

static void sf_opaque_terminate_c16_ekffede(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_ekffedeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c16_ekffede((SFc16_ekffedeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc16_ekffede((SFc16_ekffedeInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_ekffede(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c16_ekffede((SFc16_ekffedeInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_ekffede(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ekffede","ekffede",16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ekffede","ekffede",16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ekffede","ekffede",16,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ekffede","ekffede",16,2);
      sf_mark_chart_reusable_outputs(S,"ekffede","ekffede",16,1);
    }

    sf_set_rtw_dwork_info(S,"ekffede","ekffede",16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4132438174U));
  ssSetChecksum1(S,(603363575U));
  ssSetChecksum2(S,(1528389105U));
  ssSetChecksum3(S,(2528667551U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c16_ekffede(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ekffede", "ekffede",16);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_ekffede(SimStruct *S)
{
  SFc16_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc16_ekffedeInstanceStruct *)malloc(sizeof
    (SFc16_ekffedeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_ekffedeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c16_ekffede;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c16_ekffede;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c16_ekffede;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c16_ekffede;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c16_ekffede;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c16_ekffede;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c16_ekffede;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c16_ekffede;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_ekffede;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_ekffede;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c16_ekffede;
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

void c16_ekffede_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_ekffede(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_ekffede(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_ekffede(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_ekffede_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
