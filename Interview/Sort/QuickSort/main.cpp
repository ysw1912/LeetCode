#include <vector>

#include <cassert>

#include "quick_sort.h"
#include "sort.h"
#include "utils.h"

int main() {
  std::vector<int> sorted = GenerateRange(1, 15);
  std::cout << sorted << std::endl;
  std::vector<int> arr = Shuffle(sorted);
  std::cout << "shuffled: " << arr << std::endl;
  QuickSort(arr);
  std::cout << "sorted: " << arr << std::endl;
  assert(arr == sorted);

  arr = Shuffle(sorted);
  std::cout << "shuffled: " << arr << std::endl;
  QuickSort(arr, /*use_stl=*/true);
  std::cout << "sorted: " << arr << std::endl;
  assert(arr == sorted);
}
