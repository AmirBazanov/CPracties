#include <ctype.h>
#define SIZE 100
#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE]; /* буфер для ungetch */
int bufp = 0;      /* след, свободная позиция в буфере */
int getch(void)    /* взять (возможно возвращенный) символ */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* вернуть символ на ввод */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: слишком много символов\n");
  else
    buf[bufp++] = c;
}

/* getint: читает cледующее целое из ввода в *pn */
int getint(int *pn) {
  int c, sign;
  while (isspace(c = getch()))
    ; /* пропуcк cимволов-разделителей */
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* не чиcло */
    return 0;
  }
  if (c == EOF) {
    return c;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    int signt = c;
    c = getch();
    if (!isdigit(c)) {
      ungetch(c);
      ungetch(signt);
      return 0;
    }
  }

  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  else
    return 1;
  return c;
}

int main(void) {
  int arr[SIZE], n = 0, r;
  while (n < SIZE && (r = getint(&arr[n])) != EOF) {
    if (r > 0) {
      n++;
    } else {
      getch();
    }
  }
  for (int i = 0; i < n; i++)
    printf("%d\n", arr[i]);

  return 0;
}
