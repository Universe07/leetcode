class Solution {
 public:
  bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    int n = org.size();
    vector<int> order(n + 1);
    for (int i = 0; i < n; ++i) {
      order[org[i]] = i;
    }
    vector<bool> hasPair(n);
    for (auto& v : seqs) {
      if (v.empty()) continue;
      for (int i = 0; i < v.size(); ++i) {
        if (v[i] < 1 || v[i] > n) return false;
        if (!i) continue;
        auto a = order[v[i - 1]];
        auto b = order[v[i]];
        if (a >= b) return false;
        if (a + 1 == b) hasPair[a] = true;
      }
      auto b = order[v.back()];
      if (b == n - 1) hasPair[b] = true;
    }
    return all_of(hasPair.begin(), hasPair.end(), [](auto a) { return a; });
  }
};