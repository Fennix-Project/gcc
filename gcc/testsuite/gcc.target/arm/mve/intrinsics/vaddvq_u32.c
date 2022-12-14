/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vaddv.u32	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
uint32_t
foo (uint32x4_t a)
{
  return vaddvq_u32 (a);
}


/*
**foo1:
**	...
**	vaddv.u32	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
uint32_t
foo1 (uint32x4_t a)
{
  return vaddvq (a);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */