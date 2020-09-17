#include <algorithm>
#include <vector>

#include <cassert>

using namespace std;

int rob(vector<int>& nums);

int main() {
  vector<int> nums = {1, 2, 3, 1};
  assert(rob(nums) == 4);
  nums = {2, 7, 9, 3, 1};
  assert(rob(nums) == 12);
}
/* 正解一
int rob(vector<int>& nums) {
  if (nums.empty()) {
    return 0;
  }
  int size = nums.size();
  if (size == 1) {
    return nums[0];
  }
  vector<int> dp(size);
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);
  for (int i = 2; i < size; i++) {
    dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
  }
  return dp[size - 1];
}
*/
int rob(vector<int>& nums) {
  if (nums.empty()) {
    return 0;
  }
  int size = nums.size();
  if (size == 1) {
    return nums[0];
  }
  int a = nums[0], b = max(nums[0], nums[1]), ans = b;
  for (int i = 2; i < size; i++) {
    int tmp = max(a + nums[i], b);
    ans = max(tmp, b);
    a = b;
    b = tmp;
  }
  return ans;
}
