#include <stdlib.h>
#define max_size 100

// rear和front是反的。。蛋疼
typedef struct SqQueue
{
  int data[max_size];
  int rear;
  int front;
} SqQueue;

SqQueue *sq_queue_new()
{
  SqQueue *sq = (SqQueue *)malloc(sizeof(SqQueue));
  sq->front = 0;
  sq->rear = 0;
  return sq;
}

int sq_queue_is_empty(SqQueue *sq)
{
  return sq->front == sq->rear;
}

int sq_queue_is_full(SqQueue *sq)
{
  int nf = sq->front + 1;
  if (nf >= max_size)
  {
    nf = nf - max_size;
  }
  return nf == sq->rear;
}

int sq_queue_enque(SqQueue *sq, int x)
{
  if (sq_queue_is_full(sq))
  {
    return 0;
  }
  int nf = sq->front + 1;
  if (nf >= max_size)
  {
    nf = nf - max_size;
  }
  sq->data[nf] = x;
  return 1;
}

int sq_queue_dequeue(SqQueue *sq, int *x)
{
  if (sq_queue_is_empty(sq))
  {
    return 0;
  }
  int nr = sq->rear + 1;
  if (nr >= max_size)
  {
    nr = nr - max_size;
  }
  sq->rear = nr;
  *x = sq->data[sq->rear];
  return 1;
}
