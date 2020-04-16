class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0, cur = 0; i < nums.size(); ++i) {
      cur += nums[i];
      if (mp.count(cur - k) > 0) {
        ans = max(ans, i - mp[cur - k]);
      }
      if (mp.count(cur) <= 0) {
        mp[cur] = i;
      }
    }
    return ans;
  }
};