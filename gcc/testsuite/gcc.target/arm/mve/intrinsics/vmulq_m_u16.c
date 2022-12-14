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
**	vmult.i16	q[0-9]+, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint16x8_t
foo (uint16x8_t inactive, uint16x8_t a, uint16x8_t b, mve_pred16_t p)
{
  return vmulq_m_u16 (inactive, a, b, p);
}


/*
**foo1:
**	...
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vmult.i16	q[0-9]+, q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint16x8_t
foo1 (uint16x8_t inactive, uint16x8_t a, uint16x8_t b, mve_pred16_t p)
{
  return vmulq_m (inactive, a, b, p);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */