#include <algorithm>
#include <vector>

#include <cassert>

using namespace std;

int integerBreak(int n);

int main() {
  assert(integerBreak(2) == 1);
  assert(integerBreak(10) == 36);
}

int integerBreak(int n) {
  vector<int> dp(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i / 2; j++) {
      dp[i] = max(dp[i], j * max(i - j, dp[i - j]));
    }
  }
  return dp.back();
}
