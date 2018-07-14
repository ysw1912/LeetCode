### 74. Search a 2D Matrix

-----

&emsp;&emsp;编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

- 每行中的整数从左到右按升序排列。
- 每行的第一个整数大于前一行的最后一个整数。

&emsp;&emsp;

**Example 1**

    Input: 
    matrix = [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    target = 3
    Output: true

**Example 2**

    Input: 
    matrix = [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    target = 13
    Output: false

-----

#### 正解一

&emsp;&emsp;其实相当于一个有序数组，首先对行使用二分，确定只可能位于哪一行；再在行中使用二分，确定该行中是否存在该元素。

&emsp;&emsp;注意，对行二分和对列二分稍有不同。因此该解法比起解法二，虽然时间都是 O(log(mn))，但更加易错。

```cpp
bool searchMatrix(int** matrix, int row, int col, int target)
{
    if (row == 0 && col == 0)
        return false;
    if (target < matrix[0][0] || target > matrix[row - 1][col - 1])
        return false;
    int left = 0, right = row, mid = left + (right - left) / 2;
    while (left < right - 1) {
        if (target == matrix[mid][0])
            return true;
        else if (target < matrix[mid][0])
            right = mid;
        else 
            left = mid;
        mid = left + (right - left) / 2;
    }
    int i = mid;
    left = 0, right = col - 1, mid = left + (right - left) / 2;
    while (left <= right) {
        if (target == matrix[i][mid])
            return true;
        else if (target < matrix[i][mid])
            right = mid - 1;
        else 
            left = mid + 1;
        mid = left + (right - left) / 2;
    }
    return false;
}
```

#### 正解二

&emsp;&emsp;直接将矩阵看做一个数组，直接对数组进行二分！！！

- 矩阵 → 数组：matrix[i][j] → arr[i * col + j]
- 数组 → 矩阵：arr[k] → matrix[k / col][k % col]

```cpp
bool searchMatrix(int** matrix, int row, int col, int target)
{
    if (row == 0 && col == 0)
        return false;
    if (target < matrix[0][0] || target > matrix[row - 1][col - 1])
        return false;
    int left = 0, right = row * col - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target == matrix[mid / col][mid % col])
            return true;
        else if (target < matrix[mid / col][mid % col])
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return matrix[left / col][left % col] == target;
}
```
