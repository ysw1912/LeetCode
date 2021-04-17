#include "insertion_sort.h"

#include <algorithm>

namespace {

void InsertionSortImpl(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
      std::swap(arr[j], arr[j - 1]);
    }
  }
}

void InsertionSortStlImpl(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int num = arr[i];
    int* upper = std::upper_bound(arr, arr + i, num);
    if (upper == arr + i) {
      continue;
    }
    std::move(upper, arr + i, upper + 1);
    *upper = num;
  }
}

}  // namespace

DEFINE_FUNC(InsertionSort);
