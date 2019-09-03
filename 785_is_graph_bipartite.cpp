class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    const int n = graph.size();
    vector<int> colors(n, 0);
    for (int i = 0; i < n; ++i) {
      if (!colors[i] && !dfs(graph, colors, i, 1)) return false;
    }
    return true;
  }
  bool dfs(vector<vector<int>>& graph, vector<int>& colors, int node,
           int color) {
    if (colors[node]) return color == colors[node];
    colors[node] = color;
    for (int next : graph[node]) {
      if (!dfs(graph, colors, next, -color)) return false;
    }
    return true;
  }
};

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    const int n = graph.size();
    vector<int> colors(n, 0);
    for (int i = 0; i < n; ++i) {
      if (!colors[i] && !dfs(graph, colors, i, 1)) return false;
    }
    return true;
  }
  bool dfs(vector<vector<int>>& graph, vector<int>& colors, int node,
           int color) {
    colors[node] = color;
    for (int next : graph[node]) {
      if (colors[next] == color) return false;
      if (colors[next] == 0 && !dfs(graph, colors, next, -color)) return false;
    }
    return true;
  }
};