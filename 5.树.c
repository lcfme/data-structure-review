#include <stdlib.h>
#include <stdio.h>

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