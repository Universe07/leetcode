// Solution: DP
// dp[i][j] : = prob of j coins face up after tossing first i coins.dp[i][j] =
// dp[i - 1][j] * (1 – p[i]) + dp[i - 1][j - 1] * p[i]
//
// Time complexity:O(n ^ 2)
// Space complexity : O(n ^ 2)->O(n)

class Solution {
 public:
  double probabilityOfHeads(vector<double>& prob, int target) {
    const int n = prob.size();
    vector<double> dp(target + 1);
    dp[0] = 1.0;
    for (int i = 0; i < n; ++i) {
      for (int j = min(i + 1, target); j >= 0; --j)
        dp[j] = dp[j] * (1 - prob[i]) + (j > 0 ? dp[j - 1] : 0) * prob[i];
    }
    return dp[target];
  }
};