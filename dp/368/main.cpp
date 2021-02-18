#include <algorithm>
#include <vector>

#include <cassert>

#include "utils.h"

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums);

int main() {
  vector<int> nums = {1, 2, 3};
  assert(largestDivisibleSubset(nums) == vector<int>({1, 2}));
  nums = {1, 2, 4, 8};
  assert(largestDivisibleSubset(nums) == vector<int>({1, 2, 4, 8}));
  nums = {5, 9, 18, 54, 108, 540, 90, 180, 360, 720};
  assert(largestDivisibleSubset(nums) == vector<int>({9, 18, 90, 180, 360, 720}));
}

vector<int> largestDivisibleSubset(vector<int>& nums) {
  if (nums.empty()) {
    return {};
  }
  sort(nums.begin(), nums.end());
  int size = nums.size();
  vector<vector<int>> dp(2, vector<int>(size, 0));
  for (int i = 0; i < size; i++) {
    // Max length.
    dp[0][i] = 1;
    // Predecessor.
    dp[1][i] = i;
  }
  for (int i = 1; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] % nums[j] == 0 && dp[0][j] + 1 > dp[0][i]) {
        dp[0][i] = dp[0][j] + 1;
        dp[1][i] = j;
      }
    }
  }
  cout << dp << endl;
  int idx = max_element(dp[0].begin(), dp[0].end()) - dp[0].begin();
  int len = dp[0][idx];
  vector<int> res;
  for (int i = 0; i < len; i++) {
    res.emplace_back(nums[idx]);
    idx = dp[1][idx];
  }
  std::reverse(res.begin(), res.end());
  cout << res << endl;
  return res;
}
