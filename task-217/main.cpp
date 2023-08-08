#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int> &nums) {
  unordered_set<int> pull;
  for (int num : nums) {
    if (pull.count(num) == 1) {
      return true;
    }
    pull.insert(num);
  }
  return false;
}