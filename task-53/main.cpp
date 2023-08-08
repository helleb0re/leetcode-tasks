#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// use kadane's algorithm
int maxSubArray(vector<int> &nums) {
  int curr_sum = 0, best_sum = numeric_limits<int>::min();
  for (int i = 0; i < nums.size(); ++i) {
    curr_sum = max(nums[i], curr_sum + nums[i]);
    best_sum = max(best_sum, curr_sum);
  }
  return best_sum;
}

int main() {
  vector<int> nums = {-1};
  cout << maxSubArray(nums) << endl;
}