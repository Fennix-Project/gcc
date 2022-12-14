/* { dg-do run } */
/* { dg-options "-O -fdump-tree-phiopt" } */

#include <stdint.h>

__attribute__ ((noipa, noinline))
uint8_t three_minmax2 (uint8_t xc, uint8_t xm, uint8_t xy) {
	uint8_t	 xk;
    xc=~xc;
    xm=~xm;
    xy=~xy;
    if (xc > xm) {
        xk = (uint8_t) (xc > xy ? xc : xy);
    } else {
        xk = (uint8_t) (xm < xy ? xm : xy);
    }
    return xk;
}

int
main (void)
{
  volatile uint8_t xy = 255;
  volatile uint8_t xm = 127;
  volatile uint8_t xc = 0;
  if (three_minmax2 (xc, xm, xy) != 255)
    __builtin_abort ();
  return 0;
}

/* { dg-final { scan-tree-dump-times "MIN_EXPR" 1 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times "MAX_EXPR" 1 "phiopt1" } } */
