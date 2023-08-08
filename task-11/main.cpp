#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height) {
  int left = height.front(), right = height.back();
  int left_ind = 0, right_ind = height.size() - 1;
  int max_area = min(left, right) * (right_ind - left_ind);
  while (left_ind + 1 != right_ind) {
    if (left <= right) {
      left = height[++left_ind];
    } else {
      right = height[--right_ind];
    }
    max_area = max(max_area, min(left, right) * (right_ind - left_ind));
  }

  return max_area;
}

int main() {
  vector<int> arr = {1, 1};
  cout << maxArea(arr) << endl;
}