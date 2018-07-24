// Author: shiyi
#ifndef SEARCH_H
#define SEARCH_H
#endif

int SeqSearch(int array[], int k, int n) {
  for (int i = 0; i < n; i++) {
    if (array[i] == k) {
      return i;
    }
  }
  return -1;
}

int BinarySearch(int array[], int k, int length) {
  int first = 0, end = length - 1;
  while (first <= end) {
    int mid = first + (end - first) / 2;
    if (array[mid] > k)
      end = mid - 1;
    else if (array[mid] < k)
      first = mid + 1;
    else
      return mid;
  }
  return -1;
}
