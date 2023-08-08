#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
  vector<int> dp(static_cast<int>(arr.size()));
  dp[0] = arr[0];
  for (int i = 1; i < arr.size(); ++i)
  {
    int max_arr_val = 0, local_max = 0;
    for (int j = i; j >= max(0, i - k + 1); --j)
    {
      max_arr_val = max(arr[j], max_arr_val);
      local_max =
          max(local_max, (i - j + 1) * max_arr_val + (j == 0 ? 0 : dp[j - 1]));
    }
    dp[i] = local_max;
  }
  return dp[arr.size() - 1];
}

int main()
{
  vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
  cout << maxSumAfterPartitioning(arr, 3) << endl;
}