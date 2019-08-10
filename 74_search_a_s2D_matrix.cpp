class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
      return false;
    }
    const int m = matrix.size();
    const int n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (matrix[mid / n][mid % n] == target) {
        return true;
      }
      if (matrix[mid / n][mid % n] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return false;
  }
};