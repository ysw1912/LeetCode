#include <tuple>

#include <cassert>

#include "data_structure.h"

using namespace std;

ListNode* reverseKGroup(ListNode* head, int k);

int main() {
  ListNode* head = ListNode::Create({1, 2, 3, 4, 5});
  ListNode* head2 = ListNode::Create({2, 1, 4, 3, 5});
  head = reverseKGroup(head, 2);
  while (head2) {
    assert(head2->val == head->val);
    head2 = head2->next;
    head = head->next;
  }
}

pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
  ListNode* prev = nullptr;
  ListNode* curr = head;
  while (curr != tail) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  curr->next = prev;
  return {tail, head};
}

ListNode* reverseKGroup(ListNode* head, int k) {
  if (!head || k == 1) {
    return head;
  }

  auto* dummy = new ListNode();
  dummy->next = head;

  ListNode* prev = dummy;
  ListNode* next = head;

  while (next) {
    ListNode* tail = head;
    int i = k;
    while (tail && --i) {
      tail = tail->next;
    }
    if (i == 0) {
      assert(tail);
      next = tail->next;
      tie(head, tail) = reverse(head, tail);
      tail->next = next;
    } else {
      next = nullptr;
    }

    prev->next = head;
    prev = tail;
    head = next;
  }

  ListNode* ret = dummy->next;
  delete dummy;
  return ret;
}
