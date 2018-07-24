// Author: shiyi
#ifndef CUSTOM_HPP
#define CUSTOM_HPP
#endif

#include <cstdlib>
#include <iostream>
using namespace std;

// Create a binary tree structure.
typedef struct node {
  int data;
  struct node *left, *right;
} BTNode;

// Create a binary tree.
BTNode *CreateBTree(int a[], int n) {
  BTNode *root, *c, *p, *pa;
  root = (BTNode *)malloc(sizeof(BTNode));  // Create the root node.
  root->data = a[0];
  root->left = NULL;
  root->right = NULL;
  // Create other nodes.
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
  free(p);  // Free memory.
  return root;
}
