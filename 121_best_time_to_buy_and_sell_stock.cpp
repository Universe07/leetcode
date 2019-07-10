class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }
    int hold = INT_MIN;
    int release = INT_MIN;
    for (const auto& p : prices) {
      hold = max(hold, -p);
      release = max(release, hold + p);
    }
    return release;
  }
};