#include <algorithm>
#include <vector>

#include <cassert>

using namespace std;

int lengthOfLIS(vector<int>& nums);

int main() {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  assert(lengthOfLIS(nums) == 4);
  nums = {4, 10, 4, 3, 8, 9};
  assert(lengthOfLIS(nums) == 3);
  nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
  assert(lengthOfLIS(nums) == 6);
}

int lengthOfLIS(vector<int>& nums) {
  if (nums.empty()) {
    return 0;
  }
  int size = nums.size();
  vector<int> dp(size, 1);
  for (int i = 1; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
//  cout << dp << endl;
  return *max_element(dp.begin(), dp.end());
}
