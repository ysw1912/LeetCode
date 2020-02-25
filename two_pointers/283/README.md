### 283. Move Zeroes

-----

&emsp;&emsp;给定一个数组，in-place 地将所有 0 移至末尾并保持其他非 0 元素相对位置不变。

-----

#### 正解一 O(n)

&emsp;&emsp;双指针 first_zero 与 i，first_zero 指向第一个 0。遍历 i，若 nums[i] 非 0，则 nums[i] 与 nums[first_zero] 交换，first_zero++。

-----

#### 正解二

&emsp;&emsp;利用 STL。

- std::remove + std::fill
- std::stable_partition
