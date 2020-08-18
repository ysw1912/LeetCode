#include <cassert>

#include <algorithm>
#include <vector>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals);

int main() {
  vector<vector<int>> intervals;
  assert(eraseOverlapIntervals(intervals) == 0);
  intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  assert(eraseOverlapIntervals(intervals) == 1);
  intervals = {{1, 2}, {1, 2}, {1, 2}};
  assert(eraseOverlapIntervals(intervals) == 2);
  intervals = {{1, 2}, {2, 3}};
  assert(eraseOverlapIntervals(intervals) == 0);
}

bool isOverlapping(const vector<int>& a, const vector<int>& b) {
  return a[0] < b[1] && b[0] < a[1];
}

/* 解法一
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  if (intervals.empty()) {
    return 0;
  }
  sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
  });
  int size = intervals.size();
  vector<int> dp(size, 1);
  for (int i = 1; i < size; i++) {
    int max = 0;
    for (int j = 0; j < i; j++) {
      if (!isOverlapping(intervals[i], intervals[j]) && dp[j] > max) {
        max = dp[j];
      }
    }
    dp[i] = max + 1;
  }
  return size - *max_element(dp.begin(), dp.end());
}
*/
/* 解法二
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  if (intervals.empty()) {
    return 0;
  }
  sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1];
  });
  int size = intervals.size();
  vector<int> dp(size, 1);
  for (int i = 1; i < size; i++) {
    int max = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (!isOverlapping(intervals[i], intervals[j])) {
        max = dp[j];
        break;
      }
    }
    dp[i] = std::max(max + 1, dp[i - 1]);
  }
  return size - *max_element(dp.begin(), dp.end());
}
*/
/* 解法三
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  if (intervals.empty()) {
    return 0;
  }
  sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
  });
  int ans = 0;
  vector<int>* prev = &intervals[0];
  for (size_t i = 1; i < intervals.size(); i++) {
    if (isOverlapping(*prev, intervals[i])) {
      if (intervals[i][1] <= (*prev)[1]) {
        prev = &intervals[i];
      }
      ++ans;
    } else {
      prev = &intervals[i];
    }
  }
  return ans;
}
*/
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  if (intervals.empty()) {
    return 0;
  }
  sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1];
  });
  int ans = 0;
  vector<int>* prev = &intervals[0];
  for (size_t i = 1; i < intervals.size(); i++) {
    if (isOverlapping(*prev, intervals[i])) {
      ++ans;
    } else {
      prev = &intervals[i];
    }
  }
  return ans;
}
