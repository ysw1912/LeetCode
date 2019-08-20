#include "utils.h"

#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums);

int main()
{
  vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
  int len = removeDuplicates(nums);
  PrintVector(nums, len);
  return 0;
}

int removeDuplicates(vector<int>& nums) {
  int i = 0;
  for (auto& e : nums) {
    if (i < 2 || e > nums[i - 2])
      nums[i++] = e;
  }
  return i;
}

/*
int removeDuplicates(vector<int>& nums) {
  int size = static_cast<int>(nums.size());
  if (size <= 2)
    return size;
  int i = 0, p = 0, q = 0;
  while (q < size) {
    while (++q < size && nums[p] == nums[q]);
    if (q - p == 1) {
      nums[i++] = nums[p];
    } else {
      nums[i++] = nums[p];
      nums[i++] = nums[p];
    }
    p = q;
  }
  return i;
}
*/
