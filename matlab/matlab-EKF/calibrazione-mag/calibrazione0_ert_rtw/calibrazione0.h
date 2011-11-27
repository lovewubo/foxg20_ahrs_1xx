/*
 * File: calibrazione0.h
 *
 * Code generated for Simulink model 'calibrazione0'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Tue Nov 01 13:14:50 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_calibrazione0_h_
#define RTW_HEADER_calibrazione0_h_
#ifndef calibrazione0_COMMON_INCLUDES_
# define calibrazione0_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_assert.h"
#include "rt_defines.h"
#endif                                 /* calibrazione0_COMMON_INCLUDES_ */

#include "calibrazione0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T sp2;                          /* '<S15>/sp[2]' */
  real_T cp2;                          /* '<S15>/cp[2]' */
  real_T cp1;                          /* '<S15>/cp[1]' */
  real_T sp1;                          /* '<S15>/sp[1]' */
  real_T Assignment[11];               /* '<S62>/Assignment' */
  real_T Assignment1[11];              /* '<S62>/Assignment1' */
  real_T sqrt_g;                       /* '<S14>/sqrt' */
  real_T Product11;                    /* '<S54>/Product11' */
  real_T Product4;                     /* '<S55>/Product4' */
  real_T Product12;                    /* '<S60>/Product12' */
  real_T sqrt_i;                       /* '<S61>/sqrt' */
  real_T Merge[2];                     /* '<S27>/Merge' */
  real_T Sum1;                         /* '<S22>/Sum1' */
  real_T Sum2;                         /* '<S22>/Sum2' */
  real_T Sum3;                         /* '<S22>/Sum3' */
  real_T Sum5;                         /* '<S22>/Sum5' */
  real_T Sum2_e[169];                  /* '<S24>/Sum2' */
  real_T Merge_j[2];                   /* '<S23>/Merge' */
  real_T Assignment_g[169];            /* '<S23>/Assignment' */
  real_T Assignment_snorm[169];        /* '<S23>/Assignment_snorm' */
  real_T Product2;                     /* '<S25>/Product2' */
  real_T Assignment2_d[13];            /* '<S30>/Assignment2' */
  real_T Assignment2_dj[13];           /* '<S29>/Assignment2' */
} BlockIO_calibrazione0;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE[2];         /* '<S62>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_d;          /* '<S22>/Unit Delay1' */
  real_T UnitDelay3_DSTATE;            /* '<S22>/Unit Delay3' */
  real_T UnitDelay2_DSTATE_b;          /* '<S22>/Unit Delay2' */
  real_T UnitDelay4_DSTATE;            /* '<S22>/Unit Delay4' */
  real_T UnitDelay_DSTATE_o[169];      /* '<S24>/Unit Delay' */
  real_T UnitDelay_DSTATE_b[169];      /* '<S51>/Unit Delay' */
  real_T UnitDelay_DSTATE_m[169];      /* '<S23>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b[169];     /* '<S23>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_f[13];      /* '<S25>/Unit Delay1' */
  real_T otime_PreviousInput;          /* '<S19>/otime' */
  real_T olon_PreviousInput;           /* '<S18>/olon' */
  real_T olat_PreviousInput;           /* '<S17>/olat' */
  real_T oalt_PreviousInput;           /* '<S17>/oalt' */
  uint8_T ForIterator_IterationMarker[7];/* '<S21>/For Iterator' */
  boolean_T SpecialcaseNorthSouthGeographic;/* '<S22>/Special case - North//South Geographic Pole' */
} D_Work_calibrazione0;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T posizione[3];                 /* '<Root>/posizione' */
  real_T mag_x[168];                   /* '<Root>/mag_x' */
  real_T mag_y[168];                   /* '<Root>/mag_y' */
  real_T mag_z[168];                   /* '<Root>/mag_z' */
  real_T w[504];                       /* '<Root>/w' */
} ExternalInputs_calibrazione0;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T G[9];                         /* '<Root>/G' */
  real_T b[3];                         /* '<Root>/b' */
  real_T W[3];                         /* '<Root>/W' */
} ExternalOutputs_calibrazione0;

/* Parameters (auto storage) */
struct Parameters_calibrazione0_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T k1313_Value[169];             /* Expression: k
                                        * Referenced by: '<S30>/k[13][13]'
                                        */
  real_T bpp_Y0;                       /* Expression: 0
                                        * Referenced by: '<S25>/bpp'
                                        */
  real_T Constant_Value_g;             /* Expression: fm(2)
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real_T UnitDelay1_X0[13];            /* Expression: ones(1,maxdef+1)
                                        * Referenced by: '<S25>/Unit Delay1'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Constant_Value_jd;            /* Expression: 1
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S39>/Switch'
                                        */
  real_T k1313_Value_a[169];           /* Expression: k
                                        * Referenced by: '<S39>/k[13][13]'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S39>/Switch1'
                                        */
  real_T UnitDelay_X0[169];            /* Expression: zeros(maxdef+1,maxdef+1)
                                        * Referenced by: '<S23>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_k[169];         /* Expression: snorm
                                        * Referenced by: '<S23>/Unit Delay1'
                                        */
  real_T zerosmaxdef1maxdef1_Value[169];/* Expression: zeros(maxdef+1,maxdef+1)
                                         * Referenced by: '<S51>/zeros(maxdef+1,maxdef+1)'
                                         */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S52>/Gain'
                                        */
  real_T UnitDelay_X0_o[169];          /* Expression: zeros(maxdef+1,maxdef+1)
                                        * Referenced by: '<S24>/Unit Delay'
                                        */
  real_T cmaxdefmaxdef_Value[169];     /* Expression: c
                                        * Referenced by: '<S24>/c[maxdef][maxdef]'
                                        */
  real_T cdmaxdefmaxdef_Value[169];    /* Expression: cd
                                        * Referenced by: '<S24>/cd[maxdef][maxdef]'
                                        */
  real_T UnitDelay_X0_f[169];          /* Expression: zeros(maxdef+1,maxdef+1)
                                        * Referenced by: '<S51>/Unit Delay'
                                        */
  real_T Constant1_Value_g;            /* Expression: 1
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T fm_Value[13];                 /* Expression: fm
                                        * Referenced by: '<S22>/fm'
                                        */
  real_T fn_Value[13];                 /* Expression: fn
                                        * Referenced by: '<S22>/fn'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real_T UnitDelay1_X0_l;              /* Expression: 0
                                        * Referenced by: '<S22>/Unit Delay1'
                                        */
  real_T UnitDelay3_X0;                /* Expression: 0
                                        * Referenced by: '<S22>/Unit Delay3'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S22>/Unit Delay2'
                                        */
  real_T UnitDelay4_X0;                /* Expression: 0
                                        * Referenced by: '<S22>/Unit Delay4'
                                        */
  real_T UnitDelay_X0_e;               /* Expression: 0
                                        * Referenced by: '<S13>/Unit Delay'
                                        */
  real_T UnitDelay2_X0_l[4];           /* Expression: [0 0 0 0]
                                        * Referenced by: '<S13>/Unit Delay2'
                                        */
  real_T b_Value;                      /* Expression: 6356.7523142
                                        * Referenced by: '<S14>/b'
                                        */
  real_T a_Value;                      /* Expression: 6378.137
                                        * Referenced by: '<S14>/a'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 2
                                        * Referenced by: '<S59>/Gain'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Constant_Value_k[11];         /* Expression: [1:maxdef-1]
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T UnitDelay1_X0_e;              /* Expression: 0
                                        * Referenced by: '<S62>/Unit Delay1'
                                        */
  real_T ForIterator_IterationLimit;   /* Expression: maxdef-1
                                        * Referenced by: '<S62>/For Iterator'
                                        */
  real_T cpm1spm1_Threshold;           /* Expression: 1
                                        * Referenced by: '<S62>/cp[m-1] sp[m-1]'
                                        */
  real_T Constant1_Value_p[11];        /* Expression: [1:maxdef-1]
                                        * Referenced by: '<S62>/Constant1'
                                        */
  real_T sp13_Y0[13];                  /* Expression: [ zeros(1,13) ]
                                        * Referenced by: '<S15>/sp[13]'
                                        */
  real_T cp13_Y0[13];                  /* Expression: [ zeros(1,13) ]
                                        * Referenced by: '<S15>/cp[13]'
                                        */
  real_T cp1_Value;                    /* Expression: 1
                                        * Referenced by: '<S15>/cp[1]'
                                        */
  real_T sp1_Value;                    /* Expression: 0
                                        * Referenced by: '<S15>/sp[1]'
                                        */
  real_T epoch_Value;                  /* Expression: epoch
                                        * Referenced by: '<S11>/epoch'
                                        */
  real_T Date_Value[3];                /* Expression: simdate
                                        * Referenced by: '<S2>/Date'
                                        */
  real_T DayToYear_Gain;               /* Expression: 1/365
                                        * Referenced by: '<S2>/DayToYear'
                                        */
  real_T MonthToYear_Gain;             /* Expression: 1/12
                                        * Referenced by: '<S2>/MonthToYear'
                                        */
  real_T otime_X0;                     /* Expression: -1000
                                        * Referenced by: '<S19>/otime'
                                        */
  real_T u80deg_UpperSat;              /* Expression: 180.0
                                        * Referenced by: '<S4>/+//- 180 deg'
                                        */
  real_T u80deg_LowerSat;              /* Expression: -180.0
                                        * Referenced by: '<S4>/+//- 180 deg'
                                        */
  real_T u0deg_UpperSat;               /* Expression: 90.0
                                        * Referenced by: '<S4>/+//- 90 deg'
                                        */
  real_T u0deg_LowerSat;               /* Expression: -90.0
                                        * Referenced by: '<S4>/+//- 90 deg'
                                        */
  real_T UnitConversion_Gain;          /* Expression: slope
                                        * Referenced by: '<S63>/Unit Conversion'
                                        */
  real_T olon_X0;                      /* Expression: -1000
                                        * Referenced by: '<S18>/olon'
                                        */
  real_T olat_X0;                      /* Expression: -1000
                                        * Referenced by: '<S17>/olat'
                                        */
  real_T UnitConversion_Gain_e;        /* Expression: slope
                                        * Referenced by: '<S10>/Unit Conversion'
                                        */
  real_T to1000000m_UpperSat;          /* Expression: 1000000.0
                                        * Referenced by: '<S4>/0 to 1,000,000 m'
                                        */
  real_T to1000000m_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S4>/0 to 1,000,000 m'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 0.001
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T oalt_X0;                      /* Expression: -1000
                                        * Referenced by: '<S17>/oalt'
                                        */
  real_T re_Value;                     /* Expression: 6371.2
                                        * Referenced by: '<S11>/re'
                                        */
  real_T UnitConversion_Gain_p;        /* Expression: slope
                                        * Referenced by: '<S68>/Unit Conversion'
                                        */
  real_T UnitConversion_Gain_pl;       /* Expression: slope
                                        * Referenced by: '<S69>/Unit Conversion'
                                        */
  real_T UnitConversion_Gain_g;        /* Expression: slope
                                        * Referenced by: '<S12>/Unit Conversion'
                                        */
  real_T PowerConversion_Gain;         /* Expression: 1.0
                                        * Referenced by: '<S4>/Power Conversion'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.00001
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 0.00001
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T min_val_Value;                /* Expression: min
                                        * Referenced by: '<S5>/min_val'
                                        */
  real_T max_val_Value;                /* Expression: max
                                        * Referenced by: '<S5>/max_val'
                                        */
  real_T min_val_Value_c;              /* Expression: min
                                        * Referenced by: '<S6>/min_val'
                                        */
  real_T max_val_Value_p;              /* Expression: max
                                        * Referenced by: '<S6>/max_val'
                                        */
  real_T min_val_Value_j;              /* Expression: min
                                        * Referenced by: '<S7>/min_val'
                                        */
  real_T max_val_Value_m;              /* Expression: max
                                        * Referenced by: '<S7>/max_val'
                                        */
  real_T min_val_Value_k;              /* Expression: min
                                        * Referenced by: '<S9>/min_val'
                                        */
  real_T max_val_Value_k;              /* Expression: max
                                        * Referenced by: '<S9>/max_val'
                                        */
  int32_T Constant1_Value_e;           /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S31>/Constant1'
                                        */
  int32_T Constant_Value_ex;           /* Computed Parameter: Constant_Value_ex
                                        * Referenced by: '<S32>/Constant'
                                        */
  int32_T Constant_Value_exo;          /* Computed Parameter: Constant_Value_exo
                                        * Referenced by: '<S30>/Constant'
                                        */
  int32_T Constant_Value_as;           /* Computed Parameter: Constant_Value_as
                                        * Referenced by: '<S41>/Constant'
                                        */
  int32_T Gain_Gain_a;                 /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S41>/Gain'
                                        */
  int32_T Constant_Value_asp;          /* Computed Parameter: Constant_Value_asp
                                        * Referenced by: '<S44>/Constant'
                                        */
  int32_T Gain_Gain_as;                /* Computed Parameter: Gain_Gain_as
                                        * Referenced by: '<S43>/Gain'
                                        */
  int32_T Constant_Value_aspr;         /* Computed Parameter: Constant_Value_aspr
                                        * Referenced by: '<S47>/Constant'
                                        */
  int32_T Constant1_Value_as;          /* Computed Parameter: Constant1_Value_as
                                        * Referenced by: '<S47>/Constant1'
                                        */
  int32_T Constant1_Value_asp;         /* Computed Parameter: Constant1_Value_asp
                                        * Referenced by: '<S48>/Constant1'
                                        */
  int32_T Constant_Value_aspro;        /* Computed Parameter: Constant_Value_aspro
                                        * Referenced by: '<S46>/Constant'
                                        */
  int32_T Constant1_Value_aspr;        /* Computed Parameter: Constant1_Value_aspr
                                        * Referenced by: '<S45>/Constant1'
                                        */
  int32_T Gain_Gain_asp;               /* Computed Parameter: Gain_Gain_asp
                                        * Referenced by: '<S45>/Gain'
                                        */
  int32_T Constant1_Value_aspro;       /* Computed Parameter: Constant1_Value_aspro
                                        * Referenced by: '<S49>/Constant1'
                                        */
  int32_T Constant_Value_f;            /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S23>/Constant'
                                        */
  int32_T Constant_Value_l;            /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S40>/Constant'
                                        */
  int32_T Gain_Gain_l;                 /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S40>/Gain'
                                        */
  int32_T Constant_Value_b;            /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S50>/Constant'
                                        */
  int32_T Constant1_Value_d2;          /* Computed Parameter: Constant1_Value_d2
                                        * Referenced by: '<S50>/Constant1'
                                        */
  int32_T Constant_Value_lf;           /* Computed Parameter: Constant_Value_lf
                                        * Referenced by: '<S52>/Constant'
                                        */
  int32_T tc_old_Threshold;            /* Computed Parameter: tc_old_Threshold
                                        * Referenced by: '<S51>/tc_old'
                                        */
  int32_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S22>/Constant'
                                        */
  int32_T Constant1_Value_pd;          /* Computed Parameter: Constant1_Value_pd
                                        * Referenced by: '<S22>/Constant1'
                                        */
  int32_T Constant_Value_bf;           /* Computed Parameter: Constant_Value_bf
                                        * Referenced by: '<S21>/Constant'
                                        */
  int32_T Constant_Value_m;            /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S26>/Constant'
                                        */
  int32_T Gain_Gain_o;                 /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S26>/Gain'
                                        */
  int32_T Constant_Value_je;           /* Computed Parameter: Constant_Value_je
                                        * Referenced by: '<S28>/Constant'
                                        */
  int32_T Constant_Value_mw;           /* Computed Parameter: Constant_Value_mw
                                        * Referenced by: '<S13>/Constant'
                                        */
  int32_T ForIterator_IterationLimit_j;/* Computed Parameter: ForIterator_IterationLimit_j
                                        * Referenced by: '<S13>/For Iterator'
                                        */
  int32_T arn_Threshold;               /* Computed Parameter: arn_Threshold
                                        * Referenced by: '<S13>/ar(n)'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_calibrazione0 {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_calibrazione0 calibrazione0_P;

/* Block signals (auto storage) */
extern BlockIO_calibrazione0 calibrazione0_B;

/* Block states (auto storage) */
extern D_Work_calibrazione0 calibrazione0_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_calibrazione0 calibrazione0_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_calibrazione0 calibrazione0_Y;

/* Model entry point functions */
extern void calibrazione0_initialize(void);
extern void calibrazione0_step(void);
extern void calibrazione0_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_calibrazione0 *const calibrazione0_M;

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
 * hilite_system('calibrazione_M/calibrazione _magnetometro')    - opens subsystem calibrazione_M/calibrazione _magnetometro
 * hilite_system('calibrazione_M/calibrazione _magnetometro/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : calibrazione_M
 * '<S1>'   : calibrazione_M/calibrazione _magnetometro
 * '<S2>'   : calibrazione_M/calibrazione _magnetometro/WMM-2010
 * '<S3>'   : calibrazione_M/calibrazione _magnetometro/calibration-mag
 * '<S4>'   : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010
 * '<S5>'   : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/Check Altitude
 * '<S6>'   : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/Check Latitude
 * '<S7>'   : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/Check Longitude
 * '<S8>'   : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/Compute x,y,z, and h components of magnetic field
 * '<S9>'   : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/Is time within model limits
 * '<S10>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/Length Conversion
 * '<S11>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag
 * '<S12>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/Compute x,y,z, and h components of magnetic field/Angle Conversion2
 * '<S13>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates
 * '<S14>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates
 * '<S15>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates
 * '<S16>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Get Cosine and Sine  of Latitude and Longitude
 * '<S17>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Has altitude or latitude changed
 * '<S18>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Has longitude changed
 * '<S19>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Has time changed
 * '<S20>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity
 * '<S21>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem
 * '<S22>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion
 * '<S23>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations
 * '<S24>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients
 * '<S25>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole
 * '<S26>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate  index
 * '<S27>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values
 * '<S28>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/special case
 * '<S29>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem1
 * '<S30>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2
 * '<S31>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  indices
 * '<S32>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  row and column
 * '<S33>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem
 * '<S34>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1
 * '<S35>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/m,n
 * '<S36>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/n,m-1
 * '<S37>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem
 * '<S38>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1
 * '<S39>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2
 * '<S40>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/calculate  index
 * '<S41>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  index
 * '<S42>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  row and column
 * '<S43>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  index
 * '<S44>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  row and column
 * '<S45>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  indices
 * '<S46>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column1
 * '<S47>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column2
 * '<S48>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2
 * '<S49>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2
 * '<S50>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/If Action Subsystem
 * '<S51>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)
 * '<S52>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem1
 * '<S53>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem2
 * '<S54>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate ca
 * '<S55>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate ct
 * '<S56>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate d
 * '<S57>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate q
 * '<S58>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate q2
 * '<S59>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate r2
 * '<S60>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate sa
 * '<S61>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates/calculate st
 * '<S62>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Convert from geodetic to  spherical coordinates /For Iterator Subsystem
 * '<S63>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Get Cosine and Sine  of Latitude and Longitude/Angle Conversion
 * '<S64>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bx
 * '<S65>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate by
 * '<S66>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bz
 * '<S67>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity
 * '<S68>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion1
 * '<S69>'  : calibrazione_M/calibrazione _magnetometro/WMM-2010/World Magnetic Model 2010/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion2
 */
#endif                                 /* RTW_HEADER_calibrazione0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
