#include <stdlib.h>
#include <stdio.h>

#define max_size 100

typedef struct OLNode
{
  int val, i, j;
  struct OLNode *down;
  struct OLNode *right;
} OLNode;

typedef struct CrossList
{
  int m, n, k;
  OLNode *rhead;
  OLNode *chead;
} CrossList;

void createtrimat(int A[][max_size], int m, int n, int B[][3])
{
  int k = 1;
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (A[i][j] == 0)
        continue;
      B[k][0] = A[i][j];
      B[k][1] = i;
      B[k][2] = j;
      ++k;
    }
  }
  B[0][0] = k - 1;
  B[0][1] = m;
  B[0][2] = n;
}

void createCrossListMatrix(int A[][max_size], int m, int n, int k)
{
  CrossList *cl = (CrossList *)malloc(sizeof(CrossList));
  cl->k = k;
  cl->m = m;
  cl->n = n;
  cl->chead = (OLNode *)malloc(sizeof(OLNode) * n);
  cl->rhead = (OLNode *)malloc(sizeof(OLNode) * m);
  for (int i = 0; i < m; ++i)
  {
    (*(cl->rhead + i)).down = 0;
    (*(cl->rhead + i)).right = 0;
  }

  for (int i = 0; i < n; ++i)
  {
    (*(cl->chead + i)).down = 0;
    (*(cl->chead + i)).right = 0;
  }
  OLNode *temp[max_size];
  for (int i = 0; i < n; ++i)
  {
    temp[i] = (cl->chead + i);
  }

  for (int i = 0; i < m; ++i)
  {
    OLNode *c = cl->rhead + i;
    for (int j = 0; j < n; ++j)
    {
      if (A[i][j] != 0)
      {
        OLNode *p = (OLNode *)malloc(sizeof(OLNode));
        p->i = i;
        p->j = j;
        p->val = A[i][j];
        p->down = 0;
        p->down = 0;
        c->right = p;
        c = p;
        temp[j]->down = p;
        temp[j] = p;
      }
    }
  }
}
