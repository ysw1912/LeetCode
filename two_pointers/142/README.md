### 142. Linked List Cycle II

-----

&emsp;&emsp;判断链表是否有环，返回环的入口位置。

-----

#### 正解

&emsp;&emsp;双指针 p 一次 1 step，q 一次 2 step，如果链表有环则 p、q 会在环中汇合，这里设汇合点为 meet。

![判断有环](https://github.com/ysw1912/LeetCode/blob/master/two_pointers/142/1.png)

&emsp;&emsp;接下来要找到环的入口：

1. 一种想法是，将该问题转化为求两个链表的交汇点，一条链表是 head -> ... -> meet，另一条是 meet -> ... -> meet。
   
   这种方法的小缺点是需要遍历 2 次链表，复杂度为 O(2n)。
   
2. 最好的方法需要用到一些数学推导。如图，假设 head 到环的入口的步长为 m，入口到 meet 的步长为 k，环的一圈步长为 r。

   ![寻找入口](https://github.com/ysw1912/LeetCode/blob/master/two_pointers/142/2.png)
   
   则 p 走过了 m + k + P * r 步，q 走过了 m + k + Q * r 步，其中 P、Q 均为自然数。
   
   并且 q 走过的步长是 p 的 2 倍，所以 m + k + Q * r = 2 * (m + k + P * r)，可知 (Q - 2P) * r = m + k，即 N * r = m + k。
   
   也就是说，从 head 走到环入口的步长是环的长度的整数倍。如果让 p 从 head 出发，q 从 meet 出发，每次都只走 1 step，当 p 走过 m + k 步到达 meet 时，q 也一定会重新回到 meet，再往前倒退几步的话，p、q一定会在环的入口出相遇。
   
   所以直接让 p 从 head 出发，q 从 meet 出发，他们第一次相遇的位置，即为环的入口，复杂度为 O(n)。