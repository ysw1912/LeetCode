/*************************************************************************
    > File Name: main.cpp
    > Author: Stewie
    > E-mail: 793377164@qq.com
    > Created Time: 2018-07-13
*************************************************************************/

#include <iostream>
#include <cstdarg>

using namespace std;

bool find(int** matrix, int row, int col, int target);

int** CreateMatrix(int row, int col, ...)
{
    int** matrix = new int*[row];
    va_list arg_ptr;
    va_start(arg_ptr, col);
    for (int i = 0; i < row; ++i) {
        int* arr = new int[col];
        for (int j = 0; j < col; ++j) {
            int num = va_arg(arg_ptr, int);
            arr[j] = num;
        }
        matrix[i] = arr;
    }
    va_end(arg_ptr);
    return matrix;
}

void PrintMatrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d ", matrix[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    int row = 3, col = 4;
    int** matrix = CreateMatrix(row, col,  1,  3,  5,  7,
                                          10, 11, 16, 20,
                                          23, 30, 34, 50);
    PrintMatrix(matrix, row, col);
    cout << find(matrix, row, col, 17) << endl;
    return 0;
}

bool find(int** matrix, int row, int col, int target)
{
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


