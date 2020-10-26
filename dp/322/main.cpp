#include <algorithm>
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
}

int coinChange(vector<int>& coins, int amount) {

}
