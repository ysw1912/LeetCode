### 455. Assign Cookies

-----

&emsp;&emsp;给孩子分饼干，每个孩子最多只能给一块饼干。

&emsp;&emsp;每个孩子 i 都有一个胃口值 gi，每块饼干 j 都有一个尺寸 sj。如果 sj ≥ gi，则孩子会得到满足。

&emsp;&emsp;尽可能满足越多数量的孩子，并输出这个最大值。

-----

#### 正解 贪心

&emsp;&emsp;Easy 题。

&emsp;&emsp;将胃口 g 数组和饼干 s 数组从小到大的排序。

&emsp;&emsp;遍历两个数组：

- 如果当前 g[i] <= s[j]，则可以满足该孩子的胃口，result++，i++，j++。
- 否则，j++，看下一个饼干的大小能否满足对应孩子的胃口。

当 i 或 j 到达结尾时，返回结果值result。
