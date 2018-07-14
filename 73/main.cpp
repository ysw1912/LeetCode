/*************************************************************************
    > File Name: main.cpp
    > Author: Stewie
    > E-mail: 793377164@qq.com
    > Created Time: 2018-07-05
*************************************************************************/

#include <iostream>
#include <cstdarg>
#include <cstring>

using namespace std;

void setZeroes(int** matrix, int row, int col);

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
    int row = 2, col = 3;
    int** matrix = CreateMatrix(row, col, 1, 1, 1,
                                          0, 1, 2);
    PrintMatrix(matrix, row, col);
    setZeroes(matrix, row, col); 
    printf("----------\n");
    PrintMatrix(matrix, row, col);
    return 0;
}
/*
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
*/ 
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
