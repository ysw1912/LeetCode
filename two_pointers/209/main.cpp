#include <cassert>
#include <vector>

#include "utils.h"

using namespace std;

int minSubArrayLen(int s, vector<int>& nums);

int main() {
  vector<int> nums{2, 3, 1, 2, 4, 3};
  assert(minSubArrayLen(4, nums) == 1);
  assert(minSubArrayLen(6, nums) == 2);
  assert(minSubArrayLen(7, nums) == 2);

  nums = {10, 5, 13, 4, 8, 4, 5, 11, 14, 9, 16, 10, 20, 8};
  assert(minSubArrayLen(80, nums) == 6);

  nums = {2};
  assert(minSubArrayLen(2, nums) == 1);
  return 0;
}

/* 正解三 */
int minSubArrayLen(int s, vector<int>& nums) {
  int min = INT_MAX, sum = 0;
  for (int i = 0, j = 0; j < static_cast<int>(nums.size()); ++j) {
    sum += nums[j];
    while (sum - nums[i] >= s) sum -= nums[i++];
    if (sum >= s) min = std::min(j - i + 1, min);
  }
  return min == INT_MAX ? 0 : min;
}

/* 正解二
bool WindowExist(int s, vector<int>& nums, int size) {
  int sum = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    if (i >= size) sum -= nums[i - size];
    sum += nums[i];
    if (sum >= s) return true;
  }
  return false;
}

int minSubArrayLen(int s, vector<int>& nums) {
  int i = 1, j = nums.size(), len = 0;
  while(i <= j) {
    int mid = i + (j - i) / 2;
    if (WindowExist(s, nums, mid)) {
      j = mid - 1;
      len = mid;
    }
    else {
      i = mid + 1;
    }
  }
  return len;
}
*/

/* 正解一
int minSubArrayLen(int s, vector<int>& nums) {
  int n = nums.size(), len = INT_MAX;
  vector<int> sums(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    sums[i] = sums[i - 1] + nums[i - 1];
  }
  for (int i = n; i >= 0 && sums[i] >= s; i--) {
    int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
    len = min(len, i - j + 1);
  }
  return len == INT_MAX ? 0 : len;
}
*/
