// Time: O(|V| + |E|)
// Space: O(|V| + |E|)

class Solution {
 public:
  vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<int> ans(N, 0);
    vector<vector<int>> G(N);
    for (const auto& path : paths) {
      G[path[0] - 1].push_back(path[1] - 1);
      G[path[1] - 1].push_back(path[0] - 1);
    }
    for (int i = 0; i < N; ++i) {
      int mask = 0;
      for (const auto& j : G[i]) {
        mask |= (1 << ans[j]);
      }
      for (int c = 1; c <= 4 && ans[i] == 0; ++c) {
        if (!(mask & (1 << c))) ans[i] = c;
      }
    }
    return ans;
  }
};