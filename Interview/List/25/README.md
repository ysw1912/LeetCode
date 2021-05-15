### 25. Reverse Nodes in k-Group

-----

&emsp;&emsp;链表每 k 个节点一组进行翻转。

```text
输入: head = [1, 2, 3, 4, 5], k = 2
输出: [2, 1, 4, 3, 5]

输入：head = [1, 2, 3, 4, 5], k = 3
输出：[3, 2, 1, 4, 5]
解释：4, 5 长度小于 3，不翻转
```

-----

#### 正解

&emsp;&emsp;以 head = [1, 2, 3, 4, 5], k = 3 为例：
```text
1 -> 2 -> 3 -> 4 -> 5 -> null
```
创建 dummy 头节点，这样最后直接返回 dummy->next 即可。
```text
       head
         ↓
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> null
```
对于每个组（3个节点），有其头节点 head 和尾节点 tail，先保存 `next = tail->next`。
```text
       head      tail
         ↓        ↓
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> null
  ↑                    ↑
 prev                  next
```
对 head ... tail 之间的节点做普通的翻转，并让 head、tail 对调。
再把 prev 和 head 接起来，tail 和 next 接起来。
```text
       head      tail
         ↓        ↓
dummy -> 3 -> 2 -> 1 -> 4 -> 5 -> null
  ↑                    ↑
 prev                  next
```
将 prev 移到 tail，head 移到 next 进行下一轮。

下轮计算 tail、next 时若发现长度不足 k，则不必翻转。
