#ifndef __c18_ekffedepre_h__
#define __c18_ekffedepre_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c18_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c18_doneDoubleBufferReInit;
  boolean_T c18_isStable;
  uint8_T c18_is_active_c18_ekffedepre;
  ChartInfoStruct chartInfo;
} SFc18_ekffedepreInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c18_ekffedepre_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c18_ekffedepre_get_check_sum(mxArray *plhs[]);
extern void c18_ekffedepre_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
