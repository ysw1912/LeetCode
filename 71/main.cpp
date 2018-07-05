/*************************************************************************
    > File Name: main.cpp
    > Author: Stewie
    > E-mail: 793377164@qq.com
    > Created Time: 2018-07-04
*************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string simplifyPath(string path);

int main()
{
    string str;
    cin >> str;
    cout << simplifyPath(str) << endl;
    return 0;
}
/*
string simplifyPath(string path)
{
    path.push_back('/');
    vector<string> vec;
    size_t i = 0;
    string tmp = "";
    while (i < path.size()) {
        if (path[i] == '/') {
            if (tmp != "" && tmp != ".") {
                if (tmp == "..") {
                    if (!vec.empty())
                        vec.pop_back();
                }
                else 
                    vec.push_back(tmp);
            }
            tmp = "";
            while (++i < path.size() && path[i] == '/');
        }
        else {
            tmp.push_back(path[i]);
            ++i;
        }
    }
    if (vec.empty())
        return "/";
    string res = "";
    for (string dir : vec) {
        res.push_back('/');
        res.append(dir);
    }
    return res;
}
*/ 
string simplifyPath(string path)
{
    string res, tmp;
    vector<string> vec;
    stringstream ss(path);
    while (getline(ss, tmp, '/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !vec.empty()) vec.pop_back();
        else if (tmp != "..") vec.push_back(tmp);
    }
    for (string str : vec) res += '/' + str;
    return res.empty() ? "/" : res;
}
