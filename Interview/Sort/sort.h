#ifndef LEETCODE_SORT_H_
#define LEETCODE_SORT_H_

#include <vector>

std::vector<int> GenerateRange(int start, int end);

std::vector<int> Shuffle(const std::vector<int>& arr);

#define DECLARE_FUNC(SORT_FUNC) \
void SORT_FUNC(std::vector<int>& arr, bool use_stl = false); \
void SORT_FUNC(int arr[], int n, bool use_stl = false)

#define DEFINE_FUNC(SORT_FUNC) \
void SORT_FUNC(std::vector<int>& arr, bool use_stl) { \
  SORT_FUNC(arr.data(), arr.size(), use_stl); \
} \
void SORT_FUNC(int arr[], int n, bool use_stl) { \
  if (use_stl) { \
    SORT_FUNC##StlImpl(arr, n); \
  } else { \
    SORT_FUNC##Impl(arr, n); \
  } \
}

#endif //LEETCODE_SORT_H_
