#include <bitset>
#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
  int count = 0;
  for (; n;) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int main() { cout << hammingWeight(5) << endl; }