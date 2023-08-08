#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
  vector<int> res;
  for (int i = 0; i <= rowIndex; ++i) {
    res.resize(i + 1, 1);
    int tmp = res[0];
    for (int j = 1; j <= i / 2; ++j) {
      int tmp1 = res[j];
      res[j] = res[i - j] = res[j] + tmp;
      tmp = tmp1;
    }
  }
  return std::move(res);
}

ostream &operator<<(ostream &out, const vector<int> &arr) {
  out << "["s;
  for (int i = 0; i < arr.size(); ++i) {
    out << arr[i] << (i + 1 == arr.size() ? ""s : ","s);
  }
  out << "]"s;
  return out;
}

int main() { cout << getRow(6) << endl; }