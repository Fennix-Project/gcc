/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vabd.s16	q[0-9]+, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
int16x8_t
foo (int16x8_t a, int16x8_t b)
{
  return vabdq_s16 (a, b);
}


/*
**foo1:
**	...
**	vabd.s16	q[0-9]+, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
int16x8_t
foo1 (int16x8_t a, int16x8_t b)
{
  return vabdq (a, b);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */