#include <stdio.h>
#include <stdlib.h>
#define max_size 100

typedef struct
{
  int data[max_size];
  int top;
} SqStack;

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode;

// 顺序队列
typedef struct
{
  int data[max_size];
  int front;
  int rear;
} SqQueue;

// 链表队列
// 节点定义
typedef struct QNode
{
  int data;
  struct QNode *next;
} QNode;

// 链队定义
typedef struct
{
  QNode *front;
  QNode *rear;
} LQueue;

// 创建一个栈 SqStack
SqStack *createSqStack()
{
  SqStack *stack = (SqStack *)malloc(sizeof(SqStack));
  stack->top = -1;
  return stack;
}

// 判断栈为空
int isEmpty(SqStack *stack)
{
  if (stack->top == -1)
  {
    return 1;
  }
  return 0;
}

// 进栈代码
int push(SqStack *stack, int x)
{
  if (stack->top == max_size - 1)
    return 0;
  stack->data[++stack->top] = x;
  return 1;
}

// 出栈代码
int pop(SqStack *stack, int *x)
{
  if (stack->top == -1)
    return 0;
  *x = stack->data[stack->top--];
  return 1;
}

// 链栈实现
typedef struct LStack
{
  LNode *top;
} LStack;

void LStack_push(LStack *lstack, int num)
{
  LNode *top = lstack->top;
  LNode *n = (LNode *)malloc(sizeof(LNode));
  n->data = num;
  n->next = top;
  lstack->top = n;
}

void LStack_pop(LStack *lstack)
{
  LNode *top = lstack->top;
  lstack->top = top->next;
  free(top);
}
