/*
 * File: EKF.h
 *
 * Code generated for Simulink model 'EKF'.
 *
 * Model version                  : 1.662
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Fri Feb 03 19:39:16 2012
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
  real_T gphih;                        /* '<S29>/g(phi,h)' */
  real_T c;                            /* '<S4>/c' */
  real_T sp2;                          /* '<S42>/sp[2]' */
  real_T cp2;                          /* '<S42>/cp[2]' */
  real_T cp1;                          /* '<S42>/cp[1]' */
  real_T sp1;                          /* '<S42>/sp[1]' */
  real_T Assignment[11];               /* '<S89>/Assignment' */
  real_T Assignment1[11];              /* '<S89>/Assignment1' */
  real_T sqrt_h;                       /* '<S41>/sqrt' */
  real_T Product11;                    /* '<S81>/Product11' */
  real_T Product4;                     /* '<S82>/Product4' */
  real_T Product12;                    /* '<S87>/Product12' */
  real_T sqrt_n;                       /* '<S88>/sqrt' */
  real_T Merge[2];                     /* '<S54>/Merge' */
  real_T Sum1;                         /* '<S49>/Sum1' */
  real_T Sum2;                         /* '<S49>/Sum2' */
  real_T Sum3;                         /* '<S49>/Sum3' */
  real_T Sum5;                         /* '<S49>/Sum5' */
  real_T Sum2_c[169];                  /* '<S51>/Sum2' */
  real_T Merge_o[2];                   /* '<S50>/Merge' */
  real_T Assignment_k[169];            /* '<S50>/Assignment' */
  real_T Assignment_snorm[169];        /* '<S50>/Assignment_snorm' */
  real_T Product2;                     /* '<S52>/Product2' */
  real_T Assignment2_n[13];            /* '<S57>/Assignment2' */
  real_T Assignment2_nk[13];           /* '<S56>/Assignment2' */
} BlockIO_EKF;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE[2];         /* '<S89>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_m;          /* '<S49>/Unit Delay1' */
  real_T UnitDelay3_DSTATE;            /* '<S49>/Unit Delay3' */
  real_T UnitDelay2_DSTATE_f;          /* '<S49>/Unit Delay2' */
  real_T UnitDelay4_DSTATE;            /* '<S49>/Unit Delay4' */
  real_T UnitDelay_DSTATE_o[169];      /* '<S51>/Unit Delay' */
  real_T UnitDelay_DSTATE_k[169];      /* '<S78>/Unit Delay' */
  real_T UnitDelay_DSTATE_ka[169];     /* '<S50>/Unit Delay' */
  real_T UnitDelay1_DSTATE_p[169];     /* '<S50>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_p4[13];     /* '<S52>/Unit Delay1' */
  real_T Memory1_PreviousInput[49];    /* '<S3>/Memory1' */
  real_T Memory_PreviousInput[7];      /* '<S3>/Memory' */
  real_T Memory_PreviousInput_i[3];    /* '<S1>/Memory' */
  real_T Memory1_PreviousInput_m[4];   /* '<S1>/Memory1' */
  real_T Memory_PreviousInput_o[4];    /* '<S108>/Memory' */
  real_T Memory1_PreviousInput_f;      /* '<S109>/Memory1' */
  real_T Memory2_PreviousInput[3];     /* '<S1>/Memory2' */
  real_T Memory_PreviousInput_a;       /* '<S109>/Memory' */
  real_T otime_PreviousInput;          /* '<S46>/otime' */
  real_T olon_PreviousInput;           /* '<S45>/olon' */
  real_T olat_PreviousInput;           /* '<S44>/olat' */
  real_T oalt_PreviousInput;           /* '<S44>/oalt' */
  real_T Product2_DWORK4[16];          /* '<S17>/Product2' */
  real_T Product2_DWORK4_k[16];        /* '<S16>/Product2' */
  uint8_T ForIterator_IterationMarker[7];/* '<S48>/For Iterator' */
  boolean_T EnabledSubsystem_MODE;     /* '<S1>/Enabled Subsystem' */
  boolean_T SpecialcaseNorthSouthGeographic;/* '<S49>/Special case - North//South Geographic Pole' */
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
  real_T tau;                          /* '<Root>/tau' */
  real_T trig;                         /* '<Root>/trig' */
} ExternalInputs_EKF;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T eulero[3];                    /* '<Root>/eulero' */
  real_T quaternioni[4];               /* '<Root>/quaternioni' */
  real_T pqr[3];                       /* '<Root>/p-q-r' */
  real_T WMM[3];                       /* '<Root>/WMM' */
  real_T WGS[3];                       /* '<Root>/WGS' */
  real_T quat_dot[4];                  /* '<Root>/quat_dot' */
} ExternalOutputs_EKF;

/* Parameters (auto storage) */
struct Parameters_EKF_ {
  real_T Constant_Value[49];           /* Expression: eye(7)
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Rmatrix_Value[16];            /* Expression: eye(4)
                                        * Referenced by: '<S19>/R matrix'
                                        */
  real_T Rmatrix1_Value[12];           /* Expression: zeros(4,3)
                                        * Referenced by: '<S19>/R matrix1'
                                        */
  real_T Rmatrix_Value_h[16];          /* Expression: eye(4)
                                        * Referenced by: '<S20>/R matrix'
                                        */
  real_T Rmatrix1_Value_h[12];         /* Expression: zeros(4,3)
                                        * Referenced by: '<S20>/R matrix1'
                                        */
  real_T Constant2_Value[49];          /* Expression: eye(7)
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T _Value[12];                   /* Expression: zeros(4,3)
                                        * Referenced by: '<S23>/ '
                                        */
  real_T u_Value[12];                  /* Expression: zeros(3,4)
                                        * Referenced by: '<S23>/ 1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T k1313_Value[169];             /* Expression: k
                                        * Referenced by: '<S57>/k[13][13]'
                                        */
  real_T bpp_Y0;                       /* Expression: 0
                                        * Referenced by: '<S52>/bpp'
                                        */
  real_T Constant_Value_a;             /* Expression: fm(2)
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S52>/Constant1'
                                        */
  real_T UnitDelay1_X0[13];            /* Expression: ones(1,maxdef+1)
                                        * Referenced by: '<S52>/Unit Delay1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S66>/Constant1'
                                        */
  real_T Constant_Value_la;            /* Expression: 0
                                        * Referenced by: '<S66>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S66>/Switch'
                                        */
  real_T k1313_Value_l[169];           /* Expression: k
                                        * Referenced by: '<S66>/k[13][13]'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S66>/Switch1'
                                        */
  real_T UnitDelay_X0[169];            /* Expression: zeros(maxdef+1,maxdef+1)
                                        * Referenced by: '<S50>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_m[169];         /* Expression: snorm
                                        * Referenced by: '<S50>/Unit Delay1'
                                        */
  real_T zerosmaxdef1maxdef1_Value[169];/* Expression: zeros(maxdef+1,maxdef+1)
                                         * Referenced by: '<S78>/zeros(maxdef+1,maxdef+1)'
                                         */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S79>/Gain'
                                        */
  real_T UnitDelay_X0_a[169];          /* Expression: zeros(maxdef+1,maxdef+1)
                                        * Referenced by: '<S51>/Unit Delay'
                                        */
  real_T cmaxdefmaxdef_Value[169];     /* Expression: c
                                        * Referenced by: '<S51>/c[maxdef][maxdef]'
                                        */
  real_T cdmaxdefmaxdef_Value[169];    /* Expression: cd
                                        * Referenced by: '<S51>/cd[maxdef][maxdef]'
                                        */
  real_T UnitDelay_X0_g[169];          /* Expression: zeros(maxdef+1,maxdef+1)
                                        * Referenced by: '<S78>/Unit Delay'
                                        */
  real_T Constant1_Value_p;            /* Expression: 1
                                        * Referenced by: '<S54>/Constant1'
                                        */
  real_T fm_Value[13];                 /* Expression: fm
                                        * Referenced by: '<S49>/fm'
                                        */
  real_T fn_Value[13];                 /* Expression: fn
                                        * Referenced by: '<S49>/fn'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S55>/Constant1'
                                        */
  real_T UnitDelay1_X0_c;              /* Expression: 0
                                        * Referenced by: '<S49>/Unit Delay1'
                                        */
  real_T UnitDelay3_X0;                /* Expression: 0
                                        * Referenced by: '<S49>/Unit Delay3'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S49>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0;                /* Expression: 0
                                        * Referenced by: '<S49>/Unit Delay4'
                                        */
  real_T UnitDelay_X0_m;               /* Expression: 0
                                        * Referenced by: '<S40>/Unit Delay'
                                        */
  real_T UnitDelay2_X0_j[4];           /* Expression: [0 0 0 0]
                                        * Referenced by: '<S40>/Unit Delay2'
                                        */
  real_T b_Value;                      /* Expression: 6356.7523142
                                        * Referenced by: '<S41>/b'
                                        */
  real_T a_Value;                      /* Expression: 6378.137
                                        * Referenced by: '<S41>/a'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 2
                                        * Referenced by: '<S86>/Gain'
                                        */
  real_T Constant_Value_lx;            /* Expression: 1
                                        * Referenced by: '<S88>/Constant'
                                        */
  real_T Constant_Value_o[11];         /* Expression: [1:maxdef-1]
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T UnitDelay1_X0_l;              /* Expression: 0
                                        * Referenced by: '<S89>/Unit Delay1'
                                        */
  real_T ForIterator_IterationLimit;   /* Expression: maxdef-1
                                        * Referenced by: '<S89>/For Iterator'
                                        */
  real_T cpm1spm1_Threshold;           /* Expression: 1
                                        * Referenced by: '<S89>/cp[m-1] sp[m-1]'
                                        */
  real_T Constant1_Value_j[11];        /* Expression: [1:maxdef-1]
                                        * Referenced by: '<S89>/Constant1'
                                        */
  real_T sp13_Y0[13];                  /* Expression: [ zeros(1,13) ]
                                        * Referenced by: '<S42>/sp[13]'
                                        */
  real_T cp13_Y0[13];                  /* Expression: [ zeros(1,13) ]
                                        * Referenced by: '<S42>/cp[13]'
                                        */
  real_T cp1_Value;                    /* Expression: 1
                                        * Referenced by: '<S42>/cp[1]'
                                        */
  real_T sp1_Value;                    /* Expression: 0
                                        * Referenced by: '<S42>/sp[1]'
                                        */
  real_T u_Value_e;                    /* Expression: 1/2
                                        * Referenced by: '<S29>/1//2'
                                        */
  real_T u_Value_h;                    /* Expression: 3/2
                                        * Referenced by: '<S29>/3//2'
                                        */
  real_T EquatorialRadius_Value;       /* Expression: 6378137
                                        * Referenced by: '<S29>/Equatorial Radius'
                                        */
  real_T FirstEccentricity_Value;      /* Expression: 0.0818191908426
                                        * Referenced by: '<S29>/First Eccentricity'
                                        */
  real_T GravityatEquator_Value;       /* Expression: 9.7803267714
                                        * Referenced by: '<S29>/Gravity at Equator'
                                        */
  real_T Gravityformulaconst_Value;    /* Expression: 0.00193185138639
                                        * Referenced by: '<S29>/Gravity formula const'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S29>/One'
                                        */
  real_T Date_Value[3];                /* Expression: simdate
                                        * Referenced by: '<S30>/Date'
                                        */
  real_T DayToYear_Gain;               /* Expression: 1/365
                                        * Referenced by: '<S30>/DayToYear'
                                        */
  real_T epoch_Value;                  /* Expression: epoch
                                        * Referenced by: '<S38>/epoch'
                                        */
  real_T MonthToYear_Gain;             /* Expression: 1/12
                                        * Referenced by: '<S30>/MonthToYear'
                                        */
  real_T otime_X0;                     /* Expression: -1000
                                        * Referenced by: '<S46>/otime'
                                        */
  real_T u80deg_UpperSat;              /* Expression: 180.0
                                        * Referenced by: '<S31>/+//- 180 deg'
                                        */
  real_T u80deg_LowerSat;              /* Expression: -180.0
                                        * Referenced by: '<S31>/+//- 180 deg'
                                        */
  real_T u0deg_UpperSat;               /* Expression: 90.0
                                        * Referenced by: '<S31>/+//- 90 deg'
                                        */
  real_T u0deg_LowerSat;               /* Expression: -90.0
                                        * Referenced by: '<S31>/+//- 90 deg'
                                        */
  real_T UnitConversion_Gain;          /* Expression: slope
                                        * Referenced by: '<S90>/Unit Conversion'
                                        */
  real_T olon_X0;                      /* Expression: -1000
                                        * Referenced by: '<S45>/olon'
                                        */
  real_T olat_X0;                      /* Expression: -1000
                                        * Referenced by: '<S44>/olat'
                                        */
  real_T UnitConversion_Gain_h;        /* Expression: slope
                                        * Referenced by: '<S37>/Unit Conversion'
                                        */
  real_T to1000000m_UpperSat;          /* Expression: 1000000.0
                                        * Referenced by: '<S31>/0 to 1,000,000 m'
                                        */
  real_T to1000000m_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S31>/0 to 1,000,000 m'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 0.001
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T oalt_X0;                      /* Expression: -1000
                                        * Referenced by: '<S44>/oalt'
                                        */
  real_T re_Value;                     /* Expression: 6371.2
                                        * Referenced by: '<S38>/re'
                                        */
  real_T UnitConversion_Gain_m;        /* Expression: slope
                                        * Referenced by: '<S95>/Unit Conversion'
                                        */
  real_T UnitConversion_Gain_mi;       /* Expression: slope
                                        * Referenced by: '<S96>/Unit Conversion'
                                        */
  real_T UnitConversion_Gain_d;        /* Expression: slope
                                        * Referenced by: '<S39>/Unit Conversion'
                                        */
  real_T PowerConversion_Gain;         /* Expression: 1.0
                                        * Referenced by: '<S31>/Power Conversion'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.00001
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real_T min_val_Value;                /* Expression: min
                                        * Referenced by: '<S32>/min_val'
                                        */
  real_T max_val_Value;                /* Expression: max
                                        * Referenced by: '<S32>/max_val'
                                        */
  real_T min_val_Value_p;              /* Expression: min
                                        * Referenced by: '<S33>/min_val'
                                        */
  real_T max_val_Value_h;              /* Expression: max
                                        * Referenced by: '<S33>/max_val'
                                        */
  real_T min_val_Value_i;              /* Expression: min
                                        * Referenced by: '<S34>/min_val'
                                        */
  real_T max_val_Value_m;              /* Expression: max
                                        * Referenced by: '<S34>/max_val'
                                        */
  real_T min_val_Value_f;              /* Expression: min
                                        * Referenced by: '<S36>/min_val'
                                        */
  real_T max_val_Value_ht;             /* Expression: max
                                        * Referenced by: '<S36>/max_val'
                                        */
  real_T PowerConversion1_Gain;        /* Expression: 1.0
                                        * Referenced by: '<S31>/Power Conversion1'
                                        */
  real_T PowerConversion2_Gain;        /* Expression: 1.0
                                        * Referenced by: '<S31>/Power Conversion2'
                                        */
  real_T c_Value;                      /* Expression: 0
                                        * Referenced by: '<S4>/c'
                                        */
  real_T Memory1_X0[49];               /* Expression: diag([ones(4,1)*0.003;zeros(3,1)])
                                        * Referenced by: '<S3>/Memory1'
                                        */
  real_T Memory_X0[7];                 /* Expression: x0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T Memory_X0_k;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Memory1_X0_i;                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S108>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S108>/Saturation'
                                        */
  real_T Constant_Value_kq;            /* Expression: 1
                                        * Referenced by: '<S108>/Constant'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T u_Gain;                       /* Expression: 0.5
                                        * Referenced by: '<S100>/1//2'
                                        */
  real_T Memory_X0_h;                  /* Expression: 0
                                        * Referenced by: '<S108>/Memory'
                                        */
  real_T Constant_Value_n[3];          /* Expression: zeros(3,1)
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value_k[4];         /* Expression: zeros(4,1)
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Memory1_X0_o;                 /* Expression: 0.1
                                        * Referenced by: '<S109>/Memory1'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S109>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S109>/Gain2'
                                        */
  real_T Gain_Gain_gj;                 /* Expression: 1
                                        * Referenced by: '<S109>/Gain'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  real_T saturation2pi_UpperSat;       /* Expression: pi
                                        * Referenced by: '<S109>/saturation 2pi'
                                        */
  real_T saturation2pi_LowerSat;       /* Expression: -pi
                                        * Referenced by: '<S109>/saturation 2pi'
                                        */
  real_T Constant_Value_ko;            /* Expression: 1
                                        * Referenced by: '<S109>/Constant'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -1
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Memory_X0_l;                  /* Expression: 0
                                        * Referenced by: '<S109>/Memory'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T UnitConversion_Gain_o;        /* Expression: slope
                                        * Referenced by: '<S2>/Unit Conversion'
                                        */
  real_T u_Gain_g;                     /* Expression: 0.5
                                        * Referenced by: '<S8>/1//2'
                                        */
  int32_T Constant1_Value_c;           /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S58>/Constant1'
                                        */
  int32_T Constant_Value_cg;           /* Computed Parameter: Constant_Value_cg
                                        * Referenced by: '<S59>/Constant'
                                        */
  int32_T Constant_Value_cgz;          /* Computed Parameter: Constant_Value_cgz
                                        * Referenced by: '<S57>/Constant'
                                        */
  int32_T Constant_Value_las;          /* Computed Parameter: Constant_Value_las
                                        * Referenced by: '<S68>/Constant'
                                        */
  int32_T Gain_Gain_l;                 /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S68>/Gain'
                                        */
  int32_T Constant_Value_lase;         /* Computed Parameter: Constant_Value_lase
                                        * Referenced by: '<S71>/Constant'
                                        */
  int32_T Gain_Gain_la;                /* Computed Parameter: Gain_Gain_la
                                        * Referenced by: '<S70>/Gain'
                                        */
  int32_T Constant_Value_laseq;        /* Computed Parameter: Constant_Value_laseq
                                        * Referenced by: '<S74>/Constant'
                                        */
  int32_T Constant1_Value_la;          /* Computed Parameter: Constant1_Value_la
                                        * Referenced by: '<S74>/Constant1'
                                        */
  int32_T Constant1_Value_las;         /* Computed Parameter: Constant1_Value_las
                                        * Referenced by: '<S75>/Constant1'
                                        */
  int32_T Constant_Value_laseqo;       /* Computed Parameter: Constant_Value_laseqo
                                        * Referenced by: '<S73>/Constant'
                                        */
  int32_T Constant1_Value_lase;        /* Computed Parameter: Constant1_Value_lase
                                        * Referenced by: '<S72>/Constant1'
                                        */
  int32_T Gain_Gain_las;               /* Computed Parameter: Gain_Gain_las
                                        * Referenced by: '<S72>/Gain'
                                        */
  int32_T Constant1_Value_laseq;       /* Computed Parameter: Constant1_Value_laseq
                                        * Referenced by: '<S76>/Constant1'
                                        */
  int32_T Constant_Value_h;            /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S50>/Constant'
                                        */
  int32_T Constant_Value_op;           /* Computed Parameter: Constant_Value_op
                                        * Referenced by: '<S67>/Constant'
                                        */
  int32_T Gain_Gain_oa;                /* Computed Parameter: Gain_Gain_oa
                                        * Referenced by: '<S67>/Gain'
                                        */
  int32_T Constant_Value_f;            /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S77>/Constant'
                                        */
  int32_T Constant1_Value_b;           /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S77>/Constant1'
                                        */
  int32_T Constant_Value_ks;           /* Computed Parameter: Constant_Value_ks
                                        * Referenced by: '<S79>/Constant'
                                        */
  int32_T tc_old_Threshold;            /* Computed Parameter: tc_old_Threshold
                                        * Referenced by: '<S78>/tc_old'
                                        */
  int32_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S49>/Constant'
                                        */
  int32_T Constant1_Value_bs;          /* Computed Parameter: Constant1_Value_bs
                                        * Referenced by: '<S49>/Constant1'
                                        */
  int32_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S48>/Constant'
                                        */
  int32_T Constant_Value_opp;          /* Computed Parameter: Constant_Value_opp
                                        * Referenced by: '<S53>/Constant'
                                        */
  int32_T Gain_Gain_e;                 /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S53>/Gain'
                                        */
  int32_T Constant_Value_kh;           /* Computed Parameter: Constant_Value_kh
                                        * Referenced by: '<S55>/Constant'
                                        */
  int32_T Constant_Value_li;           /* Computed Parameter: Constant_Value_li
                                        * Referenced by: '<S40>/Constant'
                                        */
  int32_T ForIterator_IterationLimit_b;/* Computed Parameter: ForIterator_IterationLimit_b
                                        * Referenced by: '<S40>/For Iterator'
                                        */
  int32_T arn_Threshold;               /* Computed Parameter: arn_Threshold
                                        * Referenced by: '<S40>/ar(n)'
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
 * '<S4>'   : ekffede/EKF/Enabled Subsystem
 * '<S5>'   : ekffede/EKF/Gyro-bias
 * '<S6>'   : ekffede/EKF/QUEST_Pqq
 * '<S7>'   : ekffede/EKF/Quaternions to Rotation Angles
 * '<S8>'   : ekffede/EKF/Rotation Angles to Quaternions
 * '<S9>'   : ekffede/EKF/acc-cal
 * '<S10>'  : ekffede/EKF/mag-cal
 * '<S11>'  : ekffede/EKF/quat_derivative
 * '<S12>'  : ekffede/EKF/unione comp filter
 * '<S13>'  : ekffede/EKF/EKF_AHRS/Correction
 * '<S14>'  : ekffede/EKF/EKF_AHRS/Prediction
 * '<S15>'  : ekffede/EKF/EKF_AHRS/Correction/Covariance Matrix
 * '<S16>'  : ekffede/EKF/EKF_AHRS/Correction/Kalman Gain Matrix
 * '<S17>'  : ekffede/EKF/EKF_AHRS/Correction/Kalman Gain Matrix (full)
 * '<S18>'  : ekffede/EKF/EKF_AHRS/Correction/State Correction
 * '<S19>'  : ekffede/EKF/EKF_AHRS/Correction/Subsystem
 * '<S20>'  : ekffede/EKF/EKF_AHRS/Correction/State Correction/Subsystem
 * '<S21>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction
 * '<S22>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/Phi(k)
 * '<S23>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/Q_matrix
 * '<S24>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/f(x_k)
 * '<S25>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/Phi(k)/d f(x) // dx
 * '<S26>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/Q_matrix/MATLAB Function
 * '<S27>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/Q_matrix/MATLAB Function1
 * '<S28>'  : ekffede/EKF/EKF_AHRS/Prediction/Prediction/f(x_k)/f(xk)
 * '<S29>'  : ekffede/EKF/Enabled Subsystem/WGS-84
 * '<S30>'  : ekffede/EKF/Enabled Subsystem/WMM-2010
 * '<S31>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010
 * '<S32>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/Check Altitude
 * '<S33>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/Check Latitude
 * '<S34>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/Check Longitude
 * '<S35>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/Compute x,y,z, and h components of magnetic field
 * '<S36>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/Is time within model limits
 * '<S37>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/Length Conversion
 * '<S38>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag
 * '<S39>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/Compute x,y,z, and h components of magnetic field/Angle Conversion2
 * '<S40>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates
 * '<S41>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates
 * '<S42>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates
 * '<S43>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Get Cosine and Sine  of Latitude and Longitude
 * '<S44>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Has altitude or latitude changed
 * '<S45>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Has longitude changed
 * '<S46>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Has time changed
 * '<S47>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity
 * '<S48>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem
 * '<S49>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion
 * '<S50>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations
 * '<S51>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients
 * '<S52>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole
 * '<S53>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate  index
 * '<S54>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values
 * '<S55>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/special case
 * '<S56>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem1
 * '<S57>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2
 * '<S58>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  indices
 * '<S59>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  row and column
 * '<S60>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem
 * '<S61>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1
 * '<S62>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/m,n
 * '<S63>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/n,m-1
 * '<S64>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem
 * '<S65>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1
 * '<S66>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2
 * '<S67>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/calculate  index
 * '<S68>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  index
 * '<S69>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  row and column
 * '<S70>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  index
 * '<S71>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  row and column
 * '<S72>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  indices
 * '<S73>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column1
 * '<S74>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column2
 * '<S75>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2
 * '<S76>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2
 * '<S77>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/If Action Subsystem
 * '<S78>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)
 * '<S79>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem1
 * '<S80>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem2
 * '<S81>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate ca
 * '<S82>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate ct
 * '<S83>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate d
 * '<S84>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate q
 * '<S85>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate q2
 * '<S86>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate r2
 * '<S87>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate sa
 * '<S88>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate st
 * '<S89>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates /For Iterator Subsystem
 * '<S90>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Get Cosine and Sine  of Latitude and Longitude/Angle Conversion
 * '<S91>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bx
 * '<S92>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate by
 * '<S93>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bz
 * '<S94>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity
 * '<S95>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion1
 * '<S96>'  : ekffede/EKF/Enabled Subsystem/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion2
 * '<S97>'  : ekffede/EKF/QUEST_Pqq/MATLAB Function2
 * '<S98>'  : ekffede/EKF/QUEST_Pqq/QUEST
 * '<S99>'  : ekffede/EKF/QUEST_Pqq/Quaternions to Rotation Angles
 * '<S100>' : ekffede/EKF/QUEST_Pqq/Rotation Angles to Quaternions
 * '<S101>' : ekffede/EKF/QUEST_Pqq/q_matrix
 * '<S102>' : ekffede/EKF/QUEST_Pqq/Quaternions to Rotation Angles/Quaternion Normalize
 * '<S103>' : ekffede/EKF/QUEST_Pqq/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus
 * '<S104>' : ekffede/EKF/QUEST_Pqq/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm
 * '<S105>' : ekffede/EKF/Quaternions to Rotation Angles/Quaternion Normalize
 * '<S106>' : ekffede/EKF/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus
 * '<S107>' : ekffede/EKF/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm
 * '<S108>' : ekffede/EKF/unione comp filter/complementar_filter
 * '<S109>' : ekffede/EKF/unione comp filter/complementar_filter_yaw
 * '<S110>' : ekffede/EKF/unione comp filter/complementar_filter/correzione inversione quat
 * '<S111>' : ekffede/EKF/unione comp filter/complementar_filter/quat_derivative
 * '<S112>' : ekffede/EKF/unione comp filter/complementar_filter_yaw/corezione passaggio 360
 * '<S113>' : ekffede/EKF/unione comp filter/complementar_filter_yaw/yaw_complementar_calculator
 */
#endif                                 /* RTW_HEADER_EKF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
