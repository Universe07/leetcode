class Solution {
 public:
  string shortestSuperstring(vector<string>& A) {
    const int n = A.size();
    string ans;
    best_len = INT_MAX;
    cost = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cost[i][j] = A[j].length();
        for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k) {
          if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) {
            cost[i][j] = A[j].length() - k;
          }
        }
      }
    }
    vector<int> path(n);
    dfs(A, 0, 0, 0, path);
    string ans = A[best_path[0]];
    for (int k = 1; k < best_path.size(); ++k) {
      int pre = best_path[k - 1];
      int cur = best_path[k];
      ans += A[cur].substr(A[cur].length() - cost[pre][cur]);
    }
    return ans;
  }

 private:
  vector<vector<int>> cost;
  vector<int> best_path;
  int best_len;
  void dfs(const vector<string>& A, int d, int used, int cur_len,
           vector<int>& path) {
    if (cur_len > best_len) return;
    if (d == A.size()) {
      best_path = path;
      best_len = cur_len;
      return;
    }
    for (int i = 0; i < A.size(); ++i) {
      if (used & (1 << i)) continue;
      path[d] = i;
      dfs(A, d + 1, used | (1 << i),
          d == 0 ? A[i].length() : cur_len + cost[path[d - 1]][i], path);
    }
  }
};