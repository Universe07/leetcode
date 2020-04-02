class Solution {
 public:
  int minTransfers(vector<vector<int>>& transactions) {
    unordered_map<int, long> bal;
    for (auto& t : transactions) bal[t[0]] -= t[2], bal[t[1]] += t[2];
    for (auto& b : bal)
      if (b.second) debt.push_back(b.second);
    return dfs(0);
  }

 private:
  int dfs(int s) {
    while (s < debt.size() && !debt[s]) ++s;
    int res = INT_MAX;
    for (long i = s + 1; i < debt.size(); ++i) {
      if (debt[i] * debt[s] < 0) {
        debt[i] += debt[s];
        res = min(res, 1 + dfs(s + 1));
        debt[i] -= debt[s];
      }
    }
    return res < INT_MAX ? res : 0;
  }
  vector<long> debt;
};