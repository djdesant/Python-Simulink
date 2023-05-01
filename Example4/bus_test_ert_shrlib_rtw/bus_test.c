/*
 * File: bus_test.c
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

#include "bus_test.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

static void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
static int32_T mul_s32_hiSR(int32_T a, int32_T b, uint32_T aShift);

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

static void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  absIn1 = in1 < 0 ? ~(uint32_T)in1 + 1U : (uint32_T)in1;
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << 16U) + absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += productHiLo << 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if ((in0 != 0) && ((in1 != 0) && ((in0 > 0) != (in1 > 0)))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

static int32_T mul_s32_hiSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  return (int32_T)u32_chi >> aShift;
}

/* Model step function */
void bus_test_step(RT_MODEL_bus_test *const bus_test_M, ExternalInputs_bus_test *
                   bus_test_U, ExternalOutputs_bus_test *bus_test_Y)
{
  D_Work_bus_test *bus_test_DWork = ((D_Work_bus_test *) bus_test_M->dwork);
  InstP_bus_test *bus_test_InstP = bus_test_M->bus_test_InstP_ref;
  uint16_T rtb_Out2;

  /* Gain: '<Root>/Gain2' incorporates:
   *  Inport: '<Root>/U'
   */
  rtb_Out2 = (uint16_T)((uint32_T)bus_test_InstP->p.Para2 * bus_test_U->U.In2);

  /* BusCreator: '<Root>/Bus Creator1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write'
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   */
  bus_test_DWork->d.Diag1 = bus_test_DWork->DiscreteTimeIntegrator_DSTATE;
  bus_test_DWork->d.Diag2 = rtb_Out2;

  /* Outport: '<Root>/Y' incorporates:
   *  BusCreator: '<Root>/Bus Creator'
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   */
  bus_test_Y->Y.Out1 = bus_test_DWork->DiscreteTimeIntegrator_DSTATE;
  bus_test_Y->Y.Out2 = rtb_Out2;

  /* Outport: '<Root>/D' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read1'
   */
  bus_test_Y->D = bus_test_DWork->d;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Gain: '<Root>/Gain1'
   *  Inport: '<Root>/U'
   *  Product: '<Root>/Product1'
   */
  bus_test_DWork->DiscreteTimeIntegrator_DSTATE += mul_s32_hiSR(439804651,
    (int32_T)bus_test_InstP->p.Para1 * bus_test_U->U.In1 * (int32_T)
    bus_test_InstP->p.ts, 10U);
}

/* Model initialize function */
void bus_test_initialize(RT_MODEL_bus_test *const bus_test_M)
{
  D_Work_bus_test *bus_test_DWork = ((D_Work_bus_test *) bus_test_M->dwork);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)bus_test_DWork, 0,
                sizeof(D_Work_bus_test));
}

/* Model terminate function */
void bus_test_terminate(RT_MODEL_bus_test *const bus_test_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(bus_test_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
