#ifndef __c15_EKF_h__
#define __c15_EKF_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c15_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c15_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c15_doneDoubleBufferReInit;
  boolean_T c15_isStable;
  uint8_T c15_is_active_c15_EKF;
  ChartInfoStruct chartInfo;
} SFc15_EKFInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_EKF_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_EKF_get_check_sum(mxArray *plhs[]);
extern void c15_EKF_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
