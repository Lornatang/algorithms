// Author: shiyi
#ifndef CUSTOM_HPP
#define CUSTOM_HPP
#include <iostream>
#include "search.h"
#include "sort.h"
using namespace std;
#endif

#define len(x) sizeof(x) / sizeof(int);  // Get the array length

// Print the array
void disp(int array[], int length) {
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
