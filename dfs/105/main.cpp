#include <cassert>

#include <algorithm>
#include <vector>

#include "data_structure.h"

using namespace std;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

int main() {
  vector<int> preorder{3, 9, 20, 15, 7};
  vector<int> inorder{9, 3, 15, 20, 7};
  TreeNode* root = buildTree(preorder, inorder);
}

TreeNode* buildTree(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2) {
  auto* root = new TreeNode(preorder[s1]);
  int pos = s2;
  while (inorder[pos] != preorder[s1]) {
    pos++;
  }
  if (pos - 1 >= s2) {
    root->left = buildTree(preorder, s1 + 1, s1 + pos - s2, inorder, s2, pos - 1);
  }
  if (pos + 1 <= e2) {
    root->right = buildTree(preorder, e1 - e2 + pos + 1, e1, inorder, pos + 1, e2);
  }
  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}
