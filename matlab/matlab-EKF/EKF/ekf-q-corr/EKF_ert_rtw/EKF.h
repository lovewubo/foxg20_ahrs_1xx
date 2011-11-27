/*
 * File: EKF.h
 *
 * Code generated for Simulink model 'EKF'.
 *
 * Model version                  : 1.378
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Tue Nov 01 13:07:00 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_EKF_h_
#define RTW_HEADER_EKF_h_
#ifndef EKF_COMMON_INCLUDES_
# define EKF_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_assert.h"
#include "rt_defines.h"
#include "rt_matrixlib.h"
#endif                                 /* EKF_COMMON_INCLUDES_ */

#include "EKF_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T sp2;                          /* '<S43>/sp[2]' */
  real_T cp2;                          /* '<S43>/cp[2]' */
  real_T cp1;                          /* '<S43>/cp[1]' */
  real_T sp1;                          /* '<S43>/sp[1]' */
  real_T Assignment[11];               /* '<S90>/Assignment' */
  real_T Assignment1[11];              /* '<S90>/Assignment1' */
  real_T sqrt_g;                       /* '<S42>/sqrt' */
  real_T Product11;                    /* '<S82>/Product11' */
  real_T Product4;                     /* '<S83>/Product4' */
  real_T Product12;                    /* '<S88>/Product12' */
  real_T sqrt_h;                       /* '<S89>/sqrt' */
  real_T Merge[2];                     /* '<S55>/Merge' */
  real_T Sum1;                         /* '<S50>/Sum1' */
  real_T Sum2;                         /* '<S50>/Sum2' */
  real_T Sum3;                         /* '<S50>/Sum3' */
  real_T Sum5;                         /* '<S50>/Sum5' */
  real_T Sum2_j[169];                  /* '<S52>/Sum2' */
  real_T Merge_j[2];                   /* '<S51>/Merge' */
  real_T Assignment_g[169];            /* '<S51>/Assignment' */
  real_T Assignment_snorm[169];        /* '<S51>/Assignment_snorm' */
  real_T Product2;                     /* '<S53>/Product2' */
  real_T Assignment2_h[13];            /* '<S58>/Assignment2' */
  real_T Assignment2_d[13];            /* '<S57>/Assignment2' */
} BlockIO_EKF;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE[2];         /* '<S90>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_d;          /* '<S50>/Unit Delay1' */
  real_T UnitDelay3_DSTATE;            /* '<S50>/Unit Delay3' */
  real_T UnitDelay2_DSTATE_a;          /* '<S50>/Unit Delay2' */
  real_T UnitDelay4_DSTATE;            /* '<S50>/Unit Delay4' */
  real_T UnitDelay_DSTATE_g[169];      /* '<S52>/Unit Delay' */
  real_T UnitDelay_DSTATE_o[169];      /* '<S79>/Unit Delay' */
  real_T UnitDelay_DSTATE_d[169];      /* '<S51>/Unit Delay' */
  real_T UnitDelay1_DSTATE_h[169];     /* '<S51>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_dg[13];     /* '<S53>/Unit Delay1' */
  real_T Memory1_PreviousInput[49];    /* '<S3>/Memory1' */
  real_T Memory_PreviousInput[7];      /* '<S3>/Memory' */
  real_T otime_PreviousInput;          /* '<S47>/otime' */
  real_T olon_PreviousInput;           /* '<S46>/olon' */
  real_T olat_PreviousInput;           /* '<S45>/olat' */
  real_T oalt_PreviousInput;           /* '<S45>/oalt' */
  real_T Product2_DWORK4[16];          /* '<S15>/Product2' */
  real_T Product2_DWORK4_k[16];        /* '<S14>/Product2' */
  uint8_T ForIterator_IterationMarker[7];/* '<S49>/For Iterator' */
  boolean_T SpecialcaseNorthSouthGeographic;/* '<S50>/Special case - North//South Geographic Pole' */
} D_Work_EKF;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T latlonalti[3];                /* '<Root>/lat-lon-alti' */
  real_T accell[3];                    /* '<Root>/accell' */
  real_T mag[3];                       /* '<Root>/mag' */
  real_T gyro[3];                      /* '<Root>/gyro' */
  real_T deviazione_std_accell;        /* '<Root>/deviazione_std_accell' */
  real_T deviazione_std_magneto;       /* '<Root>/deviazione_std_magneto' */
  real_T dt;                           /* '<Root>/dt' */
  real_T Q_quat[4];                    /* '<Root>/Q_quat' */
  real_T Q_bias[3];                    /* '<Root>/Q_bias' */
  real_T GPS_Reset;                    /* '<Root>/GPS_Reset' */
  real_T Accel_Cal[12];                /* '<Root>/Accel_Cal' */
  real_T Mag_Cal[12];                  /* '<Root>/Mag_Cal' */
  real_T Gyro_Cal[3];                  /* '<Root>/Gyro_Cal' */
} ExternalInputs_EKF;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T eulero[3];                    /* '<Root>/eulero' */
  real_T quaternioni[4];               /* '<Root>/quaternioni' */
  real_T pqr[3];                       /* '<Root>/p-q-r' */
  real_T WMM[3];                       /* '<Root>/WMM' */
  real_T WGS[3];                       /* '<Root>/WGS' */
} ExternalOutputs_EKF;

/* Parameters (auto storage) */
struct Parameters_EKF_ {
  real_T Constant_Value[49];           /* Expression: eye(7)
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Rmatrix_Value[16];            /* Expression: eye(4)
                                        * Referenced by: '<S17>/R matrix'
                                        */
  real_T Rmatrix1_Value[12];           /* Expression: zeros(4,3)
                                        * Referenced by: '<S17>/R matrix1'
                                        */
  real_T Rmatrix_Value_h[16];          /* Expression: eye(4)
                                        * Referenced by: '<S18>/R matrix'
                                        */
  real_T Rmatrix1_Value_h[12];         /* Expression: zeros(4,3)
                                        * Referenced by: '<S18>/R matrix1'
                                        */
  real_T Constant2_Value[49];          /* Expression: eye(7)
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real_T _Value[12];                   /* Expression: zeros(4,3)
                                        * Referenced by: '<S21>/ '
                                        */
  real_T u_Value[12];                  /* Expression: zeros(3,4)
                                        * Referenced by: '<S21>/ 1'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T k1313_Value[169];             /* Expression: k
                                        * Referenced by: '<S58>/k[13][13]'
                                        */
  real_T bpp_Y0;                       /* Expression: 0
                                        * Referenced by: '<S53>/bpp'
                                        */
  real_T Constant_Value_i;             /* Expression: fm(2)
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S53>/Constant1'
                                        */
  real_T UnitDelay1_X0[13];            /* Expression: ones(1,maxdef+1)
                                        * Referenced by: '<S53>/Unit Delay1'
                                        */
  real_T Constant_Value_ip;            /* Expression: 1
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S64>/Constant'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S67>/Constant1'
                                        */
  real_T Constant_Value_gy;            /* Expression: 0
                                        * Referenced by: '<S67>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S67>/Switch'
                                        */
  real_T k1313_Value_k[169];           /* Expression: k
                                        * Referenced by: '<S67>/k[13][13]'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S67>/Switch1'
                                        */
  real_T UnitDelay_X0[169];            /* Expression: zeros(maxdef+1,maxdef+1)
                                        * Referenced by: '<S51>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_g[169];         /* Expression: snorm
                                        * Referenced by: '<S51>/Unit Delay1'
                                        */
  real_T zerosmaxdef1maxdef1_Value[169];/* Expression: zeros(maxdef+1,maxdef+1)
                                         * Referenced by: '<S79>/zeros(maxdef+1,maxdef+1)'
                                         */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S80>/Gain'
                                        */
  real_T UnitDelay_X0_e[169];          /* Expression: zeros(maxdef+1,maxdef+1)
                                        * Referenced by: '<S52>/Unit Delay'
                                        */
  real_T cmaxdefmaxdef_Value[169];     /* Expression: c
                                        * Referenced by: '<S52>/c[maxdef][maxdef]'
                                        */
  real_T cdmaxdefmaxdef_Value[169];    /* Expression: cd
                                        * Referenced by: '<S52>/cd[maxdef][maxdef]'
                                        */
  real_T UnitDelay_X0_h[169];          /* Expression: zeros(maxdef+1,maxdef+1)
                                        * Referenced by: '<S79>/Unit Delay'
                                        */
  real_T Constant1_Value_p;            /* Expression: 1
                                        * Referenced by: '<S55>/Constant1'
                                        */
  real_T fm_Value[13];                 /* Expression: fm
                                        * Referenced by: '<S50>/fm'
                                        */
  real_T fn_Value[13];                 /* Expression: fn
                                        * Referenced by: '<S50>/fn'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S56>/Constant1'
                                        */
  real_T UnitDelay1_X0_p;              /* Expression: 0
                                        * Referenced by: '<S50>/Unit Delay1'
                                        */
  real_T UnitDelay3_X0;                /* Expression: 0
                                        * Referenced by: '<S50>/Unit Delay3'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S50>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0;                /* Expression: 0
                                        * Referenced by: '<S50>/Unit Delay4'
                                        */
  real_T UnitDelay_X0_c;               /* Expression: 0
                                        * Referenced by: '<S41>/Unit Delay'
                                        */
  real_T UnitDelay2_X0_e[4];           /* Expression: [0 0 0 0]
                                        * Referenced by: '<S41>/Unit Delay2'
                                        */
  real_T b_Value;                      /* Expression: 6356.7523142
                                        * Referenced by: '<S42>/b'
                                        */
  real_T a_Value;                      /* Expression: 6378.137
                                        * Referenced by: '<S42>/a'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 2
                                        * Referenced by: '<S87>/Gain'
                                        */
  real_T Constant_Value_a2;            /* Expression: 1
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T Constant_Value_eo[11];        /* Expression: [1:maxdef-1]
                                        * Referenced by: '<S90>/Constant'
                                        */
  real_T UnitDelay1_X0_o;              /* Expression: 0
                                        * Referenced by: '<S90>/Unit Delay1'
                                        */
  real_T ForIterator_IterationLimit;   /* Expression: maxdef-1
                                        * Referenced by: '<S90>/For Iterator'
                                        */
  real_T cpm1spm1_Threshold;           /* Expression: 1
                                        * Referenced by: '<S90>/cp[m-1] sp[m-1]'
                                        */
  real_T Constant1_Value_b[11];        /* Expression: [1:maxdef-1]
                                        * Referenced by: '<S90>/Constant1'
                                        */
  real_T sp13_Y0[13];                  /* Expression: [ zeros(1,13) ]
                                        * Referenced by: '<S43>/sp[13]'
                                        */
  real_T cp13_Y0[13];                  /* Expression: [ zeros(1,13) ]
                                        * Referenced by: '<S43>/cp[13]'
                                        */
  real_T cp1_Value;                    /* Expression: 1
                                        * Referenced by: '<S43>/cp[1]'
                                        */
  real_T sp1_Value;                    /* Expression: 0
                                        * Referenced by: '<S43>/sp[1]'
                                        */
  real_T Memory1_X0[49];               /* Expression: diag([ones(4,1)*0.003;zeros(3,1)])
                                        * Referenced by: '<S3>/Memory1'
                                        */
  real_T Memory_X0[7];                 /* Expression: x0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T c_Value;                      /* Expression: 0
                                        * Referenced by: '<S1>/c'
                                        */
  real_T GravityatEquator_Value;       /* Expression: 9.7803267714
                                        * Referenced by: '<S7>/Gravity at Equator'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S7>/One'
                                        */
  real_T Gravityformulaconst_Value;    /* Expression: 0.00193185138639
                                        * Referenced by: '<S7>/Gravity formula const'
                                        */
  real_T FirstEccentricity_Value;      /* Expression: 0.0818191908426
                                        * Referenced by: '<S7>/First Eccentricity'
                                        */
  real_T u_Value_k;                    /* Expression: 1/2
                                        * Referenced by: '<S7>/1//2'
                                        */
  real_T epoch_Value;                  /* Expression: epoch
                                        * Referenced by: '<S39>/epoch'
                                        */
  real_T Date_Value[3];                /* Expression: simdate
                                        * Referenced by: '<S8>/Date'
                                        */
  real_T DayToYear_Gain;               /* Expression: 1/365
                                        * Referenced by: '<S8>/DayToYear'
                                        */
  real_T MonthToYear_Gain;             /* Expression: 1/12
                                        * Referenced by: '<S8>/MonthToYear'
                                        */
  real_T otime_X0;                     /* Expression: -1000
                                        * Referenced by: '<S47>/otime'
                                        */
  real_T u80deg_UpperSat;              /* Expression: 180.0
                                        * Referenced by: '<S32>/+//- 180 deg'
                                        */
  real_T u80deg_LowerSat;              /* Expression: -180.0
                                        * Referenced by: '<S32>/+//- 180 deg'
                                        */
  real_T u0deg_UpperSat;               /* Expression: 90.0
                                        * Referenced by: '<S32>/+//- 90 deg'
                                        */
  real_T u0deg_LowerSat;               /* Expression: -90.0
                                        * Referenced by: '<S32>/+//- 90 deg'
                                        */
  real_T UnitConversion_Gain;          /* Expression: slope
                                        * Referenced by: '<S91>/Unit Conversion'
                                        */
  real_T olon_X0;                      /* Expression: -1000
                                        * Referenced by: '<S46>/olon'
                                        */
  real_T olat_X0;                      /* Expression: -1000
                                        * Referenced by: '<S45>/olat'
                                        */
  real_T UnitConversion_Gain_a;        /* Expression: slope
                                        * Referenced by: '<S38>/Unit Conversion'
                                        */
  real_T to1000000m_UpperSat;          /* Expression: 1000000.0
                                        * Referenced by: '<S32>/0 to 1,000,000 m'
                                        */
  real_T to1000000m_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S32>/0 to 1,000,000 m'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 0.001
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T oalt_X0;                      /* Expression: -1000
                                        * Referenced by: '<S45>/oalt'
                                        */
  real_T re_Value;                     /* Expression: 6371.2
                                        * Referenced by: '<S39>/re'
                                        */
  real_T UnitConversion_Gain_e;        /* Expression: slope
                                        * Referenced by: '<S96>/Unit Conversion'
                                        */
  real_T UnitConversion_Gain_o;        /* Expression: slope
                                        * Referenced by: '<S97>/Unit Conversion'
                                        */
  real_T UnitConversion_Gain_ax;       /* Expression: slope
                                        * Referenced by: '<S40>/Unit Conversion'
                                        */
  real_T PowerConversion_Gain;         /* Expression: 1.0
                                        * Referenced by: '<S32>/Power Conversion'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.00001
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Constant_Value_n[3];          /* Expression: zeros(3,1)
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value_k[4];         /* Expression: zeros(4,1)
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T UnitConversion_Gain_ol;       /* Expression: slope
                                        * Referenced by: '<S2>/Unit Conversion'
                                        */
  real_T min_val_Value;                /* Expression: min
                                        * Referenced by: '<S33>/min_val'
                                        */
  real_T max_val_Value;                /* Expression: max
                                        * Referenced by: '<S33>/max_val'
                                        */
  real_T min_val_Value_k;              /* Expression: min
                                        * Referenced by: '<S34>/min_val'
                                        */
  real_T max_val_Value_d;              /* Expression: max
                                        * Referenced by: '<S34>/max_val'
                                        */
  real_T min_val_Value_c;              /* Expression: min
                                        * Referenced by: '<S35>/min_val'
                                        */
  real_T max_val_Value_p;              /* Expression: max
                                        * Referenced by: '<S35>/max_val'
                                        */
  real_T min_val_Value_i;              /* Expression: min
                                        * Referenced by: '<S37>/min_val'
                                        */
  real_T max_val_Value_c;              /* Expression: max
                                        * Referenced by: '<S37>/max_val'
                                        */
  int32_T Constant1_Value_ao;          /* Computed Parameter: Constant1_Value_ao
                                        * Referenced by: '<S59>/Constant1'
                                        */
  int32_T Constant_Value_k;            /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S60>/Constant'
                                        */
  int32_T Constant_Value_er;           /* Computed Parameter: Constant_Value_er
                                        * Referenced by: '<S58>/Constant'
                                        */
  int32_T Constant_Value_c;            /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S69>/Constant'
                                        */
  int32_T Gain_Gain_c;                 /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S69>/Gain'
                                        */
  int32_T Constant_Value_ix;           /* Computed Parameter: Constant_Value_ix
                                        * Referenced by: '<S72>/Constant'
                                        */
  int32_T Gain_Gain_e;                 /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S71>/Gain'
                                        */
  int32_T Constant_Value_f;            /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S75>/Constant'
                                        */
  int32_T Constant1_Value_f;           /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S75>/Constant1'
                                        */
  int32_T Constant1_Value_bw;          /* Computed Parameter: Constant1_Value_bw
                                        * Referenced by: '<S76>/Constant1'
                                        */
  int32_T Constant_Value_fu;           /* Computed Parameter: Constant_Value_fu
                                        * Referenced by: '<S74>/Constant'
                                        */
  int32_T Constant1_Value_d;           /* Computed Parameter: Constant1_Value_d
                                        * Referenced by: '<S73>/Constant1'
                                        */
  int32_T Gain_Gain_d;                 /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S73>/Gain'
                                        */
  int32_T Constant1_Value_kv;          /* Computed Parameter: Constant1_Value_kv
                                        * Referenced by: '<S77>/Constant1'
                                        */
  int32_T Constant_Value_h;            /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S51>/Constant'
                                        */
  int32_T Constant_Value_ie;           /* Computed Parameter: Constant_Value_ie
                                        * Referenced by: '<S68>/Constant'
                                        */
  int32_T Gain_Gain_j;                 /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S68>/Gain'
                                        */
  int32_T Constant_Value_b;            /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S78>/Constant'
                                        */
  int32_T Constant1_Value_jr;          /* Computed Parameter: Constant1_Value_jr
                                        * Referenced by: '<S78>/Constant1'
                                        */
  int32_T Constant_Value_ik;           /* Computed Parameter: Constant_Value_ik
                                        * Referenced by: '<S80>/Constant'
                                        */
  int32_T tc_old_Threshold;            /* Computed Parameter: tc_old_Threshold
                                        * Referenced by: '<S79>/tc_old'
                                        */
  int32_T Constant_Value_l;            /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S50>/Constant'
                                        */
  int32_T Constant1_Value_ji;          /* Computed Parameter: Constant1_Value_ji
                                        * Referenced by: '<S50>/Constant1'
                                        */
  int32_T Constant_Value_km;           /* Computed Parameter: Constant_Value_km
                                        * Referenced by: '<S49>/Constant'
                                        */
  int32_T Constant_Value_kz;           /* Computed Parameter: Constant_Value_kz
                                        * Referenced by: '<S54>/Constant'
                                        */
  int32_T Gain_Gain_np;                /* Computed Parameter: Gain_Gain_np
                                        * Referenced by: '<S54>/Gain'
                                        */
  int32_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S56>/Constant'
                                        */
  int32_T Constant_Value_ln;           /* Computed Parameter: Constant_Value_ln
                                        * Referenced by: '<S41>/Constant'
                                        */
  int32_T ForIterator_IterationLimit_l;/* Computed Parameter: ForIterator_IterationLimit_l
                                        * Referenced by: '<S41>/For Iterator'
                                        */
  int32_T arn_Threshold;               /* Computed Parameter: arn_Threshold
                                        * Referenced by: '<S41>/ar(n)'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_EKF {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_EKF EKF_P;

/* Block signals (auto storage) */
extern BlockIO_EKF EKF_B;

/* Block states (auto storage) */
extern D_Work_EKF EKF_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_EKF EKF_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_EKF EKF_Y;

/* Model entry point functions */
extern void EKF_initialize(void);
extern void EKF_step(void);
extern void EKF_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_EKF *const EKF_M;

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
 * hilite_system('ekffede/EKF')    - opens subsystem ekffede/EKF
 * hilite_system('ekffede/EKF/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : ekffede
 * '<S1>'   : ekffede/EKF
 * '<S2>'   : ekffede/EKF/Angle Conversion
 * '<S3>'   : ekffede/EKF/EKF_AHRS
 * '<S4>'   : ekffede/EKF/Gyro-bias
 * '<S5>'   : ekffede/EKF/QUEST_Pqq
 * '<S6>'   : ekffede/EKF/Quaternions to Rotation Angles
 * '<S7>'   : ekffede/EKF/WGS-84
 * '<S8>'   : ekffede/EKF/WMM-2010
 * '<S9>'   : ekffede/EKF/acc-cal
 * '<S10>'  : ekffede/EKF/mag-cal
 * '<S11>'  : ekffede/EKF/EKF_AHRS/Correction
 * '<S12>'  : ekffede/EKF/EKF_AHRS/Prediction
 * '<S13>'  : ekffede/EKF/EKF_AHRS/Correction/Covariance Matrix
 * '<S14>'  : ekffede/EKF/EKF_AHRS/Correction/Kalman Gain Matrix
 * '<S15>'  : ekffede/EKF/EKF_AHRS/Correction/Kalman Gain Matrix (full)
 * '<S16>'  : ekffede/EKF/EKF_AHRS/Correction/State Correction
 * '<S17>'  : ekffede/EKF/EKF_AHRS/Correction/Subsystem
 * '<S18>'  : ekffede/EKF/EKF_AHRS/Correction/State Correction/Subsystem
 * '<S19>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction
 * '<S20>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/Phi(k)
 * '<S21>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/Q_matrix
 * '<S22>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/f(x_k)
 * '<S23>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/Phi(k)/d f(x) // dx
 * '<S24>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/Q_matrix/MATLAB Function
 * '<S25>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/Q_matrix/MATLAB Function1
 * '<S26>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/f(x_k)/f(xk)
 * '<S27>'  : ekffede/EKF/QUEST_Pqq/QUEST
 * '<S28>'  : ekffede/EKF/QUEST_Pqq/q_matrix
 * '<S29>'  : ekffede/EKF/Quaternions to Rotation Angles/Quaternion Normalize
 * '<S30>'  : ekffede/EKF/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus
 * '<S31>'  : ekffede/EKF/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm
 * '<S32>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010
 * '<S33>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/Check Altitude
 * '<S34>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/Check Latitude
 * '<S35>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/Check Longitude
 * '<S36>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/Compute x,y,z, and h components of magnetic field
 * '<S37>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/Is time within model limits
 * '<S38>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/Length Conversion
 * '<S39>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag
 * '<S40>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/Compute x,y,z, and h components of magnetic field/Angle Conversion2
 * '<S41>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates
 * '<S42>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates
 * '<S43>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates
 * '<S44>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Get Cosine and Sine  of Latitude and Longitude
 * '<S45>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Has altitude or latitude changed
 * '<S46>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Has longitude changed
 * '<S47>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Has time changed
 * '<S48>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity
 * '<S49>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem
 * '<S50>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion
 * '<S51>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations
 * '<S52>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients
 * '<S53>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole
 * '<S54>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate  index
 * '<S55>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values
 * '<S56>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/special case
 * '<S57>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem1
 * '<S58>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2
 * '<S59>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  indices
 * '<S60>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  row and column
 * '<S61>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem
 * '<S62>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1
 * '<S63>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/m,n
 * '<S64>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/n,m-1
 * '<S65>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem
 * '<S66>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1
 * '<S67>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2
 * '<S68>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/calculate  index
 * '<S69>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  index
 * '<S70>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  row and column
 * '<S71>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  index
 * '<S72>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  row and column
 * '<S73>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  indices
 * '<S74>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column1
 * '<S75>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column2
 * '<S76>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2
 * '<S77>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2
 * '<S78>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/If Action Subsystem
 * '<S79>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)
 * '<S80>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem1
 * '<S81>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem2
 * '<S82>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate ca
 * '<S83>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate ct
 * '<S84>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate d
 * '<S85>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate q
 * '<S86>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate q2
 * '<S87>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate r2
 * '<S88>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate sa
 * '<S89>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate st
 * '<S90>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates /For Iterator Subsystem
 * '<S91>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Get Cosine and Sine  of Latitude and Longitude/Angle Conversion
 * '<S92>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bx
 * '<S93>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate by
 * '<S94>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bz
 * '<S95>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity
 * '<S96>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion1
 * '<S97>'  : ekffede/EKF/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion2
 */
#endif                                 /* RTW_HEADER_EKF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
