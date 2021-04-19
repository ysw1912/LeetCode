#include <string>

#include <cassert>
#include <cmath>

int strStr(const std::string& s, const std::string& p) {
  if (p.empty()) {
    return 0;
  }
  if (p.size() > s.size()) {
    return -1;
  }
  int r = 1 << sizeof(char);
  int f = pow(r, p.size() - 1);
  int hash_p = 0, hash_s = 0;
  for (int i = 0; i < p.size(); i++) {
    hash_p = hash_p * r + p[i];
    hash_s = hash_s * r + s[i];
  }
  for (int i = 0; i <= s.size() - p.size(); i++) {
    if (hash_p == hash_s) {
      return i;
    }
    if (i < s.size() - p.size()) {
      hash_s = (hash_s - s[i] * f) * r + s[i + p.size()];
    }
  }
  return -1;
}

int main() {
  assert(strStr("hello", "ll") == 2);
  assert(strStr("aaaaa", "bba") == -1);
  assert(strStr("", "") == 0);
}
