#include <cassert>

#include <functional>

#include "data_structure.h"

using namespace std;

TreeNode* sortedListToBST(ListNode* head);

int main() {
  ListNode* list = nullptr;
  assert(sortedListToBST(list) == nullptr);
  list = ListNode::Create({0});
  sortedListToBST(list);
  list = ListNode::Create({1, 3});
  sortedListToBST(list);
  list = ListNode::Create({-10, -3, 0, 5, 9});
  sortedListToBST(list);
}

TreeNode* sortedListToBST(ListNode* head) {
  function<TreeNode*(ListNode*, ListNode*)> transform = [&](ListNode* head, ListNode* tail) -> TreeNode* {
      if (!head || head == tail) return nullptr;
      ListNode* p = head;
      ListNode* q = head;
      while (q != tail) {
        q = q->next;
        if (q == tail) break;
        p = p->next;
        q = q->next;
      }
      auto* root = new TreeNode(p->val);
      root->left = transform(head, p);
      root->right = transform(p->next, tail);
      return root;
  };
  return transform(head, nullptr);
}
