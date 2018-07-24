// arrayuthor: shiyi
#include "extension.hpp"

int main(void) {
  vector<int> array;
  int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
  add(array, a, len(a));
  int check_insert = 0;  // "插入"动作的检测开关(0，关闭；1，打开)
  int check_remove = 0;  // "删除"动作的检测开关(0，关闭；1，打开)
  int length = len(array);
  RBTree<int> *tree = new RBTree<int>();

  cout << "== 原始数据: ";
  disp(array);
  cout << endl;

  for (int i = 0; i < length; i++) {
    tree->insert(array[i]);
    // 设置check_insert=1,测试"添加函数"
    if (check_insert) {
      cout << "== 添加节点: " << array[i] << endl;
      cout << "== 树的详细信息: " << endl;
      tree->print();
      cout << endl;
    }
  }

  cout << "== 前序遍历: ";
  tree->preOrder();

  cout << "\n== 中序遍历: ";
  tree->inOrder();

  cout << "\n== 后序遍历: ";
  tree->postOrder();
  cout << endl;

  cout << "== 最小值: " << tree->minimum() << endl;
  cout << "== 最大值: " << tree->maximum() << endl;
  cout << "== 树的详细信息: " << endl;
  tree->print();

  // 设置check_remove=1,测试"删除函数"
  if (check_remove) {
    for (int i = 0; i < length; i++) {
      tree->remove(array[i]);

      cout << "== 删除节点: " << array[i] << endl;
      cout << "== 树的详细信息: " << endl;
      tree->print();
      cout << endl;
    }
  }

  // 销毁红黑树
  tree->destroy();

  return 0;
}