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
**	vaddvat.s16	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
int32_t
foo (int32_t a, int16x8_t b, mve_pred16_t p)
{
  return vaddvaq_p_s16 (a, b, p);
}


/*
**foo1:
**	...
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vaddvat.s16	(?:ip|fp|r[0-9]+), q[0-9]+(?:	@.*|)
**	...
*/
int32_t
foo1 (int32_t a, int16x8_t b, mve_pred16_t p)
{
  return vaddvaq_p (a, b, p);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */