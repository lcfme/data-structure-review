// 不得不说，这是种傻逼至极的操作，但是也没办法需要实现

#include <stdlib.h>

typedef struct
{
  int max_size;
  int top;
} ST;

void push(ST *st, int x);
void pop(ST *st, int *x);
int isEmpty(ST *st);

int enQueue(ST *s1, ST *s2, int x)
{
  if (s1->top < s1->max_size - 1)
  {
    push(s1, x);
    return 1;
  }
  if (!isEmpty(s2))
  {
    return 0;
  }
  while (!isEmpty(s1))
  {
    int x;
    pop(s1, &x);
    push(s2, x);
  }
  return 1;
}

int deQueue(ST *st1, ST *st2, int *x)
{
  if (!isEmpty(st2))
  {
    pop(st2, x);
    return 1;
  }
  if (isEmpty(st1))
  {
    return 0;
  }
  while (!isEmpty(st1))
  {
    int temp;
    pop(st1, &temp);
    push(st2, temp);
  }
  pop(st2, x);
  return 1;
}

int isQueueEmpty(ST *st1, ST *st2)
{
  return isEmpty(st1) && isEmpty(st2);
}