### 69. Sqrt(x)

&emsp;&emsp;Implement `int sqrt(int x)`.

&emsp;&emsp;确保 x 是非负整数。返回值是 int 型，直接舍去小数部分。

#### 错解一

&emsp;&emsp;暴力循环法，超时。

#### 错解二

&emsp;&emsp;尝试二分。从 left = 0 到 right = x，取 mid = (left + right) / 2，然后判断 mid * mid 与 x 的大小。结果错误，发现 x 较大时，mid * mid 的值会溢出，溢出后也可正可负，无法判断。

#### 正解一  

&emsp;&emsp;首先解决整数溢出的问题，主要有两点：

- 使用`mid = left + (right - left) / 2`代替`mid = (left + right) / 2`

- 使用`mid <= x / mid`代替`mid * mid <= x`

&emsp;&emsp;然后发现 right 可以从 x / 2 开始，因为当 x ≥ 2 时，sqrt(x) ≤ x / 2；而 x == 1 or 0 则可以直接返回自身。然后这里又有一坑，当 2 ≤ x ≤ 3 时，x / 2 == 1，此时得出 mid = 0，x / mid 会出现除以 0 的错误。于是最终把右边界 right 设为`x / 2 + 1`。

&emsp;&emsp;最终程序如下

```cpp
int mySqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int left = 0, right = x / 2 + 1, res = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;     
        if (mid <= x / mid) {
            res = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return res;
}
```
