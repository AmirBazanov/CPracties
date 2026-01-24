#include <stdio.h>
#define N 4
#define LIM 1000
void getLine(char line[]);
void replaseTabs(char f[], char t[]);
int main() {
  char string[LIM];
  char tabLesArr[LIM];
  getLine(string);
  replaseTabs(string, tabLesArr);
  for (int i = 0; i < LIM - 1; i++) {
    putchar(tabLesArr[i]);
  }
}

void getLine(char s[]) {
  int c, i;
  for (i = 0; i < LIM - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == 'n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
}

void replaseTabs(char from[], char to[]) {
  int j = 0;
  for (int i = 0; i < LIM - 1; i++) {
    if (from[i] == '\t') {
      for (j = i; j <= i + N || (i + N) > LIM; j++) {
        to[j] = ' ';
      }
    }
    if (j < LIM - 1) {

      to[j] = from[i];
      ++j;
    }
  }
}
