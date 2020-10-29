#include <vector>

#include <cassert>

#include "utils.h"

using namespace std;

vector<int> countBits(int num);

int main() {
  vector<int> bits = {0, 1, 1};
  assert(countBits(2) == bits);
  bits = {0, 1, 1, 2, 1, 2};
  assert(countBits(5) == bits);
}
/* 正解一
vector<int> countBits(int num) {
  vector<int> bits(num + 1);
  for (int i = 1; i <= num; i++) {
    bits[i] = bits[i & (i - 1)] + 1;
  }
  return bits;
}
 */

 vector<int> countBits(int num) {
  vector<int> bits(num + 1);
  for (int i = 1; i <= num; i++) {
    bits[i] = bits[i >> 1] + (i & 1);
  }
  return bits;
}
