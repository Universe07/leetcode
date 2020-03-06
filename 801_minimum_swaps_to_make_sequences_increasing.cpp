// Time: O(n)
// Space: O(n)

class Solution {
 public:
  int minSwap(vector<int>& A, vector<int>& B) {
    const int n = A.size();
    vector<int> keep(n, INT_MAX);
    vector<int> swap(n, INT_MAX);
    keep[0] = 0;
    swap[0] = 1;
    for (int i = 1; i < n; ++i) {
      if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
        keep[i] = keep[i - 1];
        swap[i] = swap[i - 1] + 1;
      }
      if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
        keep[i] = min(swap[i - 1], keep[i]);
        swap[i] = min(keep[i - 1] + 1, swap[i]);
      }
    }
    return min(keep.back(), swap.back());
  }
};