#include <algorithm>
#include <vector>

#include <cassert>

using namespace std;

int countNumbersWithUniqueDigits(int n);

int main() {
  assert(countNumbersWithUniqueDigits(2) == 91);
}

int countNumbersWithUniqueDigits(int n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return 10;
  }
  n = min(10, n);
  vector<int> dp(n + 1);
  dp[0] = 1;
  dp[1] = 9;
  int ans = 10;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] * (10 - i + 1);
    ans += dp[i];
  }
  return ans;
}
