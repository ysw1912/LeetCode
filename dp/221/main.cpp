#include <algorithm>
#include <vector>
#include <iostream>

#include <cassert>
#include <cmath>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix);

int main() {
  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}};
  assert(maximalSquare(matrix) == 4);
  matrix = {{'0', '0', '0', '1'},
            {'1', '1', '0', '1'},
            {'1', '1', '1', '1'},
            {'0', '1', '1', '1'},
            {'0', '1', '1', '1'}};
  assert(maximalSquare(matrix) == 9);
}
/* 正解一
int maximalSquare(vector<vector<char>>& matrix) {
  if (matrix.empty()) {
    return 0;
  }
  vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
  int ans = 0;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] == '0') {
        continue;
      }
      if (i == 0 || j == 0) {
        dp[i][j] = 1;
        ans = max(ans, dp[i][j]);
        continue;
      }
      int a = dp[i - 1][j - 1], b = dp[i - 1][j], c = dp[i][j - 1];
      if (a > 0 && b > 0 && c > 0) {
        int n = sqrt(min(a, min(b, c)));
        dp[i][j] = (n + 1) * (n + 1);
      } else {
        dp[i][j] = 1;
      }
      ans = max(ans, dp[i][j]);
    }
  }
  return ans;
}
*/
int maximalSquare(vector<vector<char>>& matrix) {
  if (matrix.empty()) {
    return 0;
  }
  vector<int> dp(matrix[0].size(), 0);
  int ans = 0;
  int left_up = 0;
  for (int i = 0; i < matrix.size(); i++) {
    left_up = dp[0];
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] == '0') {
        dp[j] = 0;
        continue;
      }
      if (i == 0 || j == 0) {
        dp[j] = 1;
        ans = max(ans, dp[j]);
        continue;
      }
      int a = dp[i - 1][j - 1], b = dp[i - 1][j], c = dp[i][j - 1];
      if (a > 0 && b > 0 && c > 0) {
        int n = sqrt(min(a, min(b, c)));
        dp[i][j] = (n + 1) * (n + 1);
      } else {
        dp[i][j] = 1;
      }
      ans = max(ans, dp[i][j]);
    }
  }
  return ans;
}
