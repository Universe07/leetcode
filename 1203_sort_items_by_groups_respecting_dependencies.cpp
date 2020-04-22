class Graph {
 private:
  unordered_map<int, vector<int>> adj;
  unordered_map<int, int> inDegree;

 public:
  Graph() {}
  Graph(int n) {
    adj = unordered_map<int, vector<int>>{};
    inDegree = unordered_map<int, int>{};
    for (int i = 0; i < n; ++i) {
      inDegree[i] = 0;
      adj[i] = vector<int>{};
    }
  }
  Graph(vector<int>& vec) {
    adj = unordered_map<int, vector<int>>{};
    inDegree = unordered_map<int, int>{};
    for (const int& i : vec) {
      inDegree[i] = 0;
      adj[i] = vector<int>{};
    }
  }
  void addEdge(int from, int to) {
    adj[from].push_back(to);
    ++inDegree[to];
  }
  vector<int> sort() {
    queue<int> q;
    vector<int> ans;
    for (const auto& in : inDegree) {
      if (in.second == 0) q.push(in.first);
    }
    while (!q.empty()) {
      int h = q.front();
      q.pop();
      ans.push_back(h);
      for (const auto& ad : adj[h]) {
        --inDegree[ad];
        if (inDegree[ad] == 0) q.push(ad);
      }
    }
    return ans;
  }
};

class Solution {
 public:
  vector<int> sortItems(int n, int m, vector<int>& group,
                        vector<vector<int>>& beforeItems) {
    vector<vector<int>> groupItems(m, vector<int>{});
    for (int i = 0; i < n; ++i) {
      if (group[i] >= 0) {
        groupItems[group[i]].push_back(i);
      } else {
        group[i] = groupItems.size();
        groupItems.push_back(vector<int>{i});
      }
    }
    Graph groupGraph = Graph(groupItems.size());
    vector<Graph> groupItemsGraph(groupItems.size());
    for (int i = 0; i < groupItems.size(); ++i) {
      groupItemsGraph[i] = Graph(groupItems[i]);
    }
    for (int i = 0; i < n; ++i) {
      for (const int& item : beforeItems[i]) {
        int gi = group[i];
        if (gi == group[item]) {
          groupItemsGraph[gi].addEdge(item, i);
        } else {
          groupGraph.addEdge(group[item], gi);
        }
      }
    }
    vector<int> groupOrder = groupGraph.sort();
    vector<int> ans;
    if (groupOrder.size() < groupItems.size()) return ans;
    for (const int& i : groupOrder) {
      vector<int> order = groupItemsGraph[i].sort();
      if (order.size() < groupItems[i].size())
        return vector<int>{};
      else
        for (const int& j : order) ans.push_back(j);
    }
    return ans;
  }
};