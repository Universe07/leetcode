// Solution 1 : DP
// Time complexity : O(kn ^ 2)
// Space complexity : O(kn)

class Solution {
 public:
  double largestSumOfAverages(vector<int>& A, int K) {
    const int n = A.size();
    vector<vector<double>> dp(K + 1, vector<double>(n + 1, 0.0));
    vector<double> sum(n + 1, 0.0);
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + A[i - 1];
      dp[1][i] = static_cast<double>(sum[i]) / i;
    }
    for (int k = 2; k <= K; ++k) {
      for (int i = k; i <= n; ++i) {
        for (int j = k - 1; j < i; ++j) {
          dp[k][i] = max(dp[k][i], dp[k - 1][j] + (sum[i] - sum[j]) / (i - j));
        }
      }
    }
    return dp[K][n];
  }
};

class Solution {
 public:
  double largestSumOfAverages(vector<int>& A, int K) {
    const int n = A.size();
    vector<double> dp(n + 1, 0.0);
    vector<double> sums(n + 1, 0.0);
    for (int i = 1; i <= n; ++i) {
      sums[i] = sums[i - 1] + A[i - 1];
      dp[i] = static_cast<double>(sums[i]) / i;
    }
    for (int k = 2; k <= K; ++k) {
      vector<double> tmp(n + 1, 0.0);
      for (int i = k; i <= n; ++i)
        for (int j = k - 1; j < i; ++j)
          tmp[i] = max(tmp[i], dp[j] + (sums[i] - sums[j]) / (i - j));
      dp.swap(tmp);
    }
    return dp[n];
  }
};
