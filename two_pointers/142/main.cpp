#include <cassert>
#include <iostream>

#include "data_structure.h"

ListNode *detectCycle(ListNode *head);

int main() {
  ListNode* head;
  head = ListNode::Create({3, 2, 0, -4}, 1);
  assert(detectCycle(head)->val == 2);
  head = ListNode::Create({1, 2}, 0);
  assert(detectCycle(head)->val == 1);
  head = ListNode::Create({1});
  assert(!detectCycle(head));
  return 0;
}

ListNode *detectCycle(ListNode *head) {
  ListNode* p = head;
  ListNode* q = head;
  while (q && q->next) {
    p = p->next;
    q = q->next->next;
    if (p == q) {
      p = head;
      while (p != q) {
        p = p->next;
        q = q->next;
      }
      return p;
    }
  }
  return nullptr;
}
