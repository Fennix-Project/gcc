/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vrshl.s32	q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
int32x4_t
foo (int32x4_t a, int32_t b)
{
  return vrshlq_n_s32 (a, b);
}


/*
**foo1:
**	...
**	vrshl.s32	q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
int32x4_t
foo1 (int32x4_t a, int32_t b)
{
  return vrshlq (a, b);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */