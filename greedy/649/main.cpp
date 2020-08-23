#include <cassert>

#include <queue>
#include <string>
#include <vector>

using namespace std;

string predictPartyVictory(string senate);

int main() {
  assert(predictPartyVictory("RD") == "Radiant");
  assert(predictPartyVictory("RDD") == "Dire");
}
/* 暴力
string predictPartyVictory(string senate) {
  int size = senate.size();
  vector<bool> valid(size, true);
  int num_radiant = 0, num_dire = 0;
  for (int i = 0; i < size; i++) {
    if (senate[i] == 'R') {
      num_radiant++;
    } else {
      num_dire++;
    }
  }
  while (num_radiant > 0 && num_dire > 0) {
    for (int i = 0; i < size; i++) {
      if (!valid[i]) continue;
      if (senate[i] == 'R') {
        if (num_dire == 0) break;
        for (int j = i + 1; j < i + 1 + size; j++) {
          int idx = j % size;
          if (senate[idx] == 'D' && valid[idx]) {
            valid[idx] = false;
            --num_dire;
            break;
          }
        }
      } else {
        if (num_radiant == 0) break;
        for (int j = i + 1; j < i + 1 + size; j++) {
          int idx = j % size;
          if (senate[idx] == 'R' && valid[idx]) {
            valid[idx] = false;
            --num_radiant;
            break;
          }
        }
      }
    }
  }
  return num_radiant > 0 ? "Radiant" : "Dire";
}
*/
string predictPartyVictory(string senate) {
  queue<int> q;
  // 0 - Radiant, 1 - Dire
  vector<int> people = {0, 0};
  vector<int> bans = {0, 0};
  for (char c : senate) {
    int idx = c == 'D';
    ++people[idx];
    q.push(idx);
  }
  while (people[0] && people[1]) {
    int idx = q.front();
    q.pop();
    if (bans[idx ^ 1] > 0) {
      --people[idx];
      --bans[idx ^ 1];
    } else {
      ++bans[idx];
      q.push(idx);
    }
  }
  return people[0] > 0 ? "Radiant" : "Dire";
}