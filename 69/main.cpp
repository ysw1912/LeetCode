/*************************************************************************
    > File Name: main.cpp
    > Author: Stewie
    > E-mail: 793377164@qq.com
    > Created Time: 2018-07-02
*************************************************************************/

#include <iostream>

using namespace std;

int mySqrt(int x);

int main()
{
    int x;
    cin >> x;
    cout << mySqrt(x) << endl;
    return 0;
}

int mySqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int left = 1, right = x / 2, res = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;     
        if (mid <= x / mid) {
            res = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return res;
}
