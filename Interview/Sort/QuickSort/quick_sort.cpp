#include "quick_sort.h"

#include <algorithm>
#include <functional>

namespace {

void QuickSortImpl(int arr[], int n) {
  std::function<void(int, int)> quick_sort = [&](int begin, int end) {
    if (begin + 1 >= end) {
      return;
    }
    int i = begin + 1, j = end - 1;
    while (i <= j) {
      while (i <= j && arr[i] <= arr[begin]) i++;
      while (i <= j && arr[j] >= arr[begin]) j--;
      if (i < j) {
        std::swap(arr[i], arr[j]);
      }
    }
    std::swap(arr[i - 1], arr[begin]);
    quick_sort(begin, i - 1);
    quick_sort(i, end);
  };
  quick_sort(0, n);
}

void QuickSortStlImpl(int arr[], int n) {
  std::function<void(int, int)> quick_sort = [&](int begin, int end) {
    if (begin + 1 >= end) {
      return;
    }
    int key = arr[begin];
    int* lower_ptr = std::stable_partition(arr + begin, arr + end,
                                           [&](int x) { return x < key; });
    int lower = std::distance(arr, lower_ptr);
    int* upper_ptr = std::stable_partition(lower_ptr, arr + end,
                                           [&](int x) { return x == key; });
    int upper = std::distance(arr, upper_ptr);
    quick_sort(begin, lower);
    quick_sort(upper, end);
  };
  quick_sort(0, n);
}

}  // namespace

DEFINE_FUNC(QuickSort);
