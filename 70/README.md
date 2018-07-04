
### 70. Climbing Stairs

-----

&emsp;&emsp;爬梯子，需要`n`步到达梯子顶，每次可爬 1 或 2 步，返回有多少方式可爬到梯子顶端。

**Example 1**

    Input: 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps
    
**Example 2**


    Input: 3
    Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step

-----

#### 错解一

&emsp;&emsp;首先想到递归，结果超时。

```cpp
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else 
        return climbStairs(n - 1) + climbStairs(n - 2);
}
```

-----

#### 正解一

&emsp;&emsp;将递归改成迭代，发现`f(n) = f(n - 1) + f(n - 2)`，本质就是`fibonacci`，就比较简单了。

```cpp
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    int res = 0;
    int n1 = 1, n2 = 2;
    for (int i = 3; i <= n; ++i) {
        res = n1 + n2;
        n1 = n2;
        n2 = res;
    }
    return res;
}
```
