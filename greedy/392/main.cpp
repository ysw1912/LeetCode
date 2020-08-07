#include <cassert>

#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool isSubsequence(string s, string t);

int main() {
  assert(isSubsequence("", "ahbgdc"));
  assert(isSubsequence("abc", "ahbgdc"));
  assert(!isSubsequence("axc", "ahbgdc"));
}

/*
bool isSubsequence(string s, string t) {
  int j = 0;
  for (int i = 0; i < t.size() && j < s.size(); i++) {
    if (t[i] == s[j]) {
      j++;
    }
  }
  return j == s.size();
}
*/

// 如果有多个 s 要判断是否为 t 的子序列
bool isSubsequence(string s, string t) {
  // 建立 t 中每个字符的索引
  vector<vector<int>> record(26);
  for (int i = 0; i < t.size(); i++) {
    record[t[i] - 'a'].push_back(i);
  }
  // 检测 s 中每个元素是否在正确的位置，index 必须递增
  int index = -1;
  for (int i = 0; i < s.size(); i++) {
    auto iter = upper_bound(
        record[s[i] - 'a'].begin(), record[s[i] - 'a'].end(), index);
    if (iter == record[s[i] - 'a'].end()) {
      return false;
    }
    index = *iter;
  }
  return true;
}
