// Author: shiyi
#ifndef HASH_H
#define HASH_H
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
  static const int tableSize = 40;
  item *HashTable[tableSize];
};
#endif // HASH_H