### 209. Minimum Size Subarray Sum

-----

&emsp;&emsp;给定一个数组和一个正整数 s，找出该数组中满足其和 ≥ s 的长度最小的连续子数组的长度。如果不存在符合条件的连续子数组，返回 0。

-----

#### 正解一 O(nlogn)

&emsp;&emsp;基于不等式推导的方法，使用了二分查找因此复杂度为 O(nlogn)。

- 维护一个 sums 数组
  - sums[0] = 0
  - sums[i] = nums[0] + ... + nums[i - 1], i > 0
- 对于每个 sums[i] >= s（sums 数组单调递增，可从后往前遍历），通过二分查找找到第一个 j，使得 sums[j] > sums[i] - s，`int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();`；
  
  此时 sums[j - 1] ≤ sums[i] - s，代入 sums 数组的定义式，可知
  
  - nums[0] + ... + nums[j - 1] > nums[0] + ... + nums[j - 1] + nums[j] + ... + nums[i - 1] - s
  - nums[0] + ... + nums[j - 2] ≤ nums[0] + ... + nums[j - 2] + nums[j - 1] + ... + nums[i - 1] - s
  
  不等式两边同时减去左边，可知
  
  - 0 > nums[j] + ... + nums[i - 1] - s，即 nums[j] + ... + nums[i - 1] < s
  - 0 ≤ nums[j - 1] + ... + nums[i - 1] - s，即 nums[j - 1] + ... + nums[i - 1] ≥ s
  
  因此 nums[j-1 ... i-1]是和大于等于 s 的最短子数组
  
- 对于每个 i，记录 `len = min(len, i - j + 1);`。

-----

#### 正解二 O(nlogn)

&emsp;&emsp;基于二分查找以及窗口的思想。

- 二分查找的循环框架 `int mid = (i + j) / 2;`，对于每个 mid，使用 WindowExist() 判断 nums 数组中是否存在长度为 mid 的子数组满足要求。
  - 如果存在，则继续缩小窗口尺寸；
  - 如果不存在，则扩大窗口尺寸。
  
注意，这里的 mid 是数组长度，因此 i 可以从 1 开始。

-----

#### 正解三 O(n)

&emsp;&emsp;主流方法，双指针 i 和 j 直接滑动窗口。
- 外层循环，右移 j，`sum += nums[j++];`，直到 sum ≥ s；
- 内层循环，
  - 记录 `len = std::min(len, j - i)`；
  - 右移 i，`sum -= nums[i++];`，直到 sum < s。

&emsp;&emsp;数组中每个元素最多被 i 和 j 访问一次，复杂度为 O(n)。