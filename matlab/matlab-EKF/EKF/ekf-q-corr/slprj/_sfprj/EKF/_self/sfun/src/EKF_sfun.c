/* Include files */

#include "EKF_sfun.h"
#include "c1_EKF.h"
#include "c2_EKF.h"
#include "c3_EKF.h"
#include "c4_EKF.h"
#include "c11_EKF.h"
#include "c12_EKF.h"
#include "c13_EKF.h"
#include "c14_EKF.h"
#include "c15_EKF.h"
#include "c16_EKF.h"
#include "c17_EKF.h"
#include "c18_EKF.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _EKFMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void EKF_initializer(void)
{
}

void EKF_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_EKF_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_EKF_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_EKF_process_check_sum_call( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3835686164U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1428285271U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(512981422U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(126335272U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1310696787U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1717982952U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2797991598U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1868415785U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_EKF_get_check_sum(mxArray *plhs[]);
          sf_c1_EKF_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_EKF_get_check_sum(mxArray *plhs[]);
          sf_c2_EKF_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_EKF_get_check_sum(mxArray *plhs[]);
          sf_c3_EKF_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_EKF_get_check_sum(mxArray *plhs[]);
          sf_c4_EKF_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_EKF_get_check_sum(mxArray *plhs[]);
          sf_c11_EKF_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_EKF_get_check_sum(mxArray *plhs[]);
          sf_c12_EKF_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_EKF_get_check_sum(mxArray *plhs[]);
          sf_c13_EKF_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_EKF_get_check_sum(mxArray *plhs[]);
          sf_c14_EKF_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_EKF_get_check_sum(mxArray *plhs[]);
          sf_c15_EKF_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_EKF_get_check_sum(mxArray *plhs[]);
          sf_c16_EKF_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_EKF_get_check_sum(mxArray *plhs[]);
          sf_c17_EKF_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_EKF_get_check_sum(mxArray *plhs[]);
          sf_c18_EKF_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3176360410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1862911626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(659157607U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1884031890U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(41900616U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2755841632U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(228922503U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2242958367U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EKF_autoinheritance_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c1_EKF_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c2_EKF_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c3_EKF_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c4_EKF_get_autoinheritance_info();
        break;
      }

     case 11:
      {
        extern mxArray *sf_c11_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c11_EKF_get_autoinheritance_info();
        break;
      }

     case 12:
      {
        extern mxArray *sf_c12_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c12_EKF_get_autoinheritance_info();
        break;
      }

     case 13:
      {
        extern mxArray *sf_c13_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c13_EKF_get_autoinheritance_info();
        break;
      }

     case 14:
      {
        extern mxArray *sf_c14_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c14_EKF_get_autoinheritance_info();
        break;
      }

     case 15:
      {
        extern mxArray *sf_c15_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c15_EKF_get_autoinheritance_info();
        break;
      }

     case 16:
      {
        extern mxArray *sf_c16_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c16_EKF_get_autoinheritance_info();
        break;
      }

     case 17:
      {
        extern mxArray *sf_c17_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c17_EKF_get_autoinheritance_info();
        break;
      }

     case 18:
      {
        extern mxArray *sf_c18_EKF_get_autoinheritance_info(void);
        plhs[0] = sf_c18_EKF_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EKF_get_eml_resolved_functions_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray *sf_c16_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray *sf_c17_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray *sf_c18_EKF_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_EKF_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void EKF_debug_initialize(void)
{
  _EKFMachineNumber_ = sf_debug_initialize_machine("EKF","sfun",0,12,0,0,0);
  sf_debug_set_machine_event_thresholds(_EKFMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_EKFMachineNumber_,0);
}

void EKF_register_exported_symbols(SimStruct* S)
{
}
