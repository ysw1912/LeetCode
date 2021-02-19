#include "data_structure.h"

#include <cassert>
#include <iostream>
#include <vector>

ListNode* ListNode::Create(const std::initializer_list<int>& list,
    int tail_connect) {
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  ListNode* tail_next = nullptr;
  for (auto it = list.begin(); it != list.end(); ++it) {
    if (tail == nullptr) {
      tail = new ListNode(*it);
    } else {
      tail->next = new ListNode(*it);
      tail = tail->next;
    }
    if (it - list.begin() == tail_connect) tail_next = tail;
    if (!head) head = tail;
  }
  if (tail) tail->next = tail_next;
  return head;
}

void ListNode::Print(ListNode* head) {
  while (head) {
    std::cout << head->val << ' ';
    head = head->next;
  }
  std::cout << '\n';
}

TreeNode* TreeNode::Create(const std::initializer_list<int>& list) {
  size_t size = list.size();
  assert((size & (size + 1)) == 0);
  std::vector<TreeNode*> nodes;
  nodes.reserve(size);
  for (int x : list) {
    nodes.emplace_back(x != -1 ? new TreeNode(x) : nullptr);
  }
  for (size_t i = 0; i < size / 2; i++) {
    nodes[i]->left = nodes[2 * i + 1];
    nodes[i]->right = nodes[2 * i + 2];
  }
  return nodes.empty() ? nullptr : nodes.front();
}
