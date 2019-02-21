// abcd*++e/
#include <stdlib.h>

int calc(char op, int a, int b, int *r)
{
  switch (op)
  {
  case '+':
    *r = a + b;
    return 1;
  case '-':
    *r = a - b;
    return 1;
  case '*':
    *r = a * b;
    return 1;
  case '/':
    if (b == 0)
    {
      return 0;
    }
    *r = a / b;
    return 1;
  default:
    return 0;
  }
}

int is_number(char ch)
{
  return ch != 0 && ch >= '0' && ch <= '9' && ch;
}

int eval(char *exp)
{
  int i = 0;
  int stack[100];
  int top = -1;
  while (*(exp + i) != '\0')
  {
    char ch = *(exp + i);
    if (is_number(ch))
    {
      stack[++top] = atoi(&ch);
    }
    else
    {
      char op = ch;
      int b = stack[top--];
      int a = stack[top--];
      int r;
      int err = p(op, b, a, &r);
      stack[++top] = r;
    }
    ++i;
  }
  return stack[top];
}