#include <cassert>
#include <string>

using namespace std;

bool isPalindrome(string s);

int main() {
  assert(isPalindrome("A man, a plan, a canal: Panama"));
  assert(!isPalindrome("race a car"));
  return 0;
}

inline bool isSameChar(char p, char q) {
  if (p == q) return true;
  if (isalpha(p) && isalpha(q)) return abs(p - q) == 32;
  return false;
}

bool isPalindrome(string s) {
  const char* p = s.data();
  const char* q = p + s.size() - 1;
  while (p < q) {
    while (!isalnum(*p) && p < q) ++p;
    while (!isalnum(*q) && p < q) --q;
    // if (p < q && !isSameChar(*p++, *q--)) return false;
    if (p < q && tolower(*p++) != tolower(*q--)) return false;
  }
  return true;
}
