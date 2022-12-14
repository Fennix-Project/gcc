/* { dg-require-effective-target arm_v8_1m_mve_fp_ok } */
/* { dg-add-options arm_v8_1m_mve_fp } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vmaxnmvt.f32	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
float32_t
foo (float32_t a, float32x4_t b, mve_pred16_t p)
{
  return vmaxnmvq_p_f32 (a, b, p);
}


/*
**foo1:
**	...
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vmaxnmvt.f32	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
float32_t
foo1 (float32_t a, float32x4_t b, mve_pred16_t p)
{
  return vmaxnmvq_p (a, b, p);
}

/*
**foo2:
**	...
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vmaxnmvt.f32	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
float32_t
foo2 (float32x4_t b, mve_pred16_t p)
{
  return vmaxnmvq_p (1.1, b, p);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */