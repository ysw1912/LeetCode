/*************************************************************************
    > File Name: main.cpp
    > Author: Stewie
    > E-mail: 793377164@qq.com
    > Created Time: 2018-07-03
*************************************************************************/

#include <iostream>

using namespace std;

int climbStairs(int n);

int main()
{
    int x;
    cin >> x;
    cout << climbStairs(x) << endl;
    return 0;
}
/*
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else 
        return climbStairs(n - 1) + climbStairs(n - 2);
}
*/
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    int res = 0;
    int n1 = 1, n2 = 2;
    for (int i = 3; i <= n; ++i) {
        res = n1 + n2;
        n1 = n2;
        n2 = res;
    }
    return res;   
}
