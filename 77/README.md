77. Combinations

-----

&emsp;&emsp;给定两个整数 n 和 k，返回 1 到 n 中所有可能的 k 个数的组合。

**Example**

    Input: n = 4, k = 2
    Output: 
    [
      [1,2],
      [1,3],
      [1,4],
      [2,3],
      [2,4],
      [3,4]
    ]

-----

#### 正解一

&emsp;&emsp;我自己的想法是：利用 fill_vector() 一次次地向 vec 中填入一个元素，填够了后就 res.push_back(vec)。

&emsp;&emsp;初始时 vec 里没有元素，第一次可以填入的数为 1 到 n - k + 1，例子中 n = 4，k = 2，那么第一次填入的数可以是 1 到 3 (4 - 2 + 1)。如果第一次填入 4，由于 k = 2，第二次无数可填入。

&emsp;&emsp;进入 fill_vector() 后，将传入的 last 填入 vec，并判断 vec 中是否已经有 k 个数字，如果足够，则 res.push_back(vec) 并返回。如果不够，需要继续寻找可填入的下一个数字，并调用自己填入这个数。

1. 当前 vec 的最后一个数是刚填入的 last，因此下一个可填入的数最小为 last + 1；
2. 当前 vec 已有 len 个数，还需要 k - len 个数才足够，如果这 k - len 个数都从 1 到 n 的最末尾取，那下一个可填入的数最大为 n - (k - len - 1)。

&emsp;&emsp;fill_vector() 函数 res 是引用传递，vec 是值传递，是一种 DFS 的思想。

```cpp
void fill_vector(int n, int k, vector<vector<int>>& res, vector<int> vec, int last)
{
    vec.push_back(last);
    int len = vec.size();
    if (len == k) {
        res.push_back(vec);
        return;
    }
    for (int num = last + 1; num <= n - k + len + 1; ++num) {
        fill_vector(n, k, res, vec, num);
    }
}

vector<vector<int>> combine(int n, int k)
{
    if (k == 0)
        return {};
    vector<vector<int>> res;
    vector<int> vec;
    for (int num = 1; num <= n - k + 1; ++num)
        fill_vector(n, k, res, vec, num);
    return res;
}
```

#### 正解二

&emsp;&emsp;后来看到别人的代码，也是类似的思想，但 vec 都是传引用，原来只要在每一次调用自己之后，把刚填入的最后一个元素 pop_back 掉，再继续执行循环就行了。这样不需要多次对 vec 进行拷贝构造，时间、空间效率都高上不少。

```cpp
void fill_vector(int n, int k, vector<vector<int>>& res, vector<int>& vec, int last)
{
    vec.push_back(last);
    int len = vec.size();
    if (len == k) {
        res.push_back(vec);
        return;
    }
    for (int num = last + 1; num <= n - k + len + 1; ++num) {
        fill_vector(n, k, res, vec, num);
        vec.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    if (k == 0)
        return {};
    vector<vector<int>> res;
    vector<int> vec;
    for (int num = 1; num <= n - k + 1; ++num) {
        fill_vector(n, k, res, vec, num);
        vec.pop_back();
    }
    return res;
}
```

#### 正解三

&emsp;&emsp;看到一个很天才的代码，不多说，看例子。

&emsp;&emsp;例如 n = 4，k = 2。初始 vec = {0, 0}

{0, 0} → {1, 0} → {1, 1} → {1, 2} OK

{1, 2} → {1, 3} OK

{1, 3} → {1, 4} OK

{1, 4} → {1, 5} →  {2, 5} → {2, 2} → {2, 3} OK

{2, 3} → {2, 4} OK

{2, 4} → {2, 5} → {3, 5} → {3, 3} → {3, 4} OK

{3, 4} → {3, 5} → {4, 5} → {4, 4} → {4, 5} → {5, 5} → i = -1 end

```cpp
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    int i = 0;
    vector<int> vec(k, 0);
    while (i >= 0) {
        vec[i]++;
        if (vec[i] > n) 
            --i;
        else if (i == k - 1)
            res.push_back(vec);
        else {
            ++i;
            vec[i] = vec[i - 1];
        }
    }
    return res;
}
```
