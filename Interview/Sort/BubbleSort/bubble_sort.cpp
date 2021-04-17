#include "bubble_sort.h"

namespace {

void BubbleSortImpl(int arr[], int n) {
  bool swap = true;
  for (int i = 0; i < n && swap; i++) {
    swap = false;
    for (int j = 1; j < n - i; j++) {
      if (arr[j - 1] > arr[j]) {
        std::swap(arr[j - 1], arr[j]);
        swap = true;
      }
    }
  }
}

void BubbleSortStlImpl(int arr[], int n) {
  throw;
}

}  // namespace

DEFINE_FUNC(BubbleSort);
