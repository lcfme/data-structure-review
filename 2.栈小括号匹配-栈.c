#include <stdlib.h>
#include <stdio.h>

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode;

typedef struct
{
  LNode *top;
} LStack;

LStack *lstack_create()
{
  LStack *ls = (LStack *)malloc(sizeof(LStack));
  ls->top = 0;
  return ls;
}

void lstack_push(LStack *ls, int x)
{
  LNode *n = (LNode *)malloc(sizeof(LNode));
  n->next = ls->top;
  ls->top = n;
}

void lstack_pop(LStack *ls)
{
  LNode *top = ls->top;
  ls->top = ls->top->next;
  free(top);
}

int match(char exp[])
{
  LStack *ls = lstack_create();
  int i = 0;
  while (exp[i] != '\0')
  {
    if (exp[i] == '(')
    {
      lstack_push(ls, (int)exp[i]);
    }
    if (exp[i] == ')')
    {
      if (ls->top == 0)
      {
        return 0;
      }
      else
      {
        lstack_pop(ls);
      }
    }
    ++i;
  }
  if (ls->top == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  printf("%d", match("(ad(f))"));
}