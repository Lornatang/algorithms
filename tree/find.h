// Author: shiyi
#ifndef FIND_H
#define FIND_H
#include "traverse.h"

int Btree::findleaf(tree *t) {
  if (t == NULL)
    return 0;
  else {
    if (t->left == NULL && t->right == NULL)
      return n += 1;
    else {
      findleaf(t->left);
      findleaf(t->right);
    }
    return n;
  }
}
int Btree::findnode(tree *t) {
  if (t == NULL)
    return 0;
  else {
    if (t->left != NULL && t->right != NULL) {
      findnode(t->left);
      findnode(t->right);
    }
    if (t->left != NULL && t->right == NULL) {
      m += 1;
      findnode(t->left);
    }
    if (t->left == NULL && t->right != NULL) {
      m += 1;
      findnode(t->right);
    }
  }
  return m;
}
#endif