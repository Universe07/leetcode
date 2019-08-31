class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    if (M.empty()) return 0;
    int n = M.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (!M[i][i]) continue;
      ++ans;
      dfs(M, i, n);
    }
    return ans;
  }

 private:
  void dfs(vector<vector<int>>& M, int i, int n) {
    for (int j = 0; j < n; ++j) {
      if (!M[i][j]) continue;
      M[i][j] = M[j][i] = 0;
      dfs(M, j, n);
    }
  }
};