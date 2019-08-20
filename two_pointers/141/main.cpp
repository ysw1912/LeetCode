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
  ListNode* q = head ? head->next : nullptr;
  while (q) {
    if (p == q) return true;
    if (q->next) {
      q = q->next->next;
    } else {
      return false;
    }
    p = p->next;
  }
  return false;
}
