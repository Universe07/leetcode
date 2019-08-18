class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> tmp;
    dfs(n, 1, k, tmp, ans);
    return ans;
  }
  void dfs(int n, int start, int depth, vector<int>& tmp,
           vector<vector<int>>& ans) {
    if (tmp.size() == depth) {
      ans.push_back(tmp);
      return;
    }
    for (int i = start; i <= n; ++i) {
      tmp.push_back(i);
      dfs(n, i + 1, depth, tmp, ans);
      tmp.pop_back();
    }
  }
};