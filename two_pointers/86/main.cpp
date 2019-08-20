#include <iostream>

#include "data_structure.h"

ListNode* partition(ListNode* head, int x);

int main() {
  ListNode* head;
  head = ListNode::Create({1, 4, 3, 2, 5, 2});
  ListNode::Print(partition(head, 3));
  head = ListNode::Create({1, 1});
  ListNode::Print(partition(head, 2));
  return 0;
}

ListNode* partition(ListNode* head, int x) {
  if (!head) return head;
  ListNode *p = head, *left = nullptr, *right = nullptr;
  while (p) {
    if (p->val < x) {
      ListNode **p_next = nullptr;
      if (!left) {
        p_next = &head;
      } else {
        p_next = &left->next;
      }
      if (right) {  // 需要插入.
        right->next = p->next;
        p->next = *p_next;
      }
      *p_next = p;
      left = p;
    } else {
      right = p;
    }
    if (right) {
      p = right->next;
    } else {
      p = left->next;
    }
    std::cout << "[DEBUG] ";
    ListNode::Print(head);
  }
  return head;
}
