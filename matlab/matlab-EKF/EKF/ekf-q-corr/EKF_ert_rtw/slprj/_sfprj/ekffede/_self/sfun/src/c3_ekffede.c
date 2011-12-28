/* Include files */

#include "blascompat32.h"
#include "ekffede_sfun.h"
#include "c3_ekffede.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ekffede_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[27] = { "sig_quad_acc", "sig_quad_m",
  "sig_quad_tot", "a1", "a2", "cteta", "lambda_max", "S", "adjS", "sigma", "k",
  "delta", "Z", "alpha", "beta", "gamma", "X", "nargin", "nargout", "V1", "V2",
  "W1", "W2", "sig_acc", "sig_m", "q_opt", "PQQ" };

/* Function Declarations */
static void initialize_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance);
static void initialize_params_c3_ekffede(SFc3_ekffedeInstanceStruct
  *chartInstance);
static void enable_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance);
static void disable_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_ekffede(SFc3_ekffedeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_ekffede(SFc3_ekffedeInstanceStruct
  *chartInstance);
static void set_sim_state_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_st);
static void finalize_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance);
static void sf_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance);
static void c3_chartstep_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance);
static void initSimStructsc3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance, const
  mxArray *c3_PQQ, const char_T *c3_identifier, real_T c3_y[9]);
static void c3_b_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[9]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_q_opt, const char_T *c3_identifier, real_T c3_y[4]);
static void c3_d_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_e_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_f_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[64]);
static real_T c3_norm(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_x[3]);
static real_T c3_ceval_xnrm2(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_n, real_T c3_x[3], int32_T c3_ix0, int32_T c3_incx);
static real_T c3_mpower(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_a);
static real_T c3_power(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_a,
  real_T c3_b);
static void c3_eml_scalar_eg(SFc3_ekffedeInstanceStruct *chartInstance);
static void c3_eml_error(SFc3_ekffedeInstanceStruct *chartInstance);
static real_T c3_dot(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_a[3],
                     real_T c3_b[3]);
static void c3_b_eml_scalar_eg(SFc3_ekffedeInstanceStruct *chartInstance);
static real_T c3_ceval_xdot(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_n, real_T c3_x[3], int32_T c3_ix0, int32_T c3_incx, real_T c3_y[3], int32_T
  c3_iy0, int32_T c3_incy);
static void c3_cross(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_a[3],
                     real_T c3_b[3], real_T c3_c[3]);
static real_T c3_sqrt(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_x);
static void c3_b_eml_error(SFc3_ekffedeInstanceStruct *chartInstance);
static real_T c3_det(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_x[9]);
static void c3_eps(SFc3_ekffedeInstanceStruct *chartInstance);
static void c3_eml_matlab_zgetrf(SFc3_ekffedeInstanceStruct *chartInstance,
  real_T c3_A[9], real_T c3_b_A[9], int32_T c3_ipiv[3], int32_T *c3_info);
static int32_T c3_eml_ixamax(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_n, real_T c3_x[9], int32_T c3_ix0);
static int32_T c3_ceval_ixamax(SFc3_ekffedeInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[9], int32_T c3_ix0, int32_T c3_incx);
static void c3_ceval_xswap(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_n, real_T c3_x[9], int32_T c3_ix0, int32_T c3_incx, int32_T c3_iy0, int32_T
  c3_incy, real_T c3_b_x[9]);
static void c3_ceval_xger(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_m, int32_T c3_n, real_T c3_alpha1, int32_T c3_ix0, int32_T c3_incx, int32_T
  c3_iy0, int32_T c3_incy, real_T c3_A[9], int32_T c3_ia0, int32_T c3_lda,
  real_T c3_b_A[9]);
static void c3_mrdivide(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_A[9],
  real_T c3_B[9], real_T c3_y[9]);
static void c3_eml_warning(SFc3_ekffedeInstanceStruct *chartInstance);
static void c3_c_eml_scalar_eg(SFc3_ekffedeInstanceStruct *chartInstance);
static void c3_diag(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_v[9],
                    real_T c3_d[3]);
static real_T c3_sum(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_x[3]);
static void c3_d_eml_scalar_eg(SFc3_ekffedeInstanceStruct *chartInstance);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_g_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_h_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_ekffede, const char_T *c3_identifier);
static uint8_T c3_i_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sqrt(SFc3_ekffedeInstanceStruct *chartInstance, real_T *c3_x);
static void c3_b_eml_matlab_zgetrf(SFc3_ekffedeInstanceStruct *chartInstance,
  real_T c3_A[9], int32_T c3_ipiv[3], int32_T *c3_info);
static void c3_b_ceval_xswap(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_n, real_T c3_x[9], int32_T c3_ix0, int32_T c3_incx, int32_T c3_iy0, int32_T
  c3_incy);
static void c3_b_ceval_xger(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_m, int32_T c3_n, real_T c3_alpha1, int32_T c3_ix0, int32_T c3_incx, int32_T
  c3_iy0, int32_T c3_incy, real_T c3_A[9], int32_T c3_ia0, int32_T c3_lda);
static void init_dsm_address_info(SFc3_ekffedeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_ekffede = 0U;
}

static void initialize_params_c3_ekffede(SFc3_ekffedeInstanceStruct
  *chartInstance)
{
}

static void enable_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_ekffede(SFc3_ekffedeInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_ekffede(SFc3_ekffedeInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[9];
  const mxArray *c3_b_y = NULL;
  int32_T c3_i1;
  real_T c3_b_u[4];
  const mxArray *c3_c_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T (*c3_q_opt)[4];
  real_T (*c3_PQQ)[9];
  c3_PQQ = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_q_opt = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(3));
  for (c3_i0 = 0; c3_i0 < 9; c3_i0++) {
    c3_u[c3_i0] = (*c3_PQQ)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_setcell(c3_y, 0, c3_b_y);
  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_b_u[c3_i1] = (*c3_q_opt)[c3_i1];
  }

  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_ekffede;
  c3_c_u = c3_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y);
  return c3_st;
}

static void set_sim_state_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[9];
  int32_T c3_i2;
  real_T c3_dv1[4];
  int32_T c3_i3;
  real_T (*c3_PQQ)[9];
  real_T (*c3_q_opt)[4];
  c3_PQQ = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_q_opt = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)), "PQQ",
                      c3_dv0);
  for (c3_i2 = 0; c3_i2 < 9; c3_i2++) {
    (*c3_PQQ)[c3_i2] = c3_dv0[c3_i2];
  }

  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
                        "q_opt", c3_dv1);
  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    (*c3_q_opt)[c3_i3] = c3_dv1[c3_i3];
  }

  chartInstance->c3_is_active_c3_ekffede = c3_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 2)), "is_active_c3_ekffede");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_ekffede(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance)
{
}

static void sf_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance)
{
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  real_T *c3_sig_acc;
  real_T *c3_sig_m;
  real_T (*c3_PQQ)[9];
  real_T (*c3_W2)[3];
  real_T (*c3_W1)[3];
  real_T (*c3_V2)[3];
  real_T (*c3_q_opt)[4];
  real_T (*c3_V1)[3];
  c3_sig_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_sig_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_PQQ = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_W2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c3_W1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c3_V2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_q_opt = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_V1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    _SFD_DATA_RANGE_CHECK((*c3_V1)[c3_i4], 0U);
  }

  for (c3_i5 = 0; c3_i5 < 4; c3_i5++) {
    _SFD_DATA_RANGE_CHECK((*c3_q_opt)[c3_i5], 1U);
  }

  for (c3_i6 = 0; c3_i6 < 3; c3_i6++) {
    _SFD_DATA_RANGE_CHECK((*c3_V2)[c3_i6], 2U);
  }

  for (c3_i7 = 0; c3_i7 < 3; c3_i7++) {
    _SFD_DATA_RANGE_CHECK((*c3_W1)[c3_i7], 3U);
  }

  for (c3_i8 = 0; c3_i8 < 3; c3_i8++) {
    _SFD_DATA_RANGE_CHECK((*c3_W2)[c3_i8], 4U);
  }

  for (c3_i9 = 0; c3_i9 < 9; c3_i9++) {
    _SFD_DATA_RANGE_CHECK((*c3_PQQ)[c3_i9], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_sig_acc, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_sig_m, 7U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_ekffede(chartInstance);
  sf_debug_check_for_state_inconsistency(_ekffedeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  int32_T c3_i10;
  real_T c3_V1[3];
  int32_T c3_i11;
  real_T c3_V2[3];
  int32_T c3_i12;
  real_T c3_W1[3];
  int32_T c3_i13;
  real_T c3_W2[3];
  real_T c3_sig_acc;
  real_T c3_sig_m;
  uint32_T c3_debug_family_var_map[27];
  real_T c3_sig_quad_acc;
  real_T c3_sig_quad_m;
  real_T c3_sig_quad_tot;
  real_T c3_a1;
  real_T c3_a2;
  real_T c3_cteta;
  real_T c3_lambda_max;
  real_T c3_S[9];
  real_T c3_adjS[9];
  real_T c3_sigma;
  real_T c3_k;
  real_T c3_delta;
  real_T c3_Z[3];
  real_T c3_alpha;
  real_T c3_beta;
  real_T c3_gamma;
  real_T c3_X[3];
  real_T c3_nargin = 6.0;
  real_T c3_nargout = 2.0;
  real_T c3_q_opt[4];
  real_T c3_PQQ[9];
  int32_T c3_i14;
  real_T c3_A[3];
  int32_T c3_i15;
  real_T c3_b_V1[3];
  real_T c3_B;
  real_T c3_y;
  real_T c3_b_y;
  real_T c3_c_y;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  real_T c3_b_V2[3];
  real_T c3_b_B;
  real_T c3_d_y;
  real_T c3_e_y;
  real_T c3_f_y;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  real_T c3_b_W1[3];
  real_T c3_c_B;
  real_T c3_g_y;
  real_T c3_h_y;
  real_T c3_i_y;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  real_T c3_b_W2[3];
  real_T c3_d_B;
  real_T c3_j_y;
  real_T c3_k_y;
  real_T c3_l_y;
  int32_T c3_i25;
  real_T c3_e_B;
  real_T c3_m_y;
  real_T c3_n_y;
  real_T c3_o_y;
  real_T c3_p_y;
  real_T c3_f_B;
  real_T c3_q_y;
  real_T c3_r_y;
  real_T c3_s_y;
  real_T c3_t_y;
  real_T c3_g_B;
  real_T c3_u_y;
  real_T c3_v_y;
  real_T c3_w_y;
  real_T c3_b_A;
  real_T c3_h_B;
  real_T c3_x;
  real_T c3_x_y;
  real_T c3_b_x;
  real_T c3_y_y;
  real_T c3_c_x;
  real_T c3_ab_y;
  real_T c3_c_A;
  real_T c3_i_B;
  real_T c3_d_x;
  real_T c3_bb_y;
  real_T c3_e_x;
  real_T c3_cb_y;
  real_T c3_f_x;
  real_T c3_db_y;
  int32_T c3_i26;
  real_T c3_c_V1[3];
  int32_T c3_i27;
  real_T c3_c_V2[3];
  real_T c3_a;
  int32_T c3_i28;
  real_T c3_c_W1[3];
  int32_T c3_i29;
  real_T c3_c_W2[3];
  real_T c3_b;
  real_T c3_eb_y;
  int32_T c3_i30;
  real_T c3_d_V1[3];
  int32_T c3_i31;
  real_T c3_d_V2[3];
  int32_T c3_i32;
  real_T c3_d_A[3];
  real_T c3_b_a;
  int32_T c3_i33;
  real_T c3_d_W1[3];
  int32_T c3_i34;
  real_T c3_d_W2[3];
  int32_T c3_i35;
  real_T c3_e_A[3];
  real_T c3_b_b;
  real_T c3_fb_y;
  real_T c3_c_b;
  real_T c3_gb_y;
  real_T c3_c_a;
  real_T c3_d_b;
  real_T c3_hb_y;
  real_T c3_d_a;
  real_T c3_e_b;
  real_T c3_ib_y;
  int32_T c3_i36;
  int32_T c3_i37;
  real_T c3_f_b[3];
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i40;
  real_T c3_jb_y[9];
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  real_T c3_kb_y[9];
  real_T c3_e_a;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  real_T c3_lb_y[9];
  real_T c3_f_a;
  int32_T c3_i58;
  int32_T c3_i59;
  int32_T c3_i60;
  int32_T c3_i61;
  real_T c3_b_S[9];
  real_T c3_g_a;
  int32_T c3_i62;
  static real_T c3_g_b[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c3_i63;
  real_T c3_mb_y[9];
  int32_T c3_i64;
  real_T c3_c_S[9];
  real_T c3_dv2[9];
  int32_T c3_i65;
  int32_T c3_i66;
  real_T c3_d_S[9];
  int32_T c3_i67;
  real_T c3_f_A[3];
  real_T c3_h_b;
  int32_T c3_i68;
  real_T c3_b_adjS[9];
  int32_T c3_i69;
  real_T c3_g_A[3];
  int32_T c3_i70;
  real_T c3_e_S[9];
  real_T c3_h_a;
  int32_T c3_i71;
  real_T c3_e_W1[3];
  int32_T c3_i72;
  real_T c3_e_V1[3];
  real_T c3_i_b[3];
  int32_T c3_i73;
  real_T c3_i_a;
  int32_T c3_i74;
  real_T c3_e_W2[3];
  int32_T c3_i75;
  real_T c3_e_V2[3];
  int32_T c3_i76;
  int32_T c3_i77;
  real_T c3_j_a;
  real_T c3_j_b;
  real_T c3_nb_y;
  real_T c3_k_a;
  int32_T c3_i78;
  real_T c3_l_a;
  int32_T c3_i79;
  int32_T c3_i80;
  int32_T c3_i81;
  real_T c3_m_a[9];
  int32_T c3_i82;
  real_T c3_k_b[9];
  int32_T c3_i83;
  int32_T c3_i84;
  int32_T c3_i85;
  int32_T c3_i86;
  int32_T c3_i87;
  int32_T c3_i88;
  int32_T c3_i89;
  int32_T c3_i90;
  int32_T c3_i91;
  int32_T c3_i92;
  int32_T c3_i93;
  int32_T c3_i94;
  int32_T c3_i95;
  int32_T c3_i96;
  int32_T c3_i97;
  int32_T c3_i98;
  real_T c3_n_a;
  real_T c3_c;
  int32_T c3_i99;
  real_T c3_b_X[3];
  real_T c3_o_a;
  real_T c3_b_c;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_j_B;
  real_T c3_ob_y;
  real_T c3_pb_y;
  real_T c3_qb_y;
  real_T c3_rb_y;
  real_T c3_p_a;
  int32_T c3_i100;
  real_T c3_l_b[4];
  int32_T c3_i101;
  real_T c3_q_a;
  int32_T c3_i102;
  int32_T c3_i103;
  real_T c3_f_W1[3];
  int32_T c3_i104;
  real_T c3_f_W2[3];
  int32_T c3_i105;
  real_T c3_h_A[3];
  real_T c3_r_a;
  real_T c3_c_c;
  real_T c3_s_a;
  int32_T c3_i106;
  int32_T c3_i107;
  int32_T c3_i108;
  int32_T c3_i109;
  int32_T c3_i110;
  int32_T c3_i111;
  real_T c3_t_a;
  int32_T c3_i112;
  int32_T c3_i113;
  int32_T c3_i114;
  int32_T c3_i115;
  int32_T c3_i116;
  int32_T c3_i117;
  real_T c3_u_a;
  int32_T c3_i118;
  real_T c3_g_W1[3];
  int32_T c3_i119;
  real_T c3_g_W2[3];
  real_T c3_m_b;
  real_T c3_sb_y;
  int32_T c3_i120;
  int32_T c3_i121;
  int32_T c3_i122;
  int32_T c3_i123;
  int32_T c3_i124;
  int32_T c3_i125;
  int32_T c3_i126;
  int32_T c3_i127;
  int32_T c3_i128;
  int32_T c3_i129;
  real_T c3_v_a;
  int32_T c3_i130;
  int32_T c3_i131;
  real_T c3_w_a;
  int32_T c3_i132;
  int32_T c3_i133;
  int32_T c3_i134;
  int32_T c3_i135;
  int32_T c3_i136;
  int32_T c3_i137;
  real_T *c3_b_sig_acc;
  real_T *c3_b_sig_m;
  real_T (*c3_b_q_opt)[4];
  real_T (*c3_b_PQQ)[9];
  real_T (*c3_h_W2)[3];
  real_T (*c3_h_W1)[3];
  real_T (*c3_f_V2)[3];
  real_T (*c3_f_V1)[3];
  c3_b_sig_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_sig_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_PQQ = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_h_W2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c3_h_W1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c3_f_V2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_q_opt = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_f_V1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_sig_acc;
  c3_b_hoistedGlobal = *c3_b_sig_m;
  for (c3_i10 = 0; c3_i10 < 3; c3_i10++) {
    c3_V1[c3_i10] = (*c3_f_V1)[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
    c3_V2[c3_i11] = (*c3_f_V2)[c3_i11];
  }

  for (c3_i12 = 0; c3_i12 < 3; c3_i12++) {
    c3_W1[c3_i12] = (*c3_h_W1)[c3_i12];
  }

  for (c3_i13 = 0; c3_i13 < 3; c3_i13++) {
    c3_W2[c3_i13] = (*c3_h_W2)[c3_i13];
  }

  c3_sig_acc = c3_hoistedGlobal;
  c3_sig_m = c3_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 27U, 27U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_sig_quad_acc, 0U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_sig_quad_m, 1U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_sig_quad_tot, 2U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_a1, 3U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_a2, 4U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_cteta, 5U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_lambda_max, 6U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_S, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_adjS, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_sigma, 9U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_k, 10U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_delta, 11U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_Z, 12U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_alpha, 13U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_beta, 14U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_gamma, 15U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_X, 16U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 17U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 18U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c3_V1, 19U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_V2, 20U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_W1, 21U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_W2, 22U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_sig_acc, 23U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_sig_m, 24U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c3_q_opt, 25U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_PQQ, 26U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  for (c3_i14 = 0; c3_i14 < 3; c3_i14++) {
    c3_A[c3_i14] = c3_V1[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
    c3_b_V1[c3_i15] = c3_V1[c3_i15];
  }

  c3_B = c3_norm(chartInstance, c3_b_V1);
  c3_y = c3_B;
  c3_b_y = c3_y;
  c3_c_y = c3_b_y;
  for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
    c3_V1[c3_i16] = c3_A[c3_i16] / c3_c_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i17 = 0; c3_i17 < 3; c3_i17++) {
    c3_A[c3_i17] = c3_V2[c3_i17];
  }

  for (c3_i18 = 0; c3_i18 < 3; c3_i18++) {
    c3_b_V2[c3_i18] = c3_V2[c3_i18];
  }

  c3_b_B = c3_norm(chartInstance, c3_b_V2);
  c3_d_y = c3_b_B;
  c3_e_y = c3_d_y;
  c3_f_y = c3_e_y;
  for (c3_i19 = 0; c3_i19 < 3; c3_i19++) {
    c3_V2[c3_i19] = c3_A[c3_i19] / c3_f_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  for (c3_i20 = 0; c3_i20 < 3; c3_i20++) {
    c3_A[c3_i20] = c3_W1[c3_i20];
  }

  for (c3_i21 = 0; c3_i21 < 3; c3_i21++) {
    c3_b_W1[c3_i21] = c3_W1[c3_i21];
  }

  c3_c_B = c3_norm(chartInstance, c3_b_W1);
  c3_g_y = c3_c_B;
  c3_h_y = c3_g_y;
  c3_i_y = c3_h_y;
  for (c3_i22 = 0; c3_i22 < 3; c3_i22++) {
    c3_W1[c3_i22] = c3_A[c3_i22] / c3_i_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i23 = 0; c3_i23 < 3; c3_i23++) {
    c3_A[c3_i23] = c3_W2[c3_i23];
  }

  for (c3_i24 = 0; c3_i24 < 3; c3_i24++) {
    c3_b_W2[c3_i24] = c3_W2[c3_i24];
  }

  c3_d_B = c3_norm(chartInstance, c3_b_W2);
  c3_j_y = c3_d_B;
  c3_k_y = c3_j_y;
  c3_l_y = c3_k_y;
  for (c3_i25 = 0; c3_i25 < 3; c3_i25++) {
    c3_W2[c3_i25] = c3_A[c3_i25] / c3_l_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_sig_quad_acc = c3_mpower(chartInstance, c3_sig_acc);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_sig_quad_m = c3_mpower(chartInstance, c3_sig_m);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_e_B = c3_sig_quad_acc;
  c3_m_y = c3_e_B;
  c3_n_y = c3_m_y;
  c3_o_y = c3_n_y;
  c3_p_y = 1.0 / c3_o_y;
  c3_f_B = c3_sig_quad_m;
  c3_q_y = c3_f_B;
  c3_r_y = c3_q_y;
  c3_s_y = c3_r_y;
  c3_t_y = 1.0 / c3_s_y;
  c3_g_B = c3_p_y + c3_t_y;
  c3_u_y = c3_g_B;
  c3_v_y = c3_u_y;
  c3_w_y = c3_v_y;
  c3_sig_quad_tot = 1.0 / c3_w_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_b_A = c3_sig_quad_tot;
  c3_h_B = c3_sig_quad_acc;
  c3_x = c3_b_A;
  c3_x_y = c3_h_B;
  c3_b_x = c3_x;
  c3_y_y = c3_x_y;
  c3_c_x = c3_b_x;
  c3_ab_y = c3_y_y;
  c3_a1 = c3_c_x / c3_ab_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  c3_c_A = c3_sig_quad_tot;
  c3_i_B = c3_sig_quad_m;
  c3_d_x = c3_c_A;
  c3_bb_y = c3_i_B;
  c3_e_x = c3_d_x;
  c3_cb_y = c3_bb_y;
  c3_f_x = c3_e_x;
  c3_db_y = c3_cb_y;
  c3_a2 = c3_f_x / c3_db_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
  for (c3_i26 = 0; c3_i26 < 3; c3_i26++) {
    c3_c_V1[c3_i26] = c3_V1[c3_i26];
  }

  for (c3_i27 = 0; c3_i27 < 3; c3_i27++) {
    c3_c_V2[c3_i27] = c3_V2[c3_i27];
  }

  c3_a = c3_dot(chartInstance, c3_c_V1, c3_c_V2);
  for (c3_i28 = 0; c3_i28 < 3; c3_i28++) {
    c3_c_W1[c3_i28] = c3_W1[c3_i28];
  }

  for (c3_i29 = 0; c3_i29 < 3; c3_i29++) {
    c3_c_W2[c3_i29] = c3_W2[c3_i29];
  }

  c3_b = c3_dot(chartInstance, c3_c_W1, c3_c_W2);
  c3_eb_y = c3_a * c3_b;
  for (c3_i30 = 0; c3_i30 < 3; c3_i30++) {
    c3_d_V1[c3_i30] = c3_V1[c3_i30];
  }

  for (c3_i31 = 0; c3_i31 < 3; c3_i31++) {
    c3_d_V2[c3_i31] = c3_V2[c3_i31];
  }

  c3_cross(chartInstance, c3_d_V1, c3_d_V2, c3_A);
  for (c3_i32 = 0; c3_i32 < 3; c3_i32++) {
    c3_d_A[c3_i32] = c3_A[c3_i32];
  }

  c3_b_a = c3_norm(chartInstance, c3_d_A);
  for (c3_i33 = 0; c3_i33 < 3; c3_i33++) {
    c3_d_W1[c3_i33] = c3_W1[c3_i33];
  }

  for (c3_i34 = 0; c3_i34 < 3; c3_i34++) {
    c3_d_W2[c3_i34] = c3_W2[c3_i34];
  }

  c3_cross(chartInstance, c3_d_W1, c3_d_W2, c3_A);
  for (c3_i35 = 0; c3_i35 < 3; c3_i35++) {
    c3_e_A[c3_i35] = c3_A[c3_i35];
  }

  c3_b_b = c3_norm(chartInstance, c3_e_A);
  c3_fb_y = c3_b_a * c3_b_b;
  c3_cteta = c3_eb_y + c3_fb_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  c3_c_b = c3_a1;
  c3_gb_y = 2.0 * c3_c_b;
  c3_c_a = c3_gb_y;
  c3_d_b = c3_a2;
  c3_hb_y = c3_c_a * c3_d_b;
  c3_d_a = c3_hb_y;
  c3_e_b = c3_cteta;
  c3_ib_y = c3_d_a * c3_e_b;
  c3_lambda_max = (c3_mpower(chartInstance, c3_a1) + c3_mpower(chartInstance,
    c3_a2)) + c3_ib_y;
  c3_b_sqrt(chartInstance, &c3_lambda_max);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  for (c3_i36 = 0; c3_i36 < 3; c3_i36++) {
    c3_A[c3_i36] = c3_W1[c3_i36];
  }

  for (c3_i37 = 0; c3_i37 < 3; c3_i37++) {
    c3_f_b[c3_i37] = c3_V1[c3_i37];
  }

  c3_i38 = 0;
  for (c3_i39 = 0; c3_i39 < 3; c3_i39++) {
    for (c3_i40 = 0; c3_i40 < 3; c3_i40++) {
      c3_jb_y[c3_i40 + c3_i38] = c3_A[c3_i40] * c3_f_b[c3_i39];
    }

    c3_i38 += 3;
  }

  for (c3_i41 = 0; c3_i41 < 3; c3_i41++) {
    c3_A[c3_i41] = c3_V1[c3_i41];
  }

  for (c3_i42 = 0; c3_i42 < 3; c3_i42++) {
    c3_f_b[c3_i42] = c3_W1[c3_i42];
  }

  c3_i43 = 0;
  for (c3_i44 = 0; c3_i44 < 3; c3_i44++) {
    for (c3_i45 = 0; c3_i45 < 3; c3_i45++) {
      c3_kb_y[c3_i45 + c3_i43] = c3_A[c3_i45] * c3_f_b[c3_i44];
    }

    c3_i43 += 3;
  }

  c3_e_a = c3_a1;
  for (c3_i46 = 0; c3_i46 < 9; c3_i46++) {
    c3_jb_y[c3_i46] += c3_kb_y[c3_i46];
  }

  for (c3_i47 = 0; c3_i47 < 9; c3_i47++) {
    c3_jb_y[c3_i47] *= c3_e_a;
  }

  for (c3_i48 = 0; c3_i48 < 3; c3_i48++) {
    c3_A[c3_i48] = c3_W2[c3_i48];
  }

  for (c3_i49 = 0; c3_i49 < 3; c3_i49++) {
    c3_f_b[c3_i49] = c3_V2[c3_i49];
  }

  c3_i50 = 0;
  for (c3_i51 = 0; c3_i51 < 3; c3_i51++) {
    for (c3_i52 = 0; c3_i52 < 3; c3_i52++) {
      c3_kb_y[c3_i52 + c3_i50] = c3_A[c3_i52] * c3_f_b[c3_i51];
    }

    c3_i50 += 3;
  }

  for (c3_i53 = 0; c3_i53 < 3; c3_i53++) {
    c3_A[c3_i53] = c3_V2[c3_i53];
  }

  for (c3_i54 = 0; c3_i54 < 3; c3_i54++) {
    c3_f_b[c3_i54] = c3_W2[c3_i54];
  }

  c3_i55 = 0;
  for (c3_i56 = 0; c3_i56 < 3; c3_i56++) {
    for (c3_i57 = 0; c3_i57 < 3; c3_i57++) {
      c3_lb_y[c3_i57 + c3_i55] = c3_A[c3_i57] * c3_f_b[c3_i56];
    }

    c3_i55 += 3;
  }

  c3_f_a = c3_a2;
  for (c3_i58 = 0; c3_i58 < 9; c3_i58++) {
    c3_kb_y[c3_i58] += c3_lb_y[c3_i58];
  }

  for (c3_i59 = 0; c3_i59 < 9; c3_i59++) {
    c3_kb_y[c3_i59] *= c3_f_a;
  }

  for (c3_i60 = 0; c3_i60 < 9; c3_i60++) {
    c3_S[c3_i60] = c3_jb_y[c3_i60] + c3_kb_y[c3_i60];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  for (c3_i61 = 0; c3_i61 < 9; c3_i61++) {
    c3_b_S[c3_i61] = c3_S[c3_i61];
  }

  c3_g_a = c3_det(chartInstance, c3_b_S);
  for (c3_i62 = 0; c3_i62 < 9; c3_i62++) {
    c3_jb_y[c3_i62] = c3_g_a * c3_g_b[c3_i62];
  }

  for (c3_i63 = 0; c3_i63 < 9; c3_i63++) {
    c3_mb_y[c3_i63] = c3_jb_y[c3_i63];
  }

  for (c3_i64 = 0; c3_i64 < 9; c3_i64++) {
    c3_c_S[c3_i64] = c3_S[c3_i64];
  }

  c3_mrdivide(chartInstance, c3_mb_y, c3_c_S, c3_dv2);
  for (c3_i65 = 0; c3_i65 < 9; c3_i65++) {
    c3_adjS[c3_i65] = c3_dv2[c3_i65];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  for (c3_i66 = 0; c3_i66 < 9; c3_i66++) {
    c3_d_S[c3_i66] = c3_S[c3_i66];
  }

  c3_diag(chartInstance, c3_d_S, c3_A);
  for (c3_i67 = 0; c3_i67 < 3; c3_i67++) {
    c3_f_A[c3_i67] = c3_A[c3_i67];
  }

  c3_h_b = c3_sum(chartInstance, c3_f_A);
  c3_sigma = 0.5 * c3_h_b;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  for (c3_i68 = 0; c3_i68 < 9; c3_i68++) {
    c3_b_adjS[c3_i68] = c3_adjS[c3_i68];
  }

  c3_diag(chartInstance, c3_b_adjS, c3_A);
  for (c3_i69 = 0; c3_i69 < 3; c3_i69++) {
    c3_g_A[c3_i69] = c3_A[c3_i69];
  }

  c3_k = c3_sum(chartInstance, c3_g_A);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
  for (c3_i70 = 0; c3_i70 < 9; c3_i70++) {
    c3_e_S[c3_i70] = c3_S[c3_i70];
  }

  c3_delta = c3_det(chartInstance, c3_e_S);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_h_a = c3_a1;
  for (c3_i71 = 0; c3_i71 < 3; c3_i71++) {
    c3_e_W1[c3_i71] = c3_W1[c3_i71];
  }

  for (c3_i72 = 0; c3_i72 < 3; c3_i72++) {
    c3_e_V1[c3_i72] = c3_V1[c3_i72];
  }

  c3_cross(chartInstance, c3_e_W1, c3_e_V1, c3_i_b);
  for (c3_i73 = 0; c3_i73 < 3; c3_i73++) {
    c3_i_b[c3_i73] *= c3_h_a;
  }

  c3_i_a = c3_a2;
  for (c3_i74 = 0; c3_i74 < 3; c3_i74++) {
    c3_e_W2[c3_i74] = c3_W2[c3_i74];
  }

  for (c3_i75 = 0; c3_i75 < 3; c3_i75++) {
    c3_e_V2[c3_i75] = c3_V2[c3_i75];
  }

  c3_cross(chartInstance, c3_e_W2, c3_e_V2, c3_A);
  for (c3_i76 = 0; c3_i76 < 3; c3_i76++) {
    c3_A[c3_i76] *= c3_i_a;
  }

  for (c3_i77 = 0; c3_i77 < 3; c3_i77++) {
    c3_Z[c3_i77] = c3_i_b[c3_i77] + c3_A[c3_i77];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
  c3_alpha = (c3_mpower(chartInstance, c3_lambda_max) - c3_mpower(chartInstance,
    c3_sigma)) + c3_k;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
  c3_beta = c3_lambda_max - c3_sigma;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
  c3_j_a = c3_lambda_max + c3_sigma;
  c3_j_b = c3_alpha;
  c3_nb_y = c3_j_a * c3_j_b;
  c3_gamma = c3_nb_y - c3_delta;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
  c3_k_a = c3_alpha;
  for (c3_i78 = 0; c3_i78 < 9; c3_i78++) {
    c3_jb_y[c3_i78] = c3_k_a * c3_g_b[c3_i78];
  }

  c3_l_a = c3_beta;
  for (c3_i79 = 0; c3_i79 < 9; c3_i79++) {
    c3_lb_y[c3_i79] = c3_S[c3_i79];
  }

  for (c3_i80 = 0; c3_i80 < 9; c3_i80++) {
    c3_lb_y[c3_i80] *= c3_l_a;
  }

  for (c3_i81 = 0; c3_i81 < 9; c3_i81++) {
    c3_m_a[c3_i81] = c3_S[c3_i81];
  }

  for (c3_i82 = 0; c3_i82 < 9; c3_i82++) {
    c3_k_b[c3_i82] = c3_S[c3_i82];
  }

  c3_c_eml_scalar_eg(chartInstance);
  c3_c_eml_scalar_eg(chartInstance);
  for (c3_i83 = 0; c3_i83 < 3; c3_i83++) {
    c3_i84 = 0;
    for (c3_i85 = 0; c3_i85 < 3; c3_i85++) {
      c3_kb_y[c3_i84 + c3_i83] = 0.0;
      c3_i86 = 0;
      for (c3_i87 = 0; c3_i87 < 3; c3_i87++) {
        c3_kb_y[c3_i84 + c3_i83] += c3_m_a[c3_i86 + c3_i83] * c3_k_b[c3_i87 +
          c3_i84];
        c3_i86 += 3;
      }

      c3_i84 += 3;
    }
  }

  for (c3_i88 = 0; c3_i88 < 9; c3_i88++) {
    c3_jb_y[c3_i88] = (c3_jb_y[c3_i88] + c3_lb_y[c3_i88]) + c3_kb_y[c3_i88];
  }

  for (c3_i89 = 0; c3_i89 < 3; c3_i89++) {
    c3_i_b[c3_i89] = c3_Z[c3_i89];
  }

  c3_d_eml_scalar_eg(chartInstance);
  c3_d_eml_scalar_eg(chartInstance);
  for (c3_i90 = 0; c3_i90 < 3; c3_i90++) {
    c3_X[c3_i90] = 0.0;
  }

  for (c3_i91 = 0; c3_i91 < 3; c3_i91++) {
    c3_X[c3_i91] = 0.0;
  }

  for (c3_i92 = 0; c3_i92 < 3; c3_i92++) {
    c3_A[c3_i92] = c3_X[c3_i92];
  }

  for (c3_i93 = 0; c3_i93 < 3; c3_i93++) {
    c3_X[c3_i93] = c3_A[c3_i93];
  }

  for (c3_i94 = 0; c3_i94 < 3; c3_i94++) {
    c3_A[c3_i94] = c3_X[c3_i94];
  }

  for (c3_i95 = 0; c3_i95 < 3; c3_i95++) {
    c3_X[c3_i95] = c3_A[c3_i95];
  }

  for (c3_i96 = 0; c3_i96 < 3; c3_i96++) {
    c3_X[c3_i96] = 0.0;
    c3_i97 = 0;
    for (c3_i98 = 0; c3_i98 < 3; c3_i98++) {
      c3_X[c3_i96] += c3_jb_y[c3_i97 + c3_i96] * c3_i_b[c3_i98];
      c3_i97 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
  c3_n_a = c3_gamma;
  c3_c = c3_power(chartInstance, c3_n_a, 2.0);
  for (c3_i99 = 0; c3_i99 < 3; c3_i99++) {
    c3_b_X[c3_i99] = c3_X[c3_i99];
  }

  c3_o_a = c3_norm(chartInstance, c3_b_X);
  c3_b_c = c3_power(chartInstance, c3_o_a, 2.0);
  c3_g_x = c3_c + c3_b_c;
  c3_h_x = c3_g_x;
  if (c3_h_x < 0.0) {
    c3_b_eml_error(chartInstance);
  }

  c3_h_x = muDoubleScalarSqrt(c3_h_x);
  c3_j_B = c3_h_x;
  c3_ob_y = c3_j_B;
  c3_pb_y = c3_ob_y;
  c3_qb_y = c3_pb_y;
  c3_rb_y = 1.0 / c3_qb_y;
  c3_p_a = c3_rb_y;
  for (c3_i100 = 0; c3_i100 < 3; c3_i100++) {
    c3_l_b[c3_i100] = c3_X[c3_i100];
  }

  c3_l_b[3] = c3_gamma;
  for (c3_i101 = 0; c3_i101 < 4; c3_i101++) {
    c3_q_opt[c3_i101] = c3_p_a * c3_l_b[c3_i101];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
  c3_q_a = c3_sig_quad_tot;
  for (c3_i102 = 0; c3_i102 < 9; c3_i102++) {
    c3_jb_y[c3_i102] = c3_q_a * c3_g_b[c3_i102];
  }

  for (c3_i103 = 0; c3_i103 < 3; c3_i103++) {
    c3_f_W1[c3_i103] = c3_W1[c3_i103];
  }

  for (c3_i104 = 0; c3_i104 < 3; c3_i104++) {
    c3_f_W2[c3_i104] = c3_W2[c3_i104];
  }

  c3_cross(chartInstance, c3_f_W1, c3_f_W2, c3_A);
  for (c3_i105 = 0; c3_i105 < 3; c3_i105++) {
    c3_h_A[c3_i105] = c3_A[c3_i105];
  }

  c3_r_a = c3_norm(chartInstance, c3_h_A);
  c3_c_c = c3_power(chartInstance, c3_r_a, -2.0);
  c3_s_a = c3_sig_quad_m - c3_sig_quad_tot;
  for (c3_i106 = 0; c3_i106 < 3; c3_i106++) {
    c3_i_b[c3_i106] = c3_W1[c3_i106];
  }

  for (c3_i107 = 0; c3_i107 < 3; c3_i107++) {
    c3_i_b[c3_i107] *= c3_s_a;
  }

  for (c3_i108 = 0; c3_i108 < 3; c3_i108++) {
    c3_f_b[c3_i108] = c3_W1[c3_i108];
  }

  c3_i109 = 0;
  for (c3_i110 = 0; c3_i110 < 3; c3_i110++) {
    for (c3_i111 = 0; c3_i111 < 3; c3_i111++) {
      c3_kb_y[c3_i111 + c3_i109] = c3_i_b[c3_i111] * c3_f_b[c3_i110];
    }

    c3_i109 += 3;
  }

  c3_t_a = c3_sig_quad_acc - c3_sig_quad_tot;
  for (c3_i112 = 0; c3_i112 < 3; c3_i112++) {
    c3_i_b[c3_i112] = c3_W2[c3_i112];
  }

  for (c3_i113 = 0; c3_i113 < 3; c3_i113++) {
    c3_i_b[c3_i113] *= c3_t_a;
  }

  for (c3_i114 = 0; c3_i114 < 3; c3_i114++) {
    c3_f_b[c3_i114] = c3_W2[c3_i114];
  }

  c3_i115 = 0;
  for (c3_i116 = 0; c3_i116 < 3; c3_i116++) {
    for (c3_i117 = 0; c3_i117 < 3; c3_i117++) {
      c3_lb_y[c3_i117 + c3_i115] = c3_i_b[c3_i117] * c3_f_b[c3_i116];
    }

    c3_i115 += 3;
  }

  c3_u_a = c3_sig_quad_tot;
  for (c3_i118 = 0; c3_i118 < 3; c3_i118++) {
    c3_g_W1[c3_i118] = c3_W1[c3_i118];
  }

  for (c3_i119 = 0; c3_i119 < 3; c3_i119++) {
    c3_g_W2[c3_i119] = c3_W2[c3_i119];
  }

  c3_m_b = c3_dot(chartInstance, c3_g_W1, c3_g_W2);
  c3_sb_y = c3_u_a * c3_m_b;
  for (c3_i120 = 0; c3_i120 < 3; c3_i120++) {
    c3_A[c3_i120] = c3_W1[c3_i120];
  }

  for (c3_i121 = 0; c3_i121 < 3; c3_i121++) {
    c3_f_b[c3_i121] = c3_W2[c3_i121];
  }

  c3_i122 = 0;
  for (c3_i123 = 0; c3_i123 < 3; c3_i123++) {
    for (c3_i124 = 0; c3_i124 < 3; c3_i124++) {
      c3_m_a[c3_i124 + c3_i122] = c3_A[c3_i124] * c3_f_b[c3_i123];
    }

    c3_i122 += 3;
  }

  for (c3_i125 = 0; c3_i125 < 3; c3_i125++) {
    c3_A[c3_i125] = c3_W2[c3_i125];
  }

  for (c3_i126 = 0; c3_i126 < 3; c3_i126++) {
    c3_f_b[c3_i126] = c3_W1[c3_i126];
  }

  c3_i127 = 0;
  for (c3_i128 = 0; c3_i128 < 3; c3_i128++) {
    for (c3_i129 = 0; c3_i129 < 3; c3_i129++) {
      c3_k_b[c3_i129 + c3_i127] = c3_A[c3_i129] * c3_f_b[c3_i128];
    }

    c3_i127 += 3;
  }

  c3_v_a = c3_sb_y;
  for (c3_i130 = 0; c3_i130 < 9; c3_i130++) {
    c3_m_a[c3_i130] += c3_k_b[c3_i130];
  }

  for (c3_i131 = 0; c3_i131 < 9; c3_i131++) {
    c3_m_a[c3_i131] *= c3_v_a;
  }

  c3_w_a = c3_c_c;
  for (c3_i132 = 0; c3_i132 < 9; c3_i132++) {
    c3_kb_y[c3_i132] = (c3_kb_y[c3_i132] + c3_lb_y[c3_i132]) + c3_m_a[c3_i132];
  }

  for (c3_i133 = 0; c3_i133 < 9; c3_i133++) {
    c3_kb_y[c3_i133] *= c3_w_a;
  }

  for (c3_i134 = 0; c3_i134 < 9; c3_i134++) {
    c3_jb_y[c3_i134] += c3_kb_y[c3_i134];
  }

  for (c3_i135 = 0; c3_i135 < 9; c3_i135++) {
    c3_PQQ[c3_i135] = 0.25 * c3_jb_y[c3_i135];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -30);
  sf_debug_symbol_scope_pop();
  for (c3_i136 = 0; c3_i136 < 4; c3_i136++) {
    (*c3_b_q_opt)[c3_i136] = c3_q_opt[c3_i136];
  }

  for (c3_i137 = 0; c3_i137 < 9; c3_i137++) {
    (*c3_b_PQQ)[c3_i137] = c3_PQQ[c3_i137];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_ekffede(SFc3_ekffedeInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i138;
  int32_T c3_i139;
  int32_T c3_i140;
  real_T c3_b_inData[9];
  int32_T c3_i141;
  int32_T c3_i142;
  int32_T c3_i143;
  real_T c3_u[9];
  const mxArray *c3_y = NULL;
  SFc3_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc3_ekffedeInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i138 = 0;
  for (c3_i139 = 0; c3_i139 < 3; c3_i139++) {
    for (c3_i140 = 0; c3_i140 < 3; c3_i140++) {
      c3_b_inData[c3_i140 + c3_i138] = (*(real_T (*)[9])c3_inData)[c3_i140 +
        c3_i138];
    }

    c3_i138 += 3;
  }

  c3_i141 = 0;
  for (c3_i142 = 0; c3_i142 < 3; c3_i142++) {
    for (c3_i143 = 0; c3_i143 < 3; c3_i143++) {
      c3_u[c3_i143 + c3_i141] = c3_b_inData[c3_i143 + c3_i141];
    }

    c3_i141 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance, const
  mxArray *c3_PQQ, const char_T *c3_identifier, real_T c3_y[9])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_PQQ), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_PQQ);
}

static void c3_b_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[9])
{
  real_T c3_dv3[9];
  int32_T c3_i144;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv3, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c3_i144 = 0; c3_i144 < 9; c3_i144++) {
    c3_y[c3_i144] = c3_dv3[c3_i144];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_PQQ;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[9];
  int32_T c3_i145;
  int32_T c3_i146;
  int32_T c3_i147;
  SFc3_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc3_ekffedeInstanceStruct *)chartInstanceVoid;
  c3_PQQ = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_PQQ), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_PQQ);
  c3_i145 = 0;
  for (c3_i146 = 0; c3_i146 < 3; c3_i146++) {
    for (c3_i147 = 0; c3_i147 < 3; c3_i147++) {
      (*(real_T (*)[9])c3_outData)[c3_i147 + c3_i145] = c3_y[c3_i147 + c3_i145];
    }

    c3_i145 += 3;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i148;
  real_T c3_b_inData[4];
  int32_T c3_i149;
  real_T c3_u[4];
  const mxArray *c3_y = NULL;
  SFc3_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc3_ekffedeInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i148 = 0; c3_i148 < 4; c3_i148++) {
    c3_b_inData[c3_i148] = (*(real_T (*)[4])c3_inData)[c3_i148];
  }

  for (c3_i149 = 0; c3_i149 < 4; c3_i149++) {
    c3_u[c3_i149] = c3_b_inData[c3_i149];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_q_opt, const char_T *c3_identifier, real_T c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_q_opt), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_q_opt);
}

static void c3_d_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4])
{
  real_T c3_dv4[4];
  int32_T c3_i150;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv4, 1, 0, 0U, 1, 0U, 1, 4);
  for (c3_i150 = 0; c3_i150 < 4; c3_i150++) {
    c3_y[c3_i150] = c3_dv4[c3_i150];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_q_opt;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[4];
  int32_T c3_i151;
  SFc3_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc3_ekffedeInstanceStruct *)chartInstanceVoid;
  c3_q_opt = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_q_opt), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_q_opt);
  for (c3_i151 = 0; c3_i151 < 4; c3_i151++) {
    (*(real_T (*)[4])c3_outData)[c3_i151] = c3_y[c3_i151];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc3_ekffedeInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i152;
  real_T c3_b_inData[3];
  int32_T c3_i153;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc3_ekffedeInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i152 = 0; c3_i152 < 3; c3_i152++) {
    c3_b_inData[c3_i152] = (*(real_T (*)[3])c3_inData)[c3_i152];
  }

  for (c3_i153 = 0; c3_i153 < 3; c3_i153++) {
    c3_u[c3_i153] = c3_b_inData[c3_i153];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static real_T c3_e_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc3_ekffedeInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_f_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3])
{
  real_T c3_dv5[3];
  int32_T c3_i154;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i154 = 0; c3_i154 < 3; c3_i154++) {
    c3_y[c3_i154] = c3_dv5[c3_i154];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_X;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i155;
  SFc3_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc3_ekffedeInstanceStruct *)chartInstanceVoid;
  c3_X = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_X), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_X);
  for (c3_i155 = 0; c3_i155 < 3; c3_i155++) {
    (*(real_T (*)[3])c3_outData)[c3_i155] = c3_y[c3_i155];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_ekffede_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[64];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i156;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 64));
  for (c3_i156 = 0; c3_i156 < 64; c3_i156++) {
    c3_r0 = &c3_info[c3_i156];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i156);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i156);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i156);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i156);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i156);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i156);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i156);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i156);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[64])
{
  c3_info[0].context = "";
  c3_info[0].name = "norm";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c3_info[0].fileTimeLo = 1667391744U;
  c3_info[0].fileTimeHi = 30108011U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c3_info[1].name = "eml_index_class";
  c3_info[1].dominantType = "";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[1].fileTimeLo = 1187391744U;
  c3_info[1].fileTimeHi = 30108011U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c3_info[2].name = "eml_xnrm2";
  c3_info[2].dominantType = "int32";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c3_info[2].fileTimeLo = 527391744U;
  c3_info[2].fileTimeHi = 30108011U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c3_info[3].name = "eml_refblas_xnrm2";
  c3_info[3].dominantType = "int32";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[3].fileTimeLo = 1527391744U;
  c3_info[3].fileTimeHi = 30108011U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[4].name = "eml_index_minus";
  c3_info[4].dominantType = "int32";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[4].fileTimeLo = 1187391744U;
  c3_info[4].fileTimeHi = 30108011U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[5].name = "eml_index_times";
  c3_info[5].dominantType = "int32";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[5].fileTimeLo = 1207391744U;
  c3_info[5].fileTimeHi = 30108011U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[6].name = "eml_index_plus";
  c3_info[6].dominantType = "int32";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[6].fileTimeLo = 1187391744U;
  c3_info[6].fileTimeHi = 30108011U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[7].name = "abs";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[7].fileTimeLo = 347391744U;
  c3_info[7].fileTimeHi = 30108011U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[8].name = "eml_scalar_abs";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[8].fileTimeLo = 527391744U;
  c3_info[8].fileTimeHi = 30108011U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context = "";
  c3_info[9].name = "mrdivide";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[9].fileTimeLo = 2117098240U;
  c3_info[9].fileTimeHi = 30130935U;
  c3_info[9].mFileTimeLo = 3573034496U;
  c3_info[9].mFileTimeHi = 30114299U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[10].name = "rdivide";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[10].fileTimeLo = 1847391744U;
  c3_info[10].fileTimeHi = 30108011U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[11].name = "eml_div";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[11].fileTimeLo = 387391744U;
  c3_info[11].fileTimeHi = 30108011U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context = "";
  c3_info[12].name = "mpower";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[12].fileTimeLo = 1827391744U;
  c3_info[12].fileTimeHi = 30108011U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[13].name = "power";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[13].fileTimeLo = 1847391744U;
  c3_info[13].fileTimeHi = 30108011U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[14].name = "eml_scalar_eg";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[14].fileTimeLo = 1367391744U;
  c3_info[14].fileTimeHi = 30108011U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[15].name = "eml_scalexp_alloc";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[15].fileTimeLo = 1367391744U;
  c3_info[15].fileTimeHi = 30108011U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[16].name = "eml_scalar_floor";
  c3_info[16].dominantType = "double";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[16].fileTimeLo = 667391744U;
  c3_info[16].fileTimeHi = 30108011U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[17].name = "eml_error";
  c3_info[17].dominantType = "char";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[17].fileTimeLo = 407391744U;
  c3_info[17].fileTimeHi = 30108011U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context = "";
  c3_info[18].name = "dot";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c3_info[18].fileTimeLo = 1827391744U;
  c3_info[18].fileTimeHi = 30108011U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c3_info[19].name = "isequal";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c3_info[19].fileTimeLo = 987391744U;
  c3_info[19].fileTimeHi = 30108011U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c3_info[20].name = "eml_isequal_core";
  c3_info[20].dominantType = "double";
  c3_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c3_info[20].fileTimeLo = 1267391744U;
  c3_info[20].fileTimeHi = 30108011U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c3_info[21].name = "isnan";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[21].fileTimeLo = 1007391744U;
  c3_info[21].fileTimeHi = 30108011U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m!vdot";
  c3_info[22].name = "eml_xdotc";
  c3_info[22].dominantType = "int32";
  c3_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c3_info[22].fileTimeLo = 487391744U;
  c3_info[22].fileTimeHi = 30108011U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c3_info[23].name = "eml_xdot";
  c3_info[23].dominantType = "int32";
  c3_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[23].fileTimeLo = 487391744U;
  c3_info[23].fileTimeHi = 30108011U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c3_info[24].name = "eml_refblas_xdot";
  c3_info[24].dominantType = "int32";
  c3_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[24].fileTimeLo = 1207391744U;
  c3_info[24].fileTimeHi = 30108011U;
  c3_info[24].mFileTimeLo = 0U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[25].name = "eml_refblas_xdotx";
  c3_info[25].dominantType = "int32";
  c3_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[25].fileTimeLo = 1227391744U;
  c3_info[25].fileTimeHi = 30108011U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
  c3_info[26].context = "";
  c3_info[26].name = "mtimes";
  c3_info[26].dominantType = "double";
  c3_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[26].fileTimeLo = 3573034496U;
  c3_info[26].fileTimeHi = 30114299U;
  c3_info[26].mFileTimeLo = 0U;
  c3_info[26].mFileTimeHi = 0U;
  c3_info[27].context = "";
  c3_info[27].name = "cross";
  c3_info[27].dominantType = "double";
  c3_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c3_info[27].fileTimeLo = 1827391744U;
  c3_info[27].fileTimeHi = 30108011U;
  c3_info[27].mFileTimeLo = 0U;
  c3_info[27].mFileTimeHi = 0U;
  c3_info[28].context = "";
  c3_info[28].name = "sqrt";
  c3_info[28].dominantType = "double";
  c3_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[28].fileTimeLo = 927391744U;
  c3_info[28].fileTimeHi = 30108011U;
  c3_info[28].mFileTimeLo = 0U;
  c3_info[28].mFileTimeHi = 0U;
  c3_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[29].name = "eml_scalar_sqrt";
  c3_info[29].dominantType = "double";
  c3_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c3_info[29].fileTimeLo = 787391744U;
  c3_info[29].fileTimeHi = 30108011U;
  c3_info[29].mFileTimeLo = 0U;
  c3_info[29].mFileTimeHi = 0U;
  c3_info[30].context = "";
  c3_info[30].name = "det";
  c3_info[30].dominantType = "double";
  c3_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c3_info[30].fileTimeLo = 1627391744U;
  c3_info[30].fileTimeHi = 30108011U;
  c3_info[30].mFileTimeLo = 0U;
  c3_info[30].mFileTimeHi = 0U;
  c3_info[31].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c3_info[31].name = "eml_xgetrf";
  c3_info[31].dominantType = "int32";
  c3_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c3_info[31].fileTimeLo = 1467391744U;
  c3_info[31].fileTimeHi = 30108011U;
  c3_info[31].mFileTimeLo = 0U;
  c3_info[31].mFileTimeHi = 0U;
  c3_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c3_info[32].name = "eml_lapack_xgetrf";
  c3_info[32].dominantType = "int32";
  c3_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c3_info[32].fileTimeLo = 1507391744U;
  c3_info[32].fileTimeHi = 30108011U;
  c3_info[32].mFileTimeLo = 0U;
  c3_info[32].mFileTimeHi = 0U;
  c3_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c3_info[33].name = "eml_matlab_zgetrf";
  c3_info[33].dominantType = "int32";
  c3_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c3_info[33].fileTimeLo = 1567391744U;
  c3_info[33].fileTimeHi = 30108011U;
  c3_info[33].mFileTimeLo = 0U;
  c3_info[33].mFileTimeHi = 0U;
  c3_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c3_info[34].name = "realmin";
  c3_info[34].dominantType = "char";
  c3_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c3_info[34].fileTimeLo = 1087391744U;
  c3_info[34].fileTimeHi = 30108011U;
  c3_info[34].mFileTimeLo = 0U;
  c3_info[34].mFileTimeHi = 0U;
  c3_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c3_info[35].name = "eps";
  c3_info[35].dominantType = "char";
  c3_info[35].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[35].fileTimeLo = 267391744U;
  c3_info[35].fileTimeHi = 30108011U;
  c3_info[35].mFileTimeLo = 0U;
  c3_info[35].mFileTimeHi = 0U;
  c3_info[36].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[36].name = "eml_is_float_class";
  c3_info[36].dominantType = "char";
  c3_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[36].fileTimeLo = 1227391744U;
  c3_info[36].fileTimeHi = 30108011U;
  c3_info[36].mFileTimeLo = 0U;
  c3_info[36].mFileTimeHi = 0U;
  c3_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c3_info[37].name = "min";
  c3_info[37].dominantType = "int32";
  c3_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[37].fileTimeLo = 367391744U;
  c3_info[37].fileTimeHi = 30108011U;
  c3_info[37].mFileTimeLo = 0U;
  c3_info[37].mFileTimeHi = 0U;
  c3_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[38].name = "eml_min_or_max";
  c3_info[38].dominantType = "int32";
  c3_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[38].fileTimeLo = 1287391744U;
  c3_info[38].fileTimeHi = 30108011U;
  c3_info[38].mFileTimeLo = 0U;
  c3_info[38].mFileTimeHi = 0U;
  c3_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c3_info[39].name = "colon";
  c3_info[39].dominantType = "int32";
  c3_info[39].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c3_info[39].fileTimeLo = 1787391744U;
  c3_info[39].fileTimeHi = 30108011U;
  c3_info[39].mFileTimeLo = 0U;
  c3_info[39].mFileTimeHi = 0U;
  c3_info[40].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c3_info[40].name = "floor";
  c3_info[40].dominantType = "double";
  c3_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[40].fileTimeLo = 827391744U;
  c3_info[40].fileTimeHi = 30108011U;
  c3_info[40].mFileTimeLo = 0U;
  c3_info[40].mFileTimeHi = 0U;
  c3_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c3_info[41].name = "intmin";
  c3_info[41].dominantType = "char";
  c3_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c3_info[41].fileTimeLo = 967391744U;
  c3_info[41].fileTimeHi = 30108011U;
  c3_info[41].mFileTimeLo = 0U;
  c3_info[41].mFileTimeHi = 0U;
  c3_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c3_info[42].name = "intmax";
  c3_info[42].dominantType = "char";
  c3_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[42].fileTimeLo = 967391744U;
  c3_info[42].fileTimeHi = 30108011U;
  c3_info[42].mFileTimeLo = 0U;
  c3_info[42].mFileTimeHi = 0U;
  c3_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c3_info[43].name = "eml_ixamax";
  c3_info[43].dominantType = "int32";
  c3_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c3_info[43].fileTimeLo = 447391744U;
  c3_info[43].fileTimeHi = 30108011U;
  c3_info[43].mFileTimeLo = 0U;
  c3_info[43].mFileTimeHi = 0U;
  c3_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c3_info[44].name = "eml_refblas_ixamax";
  c3_info[44].dominantType = "int32";
  c3_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c3_info[44].fileTimeLo = 1187391744U;
  c3_info[44].fileTimeHi = 30108011U;
  c3_info[44].mFileTimeLo = 0U;
  c3_info[44].mFileTimeHi = 0U;
  c3_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c3_info[45].name = "eml_xcabs1";
  c3_info[45].dominantType = "double";
  c3_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c3_info[45].fileTimeLo = 467391744U;
  c3_info[45].fileTimeHi = 30108011U;
  c3_info[45].mFileTimeLo = 0U;
  c3_info[45].mFileTimeHi = 0U;
  c3_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c3_info[46].name = "eml_xswap";
  c3_info[46].dominantType = "int32";
  c3_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c3_info[46].fileTimeLo = 1447391744U;
  c3_info[46].fileTimeHi = 30108011U;
  c3_info[46].mFileTimeLo = 0U;
  c3_info[46].mFileTimeHi = 0U;
  c3_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c3_info[47].name = "eml_refblas_xswap";
  c3_info[47].dominantType = "int32";
  c3_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c3_info[47].fileTimeLo = 1567391744U;
  c3_info[47].fileTimeHi = 30108011U;
  c3_info[47].mFileTimeLo = 0U;
  c3_info[47].mFileTimeHi = 0U;
  c3_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c3_info[48].name = "eml_xgeru";
  c3_info[48].dominantType = "int32";
  c3_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c3_info[48].fileTimeLo = 527391744U;
  c3_info[48].fileTimeHi = 30108011U;
  c3_info[48].mFileTimeLo = 0U;
  c3_info[48].mFileTimeHi = 0U;
  c3_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c3_info[49].name = "eml_xger";
  c3_info[49].dominantType = "int32";
  c3_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c3_info[49].fileTimeLo = 507391744U;
  c3_info[49].fileTimeHi = 30108011U;
  c3_info[49].mFileTimeLo = 0U;
  c3_info[49].mFileTimeHi = 0U;
  c3_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c3_info[50].name = "eml_refblas_xger";
  c3_info[50].dominantType = "int32";
  c3_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c3_info[50].fileTimeLo = 1227391744U;
  c3_info[50].fileTimeHi = 30108011U;
  c3_info[50].mFileTimeLo = 0U;
  c3_info[50].mFileTimeHi = 0U;
  c3_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c3_info[51].name = "eml_refblas_xgerx";
  c3_info[51].dominantType = "int32";
  c3_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c3_info[51].fileTimeLo = 1267391744U;
  c3_info[51].fileTimeHi = 30108011U;
  c3_info[51].mFileTimeLo = 0U;
  c3_info[51].mFileTimeHi = 0U;
  c3_info[52].context = "";
  c3_info[52].name = "eye";
  c3_info[52].dominantType = "double";
  c3_info[52].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c3_info[52].fileTimeLo = 287391744U;
  c3_info[52].fileTimeHi = 30108011U;
  c3_info[52].mFileTimeLo = 0U;
  c3_info[52].mFileTimeHi = 0U;
  c3_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[53].name = "eml_assert_valid_size_arg";
  c3_info[53].dominantType = "double";
  c3_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c3_info[53].fileTimeLo = 347391744U;
  c3_info[53].fileTimeHi = 30108011U;
  c3_info[53].mFileTimeLo = 0U;
  c3_info[53].mFileTimeHi = 0U;
  c3_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c3_info[54].name = "isinf";
  c3_info[54].dominantType = "double";
  c3_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c3_info[54].fileTimeLo = 1007391744U;
  c3_info[54].fileTimeHi = 30108011U;
  c3_info[54].mFileTimeLo = 0U;
  c3_info[54].mFileTimeHi = 0U;
  c3_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[55].name = "mldivide";
  c3_info[55].dominantType = "double";
  c3_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c3_info[55].fileTimeLo = 2117098240U;
  c3_info[55].fileTimeHi = 30130935U;
  c3_info[55].mFileTimeLo = 3553034496U;
  c3_info[55].mFileTimeHi = 30114299U;
  c3_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c3_info[56].name = "eml_lusolve";
  c3_info[56].dominantType = "double";
  c3_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c3_info[56].fileTimeLo = 1267391744U;
  c3_info[56].fileTimeHi = 30108011U;
  c3_info[56].mFileTimeLo = 0U;
  c3_info[56].mFileTimeHi = 0U;
  c3_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c3_info[57].name = "eml_warning";
  c3_info[57].dominantType = "char";
  c3_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c3_info[57].fileTimeLo = 1427391744U;
  c3_info[57].fileTimeHi = 30108011U;
  c3_info[57].mFileTimeLo = 0U;
  c3_info[57].mFileTimeHi = 0U;
  c3_info[58].context = "";
  c3_info[58].name = "diag";
  c3_info[58].dominantType = "double";
  c3_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  c3_info[58].fileTimeLo = 267391744U;
  c3_info[58].fileTimeHi = 30108011U;
  c3_info[58].mFileTimeLo = 0U;
  c3_info[58].mFileTimeHi = 0U;
  c3_info[59].context = "";
  c3_info[59].name = "sum";
  c3_info[59].dominantType = "double";
  c3_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[59].fileTimeLo = 407391744U;
  c3_info[59].fileTimeHi = 30108011U;
  c3_info[59].mFileTimeLo = 0U;
  c3_info[59].mFileTimeHi = 0U;
  c3_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[60].name = "eml_const_nonsingleton_dim";
  c3_info[60].dominantType = "double";
  c3_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c3_info[60].fileTimeLo = 367391744U;
  c3_info[60].fileTimeHi = 30108011U;
  c3_info[60].mFileTimeLo = 0U;
  c3_info[60].mFileTimeHi = 0U;
  c3_info[61].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[61].name = "eml_xgemm";
  c3_info[61].dominantType = "int32";
  c3_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[61].fileTimeLo = 507391744U;
  c3_info[61].fileTimeHi = 30108011U;
  c3_info[61].mFileTimeLo = 0U;
  c3_info[61].mFileTimeHi = 0U;
  c3_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c3_info[62].name = "length";
  c3_info[62].dominantType = "double";
  c3_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c3_info[62].fileTimeLo = 1007391744U;
  c3_info[62].fileTimeHi = 30108011U;
  c3_info[62].mFileTimeLo = 0U;
  c3_info[62].mFileTimeHi = 0U;
  c3_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[63].name = "eml_refblas_xgemm";
  c3_info[63].dominantType = "int32";
  c3_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[63].fileTimeLo = 1227391744U;
  c3_info[63].fileTimeHi = 30108011U;
  c3_info[63].mFileTimeLo = 0U;
  c3_info[63].mFileTimeHi = 0U;
}

static real_T c3_norm(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_x[3])
{
  int32_T c3_i157;
  real_T c3_b_x[3];
  for (c3_i157 = 0; c3_i157 < 3; c3_i157++) {
    c3_b_x[c3_i157] = c3_x[c3_i157];
  }

  return c3_ceval_xnrm2(chartInstance, 3, c3_b_x, 1, 1);
}

static real_T c3_ceval_xnrm2(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_n, real_T c3_x[3], int32_T c3_ix0, int32_T c3_incx)
{
  return dnrm232(&c3_n, &c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c3_ix0), 1, 3, 1, 0) - 1], &c3_incx);
}

static real_T c3_mpower(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_a)
{
  return c3_power(chartInstance, c3_a, 2.0);
}

static real_T c3_power(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_a,
  real_T c3_b)
{
  real_T c3_ak;
  real_T c3_bk;
  real_T c3_x;
  real_T c3_b_x;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_a;
  c3_bk = c3_b;
  if (c3_ak < 0.0) {
    c3_x = c3_bk;
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarFloor(c3_b_x);
    if (c3_b_x != c3_bk) {
      c3_eml_error(chartInstance);
    }
  }

  return muDoubleScalarPower(c3_ak, c3_bk);
}

static void c3_eml_scalar_eg(SFc3_ekffedeInstanceStruct *chartInstance)
{
}

static void c3_eml_error(SFc3_ekffedeInstanceStruct *chartInstance)
{
  int32_T c3_i158;
  static char_T c3_varargin_1[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm',
    'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[31];
  const mxArray *c3_y = NULL;
  for (c3_i158 = 0; c3_i158 < 31; c3_i158++) {
    c3_u[c3_i158] = c3_varargin_1[c3_i158];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c3_y));
}

static real_T c3_dot(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_a[3],
                     real_T c3_b[3])
{
  int32_T c3_i159;
  real_T c3_b_a[3];
  int32_T c3_i160;
  real_T c3_b_b[3];
  c3_b_eml_scalar_eg(chartInstance);
  for (c3_i159 = 0; c3_i159 < 3; c3_i159++) {
    c3_b_a[c3_i159] = c3_a[c3_i159];
  }

  for (c3_i160 = 0; c3_i160 < 3; c3_i160++) {
    c3_b_b[c3_i160] = c3_b[c3_i160];
  }

  return c3_ceval_xdot(chartInstance, 3, c3_b_a, 1, 1, c3_b_b, 1, 1);
}

static void c3_b_eml_scalar_eg(SFc3_ekffedeInstanceStruct *chartInstance)
{
}

static real_T c3_ceval_xdot(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_n, real_T c3_x[3], int32_T c3_ix0, int32_T c3_incx, real_T c3_y[3], int32_T
  c3_iy0, int32_T c3_incy)
{
  real_T c3_d;
  c3_d = 0.0;
  if ((real_T)c3_n > 0.0) {
    c3_d = ddot32(&c3_n, &c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_ix0), 1, 3, 1, 0) - 1], &c3_incx,
                  &c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_iy0), 1, 3, 1, 0) - 1], &c3_incy);
  }

  return c3_d;
}

static void c3_cross(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_a[3],
                     real_T c3_b[3], real_T c3_c[3])
{
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_y;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_b_y;
  real_T c3_c1;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_c_y;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_d_y;
  real_T c3_c2;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_e_y;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_f_y;
  real_T c3_c3;
  c3_b_a = c3_a[1];
  c3_b_b = c3_b[2];
  c3_y = c3_b_a * c3_b_b;
  c3_c_a = c3_a[2];
  c3_c_b = c3_b[1];
  c3_b_y = c3_c_a * c3_c_b;
  c3_c1 = c3_y - c3_b_y;
  c3_d_a = c3_a[2];
  c3_d_b = c3_b[0];
  c3_c_y = c3_d_a * c3_d_b;
  c3_e_a = c3_a[0];
  c3_e_b = c3_b[2];
  c3_d_y = c3_e_a * c3_e_b;
  c3_c2 = c3_c_y - c3_d_y;
  c3_f_a = c3_a[0];
  c3_f_b = c3_b[1];
  c3_e_y = c3_f_a * c3_f_b;
  c3_g_a = c3_a[1];
  c3_g_b = c3_b[0];
  c3_f_y = c3_g_a * c3_g_b;
  c3_c3 = c3_e_y - c3_f_y;
  c3_c[0] = c3_c1;
  c3_c[1] = c3_c2;
  c3_c[2] = c3_c3;
}

static real_T c3_sqrt(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_sqrt(chartInstance, &c3_b_x);
  return c3_b_x;
}

static void c3_b_eml_error(SFc3_ekffedeInstanceStruct *chartInstance)
{
  int32_T c3_i161;
  static char_T c3_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  for (c3_i161 = 0; c3_i161 < 30; c3_i161++) {
    c3_u[c3_i161] = c3_varargin_1[c3_i161];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c3_y));
}

static real_T c3_det(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_x[9])
{
  real_T c3_y;
  int32_T c3_info;
  int32_T c3_ipiv[3];
  real_T c3_k;
  real_T c3_b_k;
  real_T c3_a;
  real_T c3_b;
  boolean_T c3_isodd;
  real_T c3_c_k;
  c3_b_eml_matlab_zgetrf(chartInstance, c3_x, c3_ipiv, &c3_info);
  c3_y = c3_x[0];
  for (c3_k = 2.0; c3_k <= 3.0; c3_k++) {
    c3_b_k = c3_k;
    c3_a = c3_y;
    c3_b = c3_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c3_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c3_b_k), 1, 3, 2, 0) - 1)) - 1];
    c3_y = c3_a * c3_b;
  }

  c3_isodd = FALSE;
  for (c3_c_k = 1.0; c3_c_k <= 2.0; c3_c_k++) {
    c3_b_k = c3_c_k;
    if ((real_T)c3_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
         _SFD_INTEGER_CHECK("", c3_b_k), 1, 3, 1, 0) - 1] > c3_b_k) {
      c3_isodd = !c3_isodd;
    }
  }

  if (c3_isodd) {
    c3_y = -c3_y;
  }

  return c3_y;
}

static void c3_eps(SFc3_ekffedeInstanceStruct *chartInstance)
{
}

static void c3_eml_matlab_zgetrf(SFc3_ekffedeInstanceStruct *chartInstance,
  real_T c3_A[9], real_T c3_b_A[9], int32_T c3_ipiv[3], int32_T *c3_info)
{
  int32_T c3_i162;
  for (c3_i162 = 0; c3_i162 < 9; c3_i162++) {
    c3_b_A[c3_i162] = c3_A[c3_i162];
  }

  c3_b_eml_matlab_zgetrf(chartInstance, c3_b_A, c3_ipiv, c3_info);
}

static int32_T c3_eml_ixamax(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_n, real_T c3_x[9], int32_T c3_ix0)
{
  int32_T c3_b_n;
  int32_T c3_b_ix0;
  int32_T c3_i163;
  real_T c3_b_x[9];
  c3_b_n = c3_n;
  c3_b_ix0 = c3_ix0;
  for (c3_i163 = 0; c3_i163 < 9; c3_i163++) {
    c3_b_x[c3_i163] = c3_x[c3_i163];
  }

  return c3_ceval_ixamax(chartInstance, c3_b_n, c3_b_x, c3_b_ix0, 1);
}

static int32_T c3_ceval_ixamax(SFc3_ekffedeInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[9], int32_T c3_ix0, int32_T c3_incx)
{
  return idamax32(&c3_n, &c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c3_ix0), 1, 9, 1, 0) - 1], &c3_incx);
}

static void c3_ceval_xswap(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_n, real_T c3_x[9], int32_T c3_ix0, int32_T c3_incx, int32_T c3_iy0, int32_T
  c3_incy, real_T c3_b_x[9])
{
  int32_T c3_i164;
  for (c3_i164 = 0; c3_i164 < 9; c3_i164++) {
    c3_b_x[c3_i164] = c3_x[c3_i164];
  }

  c3_b_ceval_xswap(chartInstance, c3_n, c3_b_x, c3_ix0, c3_incx, c3_iy0, c3_incy);
}

static void c3_ceval_xger(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_m, int32_T c3_n, real_T c3_alpha1, int32_T c3_ix0, int32_T c3_incx, int32_T
  c3_iy0, int32_T c3_incy, real_T c3_A[9], int32_T c3_ia0, int32_T c3_lda,
  real_T c3_b_A[9])
{
  int32_T c3_i165;
  for (c3_i165 = 0; c3_i165 < 9; c3_i165++) {
    c3_b_A[c3_i165] = c3_A[c3_i165];
  }

  c3_b_ceval_xger(chartInstance, c3_m, c3_n, c3_alpha1, c3_ix0, c3_incx, c3_iy0,
                  c3_incy, c3_b_A, c3_ia0, c3_lda);
}

static void c3_mrdivide(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_A[9],
  real_T c3_B[9], real_T c3_y[9])
{
  int32_T c3_i166;
  int32_T c3_i167;
  int32_T c3_i168;
  int32_T c3_i169;
  real_T c3_b_A[9];
  int32_T c3_i170;
  int32_T c3_i171;
  int32_T c3_i172;
  int32_T c3_i173;
  real_T c3_b_B[9];
  int32_T c3_r1;
  int32_T c3_r2;
  int32_T c3_r3;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_b_y;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_c_y;
  real_T c3_maxval;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_d_y;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_e_y;
  real_T c3_a21;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_m_x;
  real_T c3_f_y;
  real_T c3_n_x;
  real_T c3_o_x;
  real_T c3_g_y;
  real_T c3_d;
  real_T c3_p_x;
  real_T c3_h_y;
  real_T c3_q_x;
  real_T c3_i_y;
  real_T c3_z;
  real_T c3_r_x;
  real_T c3_j_y;
  real_T c3_s_x;
  real_T c3_k_y;
  real_T c3_b_z;
  real_T c3_a;
  real_T c3_b;
  real_T c3_l_y;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_m_y;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_n_y;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_o_y;
  real_T c3_t_x;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_p_y;
  real_T c3_w_x;
  real_T c3_x_x;
  real_T c3_q_y;
  real_T c3_b_d;
  real_T c3_y_x;
  real_T c3_ab_x;
  real_T c3_bb_x;
  real_T c3_r_y;
  real_T c3_cb_x;
  real_T c3_db_x;
  real_T c3_s_y;
  real_T c3_c_d;
  int32_T c3_rtemp;
  real_T c3_eb_x;
  real_T c3_t_y;
  real_T c3_fb_x;
  real_T c3_u_y;
  real_T c3_c_z;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_v_y;
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_Y[9];
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_w_y;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_x_y;
  real_T c3_h_a;
  real_T c3_h_b;
  real_T c3_y_y;
  real_T c3_gb_x;
  real_T c3_ab_y;
  real_T c3_hb_x;
  real_T c3_bb_y;
  real_T c3_d_z;
  real_T c3_i_a;
  real_T c3_i_b;
  real_T c3_cb_y;
  real_T c3_j_a;
  real_T c3_j_b;
  real_T c3_db_y;
  real_T c3_ib_x;
  real_T c3_eb_y;
  real_T c3_jb_x;
  real_T c3_fb_y;
  real_T c3_e_z;
  real_T c3_k_a;
  real_T c3_k_b;
  real_T c3_gb_y;
  real_T c3_kb_x;
  real_T c3_hb_y;
  real_T c3_lb_x;
  real_T c3_ib_y;
  real_T c3_f_z;
  int32_T c3_i174;
  int32_T c3_i175;
  int32_T c3_i176;
  int32_T c3_i177;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c3_i166 = 0;
  for (c3_i167 = 0; c3_i167 < 3; c3_i167++) {
    c3_i168 = 0;
    for (c3_i169 = 0; c3_i169 < 3; c3_i169++) {
      c3_b_A[c3_i169 + c3_i166] = c3_B[c3_i168 + c3_i167];
      c3_i168 += 3;
    }

    c3_i166 += 3;
  }

  c3_i170 = 0;
  for (c3_i171 = 0; c3_i171 < 3; c3_i171++) {
    c3_i172 = 0;
    for (c3_i173 = 0; c3_i173 < 3; c3_i173++) {
      c3_b_B[c3_i173 + c3_i170] = c3_A[c3_i172 + c3_i171];
      c3_i172 += 3;
    }

    c3_i170 += 3;
  }

  c3_r1 = 1;
  c3_r2 = 2;
  c3_r3 = 3;
  c3_x = c3_b_A[0];
  c3_b_x = c3_x;
  c3_c_x = c3_b_x;
  c3_b_y = muDoubleScalarAbs(c3_c_x);
  c3_d_x = 0.0;
  c3_e_x = c3_d_x;
  c3_c_y = muDoubleScalarAbs(c3_e_x);
  c3_maxval = c3_b_y + c3_c_y;
  c3_f_x = c3_b_A[1];
  c3_g_x = c3_f_x;
  c3_h_x = c3_g_x;
  c3_d_y = muDoubleScalarAbs(c3_h_x);
  c3_i_x = 0.0;
  c3_j_x = c3_i_x;
  c3_e_y = muDoubleScalarAbs(c3_j_x);
  c3_a21 = c3_d_y + c3_e_y;
  if (c3_a21 > c3_maxval) {
    c3_maxval = c3_a21;
    c3_r1 = 2;
    c3_r2 = 1;
  }

  c3_k_x = c3_b_A[2];
  c3_l_x = c3_k_x;
  c3_m_x = c3_l_x;
  c3_f_y = muDoubleScalarAbs(c3_m_x);
  c3_n_x = 0.0;
  c3_o_x = c3_n_x;
  c3_g_y = muDoubleScalarAbs(c3_o_x);
  c3_d = c3_f_y + c3_g_y;
  if (c3_d > c3_maxval) {
    c3_r1 = 3;
    c3_r2 = 2;
    c3_r3 = 1;
  }

  c3_p_x = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) - 1];
  c3_h_y = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) - 1];
  c3_q_x = c3_p_x;
  c3_i_y = c3_h_y;
  c3_z = c3_q_x / c3_i_y;
  c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r2), 1, 3, 1, 0) - 1] = c3_z;
  c3_r_x = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r3), 1, 3, 1, 0) - 1];
  c3_j_y = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) - 1];
  c3_s_x = c3_r_x;
  c3_k_y = c3_j_y;
  c3_b_z = c3_s_x / c3_k_y;
  c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) - 1] = c3_b_z;
  c3_a = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) - 1];
  c3_b = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) + 2];
  c3_l_y = c3_a * c3_b;
  c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r2), 1, 3, 1, 0) + 2] = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c3_r2), 1, 3, 1, 0) + 2] - c3_l_y;
  c3_b_a = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r3), 1, 3, 1, 0) - 1];
  c3_b_b = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) + 2];
  c3_m_y = c3_b_a * c3_b_b;
  c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) + 2] = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c3_r3), 1, 3, 1, 0) + 2] - c3_m_y;
  c3_c_a = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) - 1];
  c3_c_b = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) + 5];
  c3_n_y = c3_c_a * c3_c_b;
  c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r2), 1, 3, 1, 0) + 5] = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c3_r2), 1, 3, 1, 0) + 5] - c3_n_y;
  c3_d_a = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r3), 1, 3, 1, 0) - 1];
  c3_d_b = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) + 5];
  c3_o_y = c3_d_a * c3_d_b;
  c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) + 5] = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c3_r3), 1, 3, 1, 0) + 5] - c3_o_y;
  c3_t_x = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r3), 1, 3, 1, 0) + 2];
  c3_u_x = c3_t_x;
  c3_v_x = c3_u_x;
  c3_p_y = muDoubleScalarAbs(c3_v_x);
  c3_w_x = 0.0;
  c3_x_x = c3_w_x;
  c3_q_y = muDoubleScalarAbs(c3_x_x);
  c3_b_d = c3_p_y + c3_q_y;
  c3_y_x = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) + 2];
  c3_ab_x = c3_y_x;
  c3_bb_x = c3_ab_x;
  c3_r_y = muDoubleScalarAbs(c3_bb_x);
  c3_cb_x = 0.0;
  c3_db_x = c3_cb_x;
  c3_s_y = muDoubleScalarAbs(c3_db_x);
  c3_c_d = c3_r_y + c3_s_y;
  if (c3_b_d > c3_c_d) {
    c3_rtemp = c3_r2;
    c3_r2 = c3_r3;
    c3_r3 = c3_rtemp;
  }

  c3_eb_x = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c3_r3), 1, 3, 1, 0) + 2];
  c3_t_y = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) + 2];
  c3_fb_x = c3_eb_x;
  c3_u_y = c3_t_y;
  c3_c_z = c3_fb_x / c3_u_y;
  c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) + 2] = c3_c_z;
  c3_e_a = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r3), 1, 3, 1, 0) + 2];
  c3_e_b = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) + 5];
  c3_v_y = c3_e_a * c3_e_b;
  c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) + 5] = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c3_r3), 1, 3, 1, 0) + 5] - c3_v_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c3_r1), 1, 3, 1, 0) - 1] == 0.0) {
    guard2 = TRUE;
  } else if (c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
               "", (real_T)c3_r2), 1, 3, 1, 0) + 2] == 0.0) {
    guard2 = TRUE;
  } else {
    if (c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_r3), 1, 3, 1, 0) + 5] == 0.0) {
      guard1 = TRUE;
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c3_eml_warning(chartInstance);
  }

  c3_c_eml_scalar_eg(chartInstance);
  for (c3_k = 1; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c3_b_k), 1, 3, 2, 0) - 1)] = c3_b_B
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c3_r1), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)) - 1];
    c3_f_a = c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)];
    c3_f_b = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r2), 1, 3, 1, 0) - 1];
    c3_w_y = c3_f_a * c3_f_b;
    c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c3_b_k), 1, 3, 2, 0) - 1)] = c3_b_B
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c3_r2), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)) - 1] -
      c3_w_y;
    c3_g_a = c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)];
    c3_g_b = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r3), 1, 3, 1, 0) - 1];
    c3_x_y = c3_g_a * c3_g_b;
    c3_h_a = c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)];
    c3_h_b = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r3), 1, 3, 1, 0) + 2];
    c3_y_y = c3_h_a * c3_h_b;
    c3_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c3_b_k), 1, 3, 2, 0) - 1)] = (c3_b_B
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c3_r3), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)) - 1] - c3_x_y) -
      c3_y_y;
    c3_gb_x = c3_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)];
    c3_ab_y = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c3_r3), 1, 3, 1, 0) + 5];
    c3_hb_x = c3_gb_x;
    c3_bb_y = c3_ab_y;
    c3_d_z = c3_hb_x / c3_bb_y;
    c3_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c3_b_k), 1, 3, 2, 0) - 1)] = c3_d_z;
    c3_i_a = c3_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)];
    c3_i_b = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r1), 1, 3, 1, 0) + 5];
    c3_cb_y = c3_i_a * c3_i_b;
    c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c3_b_k), 1, 3, 2, 0) - 1)] = c3_Y[3 *
      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
         c3_b_k), 1, 3, 2, 0) - 1)] - c3_cb_y;
    c3_j_a = c3_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)];
    c3_j_b = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r2), 1, 3, 1, 0) + 5];
    c3_db_y = c3_j_a * c3_j_b;
    c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c3_b_k), 1, 3, 2, 0) - 1)] = c3_Y[1 + 3 *
      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
         c3_b_k), 1, 3, 2, 0) - 1)] - c3_db_y;
    c3_ib_x = c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)];
    c3_eb_y = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c3_r2), 1, 3, 1, 0) + 2];
    c3_jb_x = c3_ib_x;
    c3_fb_y = c3_eb_y;
    c3_e_z = c3_jb_x / c3_fb_y;
    c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c3_b_k), 1, 3, 2, 0) - 1)] = c3_e_z;
    c3_k_a = c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)];
    c3_k_b = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r1), 1, 3, 1, 0) + 2];
    c3_gb_y = c3_k_a * c3_k_b;
    c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c3_b_k), 1, 3, 2, 0) - 1)] = c3_Y[3 *
      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
         c3_b_k), 1, 3, 2, 0) - 1)] - c3_gb_y;
    c3_kb_x = c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1)];
    c3_hb_y = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c3_r1), 1, 3, 1, 0) - 1];
    c3_lb_x = c3_kb_x;
    c3_ib_y = c3_hb_y;
    c3_f_z = c3_lb_x / c3_ib_y;
    c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c3_b_k), 1, 3, 2, 0) - 1)] = c3_f_z;
  }

  c3_i174 = 0;
  for (c3_i175 = 0; c3_i175 < 3; c3_i175++) {
    c3_i176 = 0;
    for (c3_i177 = 0; c3_i177 < 3; c3_i177++) {
      c3_y[c3_i177 + c3_i174] = c3_Y[c3_i176 + c3_i175];
      c3_i176 += 3;
    }

    c3_i174 += 3;
  }
}

static void c3_eml_warning(SFc3_ekffedeInstanceStruct *chartInstance)
{
  int32_T c3_i178;
  static char_T c3_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c3_u[27];
  const mxArray *c3_y = NULL;
  for (c3_i178 = 0; c3_i178 < 27; c3_i178++) {
    c3_u[c3_i178] = c3_varargin_1[c3_i178];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 27));
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c3_y));
}

static void c3_c_eml_scalar_eg(SFc3_ekffedeInstanceStruct *chartInstance)
{
}

static void c3_diag(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_v[9],
                    real_T c3_d[3])
{
  int32_T c3_i179;
  int32_T c3_i180;
  c3_i179 = 0;
  for (c3_i180 = 0; c3_i180 < 3; c3_i180++) {
    c3_d[c3_i180] = c3_v[c3_i179];
    c3_i179 += 4;
  }
}

static real_T c3_sum(SFc3_ekffedeInstanceStruct *chartInstance, real_T c3_x[3])
{
  real_T c3_y;
  int32_T c3_k;
  int32_T c3_b_k;
  c3_y = c3_x[0];
  for (c3_k = 2; c3_k < 4; c3_k++) {
    c3_b_k = c3_k;
    c3_y += c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c3_b_k), 1, 3, 1, 0) - 1];
  }

  return c3_y;
}

static void c3_d_eml_scalar_eg(SFc3_ekffedeInstanceStruct *chartInstance)
{
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc3_ekffedeInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static int32_T c3_g_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i181;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i181, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i181;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc3_ekffedeInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_ekffede, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_ekffede), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_ekffede);
  return c3_y;
}

static uint8_T c3_i_emlrt_marshallIn(SFc3_ekffedeInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sqrt(SFc3_ekffedeInstanceStruct *chartInstance, real_T *c3_x)
{
  if (*c3_x < 0.0) {
    c3_b_eml_error(chartInstance);
  }

  *c3_x = muDoubleScalarSqrt(*c3_x);
}

static void c3_b_eml_matlab_zgetrf(SFc3_ekffedeInstanceStruct *chartInstance,
  real_T c3_A[9], int32_T c3_ipiv[3], int32_T *c3_info)
{
  int32_T c3_i182;
  int32_T c3_j;
  int32_T c3_b_j;
  int32_T c3_a;
  int32_T c3_jm1;
  int32_T c3_b;
  int32_T c3_mmj;
  int32_T c3_b_a;
  int32_T c3_c;
  int32_T c3_b_b;
  int32_T c3_jj;
  int32_T c3_c_a;
  int32_T c3_jp1j;
  int32_T c3_d_a;
  int32_T c3_b_c;
  int32_T c3_i183;
  int32_T c3_i184;
  int32_T c3_i185;
  real_T c3_b_A[9];
  int32_T c3_e_a;
  int32_T c3_jpiv_offset;
  int32_T c3_f_a;
  int32_T c3_c_b;
  int32_T c3_jpiv;
  int32_T c3_g_a;
  int32_T c3_d_b;
  int32_T c3_c_c;
  int32_T c3_e_b;
  int32_T c3_jrow;
  int32_T c3_h_a;
  int32_T c3_f_b;
  int32_T c3_jprow;
  int32_T c3_ix0;
  int32_T c3_iy0;
  int32_T c3_b_ix0;
  int32_T c3_b_iy0;
  int32_T c3_b_jp1j;
  int32_T c3_i_a;
  int32_T c3_d_c;
  int32_T c3_j_a;
  int32_T c3_g_b;
  int32_T c3_loop_ub;
  int32_T c3_i;
  int32_T c3_b_i;
  real_T c3_x;
  real_T c3_y;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_z;
  int32_T c3_h_b;
  int32_T c3_e_c;
  int32_T c3_k_a;
  int32_T c3_f_c;
  int32_T c3_l_a;
  int32_T c3_g_c;
  int32_T c3_m;
  int32_T c3_n;
  int32_T c3_c_ix0;
  int32_T c3_c_iy0;
  int32_T c3_ia0;
  int32_T c3_b_m;
  int32_T c3_b_n;
  int32_T c3_d_ix0;
  int32_T c3_d_iy0;
  int32_T c3_b_ia0;
  int32_T c3_c_m;
  int32_T c3_c_n;
  int32_T c3_e_ix0;
  int32_T c3_e_iy0;
  int32_T c3_c_ia0;
  c3_eps(chartInstance);
  for (c3_i182 = 0; c3_i182 < 3; c3_i182++) {
    c3_ipiv[c3_i182] = 1 + c3_i182;
  }

  *c3_info = 0;
  for (c3_j = 1; c3_j < 3; c3_j++) {
    c3_b_j = c3_j;
    c3_a = c3_b_j - 1;
    c3_jm1 = c3_a;
    c3_b = c3_b_j - 3;
    c3_mmj = -c3_b;
    c3_b_a = c3_jm1;
    c3_c = c3_b_a << 2;
    c3_b_b = c3_c + 1;
    c3_jj = c3_b_b;
    c3_c_a = c3_jj + 1;
    c3_jp1j = c3_c_a;
    c3_d_a = c3_mmj;
    c3_b_c = c3_d_a;
    c3_i183 = 0;
    for (c3_i184 = 0; c3_i184 < 3; c3_i184++) {
      for (c3_i185 = 0; c3_i185 < 3; c3_i185++) {
        c3_b_A[c3_i185 + c3_i183] = c3_A[c3_i185 + c3_i183];
      }

      c3_i183 += 3;
    }

    c3_e_a = c3_eml_ixamax(chartInstance, c3_b_c + 1, c3_b_A, c3_jj) - 1;
    c3_jpiv_offset = c3_e_a;
    c3_f_a = c3_jj;
    c3_c_b = c3_jpiv_offset;
    c3_jpiv = c3_f_a + c3_c_b;
    if (c3_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_jpiv), 1, 9, 1, 0) - 1] != 0.0) {
      if ((real_T)c3_jpiv_offset != 0.0) {
        c3_g_a = c3_b_j;
        c3_d_b = c3_jpiv_offset;
        c3_c_c = c3_g_a + c3_d_b;
        c3_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_b_j), 1, 3, 1, 0) - 1] = c3_c_c;
        c3_e_b = c3_jm1 + 1;
        c3_jrow = c3_e_b;
        c3_h_a = c3_jrow;
        c3_f_b = c3_jpiv_offset;
        c3_jprow = c3_h_a + c3_f_b;
        c3_ix0 = c3_jrow;
        c3_iy0 = c3_jprow;
        c3_b_ix0 = c3_ix0;
        c3_b_iy0 = c3_iy0;
        c3_b_ceval_xswap(chartInstance, 3, c3_A, c3_b_ix0, 3, c3_b_iy0, 3);
      }

      c3_b_jp1j = c3_jp1j;
      c3_i_a = c3_mmj;
      c3_d_c = c3_i_a;
      c3_j_a = c3_jp1j;
      c3_g_b = c3_d_c;
      c3_loop_ub = (c3_j_a + c3_g_b) - 1;
      for (c3_i = c3_b_jp1j; c3_i <= c3_loop_ub; c3_i++) {
        c3_b_i = c3_i;
        c3_x = c3_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c3_b_i), 1, 9, 1, 0) - 1];
        c3_y = c3_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c3_jj), 1, 9, 1, 0) - 1];
        c3_b_x = c3_x;
        c3_b_y = c3_y;
        c3_z = c3_b_x / c3_b_y;
        c3_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_b_i), 1, 9, 1, 0) - 1] = c3_z;
      }
    } else {
      *c3_info = c3_b_j;
    }

    c3_h_b = c3_b_j;
    c3_e_c = -c3_h_b;
    c3_k_a = c3_jj;
    c3_f_c = c3_k_a;
    c3_l_a = c3_jj;
    c3_g_c = c3_l_a;
    c3_m = c3_mmj;
    c3_n = c3_e_c;
    c3_c_ix0 = c3_jp1j;
    c3_c_iy0 = c3_f_c;
    c3_ia0 = c3_g_c;
    c3_b_m = c3_m;
    c3_b_n = c3_n;
    c3_d_ix0 = c3_c_ix0;
    c3_d_iy0 = c3_c_iy0;
    c3_b_ia0 = c3_ia0;
    c3_c_m = c3_b_m;
    c3_c_n = c3_b_n + 3;
    c3_e_ix0 = c3_d_ix0;
    c3_e_iy0 = c3_d_iy0;
    c3_c_ia0 = c3_b_ia0;
    if ((real_T)c3_c_m < 1.0) {
    } else if ((real_T)c3_c_n < 1.0) {
    } else {
      c3_b_ceval_xger(chartInstance, c3_c_m, c3_c_n, -1.0, c3_e_ix0, 1, c3_e_iy0
                      + 3, 3, c3_A, c3_c_ia0 + 4, 3);
    }
  }

  if ((real_T)*c3_info == 0.0) {
    if (!(c3_A[8] != 0.0)) {
      *c3_info = 3;
    }
  }
}

static void c3_b_ceval_xswap(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_n, real_T c3_x[9], int32_T c3_ix0, int32_T c3_incx, int32_T c3_iy0, int32_T
  c3_incy)
{
  dswap32(&c3_n, &c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c3_ix0), 1, 9, 1, 0) - 1], &c3_incx,
          &c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c3_iy0), 1, 9, 1, 0) - 1], &c3_incy);
}

static void c3_b_ceval_xger(SFc3_ekffedeInstanceStruct *chartInstance, int32_T
  c3_m, int32_T c3_n, real_T c3_alpha1, int32_T c3_ix0, int32_T c3_incx, int32_T
  c3_iy0, int32_T c3_incy, real_T c3_A[9], int32_T c3_ia0, int32_T c3_lda)
{
  dger32(&c3_m, &c3_n, &c3_alpha1, &c3_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c3_ix0), 1, 9, 1, 0) - 1],
         &c3_incx, &c3_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c3_iy0), 1, 9, 1, 0) - 1], &c3_incy,
         &c3_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
           (real_T)c3_ia0), 1, 9, 1, 0) - 1], &c3_lda);
}

static void init_dsm_address_info(SFc3_ekffedeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_ekffede_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4285262098U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3316175240U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1026366793U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1506970096U);
}

mxArray *sf_c3_ekffede_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2903184435U);
    pr[1] = (double)(1080445040U);
    pr[2] = (double)(3759518432U);
    pr[3] = (double)(388917781U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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

static const mxArray *sf_get_sim_state_info_c3_ekffede(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[11],T\"PQQ\",},{M[1],M[5],T\"q_opt\",},{M[8],M[0],T\"is_active_c3_ekffede\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_ekffede_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ekffedeInstanceStruct *chartInstance;
    chartInstance = (SFc3_ekffedeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_ekffedeMachineNumber_,
          3,
          1,
          1,
          8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"V1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"q_opt");
          _SFD_SET_DATA_PROPS(2,1,1,0,"V2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"W1");
          _SFD_SET_DATA_PROPS(4,1,1,0,"W2");
          _SFD_SET_DATA_PROPS(5,2,0,1,"PQQ");
          _SFD_SET_DATA_PROPS(6,1,1,0,"sig_acc");
          _SFD_SET_DATA_PROPS(7,1,1,0,"sig_m");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,876);
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
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_sig_acc;
          real_T *c3_sig_m;
          real_T (*c3_V1)[3];
          real_T (*c3_q_opt)[4];
          real_T (*c3_V2)[3];
          real_T (*c3_W1)[3];
          real_T (*c3_W2)[3];
          real_T (*c3_PQQ)[9];
          c3_sig_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_sig_acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_PQQ = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c3_W2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c3_W1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c3_V2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c3_q_opt = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_V1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_V1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_q_opt);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_V2);
          _SFD_SET_DATA_VALUE_PTR(3U, *c3_W1);
          _SFD_SET_DATA_VALUE_PTR(4U, *c3_W2);
          _SFD_SET_DATA_VALUE_PTR(5U, *c3_PQQ);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_sig_acc);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_sig_m);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ekffedeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c3_ekffede(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_ekffedeInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c3_ekffede((SFc3_ekffedeInstanceStruct*) chartInstanceVar);
  initialize_c3_ekffede((SFc3_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_ekffede(void *chartInstanceVar)
{
  enable_c3_ekffede((SFc3_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_ekffede(void *chartInstanceVar)
{
  disable_c3_ekffede((SFc3_ekffedeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_ekffede(void *chartInstanceVar)
{
  sf_c3_ekffede((SFc3_ekffedeInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_ekffede(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_ekffede((SFc3_ekffedeInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_ekffede();/* state var info */
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

extern void sf_internal_set_sim_state_c3_ekffede(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_ekffede();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_ekffede((SFc3_ekffedeInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_ekffede(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_ekffede(S);
}

static void sf_opaque_set_sim_state_c3_ekffede(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_ekffede(S, st);
}

static void sf_opaque_terminate_c3_ekffede(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ekffedeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_ekffede((SFc3_ekffedeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_ekffede((SFc3_ekffedeInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_ekffede(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_ekffede((SFc3_ekffedeInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_ekffede(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ekffede","ekffede",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ekffede","ekffede",3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ekffede","ekffede",3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ekffede","ekffede",3,6);
      sf_mark_chart_reusable_outputs(S,"ekffede","ekffede",3,2);
    }

    sf_set_rtw_dwork_info(S,"ekffede","ekffede",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2967318253U));
  ssSetChecksum1(S,(2540967073U));
  ssSetChecksum2(S,(766197214U));
  ssSetChecksum3(S,(1394406695U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_ekffede(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ekffede", "ekffede",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_ekffede(SimStruct *S)
{
  SFc3_ekffedeInstanceStruct *chartInstance;
  chartInstance = (SFc3_ekffedeInstanceStruct *)malloc(sizeof
    (SFc3_ekffedeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_ekffedeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_ekffede;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_ekffede;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_ekffede;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_ekffede;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_ekffede;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_ekffede;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_ekffede;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_ekffede;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_ekffede;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_ekffede;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_ekffede;
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

void c3_ekffede_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_ekffede(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_ekffede(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_ekffede(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_ekffede_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
