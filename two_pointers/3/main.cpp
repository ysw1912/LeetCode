#include "utils.h"

#include <unordered_set>
#include <vector>

#include <cassert>

using namespace std;

int lengthOfLongestSubstring(string s);

int main()
{
  assert(lengthOfLongestSubstring("abcabcbb") == 3);
  assert(lengthOfLongestSubstring("bbbbb") == 1);
  assert(lengthOfLongestSubstring("pwwkew") == 3);
  assert(lengthOfLongestSubstring("") == 0);
}
/*
int lengthOfLongestSubstring(string s) {
  if (s.empty()) {
    return 0;
  }
  int len = 0;
  unordered_set<char> set;
  int r = -1;
  for (int i = 0; i < s.size() && r != s.size() - 1; i++) {
    if (i > 0) {
      set.erase(s[i - 1]);
    }
    while (r + 1 < s.size() && !set.count(s[r + 1])) {
      set.emplace(s[++r]);
    }
    len = max(len, r - i + 1);
  }
  return len;
}
*/
int lengthOfLongestSubstring(string s) {
  array<int, 256> map{};
  map.fill(-1);
  int len = 0, start = -1;
  for (int i = 0; i != s.length(); i++) {
    if (map[s[i]] > start)
      start = map[s[i]];
    map[s[i]] = i;
    len = max(len, i - start);
  }
  return len;
}
