/* Include files */

#include "blascompat32.h"
#include "EKF_sfun.h"
#include "c19_EKF.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EKF_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c19_debug_family_names[6] = { "nargin", "nargout", "u",
  "prev_in", "y", "prev_out" };

/* Function Declarations */
static void initialize_c19_EKF(SFc19_EKFInstanceStruct *chartInstance);
static void initialize_params_c19_EKF(SFc19_EKFInstanceStruct *chartInstance);
static void enable_c19_EKF(SFc19_EKFInstanceStruct *chartInstance);
static void disable_c19_EKF(SFc19_EKFInstanceStruct *chartInstance);
static void c19_update_debugger_state_c19_EKF(SFc19_EKFInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c19_EKF(SFc19_EKFInstanceStruct
  *chartInstance);
static void set_sim_state_c19_EKF(SFc19_EKFInstanceStruct *chartInstance, const
  mxArray *c19_st);
static void finalize_c19_EKF(SFc19_EKFInstanceStruct *chartInstance);
static void sf_c19_EKF(SFc19_EKFInstanceStruct *chartInstance);
static void initSimStructsc19_EKF(SFc19_EKFInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_emlrt_marshallIn(SFc19_EKFInstanceStruct *chartInstance, const
  mxArray *c19_prev_out, const char_T *c19_identifier);
static real_T c19_b_emlrt_marshallIn(SFc19_EKFInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_c_emlrt_marshallIn(SFc19_EKFInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static uint8_T c19_d_emlrt_marshallIn(SFc19_EKFInstanceStruct *chartInstance,
  const mxArray *c19_b_is_active_c19_EKF, const char_T *c19_identifier);
static uint8_T c19_e_emlrt_marshallIn(SFc19_EKFInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void init_dsm_address_info(SFc19_EKFInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c19_EKF(SFc19_EKFInstanceStruct *chartInstance)
{
  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c19_is_active_c19_EKF = 0U;
}

static void initialize_params_c19_EKF(SFc19_EKFInstanceStruct *chartInstance)
{
}

static void enable_c19_EKF(SFc19_EKFInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c19_EKF(SFc19_EKFInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c19_update_debugger_state_c19_EKF(SFc19_EKFInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c19_EKF(SFc19_EKFInstanceStruct
  *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  real_T c19_hoistedGlobal;
  real_T c19_u;
  const mxArray *c19_b_y = NULL;
  real_T c19_b_hoistedGlobal;
  real_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  uint8_T c19_c_hoistedGlobal;
  uint8_T c19_c_u;
  const mxArray *c19_d_y = NULL;
  real_T *c19_prev_out;
  real_T *c19_e_y;
  c19_prev_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c19_e_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellarray(3));
  c19_hoistedGlobal = *c19_prev_out;
  c19_u = c19_hoistedGlobal;
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_hoistedGlobal = *c19_e_y;
  c19_b_u = c19_b_hoistedGlobal;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 1, c19_c_y);
  c19_c_hoistedGlobal = chartInstance->c19_is_active_c19_EKF;
  c19_c_u = c19_c_hoistedGlobal;
  c19_d_y = NULL;
  sf_mex_assign(&c19_d_y, sf_mex_create("y", &c19_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 2, c19_d_y);
  sf_mex_assign(&c19_st, c19_y);
  return c19_st;
}

static void set_sim_state_c19_EKF(SFc19_EKFInstanceStruct *chartInstance, const
  mxArray *c19_st)
{
  const mxArray *c19_u;
  real_T *c19_prev_out;
  real_T *c19_y;
  c19_prev_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c19_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c19_doneDoubleBufferReInit = TRUE;
  c19_u = sf_mex_dup(c19_st);
  *c19_prev_out = c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c19_u, 0)), "prev_out");
  *c19_y = c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u,
    1)), "y");
  chartInstance->c19_is_active_c19_EKF = c19_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c19_u, 2)), "is_active_c19_EKF");
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_EKF(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_EKF(SFc19_EKFInstanceStruct *chartInstance)
{
}

static void sf_c19_EKF(SFc19_EKFInstanceStruct *chartInstance)
{
  real_T c19_hoistedGlobal;
  real_T c19_b_hoistedGlobal;
  real_T c19_u;
  real_T c19_prev_in;
  uint32_T c19_debug_family_var_map[6];
  real_T c19_nargin = 2.0;
  real_T c19_nargout = 2.0;
  real_T c19_y;
  real_T c19_prev_out;
  real_T c19_x;
  real_T c19_b_x;
  real_T c19_b_y;
  real_T c19_c_x;
  real_T c19_d_x;
  real_T c19_c_y;
  real_T *c19_b_u;
  real_T *c19_d_y;
  real_T *c19_b_prev_in;
  real_T *c19_b_prev_out;
  boolean_T guard1 = FALSE;
  c19_b_prev_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c19_b_prev_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c19_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c19_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c19_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c19_d_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c19_b_prev_in, 2U);
  _SFD_DATA_RANGE_CHECK(*c19_b_prev_out, 3U);
  chartInstance->c19_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c19_sfEvent);
  c19_hoistedGlobal = *c19_b_u;
  c19_b_hoistedGlobal = *c19_b_prev_in;
  c19_u = c19_hoistedGlobal;
  c19_prev_in = c19_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c19_debug_family_names,
    c19_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c19_nargin, 0U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c19_nargout, 1U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c19_u, 2U, c19_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c19_prev_in, 3U, c19_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c19_y, 4U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c19_prev_out, 5U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 4);
  guard1 = FALSE;
  if (CV_EML_COND(0, 0, c19_u > 175.0)) {
    if (CV_EML_COND(0, 1, c19_u < 185.0)) {
      CV_EML_MCDC(0, 0, TRUE);
      CV_EML_IF(0, 0, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 5);
      c19_x = c19_u;
      c19_b_x = c19_x;
      c19_b_y = muDoubleScalarAbs(c19_b_x);
      c19_c_x = c19_prev_in;
      c19_d_x = c19_c_x;
      c19_c_y = muDoubleScalarAbs(c19_d_x);
      if (CV_EML_IF(0, 1, c19_b_y - c19_c_y > 0.1)) {
        _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 6);
        if (CV_EML_IF(0, 2, c19_u - c19_prev_in > 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 7);
          c19_y = c19_prev_in + 0.1;
          _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 8);
          c19_prev_out = c19_y;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 10);
          c19_y = c19_prev_in - 0.1;
          _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 11);
          c19_prev_out = c19_y;
        }
      } else {
        _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 14);
        c19_y = c19_u;
        _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 15);
        c19_prev_out = c19_y;
      }
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 0, FALSE);
    CV_EML_IF(0, 0, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 18);
    c19_y = c19_u;
    _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 19);
    c19_prev_out = c19_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, -19);
  sf_debug_symbol_scope_pop();
  *c19_d_y = c19_y;
  *c19_b_prev_out = c19_prev_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c19_sfEvent);
  sf_debug_check_for_state_inconsistency(_EKFMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc19_EKF(SFc19_EKFInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber)
{
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc19_EKFInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c19_mxArrayOutData, c19_y);
  return c19_mxArrayOutData;
}

static real_T c19_emlrt_marshallIn(SFc19_EKFInstanceStruct *chartInstance, const
  mxArray *c19_prev_out, const char_T *c19_identifier)
{
  real_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_prev_out),
    &c19_thisId);
  sf_mex_destroy(&c19_prev_out);
  return c19_y;
}

static real_T c19_b_emlrt_marshallIn(SFc19_EKFInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d0;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d0, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_prev_out;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc19_EKFInstanceStruct *)chartInstanceVoid;
  c19_prev_out = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_prev_out),
    &c19_thisId);
  sf_mex_destroy(&c19_prev_out);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

const mxArray *sf_c19_EKF_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo;
  c19_ResolvedFunctionInfo c19_info[2];
  c19_ResolvedFunctionInfo (*c19_b_info)[2];
  const mxArray *c19_m0 = NULL;
  int32_T c19_i0;
  c19_ResolvedFunctionInfo *c19_r0;
  c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  c19_b_info = (c19_ResolvedFunctionInfo (*)[2])c19_info;
  (*c19_b_info)[0].context = "";
  (*c19_b_info)[0].name = "abs";
  (*c19_b_info)[0].dominantType = "double";
  (*c19_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c19_b_info)[0].fileTimeLo = 347391744U;
  (*c19_b_info)[0].fileTimeHi = 30108011U;
  (*c19_b_info)[0].mFileTimeLo = 0U;
  (*c19_b_info)[0].mFileTimeHi = 0U;
  (*c19_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c19_b_info)[1].name = "eml_scalar_abs";
  (*c19_b_info)[1].dominantType = "double";
  (*c19_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c19_b_info)[1].fileTimeLo = 527391744U;
  (*c19_b_info)[1].fileTimeHi = 30108011U;
  (*c19_b_info)[1].mFileTimeLo = 0U;
  (*c19_b_info)[1].mFileTimeHi = 0U;
  sf_mex_assign(&c19_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2));
  for (c19_i0 = 0; c19_i0 < 2; c19_i0++) {
    c19_r0 = &c19_info[c19_i0];
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c19_r0->context)), "context", "nameCaptureInfo",
                    c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c19_r0->name)), "name", "nameCaptureInfo", c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo",
      c19_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c19_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c19_r0->resolved)), "resolved",
                    "nameCaptureInfo", c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo",
      &c19_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo",
      &c19_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c19_i0);
  }

  sf_mex_assign(&c19_nameCaptureInfo, c19_m0);
  return c19_nameCaptureInfo;
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc19_EKFInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c19_mxArrayOutData, c19_y);
  return c19_mxArrayOutData;
}

static int32_T c19_c_emlrt_marshallIn(SFc19_EKFInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i1;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i1, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i1;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc19_EKFInstanceStruct *)chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static uint8_T c19_d_emlrt_marshallIn(SFc19_EKFInstanceStruct *chartInstance,
  const mxArray *c19_b_is_active_c19_EKF, const char_T *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_is_active_c19_EKF), &c19_thisId);
  sf_mex_destroy(&c19_b_is_active_c19_EKF);
  return c19_y;
}

static uint8_T c19_e_emlrt_marshallIn(SFc19_EKFInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void init_dsm_address_info(SFc19_EKFInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c19_EKF_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1248649477U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3625661968U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2315910942U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2488169570U);
}

mxArray *sf_c19_EKF_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(27382646U);
    pr[1] = (double)(3984133804U);
    pr[2] = (double)(2456765188U);
    pr[3] = (double)(3227266072U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c19_EKF(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[7],T\"prev_out\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c19_EKF\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_EKF_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_EKFInstanceStruct *chartInstance;
    chartInstance = (SFc19_EKFInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_EKFMachineNumber_,
          19,
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
          init_script_number_translation(_EKFMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_EKFMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_EKFMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"prev_in");
          _SFD_SET_DATA_PROPS(3,2,0,1,"prev_out");
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,364);
        _SFD_CV_INIT_EML_IF(0,0,51,71,321,358);
        _SFD_CV_INIT_EML_IF(0,1,76,105,272,320);
        _SFD_CV_INIT_EML_IF(0,2,114,130,195,267);

        {
          static int condStart[] = { 54, 65 };

          static int condEnd[] = { 61, 71 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,54,71,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)c19_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)c19_sf_marshallIn);

        {
          real_T *c19_u;
          real_T *c19_y;
          real_T *c19_prev_in;
          real_T *c19_prev_out;
          c19_prev_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c19_prev_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c19_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c19_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c19_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c19_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c19_prev_in);
          _SFD_SET_DATA_VALUE_PTR(3U, c19_prev_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_EKFMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c19_EKF(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc19_EKFInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c19_EKF((SFc19_EKFInstanceStruct*) chartInstanceVar);
  initialize_c19_EKF((SFc19_EKFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c19_EKF(void *chartInstanceVar)
{
  enable_c19_EKF((SFc19_EKFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c19_EKF(void *chartInstanceVar)
{
  disable_c19_EKF((SFc19_EKFInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c19_EKF(void *chartInstanceVar)
{
  sf_c19_EKF((SFc19_EKFInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c19_EKF(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c19_EKF((SFc19_EKFInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_EKF();/* state var info */
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

extern void sf_internal_set_sim_state_c19_EKF(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_EKF();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c19_EKF((SFc19_EKFInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c19_EKF(SimStruct* S)
{
  return sf_internal_get_sim_state_c19_EKF(S);
}

static void sf_opaque_set_sim_state_c19_EKF(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c19_EKF(S, st);
}

static void sf_opaque_terminate_c19_EKF(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_EKFInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c19_EKF((SFc19_EKFInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_EKF((SFc19_EKFInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_EKF(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c19_EKF((SFc19_EKFInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_EKF(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"EKF","EKF",19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"EKF","EKF",19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"EKF","EKF",19,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"EKF","EKF",19,2);
      sf_mark_chart_reusable_outputs(S,"EKF","EKF",19,2);
    }

    sf_set_rtw_dwork_info(S,"EKF","EKF",19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1606709660U));
  ssSetChecksum1(S,(2613274277U));
  ssSetChecksum2(S,(3218291920U));
  ssSetChecksum3(S,(3478225517U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c19_EKF(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "EKF", "EKF",19);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_EKF(SimStruct *S)
{
  SFc19_EKFInstanceStruct *chartInstance;
  chartInstance = (SFc19_EKFInstanceStruct *)malloc(sizeof
    (SFc19_EKFInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc19_EKFInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c19_EKF;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c19_EKF;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c19_EKF;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c19_EKF;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c19_EKF;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c19_EKF;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c19_EKF;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c19_EKF;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_EKF;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_EKF;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c19_EKF;
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

void c19_EKF_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_EKF(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_EKF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_EKF(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_EKF_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
