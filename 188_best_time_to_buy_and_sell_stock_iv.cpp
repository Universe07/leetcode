class Solution {
 public:
  int len;
  int maxProfit(int k, vector<int>& prices) {
    len = prices.size();
    if (k >= len / 2) return quickSolve(prices);
    vector<vector<int>> dp(k + 1, vector<int>(len));
    for (int i = 1; i <= k; ++i) {
      int tmp = -prices[0];
      for (int j = 1; j < len; ++j) {
        dp[i][j] = max(dp[i][j - 1], prices[j] + tmp);
        tmp = max(tmp, dp[i - 1][j - 1] - prices[j]);
      }
    }
    return dp[k][len - 1];
  }

 private:
  int quickSolve(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < len; ++i)
      if (prices[i] > prices[i - 1]) profit += (prices[i] - prices[i - 1]);
    return profit;
  }
};