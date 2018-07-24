// Author: shiyi
#include "find.h"
#include "traverse.h"

#

int main(void) {
  int a[] = {6, 2, 3, 7, 4, 8, 5, 9, 1, 12, 16, 20, 11, 10, 13};
  BTNode *root;                    // Create the root node
  int n = sizeof(a) / sizeof(int); // Array length.
  root = CreateBTree(a, n);
  // Traverse the output.
  cout << "First: ";
  Forder(root);
  cout << endl;
  cout << "Middle: ";
  Inorder(root);
  cout << endl;
  cout << "Last: ";
  Porder(root);

  //

  return 0;
}
