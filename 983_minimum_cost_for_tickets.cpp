class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(days[days.size() - 1] + 1, 0);
    vector<bool> travel(days[days.size() - 1] + 1, false);
    for (int i = 0; i < days.size(); ++i) travel[days[i]] = true;
    for (int i = 1; i < dp.size(); ++i) {
      if (!travel[i])
        dp[i] = dp[i - 1];
      else {
        int q1 = dp[max(i - 1, 0)] + costs[0];
        int q2 = dp[max(i - 7, 0)] + costs[1];
        int q3 = dp[max(i - 30, 0)] + costs[2];
        dp[i] = min(q1, min(q2, q3));
      }
    }
    return dp[dp.size() - 1];
  }
};