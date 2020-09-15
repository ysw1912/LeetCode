### 121. Best Time to Buy and Sell Stock

-----

&emsp;&emsp;给定一个数组，prices[i] 是一支股票第 i 天的价格。
            
&emsp;&emsp;最多只允许完成一笔交易（即买入和卖出股票一次），计算所能获取的最大利润。

```text
输入: [7, 1, 5, 3, 6, 4]
输出: 5
解释: 第 2 天买入，第 5 天卖出，最大利润 = 6 - 1 = 5
```

-----

#### 正解一 DP

&emsp;&emsp;用一个变量记录历史最低价格 min，那么在第 i 天卖出股票能得到的利润就是 prices[i] - min。

&emsp;&emsp;遍历求该利润的最大值即可。Easy 题。
