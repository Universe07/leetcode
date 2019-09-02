class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<State> visited(graph.size(), UNKNOWN);
    vector<int> ans;
    for (int i = 0; i < graph.size(); ++i) {
      if (dfs(graph, visited, i, ans) == SAFE) {
        ans.push_back(i);
      }
    }
    return ans;
  }

 private:
  enum State { UNKNOWN, VISITING, SAFE, UNSAFE };
  State dfs(vector<vector<int>>& graph, vector<State>& visited, int cur,
            vector<int>& ans) {
    if (visited[cur] == VISITING) return UNSAFE;
    if (visited[cur] != UNKNOWN) return visited[cur];
    visited[cur] = VISITING;
    for (int next : graph[cur]) {
      if (dfs(graph, visited, next, ans) == UNSAFE)
        return visited[cur] = UNSAFE;
    }
    return visited[cur] = SAFE;
  }
};