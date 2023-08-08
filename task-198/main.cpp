#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums) {
  int prev_max_wo_last_elem = 0, prev_max_sub_arr = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    int tmp = prev_max_sub_arr;
    prev_max_sub_arr = max(prev_max_sub_arr, prev_max_wo_last_elem + nums[i]);
    prev_max_wo_last_elem = tmp;
  }
  return prev_max_sub_arr;
}

int main() {
  vector<int> arr = {2, 1, 1, 2};
  cout << rob(arr) << endl;
}