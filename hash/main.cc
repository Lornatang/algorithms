#include "extension.hpp"

using namespace std;

int main(void) {
  Hash Hashy;
  string name1 = " ";
  string name2 = " ";
  Hashy.PrintTable();

  Hashy.AddItem("Paul", "Locha");
  Hashy.AddItem("Kim", "Iced Mocha");
  Hashy.AddItem("Anni", "Strawberry Smoothy");
  Hashy.AddItem("Sara", "Passion Tea");
  Hashy.AddItem("Mike", "Tea");
  Hashy.AddItem("steve", "Apple cider");
  Hashy.AddItem("Sill", "Root beer");
  Hashy.AddItem("Bill", "Lochs");
  Hashy.AddItem("Susan", "Cola");
  Hashy.AddItem("Joe", "Green Tea");

  Hashy.PrintTable();

  Hashy.PrintItemsInIndex(0);

  while (name1 != "exit") {
    cout << "search for: ";
    cin >> name1;
    if (name1 != "exit") {
      Hashy.FindDrink(name1);
    }
  }

  while (name2 != "exit") {
    cout << "Remove: ";
    cin >> name2;
    if (name2 != "exit") {
      Hashy.RemoveItem(name2);
    }
  }
  Hashy.PrintTable();

  Hashy.PrintItemsInIndex(0);

  return 0;
}
