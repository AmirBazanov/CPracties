#include <stdio.h>
#define MAXLINE 1000 /* максимальный размер вводимой строки */
int getLine(char line[], int len);
void copy(char to[], char from[]);
/* печать самой длинной строки */
int main() {
  int len;               /* длина текущей строки */
  int max;               /* длина максимальной из просмотренных строк */
  char line[MAXLINE];    /* текущая строка */
  char longest[MAXLINE]; /* самая длинная строка */
  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) /* была ли хоть одна строка? */
    printf("%s", longest);
  return 0;
}
/* getLine: читает строку в s, возвращает длину */
int getLine(char s[], int lim) {
  int c, i, j;
  j = i = 0;
  while ((c = getchar()) != EOF && c != '\n') {
    if (i < lim - 1) {
      s[i] = c;
      ++i;
    }
    ++j;
  }
  if (i < lim) {
    s[i] = '\0';
  }
  if (c == '\n') {
    ++j;
  }
  if (j >= 100) {
    printf("%s", s);
  }
  return j;
}
/* copy: копирует из 'from' в 'to'; to достаточно большой */
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
