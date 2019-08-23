class Solution {
 public:
  int totalNQueens(int n) {
    ans = 0;
    cols = vector<int>(n, 0);
    diag1 = vector<int>(n * 2 - 1, 0);
    diag2 = vector<int>(n * 2 - 1, 0);
    nqueens(n, 0);
    return ans;
  }

 private:
  vector<int> cols;
  vector<int> diag1;
  vector<int> diag2;
  int ans;
  bool available(int row, int col, int n) {
    return !cols[col] && !diag1[row + col] && !diag2[row - col + n - 1];
  }
  void update(int row, int col, int n, bool is_put) {
    cols[col] = is_put;
    diag1[row + col] = is_put;
    diag2[row - col + n - 1] = is_put;
  }
  void nqueens(int n, int row) {
    if (row == n) {
      ans++;
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (!available(row, col, n)) continue;
      update(row, col, n, true);
      nqueens(n, row + 1);
      update(row, col, n, false);
    }
  }
};