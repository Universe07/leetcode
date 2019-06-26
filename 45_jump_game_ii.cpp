// Time: O(n)
// Space: O(1)

class Solution {
 public:
  int jump(vector<int>& nums) {
    int ans = 0;
    int cur = 0, pre = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > pre) {
        pre = cur;
        ++ans;
      }
      cur = max(cur, i + nums[i]);
    }
    return ans;
  }
};