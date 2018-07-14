### 73. Set Matrix Zeroes

-----

&emsp;&emsp;给定 m x n 矩阵，如果一个元素是 0，则将其所在行、列都设为0。

&emsp;&emsp;尽量避免使用 O(mn) 或 O(m + n) 空间，只用 O(1) 空间。

**Example 1**

    Input: 
    [
      [1,1,1],
      [1,0,1],
      [1,1,1]
    ]
    Output: 
    [
      [1,0,1],
      [0,0,0],
      [1,0,1]
    ]

**Example 2**

    Input: 
    [
      [0,1,2,0],
      [3,4,5,2],
      [1,3,1,5]
    ]
    Output: 
    [
      [0,0,0,0],
      [0,4,5,0],
      [0,3,1,0]
    ]

-----

#### 错解一

&emsp;&emsp;使用 2 个数组 O(m + n) 空间，表示每行和每列的状态，如果该行或该列含 0，则相应的 flag 位置 1。

```cpp
void setZeroes(int** matrix, int row, int col)
{
    int* rowFlag = (int*)malloc(row * sizeof(int));
    int* colFlag = (int*)malloc(col * sizeof(int));
    memset(rowFlag, 0, row * sizeof(int));
    memset(colFlag, 0, col * sizeof(int));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == 0) {
                rowFlag[i] = 1;
                colFlag[j] = 1;
            }
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (rowFlag[i] == 1 || colFlag[j] == 1)
                matrix[i][j] = 0;
        }
    }
}
```

-----

#### 正解一

&emsp;&emsp;分两个阶段：

&emsp;&emsp;第一阶段：用每行第一个元素 matrix[i][0] 表示该行的状态，如果该行需要为 0，则 matrix[i][0] = 0；用每列第一个元素 matrix[0][j] 表示该列的状态，如果该列需要为 0，则 matrix[0][j] = 0。而 matrix[0][0] 用于表示第 0 行的状态，因此额外使用一个自动变量 col0 表示第 0 列的状态，空间 O(1)。

&emsp;&emsp;第二阶段：根据 matrix[i][0] 和 matrix[0][j] 和 col0 的值，将矩阵元素相应地置 0。注意，此时遍历行要从第 row - 1 行遍历到第 0 行，因为第 0 行保存着状态，不能首先改变第 0 行；而遍历列则无所谓，因为第 0 列的状态保存在 col0 变量中，但第 0 列 matrix[i][0] 也要在修改完第 i 行之后更新。

```cpp
void setZeroes(int** matrix, int row, int col)
{
    int col0 = 1;
    for (int i = 0; i < row; ++i) {
        if (matrix[i][0] == 0)
            col0 = 0;
        for (int j = 1; j < col; ++j) {
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
        }
    }
    for (int i = row - 1; i >= 0; --i) {
        for (int j = 1; j < col; ++j)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0)
            matrix[i][0] = 0;
    }
}
```
