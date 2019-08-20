#include "utils.h"

#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main() {
  vector<int> nums1{1, 2, 3, 0, 0, 0};
  vector<int> nums2{2, 5, 6};
  merge(nums1, 3, nums2, 3);
  PrintVector(nums1, nums1.size());
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  for (int i = m + n - 1; m > 0 && n > 0; --i) {
    if (nums1[m - 1] > nums2[n - 1]) {
      nums1[i] = nums1[--m];
    } else {
      nums1[i] = nums2[--n];
    }
  }
  if (n > 0) copy(nums2.begin(), nums2.begin() + n, nums1.begin());
}