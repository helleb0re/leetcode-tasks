#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

using namespace std;

using dfsType = std::function<void(int, vector<int>, int)>;

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<vector<int>> result;

  std::function<void(int, vector<int>, int)> dfs =
      [&result, &candidates, target, &dfs](int i, vector<int> cur,
                                           int total) -> void {
    if (total == target) {
      result.emplace_back(cur);
      return;
    }

    if (i >= candidates.size() || total > target) {
      return;
    }

    cur.push_back(candidates[i]);
    dfs(i, cur, total + candidates[i]);
    cur.pop_back();
    dfs(i + 1, cur, total);
  };

  dfs(0, {}, 0);

  return result;
}

ostream &operator<<(ostream &out, const vector<int> &vec) {
  out << "["s;
  for (size_t i = 0; i < vec.size(); ++i) {
    out << vec[i] << (i + 1 == vec.size() ? ""s : ",");
  }
  out << "]"s;
  return out;
}

ostream &operator<<(ostream &out, const vector<vector<int>> &vec) {
  out << "["s;
  for (const vector<int> &elem : vec) {
    out << elem;
  }
  out << "]"s;
  return out;
}

int main() {
  vector<int> vec{2, 3, 5};
  cout << combinationSum(vec, 8) << endl;
}