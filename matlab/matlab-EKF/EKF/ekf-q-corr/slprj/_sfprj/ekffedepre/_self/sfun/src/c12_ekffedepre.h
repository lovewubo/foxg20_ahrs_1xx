#ifndef __c12_ekffedepre_h__
#define __c12_ekffedepre_h__

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
} c12_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c12_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c12_doneDoubleBufferReInit;
  boolean_T c12_isStable;
  uint8_T c12_is_active_c12_ekffedepre;
  ChartInfoStruct chartInfo;
} SFc12_ekffedepreInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_ekffedepre_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_ekffedepre_get_check_sum(mxArray *plhs[]);
extern void c12_ekffedepre_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
