/*************************************************************************
    > File Name: main.cpp
    > Author: Stewie
    > E-mail: 793377164@qq.com
    > Created Time: 2018-07-14
*************************************************************************/

#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

void sortColors(vector<int>& nums);

int main()
{
    vector<int> vec{2, 0, 2, 1, 1, 0};
    sortColors(vec);
    PrintVector(vec, vec.size());
    return 0;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

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
