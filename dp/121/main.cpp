#include <algorithm>
#include <vector>

#include <cassert>

using namespace std;

int maxProfit(vector<int>& prices);

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  assert(maxProfit(prices) == 5);
}

/* 自己解
int maxProfit(vector<int>& prices) {
  int size = prices.size();
  if (size < 2) {
    return 0;
  }
  vector<int> mins(size), dp(size);
  mins[0] = prices[0];
  for (int i = 1; i < size; i++) {
    mins[i] = min(prices[i], mins[i - 1]);
    dp[i] = prices[i] - mins[i];
  }
  return *max_element(dp.begin(), dp.end());
}
*/
int maxProfit(vector<int>& prices) {
  int min_price = INT_MAX, max_profit = 0;
  for (int price : prices) {
    min_price = min(price, min_price);
    max_profit = max(max_profit, price - min_price);
  }
  return max_profit;
}
