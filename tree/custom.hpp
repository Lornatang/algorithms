#include <iostream>
using namespace std;

//创建二叉树结构体
typedef struct node {
  int data;
  struct node *left, *right;
} BTNode;

//创建二叉树
BTNode *CreateBTree(int a[], int n) {
  BTNode *root, *c, *p, *pa;
  root = (BTNode *)malloc(sizeof(BTNode));  //创建根结点
  root->data = a[0];
  root->left = root->right = NULL;
  //	创建其他结点
  for (int i = 1; i < n; i++) {
    p = (BTNode *)malloc(sizeof(BTNode));
    p->data = a[i];
    p->left = p->right = NULL;
    c = root;
    while (c) {
      pa = c;
      if (c->data > p->data)
        c = c->left;
      else
        c = c->right;
    }
    if (pa->data > p->data)
      pa->left = p;
    else
      pa->right = p;
  }
  free(p);
  return root;
}
