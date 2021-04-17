#include "selection_sort.h"

#include <algorithm>

namespace {

void SelectionSortImpl(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    std::swap(arr[i], arr[min]);
  }
}

void SelectionSortStlImpl(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int* min = std::min_element(arr + i, arr + n);
    std::swap(arr[i], arr[min - arr]);
  }
}

}  // namespace

DEFINE_FUNC(SelectionSort);
