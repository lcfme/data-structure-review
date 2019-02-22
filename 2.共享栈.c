#include <stdlib.h>
#define max_size 100

typedef struct
{
  int data[max_size];
  int top[2];
} ShareStack;

ShareStack *sharestack_new()
{
  ShareStack *ss = (ShareStack *)malloc(sizeof(ShareStack));
  ss->top[0] = -1;
  ss->top[1] = max_size;
  return ss;
}

int push(ShareStack *ss, int no, int x)
{
  if (ss->top[0] + 1 == ss->top[1])
  {
    return 0;
  }
  if (no == 0)
  {
    ss->data[++ss->top[no]] = x;
  }
  else
  {
    ss->data[--ss->top[no]] = x;
  }
  return 1;
}

int pop(ShareStack *ss, int no, int *elem)
{
  if (no == 0)
  {
    if (ss->top[no] == -1)
    {
      return 0;
    }
    *elem = ss->data[ss->top[no]--];
    return 1;
  }
  if (ss->top[no] == max_size)
  {
    return 0;
  }
  *elem = ss->data[ss->top[no]++];
  return 1;
}