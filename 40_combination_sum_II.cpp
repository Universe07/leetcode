// Time : O(n!)
// Space: O(1)

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> item;
    set<vector<int>> res_set;
    int sum = 0;
    sort(candidates.begin(), candidates.end());
    generate(0, target, 0, candidates, result, item, res_set);
    return result;
  }
  void generate(int i, int target, int sum, vector<int>& nums,
                vector<vector<int>>& result, vector<int>& item,
                set<vector<int>>& res_set) {
    if (i >= nums.size() || sum > target) {
      return;
    }
    item.push_back(nums[i]);
    sum += nums[i];
    if (target == sum && res_set.find(item) == res_set.end()) {
      result.push_back(item);
      res_set.insert(item);
    }
    generate(i + 1, target, sum, nums, result, item, res_set);
    sum -= nums[i];
    item.pop_back();
    generate(i + 1, target, sum, nums, result, item, res_set);
  }
};

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    if (candidates.empty()) return {};
    vector<vector<int>> ans;
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, tmp, ans);
    return ans;
  }
  void dfs(const vector<int>& candidates, int gap, int start, vector<int>& tmp,
           vector<vector<int>>& ans) {
    if (gap == 0) {
      ans.push_back(tmp);
      return;
    }
    for (int i = start; i < candidates.size(); ++i) {
      if (gap < candidates[i]) break;
      if (i > start && candidates[i] == candidates[i - 1]) continue;
      tmp.push_back(candidates[i]);
      dfs(candidates, gap - candidates[i], i + 1, tmp, ans);
      tmp.pop_back();
    }
  }
};

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    if (candidates.empty()) return {};
    set<vector<int>> ans;
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, tmp, ans);
    return vector<vector<int>>(ans.begin(), ans.end());
  }
  void dfs(const vector<int>& candidates, int gap, int start, vector<int>& tmp,
           set<vector<int>>& ans) {
    if (gap == 0) {
      ans.insert(tmp);
      return;
    }
    for (int i = start; i < candidates.size(); ++i) {
      if (candidates[i] > gap) break;
      tmp.push_back(candidates[i]);
      dfs(candidates, gap - candidates[i], i + 1, tmp, ans);
      tmp.pop_back();
    }
  }
};