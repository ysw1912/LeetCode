#include <cassert>

#include "data_structure.h"

using namespace std;

ListNode* reverseList(ListNode* head);

int main() {
  ListNode* head = ListNode::Create({1, 2, 3, 4, 5});
  ListNode* head2 = ListNode::Create({5, 4, 3, 2, 1});
  head = reverseList(head);
  while (head2) {
    assert(head2->val == head->val);
    head2 = head2->next;
    head = head->next;
  }
}

ListNode* reverseList(ListNode* head) {
  ListNode* prev = nullptr;
  while (head) {
    ListNode* next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}
