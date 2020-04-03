// Explanation:
// Assume index in A and B is [0, N * N -1].

// Loop on A, if value == 1, save a coordinates i / N * 100 + i % N to LA.
// Loop on B, if value == 1, save a coordinates i / N * 100 + i % N to LB.
// Loop on combination (i, j) of LA and LB, increase count[i - j] by 1.
// If we slide to make A[i] orverlap B[j], we can get 1 point.
// Loop on count and return max values.
// I use a 1 key hashmap. Assume ab for row and cd for col, I make it abcd as
// coordinate. For sure, hashmap with 2 keys will be better for understanding.

// Complexity:
// Assume A the number of points in the image A
// B the number of points in the image B,
// N = A.length = B.length.
// O(N^2) time for preparing, and O(AB) time for loop.
// So overall O(AB + N^2) time. Space is O(A + B).

class Solution {
 public:
  int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<int> LA, LB;
    int N = A.size();
    unordered_map<int, int> count;
    for (int i = 0; i < N * N; ++i)
      if (A[i / N][i % N] == 1) LA.push_back(i / N * 100 + i % N);
    for (int i = 0; i < N * N; ++i)
      if (B[i / N][i % N] == 1) LB.push_back(i / N * 100 + i % N);
    for (int i : LA)
      for (int j : LB) count[i - j]++;
    int res = 0;
    for (auto& it : count) res = max(res, it.second);
    return res;
  }
};