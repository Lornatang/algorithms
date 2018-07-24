// Author: shiyi
#include "custom.h"

// The preceding sequence traverses the output.
int Forder(BTNode *root) {
  vector<int> array;
  if (!root) {
    return 0;
  } else {
    array.push_back(root->data);
    Forder(root->left);
    Forder(root->right);
  }
}

// Middle order traversal output.
void Inorder(BTNode *root) {
  vector<int> array;
  if (!root)
    return;
  else {
    Inorder(root->left);
    array.push_back(root->data);
    Inorder(root->right);
  }
}

// Sequential traversal output.
void Porder(BTNode *root) {
  vector<int> array;
  if (!root) {
    return;
  } else {
    Porder(root->left);
    Porder(root->right);
    array.push_back(root->data);
  }
}