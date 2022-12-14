/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vqdmullb.s16	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
int32x4_t
foo (int16x8_t a, int16_t b)
{
  return vqdmullbq_n_s16 (a, b);
}


/*
**foo1:
**	...
**	vqdmullb.s16	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
int32x4_t
foo1 (int16x8_t a, int16_t b)
{
  return vqdmullbq (a, b);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */