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

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> used(nums.size());
    vector<int> tmp;
    dfs(nums, used, tmp, ans);
    return ans;
  }
  void dfs(const vector<int>& nums, vector<int>& used, vector<int>& tmp,
           vector<vector<int>>& ans) {
    if (tmp.size() == nums.size()) {
      ans.push_back(tmp);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) continue;
      used[i] = 1;
      tmp.push_back(nums[i]);
      dfs(nums, used, tmp, ans);
      tmp.pop_back();
      used[i] = 0;
    }
  }
};