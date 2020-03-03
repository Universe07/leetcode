class Solution {
 public:
  int longestMountain(vector<int>& A) {
    vector<int> inc(A.size());
    vector<int> dec(A.size());
    for (int i = 1; i < A.size(); ++i)
      if (A[i] > A[i - 1]) inc[i] = inc[i - 1] + 1;
    for (int i = A.size() - 2; i > 0; --i)
      if (A[i] > A[i + 1]) dec[i] = dec[i + 1] + 1;
    int ans = 0;
    for (int i = 0; i < A.size(); ++i)
      if (inc[i] && dec[i]) ans = max(ans, inc[i] + dec[i] + 1);
    return ans >= 3 ? ans : 0;
  }
};

class Solution {
 public:
  int longestMountain(vector<int>& A) {
    int inc = 0;
    int dec = 0;
    int ans = 0;
    for (int i = 1; i < A.size(); ++i) {
      if (dec && A[i] > A[i - 1] || A[i] == A[i - 1]) inc = dec = 0;
      inc += A[i] > A[i - 1];
      dec += A[i] < A[i - 1];
      if (inc && dec) ans = max(ans, inc + dec + 1);
    }
    return ans >= 3 ? ans : 0;
  }
};