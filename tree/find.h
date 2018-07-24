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

// Find the element, return 1 if it exists, return 0 does not exist
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
    // The situation where the node to be deleted has two children.
    if (root->left && root->right) {
      BTNode *tmp = findmin(root->right);
      root->data = tmp->data;
      root->right = delnum(root->right, tmp->data);
    }
    // The node to be deleted has only one or no children.
    else {
      if (root->left == NULL)
        root = root->right;
      else if (root->right == NULL)
        root = root->left;
    }
  }
  return root;
}