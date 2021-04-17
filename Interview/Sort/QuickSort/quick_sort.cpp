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
  std::sort(arr, arr + n);
}

}  // namespace

DEFINE_FUNC(QuickSort);
