class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> tmp;
    dfs(k, n, 1, tmp, ans);
    return ans;
  }
  void dfs(int depth, int gap, int start, vector<int>& tmp,
           vector<vector<int>>& ans) {
    if (tmp.size() == depth) {
      if (gap == 0) {
        ans.push_back(tmp);
        return;
      }
    }
    for (int i = start; i <= 9; ++i) {
      if (i > gap) break;
      tmp.push_back(i);
      dfs(depth, gap - i, i + 1, tmp, ans);
      tmp.pop_back();
    }
  }
};