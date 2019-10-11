#include <cassert>
#include <iostream>

#include "data_structure.h"

bool isPalindrome(ListNode* head);

int main() {
  ListNode* head;
  head = ListNode::Create({1, 2, 2, 1});
  assert(isPalindrome(head));
  head = ListNode::Create({1, 2, 3, 2, 1});
  assert(isPalindrome(head));
  head = ListNode::Create({1, 2, 3, 4, 1});
  assert(!isPalindrome(head));
}

/*
bool isPalindrome(ListNode* head) {
  ListNode *fast = head, *slow = head;
  ListNode *pre = nullptr, *next;
  while (fast && fast->next) {
    fast = fast->next->next;
    next = slow->next;
    slow->next = pre;
    pre = slow;
    slow = next;
  }
  if (fast) {
    slow = slow->next;
  }
  while (pre) {
    if (slow->val != pre->val) return false;
    slow = slow->next;
    pre = pre->next;
  }
  return true;
}
*/

bool isPalindromeInternal(ListNode* p, ListNode** temp) {
  if (p == nullptr) return true;
  bool isPal = isPalindromeInternal(p->next, temp) && ((*temp)->val == p->val);
  *temp = (*temp)->next;
  return isPal;
}

bool isPalindrome(ListNode* head) {
  ListNode** temp = &head;
  return isPalindromeInternal(head, temp);
}
