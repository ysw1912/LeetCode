#include <vector>

#include <cassert>

using namespace std;

int numSquares(int n);

int main() {
  assert(numSquares(12) == 3);
  assert(numSquares(13) == 2);
}

int numSquares(int n, vector<int>& cache) {
  if (cache[n] != -1) {
    return cache[n];
  }
  int min_num = INT_MAX;
  for (int i = 1; i * i <= n; i++) {
    min_num = min(numSquares(n - i * i, cache), min_num);
  }
  cache[n] = min_num + 1;
  return cache[n];
}

int numSquares(int n) {
  vector<int> cache(n + 1, -1);
  cache[0] = 0;
  return numSquares(n, cache);
}
