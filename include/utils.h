#ifndef LEETCODE_UTILS_H_
#define LEETCODE_UTILS_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
void PrintVector(const std::vector<T>& vec, size_t size) {
  std::copy(
      vec.begin(), 
      vec.begin() + size, 
      std::ostream_iterator<T>(std::cout, " "));
  std::cout << std::endl;
}

#endif  // LEETCODE_UTILS_H_
