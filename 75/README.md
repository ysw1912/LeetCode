### 75. Sort Colors

-----

&emsp;&emsp;给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。（使用整数 0、 1 和 2 分别表示红色、白色和蓝色）

&emsp;&emsp;直观的解决方案是使用计数排序的两趟扫描算法。建议使用 O(1) 空间的一趟扫描算法。

**Example**

    Input: [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

-----

#### 正解一

&emsp;&emsp;由于只有 3 个数，只要把最小的数 0 一直放到数组前端，最大的 2 一直放在数组尾端，即可完成排序。用 left 指向数组头，right 指向数组尾，p 从头开始遍历到 right。如果 p 所指是 0，则与 left 交换，left 右移一位；如果 p 所指是 2，则与 right 交换，right 左移一位；如果该轮无需交换，则 p 前进一位。

```cpp
void sortColors(vector<int>& nums)
{
    int left = 0, right = nums.size() - 1;
    int p = left;
    while (p <= right) {
        if (nums[p] == 0 && p != left) {
            swap(nums[left], nums[p]);
            ++left;
        }
        else if (nums[p] == 2 && p != right) {
            swap(nums[right], nums[p]);
            --right;
        }
        else 
            ++p;
    }
}
```
