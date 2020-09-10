#include <algorithm>
#include <vector>

#include <cassert>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle);

int main() {
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  assert(minimumTotal(triangle) == 11);
}

/* 正解一
int minimumTotal(vector<vector<int>>& triangle) {
  if (triangle.empty()) {
    return 0;
  }
  vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size()));
  dp[0][0] = triangle[0][0];
  for (size_t i = 1; i < triangle.size(); i++) {
    dp[i][0] = dp[i - 1][0] + triangle[i][0];
    dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    for (size_t j = 1; j < i; j++) {
      dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
    }
  }
  return *min_element(dp.back().begin(), dp.back().end());
}
*/

int minimumTotal(vector<vector<int>>& triangle) {
  if (triangle.empty()) {
    return 0;
  }
  vector<int> dp(triangle.back().size());
  dp[0] = triangle[0][0];
  for (size_t i = 1; i < triangle.size(); i++) {
    dp[i] = dp[i - 1] + triangle[i][i];
    for (size_t j = i - 1; j > 0; j--) {
      dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
    }
    dp[0] = dp[0] + triangle[i][0];
  }
  return *min_element(dp.begin(), dp.end());
}
