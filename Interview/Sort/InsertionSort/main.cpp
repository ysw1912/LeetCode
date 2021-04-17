#include <vector>

#include <cassert>

#include "insertion_sort.h"
#include "utils.h"

int main() {
  std::vector<int> sorted = GenerateRange(1, 17);
  std::cout << sorted << std::endl;
  std::vector<int> arr = Shuffle(sorted);
  std::cout << "shuffled: " << arr << std::endl;
  InsertionSort(arr);
  std::cout << "sorted: " << arr << std::endl;
  assert(arr == sorted);

  arr = Shuffle(sorted);
  std::cout << "shuffled: " << arr << std::endl;
  InsertionSort(arr, /*use_stl=*/true);
  std::cout << "sorted: " << arr << std::endl;
  assert(arr == sorted);
}
