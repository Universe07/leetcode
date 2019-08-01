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