#include <array>
#include <iostream>
#include <vector>

using namespace std;

// solution with grid
/*
int uniquePaths(int m, int n) {
  vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));
  grid[m - 1][n - 1] = 1;

  for (int i = m - 1; i >= 0; --i) {

    for (int j = n - 1; j >= 0; --j) {

      grid[i][j] += grid[i + 1][j] + grid[i][j + 1];

    }
  }

  return grid[0][0];
}
*/

// solution with memorize only curr and prev rows
int uniquePaths(int m, int n) {
  vector<int> row(n + 1, 1);
  row.back() = 0;
  for (int i = m - 2; i >= 0; --i) {
    vector<int> new_row(n + 1, 1);
    new_row.back() = 0;
    for (int j = n - 1; j >= 0; --j) {
      new_row[j] = row[j] + new_row[j + 1];
    }
    std::swap(row, new_row);
  }

  return row[0];
}

int main() { std::cout << uniquePaths(3, 7) << std::endl; }