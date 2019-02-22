#include <stdlib.h>

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode;

typedef struct LQueue
{
  LNode *rear;
  LNode *front;
} LQueue;

LQueue *lqueue_new()
{
  LQueue *lq = (LQueue *)malloc(sizeof(LQueue));
  lq->rear = lq->front = 0;
  return lq;
}

int lqueue_is_empty(LQueue *lq)
{
  return lq->rear == 0 || lq->front == 0;
}

void lqueue_enqueue(LQueue *lq, int x)
{
  LNode *n = (LNode *)malloc(sizeof(LNode));
  n->data = x;
  n->next = 0;
  if (lq->rear == 0)
  {
    lq->rear = n;
    lq->front = n;
  }
  else
  {
    lq->rear->next = n;
    lq->rear = n;
  }
}

void lqueue_dequeue(LQueue *lq, int *elem)
{
  LNode *n = lq->front;
  if (n == 0)
  {
    return 0;
  }
  if (lq->rear == lq->front)
  {
    lq->front = lq->rear = 0;
  }
  else
  {
    lq->front = lq->front->next;
  }
  free(n);
}
