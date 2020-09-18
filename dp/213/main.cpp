#include <algorithm>
#include <vector>

#include <cassert>

using namespace std;

int rob(vector<int>& nums);

int main() {
  vector<int> nums = {2, 3, 2};
  assert(rob(nums) == 3);
  nums = {1, 2, 3, 1};
  assert(rob(nums) == 4);
}

int rob(vector<int>& nums, int start, int end) {
  int a = nums[start], b = max(nums[start], nums[start + 1]), ans = b;
  for (int i = start + 2; i < end; i++) {
    int tmp = max(a + nums[i], b);
    ans = max(tmp, b);
    a = b;
    b = tmp;
  }
  return ans;
}

int rob(vector<int>& nums) {
  if (nums.empty()) {
    return 0;
  }
  int size = nums.size();
  if (size == 1) {
    return nums[0];
  }
  if (size == 2) {
    return max(nums[0], nums[1]);
  }
  return max(rob(nums, 1, nums.size()), rob(nums, 0, nums.size() - 1));
}
