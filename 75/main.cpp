/*************************************************************************
    > File Name: main.cpp
    > Author: Stewie
    > E-mail: 793377164@qq.com
    > Created Time: 2018-07-14
*************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums);

int main()
{
    vector<int> vec{};
    sortColors(vec);
    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << endl;
    return 0;
}

void sortColors(vector<int>& nums)
{
}
