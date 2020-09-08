#include <string>
#include <vector>

#include <cassert>

#include "data_structure.h"

using namespace std;

vector<TreeNode*> generateTrees(int n);

int main() {

}
/* 正解一
vector<TreeNode*> generateTrees(int start, int end) {
  if (start > end) {
    return {nullptr};
  }
  vector<TreeNode*> ans;
  for (int i = start; i <= end; i++) {
    vector<TreeNode*> lefts = generateTrees(start, i - 1);
    vector<TreeNode*> rights = generateTrees(i + 1, end);
    for (TreeNode* left : lefts) {
      for (TreeNode* right : rights) {
        ans.push_back(new TreeNode(i, left, right));
      }
    }
  }
  return ans;
}

vector<TreeNode*> generateTrees(int n) {
  if (n == 0) {
    return {};
  }
  return generateTrees(1, n);
}
*/

// 正解二 DP
TreeNode* clone(TreeNode* root, int offset) {
  if (!root) {
    return nullptr;
  }
  return new TreeNode(root->val + offset, clone(root->left, offset), clone(root->right, offset));
}

vector<TreeNode*> generateTrees(int n) {
  if (n == 0) {
    return {};
  }
  vector<vector<TreeNode*>> dp(n + 1);
  dp[0] = {nullptr};
  for (int i = 1; i <= n; i++) {
    // 将不同的数字作为根节点，只需要考虑到 i
    for (int j = 1; j <= i; j++) {
      for (TreeNode* l : dp[j - 1]) {   // j - 1 左子树的长度
        for (TreeNode* r : dp[i - j]) { // i - j 右子树的长度
          // 克隆右子树并加上偏差
          dp[i].push_back(new TreeNode(j, l, clone(r, j)));
        }
      }
    }
  }
  return dp[n];
}
