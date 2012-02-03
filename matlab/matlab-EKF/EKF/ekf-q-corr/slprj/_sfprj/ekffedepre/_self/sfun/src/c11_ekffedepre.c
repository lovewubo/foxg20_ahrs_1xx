/* Include files */

#include "blascompat32.h"
#include "ekffedepre_sfun.h"
#include "c11_ekffedepre.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ekffedepre_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c11_debug_family_names[4] = { "nargin", "nargout", "Q_quat",
  "y" };

/* Function Declarations */
static void initialize_c11_ekffedepre(SFc11_ekffedepreInstanceStruct
  *chartInstance);
static void initialize_params_c11_ekffedepre(SFc11_ekffedepreInstanceStruct
  *chartInstance);
static void enable_c11_ekffedepre(SFc11_ekffedepreInstanceStruct *chartInstance);
static void disable_c11_ekffedepre(SFc11_ekffedepreInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_ekffedepre
  (SFc11_ekffedepreInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_ekffedepre
  (SFc11_ekffedepreInstanceStruct *chartInstance);
static void set_sim_state_c11_ekffedepre(SFc11_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c11_st);
static void finalize_c11_ekffedepre(SFc11_ekffedepreInstanceStruct
  *chartInstance);
static void sf_c11_ekffedepre(SFc11_ekffedepreInstanceStruct *chartInstance);
static void initSimStructsc11_ekffedepre(SFc11_ekffedepreInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c11_y, const char_T *c11_identifier, real_T c11_b_y[16]);
static void c11_b_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[16]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_c_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_d_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_e_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_ekffedepre, const char_T
  *c11_identifier);
static uint8_T c11_f_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_ekffedepreInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c11_ekffedepre(SFc11_ekffedepreInstanceStruct
  *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c11_is_active_c11_ekffedepre = 0U;
}

static void initialize_params_c11_ekffedepre(SFc11_ekffedepreInstanceStruct
  *chartInstance)
{
}

static void enable_c11_ekffedepre(SFc11_ekffedepreInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c11_ekffedepre(SFc11_ekffedepreInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c11_update_debugger_state_c11_ekffedepre
  (SFc11_ekffedepreInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c11_ekffedepre
  (SFc11_ekffedepreInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_u[16];
  const mxArray *c11_b_y = NULL;
  uint8_T c11_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  real_T (*c11_d_y)[16];
  c11_d_y = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(2));
  for (c11_i0 = 0; c11_i0 < 16; c11_i0++) {
    c11_u[c11_i0] = (*c11_d_y)[c11_i0];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_hoistedGlobal = chartInstance->c11_is_active_c11_ekffedepre;
  c11_b_u = c11_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y);
  return c11_st;
}

static void set_sim_state_c11_ekffedepre(SFc11_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[16];
  int32_T c11_i1;
  real_T (*c11_y)[16];
  c11_y = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c11_doneDoubleBufferReInit = TRUE;
  c11_u = sf_mex_dup(c11_st);
  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)), "y",
                       c11_dv0);
  for (c11_i1 = 0; c11_i1 < 16; c11_i1++) {
    (*c11_y)[c11_i1] = c11_dv0[c11_i1];
  }

  chartInstance->c11_is_active_c11_ekffedepre = c11_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
     "is_active_c11_ekffedepre");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_ekffedepre(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_ekffedepre(SFc11_ekffedepreInstanceStruct
  *chartInstance)
{
}

static void sf_c11_ekffedepre(SFc11_ekffedepreInstanceStruct *chartInstance)
{
  int32_T c11_i2;
  int32_T c11_i3;
  int32_T c11_i4;
  real_T c11_Q_quat[4];
  uint32_T c11_debug_family_var_map[4];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  real_T c11_y[16];
  int32_T c11_i5;
  real_T c11_v[4];
  int32_T c11_i6;
  int32_T c11_j;
  int32_T c11_b_j;
  int32_T c11_a;
  int32_T c11_c;
  int32_T c11_i7;
  real_T (*c11_b_y)[16];
  real_T (*c11_b_Q_quat)[4];
  c11_b_y = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_b_Q_quat = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  for (c11_i2 = 0; c11_i2 < 4; c11_i2++) {
    _SFD_DATA_RANGE_CHECK((*c11_b_Q_quat)[c11_i2], 0U);
  }

  for (c11_i3 = 0; c11_i3 < 16; c11_i3++) {
    _SFD_DATA_RANGE_CHECK((*c11_b_y)[c11_i3], 1U);
  }

  chartInstance->c11_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  for (c11_i4 = 0; c11_i4 < 4; c11_i4++) {
    c11_Q_quat[c11_i4] = (*c11_b_Q_quat)[c11_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c11_debug_family_names,
    c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_nargout, 1U,
    c11_c_sf_marshallOut, c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c11_Q_quat, 2U, c11_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c11_y, 3U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 4);
  for (c11_i5 = 0; c11_i5 < 4; c11_i5++) {
    c11_v[c11_i5] = c11_Q_quat[c11_i5];
  }

  for (c11_i6 = 0; c11_i6 < 16; c11_i6++) {
    c11_y[c11_i6] = 0.0;
  }

  for (c11_j = 1; c11_j < 5; c11_j++) {
    c11_b_j = c11_j;
    c11_a = c11_b_j;
    c11_c = c11_a;
    c11_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c11_b_j), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c11_c), 1, 4, 2, 0) - 1) <<
            2)) - 1] = c11_v[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c11_b_j), 1, 4, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c11_i7 = 0; c11_i7 < 16; c11_i7++) {
    (*c11_b_y)[c11_i7] = c11_y[c11_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  sf_debug_check_for_state_inconsistency(_ekffedepreMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc11_ekffedepre(SFc11_ekffedepreInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i8;
  int32_T c11_i9;
  int32_T c11_i10;
  real_T c11_b_inData[16];
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  real_T c11_u[16];
  const mxArray *c11_y = NULL;
  SFc11_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc11_ekffedepreInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i8 = 0;
  for (c11_i9 = 0; c11_i9 < 4; c11_i9++) {
    for (c11_i10 = 0; c11_i10 < 4; c11_i10++) {
      c11_b_inData[c11_i10 + c11_i8] = (*(real_T (*)[16])c11_inData)[c11_i10 +
        c11_i8];
    }

    c11_i8 += 4;
  }

  c11_i11 = 0;
  for (c11_i12 = 0; c11_i12 < 4; c11_i12++) {
    for (c11_i13 = 0; c11_i13 < 4; c11_i13++) {
      c11_u[c11_i13 + c11_i11] = c11_b_inData[c11_i13 + c11_i11];
    }

    c11_i11 += 4;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c11_mxArrayOutData, c11_y);
  return c11_mxArrayOutData;
}

static void c11_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c11_y, const char_T *c11_identifier, real_T c11_b_y[16])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_y), &c11_thisId, c11_b_y);
  sf_mex_destroy(&c11_y);
}

static void c11_b_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[16])
{
  real_T c11_dv1[16];
  int32_T c11_i14;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv1, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c11_i14 = 0; c11_i14 < 16; c11_i14++) {
    c11_y[c11_i14] = c11_dv1[c11_i14];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_y;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_b_y[16];
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  SFc11_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc11_ekffedepreInstanceStruct *)chartInstanceVoid;
  c11_y = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_y), &c11_thisId, c11_b_y);
  sf_mex_destroy(&c11_y);
  c11_i15 = 0;
  for (c11_i16 = 0; c11_i16 < 4; c11_i16++) {
    for (c11_i17 = 0; c11_i17 < 4; c11_i17++) {
      (*(real_T (*)[16])c11_outData)[c11_i17 + c11_i15] = c11_b_y[c11_i17 +
        c11_i15];
    }

    c11_i15 += 4;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i18;
  real_T c11_b_inData[4];
  int32_T c11_i19;
  real_T c11_u[4];
  const mxArray *c11_y = NULL;
  SFc11_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc11_ekffedepreInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i18 = 0; c11_i18 < 4; c11_i18++) {
    c11_b_inData[c11_i18] = (*(real_T (*)[4])c11_inData)[c11_i18];
  }

  for (c11_i19 = 0; c11_i19 < 4; c11_i19++) {
    c11_u[c11_i19] = c11_b_inData[c11_i19];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c11_mxArrayOutData, c11_y);
  return c11_mxArrayOutData;
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc11_ekffedepreInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_mxArrayOutData, c11_y);
  return c11_mxArrayOutData;
}

static real_T c11_c_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc11_ekffedepreInstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_ekffedepre_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo;
  c11_ResolvedFunctionInfo c11_info[4];
  c11_ResolvedFunctionInfo (*c11_b_info)[4];
  const mxArray *c11_m0 = NULL;
  int32_T c11_i20;
  c11_ResolvedFunctionInfo *c11_r0;
  c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  c11_b_info = (c11_ResolvedFunctionInfo (*)[4])c11_info;
  (*c11_b_info)[0].context = "";
  (*c11_b_info)[0].name = "diag";
  (*c11_b_info)[0].dominantType = "double";
  (*c11_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  (*c11_b_info)[0].fileTimeLo = 267391744U;
  (*c11_b_info)[0].fileTimeHi = 30108011U;
  (*c11_b_info)[0].mFileTimeLo = 0U;
  (*c11_b_info)[0].mFileTimeHi = 0U;
  (*c11_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  (*c11_b_info)[1].name = "eml_index_class";
  (*c11_b_info)[1].dominantType = "";
  (*c11_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c11_b_info)[1].fileTimeLo = 1187391744U;
  (*c11_b_info)[1].fileTimeHi = 30108011U;
  (*c11_b_info)[1].mFileTimeLo = 0U;
  (*c11_b_info)[1].mFileTimeHi = 0U;
  (*c11_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  (*c11_b_info)[2].name = "eml_index_plus";
  (*c11_b_info)[2].dominantType = "int32";
  (*c11_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c11_b_info)[2].fileTimeLo = 1187391744U;
  (*c11_b_info)[2].fileTimeHi = 30108011U;
  (*c11_b_info)[2].mFileTimeLo = 0U;
  (*c11_b_info)[2].mFileTimeHi = 0U;
  (*c11_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  (*c11_b_info)[3].name = "eml_scalar_eg";
  (*c11_b_info)[3].dominantType = "double";
  (*c11_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c11_b_info)[3].fileTimeLo = 1367391744U;
  (*c11_b_info)[3].fileTimeHi = 30108011U;
  (*c11_b_info)[3].mFileTimeLo = 0U;
  (*c11_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c11_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4));
  for (c11_i20 = 0; c11_i20 < 4; c11_i20++) {
    c11_r0 = &c11_info[c11_i20];
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->context)), "context", "nameCaptureInfo",
                    c11_i20);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->name)), "name", "nameCaptureInfo",
                    c11_i20);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      c11_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c11_i20);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->resolved)), "resolved",
                    "nameCaptureInfo", c11_i20);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c11_i20);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c11_i20);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c11_i20);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c11_i20);
  }

  sf_mex_assign(&c11_nameCaptureInfo, c11_m0);
  return c11_nameCaptureInfo;
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc11_ekffedepreInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_mxArrayOutData, c11_y);
  return c11_mxArrayOutData;
}

static int32_T c11_d_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i21;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i21, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i21;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc11_ekffedepreInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_e_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_ekffedepre, const char_T
  *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_ekffedepre), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_ekffedepre);
  return c11_y;
}

static uint8_T c11_f_emlrt_marshallIn(SFc11_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_ekffedepreInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c11_ekffedepre_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1693334664U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1887055176U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3772918554U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1180817095U);
}

mxArray *sf_c11_ekffedepre_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1639953541U);
    pr[1] = (double)(2661478775U);
    pr[2] = (double)(2642834913U);
    pr[3] = (double)(1169271157U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[1] = (double)(4);
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

static const mxArray *sf_get_sim_state_info_c11_ekffedepre(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c11_ekffedepre\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_ekffedepre_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_ekffedepreInstanceStruct *chartInstance;
    chartInstance = (SFc11_ekffedepreInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_ekffedepreMachineNumber_,
           11,
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
          init_script_number_translation(_ekffedepreMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_ekffedepreMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_ekffedepreMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Q_quat");
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
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          real_T (*c11_Q_quat)[4];
          real_T (*c11_y)[16];
          c11_y = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
          c11_Q_quat = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c11_Q_quat);
          _SFD_SET_DATA_VALUE_PTR(1U, *c11_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ekffedepreMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c11_ekffedepre(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_ekffedepreInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c11_ekffedepre((SFc11_ekffedepreInstanceStruct*)
    chartInstanceVar);
  initialize_c11_ekffedepre((SFc11_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c11_ekffedepre(void *chartInstanceVar)
{
  enable_c11_ekffedepre((SFc11_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_ekffedepre(void *chartInstanceVar)
{
  disable_c11_ekffedepre((SFc11_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c11_ekffedepre(void *chartInstanceVar)
{
  sf_c11_ekffedepre((SFc11_ekffedepreInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_ekffedepre(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_ekffedepre
    ((SFc11_ekffedepreInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_ekffedepre();/* state var info */
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

extern void sf_internal_set_sim_state_c11_ekffedepre(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_ekffedepre();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_ekffedepre((SFc11_ekffedepreInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_ekffedepre(SimStruct* S)
{
  return sf_internal_get_sim_state_c11_ekffedepre(S);
}

static void sf_opaque_set_sim_state_c11_ekffedepre(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c11_ekffedepre(S, st);
}

static void sf_opaque_terminate_c11_ekffedepre(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_ekffedepreInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c11_ekffedepre((SFc11_ekffedepreInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_ekffedepre((SFc11_ekffedepreInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_ekffedepre(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_ekffedepre((SFc11_ekffedepreInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_ekffedepre(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ekffedepre","ekffedepre",11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ekffedepre","ekffedepre",11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ekffedepre",
      "ekffedepre",11,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ekffedepre","ekffedepre",11,1);
      sf_mark_chart_reusable_outputs(S,"ekffedepre","ekffedepre",11,1);
    }

    sf_set_rtw_dwork_info(S,"ekffedepre","ekffedepre",11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(817507566U));
  ssSetChecksum1(S,(1068222508U));
  ssSetChecksum2(S,(514705553U));
  ssSetChecksum3(S,(3491894981U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c11_ekffedepre(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ekffedepre", "ekffedepre",11);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_ekffedepre(SimStruct *S)
{
  SFc11_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc11_ekffedepreInstanceStruct *)malloc(sizeof
    (SFc11_ekffedepreInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_ekffedepreInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c11_ekffedepre;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c11_ekffedepre;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c11_ekffedepre;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_ekffedepre;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_ekffedepre;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c11_ekffedepre;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c11_ekffedepre;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_ekffedepre;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_ekffedepre;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_ekffedepre;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c11_ekffedepre;
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

void c11_ekffedepre_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_ekffedepre(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_ekffedepre(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_ekffedepre(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_ekffedepre_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
