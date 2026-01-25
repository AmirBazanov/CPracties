#include <stdio.h>

#define MAXSTACK 1000

#define NORMAL 0
#define IN_STR 1
#define IN_CHAR 2
#define IN_COMM 3

int main(void) {
  int c, prev = 0;
  int state = NORMAL;

  char stack[MAXSTACK];
  int sp = 0; 

  while ((c = getchar()) != EOF) {

    if (state == IN_COMM) {
      if (prev == '*' && c == '/') {
        state = NORMAL;
        prev = 0;
      }
      prev = c;
      continue;
    }

    if (state == IN_STR) {
      if (c == '"' && prev != '\\') {
        state = NORMAL;
      }
      prev = c;
      continue;
    }

    if (state == IN_CHAR) {
      if (c == '\'' && prev != '\\') {
        state = NORMAL;
      }
      prev = c;
      continue;
    }


   
    if (prev == '/' && c == '*'){
      state = IN_COMM;
      prev = 0;
      continue;
    }

    if (c == '"' && prev != '\\'){
      state = IN_STR;
      prev = c;
      continue;
    }

       
    if (c == '\''){
      state = IN_CHAR;
      prev = c;
      continue;
    }

    if (c == '(' || c == '[' || c=='{'){
      if (sp < MAXSTACK){
        stack[sp++] = c;
      }
      else{
        printf("Stack overflow\n");
        return 1;
      }
    }

      
    if (c == ')'||c==']'||c=='}'){
      if (sp == 0){
        printf("Excess symbol: %c\n", c);
        return 1;
      }

      char open = stack[--sp];
      switch (c) {
        case ')':
          if (open != '('){
            printf("Symbol dont match: %c\n", c);
            return 1;
          }
          break;

        case ']':
          if (open != '['){
            printf("Symbol dont match: %c\n", c);
            return 1;
          }
          break;
        case '}':
          if (open != '{'){
            printf("Symbol dont match: %c\n", c);
            return 1;
          }
          break;
      }
    }
      prev = c;
  }


    if (state != NORMAL){
    printf("State isnt NORMAL");
    return 1;
  }

  if (sp != 0){
    printf("Unclosed braceds");
    return 1;
  }

  return 0;
}
