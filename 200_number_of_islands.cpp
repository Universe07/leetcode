class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    vector<vector<int>> mark;
    for (int i = 0; i < grid.size(); ++i) {
      mark.push_back(vector<int>(grid[i].size()));
      for (int j = 0; j < grid[i].size(); ++j) {
        mark[i][j] = 0;
      }
    }
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (mark[i][j] == 0 && grid[i][j] == '1') {
          DFS(mark, grid, i, j);
          // BFS(mark, grid, i, j);
          ++ans;
        }
      }
    }
    return ans;
  }
  void DFS(vector<vector<int>>& mark, vector<vector<char>>& grid, int x,
           int y) {
    mark[x][y] = 1;
    static const vector<int> dx = {-1, 1, 0, 0};
    static const vector<int> dy = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
      int newx = dx[i] + x;
      int newy = dy[i] + y;
      if (newx < 0 || newx > mark.size() - 1 || newy < 0 ||
          newy > mark[newx].size() - 1) {
        continue;
      }
      if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
        DFS(mark, grid, newx, newy);
      }
    }
  }
  void BFS(vector<vector<int>>& mark, vector<vector<char>>& grid, int x,
           int y) {
    static const vector<int> dx = {-1, 1, 0, 0};
    static const vector<int> dy = {0, 0, -1, 1};
    queue<pair<int, int>> que;
    que.push(make_pair(x, y));
    mark[x][y] = 1;
    while (!que.empty()) {
      x = que.front().first;
      y = que.front().second;
      que.pop();
      for (int i = 0; i < 4; ++i) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx > grid.size() - 1 || newy < 0 ||
            newy > grid[newx].size() - 1) {
          continue;
        }
        if (mark[newx][newy] == 0 || grid[newx][newy] == '1') {
          que.push(make_pair(newx, newy));
          mark[newx][newy] = 1;
        }
      }
    }
  }
};