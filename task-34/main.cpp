#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int binSearch(const vector<int> &nums, int target, bool leftBias) {
  int l = 0, r = nums.size() - 1;
  int idx = -1;

  while (l <= r) {
    int m = (l + r) / 2;

    if (nums[m] < target) {
      l = m + 1;
    } else if (nums[m] > target) {
      r = m - 1;
    } else {
      idx = m;
      if (leftBias) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
  }
  return idx;
}

vector<int> searchRange(vector<int> &nums, int target) {
  return {binSearch(nums, target, true), binSearch(nums, target, false)};
}

ostream &operator<<(ostream &out, const vector<int> &vec) {
  out << "["s;
  for (size_t i = 0; i < vec.size(); ++i) {
    out << vec[i] << (i + 1 == vec.size() ? ""s : ",");
  }
  out << "]"s;
  return out;
}

int main() {
  vector<int> a = {2, 2};

  cout << searchRange(a, 3) << endl;
}