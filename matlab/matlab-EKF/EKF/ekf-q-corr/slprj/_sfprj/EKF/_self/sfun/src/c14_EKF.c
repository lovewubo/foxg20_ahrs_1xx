/* Include files */

#include "blascompat32.h"
#include "EKF_sfun.h"
#include "c14_EKF.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EKF_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c14_debug_family_names[7] = { "acc_matrix", "acc_bias",
  "nargin", "nargout", "acc_row", "acc_calibration", "Acc_calibrate" };

/* Function Declarations */
static void initialize_c14_EKF(SFc14_EKFInstanceStruct *chartInstance);
static void initialize_params_c14_EKF(SFc14_EKFInstanceStruct *chartInstance);
static void enable_c14_EKF(SFc14_EKFInstanceStruct *chartInstance);
static void disable_c14_EKF(SFc14_EKFInstanceStruct *chartInstance);
static void c14_update_debugger_state_c14_EKF(SFc14_EKFInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c14_EKF(SFc14_EKFInstanceStruct
  *chartInstance);
static void set_sim_state_c14_EKF(SFc14_EKFInstanceStruct *chartInstance, const
  mxArray *c14_st);
static void finalize_c14_EKF(SFc14_EKFInstanceStruct *chartInstance);
static void sf_c14_EKF(SFc14_EKFInstanceStruct *chartInstance);
static void c14_chartstep_c14_EKF(SFc14_EKFInstanceStruct *chartInstance);
static void initSimStructsc14_EKF(SFc14_EKFInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance, const
  mxArray *c14_Acc_calibrate, const char_T *c14_identifier, real_T c14_y[3]);
static void c14_b_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance, const
  mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[3]);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_c_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_d_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance, const
  mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[9]);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static void c14_eml_scalar_eg(SFc14_EKFInstanceStruct *chartInstance);
static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_e_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_f_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance,
  const mxArray *c14_b_is_active_c14_EKF, const char_T *c14_identifier);
static uint8_T c14_g_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void init_dsm_address_info(SFc14_EKFInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c14_EKF(SFc14_EKFInstanceStruct *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c14_is_active_c14_EKF = 0U;
}

static void initialize_params_c14_EKF(SFc14_EKFInstanceStruct *chartInstance)
{
}

static void enable_c14_EKF(SFc14_EKFInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c14_EKF(SFc14_EKFInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c14_update_debugger_state_c14_EKF(SFc14_EKFInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c14_EKF(SFc14_EKFInstanceStruct
  *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  int32_T c14_i0;
  real_T c14_u[3];
  const mxArray *c14_b_y = NULL;
  uint8_T c14_hoistedGlobal;
  uint8_T c14_b_u;
  const mxArray *c14_c_y = NULL;
  real_T (*c14_Acc_calibrate)[3];
  c14_Acc_calibrate = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellarray(2));
  for (c14_i0 = 0; c14_i0 < 3; c14_i0++) {
    c14_u[c14_i0] = (*c14_Acc_calibrate)[c14_i0];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_hoistedGlobal = chartInstance->c14_is_active_c14_EKF;
  c14_b_u = c14_hoistedGlobal;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c14_y, 1, c14_c_y);
  sf_mex_assign(&c14_st, c14_y);
  return c14_st;
}

static void set_sim_state_c14_EKF(SFc14_EKFInstanceStruct *chartInstance, const
  mxArray *c14_st)
{
  const mxArray *c14_u;
  real_T c14_dv0[3];
  int32_T c14_i1;
  real_T (*c14_Acc_calibrate)[3];
  c14_Acc_calibrate = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c14_doneDoubleBufferReInit = TRUE;
  c14_u = sf_mex_dup(c14_st);
  c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 0)),
                       "Acc_calibrate", c14_dv0);
  for (c14_i1 = 0; c14_i1 < 3; c14_i1++) {
    (*c14_Acc_calibrate)[c14_i1] = c14_dv0[c14_i1];
  }

  chartInstance->c14_is_active_c14_EKF = c14_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c14_u, 1)), "is_active_c14_EKF");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_EKF(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_EKF(SFc14_EKFInstanceStruct *chartInstance)
{
}

static void sf_c14_EKF(SFc14_EKFInstanceStruct *chartInstance)
{
  int32_T c14_i2;
  int32_T c14_i3;
  int32_T c14_i4;
  real_T (*c14_acc_calibration)[12];
  real_T (*c14_Acc_calibrate)[3];
  real_T (*c14_acc_row)[3];
  c14_acc_calibration = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 1);
  c14_Acc_calibrate = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_acc_row = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c14_sfEvent);
  for (c14_i2 = 0; c14_i2 < 3; c14_i2++) {
    _SFD_DATA_RANGE_CHECK((*c14_acc_row)[c14_i2], 0U);
  }

  for (c14_i3 = 0; c14_i3 < 3; c14_i3++) {
    _SFD_DATA_RANGE_CHECK((*c14_Acc_calibrate)[c14_i3], 1U);
  }

  for (c14_i4 = 0; c14_i4 < 12; c14_i4++) {
    _SFD_DATA_RANGE_CHECK((*c14_acc_calibration)[c14_i4], 2U);
  }

  chartInstance->c14_sfEvent = CALL_EVENT;
  c14_chartstep_c14_EKF(chartInstance);
  sf_debug_check_for_state_inconsistency(_EKFMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c14_chartstep_c14_EKF(SFc14_EKFInstanceStruct *chartInstance)
{
  int32_T c14_i5;
  real_T c14_acc_row[3];
  int32_T c14_i6;
  real_T c14_acc_calibration[12];
  uint32_T c14_debug_family_var_map[7];
  real_T c14_acc_matrix[9];
  real_T c14_acc_bias[3];
  real_T c14_nargin = 2.0;
  real_T c14_nargout = 1.0;
  real_T c14_Acc_calibrate[3];
  int32_T c14_i7;
  real_T c14_a[9];
  int32_T c14_i8;
  real_T c14_b[3];
  int32_T c14_i9;
  real_T c14_y[3];
  int32_T c14_i10;
  int32_T c14_i11;
  int32_T c14_i12;
  int32_T c14_i13;
  real_T (*c14_b_Acc_calibrate)[3];
  real_T (*c14_b_acc_calibration)[12];
  real_T (*c14_b_acc_row)[3];
  c14_b_acc_calibration = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S,
    1);
  c14_b_Acc_calibrate = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_b_acc_row = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c14_sfEvent);
  for (c14_i5 = 0; c14_i5 < 3; c14_i5++) {
    c14_acc_row[c14_i5] = (*c14_b_acc_row)[c14_i5];
  }

  for (c14_i6 = 0; c14_i6 < 12; c14_i6++) {
    c14_acc_calibration[c14_i6] = (*c14_b_acc_calibration)[c14_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c14_debug_family_names,
    c14_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c14_acc_matrix, 0U,
    c14_d_sf_marshallOut, c14_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c14_acc_bias, 1U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c14_nargin, 2U, c14_c_sf_marshallOut,
    c14_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c14_nargout, 3U,
    c14_c_sf_marshallOut, c14_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c14_acc_row, 4U, c14_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c14_acc_calibration, 5U, c14_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c14_Acc_calibrate, 6U,
    c14_sf_marshallOut, c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 4);
  c14_acc_matrix[0] = c14_acc_calibration[0];
  c14_acc_matrix[3] = c14_acc_calibration[1];
  c14_acc_matrix[6] = c14_acc_calibration[2];
  c14_acc_matrix[1] = c14_acc_calibration[3];
  c14_acc_matrix[4] = c14_acc_calibration[4];
  c14_acc_matrix[7] = c14_acc_calibration[5];
  c14_acc_matrix[2] = c14_acc_calibration[6];
  c14_acc_matrix[5] = c14_acc_calibration[7];
  c14_acc_matrix[8] = c14_acc_calibration[8];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 8);
  c14_acc_bias[0] = c14_acc_calibration[9];
  c14_acc_bias[1] = c14_acc_calibration[10];
  c14_acc_bias[2] = c14_acc_calibration[11];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 12);
  for (c14_i7 = 0; c14_i7 < 9; c14_i7++) {
    c14_a[c14_i7] = c14_acc_matrix[c14_i7];
  }

  for (c14_i8 = 0; c14_i8 < 3; c14_i8++) {
    c14_b[c14_i8] = c14_acc_row[c14_i8];
  }

  c14_eml_scalar_eg(chartInstance);
  c14_eml_scalar_eg(chartInstance);
  for (c14_i9 = 0; c14_i9 < 3; c14_i9++) {
    c14_y[c14_i9] = 0.0;
    c14_i10 = 0;
    for (c14_i11 = 0; c14_i11 < 3; c14_i11++) {
      c14_y[c14_i9] += c14_a[c14_i10 + c14_i9] * c14_b[c14_i11];
      c14_i10 += 3;
    }
  }

  for (c14_i12 = 0; c14_i12 < 3; c14_i12++) {
    c14_Acc_calibrate[c14_i12] = c14_y[c14_i12] + c14_acc_bias[c14_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -12);
  sf_debug_symbol_scope_pop();
  for (c14_i13 = 0; c14_i13 < 3; c14_i13++) {
    (*c14_b_Acc_calibrate)[c14_i13] = c14_Acc_calibrate[c14_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c14_sfEvent);
}

static void initSimStructsc14_EKF(SFc14_EKFInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber)
{
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i14;
  real_T c14_b_inData[3];
  int32_T c14_i15;
  real_T c14_u[3];
  const mxArray *c14_y = NULL;
  SFc14_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc14_EKFInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i14 = 0; c14_i14 < 3; c14_i14++) {
    c14_b_inData[c14_i14] = (*(real_T (*)[3])c14_inData)[c14_i14];
  }

  for (c14_i15 = 0; c14_i15 < 3; c14_i15++) {
    c14_u[c14_i15] = c14_b_inData[c14_i15];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c14_mxArrayOutData, c14_y);
  return c14_mxArrayOutData;
}

static void c14_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance, const
  mxArray *c14_Acc_calibrate, const char_T *c14_identifier, real_T c14_y[3])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_Acc_calibrate),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_Acc_calibrate);
}

static void c14_b_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance, const
  mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[3])
{
  real_T c14_dv1[3];
  int32_T c14_i16;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c14_i16 = 0; c14_i16 < 3; c14_i16++) {
    c14_y[c14_i16] = c14_dv1[c14_i16];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_Acc_calibrate;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[3];
  int32_T c14_i17;
  SFc14_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc14_EKFInstanceStruct *)chartInstanceVoid;
  c14_Acc_calibrate = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_Acc_calibrate),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_Acc_calibrate);
  for (c14_i17 = 0; c14_i17 < 3; c14_i17++) {
    (*(real_T (*)[3])c14_outData)[c14_i17] = c14_y[c14_i17];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i18;
  real_T c14_b_inData[12];
  int32_T c14_i19;
  real_T c14_u[12];
  const mxArray *c14_y = NULL;
  SFc14_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc14_EKFInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i18 = 0; c14_i18 < 12; c14_i18++) {
    c14_b_inData[c14_i18] = (*(real_T (*)[12])c14_inData)[c14_i18];
  }

  for (c14_i19 = 0; c14_i19 < 12; c14_i19++) {
    c14_u[c14_i19] = c14_b_inData[c14_i19];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 12));
  sf_mex_assign(&c14_mxArrayOutData, c14_y);
  return c14_mxArrayOutData;
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc14_EKFInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c14_mxArrayOutData, c14_y);
  return c14_mxArrayOutData;
}

static real_T c14_c_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_nargout;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc14_EKFInstanceStruct *)chartInstanceVoid;
  c14_nargout = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_nargout),
    &c14_thisId);
  sf_mex_destroy(&c14_nargout);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i20;
  int32_T c14_i21;
  int32_T c14_i22;
  real_T c14_b_inData[9];
  int32_T c14_i23;
  int32_T c14_i24;
  int32_T c14_i25;
  real_T c14_u[9];
  const mxArray *c14_y = NULL;
  SFc14_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc14_EKFInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_i20 = 0;
  for (c14_i21 = 0; c14_i21 < 3; c14_i21++) {
    for (c14_i22 = 0; c14_i22 < 3; c14_i22++) {
      c14_b_inData[c14_i22 + c14_i20] = (*(real_T (*)[9])c14_inData)[c14_i22 +
        c14_i20];
    }

    c14_i20 += 3;
  }

  c14_i23 = 0;
  for (c14_i24 = 0; c14_i24 < 3; c14_i24++) {
    for (c14_i25 = 0; c14_i25 < 3; c14_i25++) {
      c14_u[c14_i25 + c14_i23] = c14_b_inData[c14_i25 + c14_i23];
    }

    c14_i23 += 3;
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c14_mxArrayOutData, c14_y);
  return c14_mxArrayOutData;
}

static void c14_d_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance, const
  mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId, real_T c14_y[9])
{
  real_T c14_dv2[9];
  int32_T c14_i26;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c14_i26 = 0; c14_i26 < 9; c14_i26++) {
    c14_y[c14_i26] = c14_dv2[c14_i26];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_acc_matrix;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[9];
  int32_T c14_i27;
  int32_T c14_i28;
  int32_T c14_i29;
  SFc14_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc14_EKFInstanceStruct *)chartInstanceVoid;
  c14_acc_matrix = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_acc_matrix), &c14_thisId,
    c14_y);
  sf_mex_destroy(&c14_acc_matrix);
  c14_i27 = 0;
  for (c14_i28 = 0; c14_i28 < 3; c14_i28++) {
    for (c14_i29 = 0; c14_i29 < 3; c14_i29++) {
      (*(real_T (*)[9])c14_outData)[c14_i29 + c14_i27] = c14_y[c14_i29 + c14_i27];
    }

    c14_i27 += 3;
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray *sf_c14_EKF_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo;
  c14_ResolvedFunctionInfo c14_info[12];
  c14_ResolvedFunctionInfo (*c14_b_info)[12];
  const mxArray *c14_m0 = NULL;
  int32_T c14_i30;
  c14_ResolvedFunctionInfo *c14_r0;
  c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  c14_b_info = (c14_ResolvedFunctionInfo (*)[12])c14_info;
  (*c14_b_info)[0].context = "";
  (*c14_b_info)[0].name = "mtimes";
  (*c14_b_info)[0].dominantType = "double";
  (*c14_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c14_b_info)[0].fileTimeLo = 3573034496U;
  (*c14_b_info)[0].fileTimeHi = 30114299U;
  (*c14_b_info)[0].mFileTimeLo = 0U;
  (*c14_b_info)[0].mFileTimeHi = 0U;
  (*c14_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c14_b_info)[1].name = "eml_index_class";
  (*c14_b_info)[1].dominantType = "";
  (*c14_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c14_b_info)[1].fileTimeLo = 1187391744U;
  (*c14_b_info)[1].fileTimeHi = 30108011U;
  (*c14_b_info)[1].mFileTimeLo = 0U;
  (*c14_b_info)[1].mFileTimeHi = 0U;
  (*c14_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c14_b_info)[2].name = "eml_scalar_eg";
  (*c14_b_info)[2].dominantType = "double";
  (*c14_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c14_b_info)[2].fileTimeLo = 1367391744U;
  (*c14_b_info)[2].fileTimeHi = 30108011U;
  (*c14_b_info)[2].mFileTimeLo = 0U;
  (*c14_b_info)[2].mFileTimeHi = 0U;
  (*c14_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c14_b_info)[3].name = "eml_xgemm";
  (*c14_b_info)[3].dominantType = "int32";
  (*c14_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c14_b_info)[3].fileTimeLo = 507391744U;
  (*c14_b_info)[3].fileTimeHi = 30108011U;
  (*c14_b_info)[3].mFileTimeLo = 0U;
  (*c14_b_info)[3].mFileTimeHi = 0U;
  (*c14_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  (*c14_b_info)[4].name = "length";
  (*c14_b_info)[4].dominantType = "double";
  (*c14_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c14_b_info)[4].fileTimeLo = 1007391744U;
  (*c14_b_info)[4].fileTimeHi = 30108011U;
  (*c14_b_info)[4].mFileTimeLo = 0U;
  (*c14_b_info)[4].mFileTimeHi = 0U;
  (*c14_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  (*c14_b_info)[5].name = "min";
  (*c14_b_info)[5].dominantType = "double";
  (*c14_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c14_b_info)[5].fileTimeLo = 367391744U;
  (*c14_b_info)[5].fileTimeHi = 30108011U;
  (*c14_b_info)[5].mFileTimeLo = 0U;
  (*c14_b_info)[5].mFileTimeHi = 0U;
  (*c14_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c14_b_info)[6].name = "eml_min_or_max";
  (*c14_b_info)[6].dominantType = "char";
  (*c14_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c14_b_info)[6].fileTimeLo = 1287391744U;
  (*c14_b_info)[6].fileTimeHi = 30108011U;
  (*c14_b_info)[6].mFileTimeLo = 0U;
  (*c14_b_info)[6].mFileTimeHi = 0U;
  (*c14_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c14_b_info)[7].name = "eml_scalexp_alloc";
  (*c14_b_info)[7].dominantType = "double";
  (*c14_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c14_b_info)[7].fileTimeLo = 1367391744U;
  (*c14_b_info)[7].fileTimeHi = 30108011U;
  (*c14_b_info)[7].mFileTimeLo = 0U;
  (*c14_b_info)[7].mFileTimeHi = 0U;
  (*c14_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c14_b_info)[8].name = "eml_refblas_xgemm";
  (*c14_b_info)[8].dominantType = "int32";
  (*c14_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c14_b_info)[8].fileTimeLo = 1227391744U;
  (*c14_b_info)[8].fileTimeHi = 30108011U;
  (*c14_b_info)[8].mFileTimeLo = 0U;
  (*c14_b_info)[8].mFileTimeHi = 0U;
  (*c14_b_info)[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c14_b_info)[9].name = "eml_index_minus";
  (*c14_b_info)[9].dominantType = "int32";
  (*c14_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  (*c14_b_info)[9].fileTimeLo = 1187391744U;
  (*c14_b_info)[9].fileTimeHi = 30108011U;
  (*c14_b_info)[9].mFileTimeLo = 0U;
  (*c14_b_info)[9].mFileTimeHi = 0U;
  (*c14_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c14_b_info)[10].name = "eml_index_times";
  (*c14_b_info)[10].dominantType = "int32";
  (*c14_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c14_b_info)[10].fileTimeLo = 1207391744U;
  (*c14_b_info)[10].fileTimeHi = 30108011U;
  (*c14_b_info)[10].mFileTimeLo = 0U;
  (*c14_b_info)[10].mFileTimeHi = 0U;
  (*c14_b_info)[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c14_b_info)[11].name = "eml_index_plus";
  (*c14_b_info)[11].dominantType = "int32";
  (*c14_b_info)[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c14_b_info)[11].fileTimeLo = 1187391744U;
  (*c14_b_info)[11].fileTimeHi = 30108011U;
  (*c14_b_info)[11].mFileTimeLo = 0U;
  (*c14_b_info)[11].mFileTimeHi = 0U;
  sf_mex_assign(&c14_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12));
  for (c14_i30 = 0; c14_i30 < 12; c14_i30++) {
    c14_r0 = &c14_info[c14_i30];
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->context)), "context", "nameCaptureInfo",
                    c14_i30);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->name)), "name", "nameCaptureInfo",
                    c14_i30);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      c14_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c14_i30);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->resolved)), "resolved",
                    "nameCaptureInfo", c14_i30);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c14_i30);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c14_i30);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c14_i30);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c14_i30);
  }

  sf_mex_assign(&c14_nameCaptureInfo, c14_m0);
  return c14_nameCaptureInfo;
}

static void c14_eml_scalar_eg(SFc14_EKFInstanceStruct *chartInstance)
{
}

static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc14_EKFInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c14_mxArrayOutData, c14_y);
  return c14_mxArrayOutData;
}

static int32_T c14_e_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i31;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i31, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i31;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc14_EKFInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_f_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance,
  const mxArray *c14_b_is_active_c14_EKF, const char_T *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_EKF), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_EKF);
  return c14_y;
}

static uint8_T c14_g_emlrt_marshallIn(SFc14_EKFInstanceStruct *chartInstance,
  const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void init_dsm_address_info(SFc14_EKFInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c14_EKF_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1938827961U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1107098318U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4174145962U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1712606483U);
}

mxArray *sf_c14_EKF_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1990016875U);
    pr[1] = (double)(3189232101U);
    pr[2] = (double)(28583981U);
    pr[3] = (double)(3998307222U);
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

static const mxArray *sf_get_sim_state_info_c14_EKF(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Acc_calibrate\",},{M[8],M[0],T\"is_active_c14_EKF\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_EKF_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_EKFInstanceStruct *chartInstance;
    chartInstance = (SFc14_EKFInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_EKFMachineNumber_,
          14,
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
          init_script_number_translation(_EKFMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_EKFMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_EKFMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"acc_row");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Acc_calibrate");
          _SFD_SET_DATA_PROPS(2,1,1,0,"acc_calibration");
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
            1.0,0,0,(MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)
            c14_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c14_acc_row)[3];
          real_T (*c14_Acc_calibrate)[3];
          real_T (*c14_acc_calibration)[12];
          c14_acc_calibration = (real_T (*)[12])ssGetInputPortSignal
            (chartInstance->S, 1);
          c14_Acc_calibrate = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c14_acc_row = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c14_acc_row);
          _SFD_SET_DATA_VALUE_PTR(1U, *c14_Acc_calibrate);
          _SFD_SET_DATA_VALUE_PTR(2U, *c14_acc_calibration);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_EKFMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c14_EKF(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_EKFInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c14_EKF((SFc14_EKFInstanceStruct*) chartInstanceVar);
  initialize_c14_EKF((SFc14_EKFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c14_EKF(void *chartInstanceVar)
{
  enable_c14_EKF((SFc14_EKFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c14_EKF(void *chartInstanceVar)
{
  disable_c14_EKF((SFc14_EKFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c14_EKF(void *chartInstanceVar)
{
  sf_c14_EKF((SFc14_EKFInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c14_EKF(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_EKF((SFc14_EKFInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_EKF();/* state var info */
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

extern void sf_internal_set_sim_state_c14_EKF(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_EKF();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_EKF((SFc14_EKFInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c14_EKF(SimStruct* S)
{
  return sf_internal_get_sim_state_c14_EKF(S);
}

static void sf_opaque_set_sim_state_c14_EKF(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c14_EKF(S, st);
}

static void sf_opaque_terminate_c14_EKF(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_EKFInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c14_EKF((SFc14_EKFInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc14_EKF((SFc14_EKFInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_EKF(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c14_EKF((SFc14_EKFInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_EKF(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"EKF","EKF",14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"EKF","EKF",14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"EKF","EKF",14,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"EKF","EKF",14,2);
      sf_mark_chart_reusable_outputs(S,"EKF","EKF",14,1);
    }

    sf_set_rtw_dwork_info(S,"EKF","EKF",14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4037964606U));
  ssSetChecksum1(S,(1548781814U));
  ssSetChecksum2(S,(810072888U));
  ssSetChecksum3(S,(1447538176U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c14_EKF(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "EKF", "EKF",14);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_EKF(SimStruct *S)
{
  SFc14_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc14_EKFInstanceStruct *)malloc(sizeof
    (SFc14_EKFInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_EKFInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c14_EKF;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c14_EKF;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c14_EKF;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_EKF;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_EKF;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c14_EKF;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c14_EKF;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c14_EKF;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_EKF;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_EKF;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c14_EKF;
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

void c14_EKF_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_EKF(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_EKF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_EKF(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_EKF_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
