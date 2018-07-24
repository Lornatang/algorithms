// Author: shiyi
#ifndef SORT_H
#define SORT_H
#endif

void exchange(int array[], int i, int j) {
  /**
   *  Swap function under an array.
   */
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

void swap(int &i, int &j) {
  /**
   *  Rewrite swap function.
   */
  int tmp = i;
  i = j;
  j = tmp;
}

void BubbleSort(int array[], int n) {
  // The sequence of n Numbers is scanned n-1 times in total.
  for (int i = 0; i < 10 - 1; i++)
    // Each scan ends with a[n-i-2] compared to a[n-i-1].
    for (int j = 0; j < 10 - i - 1; j++)
      /**
       *  if the last digit is smaller than the previous one, the positions of
       *  the two Numbers are swapped (in ascending order).
       */
      if (array[j] > array[j + 1]) {
        int tmp = array[j + 1];
        array[j + 1] = array[j];
        array[j] = tmp;
      }
}

// Selection sort
void SelectSort(int array[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;                     // min: current minimum subscript.
    for (int j = i + 1; j < n; j++)  // Scan the rest.
      if (array[min] > array[j])
        /**
         * if any other element is smaller, its subscript is recorded.
         */
        min = j;
    exchange(array, i, min);
  }
}

// insert sort
void insertSort(int array[], int n) {
  for (int i = 1; i < n; i++)
    for (int j = i; j > 0; j--) 
      exchange(array, j - 1, j);
}

// Shell sort
void ShellSort(int array[], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2)
    for (int i = gap; i < n; i++)
      for (int j = i - gap; j >= 0 && array[j] > array[j + gap]; j -= gap)
        exchange(array, j, j + gap);
}

// merge sort in the merge algorithm
void Merge(int array[], int left, int mid, int right) {
  int aux[9999];
  int i;  // the first array index
  int j;  // second array index
  int k;  // temporary array index

  // point i, j, and k to the beginning of each array, respectively.
  for (i = left, j = mid + 1, k = 0; k < (right - left) + 1; k++) {
    // if i reaches the end of the first array, copy the remaining elements of
    // the second array into the temporary array
    if (i == mid + 1) {
      aux[k] = array[j++];
      continue;
    }
    // if j reaches the end of the second array, copy the remaining elements of
    // the first array into the temporary array
    if (j == right + 1) {
      aux[k] = array[i++];
      continue;
    }
    /**
     * if the current element of the first array is smaller than the current
     * element of the second, it will the current element of the first array is
     * copied to the temporary array
     */
    if (array[i] < array[j]) aux[k] = array[i++];
    /**
     * if the current element of the second array is smaller than the current
     * element of the first array, it will the current element of the second
     * array is copied to the temporary array else Aux[k] = array[j++];
     */
  }

  /**
   * brush the ordered temporary array elements back into the ordered array of
   * arrays, i = left, the starting position of the sorted array array j = 0,
   * the starting position of the temporary array
   */
  for (i = left, j = 0; i <= right; i++, j++) array[i] = aux[j];
}

// 归并排序
void MergeSort(int array[], int start, int end) {
  if (start < end) {
    int mid = start + (end - start) / 2;
    MergeSort(array, start, mid);    // sort the first half.
    MergeSort(array, mid + 1, end);  // sort the latter half.
    // the two parts before and after the merger.
    Merge(array, start, mid, end);
  }
}

int Partition(int array[], int first, int end) {
  int pivot = array[end];
  int i = first - 1;
  for (int j = first; j < end; j++)
    if (array[j] < pivot) {
      i++;
      swap(array[i], array[j]);
    }
  swap(array[i + 1], array[end]);
  return i + 1;
}

// quicksort algorithm, recursive call.
void QuickSort(int array[], int first, int end) {
  if (first < end) {
    int mid = Partition(array, first, end);
    QuickSort(array, first, mid - 1);
    QuickSort(array, mid + 1, end);
  }
}

void adjust(int array[], int len, int index) {
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int maxidx = index;
  if (left < len && array[left] > array[maxidx]) maxidx = left;
  if (right < len && array[right] > array[maxidx])
    // maxidx is the subscript of the largest of the three Numbers.
    maxidx = right;
  // if maxidx is updated
  if (maxidx != index) {
    swap(array[maxidx], array[index]);
    adjust(array, len, maxidx);  // recursively adjust other parts that do not
  }
}

// heap sort
void HeapSort(int array[], int n) {
  // heap adjustment for non-leaf node (starting from the last non-leaf node)
  for (int i = n / 2 - 1; i >= 0; i--) {
    adjust(array, n, i);
  }
  for (int i = n - 1; i >= 1; i--) {
    // place the current maximum at the end of the array
    swap(array[0], array[i]);
    adjust(array, i, 0);  // continue to sort the unfinished part in the heap
  }
}
