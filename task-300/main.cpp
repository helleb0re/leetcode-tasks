#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &nums) {
  int n = nums.size();
  vector<int> dp(n, 1);
  int max_lng = dp.back();
  for (int i = n - 2; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] < nums[j]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
    max_lng = max(max_lng, dp[i]);
  }
  return max_lng;
}

int main() {
  vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << lengthOfLIS(arr) << endl;
}