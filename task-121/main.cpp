#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
  int profit = 0, min_elem = prices[0];
  for (size_t i = 1; i < prices.size(); ++i) {
    min_elem = min(min_elem, prices[i]);
    profit = max(profit, prices[i] - min_elem);
  }

  return profit;
}

int main() {
  vector<int> arr = {7, 1, 5, 3, 6, 4};
  cout << maxProfit(arr) << endl;
}