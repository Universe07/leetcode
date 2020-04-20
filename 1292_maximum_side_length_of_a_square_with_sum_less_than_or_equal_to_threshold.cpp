class Solution {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                    mat[i - 1][j - 1];
    int low = 0, high = min(m, n);
    while (low <= high) {
      int mid = (low + high) / 2;
      if (isMatrixExist(sum, threshold, mid)) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return high;
  }
  bool isMatrixExist(vector<vector<int>> sum, int threshold, int len) {
    for (int i = len; i < sum.size(); ++i)
      for (int j = len; j < sum[0].size(); ++j) {
        if (sum[i][j] - sum[i - len][j] - sum[i][j - len] +
                sum[i - len][j - len] <=
            threshold)
          return true;
      }
    return false;
  }
};