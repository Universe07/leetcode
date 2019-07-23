class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    vector<int> ans;
    int left = 0, right = A.size() - 1;
    while (left <= right) {
      if (A[left] * A[left] <= A[right] * A[right]) {
        ans.emplace_back(A[right] * A[right]);
        --right;
      } else {
        ans.emplace_back(A[left] * A[left]);
        ++left;
      }
    }
    // reverse(ans.begin(), ans.end());
    left = 0;
    right = A.size() - 1;
    while (left <= right) {
      swap(ans[left], ans[right]);
      ++left;
      --right;
    }
    return ans;
  }
};

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    vector<int> ans;
    int right = 0;
    while (right < A.size() && A[right] < 0) {
      ++right;
    }
    int left = right - 1;
    while (0 <= left && right < A.size()) {
      if (A[left] * A[left] >= A[right] * A[right]) {
        ans.emplace_back(A[right] * A[right]);
        ++right;
      } else {
        ans.emplace_back(A[left] * A[left]);
        --left;
      }
    }
    while (left >= 0) {
      ans.emplace_back(A[left] * A[left]);
      --left;
    }
    while (right < A.size()) {
      ans.emplace_back(A[right] * A[right]);
      ++right;
    }
    return ans;
  }
};
