class Solution {
 public:
  int largestIsland(vector<vector<int>>& grid) {
    color = 1;
    g = &grid;
    m = grid.size();
    n = grid[0].size();
    unordered_map<int, int> lookup;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ++color;
          lookup[color] = getArea(i, j);
          ans = max(ans, lookup[color]);
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          int area = 1;
          for (int color : set<int>{getColor(i - 1, j), getColor(i + 1, j),
                                    getColor(i, j - 1), getColor(i, j + 1)}) {
            area += lookup[color];
          }
          ans = max(ans, area);
        }
      }
    }
    return ans;
  }

 private:
  int m;
  int n;
  int color;
  vector<vector<int>>* g;

  int getColor(int i, int j) {
    return (i < 0 || i >= m || j < 0 || j >= n) ? 0 : (*g)[i][j];
  }
  int getArea(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || (*g)[i][j] != 1) return 0;
    (*g)[i][j] = color;
    return getArea(i - 1, j) + getArea(i + 1, j) + getArea(i, j - 1) +
           getArea(i, j + 1) + 1;
  }
};