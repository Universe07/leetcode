class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    help(ans, nums, 0);
    return ans;
  }
  void help(vector<vector<int>>& ans, vector<int> nums, int pos) {
    if (pos == nums.size() - 1) {
      ans.push_back(nums);
      return;
    }
    for (int i = pos; i < nums.size(); ++i) {
      swap(nums[i], nums[pos]);
      help(ans, nums, pos + 1);
    }
  }
};