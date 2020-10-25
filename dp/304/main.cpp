#include <algorithm>
#include <vector>

#include <cassert>

#include "utils.h"

using namespace std;

class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) : matrix_(matrix) {
    if (matrix_.empty()) {
      return;
    }
    int rows = matrix_.size();
    int cols = matrix_[0].size();
    for (int i = 0; i < rows; i++) {
      areas_.emplace_back(matrix_[i]);
      for (int j = 1; j < cols; j++) {
        areas_[i][j] += areas_[i][j - 1];
      }
    }
    for (int i = 1; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        areas_[i][j] += areas_[i - 1][j];
      }
    }
    cout << areas_ << endl;
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (row1 == 0 && col1 == 0) {
      return areas_[row2][col2];
    }
    if (row1 == 0) {
      return areas_[row2][col2] - areas_[row2][col1 - 1];
    }
    if (col1 == 0) {
      return areas_[row2][col2] - areas_[row1 - 1][col2];
    }
    return areas_[row2][col2] + areas_[row1 - 1][col1 - 1] - areas_[row1 - 1][col2] - areas_[row2][col1 - 1];
  }

 private:
  vector<vector<int>>& matrix_;
  vector<vector<int>> areas_;
};

int main() {
  vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                {5, 6, 3, 2, 1},
                                {1, 2, 0, 1, 5},
                                {4, 1, 0, 1, 7},
                                {1, 0, 3, 0, 5}};
  auto* obj = new NumMatrix(matrix);
  assert(obj->sumRegion(2, 1, 4, 3) == 8);
  assert(obj->sumRegion(1, 1, 2, 2) == 11);
  assert(obj->sumRegion(1, 2, 2, 4) == 12);
  delete obj;

  matrix = {{-4, -5}};
  obj = new NumMatrix(matrix);
  assert(obj->sumRegion(0, 0, 0, 0) == -4);
  assert(obj->sumRegion(0, 0, 0, 1) == -9);
  assert(obj->sumRegion(0, 1, 0, 1) == -5);
  delete obj;
}
