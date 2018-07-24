#ifndef extension_H
#define extension_H
#include "find.h"
bool Btree::Search(tree *t, int key) {
  if (t == NULL) {
    return false;
  } else {
    if (t->data == key) {
      return true;
    } else {
      if (key < t->data)
        return Search(t->left, key);
      else
        return Search(t->right, key);
    }
  }
}

//插入
void Btree::InsertNode(tree **t, int x) {
  // 新建一个根节点
  if (*t == NULL) {
    tree *p = new tree;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    *t = p;
    return;
  } else if (x < (*t)->data)
    InsertNode(&((*t)->left), x);
  else
    InsertNode(&((*t)->right), x);
}

//删除,比较麻烦,分几种情况
int Btree::DeleteNode(tree **t, int x) {
  tree *tmp = *t;
  if (*t == NULL) return 0;
  if (x < (*t)->data) return DeleteNode(&((*t)->left), x);
  if (x > (*t)->data) return DeleteNode(&((*t)->right), x);
  //左子树为空，且删除元素等于根节点，把右子树作为整个树
  if ((*t)->left == NULL) {
    *t = (*t)->right;
    free(tmp);
    return 1;
  } else {
    //前驱节点为空时，把左孩子节点赋给根节点，再从左子树中删除根节点
    if ((*t)->left->right == NULL) {
      (*t)->data = (*t)->left->data;
      return DeleteNode(&((*t)->left), (*t)->data);
    } else {  //找到前驱节点，再把该节点赋给根节点，最后删除该根节点
      tree *p1 = *t;
      tree *p2 = p1->left;
      while (p2->right != NULL) {
        p1 = p2;
        p2 = p2->right;
      }
      (*t)->data = p2->data;
      return DeleteNode(&(p1->right), p2->data);
    }
  }
}

#endif