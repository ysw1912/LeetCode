### 402. Remove K Digits

-----

&emsp;&emsp;给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使剩下的数字最小。

&emsp;&emsp;num 的长度 ≥ k，且 num 不会包含任何前导零。

-----

#### 正解一 O(n) 栈

```cpp

string removeKdigits(string num, int k) {
  string res;
  int keep = num.size() - k;
  for (int i = 0; i < num.size(); i++) {
    while (res.size() > 0 && res.back() > num[i] && k > 0) {
      res.pop_back();
      k--;
    }
    res.push_back(num[i]);
  }
  res.erase(keep, string::npos);

  // trim leading zeros
  int s = 0;
  while (s < (int)res.size() - 1 && res[s] == '0')  s++;
  res.erase(0, s);

  return res == "" ? "0" : res;
}
```
