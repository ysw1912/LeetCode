### 406. Queue Reconstruction by Height

-----

&emsp;&emsp;有一个被打乱顺序的队列。每个元素用一个整数对 (h, k) 表示，其中 h 是这个人的身高，k 是排在这个人前面且身高 ≥ h 的人数。

&emsp;&emsp;将这个队列重新排列至正确的顺序。

&emsp;&emsp;实例：

```text
输入:
[[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
输出:
[[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
```

-----

#### 正解一

&emsp;&emsp;核心思路：

- 先排身高更高的，矮个子的人看不见高个子的人，因此矮个子后面插入对之前的结果不会有影响。
- 而每次排入新人 [h, k] 时，已处于队列中的人身高都 >= h，所以新排入位置就是 k。

使用 list 进行插入效率相比 vector 更高，最后再转为 vector 即可。

时间复杂度，由于有排序，因此是 O(nlogn)。
