#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

#include <cassert>

using namespace std;

int coinChange(vector<int>& coins, int amount);

int main() {
  vector<int> coins = {1, 2, 5};
  assert(coinChange(coins, 11) == 3);
  coins = {2};
  assert(coinChange(coins, 3) == -1);
  coins = {1};
  assert(coinChange(coins, 0) == 0);
  assert(coinChange(coins, 1) == 1);
  assert(coinChange(coins, 2) == 2);
  coins = {186, 419, 83, 408};
  assert(coinChange(coins, 6249) == 20);
  coins = {288, 160, 10, 249, 40, 77, 314, 429};
  assert(coinChange(coins, 9208) == 22);
}
/* 正解一
int coinChange(vector<int>& coins, int amount) {
  if (amount == 0) {
    return 0;
  }
  if (coins.empty()) {
    return -1;
  }
  vector<int> cache(amount + 1, INT_MAX);
  int min_coin = *min_element(coins.begin(), coins.end());
  function<int(int)> dp = [&](int money) {
    if (money < min_coin) {
      return -1;
    }
    if (cache[money] != INT_MAX) {
      return cache[money];
    }
    int ret = INT_MAX;
    bool can_add = false;
    for (int coin : coins) {
      if (money == coin) {
        cache[money] = 1;
        return 1;
      }
      int tmp = dp(money - coin);
      if (tmp != -1) {
        ret = min(ret, tmp + 1);
        can_add = true;
      }
    }
    cache[money] = can_add ? ret : -1;
    return cache[money];
  };
  return dp(amount);
}
*/
/* 正解二
int coinChange(vector<int>& coins, int amount) {
  if (amount == 0) {
    return 0;
  }
  if (coins.empty()) {
    return -1;
  }
  vector<int> dp(amount + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= amount; i++) {
    for (int coin : coins) {
      if (i == coin) {
        dp[i] = 1;
        break;
      } else if (i > coin && dp[i - coin] != INT_MAX) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
  }
  return dp[amount] == INT_MAX ? -1 : dp[amount];
}
*/

int coinChange(vector<int>& coins, int amount) {
  if (amount == 0) {
    return 0;
  }
  if (coins.empty()) {
    return -1;
  }
  sort(coins.rbegin(), coins.rend());
  int res = INT_MAX;
  function<void(int, int, int)> dfs = [&](int idx, int money, int current) {
      if (money == 0) {
        res = current;
        return;
      }
      if (idx == coins.size()) {
        return;
      }
      for (int i = money / coins[idx]; i >= 0 && current + i < res; i--) {
        dfs(idx + 1, money - i * coins[idx], current + i);
      }
  };
  dfs(0, amount, 0);
  return res == INT_MAX ? -1 : res;
}
