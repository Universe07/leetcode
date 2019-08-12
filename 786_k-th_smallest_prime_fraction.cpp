class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    vector<int> ans(2, 0);
    double left = 0.0, right = 1.0;
    while (left < right) {
      auto mid = left + (right - left) / 2;
      int val = possible(A, mid, ans);
      if (val == K) {
        return {ans[0], ans[1]};
      } else if (val > K) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return {};
  }
  int possible(vector<int>& A, double mid, vector<int>& ans) {
    int count = 0;
    double max_f = 0.0;
    for (int i = 0, j = 1; i < A.size() - 1; ++i) {
      while (j < A.size() && A[i] > A[j] * mid) {
        ++j;
      }
      if (j == A.size()) break;
      count += A.size() - j;
      double f = static_cast<double>(A[i]) / A[j];
      if (max_f < f) {
        ans[0] = A[i];
        ans[1] = A[j];
        max_f = f;
      }
    }
    return count;
  }
};
