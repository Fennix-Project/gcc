/* { dg-require-effective-target arm_v8_1m_mve_fp_ok } */
/* { dg-add-options arm_v8_1m_mve_fp } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vmul.f32	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
float32x4_t
foo (float32x4_t a, float32_t b)
{
  return vmulq_n_f32 (a, b);
}


/*
**foo1:
**	...
**	vmul.f32	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
float32x4_t
foo1 (float32x4_t a, float32_t b)
{
  return vmulq (a, b);
}

/*
**foo2:
**	...
**	vmul.f32	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
float32x4_t
foo2 (float32x4_t a)
{
  return vmulq (a, 1.1);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */