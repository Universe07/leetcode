class Solution {
 public:
#define matrix vector<vector<int>>
  int n, m;
  map<matrix, int> dis;
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  inline bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
  }
  vector<matrix> get_neighbours(matrix& mat) {
    vector<matrix> ans;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        matrix mat2 = mat;
        mat2[i][j] = !mat[i][j];
        for (int dir = 0; dir < 4; ++dir) {
          int x = i + dx[dir], y = j + dy[dir];
          if (isValid(x, y)) mat2[x][y] = !mat[x][y];
        }
        ans.push_back(mat2);
      }
    }
    return ans;
  }
  inline bool check(matrix& mat) {
    bool ok = 1;
    for (auto& v : mat) {
      for (auto& i : v) {
        ok &= !i;
      }
    }
    return ok;
  }
  int bfs(matrix mat) {
    queue<matrix> q;
    q.push(mat);
    dis[mat] = 0;
    while (!q.empty()) {
      matrix mat = q.front();
      q.pop();
      int d = dis[mat];
      if (check(mat)) return d;
      auto v = get_neighbours(mat);
      for (auto& i : v) {
        if (!dis.count(i)) {
          dis[i] = d + 1;
          q.push(i);
        }
      }
    }
    return -1;
  }
  int minFlips(vector<vector<int>>& mat) {
    n = mat.size(), m = mat[0].size();
    dis.clear();
    return bfs(mat);
  }
};