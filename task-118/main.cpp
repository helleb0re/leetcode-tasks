#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> res = {static_cast<size_t>(numRows), vector<int>{}};
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0 || j == i) {
        res[i].push_back(1);
      } else {
        res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
      }
    }
  }
  return std::move(res);
}

ostream &operator<<(ostream &out, const vector<vector<int>> &arr) {
  out << "["s;
  for (int i = 0; i < arr.size(); ++i) {
    out << "["s;
    for (int j = 0; j < arr[i].size(); ++j) {
      out << arr[i][j] << (j + 1 == arr[i].size() ? ""s : ","s);
    }
    out << (i + 1 == arr.size() ? "]"s : "],"s);
  }
  out << "]"s;
  return out;
}

int main() { cout << generate(5) << endl; }