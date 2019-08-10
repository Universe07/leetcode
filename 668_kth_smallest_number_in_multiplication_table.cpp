class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    int left = 1, right = m * n;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (count(mid, m, n) >= k) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
  int count(int target, int m, int n) {
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
      cnt += min(target / i, n);
    }
    return cnt;
  }
};