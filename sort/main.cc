#include "custom.hpp"

extern int BinarySearch(int array[], int k, int n);

extern int SeqSearch(int array[], int k, int n);

extern void SelectSort(int array[], int n);

extern void InsertSort(int array[], int n);

extern void ShellSort(int array[], int n);

extern void Merge(int array[], int left, int mid, int right);

extern void MergeSort(int array[], int start, int end);

extern int Partition(int array[], int first, int end);

extern void QuickSort(int array[], int first, int end);

extern void adjust(int array[], int len, int index);

extern void HeapSort(int array[], int n);

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
