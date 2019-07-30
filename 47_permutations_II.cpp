class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    unordered_map<int, int> count;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      ++count[nums[i]];
    }
    vector<int> path;
    n = nums.size();
    permute(count, path, ans);
    return ans;
  }

 private:
  size_t n;
  void permute(unordered_map<int, int>& count, vector<int>& path,
               vector<vector<int>>& ans) {
    if (path.size() == n) {
      ans.push_back(path);
      return;
    }
    for (auto& it : count) {
      if (it.second) {
        path.push_back(it.first);
        --it.second;
        permute(count, path, ans);
        path.pop_back();
        ++it.second;
      }
    }
  }
};