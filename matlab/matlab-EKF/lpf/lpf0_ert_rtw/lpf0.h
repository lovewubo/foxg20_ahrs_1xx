/*
 * File: lpf0.h
 *
 * Code generated for Simulink model 'lpf0'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Tue Nov 01 12:44:21 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_lpf0_h_
#define RTW_HEADER_lpf0_h_
#ifndef lpf0_COMMON_INCLUDES_
# define lpf0_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* lpf0_COMMON_INCLUDES_ */

#include "lpf0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Gain1;                        /* '<S1>/Gain1' */
  real_T Gain2;                        /* '<S1>/Gain2' */
  real_T Stage2;                       /* '<S19>/Stage2' */
  real_T Stage1;                       /* '<S19>/Stage1' */
} BlockIO_lpf0;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Stage1_FILT_STATES[7];        /* '<S11>/Stage1' */
  real_T Stage2_FILT_STATES[40];       /* '<S11>/Stage2' */
  real_T Stage1_FILT_STATES_f[7];      /* '<S12>/Stage1' */
  real_T Stage2_FILT_STATES_b[40];     /* '<S12>/Stage2' */
  real_T Stage1_FILT_STATES_c[7];      /* '<S13>/Stage1' */
  real_T Stage2_FILT_STATES_a[40];     /* '<S13>/Stage2' */
  real_T Stage1_FILT_STATES_g[7];      /* '<S14>/Stage1' */
  real_T Stage2_FILT_STATES_d[40];     /* '<S14>/Stage2' */
  real_T Stage1_FILT_STATES_f1[7];     /* '<S15>/Stage1' */
  real_T Stage2_FILT_STATES_m[40];     /* '<S15>/Stage2' */
  real_T Stage1_FILT_STATES_o[7];      /* '<S16>/Stage1' */
  real_T Stage2_FILT_STATES_k[40];     /* '<S16>/Stage2' */
  real_T Stage1_FILT_STATES_a[6];      /* '<S17>/Stage1' */
  real_T Stage2_FILT_STATES_h[29];     /* '<S17>/Stage2' */
  real_T Stage1_FILT_STATES_d[6];      /* '<S18>/Stage1' */
  real_T Stage2_FILT_STATES_ao[29];    /* '<S18>/Stage2' */
  real_T Stage1_FILT_STATES_n[6];      /* '<S19>/Stage1' */
  real_T Stage2_FILT_STATES_f[29];     /* '<S19>/Stage2' */
  real_T Memory_PreviousInput;         /* '<S1>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S1>/Memory1' */
  real_T Memory2_PreviousInput;        /* '<S1>/Memory2' */
  real_T Memory3_PreviousInput;        /* '<S1>/Memory3' */
  real_T Memory4_PreviousInput;        /* '<S1>/Memory4' */
  real_T Memory5_PreviousInput;        /* '<S1>/Memory5' */
  real_T Memory6_PreviousInput;        /* '<S1>/Memory6' */
  real_T Memory8_PreviousInput;        /* '<S1>/Memory8' */
  real_T Memory7_PreviousInput;        /* '<S1>/Memory7' */
  real_T Memory9_PreviousInput;        /* '<S1>/Memory9' */
  real_T Memory10_PreviousInput;       /* '<S1>/Memory10' */
  real_T Memory11_PreviousInput;       /* '<S1>/Memory11' */
  real_T Memory12_PreviousInput;       /* '<S1>/Memory12' */
  real_T Memory13_PreviousInput;       /* '<S1>/Memory13' */
  real_T Memory14_PreviousInput;       /* '<S1>/Memory14' */
  real_T Memory15_PreviousInput;       /* '<S1>/Memory15' */
  real_T Memory17_PreviousInput;       /* '<S1>/Memory17' */
  real_T Memory16_PreviousInput;       /* '<S1>/Memory16' */
  real_T Memory26_PreviousInput;       /* '<S1>/Memory26' */
  real_T Memory18_PreviousInput;       /* '<S1>/Memory18' */
  real_T Memory19_PreviousInput;       /* '<S1>/Memory19' */
  real_T Memory20_PreviousInput;       /* '<S1>/Memory20' */
  real_T Memory21_PreviousInput;       /* '<S1>/Memory21' */
  real_T Memory22_PreviousInput;       /* '<S1>/Memory22' */
  real_T Memory23_PreviousInput;       /* '<S1>/Memory23' */
  real_T Memory25_PreviousInput;       /* '<S1>/Memory25' */
  real_T Memory24_PreviousInput;       /* '<S1>/Memory24' */
  int32_T Stage1_CIRCBUFFIDX;          /* '<S11>/Stage1' */
  int32_T Stage2_CIRCBUFFIDX;          /* '<S11>/Stage2' */
  int32_T Stage1_CIRCBUFFIDX_n;        /* '<S12>/Stage1' */
  int32_T Stage2_CIRCBUFFIDX_m;        /* '<S12>/Stage2' */
  int32_T Stage1_CIRCBUFFIDX_g;        /* '<S13>/Stage1' */
  int32_T Stage2_CIRCBUFFIDX_c;        /* '<S13>/Stage2' */
  int32_T Stage1_CIRCBUFFIDX_d;        /* '<S14>/Stage1' */
  int32_T Stage2_CIRCBUFFIDX_p;        /* '<S14>/Stage2' */
  int32_T Stage1_CIRCBUFFIDX_d3;       /* '<S15>/Stage1' */
  int32_T Stage2_CIRCBUFFIDX_o;        /* '<S15>/Stage2' */
  int32_T Stage1_CIRCBUFFIDX_k;        /* '<S16>/Stage1' */
  int32_T Stage2_CIRCBUFFIDX_ov;       /* '<S16>/Stage2' */
  int32_T Stage1_CIRCBUFFIDX_c;        /* '<S17>/Stage1' */
  int32_T Stage2_CIRCBUFFIDX_mf;       /* '<S17>/Stage2' */
  int32_T Stage1_CIRCBUFFIDX_a;        /* '<S18>/Stage1' */
  int32_T Stage2_CIRCBUFFIDX_l;        /* '<S18>/Stage2' */
  int32_T Stage1_CIRCBUFFIDX_m;        /* '<S19>/Stage1' */
  int32_T Stage2_CIRCBUFFIDX_d;        /* '<S19>/Stage2' */
} D_Work_lpf0;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T acc_x;                        /* '<Root>/acc_x' */
  real_T acc_y;                        /* '<Root>/acc_y' */
  real_T acc_z;                        /* '<Root>/acc_z' */
  real_T gyro_x;                       /* '<Root>/gyro_x' */
  real_T gyro_y;                       /* '<Root>/gyro_y' */
  real_T gyro_z;                       /* '<Root>/gyro_z' */
  real_T mag_x;                        /* '<Root>/mag_x' */
  real_T mag_y;                        /* '<Root>/mag_y' */
  real_T mag_z;                        /* '<Root>/mag_z' */
} ExternalInputs_lpf0;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T acc_x_f;                      /* '<Root>/acc_x_f' */
  real_T acc_y_f;                      /* '<Root>/acc_y_f' */
  real_T acc_z_f;                      /* '<Root>/acc_z_f' */
  real_T gyro_x_f;                     /* '<Root>/gyro_x_f' */
  real_T gyro_y_f;                     /* '<Root>/gyro_y_f' */
  real_T gyro_z_f;                     /* '<Root>/gyro_z_f' */
  real_T mag_x_f;                      /* '<Root>/mag_x_f' */
  real_T mag_y_f;                      /* '<Root>/mag_y_f' */
  real_T mag_z_f;                      /* '<Root>/mag_z_f' */
} ExternalOutputs_lpf0;

/* Parameters (auto storage) */
struct Parameters_lpf0_ {
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory3'
                                        */
  real_T Memory4_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory4'
                                        */
  real_T Memory5_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory5'
                                        */
  real_T Memory6_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory6'
                                        */
  real_T Memory8_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory8'
                                        */
  real_T Memory7_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory7'
                                        */
  real_T Stage1_RTP1COEFF[7];          /* Expression: NumCoeffs
                                        * Referenced by: '<S11>/Stage1'
                                        */
  real_T Stage2_RTP1COEFF[40];         /* Expression: NumCoeffs
                                        * Referenced by: '<S11>/Stage2'
                                        */
  real_T Memory9_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory9'
                                        */
  real_T Memory10_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory10'
                                        */
  real_T Memory11_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory11'
                                        */
  real_T Memory12_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory12'
                                        */
  real_T Memory13_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory13'
                                        */
  real_T Memory14_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory14'
                                        */
  real_T Memory15_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory15'
                                        */
  real_T Memory17_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory17'
                                        */
  real_T Memory16_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory16'
                                        */
  real_T Stage1_RTP1COEFF_p[7];        /* Expression: NumCoeffs
                                        * Referenced by: '<S12>/Stage1'
                                        */
  real_T Stage2_RTP1COEFF_d[40];       /* Expression: NumCoeffs
                                        * Referenced by: '<S12>/Stage2'
                                        */
  real_T Memory26_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory26'
                                        */
  real_T Memory18_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory18'
                                        */
  real_T Memory19_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory19'
                                        */
  real_T Memory20_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory20'
                                        */
  real_T Memory21_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory21'
                                        */
  real_T Memory22_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory22'
                                        */
  real_T Memory23_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory23'
                                        */
  real_T Memory25_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory25'
                                        */
  real_T Memory24_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory24'
                                        */
  real_T Stage1_RTP1COEFF_g[7];        /* Expression: NumCoeffs
                                        * Referenced by: '<S13>/Stage1'
                                        */
  real_T Stage2_RTP1COEFF_m[40];       /* Expression: NumCoeffs
                                        * Referenced by: '<S13>/Stage2'
                                        */
  real_T Stage1_RTP1COEFF_h[7];        /* Expression: NumCoeffs
                                        * Referenced by: '<S14>/Stage1'
                                        */
  real_T Stage2_RTP1COEFF_i[40];       /* Expression: NumCoeffs
                                        * Referenced by: '<S14>/Stage2'
                                        */
  real_T Stage1_RTP1COEFF_gn[7];       /* Expression: NumCoeffs
                                        * Referenced by: '<S15>/Stage1'
                                        */
  real_T Stage2_RTP1COEFF_h[40];       /* Expression: NumCoeffs
                                        * Referenced by: '<S15>/Stage2'
                                        */
  real_T Stage1_RTP1COEFF_a[7];        /* Expression: NumCoeffs
                                        * Referenced by: '<S16>/Stage1'
                                        */
  real_T Stage2_RTP1COEFF_p[40];       /* Expression: NumCoeffs
                                        * Referenced by: '<S16>/Stage2'
                                        */
  real_T Stage1_RTP1COEFF_e[6];        /* Expression: NumCoeffs
                                        * Referenced by: '<S17>/Stage1'
                                        */
  real_T Stage2_RTP1COEFF_pd[29];      /* Expression: NumCoeffs
                                        * Referenced by: '<S17>/Stage2'
                                        */
  real_T Stage1_RTP1COEFF_hv[6];       /* Expression: NumCoeffs
                                        * Referenced by: '<S18>/Stage1'
                                        */
  real_T Stage2_RTP1COEFF_f[29];       /* Expression: NumCoeffs
                                        * Referenced by: '<S18>/Stage2'
                                        */
  real_T Stage1_RTP1COEFF_o[6];        /* Expression: NumCoeffs
                                        * Referenced by: '<S19>/Stage1'
                                        */
  real_T Stage2_RTP1COEFF_l[29];       /* Expression: NumCoeffs
                                        * Referenced by: '<S19>/Stage2'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S1>/Gain2'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_lpf0 {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_lpf0 lpf0_P;

/* Block signals (auto storage) */
extern BlockIO_lpf0 lpf0_B;

/* Block states (auto storage) */
extern D_Work_lpf0 lpf0_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_lpf0 lpf0_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_lpf0 lpf0_Y;

/* Model entry point functions */
extern void lpf0_initialize(void);
extern void lpf0_step(void);
extern void lpf0_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_lpf0 *const lpf0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('lpf/lpf')    - opens subsystem lpf/lpf
 * hilite_system('lpf/lpf/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : lpf
 * '<S1>'   : lpf/lpf
 * '<S2>'   : lpf/lpf/Low pass acc firx
 * '<S3>'   : lpf/lpf/Low pass acc firy
 * '<S4>'   : lpf/lpf/Low pass acc firz
 * '<S5>'   : lpf/lpf/Low pass gyro firx1
 * '<S6>'   : lpf/lpf/Low pass gyro firx2
 * '<S7>'   : lpf/lpf/Low pass gyro firx3
 * '<S8>'   : lpf/lpf/Low pass gyro firx4
 * '<S9>'   : lpf/lpf/Low pass gyro firx5
 * '<S10>'  : lpf/lpf/Low pass gyro firx6
 * '<S11>'  : lpf/lpf/Low pass acc firx/Generated Filter Block
 * '<S12>'  : lpf/lpf/Low pass acc firy/Generated Filter Block
 * '<S13>'  : lpf/lpf/Low pass acc firz/Generated Filter Block
 * '<S14>'  : lpf/lpf/Low pass gyro firx1/Generated Filter Block
 * '<S15>'  : lpf/lpf/Low pass gyro firx2/Generated Filter Block
 * '<S16>'  : lpf/lpf/Low pass gyro firx3/Generated Filter Block
 * '<S17>'  : lpf/lpf/Low pass gyro firx4/Generated Filter Block
 * '<S18>'  : lpf/lpf/Low pass gyro firx5/Generated Filter Block
 * '<S19>'  : lpf/lpf/Low pass gyro firx6/Generated Filter Block
 */
#endif                                 /* RTW_HEADER_lpf0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
