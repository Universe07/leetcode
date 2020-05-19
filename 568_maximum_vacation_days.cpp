class Solution {
 public:
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    int city = days.size();
    int week = days[0].size();
    vector<int> dp(city, INT_MIN);
    dp[0] = 0;
    for (int i = 0; i < week; ++i) {
      vector<int> tmp(city, INT_MIN);
      for (int j = 0; j < city; ++j) {
        for (int k = 0; k < city; ++k) {
          if (k == j || flights[k][j] == 1) {
            tmp[j] = max(tmp[j], dp[k] + days[j][i]);
          }
        }
      }
      dp = tmp;
    }
    int ans = *max_element(dp.begin(), dp.end());
    return ans;
  }
};