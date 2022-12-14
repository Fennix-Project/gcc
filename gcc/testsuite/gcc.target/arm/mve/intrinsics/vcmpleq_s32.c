/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vcmp.s32	le, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
**	vmrs	(?:ip|fp|r[0-9]+), p0(?:	@.*|)
**	...
*/
mve_pred16_t
foo (int32x4_t a, int32x4_t b)
{
  return vcmpleq_s32 (a, b);
}


/*
**foo1:
**	...
**	vcmp.s32	le, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
**	vmrs	(?:ip|fp|r[0-9]+), p0(?:	@.*|)
**	...
*/
mve_pred16_t
foo1 (int32x4_t a, int32x4_t b)
{
  return vcmpleq (a, b);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */