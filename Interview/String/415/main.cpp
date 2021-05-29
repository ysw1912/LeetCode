#include <algorithm>
#include <string>

#include <cassert>

using namespace std;

string addStrings(string num1, string num2);

int main() {
  assert(addStrings("11", "123") == "134");
  assert(addStrings("456", "77") == "533");
  assert(addStrings("9", "1") == "10");
  assert(addStrings("0", "0") == "0");
}

string addStrings(string num1, string num2) {
  string ans;
  int i = num1.size() - 1, j = num2.size() - 1;
  int c = 0;
  while (i >= 0 || j >= 0 || c) {
    int a = i >= 0 ? num1[i--] - '0' : 0;
    int b = j >= 0 ? num2[j--] - '0' : 0;
    int s = a + b + c;
    ans.push_back((s % 10) + '0');
    c = s / 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
