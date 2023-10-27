#include <vector>

using namespace std;

// make two passes, first in-order, second in-reverse, to compute products
vector<int> productExceptSelf(vector<int> &nums) {
  std::vector<int> tmp(nums.size(), 1);
  int buff = nums.front();
  for (size_t i = 1; i < nums.size(); ++i) {
    tmp[i] *= buff;
    buff *= nums[i];
  }
  buff = nums.back();
  for (size_t i = nums.size() - 2; i > 0; --i) {
    tmp[i] *= buff;
    buff *= nums[i];
  }
  tmp.front() *= buff;
  return tmp;
}

int main() {
  auto arr = std::vector<int>{2, 3, 4};
  productExceptSelf(arr);
}