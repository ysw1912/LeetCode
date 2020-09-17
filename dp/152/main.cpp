#include <algorithm>
#include <vector>

#include <cassert>

using namespace std;

int maxProduct(vector<int>& nums);

int main() {
  vector<int> nums = {2, 3, -2, 4};
  assert(maxProduct(nums) == 6);
  nums = {-2, 0, -1};
  assert(maxProduct(nums) == 0);
}
/* 正解一
int maxProduct(vector<int>& nums) {
  int size = nums.size();
  // 0: max, 1: min
  vector<vector<int>> dp(2, vector<int>(size));
  dp[0][0] = dp[1][0] = nums[0];
  for (int i = 1; i < size; i++) {
    dp[0][i] = max(max(dp[0][i - 1] * nums[i], dp[1][i - 1] * nums[i]), nums[i]);
    dp[1][i] = min(min(dp[0][i - 1] * nums[i], dp[1][i - 1] * nums[i]), nums[i]);
  }
  return *max_element(dp[0].begin(), dp[0].end());
}
*/

int maxProduct(vector<int>& nums) {
  int size = nums.size();
  int min_num{nums[0]}, max_num{nums[0]}, max_ans{nums[0]};
  for (int i = 1; i < size; i++) {
    int tmp_max = max(max(max_num * nums[i], min_num * nums[i]), nums[i]);
    min_num = min(min(max_num * nums[i], min_num * nums[i]), nums[i]);
    max_num = tmp_max;
    max_ans = max(max_ans, max_num);
  }
  return max_ans;
}
