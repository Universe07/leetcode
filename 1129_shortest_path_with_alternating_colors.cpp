class Solution {
 public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges,
                                       vector<vector<int>>& blue_edges) {
    vector<unordered_set<int>> edge_r(n);
    vector<unordered_set<int>> edge_b(n);
    for (const auto& edge : red_edges) edge_r[edge[0]].insert(edge[1]);
    for (const auto& edge : blue_edges) edge_b[edge[0]].insert(edge[1]);
    unordered_set<int> seen_r;
    unordered_set<int> seen_b;
    vector<int> ans(n, -1);
    queue<pair<int, int>> que;
    que.push({0, 0});
    que.push({0, 1});
    seen_r.insert(0);
    seen_b.insert(0);
    int steps = 0;
    while (!que.empty()) {
      int size = que.size();
      while (size--) {
        int p = que.front().first;
        int is_red = que.front().second;
        que.pop();
        ans[p] = ans[p] >= 0 ? min(ans[p], steps) : steps;
        const auto& edges = is_red ? edge_r : edge_b;
        auto& seen = is_red ? seen_r : seen_b;
        for (int next : edges[p]) {
          if (seen.count(next)) continue;
          seen.insert(next);
          que.push({next, 1 - is_red});
        }
      }
      ++steps;
    }
    return ans;
  }
};