// DFS
// Time: O(n2)
// Space:

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    graph_ = vector<vector<int>>(numCourses);
    for (int i = 0; i < prerequisites.size(); ++i) {
      graph_[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    vector<int> visited(numCourses, 0);
    for (int i = 0; i < numCourses; ++i) {
      if (dfs(i, visited)) {
        return false;
      }
    }
    return true;
  }

 private:
  vector<vector<int>> graph_;
  bool dfs(int cur, vector<int>& visited) {
    if (visited[cur] == 1) return true;
    if (visited[cur] == 2) return false;

    visited[cur] = 1;
    for (int j = 0; j < graph_[cur].size(); ++j) {
      if (dfs(graph_[cur][j], visited)) {
        return true;
      }
    }
    visited[cur] = 2;
    return false;
  }
};

// topological sort
// Time: O(V + E)
// Space: O(E)

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    queue<int> zeroIndegree;
    unordered_map<int, unordered_set<int>> inDegree;
    unordered_map<int, unordered_set<int>> outDegree;

    for (int i = 0; i < prerequisites.size(); ++i) {
      inDegree[prerequisites[i][0]].insert(prerequisites[i][1]);
      outDegree[prerequisites[i][1]].insert(prerequisites[i][0]);
    }

    for (int i = 0; i < numCourses; ++i) {
      if (inDegree.find(i) == inDegree.end()) {
        zeroIndegree.push(i);
      }
    }

    while (!zeroIndegree.empty()) {
      int prep = zeroIndegree.front();
      zeroIndegree.pop();
      for (const auto& course : outDegree[prep]) {
        inDegree[course].erase(prep);
        if (inDegree[course].empty()) {
          zeroIndegree.push(course);
        }
      }
      outDegree.erase(prep);
    }
    if (!outDegree.empty()) {
      return false;
    }
    return true;
  }
};

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    graph = vector<vector<int>>(numCourses);
    for (int i = 0; i < prerequisites.size(); ++i) {
      graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    vector<int> visited(numCourses, 0);
    for (int i = 0; i < numCourses; ++i) {
      if (dfs(i, visited)) return false;
    }
    return true;
  }

 private:
  vector<vector<int>> graph;
  bool dfs(int cur, vector<int>& visited) {
    if (visited[cur] == 1) return true;
    if (visited[cur] == 2) return false;
    visited[cur] = 1;
    for (const int nextCur : graph[cur]) {
      if (dfs(nextCur, visited)) return true;
    }
    visited[cur] = 2;
    return false;
  }
};