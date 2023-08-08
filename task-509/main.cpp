#include <iostream>
#include <utility>

using namespace std;

int fib(int n) {
  int f0 = 0, f1 = 1;

  for (int i = 1; i < n; ++i) {
    swap(f1, f0);
    f1 = f1 + f0;
  }

  return n == 0 ? f0 : f1;
}

int main() { cout << fib(2) << endl; }