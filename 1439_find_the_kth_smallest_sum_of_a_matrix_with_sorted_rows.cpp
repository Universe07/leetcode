class Solution {
 public:
  int kthSmallest(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    int left = m, right = m * 5000, ans = -1;
    while (left <= right) {
      int mid = (left + right) / 2;
      int cnt = helper(mat, m, n, mid, 0, 0, k);
      if (cnt >= k) {
        ans = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
  int helper(vector<vector<int>>& mat, int m, int n, int targetSum, int r,
             int sum, int k) {
    if (sum > targetSum) return 0;
    if (r == m) return 1;
    int ans = 0;
    for (int c = 0; c < n; ++c) {
      int cnt = helper(mat, m, n, targetSum, r + 1, sum + mat[r][c], k - ans);
      if (cnt == 0) break;
      ans += cnt;
      if (ans > k) break;
    }
    return ans;
  }
};