#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target) {
  int l = 0, r = nums.size() - 1;

  while (l <= r) {
    int m = (l + r) / 2;

    if (nums[m] == target) {
      return m;
    }

    if (nums[m] >= nums[l]) {
      if (target < nums[l] || target > nums[m]) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    } else {
      if (target > nums[r] || target < nums[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
  }
  return -1;
}

int main() {
  vector<int> nums{4, 5, 6, 7, 0, 1, 2};
  cout << search(nums, 0) << endl;
}