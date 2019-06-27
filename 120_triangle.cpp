// Time : O(n2)
// Space: O(n2)

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.empty()) {
      return 0;
    }
    vector<vector<int>> dp;
    for (int i = 0; i < triangle.size(); ++i) {
      dp.push_back(vector<int>());
      for (int j = 0; j < triangle[i].size(); ++j) {
        dp[i].push_back(0);
      }
    }
    for (int j = 0; j < dp.size(); ++j) {
      dp[dp.size() - 1][j] = triangle[dp.size() - 1][j];
    }
    for (int i = dp.size() - 2; i >= 0; --i) {
      for (int j = 0; j < dp[i].size(); ++j) {
        dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
      }
    }
    return dp[0][0];
  }
};