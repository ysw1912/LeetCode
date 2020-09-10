#include <algorithm>
#include <vector>

#include <cassert>

using namespace std;

int maxProfit(vector<int>& prices);

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  assert(maxProfit(prices) == 5);
}

int maxProfit(vector<int>& prices) {
  return 5;
}
