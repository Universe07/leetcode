class Solution {
 public:
  vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    vector<int> res(hits.size());
    vector<int> dir = {-1, 0, 1, 0, -1};
    for (auto hit : hits) {
      grid[hit[0]][hit[1]] -= 1;
    }
    for (int i = 0; i < grid[0].size(); ++i) {
      dfs(0, i, grid);
    }
    for (int k = hits.size() - 1; k >= 0; --k) {
      int i = hits[k][0], j = hits[k][1];
      grid[i][j] += 1;
      if (grid[i][j] == 1 && isConnnect(i, j, grid, dir)) {
        res[k] = dfs(i, j, grid) - 1;
      }
    }
    return res;
  }
  int dfs(int i, int j, vector<vector<int>>& grid) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] != 1)
      return 0;
    grid[i][j] = 2;
    return 1 + dfs(i - 1, j, grid) + dfs(i + 1, j, grid) + dfs(i, j - 1, grid) +
           dfs(i, j + 1, grid);
  }
  bool isConnnect(int i, int j, vector<vector<int>>& grid, vector<int>& dir) {
    if (i == 0) return true;
    for (int k = 1; k < 5; ++k) {
      int r = i + dir[k - 1], c = j + dir[k];
      if (0 <= r && r < grid.size() && 0 <= c && c < grid[0].size() &&
          grid[r][c] == 2) {
        return true;
      }
    }
    return false;
  }
};