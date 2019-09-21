#include <cassert>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target);

int main() {
  vector<int> nums{2, 7, 11, 15};
  assert(twoSum(nums, 9) == vector<int>({1, 2}));
  assert(twoSum(nums, 18) == vector<int>({2, 3}));
  assert(twoSum(nums, 22) == vector<int>({2, 4}));
  return 0;
}

vector<int> twoSum(vector<int>& numbers, int target) {
  int i = 0, j = static_cast<int>(numbers.size()) - 1;
  while (true) {
    int sum = numbers[i] + numbers[j];
    if (sum == target) return vector<int>({++i, ++j});
    if (sum > target) --j;
    if (sum < target) ++i;
  }
}
