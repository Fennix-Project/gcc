/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vcmp.s16	lt, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vmrs	(?:ip|fp|r[0-9]+), p0(?:	@.*|)
**	...
*/
mve_pred16_t
foo (int16x8_t a, int16_t b)
{
  return vcmpltq_n_s16 (a, b);
}


/*
**foo1:
**	...
**	vcmp.s16	lt, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vmrs	(?:ip|fp|r[0-9]+), p0(?:	@.*|)
**	...
*/
mve_pred16_t
foo1 (int16x8_t a, int16_t b)
{
  return vcmpltq (a, b);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */