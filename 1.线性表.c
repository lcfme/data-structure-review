// 顺序表
#define maxSize 100
#include <stdlib.h>

typedef struct
{
  int data[maxSize];
  int length;
} Sqlist;

// 单链表

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode;

// 双链表
typedef struct DLNode
{
  int data;
  struct DLNode *prior;
  struct DLNode *next;
} DLNode;

int insertElem(Sqlist *L, int p, int e)
{
  if (p < 0 || L->length + 1 > maxSize)
  {
    return 0;
  }
  if (p < L->length)
  {
    for (int i = L->length; i >= p; i--)
    {
      L->data[i + i] = L->data[i];
    }
  }
  L->data[p] = e;
  L->length++;
  return 1;
}

int deleteElem(Sqlist *L, int p, int *e)
{
  if (p < 0 || p > L->length - 1)
  {
    return 0;
  }
  *e = L->data[p];
  for (int i = p; i < L->length - 1; i++)
  {
    L->data[i] = L->data[i + 1];
  }
  L->length--;
  return 1;
}

int getElem(Sqlist *L, int p, int *e)
{
  if (p < 0 || p > L->length - 1)
  {
    return 0;
  }
  *e = L->data[p];
  return 1;
}

// void merge(LNode *A, LNode *B, LNode *C)
// {
//   LNode *p = A->next;
//   LNode *q = B->next;
//   LNode *r;
//   *C = *A;
//   C->next = 0;
//   free(B);
//   *r = *C;

//   while (p != 0 && q != 0)
//   {
//     if (p->data <= q->data)
//     {
//       r->next = p;
//       p = p->next;
//       r = r->next;
//     }
//     else
//     {
//       r->next = q;
//       q = q->next;
//       r = r->next;
//     }
//   }
//   r->next = 0;
//   if (p != 0)
//   {
//     r->next = p;
//   }
//   if (q != 0)
//   {
//     r->next = q;
//   }
// }

void merge(LNode *A, LNode *B, LNode *C)
{
  C->next = 0;
  A = A->next;
  B = B->next;

  while (A != 0 && B != 0)
  {
    if (A->data <= B->data)
    {
      C->next = B;
      B = B->next;
      C = C->next;
    }
    else
    {
      C->next = A;
      A = A->next;
      C = C->next;
    }
  }
  C->next = 0;

  if (A)
  {
    C->next = A;
  }
  if (B)
  {
    C->next = B;
  }
}

// 尾插法
void createlistR(LNode **c, int a[], int n)
{
  LNode *s, *r;
  int i;
  *c = (LNode *)malloc(sizeof(LNode));
  (*c)->next = 0;
  r = *c;
  for (i = 0; i < n; i++)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = a[i];
    r->next = s;
    r = r->next;
  }
  r->next = 0;
}

// 头插法
void createlistF(LNode **c, int a[], int n)
{
  LNode *s;
  int i;
  *c = (LNode *)malloc(sizeof(LNode));
  (*c)->next = 0;
  for (i = 0; i < n; i++)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = a[i];

    s->next = (*c)->next;
    (*c)->next = s;
  }
}

// 查找并且删除节点
int findAndDelete(LNode *c, int x)
{
  LNode *h = c;
  while (h->next != 0)
  {
    if (h->next->data == x)
    {
      break;
    }
    h = h->next;
  }
  if (h->next == 0)
  {
    return 0;
  }
  else
  {
    LNode *t = h->next;
    h->next = h->next->next;
    free(t);
    return 1;
  }
}

// 尾插构建双向链表

void appendElemR(DLNode *dl, int elem)
{
  DLNode *n = (DLNode *)malloc(sizeof(DLNode));
  n->data = elem;
  n->next = 0;
  while (dl->next != 0)
  {
    dl = dl->next;
  }
  n->prior = dl;
  dl->next = n;
}

void createDlistR(int a[], int n)
{
  DLNode *dl = (DLNode *)malloc(sizeof(DLNode));
  dl->next = 0;
  DLNode *c;
  c = dl;
  for (int i = 0; i < n; i++)
  {
    DLNode *n = (DLNode *)malloc(sizeof(DLNode));
    n->data = a[i];
    n->prior = c;
    c->next = n;
    c = c->next;
  }
  c->next = 0;
}

// 查找值为x的节点
DLNode *findNode(DLNode *dl, int x)
{
  while (dl->next != 0 && dl->next->data != x)
  {
    dl = dl->next;
  }
  if (dl->next == 0)
  {
    return 0;
  }
  return dl->next;
}

void insertNodeAfterNode(DLNode *c, DLNode *n)
{
  n->prior = c;
  n->next = c->next;
  n->next->prior = n;
  c->next = n;
}

// 删除节点
void deleteNode(DLNode *c)
{
  DLNode *del = c->next;
  DLNode *post = del->next;
  c->next = post;
  post->prior = c;
  free(del);
}

// 综合题
// 1 m,n

void answer(int a[], int m, int n)
{
  for (int i = m, j; i < m + n; ++i)
  {
    int temp = a[i];
    for (j = i - 1; j >= 0 && a[j] < temp; --j)
    {
      a[j + 1] = a[j];
    }
    a[j + i] = temp;
  }
}

void answer2(int a[], int m, int n)
{
  for (int i = 0, j; i < n; ++i)
  {
    int temp = a[m + i];
    for (j = m + i - 1; j >= 0 && temp < a[j]; --j)
    {
      a[j + 1] = a[j];
    }
    a[j + 1] = temp;
  }
}

// 综合题 2

void answer3(LNode *la, LNode *lb)
{
  LNode *laa;
  lb = lb->next;
  while (lb != 0)
  {
    laa = la;
    while (laa->next != 0)
    {
      if (laa->next->data == lb->data)
      {
        LNode *temp = laa->next;
        if (temp->next != 0)
        {
          laa->next = temp->next;
        }
        else
        {
          laa->next = 0;
        }
        free(temp);
      }
      laa = laa->next;
    };
    lb = lb->next;
  }
}

void answer4(LNode *a, LNode *b)
{
  LNode *aa = a->next;
  LNode *bb = b->next;
  LNode *pre = a;
  while (aa != 0 && bb != 0)
  {
    if (aa->data < bb->data)
    {
      aa = aa->next;
      pre = aa;
    }
    else if (aa->data < bb->data)
    {
      bb = bb->next;
    }
    else
    {
      LNode *temp = aa;
      pre->next = aa->next;
      aa = aa->next;
      free(temp);
    }
  }
}