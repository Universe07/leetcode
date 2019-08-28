class Solution {
 public:
  int shortestBridge(vector<vector<int>>& A) {
    m = A.size();
    n = A[0].size();
    queue<pair<int, int>> que;
    bool found = false;
    for (int i = 0; i < m && !found; ++i) {
      for (int j = 0; j < n && !found; ++j) {
        if (A[i][j]) {
          dfs(A, i, j, que);
          found = true;
        }
      }
    }
    int step = 0;
    vector<int> dirs = {0, -1, 0, 1, 0};
    while (!que.empty()) {
      int size = que.size();
      while (size--) {
        int i = que.front().first;
        int j = que.front().second;
        que.pop();
        for (int k = 0; k < 4; ++k) {
          int x = i + dirs[k];
          int y = j + dirs[k + 1];
          if (x < 0 || x >= m || y < 0 || y >= n || A[x][y] == 2) continue;
          if (A[x][y] == 1) return step;
          que.push({x, y});
          A[x][y] = 2;
        }
      }
      ++step;
    }
    return -1;
  }

 private:
  void dfs(vector<vector<int>>& A, int i, int j, queue<pair<int, int>>& que) {
    if (i < 0 || i >= m || j < 0 || j >= n || A[i][j] != 1) return;
    A[i][j] = 2;
    que.emplace(i, j);
    dfs(A, i - 1, j, que);
    dfs(A, i + 1, j, que);
    dfs(A, i, j - 1, que);
    dfs(A, i, j + 1, que);
  }
  int m, n;
};