/* { dg-require-effective-target arm_v8_1m_mve_fp_ok } */
/* { dg-add-options arm_v8_1m_mve_fp } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vdup.16	q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
float16x8_t
foo (float16_t a)
{
  return vdupq_n_f16 (a);
}

/*
**foo1:
**	...
**	vdup.16	q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
float16x8_t
foo1 ()
{
  return vdupq_n_f16 (1.1);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */