#include <algorithm>
#include <unordered_set>
#include <string>
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

int maxProduct(vector<int>& nums) {

}
