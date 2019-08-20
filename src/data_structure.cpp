#include "data_structure.h"

#include <iostream>

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
