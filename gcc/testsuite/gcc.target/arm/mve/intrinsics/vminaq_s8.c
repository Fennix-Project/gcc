/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vmina.s8	q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint8x16_t
foo (uint8x16_t a, int8x16_t b)
{
  return vminaq_s8 (a, b);
}


/*
**foo1:
**	...
**	vmina.s8	q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint8x16_t
foo1 (uint8x16_t a, int8x16_t b)
{
  return vminaq (a, b);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */