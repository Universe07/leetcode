// Solution: DP
// dp[i] : = max sum that has a remainder i when mod 3.
// dp[(i + num) % 3] = max(dp[(i + num) % 3], dp[i] + num)
// ans : dp[0]
// Time: O(n)
// Space: O(1)

class Solution {
 public:
  int maxSumDivThree(vector<int>& nums) {
    vector<int> dp(3);
    for (int num : nums) {
      vector<int> tmp(dp);
      for (int s : tmp) {
        dp[(s + num) % 3] = max(dp[(s + num) % 3], s + num);
      }
    }
    return dp[0];
  }
};