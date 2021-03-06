#include <cassert>

#include <string>
#include <unordered_map>
#include <vector>

#include <utils.h>

using namespace std;

vector<vector<string>> Union(const vector<vector<string>>& sets);

int main() {
  vector<vector<string>> sets{{"a", "b", "c"}, {"b", "d"}, {"e", "f"}, {"g"}, {"d", "h"}};
  cout << Union(sets) <<endl;
}

vector<vector<string>> Union(const vector<vector<string>>& sets) {
  unordered_map<string, int> str_to_id{};
  int count = 0;
  for (const auto& set : sets) {
    int min_id = INT_MAX;
    for (const auto& s : set) {
      if (str_to_id.find(s) == str_to_id.end()) {
        str_to_id[s] = count++;
      }
      min_id = std::min(min_id, str_to_id[s]);
    }
    for (const auto& s : set) {
      str_to_id[s] = min_id;
    }
  }
  unordered_map<int, vector<string>> id_to_set{};
  for (const auto& p : str_to_id) {
    if (id_to_set.find(p.second) == id_to_set.end()) {
      id_to_set[p.second] = {p.first};
    } else {
      id_to_set[p.second].emplace_back(p.first);
    }
  }
  vector<vector<string>> res;
  res.reserve(id_to_set.size());
  for (const auto& p : id_to_set) {
    res.emplace_back(p.second);
  }
  return res;
}
