### 234. Palindrome Linked List

-----

&emsp;&emsp;给定一个单链表，判断它是否是回文。时间复杂度基本为 O(n)，本题希望空间复杂度 O(1) 而不是 O(n)。

-----

#### 正解一 O(n)

&emsp;&emsp;递归黑科技。

详见代码。

-----

#### 正解二 O(1)

&emsp;&emsp;双指针 + 链表逆序。

- 链表逆序 Code：
```cpp
ListNode* Reverse(ListNode* head) {
  ListNode *pre = nullptr, *next = nullptr;
  while (head) {
    next = head->next;
    head->next = pre;
    pre = head;
    head = next;
  }
  return pre;
}
```

- 双指针一快一慢，fast 一轮两步，slow 一轮一步，同时对 slow 进行逆序。有两种结果：
```text
链表长为奇数[ 1 <- 2 <- 3 -> 4 -> 5 ]
                   p    s         f
此时将 slow = slow->next 变为
            [ 1 <- 2 <- 3 -> 4 -> 5 ]
                   p         s    f

链表长为偶数[ 1 <- 2 <- 3 <- 4 -> 5 -> 6 ]
                       p    s           f
```
slow 和 pre 同时遍历下去，判断值是否相等。
