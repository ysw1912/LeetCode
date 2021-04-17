#include <vector>

#include <cassert>

#include "bubble_sort.h"
#include "utils.h"

int main() {
  std::vector<int> sorted = GenerateRange(1, 17);
  std::cout << sorted << std::endl;
  std::vector<int> arr = Shuffle(sorted);
  std::cout << "shuffled: " << arr << std::endl;
  BubbleSort(arr);
  std::cout << "sorted: " << arr << std::endl;
  assert(arr == sorted);
}
