#ifndef __c13_EKF_h__
#define __c13_EKF_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c13_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c13_doneDoubleBufferReInit;
  boolean_T c13_isStable;
  uint8_T c13_is_active_c13_EKF;
  ChartInfoStruct chartInfo;
} SFc13_EKFInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_EKF_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_EKF_get_check_sum(mxArray *plhs[]);
extern void c13_EKF_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
