// Time: O(N + T);
// Space: O(N)

class Solution {
 public:
  int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> degrees(N + 1);
    for (const auto& tr : trust) {
      --degrees[tr[0]];
      ++degrees[tr[1]];
    }
    for (int i = 1; i <= N; ++i) {
      if (degrees[i] == N - 1) return i;
    }
    return -1;
  }
};