#include <algorithm>
#include <unordered_set>
#include <string>
#include <vector>

#include <cassert>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict);

int main() {
  vector<string> wordDict = {"leet", "code"};
  assert(wordBreak("leetcode", wordDict));
  wordDict = {"apple", "pen"};
  assert(wordBreak("applepenapple", wordDict));
  wordDict = {"cats", "dog", "sand", "and", "cat"};
  assert(!wordBreak("catsandog", wordDict));
  wordDict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
  assert(!wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict));
}

/* 36 / 43 test cases passed.
bool wordBreak(string s, int start, vector<string>& wordDict) {
  int end = s.size();
  if (start >= end) {
    return true;
  }
  for (const string& word : wordDict) {
    int size = word.size();
    if (start + size > end) {
      continue;
    }
    if (s.substr(start, size) == word) {
      if (wordBreak(s, start + size, wordDict)) {
        return true;
      }
    }
  }
  return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
  sort(wordDict.begin(), wordDict.end(), [](const string& a, const string& b) {
      return a.size() > b.size();
  });
  return wordBreak(s, 0, wordDict);
}
*/
bool wordBreak(string s, vector<string>& wordDict) {
  unordered_set<string> words;
  int max_length = 0;
  for (const string& word : wordDict) {
    words.insert(word);
    max_length = max(max_length, static_cast<int>(word.size()));
  }
  int size = s.size();
  vector<bool> dp(size + 1, false);
  dp[0] = true;
  for (int i = 1; i <= size; i++) {
    for (int j = i - 1; j >= 0; j--) {
      int length = i - j;
      if (length > max_length) {
        break;
      }
      if (dp[j] && words.find(s.substr(j, length)) != words.end()) {
        dp[i] = true;
        break;
      }
    }
  }
  return dp[size];
}
