#include <stdio.h>
#define IN 1;
#define OUT 0;

int main() {
  int c, i, wl, state, wc;
  state = OUT;
  int digits[10];
  for (i = 0; i < 10; i++) {
    digits[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n') {
      state = OUT;
      digits[wc] = wl;
      ++wc;
      wl = 0;
    } else if (!state) {
      state = IN;
    }
    if (state) {
      ++wl;
    }
  }
  for (i = 0; i < 10; i++) {
    for (int j = 0; j < digits[i]; j++) {
      putchar('-');
      putchar('\n');
    }
  }
}
