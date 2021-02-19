#include <cassert>

#include <vector>

#include "data_structure.h"

using namespace std;

bool isValidBST(TreeNode* root);

int main() {
  TreeNode* root;
  root = TreeNode::Create({2, 1, 3});
  assert(isValidBST(root));
  root = TreeNode::Create({1, 1, -1});
  assert(!isValidBST(root));
  root = TreeNode::Create({5, 1, 4, -1, -1, 3, 6});
  assert(!isValidBST(root));
  root = TreeNode::Create({5, 4, 6, -1, -1, 3, 7});
  assert(!isValidBST(root));
}

bool isValidBST(TreeNode* root, int*& prev) {
  if (root->left && !isValidBST(root->left, prev)) {
    return false;
  }
  if (!prev) {
    prev = new int(root->val);
  } else if (*prev < root->val) {
    *prev = root->val;
  } else {
    return false;
  }
  return !(root->right && !isValidBST(root->right, prev));
}

bool isValidBST(TreeNode* root) {
  if (!root) {
    return false;
  }
  int* prev = nullptr;
  return isValidBST(root, prev);
}
