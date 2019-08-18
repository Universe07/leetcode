class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (candidates.empty()) return {};
    vector<vector<int>> ans;
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, target, tmp, ans);
    return ans;
  }
  void dfs(const vector<int>& candidates, int start, int gap, vector<int>& tmp,
           vector<vector<int>>& ans) {
    if (gap == 0) {
      ans.push_back(tmp);
      return;
    }
    for (int i = start; i < candidates.size(); ++i) {
      if (candidates[i] > gap) break;
      tmp.push_back(candidates[i]);
      dfs(candidates, i, gap - candidates[i], tmp, ans);  // 是从i开始
      tmp.pop_back();
    }
  }
};