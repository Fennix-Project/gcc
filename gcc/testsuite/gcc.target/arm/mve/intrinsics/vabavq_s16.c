/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vabav.s16	(?:ip|fp|r[0-9]+), q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint32_t
foo (uint32_t a, int16x8_t b, int16x8_t c)
{
  return vabavq_s16 (a, b, c);
}


/*
**foo1:
**	...
**	vabav.s16	(?:ip|fp|r[0-9]+), q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint32_t
foo1 (uint32_t a, int16x8_t b, int16x8_t c)
{
  return vabavq (a, b, c);
}

/*
**foo2:
**	...
**	vabav.s16	(?:ip|fp|r[0-9]+), q[0-9]+, q[0-9]+(?:	@.*|)
**	...
*/
uint32_t
foo2 (int16x8_t b, int16x8_t c)
{
  return vabavq (1, b, c);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */