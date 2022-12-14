/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
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
**	vaddvt.s16	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
int32_t
foo (int16x8_t a, mve_pred16_t p)
{
  return vaddvq_p_s16 (a, p);
}


/*
**foo1:
**	...
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vaddvt.s16	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
int32_t
foo1 (int16x8_t a, mve_pred16_t p)
{
  return vaddvq_p (a, p);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */