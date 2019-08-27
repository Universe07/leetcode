class Solution {
 public:
  int cutOffTree(vector<vector<int>>& forest) {
    m = forest.size();
    n = forest[0].size();
    vector<tuple<int, int, int>> trees;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (forest[i][j] > 1) {
          trees.push_back({forest[i][j], i, j});
        }
      }
    }
    sort(trees.begin(), trees.end());
    int total_steps = 0;
    int sx = 0;
    int sy = 0;

    for (int i = 0; i < trees.size(); ++i) {
      int tx = get<1>(trees[i]);
      int ty = get<2>(trees[i]);
      int steps = BFS(forest, sx, sy, tx, ty);

      if (steps == INT_MAX) return -1;
      total_steps += steps;
      sx = tx;
      sy = ty;
    }
    return total_steps;
  }

 private:
  int BFS(const vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
    static int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int, int>> que;
    que.push({sx, sy});
    visited[sx][sy] = 1;
    int step = 0;

    while (!que.empty()) {
      int size = que.size();
      while (size--) {
        auto pair = que.front();
        que.pop();
        int i = pair.first;
        int j = pair.second;
        if (i == tx && j == ty) {
          return step;
        }
        for (int k = 0; k < 4; ++k) {
          int x = i + dirs[k][0];
          int y = j + dirs[k][1];
          if (x < 0 || x >= m || y < 0 || y >= n || !forest[x][y] ||
              visited[x][y])
            continue;
          visited[x][y] = 1;
          que.push({x, y});
        }
      }
      ++step;
    }
    return INT_MAX;
  }
  int m, n;
};