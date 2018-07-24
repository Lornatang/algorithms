// Author: shiyi
#ifndef TRAVERSE_H
#define TRAVERSE_H
#include "base.hpp"

void Btree::Preorder(tree *t)  //这是先序遍历二叉树，采用了递归的方法。
{
  if (t != NULL) {
    print(t->data);
    print(" ");
    Preorder(t->left);
    Preorder(t->right);
  }
}
void Btree::Inorder(tree *t)  //这是中序遍历二叉树，采用了递归的方法。
{
  if (t != NULL) {
    Inorder(t->left);
    print(t->data);
    print(" ");
    Inorder(t->right);
  }
}
void Btree::Postorder(tree *t)  //这是后序遍历二叉树，采用了递归的方法。
{
  if (t != NULL) {
    Postorder(t->left);
    Postorder(t->right);
    print(t->data);
    print(" ");;
  }
}
#endif