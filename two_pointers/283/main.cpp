#include <vector>

#include "utils.h"

using namespace std;

void moveZeroes1(vector<int>& nums);
void moveZeroes2(vector<int>& nums);
void moveZeroes3(vector<int>& nums);

int main() {
  vector<int> nums{0, 1, 0, 0, 0, 3, 12};
  PrintVector(nums, nums.size());
  moveZeroes1(nums);
  PrintVector(nums, nums.size());

  nums = {2, 3, 0, 0, 1, 0, 0, 0, 3, 12, 0};
  PrintVector(nums, nums.size());
  moveZeroes2(nums);
  PrintVector(nums, nums.size());

  nums = {0, 0, 0, 0, 1, 2, 0, 0, 3, 12, 0};
  PrintVector(nums, nums.size());
  moveZeroes3(nums);
  PrintVector(nums, nums.size());
}

void moveZeroes1(vector<int>& nums) {
  int size = nums.size(), first_zero = 0;
  for (int i = 0; i < size; i++) {
    if (nums[i] != 0) {
      if (i != first_zero) {
        swap(nums[i], nums[first_zero]);
      }
      first_zero++;
    }
  }
}

void moveZeroes2(vector<int>& nums) {
  fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
}

void moveZeroes3(vector<int>& nums) {
  stable_partition(nums.begin(), nums.end(), [](int n){ return n != 0; });
}
