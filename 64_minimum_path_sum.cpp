class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(grid);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0) {
          continue;
        }
        if (i == 0 || j == 0) {
          if (i == 0) {
            dp[0][j] += dp[0][j - 1];
          } else {
            dp[i][0] += dp[i - 1][0];
          }
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};