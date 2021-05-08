#include <cassert>

#include <queue>
#include <tuple>
#include <vector>

#include <cstdio>

using namespace std;

int longestIncreasingPath(vector<vector<int>>& matrix);

int main() {
  vector<vector<int>> matrix;
  matrix = {{9, 9, 4},
            {6, 6, 8},
            {2, 1, 1}};
  assert(longestIncreasingPath(matrix) == 4);
  matrix = {{3, 4, 5},
            {3, 2, 6},
            {2, 2, 1}};
  assert(longestIncreasingPath(matrix) == 4);
  matrix = {{1}};
  assert(longestIncreasingPath(matrix) == 1);
  matrix = {{1, 2, 3, 4, 5},
            {10, 9, 8, 7, 6},
            {11, 14, 15, 18, 19},
            {12, 13, 16, 17, 20}};
  assert(longestIncreasingPath(matrix) == 20);
}
/*
int dfs(const vector<vector<int>>& matrix, vector<vector<int>>& mem, int i, int j) {
  if (mem[i][j]) {
    return mem[i][j];
  }
  mem[i][j] = 1;
  if (i > 0 && matrix[i - 1][j] < matrix[i][j]) {
    mem[i][j] = max(mem[i][j], dfs(matrix, mem, i - 1, j) + 1);
  }
  if (j > 0 && matrix[i][j - 1] < matrix[i][j]) {
    mem[i][j] = max(mem[i][j], dfs(matrix, mem, i, j - 1) + 1);
  }
  if (i + 1 < matrix.size() && matrix[i + 1][j] < matrix[i][j]) {
    mem[i][j] = max(mem[i][j], dfs(matrix, mem, i + 1, j) + 1);
  }
  if (j + 1 < matrix[0].size() && matrix[i][j + 1] < matrix[i][j]) {
    mem[i][j] = max(mem[i][j], dfs(matrix, mem, i, j + 1) + 1);
  }
  return mem[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
  if (matrix.empty()) {
    return 0;
  }
  int row = matrix.size();
  int col = matrix[0].size();
  vector<vector<int>> mem(row, vector<int>(col, 0));
  int len = 1;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      len = max(len, dfs(matrix, mem, i, j));
    }
  }
  return len;
}
*/
int longestIncreasingPath(vector<vector<int>>& matrix) {
  if (matrix.empty()) {
    return 0;
  }
  vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  int row = matrix.size();
  int col = matrix[0].size();
  vector<vector<int>> out_degree(row, vector<int>(col, 0));
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      for (auto&& direction : directions) {
        int r = i + direction.first;
        int c = j + direction.second;
        if (r >= 0 && c >= 0 && r < matrix.size() && c < matrix[0].size() && matrix[r][c] < matrix[i][j]) {
          out_degree[r][c]++;
        }
      }
    }
  }

  queue<pair<int, int>> q;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (out_degree[i][j] == 0) {
        q.push({i, j});
      }
    }
  }
  int len = 0;
  while (!q.empty()) {
    ++len;
    int size = q.size();
    for (int k = 0; k < size; k++) {
      int i, j;
      tie(i, j) = q.front();
      q.pop();

      for (auto&& direction : directions) {
        int r = i + direction.first;
        int c = j + direction.second;
        if (r >= 0 && c >= 0 && r < matrix.size() && c < matrix[0].size() && matrix[r][c] < matrix[i][j]) {
          if (--out_degree[r][c] == 0) {
            q.push({r, c});
          }
        }
      }
    }
  }
  return len;
}
