#include <iostream>
#include <vector>

int climbStairs(int n) {
  int step_1 = 1;
  int step_2 = 1;
  int tmp = 0;
  for (int i = 0; i < n - 1; ++i) {
    tmp = step_1;

    step_1 = step_1 + step_2;

    step_2 = tmp;
  }

  return step_1;
}

int main() { std::cout << climbStairs(4) << std::endl; }