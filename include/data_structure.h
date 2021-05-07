#ifndef LEETCODE_DATA_STRUCTURE_H_
#define LEETCODE_DATA_STRUCTURE_H_

#include <initializer_list>

class ListNode {
 public:
  ListNode() = default;
  explicit ListNode(int x) : val(x) {}

  // tail_connect 表示链表尾节点的下一个元素位置, 形成环.
  static ListNode* Create(const std::initializer_list<int>& list,
                          int tail_connect=-1);
  static void Print(ListNode*);

 public:
  int val = 0;
  ListNode* next = nullptr;
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) :
  val(x), left(left), right(right) {}

  static TreeNode* Create(const std::initializer_list<int>& list);
};

#endif  // LEETCODE_DATA_STRUCTURE_H_
