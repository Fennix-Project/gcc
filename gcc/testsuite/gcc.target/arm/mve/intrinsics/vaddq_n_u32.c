/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

/*
**foo:
**	...
**	vadd.i32	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
uint32x4_t
foo (uint32x4_t a, uint32_t b)
{
  return vaddq_n_u32 (a, b);
}


/*
**foo1:
**	...
**	vadd.i32	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
uint32x4_t
foo1 (uint32x4_t a, uint32_t b)
{
  return vaddq (a, b);
}

/*
**foo2:
**	...
**	vadd.i32	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
uint32x4_t
foo2 (uint32x4_t a)
{
  return vaddq (a, 1);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */