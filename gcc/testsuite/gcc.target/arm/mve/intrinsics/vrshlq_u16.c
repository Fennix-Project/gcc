/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vrshl.u16	q[0-9]+, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint16x8_t
foo (uint16x8_t a, int16x8_t b)
{
  return vrshlq_u16 (a, b);
}


/*
**foo1:
**	...
**	vrshl.u16	q[0-9]+, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint16x8_t
foo1 (uint16x8_t a, int16x8_t b)
{
  return vrshlq (a, b);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */