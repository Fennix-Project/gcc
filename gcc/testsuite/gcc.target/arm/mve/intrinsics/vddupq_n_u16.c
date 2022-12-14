/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vddup.u16	q[0-9]+, (?:ip|fp|r[0-9]+), #[0-9]+(?:	@.*|)
**	...
*/
uint16x8_t
foo (uint32_t a)
{
  return vddupq_n_u16 (a, 1);
}


/*
**foo1:
**	...
**	vddup.u16	q[0-9]+, (?:ip|fp|r[0-9]+), #[0-9]+(?:	@.*|)
**	...
*/
uint16x8_t
foo1 (uint32_t a)
{
  return vddupq_u16 (a, 1);
}

/*
**foo2:
**	...
**	vddup.u16	q[0-9]+, (?:ip|fp|r[0-9]+), #[0-9]+(?:	@.*|)
**	...
*/
uint16x8_t
foo2 ()
{
  return vddupq_u16 (1, 1);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */