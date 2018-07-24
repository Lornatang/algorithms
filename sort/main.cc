#include "custom.hpp"

void disp(int array[], int n);

int main(void) {
  int array[] = {4, -2, 1, 5, 8, 1, 20, 17, 3, 1};
  int N = len(array);
  // Sort algorithm
  QuickSort(array, 0, N - 1);
  // Search algorithm
  int a = BinarySearch(array, 17, N);
  // Display array
  disp(array, N);
  // Display elem index;
  cout << endl << "Index: " << a + 1;
  return 0;
}
