#include <string>
#include <vector>

#include <cassert>

#include "utils.h"

using namespace std;

int numDecodings(string s);

int main() {
  assert(numDecodings("12") == 2);
  assert(numDecodings("10") == 1);
  assert(numDecodings("226") == 3);
}
/*
int numDecodings(string s) {
  if (s.empty() || s[0] == '0') {
    return 0;
  }
  int size = s.size();
  vector<int> dp(size, 0);
  for (int i = 0; i < size; i++) {
    if (s[i] >= '1' && s[i] <= '9') {
      dp[i] = i >= 1 ? dp[i - 1] : 1;
    }
    if (i > 0) {
      int n = stoi(s.substr(i - 1, 2));
      if (n >= 10 && n <= 26) {
        dp[i] += i >= 2 ? dp[i - 2] : 1;
      }
    }
  }
  cout << dp << endl;
  return dp[size - 1];
}
*/
int numDecodings(string s) {
  if (s[0] == '0') {
    return 0;
  }
  int size = s.size();
  int pre = 1, cur = 1;
  for (int i = 1; i < size; i++) {
    int tmp = cur;
    if (s[i] == '0') {
      if (s[i - 1] == '1' || s[i - 1] == '2')
        cur = pre;
      else
        return 0;
    } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
      cur += pre;
    }
    pre = tmp;
  }
  return cur;
}
