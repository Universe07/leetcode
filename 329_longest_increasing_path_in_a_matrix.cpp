class Solution {
 public:
  static vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int m, n;
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.length() == 0) return 0;
    m = matrix.length(), n = matrix[0].length();
    vector<vector<int>> cache(m, vector<int>(n));
    int maxLen = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int len = dfs(matrix, i, j, cache);
        maxLen = max(maxLen, len);
      }
    }
    return maxLen;
  }
  int dfs(vector<vector<int>>& matrix, int i, int j,
          vector<vector<int>>& cache) {
    if (cache[i][j] != 0) return cache[i][j];
    int tmp = 1;
    for (auto dir : dirs) {
      int x = i + dir[0], y = j + dir[1];
      if (x < 0 || y < 0 || x >= m || y >= n || matrix[x][y] <= matrix[i][j])
        continue;
			int len = 1 + dfs(matrix, x, y, cache);
			tmp = max(len, tmp);
    }
		cache[i][j] = tmp;
		return tmp;
  }
};