/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vminv.s32	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
int32_t
foo (int32_t a, int32x4_t b)
{
  return vminvq_s32 (a, b);
}


/*
**foo1:
**	...
**	vminv.s32	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
int32_t
foo1 (int32_t a, int32x4_t b)
{
  return vminvq (a, b);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */