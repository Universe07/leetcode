// Time: O(n)
// Space: O(1)

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    vector<int> dp(nums.size() + 2, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[1], nums[0]);
    for (int i = 2; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[nums.size() - 1];
  }
};