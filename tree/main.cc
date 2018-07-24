// Author: shiyi
#include "extension.h"

int main(void) {
  Btree Tree;
  int array[] = {100, 4, 2, 3, 15, 35, 6, 45, 55, 20, 1, 14, 56, 57, 58};
  for (int i = 0; i < len(array); i++) {
    Tree.create_Btree(array[i]);
  }
  cout << endl;
  cout << "Number of nodes: " << Tree.count(Tree.root) << endl;
  cout << "Number of leaf: " << Tree.findleaf(Tree.root) << endl;
  cout << "The number of nodes in a binary tree with degree one: "
       << Tree.findnode(Tree.root) << endl;

  cout << "Preorder: ";
  end;
  Tree.dispPreorder();
  cout << "Inorder: ";
  end;
  Tree.dispInorder();
  cout << "Postorder: ";
  end;
  Tree.dispPostorder();
  end;
  cout << "Insert elem 5";
  Tree.InsertNode(&Tree.root, 5);
  Tree.dispPreorder();
  end;
  

  return 0;
}
