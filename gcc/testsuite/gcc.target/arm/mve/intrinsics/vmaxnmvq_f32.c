/* { dg-require-effective-target arm_v8_1m_mve_fp_ok } */
/* { dg-add-options arm_v8_1m_mve_fp } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vmaxnmv.f32	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
float32_t
foo (float32_t a, float32x4_t b)
{
  return vmaxnmvq_f32 (a, b);
}


/*
**foo1:
**	...
**	vmaxnmv.f32	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
float32_t
foo1 (float32_t a, float32x4_t b)
{
  return vmaxnmvq (a, b);
}

/*
**foo2:
**	...
**	vmaxnmv.f32	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
float32_t
foo2 (float32x4_t b)
{
  return vmaxnmvq (1.1, b);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */