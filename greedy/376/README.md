### 376. Wiggle Subsequence

-----

&emsp;&emsp;摆动序列：序列中连续数字之间的差严格地在正数和负数之间交替。
            
&emsp;&emsp;第一个差可能是正数或负数。少于两个元素的序列也是摆动序列。
            
&emsp;&emsp;给定一个整数序列，返回作为摆动序列的最长子序列的长度。

-----

#### 正解一 O(n) DP

&emsp;&emsp;数组中每个位置只有 3 种状态：

- nums[i] > nums[i-1]
- nums[i] < nums[i-1]
- nums[i] = nums[i-1]

&emsp;&emsp;两个 DP 数组 up[] 和 down[]

- up[i] 表示到 i 为止，且 nums[i] > nums[i-1]，最大的摆动子序列的长度。
- down[i] 表示到 i 为止，且 nums[i] < nums[i-1]，最大的摆动子序列的长度。

显然，如果

- nums[i] > nums[i-1]，则 up[i] = down[i - 1] + 1，down[i] 保持不变。
- nums[i] < nums[i-1]，则 down[i] = up[i - 1] + 1，up[i] 保持不变。
- nums[i] = nums[i-1]，则 up[i]、down[i] 均保持不变。

时间复杂度为 O(n)，空间复杂度为 O(n)。

-----

#### 正解二 O(n) 贪心

&emsp;&emsp;上述 dp 过程中 i 只与 i - 1 有关，因此可以降维，空间复杂度可为 O(1)。

```cpp
int wiggleMaxLength(vector<int>& nums) {
  int size = nums.size();
  if (size < 2) {
    return size;
  }
  int up = 1, down = 1;
  for (int i = 1; i < size; i++) {
    if (nums[i] > nums[i - 1]) {
      up = down + 1;
    } else if (nums[i] < nums[i - 1]) {
      down = up + 1;
    }
  }
  return max(up, down);
}
```
