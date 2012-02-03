/* Include files */

#include "blascompat32.h"
#include "ekffedepre_sfun.h"
#include "c15_ekffedepre.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ekffedepre_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c15_debug_family_names[7] = { "mag_matrix", "mag_bias",
  "nargin", "nargout", "mag_row", "mag_calibration", "mag_calibrate" };

/* Function Declarations */
static void initialize_c15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance);
static void initialize_params_c15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance);
static void enable_c15_ekffedepre(SFc15_ekffedepreInstanceStruct *chartInstance);
static void disable_c15_ekffedepre(SFc15_ekffedepreInstanceStruct *chartInstance);
static void c15_update_debugger_state_c15_ekffedepre
  (SFc15_ekffedepreInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_ekffedepre
  (SFc15_ekffedepreInstanceStruct *chartInstance);
static void set_sim_state_c15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c15_st);
static void finalize_c15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance);
static void sf_c15_ekffedepre(SFc15_ekffedepreInstanceStruct *chartInstance);
static void c15_chartstep_c15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance);
static void initSimStructsc15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c15_mag_calibrate, const char_T *c15_identifier, real_T c15_y[3]);
static void c15_b_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[3]);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_c_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_d_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[9]);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static void c15_eml_scalar_eg(SFc15_ekffedepreInstanceStruct *chartInstance);
static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_e_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_f_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_ekffedepre, const char_T
  *c15_identifier);
static uint8_T c15_g_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info(SFc15_ekffedepreInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c15_is_active_c15_ekffedepre = 0U;
}

static void initialize_params_c15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance)
{
}

static void enable_c15_ekffedepre(SFc15_ekffedepreInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c15_ekffedepre(SFc15_ekffedepreInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c15_update_debugger_state_c15_ekffedepre
  (SFc15_ekffedepreInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c15_ekffedepre
  (SFc15_ekffedepreInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  int32_T c15_i0;
  real_T c15_u[3];
  const mxArray *c15_b_y = NULL;
  uint8_T c15_hoistedGlobal;
  uint8_T c15_b_u;
  const mxArray *c15_c_y = NULL;
  real_T (*c15_mag_calibrate)[3];
  c15_mag_calibrate = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellarray(2));
  for (c15_i0 = 0; c15_i0 < 3; c15_i0++) {
    c15_u[c15_i0] = (*c15_mag_calibrate)[c15_i0];
  }

  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_hoistedGlobal = chartInstance->c15_is_active_c15_ekffedepre;
  c15_b_u = c15_hoistedGlobal;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c15_y, 1, c15_c_y);
  sf_mex_assign(&c15_st, c15_y);
  return c15_st;
}

static void set_sim_state_c15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c15_st)
{
  const mxArray *c15_u;
  real_T c15_dv0[3];
  int32_T c15_i1;
  real_T (*c15_mag_calibrate)[3];
  c15_mag_calibrate = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c15_doneDoubleBufferReInit = TRUE;
  c15_u = sf_mex_dup(c15_st);
  c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 0)),
                       "mag_calibrate", c15_dv0);
  for (c15_i1 = 0; c15_i1 < 3; c15_i1++) {
    (*c15_mag_calibrate)[c15_i1] = c15_dv0[c15_i1];
  }

  chartInstance->c15_is_active_c15_ekffedepre = c15_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 1)),
     "is_active_c15_ekffedepre");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_ekffedepre(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance)
{
}

static void sf_c15_ekffedepre(SFc15_ekffedepreInstanceStruct *chartInstance)
{
  int32_T c15_i2;
  int32_T c15_i3;
  int32_T c15_i4;
  real_T (*c15_mag_calibration)[12];
  real_T (*c15_mag_calibrate)[3];
  real_T (*c15_mag_row)[3];
  c15_mag_calibration = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 1);
  c15_mag_calibrate = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_mag_row = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  for (c15_i2 = 0; c15_i2 < 3; c15_i2++) {
    _SFD_DATA_RANGE_CHECK((*c15_mag_row)[c15_i2], 0U);
  }

  for (c15_i3 = 0; c15_i3 < 3; c15_i3++) {
    _SFD_DATA_RANGE_CHECK((*c15_mag_calibrate)[c15_i3], 1U);
  }

  for (c15_i4 = 0; c15_i4 < 12; c15_i4++) {
    _SFD_DATA_RANGE_CHECK((*c15_mag_calibration)[c15_i4], 2U);
  }

  chartInstance->c15_sfEvent = CALL_EVENT;
  c15_chartstep_c15_ekffedepre(chartInstance);
  sf_debug_check_for_state_inconsistency(_ekffedepreMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c15_chartstep_c15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance)
{
  int32_T c15_i5;
  real_T c15_mag_row[3];
  int32_T c15_i6;
  real_T c15_mag_calibration[12];
  uint32_T c15_debug_family_var_map[7];
  real_T c15_mag_matrix[9];
  real_T c15_mag_bias[3];
  real_T c15_nargin = 2.0;
  real_T c15_nargout = 1.0;
  real_T c15_mag_calibrate[3];
  int32_T c15_i7;
  real_T c15_a[9];
  int32_T c15_i8;
  real_T c15_b[3];
  int32_T c15_i9;
  real_T c15_y[3];
  int32_T c15_i10;
  int32_T c15_i11;
  int32_T c15_i12;
  int32_T c15_i13;
  real_T (*c15_b_mag_calibrate)[3];
  real_T (*c15_b_mag_calibration)[12];
  real_T (*c15_b_mag_row)[3];
  c15_b_mag_calibration = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S,
    1);
  c15_b_mag_calibrate = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_b_mag_row = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  for (c15_i5 = 0; c15_i5 < 3; c15_i5++) {
    c15_mag_row[c15_i5] = (*c15_b_mag_row)[c15_i5];
  }

  for (c15_i6 = 0; c15_i6 < 12; c15_i6++) {
    c15_mag_calibration[c15_i6] = (*c15_b_mag_calibration)[c15_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c15_debug_family_names,
    c15_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c15_mag_matrix, 0U,
    c15_d_sf_marshallOut, c15_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c15_mag_bias, 1U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c15_nargin, 2U, c15_c_sf_marshallOut,
    c15_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c15_nargout, 3U,
    c15_c_sf_marshallOut, c15_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c15_mag_row, 4U, c15_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c15_mag_calibration, 5U, c15_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c15_mag_calibrate, 6U,
    c15_sf_marshallOut, c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 4);
  c15_mag_matrix[0] = c15_mag_calibration[0];
  c15_mag_matrix[3] = c15_mag_calibration[1];
  c15_mag_matrix[6] = c15_mag_calibration[2];
  c15_mag_matrix[1] = c15_mag_calibration[3];
  c15_mag_matrix[4] = c15_mag_calibration[4];
  c15_mag_matrix[7] = c15_mag_calibration[5];
  c15_mag_matrix[2] = c15_mag_calibration[6];
  c15_mag_matrix[5] = c15_mag_calibration[7];
  c15_mag_matrix[8] = c15_mag_calibration[8];
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 8);
  c15_mag_bias[0] = c15_mag_calibration[9];
  c15_mag_bias[1] = c15_mag_calibration[10];
  c15_mag_bias[2] = c15_mag_calibration[11];
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 12);
  for (c15_i7 = 0; c15_i7 < 9; c15_i7++) {
    c15_a[c15_i7] = c15_mag_matrix[c15_i7];
  }

  for (c15_i8 = 0; c15_i8 < 3; c15_i8++) {
    c15_b[c15_i8] = c15_mag_row[c15_i8];
  }

  c15_eml_scalar_eg(chartInstance);
  c15_eml_scalar_eg(chartInstance);
  for (c15_i9 = 0; c15_i9 < 3; c15_i9++) {
    c15_y[c15_i9] = 0.0;
    c15_i10 = 0;
    for (c15_i11 = 0; c15_i11 < 3; c15_i11++) {
      c15_y[c15_i9] += c15_a[c15_i10 + c15_i9] * c15_b[c15_i11];
      c15_i10 += 3;
    }
  }

  for (c15_i12 = 0; c15_i12 < 3; c15_i12++) {
    c15_mag_calibrate[c15_i12] = c15_y[c15_i12] + c15_mag_bias[c15_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -12);
  sf_debug_symbol_scope_pop();
  for (c15_i13 = 0; c15_i13 < 3; c15_i13++) {
    (*c15_b_mag_calibrate)[c15_i13] = c15_mag_calibrate[c15_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
}

static void initSimStructsc15_ekffedepre(SFc15_ekffedepreInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber)
{
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i14;
  real_T c15_b_inData[3];
  int32_T c15_i15;
  real_T c15_u[3];
  const mxArray *c15_y = NULL;
  SFc15_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc15_ekffedepreInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i14 = 0; c15_i14 < 3; c15_i14++) {
    c15_b_inData[c15_i14] = (*(real_T (*)[3])c15_inData)[c15_i14];
  }

  for (c15_i15 = 0; c15_i15 < 3; c15_i15++) {
    c15_u[c15_i15] = c15_b_inData[c15_i15];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c15_mxArrayOutData, c15_y);
  return c15_mxArrayOutData;
}

static void c15_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c15_mag_calibrate, const char_T *c15_identifier, real_T c15_y[3])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_mag_calibrate),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_mag_calibrate);
}

static void c15_b_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[3])
{
  real_T c15_dv1[3];
  int32_T c15_i16;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c15_i16 = 0; c15_i16 < 3; c15_i16++) {
    c15_y[c15_i16] = c15_dv1[c15_i16];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_mag_calibrate;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[3];
  int32_T c15_i17;
  SFc15_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc15_ekffedepreInstanceStruct *)chartInstanceVoid;
  c15_mag_calibrate = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_mag_calibrate),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_mag_calibrate);
  for (c15_i17 = 0; c15_i17 < 3; c15_i17++) {
    (*(real_T (*)[3])c15_outData)[c15_i17] = c15_y[c15_i17];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i18;
  real_T c15_b_inData[12];
  int32_T c15_i19;
  real_T c15_u[12];
  const mxArray *c15_y = NULL;
  SFc15_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc15_ekffedepreInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i18 = 0; c15_i18 < 12; c15_i18++) {
    c15_b_inData[c15_i18] = (*(real_T (*)[12])c15_inData)[c15_i18];
  }

  for (c15_i19 = 0; c15_i19 < 12; c15_i19++) {
    c15_u[c15_i19] = c15_b_inData[c15_i19];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 12));
  sf_mex_assign(&c15_mxArrayOutData, c15_y);
  return c15_mxArrayOutData;
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc15_ekffedepreInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c15_mxArrayOutData, c15_y);
  return c15_mxArrayOutData;
}

static real_T c15_c_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d0, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_nargout;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc15_ekffedepreInstanceStruct *)chartInstanceVoid;
  c15_nargout = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_nargout),
    &c15_thisId);
  sf_mex_destroy(&c15_nargout);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i20;
  int32_T c15_i21;
  int32_T c15_i22;
  real_T c15_b_inData[9];
  int32_T c15_i23;
  int32_T c15_i24;
  int32_T c15_i25;
  real_T c15_u[9];
  const mxArray *c15_y = NULL;
  SFc15_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc15_ekffedepreInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_i20 = 0;
  for (c15_i21 = 0; c15_i21 < 3; c15_i21++) {
    for (c15_i22 = 0; c15_i22 < 3; c15_i22++) {
      c15_b_inData[c15_i22 + c15_i20] = (*(real_T (*)[9])c15_inData)[c15_i22 +
        c15_i20];
    }

    c15_i20 += 3;
  }

  c15_i23 = 0;
  for (c15_i24 = 0; c15_i24 < 3; c15_i24++) {
    for (c15_i25 = 0; c15_i25 < 3; c15_i25++) {
      c15_u[c15_i25 + c15_i23] = c15_b_inData[c15_i25 + c15_i23];
    }

    c15_i23 += 3;
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c15_mxArrayOutData, c15_y);
  return c15_mxArrayOutData;
}

static void c15_d_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId, real_T c15_y[9])
{
  real_T c15_dv2[9];
  int32_T c15_i26;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c15_i26 = 0; c15_i26 < 9; c15_i26++) {
    c15_y[c15_i26] = c15_dv2[c15_i26];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_mag_matrix;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[9];
  int32_T c15_i27;
  int32_T c15_i28;
  int32_T c15_i29;
  SFc15_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc15_ekffedepreInstanceStruct *)chartInstanceVoid;
  c15_mag_matrix = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_mag_matrix), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_mag_matrix);
  c15_i27 = 0;
  for (c15_i28 = 0; c15_i28 < 3; c15_i28++) {
    for (c15_i29 = 0; c15_i29 < 3; c15_i29++) {
      (*(real_T (*)[9])c15_outData)[c15_i29 + c15_i27] = c15_y[c15_i29 + c15_i27];
    }

    c15_i27 += 3;
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

const mxArray *sf_c15_ekffedepre_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo;
  c15_ResolvedFunctionInfo c15_info[12];
  c15_ResolvedFunctionInfo (*c15_b_info)[12];
  const mxArray *c15_m0 = NULL;
  int32_T c15_i30;
  c15_ResolvedFunctionInfo *c15_r0;
  c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  c15_b_info = (c15_ResolvedFunctionInfo (*)[12])c15_info;
  (*c15_b_info)[0].context = "";
  (*c15_b_info)[0].name = "mtimes";
  (*c15_b_info)[0].dominantType = "double";
  (*c15_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c15_b_info)[0].fileTimeLo = 3573034496U;
  (*c15_b_info)[0].fileTimeHi = 30114299U;
  (*c15_b_info)[0].mFileTimeLo = 0U;
  (*c15_b_info)[0].mFileTimeHi = 0U;
  (*c15_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c15_b_info)[1].name = "eml_index_class";
  (*c15_b_info)[1].dominantType = "";
  (*c15_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c15_b_info)[1].fileTimeLo = 1187391744U;
  (*c15_b_info)[1].fileTimeHi = 30108011U;
  (*c15_b_info)[1].mFileTimeLo = 0U;
  (*c15_b_info)[1].mFileTimeHi = 0U;
  (*c15_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c15_b_info)[2].name = "eml_scalar_eg";
  (*c15_b_info)[2].dominantType = "double";
  (*c15_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c15_b_info)[2].fileTimeLo = 1367391744U;
  (*c15_b_info)[2].fileTimeHi = 30108011U;
  (*c15_b_info)[2].mFileTimeLo = 0U;
  (*c15_b_info)[2].mFileTimeHi = 0U;
  (*c15_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c15_b_info)[3].name = "eml_xgemm";
  (*c15_b_info)[3].dominantType = "int32";
  (*c15_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c15_b_info)[3].fileTimeLo = 507391744U;
  (*c15_b_info)[3].fileTimeHi = 30108011U;
  (*c15_b_info)[3].mFileTimeLo = 0U;
  (*c15_b_info)[3].mFileTimeHi = 0U;
  (*c15_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  (*c15_b_info)[4].name = "length";
  (*c15_b_info)[4].dominantType = "double";
  (*c15_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c15_b_info)[4].fileTimeLo = 1007391744U;
  (*c15_b_info)[4].fileTimeHi = 30108011U;
  (*c15_b_info)[4].mFileTimeLo = 0U;
  (*c15_b_info)[4].mFileTimeHi = 0U;
  (*c15_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  (*c15_b_info)[5].name = "min";
  (*c15_b_info)[5].dominantType = "double";
  (*c15_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c15_b_info)[5].fileTimeLo = 367391744U;
  (*c15_b_info)[5].fileTimeHi = 30108011U;
  (*c15_b_info)[5].mFileTimeLo = 0U;
  (*c15_b_info)[5].mFileTimeHi = 0U;
  (*c15_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c15_b_info)[6].name = "eml_min_or_max";
  (*c15_b_info)[6].dominantType = "char";
  (*c15_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c15_b_info)[6].fileTimeLo = 1287391744U;
  (*c15_b_info)[6].fileTimeHi = 30108011U;
  (*c15_b_info)[6].mFileTimeLo = 0U;
  (*c15_b_info)[6].mFileTimeHi = 0U;
  (*c15_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c15_b_info)[7].name = "eml_scalexp_alloc";
  (*c15_b_info)[7].dominantType = "double";
  (*c15_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c15_b_info)[7].fileTimeLo = 1367391744U;
  (*c15_b_info)[7].fileTimeHi = 30108011U;
  (*c15_b_info)[7].mFileTimeLo = 0U;
  (*c15_b_info)[7].mFileTimeHi = 0U;
  (*c15_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c15_b_info)[8].name = "eml_refblas_xgemm";
  (*c15_b_info)[8].dominantType = "int32";
  (*c15_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c15_b_info)[8].fileTimeLo = 1227391744U;
  (*c15_b_info)[8].fileTimeHi = 30108011U;
  (*c15_b_info)[8].mFileTimeLo = 0U;
  (*c15_b_info)[8].mFileTimeHi = 0U;
  (*c15_b_info)[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c15_b_info)[9].name = "eml_index_minus";
  (*c15_b_info)[9].dominantType = "int32";
  (*c15_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  (*c15_b_info)[9].fileTimeLo = 1187391744U;
  (*c15_b_info)[9].fileTimeHi = 30108011U;
  (*c15_b_info)[9].mFileTimeLo = 0U;
  (*c15_b_info)[9].mFileTimeHi = 0U;
  (*c15_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c15_b_info)[10].name = "eml_index_times";
  (*c15_b_info)[10].dominantType = "int32";
  (*c15_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c15_b_info)[10].fileTimeLo = 1207391744U;
  (*c15_b_info)[10].fileTimeHi = 30108011U;
  (*c15_b_info)[10].mFileTimeLo = 0U;
  (*c15_b_info)[10].mFileTimeHi = 0U;
  (*c15_b_info)[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c15_b_info)[11].name = "eml_index_plus";
  (*c15_b_info)[11].dominantType = "int32";
  (*c15_b_info)[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c15_b_info)[11].fileTimeLo = 1187391744U;
  (*c15_b_info)[11].fileTimeHi = 30108011U;
  (*c15_b_info)[11].mFileTimeLo = 0U;
  (*c15_b_info)[11].mFileTimeHi = 0U;
  sf_mex_assign(&c15_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12));
  for (c15_i30 = 0; c15_i30 < 12; c15_i30++) {
    c15_r0 = &c15_info[c15_i30];
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->context)), "context", "nameCaptureInfo",
                    c15_i30);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->name)), "name", "nameCaptureInfo",
                    c15_i30);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      c15_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c15_i30);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->resolved)), "resolved",
                    "nameCaptureInfo", c15_i30);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c15_i30);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c15_i30);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      &c15_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c15_i30);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      &c15_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c15_i30);
  }

  sf_mex_assign(&c15_nameCaptureInfo, c15_m0);
  return c15_nameCaptureInfo;
}

static void c15_eml_scalar_eg(SFc15_ekffedepreInstanceStruct *chartInstance)
{
}

static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc15_ekffedepreInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c15_mxArrayOutData, c15_y);
  return c15_mxArrayOutData;
}

static int32_T c15_e_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i31;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i31, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i31;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc15_ekffedepreInstanceStruct *)chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_f_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_ekffedepre, const char_T
  *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_ekffedepre), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_ekffedepre);
  return c15_y;
}

static uint8_T c15_g_emlrt_marshallIn(SFc15_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info(SFc15_ekffedepreInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c15_ekffedepre_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1418534628U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1478102396U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1006035286U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2795959334U);
}

mxArray *sf_c15_ekffedepre_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1249709716U);
    pr[1] = (double)(66226331U);
    pr[2] = (double)(2861518464U);
    pr[3] = (double)(3303736457U);
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
      pr[0] = (double)(12);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c15_ekffedepre(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"mag_calibrate\",},{M[8],M[0],T\"is_active_c15_ekffedepre\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_ekffedepre_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_ekffedepreInstanceStruct *chartInstance;
    chartInstance = (SFc15_ekffedepreInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_ekffedepreMachineNumber_,
           15,
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
          init_script_number_translation(_ekffedepreMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_ekffedepreMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_ekffedepreMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"mag_row");
          _SFD_SET_DATA_PROPS(1,2,0,1,"mag_calibrate");
          _SFD_SET_DATA_PROPS(2,1,1,0,"mag_calibration");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,452);
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
            1.0,0,0,(MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)
            c15_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c15_mag_row)[3];
          real_T (*c15_mag_calibrate)[3];
          real_T (*c15_mag_calibration)[12];
          c15_mag_calibration = (real_T (*)[12])ssGetInputPortSignal
            (chartInstance->S, 1);
          c15_mag_calibrate = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c15_mag_row = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c15_mag_row);
          _SFD_SET_DATA_VALUE_PTR(1U, *c15_mag_calibrate);
          _SFD_SET_DATA_VALUE_PTR(2U, *c15_mag_calibration);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ekffedepreMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c15_ekffedepre(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_ekffedepreInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c15_ekffedepre((SFc15_ekffedepreInstanceStruct*)
    chartInstanceVar);
  initialize_c15_ekffedepre((SFc15_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c15_ekffedepre(void *chartInstanceVar)
{
  enable_c15_ekffedepre((SFc15_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c15_ekffedepre(void *chartInstanceVar)
{
  disable_c15_ekffedepre((SFc15_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c15_ekffedepre(void *chartInstanceVar)
{
  sf_c15_ekffedepre((SFc15_ekffedepreInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c15_ekffedepre(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c15_ekffedepre
    ((SFc15_ekffedepreInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_ekffedepre();/* state var info */
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

extern void sf_internal_set_sim_state_c15_ekffedepre(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_ekffedepre();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c15_ekffedepre((SFc15_ekffedepreInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c15_ekffedepre(SimStruct* S)
{
  return sf_internal_get_sim_state_c15_ekffedepre(S);
}

static void sf_opaque_set_sim_state_c15_ekffedepre(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c15_ekffedepre(S, st);
}

static void sf_opaque_terminate_c15_ekffedepre(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_ekffedepreInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c15_ekffedepre((SFc15_ekffedepreInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_ekffedepre((SFc15_ekffedepreInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_ekffedepre(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c15_ekffedepre((SFc15_ekffedepreInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_ekffedepre(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ekffedepre","ekffedepre",15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ekffedepre","ekffedepre",15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ekffedepre",
      "ekffedepre",15,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ekffedepre","ekffedepre",15,2);
      sf_mark_chart_reusable_outputs(S,"ekffedepre","ekffedepre",15,1);
    }

    sf_set_rtw_dwork_info(S,"ekffedepre","ekffedepre",15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2320380948U));
  ssSetChecksum1(S,(1460731621U));
  ssSetChecksum2(S,(2608256866U));
  ssSetChecksum3(S,(3197821797U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c15_ekffedepre(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ekffedepre", "ekffedepre",15);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_ekffedepre(SimStruct *S)
{
  SFc15_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc15_ekffedepreInstanceStruct *)malloc(sizeof
    (SFc15_ekffedepreInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_ekffedepreInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c15_ekffedepre;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c15_ekffedepre;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c15_ekffedepre;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c15_ekffedepre;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c15_ekffedepre;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c15_ekffedepre;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c15_ekffedepre;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_ekffedepre;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_ekffedepre;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_ekffedepre;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c15_ekffedepre;
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

void c15_ekffedepre_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_ekffedepre(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_ekffedepre(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_ekffedepre(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_ekffedepre_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
