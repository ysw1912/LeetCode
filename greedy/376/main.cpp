#include <cassert>

#include <vector>
#include <iostream>

#include <utils.h>

using namespace std;

int wiggleMaxLength(vector<int>& nums);

int main() {
  vector<int> nums = {1, 7, 4, 9, 2, 5};
  assert(wiggleMaxLength(nums) == 6);
  nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  assert(wiggleMaxLength(nums) == 7);
  nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  assert(wiggleMaxLength(nums) == 2);
  nums = {0, 0};
  assert(wiggleMaxLength(nums) == 1);
}

/*
int wiggleMaxLength(vector<int>& nums) {
  int size = nums.size();
  if (size < 2) {
    return size;
  }
  int length = 1, flag = 0;
  for (int i = 1, last = 0; i < size; i++) {
    int diff = nums[i] - nums[last];
    if (diff == 0) continue;
    if (flag == 0) {
      if (diff > 0) flag = 1;
      else flag = -1;
      length++;
    } else {
      if (flag * diff < 0) {
        flag *= -1;
        length++;
      }
    }
    last = i;
  }
  return length;
}
*/

// DP
int wiggleMaxLength(vector<int>& nums) {
  int size = nums.size();
  // dp[0][i]: nums[i] - nums[i - 1] > 0
  // dp[1][i]: nums[i] - nums[i - 1] < 0
  vector<vector<int>> dp(2, vector<int>(size, 1));
  for (int i = 1; i < size; i++) {
    int diff = nums[i] - nums[i - 1];
    if (diff == 0) {
      dp[0][i] = dp[0][i - 1];
      dp[1][i] = dp[1][i - 1];
    } else if (diff > 0) {
      dp[0][i] = dp[1][i - 1] + 1;
      dp[1][i] = dp[1][i - 1];
    } else {
      dp[0][i] = dp[0][i - 1];
      dp[1][i] = dp[0][i - 1] + 1;
    }
  }
  return max(dp[0][size - 1], dp[1][size - 1]);
}
