class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
      int u = edge[0];
      int v = edge[1];

      unordered_set<int> visited;
      if (hasPath(u, v, graph, visited)) {
        return edge;
      }
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    return {};
  }

 private:
  bool hasPath(int curr, int goal, const unordered_map<int, vector<int>>& graph,
               unordered_set<int>& visited) {
    if (curr == goal) return true;
    visited.insert(curr);
    if (!graph.count(curr) || !graph.count(goal)) {
      return false;
    }
    for (int next : graph.at(curr)) {
      if (visited.count(next)) continue;
      if (hasPath(next, goal, graph, visited)) return true;
    }
    return false;
  }
};

class UnionFindSet {
 public:
  UnionFindSet(int n) {
    parents_ = vector<int>(n + 1, 0);
    ranks_ = vector<int>(n + 1, 0);
    for (int i = 0; i < parents_.size(); ++i) {
      parents_[i] = i;
    }
  }

  int Find(int x) {
    if (x != parents_[x]) {
      parents_[x] = Find(parents_[x]);
    }
    return parents_[x];
  }
  bool Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);
    if (px == py) return false;

    if (ranks_[px] > ranks_[py])
      parents_[py] = px;
    else if (ranks_[py] > ranks_[px])
      parents_[px] = py;
    else {
      parents_[py] = px;
      ranks_[px] += 1;
    }
    return true;
  }

 private:
  vector<int> parents_;
  vector<int> ranks_;
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFindSet s(edges.size());
    for (const auto& edge : edges) {
      if (!s.Union(edge[0], edge[1])) {
        return edge;
      }
    }
    return {};
  }
};