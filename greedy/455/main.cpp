#include <cassert>

#include <algorithm>
#include <vector>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s);

int main() {
  vector<int> g = {1, 2, 3}, s = {1, 1};
  assert(findContentChildren(g, s) == 1);
  g = {1, 2}, s = {1, 2, 3};
  assert(findContentChildren(g, s) == 2);
}

/*
int findContentChildren(vector<int>& g, vector<int>& s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  int res = 0;
  for (int child : g) {
    auto it = lower_bound(s.begin(), s.end(), child);
    if (it == s.end()) {
      break;
    }
    res++;
    s.erase(it);
  }
  return res;
}
*/
int findContentChildren(vector<int>& g, vector<int>& s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  int i = 0, j = 0;
  while (i < g.size() && j < s.size()) {
    if (g[i] <= s[j]) {
      i++;
    }
    j++;
  }
  return i;
}
