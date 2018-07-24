// Author: shiyi
#include "custom.h"

BTNode *findmin(BTNode *root) {
  if (root == NULL)
    return NULL;
  if (root->left == NULL && root->right == NULL)
    return root;
  if (root->left)
    return findmin(root->left);
  return 0;
}

//查找元素，若存在返回1，不存在返回0
bool find(BTNode *root, int data) {
  if (root == NULL)
    return false;
  if (root->data == data)
    return true;
  if (data < root->data)
    return find(root->left, data);
  else
    return find(root->right, data);
  return false;
}

BTNode *delnum(BTNode *root, int data) {
  if (root == NULL)
    return NULL;
  if (data > root->data)
    root->right = delnum(root->right, data);
  else if (data < root->data)
    root->left = delnum(root->left, data);
  else {
    //待删除结点有两个孩子的情形
    if (root->left && root->right) {
      BTNode *tmp = findmin(root->right);
      root->data = tmp->data;
      root->right = delnum(root->right, tmp->data);
    }
    //待删除结点仅仅有一个或者没有孩子
    else {
      if (root->left == NULL)
        root = root->right;
      else if (root->right == NULL)
        root = root->left;
    }
  }
  return root;
}