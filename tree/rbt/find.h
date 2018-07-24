// arrayuthor: shiyi
#ifndef FIND_H
#define FIND_H
#include "base.h"

template <class T>
RBTNode<T> *RBTree<T>::search(T key) {
  search(root, key);
}

/*
 * (递归实现)查找"红黑树x"中键值为key的节点
 */
template <class T>
RBTNode<T> *RBTree<T>::search(RBTNode<T> *x, T key) const {
  if (x == NULL || x->key == key) return x;

  if (key < x->key)
    return search(x->left, key);
  else
    return search(x->right, key);
}

/*
 * 查找最小结点：返回tree为根结点的红黑树的最小结点。
 */
template <class T>
RBTNode<T> *RBTree<T>::minimum(RBTNode<T> *tree) {
  if (tree == NULL) return NULL;
  while (tree->left != NULL) tree = tree->left;
  return tree;
}

template <class T>
T RBTree<T>::minimum() {
  RBTNode<T> *p = minimum(root);
  if (p != NULL) return p->key;
  return (T)NULL;
}

/*
 * 查找最大结点：返回tree为根结点的红黑树的最大结点。
 */
template <class T>
RBTNode<T> *RBTree<T>::maximum(RBTNode<T> *tree) {
  if (tree == NULL) return NULL;
  while (tree->right != NULL) tree = tree->right;
  return tree;
}

template <class T>
T RBTree<T>::maximum() {
  RBTNode<T> *p = maximum(root);
  if (p != NULL) return p->key;
  return (T)NULL;
}

/*
 * 找结点(x)的后继结点。即，查找"红黑树中数据值大于该结点"的"最小结点"。
 */
template <class T>
RBTNode<T> *RBTree<T>::successor(RBTNode<T> *x) {
  // 如果x存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"。
  if (x->right != NULL) return minimum(x->right);

  // 如果x没有右孩子。则x有以下两种可能：
  // (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
  // (02)
  // x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
  RBTNode<T> *y = x->parent;
  while ((y != NULL) && (x == y->right)) {
    x = y;
    y = y->parent;
  }

  return y;
}

/*
 * 找结点(x)的前驱结点。即，查找"红黑树中数据值小于该结点"的"最大结点"。
 */
template <class T>
RBTNode<T> *RBTree<T>::predecessor(RBTNode<T> *x) {
  // 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
  if (x->left != NULL) return maximum(x->left);
  // 如果x没有左孩子。则x有以下两种可能：
  // (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
  // (01)
  // x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
  RBTNode<T> *y = x->parent;
  while ((y != NULL) && (x == y->left)) {
    x = y;
    y = y->parent;
  }

  return y;
}
#endif