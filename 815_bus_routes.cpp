// Time: O(m * n) m:# of buses, n:# of routes;
// Space: O (m * n + m)

class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if (S == T) return 0;
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < routes.size(); ++i)
      for (const int& stop : routes[i]) m[stop].push_back(i);
    vector<int> visited(routes.size(), 0);
    queue<int> q;
    q.push(S);
    int buses = 0;
    while (!q.empty()) {
      int size = q.size();
      ++buses;
      while (size--) {
        int curr = q.front();
        q.pop();
        for (const int bus : m[curr]) {
          if (visited[bus]) continue;
          visited[bus] = 1;
          for (int stop : routes[bus]) {
            if (stop == T) return buses;
            q.push(stop);
          }
        }
      }
    }
    return -1;
  }
};