/*
 * File: bus_test.h
 *
 * Code generated for Simulink model 'bus_test'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Jun 30 21:04:25 2021
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_bus_test_h_
#define RTW_HEADER_bus_test_h_
#include "rtwtypes.h"
#include <string.h>
#ifndef bus_test_COMMON_INCLUDES_
# define bus_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* bus_test_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */

/* Forward declaration for rtModel */
typedef struct tag_RTM_bus_test RT_MODEL_bus_test;

#ifndef DEFINED_TYPEDEF_FOR_bus_test_Para_t_
#define DEFINED_TYPEDEF_FOR_bus_test_Para_t_

typedef struct {
  uint32_T ts;
  uint32_T Para1;
  uint16_T Para2;
} bus_test_Para_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_bus_test_Diag_t_
#define DEFINED_TYPEDEF_FOR_bus_test_Diag_t_

typedef struct {
  int32_T Diag1;
  uint16_T Diag2;
} bus_test_Diag_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_bus_test_In_t_
#define DEFINED_TYPEDEF_FOR_bus_test_In_t_

typedef struct {
  int32_T In1;
  uint16_T In2;
} bus_test_In_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_bus_test_Out_t_
#define DEFINED_TYPEDEF_FOR_bus_test_Out_t_

typedef struct {
  int32_T Out1;
  uint16_T Out2;
} bus_test_Out_t;

#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  bus_test_Diag_t d;                   /* '<Root>/Data Store Memory' */
  int32_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
} D_Work_bus_test;

/* instance parameters, for system '<Root>' */
typedef struct {
  bus_test_Para_t p;                   /* Variable: p
                                        * Referenced by:
                                        *   '<Root>/Constant4'
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain2'
                                        */
} InstP_bus_test;

/* External inputs (root inport signals with default storage) */
typedef struct {
  bus_test_In_t U;                     /* '<Root>/U' */
} ExternalInputs_bus_test;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  bus_test_Out_t Y;                    /* '<Root>/Y' */
  bus_test_Diag_t D;                   /* '<Root>/D' */
} ExternalOutputs_bus_test;

/* Real-time Model Data Structure */
struct tag_RTM_bus_test {
  D_Work_bus_test *dwork;
  InstP_bus_test *bus_test_InstP_ref;
};

/* Model entry point functions */
extern void bus_test_initialize(RT_MODEL_bus_test *const bus_test_M);
extern void bus_test_step(RT_MODEL_bus_test *const bus_test_M,
  ExternalInputs_bus_test *bus_test_U, ExternalOutputs_bus_test *bus_test_Y);
extern void bus_test_terminate(RT_MODEL_bus_test *const bus_test_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'bus_test'
 */
#endif                                 /* RTW_HEADER_bus_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
