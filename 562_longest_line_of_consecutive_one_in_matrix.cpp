class Solution {
 public:
  int longestLine(vector<vector<int>>& M) {
    if (M.empty() || M[0].empty()) return 0;
    int n = M.size(), m = M[0].size();
    int maxl = 0, hor = 0, ver = 0, inc = 0, dec = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0, hor = 0; j < m; ++j, maxl = max(maxl, hor))
        hor = M[i][j] ? hor + 1 : 0;
    for (int j = 0; j < m; ++j)
      for (int i = 0, vec = 0; i < n; ++i, maxl = max(maxl, vec))
        vec = M[i][j] ? vec + 1 : 0;
    for (int k = 0; k < m + n; ++k) {
      for (int i = min(k, n - 1), j = max(0, k - n), inc = 0; i >= 0 && j < m;
           --i, ++j, maxl = max(maxl, inc)) {
        inc = M[i][j] ? inc + 1 : 0;
      }
      for (int i = max(n - 1 - k, 0), j = max(0, k - n), dec = 0;
           i < n && j < m; ++i, ++j, maxl = max(maxl, dec)) {
        dec = M[i][j] ? dec + 1 : 0;
      }
    }
    return maxl;
  }
};