class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int rows = grid.size(), cols = grid[0].size();
    int minSteps = max(0, rows + cols - 2), obstacls = minSteps - 1;
    if (obstacls <= k) return minSteps;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    list<vector<int>> togo;
    togo.push_back({0, 0, k});
    vector<int> visited(rows * cols, -1);
    visited[0] = k;
    int steps = 0;
    while (togo.size()) {
      steps++;
      for (int sz = togo.size(); sz > 0; sz--) {
        int r = togo.front()[0], c = togo.front()[1], o = togo.front()[2];
        togo.pop_front();
        for (auto& d : dirs) {
          int rr = r + d[0], cc = c + d[1];
          if (rr < 0 || rr >= rows || cc < 0 || cc >= cols) continue;
          int kk = o - grid[rr][cc];
          if (visited[rr * cols + cc] >= kk) continue;
          int stepsLeft = rows - rr - 1 + cols - cc - 1;
          if (stepsLeft - 1 <= kk) return steps + stepsLeft;
          togo.push_back({rr, cc, kk});
          visited[rr * cols + cc] = kk;
        }
      }
    }
    return -1;
  }
};