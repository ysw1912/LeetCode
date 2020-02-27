#include <cassert>

#include <vector>

using namespace std;

int maxProfit(vector<int>& prices);

int main() {
  vector<int> nums{7, 1, 5, 3, 6, 4};
  assert(maxProfit(nums) == 7);
}

int maxProfit(vector<int>& prices) {
  int size = prices.size();
  int profit = 0;
  for (int i = 0; i < size - 1; i++) {
    if (prices[i + 1] > prices[i]) {
      profit += prices[i + 1] - prices[i];
    }
  }
  return profit;
}
