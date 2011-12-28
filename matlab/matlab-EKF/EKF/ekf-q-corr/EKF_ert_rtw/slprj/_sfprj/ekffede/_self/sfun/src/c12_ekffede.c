/* Include files */

#include "blascompat32.h"
#include "ekffede_sfun.h"
#include "c12_ekffede.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ekffede_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c12_debug_family_names[4] = { "nargin", "nargout", "Q_bias",
  "y" };

/* Function Declarations */
static void initialize_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance);
static void initialize_params_c12_ekffede(SFc12_ekffedeInstanceStruct
  *chartInstance);
static void enable_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance);
static void disable_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_ekffede(SFc12_ekffedeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c12_ekffede(SFc12_ekffedeInstanceStruct
  *chartInstance);
static void set_sim_state_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_st);
static void finalize_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance);
static void sf_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance);
static void initSimStructsc12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_y, const char_T *c12_identifier, real_T c12_b_y[9]);
static void c12_b_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[9]);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_c_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_d_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_e_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_b_is_active_c12_ekffede, const char_T *c12_identifier);
static uint8_T c12_f_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_ekffedeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c12_is_active_c12_ekffede = 0U;
}

static void initialize_params_c12_ekffede(SFc12_ekffedeInstanceStruct
  *chartInstance)
{
}

static void enable_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c12_update_debugger_state_c12_ekffede(SFc12_ekffedeInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c12_ekffede(SFc12_ekffedeInstanceStruct
  *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  int32_T c12_i0;
  real_T c12_u[9];
  const mxArray *c12_b_y = NULL;
  uint8_T c12_hoistedGlobal;
  uint8_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T (*c12_d_y)[9];
  c12_d_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(2));
  for (c12_i0 = 0; c12_i0 < 9; c12_i0++) {
    c12_u[c12_i0] = (*c12_d_y)[c12_i0];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_hoistedGlobal = chartInstance->c12_is_active_c12_ekffede;
  c12_b_u = c12_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c12_y, 1, c12_c_y);
  sf_mex_assign(&c12_st, c12_y);
  return c12_st;
}

static void set_sim_state_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_st)
{
  const mxArray *c12_u;
  real_T c12_dv0[9];
  int32_T c12_i1;
  real_T (*c12_y)[9];
  c12_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c12_doneDoubleBufferReInit = TRUE;
  c12_u = sf_mex_dup(c12_st);
  c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 0)), "y",
                       c12_dv0);
  for (c12_i1 = 0; c12_i1 < 9; c12_i1++) {
    (*c12_y)[c12_i1] = c12_dv0[c12_i1];
  }

  chartInstance->c12_is_active_c12_ekffede = c12_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 1)),
     "is_active_c12_ekffede");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_ekffede(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance)
{
}

static void sf_c12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance)
{
  int32_T c12_i2;
  int32_T c12_i3;
  int32_T c12_i4;
  real_T c12_Q_bias[3];
  uint32_T c12_debug_family_var_map[4];
  real_T c12_nargin = 1.0;
  real_T c12_nargout = 1.0;
  real_T c12_y[9];
  int32_T c12_i5;
  real_T c12_v[3];
  int32_T c12_i6;
  int32_T c12_j;
  int32_T c12_b_j;
  int32_T c12_a;
  int32_T c12_c;
  int32_T c12_i7;
  real_T (*c12_b_y)[9];
  real_T (*c12_b_Q_bias)[3];
  c12_b_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c12_b_Q_bias = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  for (c12_i2 = 0; c12_i2 < 3; c12_i2++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_Q_bias)[c12_i2], 0U);
  }

  for (c12_i3 = 0; c12_i3 < 9; c12_i3++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_y)[c12_i3], 1U);
  }

  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  for (c12_i4 = 0; c12_i4 < 3; c12_i4++) {
    c12_Q_bias[c12_i4] = (*c12_b_Q_bias)[c12_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c12_debug_family_names,
    c12_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargin, 0U, c12_c_sf_marshallOut,
    c12_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargout, 1U,
    c12_c_sf_marshallOut, c12_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c12_Q_bias, 2U, c12_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c12_y, 3U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 4);
  for (c12_i5 = 0; c12_i5 < 3; c12_i5++) {
    c12_v[c12_i5] = c12_Q_bias[c12_i5];
  }

  for (c12_i6 = 0; c12_i6 < 9; c12_i6++) {
    c12_y[c12_i6] = 0.0;
  }

  for (c12_j = 1; c12_j < 4; c12_j++) {
    c12_b_j = c12_j;
    c12_a = c12_b_j;
    c12_c = c12_a;
    c12_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c12_b_j), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c12_c), 1, 3, 2, 0) - 1)) -
      1] = c12_v[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c12_b_j), 1, 3, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c12_i7 = 0; c12_i7 < 9; c12_i7++) {
    (*c12_b_y)[c12_i7] = c12_y[c12_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  sf_debug_check_for_state_inconsistency(_ekffedeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc12_ekffede(SFc12_ekffedeInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i8;
  int32_T c12_i9;
  int32_T c12_i10;
  real_T c12_b_inData[9];
  int32_T c12_i11;
  int32_T c12_i12;
  int32_T c12_i13;
  real_T c12_u[9];
  const mxArray *c12_y = NULL;
  SFc12_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc12_ekffedeInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_i8 = 0;
  for (c12_i9 = 0; c12_i9 < 3; c12_i9++) {
    for (c12_i10 = 0; c12_i10 < 3; c12_i10++) {
      c12_b_inData[c12_i10 + c12_i8] = (*(real_T (*)[9])c12_inData)[c12_i10 +
        c12_i8];
    }

    c12_i8 += 3;
  }

  c12_i11 = 0;
  for (c12_i12 = 0; c12_i12 < 3; c12_i12++) {
    for (c12_i13 = 0; c12_i13 < 3; c12_i13++) {
      c12_u[c12_i13 + c12_i11] = c12_b_inData[c12_i13 + c12_i11];
    }

    c12_i11 += 3;
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c12_mxArrayOutData, c12_y);
  return c12_mxArrayOutData;
}

static void c12_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_y, const char_T *c12_identifier, real_T c12_b_y[9])
{
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_y), &c12_thisId, c12_b_y);
  sf_mex_destroy(&c12_y);
}

static void c12_b_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[9])
{
  real_T c12_dv1[9];
  int32_T c12_i14;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c12_i14 = 0; c12_i14 < 9; c12_i14++) {
    c12_y[c12_i14] = c12_dv1[c12_i14];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_y;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_b_y[9];
  int32_T c12_i15;
  int32_T c12_i16;
  int32_T c12_i17;
  SFc12_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc12_ekffedeInstanceStruct *)chartInstanceVoid;
  c12_y = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_y), &c12_thisId, c12_b_y);
  sf_mex_destroy(&c12_y);
  c12_i15 = 0;
  for (c12_i16 = 0; c12_i16 < 3; c12_i16++) {
    for (c12_i17 = 0; c12_i17 < 3; c12_i17++) {
      (*(real_T (*)[9])c12_outData)[c12_i17 + c12_i15] = c12_b_y[c12_i17 +
        c12_i15];
    }

    c12_i15 += 3;
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i18;
  real_T c12_b_inData[3];
  int32_T c12_i19;
  real_T c12_u[3];
  const mxArray *c12_y = NULL;
  SFc12_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc12_ekffedeInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i18 = 0; c12_i18 < 3; c12_i18++) {
    c12_b_inData[c12_i18] = (*(real_T (*)[3])c12_inData)[c12_i18];
  }

  for (c12_i19 = 0; c12_i19 < 3; c12_i19++) {
    c12_u[c12_i19] = c12_b_inData[c12_i19];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c12_mxArrayOutData, c12_y);
  return c12_mxArrayOutData;
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc12_ekffedeInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c12_mxArrayOutData, c12_y);
  return c12_mxArrayOutData;
}

static real_T c12_c_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_nargout;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc12_ekffedeInstanceStruct *)chartInstanceVoid;
  c12_nargout = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_nargout),
    &c12_thisId);
  sf_mex_destroy(&c12_nargout);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_ekffede_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo;
  c12_ResolvedFunctionInfo c12_info[4];
  c12_ResolvedFunctionInfo (*c12_b_info)[4];
  const mxArray *c12_m0 = NULL;
  int32_T c12_i20;
  c12_ResolvedFunctionInfo *c12_r0;
  c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  c12_b_info = (c12_ResolvedFunctionInfo (*)[4])c12_info;
  (*c12_b_info)[0].context = "";
  (*c12_b_info)[0].name = "diag";
  (*c12_b_info)[0].dominantType = "double";
  (*c12_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  (*c12_b_info)[0].fileTimeLo = 267391744U;
  (*c12_b_info)[0].fileTimeHi = 30108011U;
  (*c12_b_info)[0].mFileTimeLo = 0U;
  (*c12_b_info)[0].mFileTimeHi = 0U;
  (*c12_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  (*c12_b_info)[1].name = "eml_index_class";
  (*c12_b_info)[1].dominantType = "";
  (*c12_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c12_b_info)[1].fileTimeLo = 1187391744U;
  (*c12_b_info)[1].fileTimeHi = 30108011U;
  (*c12_b_info)[1].mFileTimeLo = 0U;
  (*c12_b_info)[1].mFileTimeHi = 0U;
  (*c12_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  (*c12_b_info)[2].name = "eml_index_plus";
  (*c12_b_info)[2].dominantType = "int32";
  (*c12_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c12_b_info)[2].fileTimeLo = 1187391744U;
  (*c12_b_info)[2].fileTimeHi = 30108011U;
  (*c12_b_info)[2].mFileTimeLo = 0U;
  (*c12_b_info)[2].mFileTimeHi = 0U;
  (*c12_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  (*c12_b_info)[3].name = "eml_scalar_eg";
  (*c12_b_info)[3].dominantType = "double";
  (*c12_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c12_b_info)[3].fileTimeLo = 1367391744U;
  (*c12_b_info)[3].fileTimeHi = 30108011U;
  (*c12_b_info)[3].mFileTimeLo = 0U;
  (*c12_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c12_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4));
  for (c12_i20 = 0; c12_i20 < 4; c12_i20++) {
    c12_r0 = &c12_info[c12_i20];
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->context)), "context", "nameCaptureInfo",
                    c12_i20);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->name)), "name", "nameCaptureInfo",
                    c12_i20);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      c12_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c12_i20);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->resolved)), "resolved",
                    "nameCaptureInfo", c12_i20);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c12_i20);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c12_i20);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c12_i20);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c12_i20);
  }

  sf_mex_assign(&c12_nameCaptureInfo, c12_m0);
  return c12_nameCaptureInfo;
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc12_ekffedeInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c12_mxArrayOutData, c12_y);
  return c12_mxArrayOutData;
}

static int32_T c12_d_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i21;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i21, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i21;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc12_ekffedeInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_e_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_b_is_active_c12_ekffede, const char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_ekffede), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_ekffede);
  return c12_y;
}

static uint8_T c12_f_emlrt_marshallIn(SFc12_ekffedeInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info(SFc12_ekffedeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c12_ekffede_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(573026817U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(161277468U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3302635601U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1125785690U);
}

mxArray *sf_c12_ekffede_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1571567285U);
    pr[1] = (double)(2463084369U);
    pr[2] = (double)(780662584U);
    pr[3] = (double)(3535259596U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[1] = (double)(3);
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

static const mxArray *sf_get_sim_state_info_c12_ekffede(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c12_ekffede\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_ekffede_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_ekffedeInstanceStruct *chartInstance;
    chartInstance = (SFc12_ekffedeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_ekffedeMachineNumber_,
          12,
          1,
          1,
          2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Q_bias");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,53);
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
            1.0,0,0,(MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)
            c12_sf_marshallIn);
        }

        {
          real_T (*c12_Q_bias)[3];
          real_T (*c12_y)[9];
          c12_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c12_Q_bias = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c12_Q_bias);
          _SFD_SET_DATA_VALUE_PTR(1U, *c12_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ekffedeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c12_ekffede(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_ekffedeInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c12_ekffede((SFc12_ekffedeInstanceStruct*) chartInstanceVar);
  initialize_c12_ekffede((SFc12_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_ekffede(void *chartInstanceVar)
{
  enable_c12_ekffede((SFc12_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_ekffede(void *chartInstanceVar)
{
  disable_c12_ekffede((SFc12_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_ekffede(void *chartInstanceVar)
{
  sf_c12_ekffede((SFc12_ekffedeInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c12_ekffede(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_ekffede((SFc12_ekffedeInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_ekffede();/* state var info */
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

extern void sf_internal_set_sim_state_c12_ekffede(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_ekffede();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_ekffede((SFc12_ekffedeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c12_ekffede(SimStruct* S)
{
  return sf_internal_get_sim_state_c12_ekffede(S);
}

static void sf_opaque_set_sim_state_c12_ekffede(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c12_ekffede(S, st);
}

static void sf_opaque_terminate_c12_ekffede(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_ekffedeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c12_ekffede((SFc12_ekffedeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_ekffede((SFc12_ekffedeInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_ekffede(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_ekffede((SFc12_ekffedeInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_ekffede(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ekffede","ekffede",12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ekffede","ekffede",12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ekffede","ekffede",12,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ekffede","ekffede",12,1);
      sf_mark_chart_reusable_outputs(S,"ekffede","ekffede",12,1);
    }

    sf_set_rtw_dwork_info(S,"ekffede","ekffede",12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2616630943U));
  ssSetChecksum1(S,(1438476605U));
  ssSetChecksum2(S,(4191853878U));
  ssSetChecksum3(S,(3756288904U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c12_ekffede(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ekffede", "ekffede",12);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_ekffede(SimStruct *S)
{
  SFc12_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc12_ekffedeInstanceStruct *)malloc(sizeof
    (SFc12_ekffedeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_ekffedeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c12_ekffede;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c12_ekffede;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c12_ekffede;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_ekffede;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_ekffede;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c12_ekffede;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c12_ekffede;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c12_ekffede;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_ekffede;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_ekffede;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c12_ekffede;
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

void c12_ekffede_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_ekffede(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_ekffede(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_ekffede(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_ekffede_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
