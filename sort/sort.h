// Author: shiyi
#ifndef SORT_H
#define SORT_H
#endif

void exchange(int array[], int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

void swap(int &i, int &j){
  int tmp = i;
  i = j;
  j = tmp;
}

void SelectSort(int array[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;                    // min:当前最小值下标
    for (int j = i + 1; j < n; j++) //扫描余下的部分
      if (array[min] > array[j]) //若有其它元素更小，就记录其下标
        min = j;
    exchange(array, i, min);
  }
}

void InsertSort(int array[], int n) {
  for (int i = 1; i < n; i++)
    for (int j = i; j > 0; j--)
      exchange(array, j - 1, j);
}

void ShellSort(int array[], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2)
    for (int i = gap; i < n; i++)
      for (int j = i - gap; j >= 0 && array[j] > array[j + gap]; j -= gap)
        exchange(array, j, j + gap);
}

// 归并排序中的合并算法
void Merge(int array[], int left, int mid, int right) {
  int aux[9999];
  int i; //第一个数组索引
  int j; //第二个数组索引
  int k; //临时数组索引

  // 分别将 i, j, k 指向各自数组的首部。
  for (i = left, j = mid + 1, k = 0; k < (right - left) + 1; k++) {
    //若 i 到达第一个数组的尾部，将第二个数组余下元素复制到 临时数组中
    if (i == mid + 1) {
      aux[k] = array[j++];
      continue;
    }
    //若 j 到达第二个数组的尾部，将第一个数组余下元素复制到 临时数组中
    if (j == right + 1) {
      aux[k] = array[i++];
      continue;
    }
    //如果第一个数组的当前元素 比 第二个数组的当前元素小，将
    //第一个数组的当前元素复制到 临时数组中
    if (array[i] < array[j])
      aux[k] = array[i++];
    //如果第二个数组的当前元素 比 第一个数组的当前元素小，将
    //第二个数组的当前元素复制到 临时数组中
    else
      aux[k] = array[j++];
  }

  //将有序的临时数组 元素 刷回 被排序的数组 array 中，
  // i = left , 被排序的数组array 的起始位置
  // j = 0， 临时数组的起始位置
  for (i = left, j = 0; i <= right; i++, j++)
    array[i] = aux[j];
}

// 归并排序
void MergeSort(int array[], int start, int end) {
  if (start < end) {
    int mid = start + (end - start) / 2;
    // 对前半部分进行排序
    MergeSort(array, start, mid);
    // 对后半部分进行排序
    MergeSort(array, mid + 1, end);
    // 合并前后两部分
    Merge(array, start, mid, end);
  }
}

int Partition(int array[], int first, int end) {
  int pivot = array[end];
  int i = first - 1;
  for (int j = first; j < end; j++) {
    if (array[j] < pivot) {
      i++;
      swap(array[i], array[j]);
    }
  }
  swap(array[i + 1], array[end]);
  return i + 1;
}

// 快速排序算法，递归调用
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
  int maxIdx = index;
  if (left < len && array[left] > array[maxIdx])
    maxIdx = left;
  if (right < len && array[right] > array[maxIdx])
    maxIdx = right;    // maxIdx是3个数中最大数的下标
  if (maxIdx != index) // 如果maxIdx的值有更新
  {
    swap(array[maxIdx], array[index]);
    adjust(array, len, maxIdx); // 递归调整其他不满足堆性质的部分
  }
}
// 堆排序
void HeapSort(int array[], int n) {
  for (int i = n / 2 - 1; i >= 0;
       i--) // 对每一个非叶结点进行堆调整(从最后一个非叶结点开始)
  {
    adjust(array, n, i);
  }
  for (int i = n - 1; i >= 1; i--) {
    swap(array[0], array[i]); // 将当前最大的放置到数组末尾
    adjust(array, i, 0); // 将未完成排序的部分继续进行堆排序
  }
}
