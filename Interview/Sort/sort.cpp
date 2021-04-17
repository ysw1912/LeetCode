#include "sort.h"

#include <algorithm>
#include <chrono>
#include <random>

#include <cassert>

std::vector<int> GenerateRange(int start, int end) {
  assert(start <= end);
  std::vector<int> arr;
  arr.reserve(end - start + 1);
  for (int i = start; i <= end; i++) {
    arr.emplace_back(i);
  }
  return arr;
}

std::vector<int> Shuffle(const std::vector<int>& arr) {
  std::vector<int> shuffled = arr;
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  auto rng = std::default_random_engine{seed};
  std::shuffle(shuffled.begin(), shuffled.end(), rng);
  return shuffled;
}
