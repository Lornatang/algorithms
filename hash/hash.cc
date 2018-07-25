#include "hash.hpp"

Hash::Hash() {
  for (int i = 0; i < tableSize; i++) {
    HashTable[i] = new item;
    HashTable[i]->name = "empty";
    HashTable[i]->drink = "empty";
    HashTable[i]->next = NULL;
  }
}

int Hash::hashFunction(string key) {
  int sum = 0;
  int index = 0;

  index = key.length(); // find the length of the string passing to the function

  for (int i = 0; i < index; i++) {
    sum += static_cast<int>(key[i]); // 可以修改hash function
  }

  //    cout << "key[0] = " << key[0] << endl;
  //    cout << "key[0] = " << static_cast<int>(key[0]) << endl;
  //    cout << "key[1] = " << key[1] << endl;
  //    cout << "key[2] = " << key[2] << endl;

  //    cout << "sum = " << sum << endl;
  index = sum % tableSize;

  return index;
}

void Hash::AddItem(string name, string drink) {
  int index = hashFunction(name);

  if (HashTable[index]->name == "empty") {
    HashTable[index]->name = name;
    HashTable[index]->drink = drink;
    //        HashTable[index] -> next = NULL;
  } else {
    item *ptr = HashTable[index];

    item *n = new item;
    n->name = name;
    n->drink = drink;
    n->next = NULL;

    while (ptr->next != NULL) {
      ptr = ptr->next;
    }

    ptr->next = n;
  }
}

int Hash::NumberOfItemsInIndex(int index) {
  int Count = 0;
  //  为什么注释掉的这个统计的程序会出现问题
  // 因为Hash[index]?????

  //    item* ptr = HashTable[index];
  //
  //    while (ptr -> name != "empty") {
  //        Count++;
  //        ptr = ptr -> next;
  //    }

  if (HashTable[index]->name == "empty") {
    return Count;
  } else {
    Count++;
    item *ptr = HashTable[index];
    while (ptr->next != NULL) {
      Count++;
      ptr = ptr->next;
    }
  }

  return Count;
}

void Hash::PrintTable() {
  int number; // number of items in each bucket
  for (int i = 0; i < tableSize; i++) {
    cout << "i = " << i << ": " << endl;
    // print the first element in the bucket, and we can also see if there are
    // some other items
    number = NumberOfItemsInIndex(i);
    cout << "--------------\n";
    cout << "index = " << i << ": " << endl;
    cout << HashTable[i]->name << endl;
    cout << HashTable[i]->drink << endl;
    cout << "# of items = " << number << endl;
    cout << "--------------\n";
  }
}

void Hash::PrintItemsInIndex(int index) {
  item *ptr = HashTable[index];

  if (ptr->name == "empty") {
    cout << "index = " << index << " is empty";
  } else {
    cout << "index " << index << " conatains the following items \n";
    while (ptr != NULL) {
      cout << "--------------\n";
      cout << ptr->name << endl;
      cout << ptr->drink << endl;
      cout << "--------------\n";
      ptr = ptr->next;
    }
  }
}

void Hash::FindDrink(string name) {
  int index = hashFunction(name);
  bool FoundName = false;

  string drink;

  item *ptr = HashTable[index];
  while (ptr != NULL) {
    if (ptr->name == name) {
      FoundName = true;
      drink = ptr->drink;
    }
    ptr = ptr->next;
  }

  if (FoundName == true) {
    cout << "Favorite drink = " << drink << endl;
  } else {
    cout << name << "'s info was not found in the hash table. \n";
  }
}

void Hash::RemoveItem(string name) {
  int index = hashFunction(name);

  item *delPtr;
  item *P1;
  item *P2;

  // case 0: bucket is empty
  if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty") {
    cout << name << " was not found in the hash table. \n";
  }

  // case 1: only one item contained in the bucket, and that item
  // has matching name
  else if (HashTable[index]->name == name && HashTable[index]->next == NULL) {
    HashTable[index]->name = "empty";
    HashTable[index]->drink = "empty";
    cout << name << " was removed from the hash table. \n";

  }

  // case 2: match is located in the first item in the bucket
  // and there are more items in the bucket

  else if (HashTable[index]->name == name) {
    delPtr = HashTable[index];

    HashTable[index] = HashTable[index]->next;
    delete delPtr;
    cout << name << " was removed from the hash table. \n";

  }

  // case 3: the bucket contains items, but first item is not a match
  else {
    P1 = HashTable[index]->next;
    P2 = HashTable[index];
    while (P1 != NULL && P1->name != name) {
      P2 = P1;
      P1 = P1->next;
    }
    // case 3.1: no match
    if (P1 == NULL) {
      cout << name << " was not found in the hash table. \n";
    }
    // case 3.2: match is found
    else {
      delPtr = P1;
      P1 = P1->next;
      P2->next = P1;

      delete delPtr;
      cout << name << " was removed from the hash table. \n";
    }
  }
}
