class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (visited[i][j]) continue;
        ans = max(ans, dfs(grid, i, j, m, n, visited));
      }
    }
    return ans;
  }
  int dfs(const vector<vector<int>>& grid, int i, int j, int m, int n,
          vector<vector<int>>& visited) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 ||
        visited[i][j] == 1) {
      return 0;
    }
    visited[i][j] = 1;
    return dfs(grid, i - 1, j, m, n, visited) +
           dfs(grid, i + 1, j, m, n, visited) +
           dfs(grid, i, j - 1, m, n, visited) +
           dfs(grid, i, j + 1, m, n, visited) + 1;
  }
};