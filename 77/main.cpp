#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k);

int main()
{
    int n = 4, k = 2;
    vector<vector<int>> vec = combine(n, k);
    for (auto & i : vec) {
        for (int j = 0; j < k; ++j)
            cout << i[j] << ' ';
        cout << endl;
    }
    return 0;
}
/*
void fill_vector(int n, int k, vector<vector<int>>& res, vector<int>& vec, int last)
{
    vec.push_back(last);
    int len = vec.size();
    if (len == k) {
        res.push_back(vec);
        return;
    }
    for (int num = last + 1; num <= n - k + len + 1; ++num) {
        fill_vector(n, k, res, vec, num);
        vec.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    if (k == 0)
        return {};
    vector<vector<int>> res;
    vector<int> vec;
    for (int num = 1; num <= n - k + 1; ++num) {
        fill_vector(n, k, res, vec, num);
        vec.pop_back();
    }
    return res;
}
*/
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    int i = 0;
    vector<int> vec(k, 0);
    while (i >= 0) {
        vec[i]++;
        if (vec[i] > n) 
            --i;
        else if (i == k - 1)
            res.push_back(vec);
        else {
            ++i;
            vec[i] = vec[i - 1];
        }
    }
    return res;
}
