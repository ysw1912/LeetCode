#include <string>
#include <unordered_map>

#include <cassert>

using namespace std;

string longestDupSubstring(string s);

int main() {
  assert(longestDupSubstring("abcd").empty());
  assert(longestDupSubstring("banana") == "ana");
  assert(longestDupSubstring("abczzacbca") == "bc");
  assert(longestDupSubstring("canffcancd") == "can");
  string very_long = "nyvzwttxsshphczjjklqniaztccdrawueylaelkqtjtxdvutsewhghcmoxlvqjktgawwgpytuvoepnyfbdywpmmfukoslqvdrkuokxcexwugogcwvsuhcziwuwzfktjlhbiuhkxcreqrdbj";
  assert(longestDupSubstring(very_long) == "hcz");
}

string longestDupSubstring(const string& s, int len) {
  static int R = 26;  // 如果是所有字符，则是 256 进制（1 << CHAR_BIT）;
  static int M = 10000019;
  string longest;
  std::unordered_map<int, int> hash_to_idx{};
  long long hash = 0;
  long long pow = 1;
  for (int i = 0; i < len; i++) {
    if (i > 0) {
      pow = (pow * R) % M;
    }
    hash = (hash * R + s[i]) % M;
  }
  for (int i = 0; i <= static_cast<int>(s.size()) - len; i++) {
    if (hash_to_idx.find(hash) == hash_to_idx.end()) {
      hash_to_idx.emplace(hash, i);
    } else {
      int k = 0;
      for (; k < len && s[i + k] == s[hash_to_idx[hash] + k]; k++);
      if (k == len) {
        longest = s.substr(i, len);
        break;
      }
    }
    hash = (((hash - s[i] * pow) % M * R) + s[i + len]) % M;
    hash += hash < 0 ? M : 0;
  }
  return longest;
}

string longestDupSubstring(string s) {
  string longest{};
  int left = 1, right = static_cast<int>(s.size()) - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    string sub_str = longestDupSubstring(s, mid);
    if (sub_str.empty()) {
      right = mid - 1;
    } else {
      longest = std::move(sub_str);
      left = mid + 1;
    }
    if (mid == right) break;
  }
  return longest;
}
