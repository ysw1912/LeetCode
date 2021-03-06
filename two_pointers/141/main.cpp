#include <cassert>
#include <iostream>

#include "data_structure.h"

bool hasCycle(ListNode *head);

int main() {
  ListNode* head;
  head = ListNode::Create({3, 2, 0, -4}, 1);
  assert(hasCycle(head));
  head = ListNode::Create({1, 2}, 0);
  assert(hasCycle(head));
  head = ListNode::Create({1});
  assert(!hasCycle(head));
  return 0;
}

bool hasCycle(ListNode* head) {
  ListNode* p = head;
  ListNode* q = head;
  while (q && q->next) {
    p = p->next;
    q = q->next->next;
    if (q && p == q) return true;
  }
  return false;
}
