
#include <stdio.h>

#define N 8      // количество пробелов для таба
#define LIM 1000 // максимальный размер исходной строки

void getLine(char line[]);
void replaceTabs(char from[], char to[]);

int main() {
  char string[LIM] = {0};
  char tabLessArr[LIM * N] = {0}; // буфер больше, чтобы вместить все пробелы

  getLine(string);
  replaceTabs(string, tabLessArr);

  // выводим строку до конца '\0'
  for (int i = 0; tabLessArr[i] != '\0'; i++) {
    putchar(tabLessArr[i]);
  }

  return 0;
}

void getLine(char s[]) {
  int c, i;
  for (i = 0; i < LIM - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
}

void replaceTabs(char from[], char to[]) {
  int i, j = 0;

  for (i = 0; from[i] != '\0'; i++) {
    if (from[i] == '\t') {
      // вставляем N пробелов
      for (int a = 0; a < N; a++) {
        to[j++] = ' ';
      }
    } else {
      to[j++] = from[i];
    }
  }

  to[j] = '\0';
}
