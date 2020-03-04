// Time: O(n * m);
// Space: O(n * m);

class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    const int n = matrix.size();
    const int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        dp[i][j] = matrix[i][j];
        if (i && j && matrix[i][j])
          dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        ans += dp[i][j];
      }
    }
    return ans;
  }
};