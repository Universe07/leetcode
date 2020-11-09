class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
      ans[i] = nums[i / 2 + i % 2 * n];
    }
    return ans;
  }
};