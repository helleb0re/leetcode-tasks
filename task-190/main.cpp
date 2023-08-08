#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

uint32_t reverseBits(uint32_t n) {
  uint32_t res = 0;
  for (int i = 31; n > 0; --i) {
    if (n % 2) {
      res += pow(2, i);
    }
    n /= 2;
  }

  return res;
}

int main() { cout << reverseBits(43261596) << endl; }