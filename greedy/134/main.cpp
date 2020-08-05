#include <cassert>

#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost);

int main() {
  vector<int> gas{1, 2, 3, 4, 5};
  vector<int> cost{3, 4, 5, 1, 2};
  assert(canCompleteCircuit(gas, cost) == 3);
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  // 确定是否有解。
  int size = gas.size();
  int total = 0;
  for (int i = 0; i < size; i++) {
    total += gas[i] - cost[i];
  }
  if (total < 0) {
    return -1;
  }
  // 如果有解，确定起始点 start。
  // 如果从 A 不能到达 B，且 B 是第一个 A 不能达到的位置，则 A 与 B 之间的任何位
  // 置都不能到达 B，则起始点只可能从 B 开始。
  int tank = 0, start = 0;
  for (int i = 0; i < size; i++) {
    tank += gas[i] - cost[i];
    if (tank < 0) {
      start = i + 1;
      tank = 0;
    }
  }
  return start;
}
