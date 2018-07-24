#include "custom.hpp"
// 前序遍历输出
void Forder(BTNode *root) {
  if (!root) {
    return;
  } else {
    cout << root->data << " ";
    Forder(root->left);
    Forder(root->right);
  }
}

//利用中序遍历输出
void Inorder(BTNode *root) {
  if (!root)
    return;
  else {
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
  }
}

// 后序输出二叉树
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
  BTNode *root;                    // 创建根结点
  int n = sizeof(a) / sizeof(int); // 数组长度
  root = CreateBTree(a, n);
  Forder(root); // 前序遍历
  cout << endl;
  Inorder(root); // 中序遍历
  cout << endl;
  Porder(root); // 后序遍历
  cout << endl;
  return 0;
}
