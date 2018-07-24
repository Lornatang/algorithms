// Author: shiyi
#include <iostream>
#include "find.h"
using namespace std;

// The preceding sequence traverses the output.
void Forder(BTNode *root) {
  if (!root) {
    return;
  } else {
    cout << root->data << " ";
    Forder(root->left);
    Forder(root->right);
  }
}

// Middle order traversal output.
void Inorder(BTNode *root) {
  if (!root)
    return;
  else {
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
  }
}

// Sequential traversal output.
void Porder(BTNode *root) {
  if (!root) {
    return;
  } else {
    Porder(root->left);
    Porder(root->right);
    cout << root->data << " ";
  }
}

int main(void) {
  int a[] = {6, 2, 3, 7, 4, 8, 5, 9, 1, 12, 16, 20, 11, 10, 13};
  BTNode *root;                     // Create the root node
  int n = sizeof(a) / sizeof(int);  // Array length.
  root = CreateBTree(a, n);
  cout << "First: ";
  Forder(root);
  cout << endl;
  cout << "Middle: ";
  Inorder(root);
  cout << endl;
  cout << "Last: ";
  Porder(root);
  return 0;
}
