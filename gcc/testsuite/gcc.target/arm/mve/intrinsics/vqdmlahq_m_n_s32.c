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
**	vqdmlaht.s32	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
int32x4_t
foo (int32x4_t add, int32x4_t m1, int32_t m2, mve_pred16_t p)
{
  return vqdmlahq_m_n_s32 (add, m1, m2, p);
}


/*
**foo1:
**	...
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vqdmlaht.s32	q[0-9]+, q[0-9]+, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
*/
int32x4_t
foo1 (int32x4_t add, int32x4_t m1, int32_t m2, mve_pred16_t p)
{
  return vqdmlahq_m (add, m1, m2, p);
}

/* { dg-final { scan-assembler-not "__ARM_undef" } } */