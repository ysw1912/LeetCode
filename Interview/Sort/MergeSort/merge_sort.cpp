#include "merge_sort.h"

#include <algorithm>
#include <functional>

namespace {

void MergeSortImpl(int arr[], int n) {
  std::vector<int> buffer(n);
  std::function<void(int, int)> merge_sort = [&](int begin, int end) {
    if (begin + 1 >= end) {
      return;
    }
    int mid = begin + (end - begin) / 2;
    merge_sort(begin, mid);
    merge_sort(mid, end);
    int i = begin, j = mid, k = begin;
    while (i < mid || j < end) {
      if (j == end || (i < mid && arr[i] <= arr[j])) {
        buffer[k++] = arr[i++];
      } else {
        buffer[k++] = arr[j++];
      }
    }
    std::move(buffer.begin() + begin, buffer.begin() + end, arr + begin);
  };
  merge_sort(0, n);
}

void MergeSortStlImpl(int arr[], int n) {
  std::function<void(int, int)> merge_sort = [&](int begin, int end) {
    if (begin + 1 >= end) {
      return;
    }
    int mid = begin + (end - begin) / 2;
    merge_sort(begin, mid);
    merge_sort(mid, end);
    std::inplace_merge(arr + begin, arr + mid, arr + end);
  };
  merge_sort(0, n);
}

}  // namespace

DEFINE_FUNC(MergeSort);
