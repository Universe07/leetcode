class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    queue<pair<int, int>> que;
    vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        if (matrix[i][j] == 0) {
          que.push(make_pair(i, j));
        } else {
          ans[i][j] = INT_MAX;
        }
      }
    }
    const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!que.empty()) {
      auto cell = que.front();
      que.pop();
      for (const auto& dir : dirs) {
        auto i = cell.first + dir.first;
        auto j = cell.second + dir.second;
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() ||
            ans[i][j] <= ans[cell.first][cell.second] + 1) {
          continue;
        }
        que.emplace(make_pair(i, j));
        ans[i][j] = ans[cell.first][cell.second] + 1;
      }
    }
    return ans;
  }
};

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    queue<pair<int, int>> que;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          que.push({i, j});
          visited[i][j] = 1;
        }
      }
    }
    vector<int> dirs = {0, -1, 0, 1, 0};
    int step = 0;
    while (!que.empty()) {
      int size = que.size();
      while (size--) {
        auto pair = que.front();
        que.pop();
        int i = pair.first;
        int j = pair.second;
        ans[i][j] = step;
        for (int k = 0; k < 4; k++) {
          int x = i + dirs[k];
          int y = j + dirs[k + 1];
          if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
          que.push({x, y});
          visited[x][y] = 1;
        }
      }
      ++step;
    }
    return ans;
  }
};