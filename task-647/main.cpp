#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

int countSubstrings(string s) {
  size_t res = 0;
  for (int i = 0; i < s.size(); ++i) {
    // check odd length palindrome
    int l = i, r = i;
    while (l > -1 && r < s.size() && s[l--] == s[r++]) {
      ++res;
    }
    // check even length palindrome
    l = i, r = i + 1;
    while (l > -1 && r < s.size() && s[l--] == s[r++]) {
      ++res;
    }
  }
  return res;
}

int main() { cout << countSubstrings("aaa"s) << endl; }