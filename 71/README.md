### 71. Simplify Path

-----

&emsp;&emsp;简化给出的 Unix 风格的绝对路径。

**Example**

    "/home/" => "/home"
    "/a/./b/../../c/" => "/c"
    "/../" => "/"
    "/home//foo/" => "/home/foo"


-----

#### 正解一

&emsp;&emsp;比较简单。

```cpp
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
```

#### 正解二

&emsp;&emsp;用`getline()`划分字符串需要掌握。并且`if...else`条件需要写的精简，这里`".."`只检查1次。

```cpp
string simplifyPath(string path)
{
    string res, tmp;
    vector<string> vec;
    stringstream ss(path);
    while (getline(ss, tmp, '/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp != "..") vec.push_back(tmp);
        else if (!vec.empty()) vec.pop_back();
    }
    for (string str : vec) res += '/' + str;
    return res.empty() ? "/" : res;
}
```
