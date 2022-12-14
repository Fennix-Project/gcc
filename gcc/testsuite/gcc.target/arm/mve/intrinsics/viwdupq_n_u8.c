/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	viwdup.u8	q[0-9]+, (?:ip|fp|r[0-9]+), (?:ip|fp|r[0-9]+), #[0-9]+(?:	@.*|)
**	...
*/
uint8x16_t
foo (uint32_t a, uint32_t b)
{
  return viwdupq_n_u8 (a, b, 1);
}


/*
**foo1:
**	...
**	viwdup.u8	q[0-9]+, (?:ip|fp|r[0-9]+), (?:ip|fp|r[0-9]+), #[0-9]+(?:	@.*|)
**	...
*/
uint8x16_t
foo1 (uint32_t a, uint32_t b)
{
  return viwdupq_u8 (a, b, 1);
}

/*
**foo2:
**	...
**	viwdup.u8	q[0-9]+, (?:ip|fp|r[0-9]+), (?:ip|fp|r[0-9]+), #[0-9]+(?:	@.*|)
**	...
*/
uint8x16_t
foo2 ()
{
  return viwdupq_u8 (1, 1, 1);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */