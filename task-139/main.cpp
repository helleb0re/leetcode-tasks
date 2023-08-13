#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool wordBreak(string s, vector<string> &wordDict) {
  vector<bool> dp(s.size() + 1, false);
  dp.back() = true;

  for (int i = s.size() - 1; i >= 0; --i) {

    for (const auto &word : wordDict) {

      if (i + word.size() <= s.size() && s.substr(i, word.size()) == word) {
        dp[i] = dp[i + word.size()];
      }
      if (dp[i]) {
        break;
      }
    }
  }

  return dp.front();
}

int main() {
  string s{"leetcode"s};
  vector<string> wordDict = {"leet"s, "code"s};
  cout << wordBreak(s, wordDict) << endl;
}