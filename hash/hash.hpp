// Author: shiyi
#ifndef HASH_HPP
#define HASH_HPP
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct item {
  string name;
  string drink;
  item *next;
};

class Hash {
public:
  int hashFunction(string key);
  Hash();

  void AddItem(string name, string drink);
  int NumberOfItemsInIndex(int index);
  void PrintTable();
  void PrintItemsInIndex(int index);
  void FindDrink(string name);
  void RemoveItem(string name);

private:
  static const int tableSize = 10; // 修改为40再试试看， 存储会变换
  item *HashTable[tableSize]; // in this case, 10 buckets, each bucket contains
                              // a pointer that has the ability to point to
                              // some item
};
#endif // HASH_HPP