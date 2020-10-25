### 300. Longest Increasing Subsequence

-----

&emsp;&emsp;给定一个无序的整数数组，找到其中最长上升子序列的长度。

-----

#### 正解 DP 时间O(n^2) 空间O(n)

&emsp;&emsp;dp[i] 表示以第 i 个数字为结尾的最长上升子序列的长度。

&emsp;&emsp;遍历到 dp[i] 时，应把 dp[0...i-1] 都看一遍，如果 nums[i] 大于之前的某个数，那么 nums[i] 就可以接在这个数后面形成一个更长的上升子序列。

&emsp;&emsp;dp 数组的最大值即为结果。