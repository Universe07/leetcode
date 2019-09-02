class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    graph = vector<vector<int>>(numCourses);
    vector<int> ans;
    vector<int> visited(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); ++i) {
      graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    for (int i = 0; i < numCourses; ++i) {
      if (dfs(i, visited, ans)) return {};
    }
    return ans;
  }

 private:
  vector<vector<int>> graph;
  bool dfs(int cur, vector<int>& visited, vector<int>& ans) {
    if (visited[cur] == 1) return true;
    if (visited[cur] == 2) return false;
    visited[cur] = 1;
    for (int nextCur : graph[cur]) {
      if (dfs(nextCur, visited, ans)) return true;
    }
    visited[cur] = 2;
    ans.push_back(cur);
    return false;
  }
};