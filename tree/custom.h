// Author: shiyi
#ifndef CUSTOM_H
#define CUSTOM_H
#include <iostream>
using namespace std;

struct tree {
  int data;
  tree *left, *right;
};

class Btree {
  static int n;
  static int m;

 public:
  tree *root;
  Btree() { root = NULL; }
  void create_Btree(int);
  void Preorder(tree *);   //先序遍历
  void Inorder(tree *);    //中序遍历
  void Postorder(tree *);  //后序遍历
  void dispPreorder() { Preorder(root); }
  void dispInorder() { Inorder(root); }
  void dispPostorder() { Postorder(root); }
  // 计算二叉树的个数
  int count(tree *);
  // 求二叉树叶子的个数
  int findleaf(tree *);
  // 求二叉树中度数为1的结点数量
  int findnode(tree *);
  // 查找二叉树中是否存在
  bool Search(tree *, int);
  // 向二叉树中插入元素
  void InsertNode(tree* *, int);
  // 删除二叉树中的某个元素
  int DeleteNode(tree* *, int);
};

int Btree::n = 0;
int Btree::m = 0;

void Btree::create_Btree(int x) {
  tree *newnode = new tree;
  newnode->data = x;
  newnode->right = newnode->left = NULL;
  if (root == NULL)
    root = newnode;
  else {
    tree *back;
    tree *current = root;
    while (current != NULL) {
      back = current;
      if (current->data > x)
        current = current->left;
      else
        current = current->right;
    }
    if (back->data > x)
      back->left = newnode;
    else
      back->right = newnode;
  }
}

int Btree::count(tree *p) {
  if (p == NULL)
    return 0;
  else
    return count(p->left) + count(p->right) + 1;  // 递归。
}
#endif

#ifndef LEN
#define len(x) sizeof(x) / sizeof(x[0])
#endif

#ifndef END
#define end cout << endl;
#endif