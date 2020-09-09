#include <vector>

#include "data_structure.h"

using namespace std;

vector<TreeNode*> generateTrees(int n);

int main() {

}
/* 正解一
int numTrees(int start, int end) {
  if (start > end) {
    return 1;
  }
  int ans = 0;
  for (int i = start; i <= end; i++) {
    int left = numTrees(start, i - 1);
    int right = numTrees(i + 1, end);
    ans += left * right;
  }
  return ans;
}

int numTrees(int n) {
  if (n == 0) {
    return 0;
  }
  return numTrees(1, n);
}
*/
// 正解二 DP
TreeNode* clone(TreeNode* root, int offset) {
  if (!root) {
    return nullptr;
  }
  return new TreeNode(root->val + offset, clone(root->left, offset), clone(root->right, offset));
}

int numTrees(int n) {
  if (n == 0) {
    return 0;
  }
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i] += dp[j - 1] * dp[i - j];
    }
  }
  return dp[n];
}
