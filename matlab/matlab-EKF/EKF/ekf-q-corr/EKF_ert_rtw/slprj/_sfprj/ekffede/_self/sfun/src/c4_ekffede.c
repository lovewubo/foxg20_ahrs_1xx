/* Include files */

#include "blascompat32.h"
#include "ekffede_sfun.h"
#include "c4_ekffede.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ekffede_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[14] = { "q1", "q2", "q3", "q0", "bp",
  "bq", "br", "nargin", "nargout", "x", "p", "q", "r", "dotxk" };

/* Function Declarations */
static void initialize_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance);
static void initialize_params_c4_ekffede(SFc4_ekffedeInstanceStruct
  *chartInstance);
static void enable_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance);
static void disable_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_ekffede(SFc4_ekffedeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_ekffede(SFc4_ekffedeInstanceStruct
  *chartInstance);
static void set_sim_state_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_st);
static void finalize_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance);
static void sf_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance);
static void initSimStructsc4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance, const
  mxArray *c4_dotxk, const char_T *c4_identifier, real_T c4_y[7]);
static void c4_b_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[7]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_e_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_ekffede, const char_T *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_ekffedeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_ekffede = 0U;
}

static void initialize_params_c4_ekffede(SFc4_ekffedeInstanceStruct
  *chartInstance)
{
}

static void enable_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_ekffede(SFc4_ekffedeInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c4_ekffede(SFc4_ekffedeInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[7];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T (*c4_dotxk)[7];
  c4_dotxk = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2));
  for (c4_i0 = 0; c4_i0 < 7; c4_i0++) {
    c4_u[c4_i0] = (*c4_dotxk)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_ekffede;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y);
  return c4_st;
}

static void set_sim_state_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[7];
  int32_T c4_i1;
  real_T (*c4_dotxk)[7];
  c4_dotxk = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
                      "dotxk", c4_dv0);
  for (c4_i1 = 0; c4_i1 < 7; c4_i1++) {
    (*c4_dotxk)[c4_i1] = c4_dv0[c4_i1];
  }

  chartInstance->c4_is_active_c4_ekffede = c4_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 1)), "is_active_c4_ekffede");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_ekffede(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance)
{
}

static void sf_c4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance)
{
  int32_T c4_i2;
  int32_T c4_i3;
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  int32_T c4_i4;
  real_T c4_x[7];
  real_T c4_p;
  real_T c4_q;
  real_T c4_r;
  uint32_T c4_debug_family_var_map[14];
  real_T c4_q1;
  real_T c4_q2;
  real_T c4_q3;
  real_T c4_q0;
  real_T c4_bp;
  real_T c4_bq;
  real_T c4_br;
  real_T c4_nargin = 4.0;
  real_T c4_nargout = 1.0;
  real_T c4_dotxk[7];
  real_T c4_b;
  real_T c4_y;
  real_T c4_a;
  real_T c4_b_b;
  real_T c4_b_y;
  real_T c4_c_b;
  real_T c4_c_y;
  real_T c4_b_a;
  real_T c4_d_b;
  real_T c4_d_y;
  real_T c4_e_b;
  real_T c4_e_y;
  real_T c4_c_a;
  real_T c4_f_b;
  real_T c4_f_y;
  real_T c4_g_b;
  real_T c4_g_y;
  real_T c4_d_a;
  real_T c4_h_b;
  real_T c4_h_y;
  real_T c4_i_b;
  real_T c4_i_y;
  real_T c4_e_a;
  real_T c4_j_b;
  real_T c4_j_y;
  real_T c4_k_b;
  real_T c4_k_y;
  real_T c4_f_a;
  real_T c4_l_b;
  real_T c4_l_y;
  real_T c4_m_b;
  real_T c4_m_y;
  real_T c4_g_a;
  real_T c4_n_b;
  real_T c4_n_y;
  real_T c4_o_b;
  real_T c4_o_y;
  real_T c4_h_a;
  real_T c4_p_b;
  real_T c4_p_y;
  real_T c4_q_b;
  real_T c4_q_y;
  real_T c4_i_a;
  real_T c4_r_b;
  real_T c4_r_y;
  real_T c4_s_b;
  real_T c4_s_y;
  real_T c4_j_a;
  real_T c4_t_b;
  real_T c4_t_y;
  real_T c4_u_b;
  real_T c4_u_y;
  real_T c4_k_a;
  real_T c4_v_b;
  real_T c4_v_y;
  real_T c4_w_b;
  real_T c4_w_y;
  real_T c4_l_a;
  real_T c4_x_b;
  real_T c4_x_y;
  int32_T c4_i5;
  real_T *c4_b_p;
  real_T *c4_b_q;
  real_T *c4_b_r;
  real_T (*c4_b_dotxk)[7];
  real_T (*c4_b_x)[7];
  c4_b_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_q = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_dotxk = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i2 = 0; c4_i2 < 7; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_x)[c4_i2], 0U);
  }

  for (c4_i3 = 0; c4_i3 < 7; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_dotxk)[c4_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_b_p, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_b_q, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_b_r, 4U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_p;
  c4_b_hoistedGlobal = *c4_b_q;
  c4_c_hoistedGlobal = *c4_b_r;
  for (c4_i4 = 0; c4_i4 < 7; c4_i4++) {
    c4_x[c4_i4] = (*c4_b_x)[c4_i4];
  }

  c4_p = c4_hoistedGlobal;
  c4_q = c4_b_hoistedGlobal;
  c4_r = c4_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 14U, 14U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_q1, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_q2, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_q3, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_q0, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_bp, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_bq, 5U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_br, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c4_x, 9U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_p, 10U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_q, 11U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_r, 12U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c4_dotxk, 13U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_q1 = c4_x[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_q2 = c4_x[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_q3 = c4_x[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_q0 = c4_x[3];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_bp = c4_x[4];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_bq = c4_x[5];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_br = c4_x[6];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_b = c4_q0;
  c4_y = 0.5 * c4_b;
  c4_a = c4_y;
  c4_b_b = c4_p - c4_bp;
  c4_b_y = c4_a * c4_b_b;
  c4_c_b = c4_q3;
  c4_c_y = 0.5 * c4_c_b;
  c4_b_a = c4_c_y;
  c4_d_b = c4_q - c4_bq;
  c4_d_y = c4_b_a * c4_d_b;
  c4_e_b = c4_q2;
  c4_e_y = 0.5 * c4_e_b;
  c4_c_a = c4_e_y;
  c4_f_b = c4_r - c4_br;
  c4_f_y = c4_c_a * c4_f_b;
  c4_g_b = c4_q3;
  c4_g_y = 0.5 * c4_g_b;
  c4_d_a = c4_g_y;
  c4_h_b = c4_p - c4_bp;
  c4_h_y = c4_d_a * c4_h_b;
  c4_i_b = c4_q0;
  c4_i_y = 0.5 * c4_i_b;
  c4_e_a = c4_i_y;
  c4_j_b = c4_q - c4_bq;
  c4_j_y = c4_e_a * c4_j_b;
  c4_k_b = c4_q1;
  c4_k_y = 0.5 * c4_k_b;
  c4_f_a = c4_k_y;
  c4_l_b = c4_r - c4_br;
  c4_l_y = c4_f_a * c4_l_b;
  c4_m_b = c4_q2;
  c4_m_y = -0.5 * c4_m_b;
  c4_g_a = c4_m_y;
  c4_n_b = c4_p - c4_bp;
  c4_n_y = c4_g_a * c4_n_b;
  c4_o_b = c4_q1;
  c4_o_y = 0.5 * c4_o_b;
  c4_h_a = c4_o_y;
  c4_p_b = c4_q - c4_bq;
  c4_p_y = c4_h_a * c4_p_b;
  c4_q_b = c4_q0;
  c4_q_y = 0.5 * c4_q_b;
  c4_i_a = c4_q_y;
  c4_r_b = c4_r - c4_br;
  c4_r_y = c4_i_a * c4_r_b;
  c4_s_b = c4_q1;
  c4_s_y = -0.5 * c4_s_b;
  c4_j_a = c4_s_y;
  c4_t_b = c4_p - c4_bp;
  c4_t_y = c4_j_a * c4_t_b;
  c4_u_b = c4_q2;
  c4_u_y = 0.5 * c4_u_b;
  c4_k_a = c4_u_y;
  c4_v_b = c4_q - c4_bq;
  c4_v_y = c4_k_a * c4_v_b;
  c4_w_b = c4_q3;
  c4_w_y = 0.5 * c4_w_b;
  c4_l_a = c4_w_y;
  c4_x_b = c4_r - c4_br;
  c4_x_y = c4_l_a * c4_x_b;
  c4_dotxk[0] = (c4_b_y - c4_d_y) + c4_f_y;
  c4_dotxk[1] = (c4_h_y + c4_j_y) - c4_l_y;
  c4_dotxk[2] = (c4_n_y + c4_p_y) + c4_r_y;
  c4_dotxk[3] = (c4_t_y - c4_v_y) - c4_x_y;
  c4_dotxk[4] = 0.0;
  c4_dotxk[5] = 0.0;
  c4_dotxk[6] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -14);
  sf_debug_symbol_scope_pop();
  for (c4_i5 = 0; c4_i5 < 7; c4_i5++) {
    (*c4_b_dotxk)[c4_i5] = c4_dotxk[c4_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  sf_debug_check_for_state_inconsistency(_ekffedeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_ekffede(SFc4_ekffedeInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i6;
  real_T c4_b_inData[7];
  int32_T c4_i7;
  real_T c4_u[7];
  const mxArray *c4_y = NULL;
  SFc4_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ekffedeInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i6 = 0; c4_i6 < 7; c4_i6++) {
    c4_b_inData[c4_i6] = (*(real_T (*)[7])c4_inData)[c4_i6];
  }

  for (c4_i7 = 0; c4_i7 < 7; c4_i7++) {
    c4_u[c4_i7] = c4_b_inData[c4_i7];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance, const
  mxArray *c4_dotxk, const char_T *c4_identifier, real_T c4_y[7])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_dotxk), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_dotxk);
}

static void c4_b_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[7])
{
  real_T c4_dv1[7];
  int32_T c4_i8;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv1, 1, 0, 0U, 1, 0U, 1, 7);
  for (c4_i8 = 0; c4_i8 < 7; c4_i8++) {
    c4_y[c4_i8] = c4_dv1[c4_i8];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_dotxk;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[7];
  int32_T c4_i9;
  SFc4_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ekffedeInstanceStruct *)chartInstanceVoid;
  c4_dotxk = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_dotxk), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_dotxk);
  for (c4_i9 = 0; c4_i9 < 7; c4_i9++) {
    (*(real_T (*)[7])c4_outData)[c4_i9] = c4_y[c4_i9];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ekffedeInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ekffedeInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_ekffede_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[1];
  c4_ResolvedFunctionInfo (*c4_b_info)[1];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i10;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[1])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "mtimes";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[0].fileTimeLo = 3573034496U;
  (*c4_b_info)[0].fileTimeHi = 30114299U;
  (*c4_b_info)[0].mFileTimeLo = 0U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1));
  for (c4_i10 = 0; c4_i10 < 1; c4_i10++) {
    c4_r0 = &c4_info[c4_i10];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i10);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i10);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i10);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i10);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i10);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i10);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i10);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i10);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ekffedeInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_mxArrayOutData, c4_y);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i11;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i11, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i11;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ekffedeInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_ekffede, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_ekffede), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_ekffede);
  return c4_y;
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_ekffedeInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_ekffedeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_ekffede_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(934878299U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4152031393U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(907285236U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3451189301U);
}

mxArray *sf_c4_ekffede_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1384687785U);
    pr[1] = (double)(2105506545U);
    pr[2] = (double)(1632171359U);
    pr[3] = (double)(827062025U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
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
      pr[0] = (double)(7);
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

static const mxArray *sf_get_sim_state_info_c4_ekffede(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"dotxk\",},{M[8],M[0],T\"is_active_c4_ekffede\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_ekffede_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_ekffedeInstanceStruct *chartInstance;
    chartInstance = (SFc4_ekffedeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_ekffedeMachineNumber_,
          4,
          1,
          1,
          5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dotxk");
          _SFD_SET_DATA_PROPS(2,1,1,0,"p");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q");
          _SFD_SET_DATA_PROPS(4,1,1,0,"r");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,423);
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
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c4_p;
          real_T *c4_q;
          real_T *c4_r;
          real_T (*c4_x)[7];
          real_T (*c4_dotxk)[7];
          c4_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c4_q = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_dotxk = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_x);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_dotxk);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_p);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_q);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_r);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ekffedeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c4_ekffede(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_ekffedeInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c4_ekffede((SFc4_ekffedeInstanceStruct*) chartInstanceVar);
  initialize_c4_ekffede((SFc4_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_ekffede(void *chartInstanceVar)
{
  enable_c4_ekffede((SFc4_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_ekffede(void *chartInstanceVar)
{
  disable_c4_ekffede((SFc4_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_ekffede(void *chartInstanceVar)
{
  sf_c4_ekffede((SFc4_ekffedeInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_ekffede(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_ekffede((SFc4_ekffedeInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_ekffede();/* state var info */
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

extern void sf_internal_set_sim_state_c4_ekffede(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_ekffede();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_ekffede((SFc4_ekffedeInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_ekffede(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_ekffede(S);
}

static void sf_opaque_set_sim_state_c4_ekffede(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_ekffede(S, st);
}

static void sf_opaque_terminate_c4_ekffede(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_ekffedeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_ekffede((SFc4_ekffedeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_ekffede((SFc4_ekffedeInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_ekffede(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_ekffede((SFc4_ekffedeInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_ekffede(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ekffede","ekffede",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ekffede","ekffede",4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ekffede","ekffede",4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ekffede","ekffede",4,4);
      sf_mark_chart_reusable_outputs(S,"ekffede","ekffede",4,1);
    }

    sf_set_rtw_dwork_info(S,"ekffede","ekffede",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3559619806U));
  ssSetChecksum1(S,(4266498546U));
  ssSetChecksum2(S,(2311844954U));
  ssSetChecksum3(S,(2235525041U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_ekffede(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ekffede", "ekffede",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_ekffede(SimStruct *S)
{
  SFc4_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc4_ekffedeInstanceStruct *)malloc(sizeof
    (SFc4_ekffedeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_ekffedeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_ekffede;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_ekffede;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_ekffede;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_ekffede;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_ekffede;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_ekffede;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_ekffede;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_ekffede;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_ekffede;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_ekffede;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_ekffede;
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

void c4_ekffede_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_ekffede(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_ekffede(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_ekffede(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_ekffede_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
