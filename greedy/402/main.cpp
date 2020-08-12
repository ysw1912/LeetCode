#include <cassert>

#include <deque>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string removeKdigits(string num, int k);

int main() {
  assert(removeKdigits("1432219", 3) == "1219");
  assert(removeKdigits("10200", 1) == "200");
  assert(removeKdigits("10", 2) == "0");
  assert(removeKdigits("10", 1) == "0");
  assert(removeKdigits("112", 1) == "11");
  assert(removeKdigits("999991", 2) == "9991");
}

string removeKdigits(string num, int k) {
  if (num.size() == k) {
    return "0";
  }
  deque<char> d;
  int i = 0;
  for (; i < num.size(); i++) {
    while (!d.empty() && d.back() > num[i] && k > 0) {
      d.pop_back();
      k--;
    }
    if (k == 0) {
      break;
    }
    d.push_back(num[i]);
  }
  string ans;
  for (char& c : d) {
    ans += c;
  }
  ans += num.substr(i);
  i = 0;
  cout << ans << endl;
  while (ans[i] == '0') i++;
  ans = ans.substr(i, ans.size() - k);
  if (ans.empty()) {
    return "0";
  }
  cout << ans << endl;
  return ans;
}
