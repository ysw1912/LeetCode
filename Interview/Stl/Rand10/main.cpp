#include <cassert>
#include <cstdlib>
#include <ctime>

int Rand7() {
  srand((unsigned)time(nullptr));
  return rand() % 7 + 1;
}

/*
 * 已知 Rand_N() 可以等概率的生成 [1, N] 范围的随机数，则
 * (Rand_X() - 1) * Y + Rand_Y() 可以等概率的生成 [1, X * Y] 范围的随机数，
 * 即实现了 Rand_XY().
 */
int Rand10() {
  while (true) {
    // [1, 49]
    int n = (Rand7() - 1) * 7 + Rand7();
    if (n <= 40) {
      return n % 10 + 1;
    }
    // [1, 63]
    n = (n - 40 - 1) * 7 + Rand7();
    if (n <= 60) {
      return n % 10 + 1;
    }
    // [1, 21]
    n = (n - 60 - 1) * 7 + Rand7();
    if (n <= 20) {
      return n % 10 + 1;
    }
  }
}

int main() {
  for (int i = 0; i < 100000; i++) {
    int n = Rand10();
    assert(1 <= n && n <= 10);
  }
}
