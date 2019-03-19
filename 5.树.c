#include <stdlib.h>
#include <stdio.h>
#define max_size 100

typedef struct BTNode
{
  char data;
  struct BTNode *lchild;
  struct BTNode *rchild;
} BTNode;

void Visit(BTNode *p) {}

void preorder(BTNode *p)
{
  if (p != NULL)
  {
    Visit(p);
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

void inorder(BTNode *p)
{
  if (p != NULL)
  {
    inorder(p->lchild);
    Visit(p);
    inorder(p->rchild);
  }
}

void postorder(BTNode *p)
{
  if (p != NULL)
  {
    postorder(p->lchild);
    postorder(p->rchild);
    Visit(p);
  }
}

void search(BTNode *btree, BTNode *r, int target)
{
  if (btree == 0 || r != 0)
    return;
  if (btree->data == target)
  {
    *r = *btree;
  }
  else
  {
    search(btree->lchild, r, target);
    search(btree->rchild, r, target);
  }
}

void level(BTNode *p)
{
  int front, rear;
  BTNode *que[max_size];
  front = rear = 0;
  BTNode *q;

  if (p != 0)
  {
    rear = (rear + 1) % max_size;
    que[rear] = p;
    while (front != rear)
    {
      front = (front + 1) / max_size;
      q = que[front];
      Visit(q);
      if (q->lchild)
      {
        rear = (rear + 1) % max_size;
        que[rear] = q->lchild;
      }
      if (q->rchild)
      {
        rear = (rear + 1) % max_size;
        que[rear] = q->rchild;
      }
    }
  }
}

typedef struct
{
  BTNode *p;
  int lno;
} St;

int maxNode(BTNode *b)
{
  if (b == 0)
  {
    return 0;
  }
  St que[max_size];
  BTNode *p;
  int rear, front = 0;
  int Lno;
  ++rear;
  que[rear].p = b;
  que[rear].lno = 1;
  while (front != rear)
  {
    ++front;
    p = que[front].p;
    Lno = que[front].lno;
    if (p->lchild)
    {
      rear++;
      que[rear].p = p->lchild;
      que[rear].lno = Lno + 1;
    }
    if (p->rchild)
    {
      rear++;
      que[rear].p = p->rchild;
      que[rear].lno = Lno + 1;
    }
  }
  int max = 0;
  for (int i = 1; i <= Lno; ++i)
  {
    int count = 0;
    for (int j = 1; j <= rear; ++j)
    {
      if (que[j].lno == i)
        ++count;
    }
    if (count > max)
    {
      max = count;
    }
  }
  return max;
}

void preorderNonrecursion(BTNode *bt)
{
  if (bt == 0)
  {
    return;
  }

  BTNode *Stack[max_size];
  int top = -1;
  BTNode *p;
  Stack[++top] = bt;

  while (top != -1)
  {
    p = Stack[top--];
    Visit(p);
    if (p->rchild != 0)
    {
      Stack[++top] = p->rchild;
    }
    if (p->rchild != 0)
    {
      Stack[++top] = p->lchild;
    }
  }
}

void inorderNonrecursion(BTNode *bt)
{
  if (bt == 0)
  {
    return;
  }
  BTNode *Stack[max_size];
  int top = -1;
  BTNode *p;
  p = bt;
  while (top != -1 || p != 0)
  {
    while (p != 0)
    {
      Stack[++top] = p;
      p = p->lchild;
    }
    if (top != -1)
    {
      p = Stack[top--];
      Visit(p);
      p = p->rchild;
    }
  }
}

void postorderNonRecursion(BTNode *bt)
{
  if (bt == 0)
  {
    return;
  }
  BTNode *Stack1[max_size];
  int top1 = -1;
  BTNode *Stack2[max_size];
  int top2 = -1;
  BTNode *p = 0;
  Stack1[++top1] = bt;
  while (top1 != -1)
  {
    p = Stack1[top1--];
    Stack2[++top2] = p;

    if (p->lchild != 0)
    {
      Stack1[++top1] = p->lchild;
    }
    if (p->rchild != 0)
    {
      Stack1[++top1] = p->rchild;
    }
  }

  while (top2 != -1)
  {
    p = Stack2[top2--];
    Visit(p);
  }
}