#include <stdio.h>
#define N 4
#define LIM 1000
int main() {
  char string[LIM];
  char tabLesArr[LIM];
}

void replaseTabs(char from[], char to[]) {
  int j = 0;
  for (int i = 0; i < LIM; i++) {
    if (from[i] == '\t') {
      for (j = i; j <= i + N; j++) {
        to[j] = ' ';
      }
    }
    to[j++] = from[i];
  }
}
