### 309. Best Time to Buy and Sell Stock with Cooldown

-----

&emsp;&emsp;给定一个数组 prices，prices[i] 代表了第 i 天的股票价格 。计算出最大利润。

&emsp;&emsp;卖出股票后，无法在第二天买入股票 (即冷冻期为 1 天)。

-----

#### 正解一 DP 时间O(n) 空间O(n)

&emsp;&emsp;DP 数组 dp[i]：第 0 ~ i 天的最大收益，每天有三种状态：持有股票、不持有股票、卖出股票。
            
- dp[i][0]：第 i 天“持有股票”时，所能获得的最大收益；
- dp[i][1]：第 i 天“未持有股票”时，所能获得的最大收益；
- dp[i][2]：第 i 天“卖出股票”时，所能获得的最大收益；

&emsp;&emsp;初始条件是，如果第 0 天“持有股票”，则收益为 -prices[0]；如果第 0 天“未持有股票”和“卖出股票”，收益为 0。

&emsp;&emsp;递推公式是，

- 如果第 i 天是“持有股票”，则可能是①第 i - 1 天也“持有股票”，第 i 天什么都不做；②第 i - 1 天“未持有股票”，则第 i 天需要买入；不可能是第 i - 1 天“卖出股票”。
- 如果第 i 天是“未持有股票”，则可能是①第 i - 1 天“未持有股票”，②第 i - 1 天“卖出股票”，第 i 天什么都不做。
- 如果第 i 天是“卖出股票”，则可能是第 i - 1 天“持有股票”，第 i 天需要卖出。

&emsp;&emsp;最终最大收益的情况肯定是最后一天“未持有股票”或“卖出股票”，因此是 max(dp[size - 1][1], dp[size - 1][2])。

#### 正解二 DP 时间O(n) 空间O(1)

&emsp;&emsp;状态转移方程中 i 只与 i - 1 有关，可降维。
