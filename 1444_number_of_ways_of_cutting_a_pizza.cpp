class Solution {
  void add(long& a, long& b) { a = (a + b) % ((int)1e9 + 7); }

 public:
  int ways(vector<string>& pizza, int k) {
    int m = pizza.size(), n = pizza[0].size();
    vector<vector<int>> cnt(m + 1, vector<int>(n + 1));
    for (int i = m - 1; i >= 0; --i) {
      int s = 0;
      for (int j = n - 1; j >= 0; --j) {
        s += pizza[i][j] == 'A';
        cnt[i][j] = cnt[i + 1][j] + s;
      }
    }
    vector<vector<vector<long>>> dp(
        m + 1, vector<vector<long>>(n + 1, vector<long>(k + 1)));
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        dp[i][j][1] = 1;
        for (int l = 2; l <= k; ++l) {
          for (int t = i + 1; t < m; ++t) {
            if (cnt[i][j] == cnt[t][j]) continue;
            if (cnt[t][j] == 0) break;
            add(dp[i][j][l], dp[t][j][l - 1]);
          }
          for (int t = j + 1; t < n; ++t) {
            if (cnt[i][j] == cnt[i][t]) continue;
            if (cnt[i][t] == 0) break;
            add(dp[i][j][l], dp[i][t][l - 1]);
          }
        }
      }
    }
    return dp[0][0][k];
  }
};