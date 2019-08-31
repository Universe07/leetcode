class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    if (image[sr][sc] == newColor) {
      return image;
    }
    int m = image.size();
    int n = image[0].size();
    fill(image, m, n, image[sr][sc], sr, sc, newColor);
    return image;
  }
  void fill(vector<vector<int>>& image, int m, int n, int color, int i, int j,
            int newColor) {
    if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != color) return;
    image[i][j] = newColor;
    fill(image, m, n, color, i - 1, j, newColor);
    fill(image, m, n, color, i + 1, j, newColor);
    fill(image, m, n, color, i, j + 1, newColor);
    fill(image, m, n, color, i, j - 1, newColor);
  }
};