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
/*
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
*/
int mySqrt(int x)
{
    float xfloat = float(x);
    float xhalf = 0.5f * xfloat;
    int i = *(int*)&xfloat;     // get bits for floating VALUE 
    i = 0x5f375a86 - (i >> 1);  // gives initial guess y0
    xfloat = *(float*)&i;            // convert bits BACK to float
    // Newton step, repeating increases accuracy
    xfloat = xfloat * (1.5f - xhalf * xfloat * xfloat);
    xfloat = xfloat * (1.5f - xhalf * xfloat * xfloat);
    //xfloat = xfloat * (1.5f - xhalf * xfloat * xfloat);
    int ret = 1 / xfloat;
    return ret * ret > x ? ret - 1 : ret;
}
