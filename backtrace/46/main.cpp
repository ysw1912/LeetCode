#include <cassert>

#include <algorithm>
#include <set>
#include <vector>
#include "utils.h"

using namespace std;

vector<vector<int>> permute(vector<int>& nums);

int main() {
  vector<int> nums;
  nums = {1, 2, 3};
  vector<vector<int>> res = permute(nums);
  assert(set<vector<int>>(res.begin(), res.end()) == set<vector<int>>({{1, 2, 3},
                                                                       {1, 3, 2},
                                                                       {2, 1, 3},
                                                                       {2, 3, 1},
                                                                       {3, 1, 2},
                                                                       {3, 2, 1}}));
}

void permute(vector<int>& nums, size_t from, size_t to, vector<vector<int>>& res) {
  if (from > to) {
    return;
  }
  if (from == to) {
    res.emplace_back(nums);
    return;
  }
  for (size_t i = from; i <= to; i++) {
    swap(nums[i], nums[from]);
    permute(nums, from + 1, to, res);
    swap(nums[i], nums[from]);
  }
}
/*
vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> res;
  permute(nums, 0, nums.size() - 1, res);
  return res;
}
*/
vector<vector<int>> permute(vector<int>& nums) {
   
  vector<vector<int>> res{nums};
  int size = static_cast<int>(nums.size());
  for (;;) {
    int i = size - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    if (i < 0) break;
    int j = size - 1;
    while (j > i && nums[j] <= nums[i]) --j;
    std::swap(nums[i], nums[j]);
    std::reverse(nums.begin() + i + 1, nums.end());
    res.emplace_back(nums);
    cout << nums << endl;
  }
  return res;
}
