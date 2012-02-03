/* Include files */

#include "blascompat32.h"
#include "ekffedepre_sfun.h"
#include "c7_ekffedepre.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ekffedepre_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[8] = { "nargin", "nargout",
  "sfasamento", "ampiezza", "frequenza", "noise", "t", "wave" };

/* Function Declarations */
static void initialize_c7_ekffedepre(SFc7_ekffedepreInstanceStruct
  *chartInstance);
static void initialize_params_c7_ekffedepre(SFc7_ekffedepreInstanceStruct
  *chartInstance);
static void enable_c7_ekffedepre(SFc7_ekffedepreInstanceStruct *chartInstance);
static void disable_c7_ekffedepre(SFc7_ekffedepreInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_ekffedepre(SFc7_ekffedepreInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c7_ekffedepre(SFc7_ekffedepreInstanceStruct *
  chartInstance);
static void set_sim_state_c7_ekffedepre(SFc7_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c7_st);
static void finalize_c7_ekffedepre(SFc7_ekffedepreInstanceStruct *chartInstance);
static void sf_c7_ekffedepre(SFc7_ekffedepreInstanceStruct *chartInstance);
static void initSimStructsc7_ekffedepre(SFc7_ekffedepreInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c7_wave, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn(SFc7_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_c_emlrt_marshallIn(SFc7_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_d_emlrt_marshallIn(SFc7_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_ekffedepre, const char_T
  *c7_identifier);
static uint8_T c7_e_emlrt_marshallIn(SFc7_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_ekffedepreInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_ekffedepre(SFc7_ekffedepreInstanceStruct
  *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_ekffedepre = 0U;
}

static void initialize_params_c7_ekffedepre(SFc7_ekffedepreInstanceStruct
  *chartInstance)
{
}

static void enable_c7_ekffedepre(SFc7_ekffedepreInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_ekffedepre(SFc7_ekffedepreInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_ekffedepre(SFc7_ekffedepreInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c7_ekffedepre(SFc7_ekffedepreInstanceStruct *
  chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  uint8_T c7_b_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T *c7_wave;
  c7_wave = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2));
  c7_hoistedGlobal = *c7_wave;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = chartInstance->c7_is_active_c7_ekffedepre;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y);
  return c7_st;
}

static void set_sim_state_c7_ekffedepre(SFc7_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T *c7_wave;
  c7_wave = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  *c7_wave = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u,
    0)), "wave");
  chartInstance->c7_is_active_c7_ekffedepre = c7_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
     "is_active_c7_ekffedepre");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_ekffedepre(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_ekffedepre(SFc7_ekffedepreInstanceStruct *chartInstance)
{
}

static void sf_c7_ekffedepre(SFc7_ekffedepreInstanceStruct *chartInstance)
{
  real_T c7_hoistedGlobal;
  real_T c7_b_hoistedGlobal;
  real_T c7_c_hoistedGlobal;
  real_T c7_d_hoistedGlobal;
  real_T c7_e_hoistedGlobal;
  real_T c7_sfasamento;
  real_T c7_ampiezza;
  real_T c7_frequenza;
  real_T c7_noise;
  real_T c7_t;
  uint32_T c7_debug_family_var_map[8];
  real_T c7_nargin = 5.0;
  real_T c7_nargout = 1.0;
  real_T c7_wave;
  real_T c7_b;
  real_T c7_y;
  real_T c7_a;
  real_T c7_b_b;
  real_T c7_b_y;
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_b_a;
  real_T c7_c_b;
  real_T c7_c_y;
  real_T *c7_b_sfasamento;
  real_T *c7_b_wave;
  real_T *c7_b_ampiezza;
  real_T *c7_b_frequenza;
  real_T *c7_b_noise;
  real_T *c7_b_t;
  c7_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c7_b_noise = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c7_b_frequenza = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c7_b_ampiezza = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c7_b_wave = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_sfasamento = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c7_b_sfasamento, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_b_wave, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_b_ampiezza, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_b_frequenza, 3U);
  _SFD_DATA_RANGE_CHECK(*c7_b_noise, 4U);
  _SFD_DATA_RANGE_CHECK(*c7_b_t, 5U);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  c7_hoistedGlobal = *c7_b_sfasamento;
  c7_b_hoistedGlobal = *c7_b_ampiezza;
  c7_c_hoistedGlobal = *c7_b_frequenza;
  c7_d_hoistedGlobal = *c7_b_noise;
  c7_e_hoistedGlobal = *c7_b_t;
  c7_sfasamento = c7_hoistedGlobal;
  c7_ampiezza = c7_b_hoistedGlobal;
  c7_frequenza = c7_c_hoistedGlobal;
  c7_noise = c7_d_hoistedGlobal;
  c7_t = c7_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c7_debug_family_names,
    c7_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargin, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargout, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c7_sfasamento, 2U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_ampiezza, 3U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_frequenza, 4U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_noise, 5U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_t, 6U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c7_wave, 7U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_b = c7_frequenza;
  c7_y = 6.2831853071795862 * c7_b;
  c7_a = c7_y;
  c7_b_b = c7_t;
  c7_b_y = c7_a * c7_b_b;
  c7_x = c7_sfasamento + c7_b_y;
  c7_b_x = c7_x;
  c7_b_x = muDoubleScalarSin(c7_b_x);
  c7_b_a = c7_ampiezza;
  c7_c_b = c7_b_x;
  c7_c_y = c7_b_a * c7_c_b;
  c7_wave = c7_c_y + c7_noise;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  *c7_b_wave = c7_wave;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  sf_debug_check_for_state_inconsistency(_ekffedepreMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc7_ekffedepre(SFc7_ekffedepreInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc7_ekffedepreInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c7_mxArrayOutData, c7_y);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c7_wave, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_wave), &c7_thisId);
  sf_mex_destroy(&c7_wave);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn(SFc7_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_wave;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc7_ekffedepreInstanceStruct *)chartInstanceVoid;
  c7_wave = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_wave), &c7_thisId);
  sf_mex_destroy(&c7_wave);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_ekffedepre_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[3];
  c7_ResolvedFunctionInfo (*c7_b_info)[3];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i0;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_b_info = (c7_ResolvedFunctionInfo (*)[3])c7_info;
  (*c7_b_info)[0].context = "";
  (*c7_b_info)[0].name = "mtimes";
  (*c7_b_info)[0].dominantType = "double";
  (*c7_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c7_b_info)[0].fileTimeLo = 3573034496U;
  (*c7_b_info)[0].fileTimeHi = 30114299U;
  (*c7_b_info)[0].mFileTimeLo = 0U;
  (*c7_b_info)[0].mFileTimeHi = 0U;
  (*c7_b_info)[1].context = "";
  (*c7_b_info)[1].name = "sin";
  (*c7_b_info)[1].dominantType = "double";
  (*c7_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c7_b_info)[1].fileTimeLo = 907391744U;
  (*c7_b_info)[1].fileTimeHi = 30108011U;
  (*c7_b_info)[1].mFileTimeLo = 0U;
  (*c7_b_info)[1].mFileTimeHi = 0U;
  (*c7_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c7_b_info)[2].name = "eml_scalar_sin";
  (*c7_b_info)[2].dominantType = "double";
  (*c7_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c7_b_info)[2].fileTimeLo = 767391744U;
  (*c7_b_info)[2].fileTimeHi = 30108011U;
  (*c7_b_info)[2].mFileTimeLo = 0U;
  (*c7_b_info)[2].mFileTimeHi = 0U;
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 3));
  for (c7_i0 = 0; c7_i0 < 3; c7_i0++) {
    c7_r0 = &c7_info[c7_i0];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i0);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0);
  return c7_nameCaptureInfo;
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc7_ekffedepreInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c7_mxArrayOutData, c7_y);
  return c7_mxArrayOutData;
}

static int32_T c7_c_emlrt_marshallIn(SFc7_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i1;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i1, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i1;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc7_ekffedepreInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_d_emlrt_marshallIn(SFc7_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_ekffedepre, const char_T
  *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_ekffedepre), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_ekffedepre);
  return c7_y;
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_ekffedepreInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c7_ekffedepre_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1176544713U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1784350944U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2093713111U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2303375494U);
}

mxArray *sf_c7_ekffedepre_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(869705337U);
    pr[1] = (double)(4037793131U);
    pr[2] = (double)(919190404U);
    pr[3] = (double)(3945250788U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c7_ekffedepre(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"wave\",},{M[8],M[0],T\"is_active_c7_ekffedepre\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_ekffedepre_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_ekffedepreInstanceStruct *chartInstance;
    chartInstance = (SFc7_ekffedepreInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_ekffedepreMachineNumber_,
           7,
           1,
           1,
           6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"sfasamento");
          _SFD_SET_DATA_PROPS(1,2,0,1,"wave");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ampiezza");
          _SFD_SET_DATA_PROPS(3,1,1,0,"frequenza");
          _SFD_SET_DATA_PROPS(4,1,1,0,"noise");
          _SFD_SET_DATA_PROPS(5,1,1,0,"t");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,126);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c7_sfasamento;
          real_T *c7_wave;
          real_T *c7_ampiezza;
          real_T *c7_frequenza;
          real_T *c7_noise;
          real_T *c7_t;
          c7_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c7_noise = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c7_frequenza = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c7_ampiezza = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c7_wave = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c7_sfasamento = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_sfasamento);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_wave);
          _SFD_SET_DATA_VALUE_PTR(2U, c7_ampiezza);
          _SFD_SET_DATA_VALUE_PTR(3U, c7_frequenza);
          _SFD_SET_DATA_VALUE_PTR(4U, c7_noise);
          _SFD_SET_DATA_VALUE_PTR(5U, c7_t);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ekffedepreMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c7_ekffedepre(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_ekffedepreInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c7_ekffedepre((SFc7_ekffedepreInstanceStruct*)
    chartInstanceVar);
  initialize_c7_ekffedepre((SFc7_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_ekffedepre(void *chartInstanceVar)
{
  enable_c7_ekffedepre((SFc7_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_ekffedepre(void *chartInstanceVar)
{
  disable_c7_ekffedepre((SFc7_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_ekffedepre(void *chartInstanceVar)
{
  sf_c7_ekffedepre((SFc7_ekffedepreInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_ekffedepre(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_ekffedepre
    ((SFc7_ekffedepreInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_ekffedepre();/* state var info */
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

extern void sf_internal_set_sim_state_c7_ekffedepre(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_ekffedepre();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_ekffedepre((SFc7_ekffedepreInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_ekffedepre(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_ekffedepre(S);
}

static void sf_opaque_set_sim_state_c7_ekffedepre(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c7_ekffedepre(S, st);
}

static void sf_opaque_terminate_c7_ekffedepre(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_ekffedepreInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c7_ekffedepre((SFc7_ekffedepreInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_ekffedepre((SFc7_ekffedepreInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_ekffedepre(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_ekffedepre((SFc7_ekffedepreInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_ekffedepre(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ekffedepre","ekffedepre",7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ekffedepre","ekffedepre",7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ekffedepre",
      "ekffedepre",7,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ekffedepre","ekffedepre",7,5);
      sf_mark_chart_reusable_outputs(S,"ekffedepre","ekffedepre",7,1);
    }

    sf_set_rtw_dwork_info(S,"ekffedepre","ekffedepre",7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2179350920U));
  ssSetChecksum1(S,(3992330002U));
  ssSetChecksum2(S,(3184175835U));
  ssSetChecksum3(S,(534578481U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_ekffedepre(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ekffedepre", "ekffedepre",7);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_ekffedepre(SimStruct *S)
{
  SFc7_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc7_ekffedepreInstanceStruct *)malloc(sizeof
    (SFc7_ekffedepreInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_ekffedepreInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_ekffedepre;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_ekffedepre;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_ekffedepre;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_ekffedepre;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_ekffedepre;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_ekffedepre;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_ekffedepre;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c7_ekffedepre;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_ekffedepre;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_ekffedepre;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_ekffedepre;
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

void c7_ekffedepre_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_ekffedepre(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_ekffedepre(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_ekffedepre(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_ekffedepre_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
