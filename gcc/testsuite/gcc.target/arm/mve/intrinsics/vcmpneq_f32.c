/* { dg-require-effective-target arm_v8_1m_mve_fp_ok } */
/* { dg-add-options arm_v8_1m_mve_fp } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vcmp.f32	ne, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
**	vmrs	(?:ip|fp|r[0-9]+), p0(?:	@.*|)
**	...
*/
mve_pred16_t
foo (float32x4_t a, float32x4_t b)
{
  return vcmpneq_f32 (a, b);
}


/*
**foo1:
**	...
**	vcmp.f32	ne, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
**	vmrs	(?:ip|fp|r[0-9]+), p0(?:	@.*|)
**	...
*/
mve_pred16_t
foo1 (float32x4_t a, float32x4_t b)
{
  return vcmpneq (a, b);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */