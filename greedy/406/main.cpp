#include <cassert>

#include <algorithm>
#include <list>
#include <vector>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people);

int main() {
  vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  vector<vector<int>> ans = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
  assert(reconstructQueue(people) == ans);
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
  list<vector<int>> ans;
  sort(people.begin(),
       people.end(),
       [](const vector<int>& a, const vector<int>& b){
         return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
       });
  for (const vector<int>& person : people) {
    auto it = ans.begin();
    advance(it, person[1]);
    ans.insert(it, person);
  }
  return vector<vector<int>>(ans.begin(), ans.end());
}
