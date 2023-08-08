#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;
/*
int maxProduct(int A[], int n) {
    store the result that is the max we have found so far
    int r = A[0];

    imax/imin stores the max/min product of
    subarray that ends with the current number A[i]
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        multiplied by a negative makes big number smaller, small number bigger
        so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        max/min product for the current number is either the current number itself
        or the max/min by the previous number times the current one
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}
*/


int maxProduct(vector<int> &nums) {
  int min_prod = nums[0], max_prod = nums[0], best_prod = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    int curr_min_prod = min_prod;
    min_prod = min(nums[i], min(max_prod * nums[i], min_prod * nums[i]));
    max_prod = max(nums[i], max(max_prod * nums[i], curr_min_prod * nums[i]));
    best_prod = max(best_prod, max_prod);
  }
  return best_prod;
}

int main() {
  vector<int> nums = {2, 3, -2, 4};
  cout << maxProduct(nums) << endl;
}