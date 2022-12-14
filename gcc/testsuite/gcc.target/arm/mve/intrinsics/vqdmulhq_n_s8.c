/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vqdmulh.s8	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
int8x16_t
foo (int8x16_t a, int8_t b)
{
  return vqdmulhq_n_s8 (a, b);
}


/*
**foo1:
**	...
**	vqdmulh.s8	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
int8x16_t
foo1 (int8x16_t a, int8_t b)
{
  return vqdmulhq (a, b);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */