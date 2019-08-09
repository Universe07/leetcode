class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    int left = matrix[0][0];
    int right = matrix[m - 1][n - 1] + 1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      int total = canFinish(matrix, k, mid);
      if (total >= k) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

 private:
  int canFinish(vector<vector<int>>& matrix, int k, int mid) {
    int total = 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] <= mid) {
          ++total;
        }
      }
    }
    return total;
  }
};