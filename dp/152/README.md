### 152. Maximum Product Subarray

-----

&emsp;&emsp;给定数组 nums，找出数组中乘积最大的连续子数组所对应的乘积。

-----

#### 正解一 DP 时间O(n) 空间O(n)

&emsp;&emsp;乘积可以有负数，负数可以把一个很小的负数乘成一个很大的正数，也可以把一个很大的正数乘成一个很小的负数。

&emsp;&emsp;因此为了求最大成绩，DP 时需要要同时存储上一次的最大值和最小值。
- dp[0][i] 表示 nums[0..i-1] 中子数组的乘积最大值。
- dp[1][i] 表示 nums[0..i-1] 中子数组的乘积最小值。

&emsp;&emsp;状态转移为：
- dp[0][i] = MAX(dp[0][i - 1] * nums[i], dp[1][i - 1] * nums[i], nums[i])
- dp[1][i] = MIN(dp[0][i - 1] * nums[i], dp[1][i - 1] * nums[i], nums[i])

#### 正解二 DP 时间O(n) 空间O(1)

&emsp;&emsp;由于 DP 数组状态转移中 i 只与 i - 1 有关，可降维。
