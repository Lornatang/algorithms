// Author: shiyi
#ifndef TRAVERSE_H
#define TRAVERSE_H
#include "custom.h"

void Btree::Preorder(tree *t)  //这是先序遍历二叉树，采用了递归的方法。
{
  if (t != NULL) {
    cout << t->data << " ";
    Preorder(t->left);
    Preorder(t->right);
  }
}
void Btree::Inorder(tree *t)  //这是中序遍历二叉树，采用了递归的方法。
{
  if (t != NULL) {
    Inorder(t->left);
    cout << t->data << " ";
    Inorder(t->right);
  }
}
void Btree::Postorder(tree *t)  //这是后序遍历二叉树，采用了递归的方法。
{
  if (t != NULL) {
    Postorder(t->left);
    Postorder(t->right);
    cout << t->data << " ";
  }
}
#endif