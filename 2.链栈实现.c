#include <stdlib.h>

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode;

typedef struct LStack
{
  LNode *top;
} LStack;

LStack *lstack_new()
{
  LStack *lstack = (LStack *)malloc(sizeof(LStack));
  lstack->top = 0;
  return lstack;
}

int lstack_is_empty(LStack *ls)
{
  return ls->top == 0;
}

void lstack_push(LStack *ls, int data)
{
  LNode *n = (LNode *)malloc(sizeof(LNode));
  n->data = data;
  n->next = ls->top;
  ls->top = n;
}

void lstack_pop(LStack *ls)
{
  LNode *top = ls->top;
  ls->top = ls->top->next;
  free(top);
}