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

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
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
      if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) continue;
      used[i] = 1;
      tmp.push_back(nums[i]);
      dfs(nums, used, tmp, ans);
      tmp.pop_back();
      used[i] = 0;
    }
  }
};