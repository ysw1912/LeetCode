#include <cassert>

#include <algorithm>
#include <vector>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points);

int main() {
  vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  assert(findMinArrowShots(points) == 2);
}

int findMinArrowShots(vector<vector<int>>& points) {
  if (points.empty()) {
    return 0;
  }
  sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){ 
    return a[1] < b[1]; 
  });
  int prev = 0, res = 1;
  for (int i = 1; i < (int)points.size(); i++) {
    if (points[i][0] > points[prev][1]) {
      res += 1;
      prev = i;
    }
  }
  return res;
}
