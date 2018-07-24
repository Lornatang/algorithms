// Author: shiyi
#ifndef FIND_HPP
#define FIND_HPP
#include "traverse.hpp"

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