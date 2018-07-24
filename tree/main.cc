// Author: shiyi
#include "extension.h"

int main(void) {
  Btree Tree;
  int array[] = {100, 4, 2, 3, 15, 35, 6, 45, 55, 20, 1, 14, 56, 57, 58};
  for (int i = 0; i < len(array); i++) {
    Tree.create_Btree(array[i]);
  }
  end;

  print("Number of nodes: ");
  printf(Tree.count(Tree.root));

  print("Number of leaf: ");
  printf(Tree.findleaf(Tree.root));
  
  print("A binary tree with degree one: ");
  printf(Tree.findnode(Tree.root));

  printf("Preorder: ");
  Tree.dispPreorder();
  end;

  printf("Inorder: ");
  Tree.dispInorder();
  end;

  printf("Postorder: ");
  Tree.dispPostorder();
  end;

  printf("Insert elem 5.");
  Tree.InsertNode(&Tree.root, 5);
  Tree.dispPreorder();
  end;

  printf("Delete elem 5.");
  Tree.DeleteNode(&Tree.root, 5);
  Tree.dispPreorder();
  end;
  if (Tree.Search(Tree.root, 100)){
    print("find!");
  }
  return 0;
}
