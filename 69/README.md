### 69. Sqrt(x)

&emsp;&emsp;Implement `int sqrt(int x)`.

&emsp;&emsp;确保 x 是非负整数。返回值是 int 型，直接舍去小数部分。

#### 错解一

&emsp;&emsp;暴力循环法，超时。

#### 错解二

&emsp;&emsp;尝试二分。从 left = 0 到 right = x，取 mid = (left + right) / 2，然后判断 mid * mid 与 x 的大小。结果错误，发现 x 较大时，mid * mid 的值会溢出，溢出后也可正可负，无法判断。

#### 正解一 ：二分法

&emsp;&emsp;首先解决整数溢出的问题，主要有两点：

- 使用`mid = left + (right - left) / 2`代替`mid = (left + right) / 2`

- 使用`mid <= x / mid`代替`mid * mid <= x`

&emsp;&emsp;然后发现似乎可设`right = x / 2`，因为当 x ≥ 2 时，有 sqrt(x) ≤ x / 2；而 x ∈ {0, 1} 时，可直接返回自身。这里又有一坑！当 2 ≤ x ≤ 3 时，right = x / 2 = 1，第一次循环 mid = 0，之后的 x / mid 会出现除以 0 的错误。因此初始时设右边界`right = x / 2 + 1`或左边界`left = 1`均可解决。

&emsp;&emsp;最终程序如下

```cpp
int mySqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int left = 1, right = x / 2, res = 0;
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

#### 正解二 ：牛顿迭代法

&emsp;&emsp;主要思路：将 <img src="https://latex.codecogs.com/svg.latex?r=\sqrt{x}" title="r=\sqrt{x}" /> 转化为求 <img src="https://latex.codecogs.com/svg.latex?f(r)=r^2-x=0" title="f(r)=r^2-x=0" /> 的根。


&emsp;&emsp;在曲线 <img src="https://latex.codecogs.com/svg.latex?y=f(r)" title="y=f(r)" /> 上任取一点 <img src="https://latex.codecogs.com/svg.latex?(r_{0},f(r_{0}))(r_{0}\neq0)" title="(r_{0},f(r_{0}))(r_{0}\neq0)" />，则曲线上该点的切线方程为

&emsp;&emsp; <img src="https://latex.codecogs.com/svg.latex?y-f(r_{0})=f'(r_{0})(r-r_{0})" title="y-f(r_{0})=f'(r_{0})(r-r_{0})" />

令 y = 0，得该切线与 r 轴交于

&emsp;&emsp; <img src="https://latex.codecogs.com/svg.latex?r_{1}=r_{0}-\tfrac{f(r_{0})}{f'(r_{0})}=r_{0}-\tfrac{r_{0}^{2}-x}{2r_{0}}=(r_{0}&plus;\tfrac{x}{r_{0}})/2" title="r_{1}=r_{0}-\tfrac{f(r_{0})}{f'(r_{0})}=r_{0}-\tfrac{r_{0}^{2}-x}{2r_{0}}=(r_{0}+\tfrac{x}{r_{0}})/2" />

&emsp;&emsp;这个得到的交点 r1 是最终要求的 <img src="https://latex.codecogs.com/svg.latex?f(r)=r^2-x=0" title="f(r)=r^2-x=0" /> 的根的一次逼近，之后再以 r1 为基准继续逼近，只需迭代几步就能得到最终的结果。

&emsp;&emsp;可取初始点 r0 = x。而由正解一可知，也可从 r0 = x / 2 + 1 开始迭代。

```cpp
int mySqrt(int x) {
    long res = x / 2 + 1;
    while (res * res > x)
        res = (res + x / res) / 2;
    return res;
}
```

#### 正解三：0x5f375a86

&emsp;&emsp;基于牛顿迭代法的[超无解神奇算法](http://www.cnblogs.com/pkuoliver/archive/2010/10/06/1844725.html)

```cpp
int mySqrt(int x)
{
    float xfloat = float(x);
    float xhalf = 0.5f * xfloat;
    int i = *(int*)&xfloat;     // get bits for floating VALUE 
    i = 0x5f375a86 - (i >> 1);  // gives initial guess y0
    xfloat = *(float*)&i;       // convert bits BACK to float
    // Newton step, repeating increases accuracy
    xfloat = xfloat * (1.5f - xhalf * xfloat * xfloat);
    xfloat = xfloat * (1.5f - xhalf * xfloat * xfloat);

    int ret = 1 / xfloat;
    return ret * ret > x ? ret - 1 : ret;
}
```
