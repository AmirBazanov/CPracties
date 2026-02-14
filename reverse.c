
#include <stdio.h>
#define MAXLINE 1000

int getLine(char linef[], int max);
void copy(char to[], char from[]);
void reverse(char s[], char r[], int len);
int main() {
  int len;
  int max;
  char line[MAXLINE];
  char rev[MAXLINE];
  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0) {

    reverse(line, rev, len);
    printf("%s", rev);
  }
  return 0;
}

int getLine(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void reverse(char s[], char r[], int len) {
  int c = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (s[i] == '\0') {
      r[c] = ' ';
      c++;
      break;
    }
    r[c] = s[i];
    c++;
  }
  r[c] = '\0';
}
