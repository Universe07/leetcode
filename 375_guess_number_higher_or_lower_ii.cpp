class Solution {
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    return cal(dp, 1, n);
  }
  int cal(vector<vector<int>>& dp, int s, int e) {
    if (s >= e) return 0;
    if (dp[s][e] != 0) return dp[s][e];
    int res = INT_MAX;
    for (int i = s; i <= e; ++i) {
      int tmp = i + max(cal(dp, s, i - 1), cal(dp, i + 1, e));
      res = min(res, tmp);
    }
    dp[s][e] = res;
    return res;
  }
};

class Solution {
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int j = 2; j <= n; ++j) {
      for (int i = j - 1; i > 0; --i) {
        int globalMin = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
          int localMax = k + max(dp[i][k - 1], dp[k + 1][j]);
          globalMin = min(globalMin, localMax);
        }
        dp[i][j] = i + 1 == j ? i : globalMin;
      }
    }
    return dp[1][n];
  }
};