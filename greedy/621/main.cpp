#include <cassert>

#include <algorithm>
#include <list>
#include <queue>
#include <vector>

#include "utils.h"

using namespace std;

int leastInterval(vector<char>& tasks, int n);

int main() {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  assert(leastInterval(tasks, 2) == 8);
  assert(leastInterval(tasks, 0) == 6);
  assert(leastInterval(tasks, 50) == 104);
  tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  assert(leastInterval(tasks, 2) == 16);
}
/* 正解一
int leastInterval(vector<char>& tasks, int n) {
  vector<int> counts(26, 0);
  for (char task : tasks) {
    counts[task - 'A'] += 1;
  }
  sort(counts.begin(), counts.end(), [](int a, int b){ return a > b; });
  int res = 0;
  while (counts[0] > 0) {
    for (int i = 0; i <= n; i++) {
      if (counts[0] == 0) {
        break;
      }
      if (i <= 25 && counts[i] > 0) {
        counts[i]--;
      }
      res++;
    }
    sort(counts.begin(), counts.end(), [](int a, int b){ return a > b; });
  }
  return res;
}
*/

int leastInterval(vector<char>& tasks, int n) {
  vector<int> counts(26, 0);
  for (char task : tasks) {
    counts[task - 'A'] += 1;
  }
  priority_queue<int> queue;
  for (int count : counts) {
    if (count > 0) {
      queue.push(count);
    }
  }
  int res = 0;
  while (!queue.empty()) {
    list<int> l;
    for (int i = 0; i <= n; i++) {
      if (!queue.empty()) {
        if (queue.top() > 1) {
          l.push_back(queue.top() - 1);
        }
        queue.pop();
      }
      res++;
      if (queue.empty() && l.empty()) {
        break;
      }
    }
    for (int e : l) {
      queue.push(e);
    }
  }
  return res;
}
