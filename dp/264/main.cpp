#include <vector>

#include <cassert>

using namespace std;

int nthUglyNumber(int n);

int main() {
  assert(nthUglyNumber(10) == 12);
}

int nthUglyNumber(int n) {
  vector<int> dp(n);
  dp[0] = 1;
  int idx2 = 0, idx3 = 0, idx5 = 0;
  for (int i = 1; i < n; i++) {
    int num2 = dp[idx2] * 2, num3 = dp[idx3] * 3, num5 = dp[idx5] * 5;
    int ugly = min(min(num2, num3), num5);
    dp[i] = ugly;
    // 三个判断都执行
    // 若两个指针各自乘积后的结果相同时，两个指针都会向后移一位
    if (ugly == num2) {
      idx2++;
    }
    if (ugly == num3) {
      idx3++;
    }
    if (ugly == num5) {
      idx5++;
    }
  }
  return dp.back();
}
