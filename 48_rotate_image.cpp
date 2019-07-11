class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    const auto n = matrix.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n - 1 - i; ++j) {
        const int tmp = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
        matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - i][j];
        matrix[n - 1 - i][j] = tmp;
      }
    }
  }
};