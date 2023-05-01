/*
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>              /* This ert_main.c example uses printf/fflush */
#include "bus_test.h"                  /* Model's header file */
#include "rtwtypes.h"

static RT_MODEL_bus_test bus_test_M_;
static RT_MODEL_bus_test *const bus_test_MPtr = &bus_test_M_;/* Real-time model */
static D_Work_bus_test bus_test_DWork; /* Observable states */

/* instance parameters */
static InstP_bus_test bus_test_InstP = {
  /* Variable: p
   * Referenced by:
   *   '<Root>/Constant4'
   *   '<Root>/Gain1'
   *   '<Root>/Gain2'
   */
  {
    20U,
    2U,
    4U
  }
};                                     /* Referenced by:
                                        * '<Root>/Constant4'
                                        * '<Root>/Gain1'
                                        * '<Root>/Gain2'
                                        */

static ExternalInputs_bus_test bus_test_U;/* External inputs */
static ExternalOutputs_bus_test bus_test_Y;/* External outputs */

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL_bus_test *const bus_test_M);
void rt_OneStep(RT_MODEL_bus_test *const bus_test_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  bus_test_step(bus_test_M, &bus_test_U, &bus_test_Y);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_bus_test *const bus_test_M = bus_test_MPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  bus_test_M->dwork = &bus_test_DWork;
  bus_test_M->bus_test_InstP_ref = &bus_test_InstP;

  /* Initialize model */
  bus_test_initialize(bus_test_M);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.001 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(bus_test_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (1) {
    /*  Perform other application tasks here */
  }

  /* The option 'Remove error status field in real-time model data structure'
   * is selected, therefore the following code does not need to execute.
   */
#if 0

  /* Disable rt_OneStep() here */

  /* Terminate model */
  bus_test_terminate(bus_test_M);

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
