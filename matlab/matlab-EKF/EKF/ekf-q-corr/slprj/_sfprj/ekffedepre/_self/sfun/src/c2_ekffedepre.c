/* Include files */

#include "blascompat32.h"
#include "ekffedepre_sfun.h"
#include "c2_ekffedepre.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ekffedepre_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[14] = { "q1", "q2", "q3", "q0", "bp",
  "bq", "br", "nargin", "nargout", "x", "p", "q", "r", "F" };

/* Function Declarations */
static void initialize_c2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance);
static void initialize_params_c2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance);
static void enable_c2_ekffedepre(SFc2_ekffedepreInstanceStruct *chartInstance);
static void disable_c2_ekffedepre(SFc2_ekffedepreInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_ekffedepre(SFc2_ekffedepreInstanceStruct *
  chartInstance);
static void set_sim_state_c2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_ekffedepre(SFc2_ekffedepreInstanceStruct *chartInstance);
static void sf_c2_ekffedepre(SFc2_ekffedepreInstanceStruct *chartInstance);
static void c2_chartstep_c2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance);
static void initSimStructsc2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c2_F, const char_T *c2_identifier, real_T c2_y[49]);
static void c2_b_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[49]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_ekffedepre, const char_T
  *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_ekffedepreInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_ekffedepre = 0U;
}

static void initialize_params_c2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance)
{
}

static void enable_c2_ekffedepre(SFc2_ekffedepreInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_ekffedepre(SFc2_ekffedepreInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_ekffedepre(SFc2_ekffedepreInstanceStruct *
  chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[49];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_F)[49];
  c2_F = (real_T (*)[49])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  for (c2_i0 = 0; c2_i0 < 49; c2_i0++) {
    c2_u[c2_i0] = (*c2_F)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 7, 7));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_ekffedepre;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[49];
  int32_T c2_i1;
  real_T (*c2_F)[49];
  c2_F = (real_T (*)[49])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "F",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 49; c2_i1++) {
    (*c2_F)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_ekffedepre = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_ekffedepre");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_ekffedepre(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_ekffedepre(SFc2_ekffedepreInstanceStruct *chartInstance)
{
}

static void sf_c2_ekffedepre(SFc2_ekffedepreInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  real_T *c2_p;
  real_T *c2_q;
  real_T *c2_r;
  real_T (*c2_F)[49];
  real_T (*c2_x)[7];
  c2_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_q = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_F = (real_T (*)[49])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 7; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_x)[c2_i2], 0U);
  }

  for (c2_i3 = 0; c2_i3 < 49; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_F)[c2_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_p, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_q, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_r, 4U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_ekffedepre(chartInstance);
  sf_debug_check_for_state_inconsistency(_ekffedepreMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  int32_T c2_i4;
  real_T c2_x[7];
  real_T c2_p;
  real_T c2_q;
  real_T c2_r;
  uint32_T c2_debug_family_var_map[14];
  real_T c2_q1;
  real_T c2_q2;
  real_T c2_q3;
  real_T c2_q0;
  real_T c2_bp;
  real_T c2_bq;
  real_T c2_br;
  real_T c2_nargin = 4.0;
  real_T c2_nargout = 1.0;
  real_T c2_F[49];
  real_T c2_b;
  real_T c2_y;
  real_T c2_b_b;
  real_T c2_b_y;
  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_d_b;
  real_T c2_d_y;
  real_T c2_e_b;
  real_T c2_e_y;
  real_T c2_f_b;
  real_T c2_f_y;
  real_T c2_g_b;
  real_T c2_g_y;
  real_T c2_h_b;
  real_T c2_h_y;
  real_T c2_i_b;
  real_T c2_i_y;
  real_T c2_j_b;
  real_T c2_j_y;
  real_T c2_k_b;
  real_T c2_k_y;
  real_T c2_l_b;
  real_T c2_l_y;
  real_T c2_m_b;
  real_T c2_m_y;
  real_T c2_n_b;
  real_T c2_n_y;
  real_T c2_o_b;
  real_T c2_o_y;
  real_T c2_p_b;
  real_T c2_p_y;
  real_T c2_q_b;
  real_T c2_q_y;
  real_T c2_r_b;
  real_T c2_r_y;
  real_T c2_s_b;
  real_T c2_s_y;
  real_T c2_t_b;
  real_T c2_t_y;
  real_T c2_u_b;
  real_T c2_u_y;
  real_T c2_v_b;
  real_T c2_v_y;
  real_T c2_w_b;
  real_T c2_w_y;
  real_T c2_x_b;
  real_T c2_x_y;
  real_T c2_y_b;
  real_T c2_y_y;
  real_T c2_ab_b;
  real_T c2_ab_y;
  real_T c2_bb_b;
  real_T c2_bb_y;
  real_T c2_cb_b;
  real_T c2_cb_y;
  real_T c2_db_b;
  real_T c2_db_y;
  real_T c2_eb_b;
  real_T c2_eb_y;
  real_T c2_fb_b;
  real_T c2_fb_y;
  real_T c2_gb_b;
  real_T c2_gb_y;
  real_T c2_hb_b;
  real_T c2_hb_y;
  real_T c2_ib_b;
  real_T c2_ib_y;
  real_T c2_jb_b;
  real_T c2_jb_y;
  real_T c2_kb_b;
  real_T c2_kb_y;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  real_T *c2_b_p;
  real_T *c2_b_q;
  real_T *c2_b_r;
  real_T (*c2_b_F)[49];
  real_T (*c2_b_x)[7];
  c2_b_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_q = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_F = (real_T (*)[49])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_p;
  c2_b_hoistedGlobal = *c2_b_q;
  c2_c_hoistedGlobal = *c2_b_r;
  for (c2_i4 = 0; c2_i4 < 7; c2_i4++) {
    c2_x[c2_i4] = (*c2_b_x)[c2_i4];
  }

  c2_p = c2_hoistedGlobal;
  c2_q = c2_b_hoistedGlobal;
  c2_r = c2_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 14U, 14U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_q1, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_q2, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_q3, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_q0, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_bp, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_bq, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_br, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_x, 9U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_p, 10U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_q, 11U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_r, 12U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_F, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_q1 = c2_x[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_q2 = c2_x[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_q3 = c2_x[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_q0 = c2_x[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_bp = c2_x[4];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_bq = c2_x[5];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_br = c2_x[6];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_b = c2_r;
  c2_y = 0.5 * c2_b;
  c2_b_b = c2_br;
  c2_b_y = 0.5 * c2_b_b;
  c2_c_b = c2_q;
  c2_c_y = -0.5 * c2_c_b;
  c2_d_b = c2_bq;
  c2_d_y = 0.5 * c2_d_b;
  c2_e_b = c2_p;
  c2_e_y = 0.5 * c2_e_b;
  c2_f_b = c2_bp;
  c2_f_y = 0.5 * c2_f_b;
  c2_g_b = c2_q0;
  c2_g_y = -0.5 * c2_g_b;
  c2_h_b = c2_q3;
  c2_h_y = 0.5 * c2_h_b;
  c2_i_b = c2_q2;
  c2_i_y = -0.5 * c2_i_b;
  c2_j_b = c2_r;
  c2_j_y = -0.5 * c2_j_b;
  c2_k_b = c2_br;
  c2_k_y = 0.5 * c2_k_b;
  c2_l_b = c2_p;
  c2_l_y = 0.5 * c2_l_b;
  c2_m_b = c2_bp;
  c2_m_y = 0.5 * c2_m_b;
  c2_n_b = c2_q;
  c2_n_y = 0.5 * c2_n_b;
  c2_o_b = c2_bq;
  c2_o_y = 0.5 * c2_o_b;
  c2_p_b = c2_q3;
  c2_p_y = -0.5 * c2_p_b;
  c2_q_b = c2_q0;
  c2_q_y = -0.5 * c2_q_b;
  c2_r_b = c2_q1;
  c2_r_y = 0.5 * c2_r_b;
  c2_s_b = c2_q;
  c2_s_y = 0.5 * c2_s_b;
  c2_t_b = c2_bq;
  c2_t_y = 0.5 * c2_t_b;
  c2_u_b = c2_p;
  c2_u_y = -0.5 * c2_u_b;
  c2_v_b = c2_bp;
  c2_v_y = 0.5 * c2_v_b;
  c2_w_b = c2_r;
  c2_w_y = 0.5 * c2_w_b;
  c2_x_b = c2_br;
  c2_x_y = 0.5 * c2_x_b;
  c2_y_b = c2_q2;
  c2_y_y = 0.5 * c2_y_b;
  c2_ab_b = c2_q1;
  c2_ab_y = -0.5 * c2_ab_b;
  c2_bb_b = c2_q0;
  c2_bb_y = -0.5 * c2_bb_b;
  c2_cb_b = c2_p;
  c2_cb_y = -0.5 * c2_cb_b;
  c2_db_b = c2_bp;
  c2_db_y = 0.5 * c2_db_b;
  c2_eb_b = c2_q;
  c2_eb_y = -0.5 * c2_eb_b;
  c2_fb_b = c2_bq;
  c2_fb_y = 0.5 * c2_fb_b;
  c2_gb_b = c2_r;
  c2_gb_y = -0.5 * c2_gb_b;
  c2_hb_b = c2_br;
  c2_hb_y = 0.5 * c2_hb_b;
  c2_ib_b = c2_q1;
  c2_ib_y = 0.5 * c2_ib_b;
  c2_jb_b = c2_q2;
  c2_jb_y = 0.5 * c2_jb_b;
  c2_kb_b = c2_q3;
  c2_kb_y = 0.5 * c2_kb_b;
  c2_F[0] = 0.0;
  c2_F[7] = c2_y - c2_b_y;
  c2_F[14] = c2_c_y + c2_d_y;
  c2_F[21] = c2_e_y - c2_f_y;
  c2_F[28] = c2_g_y;
  c2_F[35] = c2_h_y;
  c2_F[42] = c2_i_y;
  c2_F[1] = c2_j_y + c2_k_y;
  c2_F[8] = 0.0;
  c2_F[15] = c2_l_y - c2_m_y;
  c2_F[22] = c2_n_y - c2_o_y;
  c2_F[29] = c2_p_y;
  c2_F[36] = c2_q_y;
  c2_F[43] = c2_r_y;
  c2_F[2] = c2_s_y - c2_t_y;
  c2_F[9] = c2_u_y + c2_v_y;
  c2_F[16] = 0.0;
  c2_F[23] = c2_w_y - c2_x_y;
  c2_F[30] = c2_y_y;
  c2_F[37] = c2_ab_y;
  c2_F[44] = c2_bb_y;
  c2_F[3] = c2_cb_y + c2_db_y;
  c2_F[10] = c2_eb_y + c2_fb_y;
  c2_F[17] = c2_gb_y + c2_hb_y;
  c2_F[24] = 0.0;
  c2_F[31] = c2_ib_y;
  c2_F[38] = c2_jb_y;
  c2_F[45] = c2_kb_y;
  c2_i5 = 0;
  for (c2_i6 = 0; c2_i6 < 7; c2_i6++) {
    c2_F[c2_i5 + 4] = 0.0;
    c2_i5 += 7;
  }

  c2_i7 = 0;
  for (c2_i8 = 0; c2_i8 < 7; c2_i8++) {
    c2_F[c2_i7 + 5] = 0.0;
    c2_i7 += 7;
  }

  c2_i9 = 0;
  for (c2_i10 = 0; c2_i10 < 7; c2_i10++) {
    c2_F[c2_i9 + 6] = 0.0;
    c2_i9 += 7;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -13);
  sf_debug_symbol_scope_pop();
  for (c2_i11 = 0; c2_i11 < 49; c2_i11++) {
    (*c2_b_F)[c2_i11] = c2_F[c2_i11];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_ekffedepre(SFc2_ekffedepreInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  real_T c2_b_inData[49];
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  real_T c2_u[49];
  const mxArray *c2_y = NULL;
  SFc2_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc2_ekffedepreInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i12 = 0;
  for (c2_i13 = 0; c2_i13 < 7; c2_i13++) {
    for (c2_i14 = 0; c2_i14 < 7; c2_i14++) {
      c2_b_inData[c2_i14 + c2_i12] = (*(real_T (*)[49])c2_inData)[c2_i14 +
        c2_i12];
    }

    c2_i12 += 7;
  }

  c2_i15 = 0;
  for (c2_i16 = 0; c2_i16 < 7; c2_i16++) {
    for (c2_i17 = 0; c2_i17 < 7; c2_i17++) {
      c2_u[c2_i17 + c2_i15] = c2_b_inData[c2_i17 + c2_i15];
    }

    c2_i15 += 7;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 7, 7));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c2_F, const char_T *c2_identifier, real_T c2_y[49])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_F), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_F);
}

static void c2_b_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[49])
{
  real_T c2_dv1[49];
  int32_T c2_i18;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 7, 7);
  for (c2_i18 = 0; c2_i18 < 49; c2_i18++) {
    c2_y[c2_i18] = c2_dv1[c2_i18];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_F;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[49];
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  SFc2_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc2_ekffedepreInstanceStruct *)chartInstanceVoid;
  c2_F = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_F), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_F);
  c2_i19 = 0;
  for (c2_i20 = 0; c2_i20 < 7; c2_i20++) {
    for (c2_i21 = 0; c2_i21 < 7; c2_i21++) {
      (*(real_T (*)[49])c2_outData)[c2_i21 + c2_i19] = c2_y[c2_i21 + c2_i19];
    }

    c2_i19 += 7;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc2_ekffedepreInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i22;
  real_T c2_b_inData[7];
  int32_T c2_i23;
  real_T c2_u[7];
  const mxArray *c2_y = NULL;
  SFc2_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc2_ekffedepreInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i22 = 0; c2_i22 < 7; c2_i22++) {
    c2_b_inData[c2_i22] = (*(real_T (*)[7])c2_inData)[c2_i22];
  }

  for (c2_i23 = 0; c2_i23 < 7; c2_i23++) {
    c2_u[c2_i23] = c2_b_inData[c2_i23];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc2_ekffedepreInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_ekffedepre_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[4];
  c2_ResolvedFunctionInfo (*c2_b_info)[4];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i24;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[4])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mrdivide";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[0].fileTimeLo = 2117098240U;
  (*c2_b_info)[0].fileTimeHi = 30130935U;
  (*c2_b_info)[0].mFileTimeLo = 3573034496U;
  (*c2_b_info)[0].mFileTimeHi = 30114299U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[1].name = "rdivide";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[1].fileTimeLo = 1847391744U;
  (*c2_b_info)[1].fileTimeHi = 30108011U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[2].name = "eml_div";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[2].fileTimeLo = 387391744U;
  (*c2_b_info)[2].fileTimeHi = 30108011U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context = "";
  (*c2_b_info)[3].name = "mtimes";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[3].fileTimeLo = 3573034496U;
  (*c2_b_info)[3].fileTimeHi = 30114299U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4));
  for (c2_i24 = 0; c2_i24 < 4; c2_i24++) {
    c2_r0 = &c2_info[c2_i24];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i24);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i24);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i24);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i24);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i24);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i24);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i24);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i24);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc2_ekffedepreInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i25;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i25, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i25;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc2_ekffedepreInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_ekffedepre, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_ekffedepre), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_ekffedepre);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_ekffedepreInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_ekffedepreInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_ekffedepre_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2177612475U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2916987943U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(588286095U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1645327369U);
}

mxArray *sf_c2_ekffedepre_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(434840538U);
    pr[1] = (double)(1430189555U);
    pr[2] = (double)(3266323551U);
    pr[3] = (double)(453544959U);
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
      pr[1] = (double)(7);
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

static const mxArray *sf_get_sim_state_info_c2_ekffedepre(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"F\",},{M[8],M[0],T\"is_active_c2_ekffedepre\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_ekffedepre_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_ekffedepreInstanceStruct *chartInstance;
    chartInstance = (SFc2_ekffedepreInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_ekffedepreMachineNumber_,
           2,
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
          init_script_number_translation(_ekffedepreMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_ekffedepreMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_ekffedepreMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"F");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,540);
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
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 7;
          dimVector[1]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_p;
          real_T *c2_q;
          real_T *c2_r;
          real_T (*c2_x)[7];
          real_T (*c2_F)[49];
          c2_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_q = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_F = (real_T (*)[49])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_x);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_F);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_p);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_q);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_r);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ekffedepreMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_ekffedepre(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_ekffedepreInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_ekffedepre((SFc2_ekffedepreInstanceStruct*)
    chartInstanceVar);
  initialize_c2_ekffedepre((SFc2_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_ekffedepre(void *chartInstanceVar)
{
  enable_c2_ekffedepre((SFc2_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_ekffedepre(void *chartInstanceVar)
{
  disable_c2_ekffedepre((SFc2_ekffedepreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_ekffedepre(void *chartInstanceVar)
{
  sf_c2_ekffedepre((SFc2_ekffedepreInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_ekffedepre(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_ekffedepre
    ((SFc2_ekffedepreInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_ekffedepre();/* state var info */
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

extern void sf_internal_set_sim_state_c2_ekffedepre(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_ekffedepre();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_ekffedepre((SFc2_ekffedepreInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_ekffedepre(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_ekffedepre(S);
}

static void sf_opaque_set_sim_state_c2_ekffedepre(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_ekffedepre(S, st);
}

static void sf_opaque_terminate_c2_ekffedepre(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_ekffedepreInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_ekffedepre((SFc2_ekffedepreInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_ekffedepre((SFc2_ekffedepreInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_ekffedepre(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_ekffedepre((SFc2_ekffedepreInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_ekffedepre(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ekffedepre","ekffedepre",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ekffedepre","ekffedepre",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ekffedepre",
      "ekffedepre",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ekffedepre","ekffedepre",2,4);
      sf_mark_chart_reusable_outputs(S,"ekffedepre","ekffedepre",2,1);
    }

    sf_set_rtw_dwork_info(S,"ekffedepre","ekffedepre",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3032088898U));
  ssSetChecksum1(S,(1012399367U));
  ssSetChecksum2(S,(4206093961U));
  ssSetChecksum3(S,(3149741906U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_ekffedepre(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ekffedepre", "ekffedepre",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_ekffedepre(SimStruct *S)
{
  SFc2_ekffedepreInstanceStruct *chartInstance;
  chartInstance = (SFc2_ekffedepreInstanceStruct *)malloc(sizeof
    (SFc2_ekffedepreInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_ekffedepreInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_ekffedepre;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_ekffedepre;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_ekffedepre;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_ekffedepre;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_ekffedepre;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_ekffedepre;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_ekffedepre;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_ekffedepre;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_ekffedepre;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_ekffedepre;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_ekffedepre;
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

void c2_ekffedepre_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_ekffedepre(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_ekffedepre(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_ekffedepre(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_ekffedepre_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
