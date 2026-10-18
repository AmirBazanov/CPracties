#include <assert.h>
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  return ((x & ~(~(~0u << n) << (p + 1 - n))) | (y & ~(~0u << n))
                                                    << (p + 1 - n));
}

int main() {
  assert(setbits(181, 4, 3, 6) == 185);
  assert(setbits(0, 0, 1, 1) == 1);                 /* set lowest bit, x=0 */
  assert(setbits(10, 0, 1, 1) == 11);                /* set lowest bit, x!=0 */
  assert(setbits(4294967295u, 3, 4, 5) == 4294967285u); /* shift=0: overwrite low nibble */
  assert(setbits(0, 15, 4, 15) == 61440);            /* set nibble in the middle, x=0 */
  assert(setbits(4294967295u, 15, 4, 0) == 4294905855u); /* clear nibble in the middle */
  assert(setbits(0, 30, 5, 31) == 2080374784u);      /* bits near the top */
  assert(setbits(0, 31, 1, 1) == 2147483648u);       /* set top bit only */
  assert(setbits(4294967295u, 31, 1, 0) == 2147483647u); /* clear top bit only */
  assert(setbits(305419896, 10, 0, 4294967295u) == 305419896); /* n=0: x unchanged */
  assert(setbits(2863311530u, 7, 8, 255) == 2863311615u); /* overwrite byte with 1s */
  assert(setbits(0, 7, 8, 255) == 255);              /* overwrite byte with 1s from 0 */
  assert(setbits(4278255360u, 23, 8, 171) == 4289462016u); /* overwrite a byte in mixed pattern */
  assert(setbits(1, 31, 31, 2147483647u) == 4294967295u); /* shift=1, 31-bit mask */
  assert(setbits(123456789, 20, 10, 987654321u) == 121998613u); /* arbitrary large mix */
}
