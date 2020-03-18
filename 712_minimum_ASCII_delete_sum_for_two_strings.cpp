// Time: O(l1 * l2)
// Space: O(l1 * l2)

class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    const int l1 = s1.length();
    const int l2 = s2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
    for (int i = 1; i <= l1; ++i) dp[i][0] = dp[i - 1][0] + s1[i - 1];
    for (int j = 1; j <= l2; ++j) dp[0][j] = dp[0][j - 1] + s2[j - 1];
    for (int i = 1; i <= l1; ++i) {
      for (int j = 1; j <= l2; ++j) {
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
      }
    }
    return dp[l1][l2];
  }
};