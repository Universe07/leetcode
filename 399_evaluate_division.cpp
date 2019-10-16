class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> lookup;
    for (int i = 0; i < equations.size(); ++i) {
      lookup[equations[i][0]].emplace(equations[i][1], values[i]);
      if (values[i]) {
        lookup[equations[i][1]].emplace(equations[i][0], 1 / values[i]);
      }
    }
    vector<double> result;
    for (int i = 0; i < queries.size(); ++i) {
      unordered_set<string> visited;
      auto temp = check(queries[i][0], queries[i][1], lookup, visited);
      if (temp.first) {
        result.emplace_back(temp.second);
      } else {
        result.emplace_back(-1);
      }
    }
    return result;
  }

 private:
  pair<bool, double> check(
      string curr, string goal,
      unordered_map<string, unordered_map<string, double>>& lookup,
      unordered_set<string>& visited) {
    if (lookup[curr].find(goal) != lookup[curr].end()) {
      return {true, lookup[curr][goal]};
    }
    for (const auto& str : lookup[curr]) {
      if (!visited.count(str.first)) {
        visited.insert(str.first);
        auto next = check(str.first, goal, lookup, visited);
        if (next.first) {
          return {true, str.second * next.second};
        }
      }
    }
    return {false, 0.0};
  }
};

class Solution {  // precision fault
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> graph;
    vector<double> ans;
    for (int i = 0; i < equations.size(); ++i) {
      graph[equations[i][0]].emplace(equations[i][1], values[i]);
      if (values[i]) {
        graph[equations[i][1]].emplace(equations[i][0], 1 / values[i]);
      }
    }
    for (int i = 0; i < queries.size(); ++i) {
      string up = queries[i][0];
      string down = queries[i][1];
      unordered_set<string> visited;
      if (!graph.count(queries[i][0]) || !graph.count(queries[i][1])) {
        ans.push_back(-1.0);
      }
      ans.push_back(check(up, down, graph, visited));
    }
    return ans;
  }

 private:
  double check(string curr, string goal,
               unordered_map<string, unordered_map<string, double>>& graph,
               unordered_set<string>& visited) {
    if (curr == goal) return 1.0;
    visited.insert(curr);
    for (const auto& pair : graph[curr]) {
      if (visited.count(pair.first)) continue;
      auto des = check(pair.first, goal, graph, visited);
      if (des > 0) return des * pair.second;
    }
    return -1.0;
  }
};

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    unordered_map<string, pair<string, double>> parents;
    for (int i = 0; i < equations.size(); ++i) {
      string up = equations[i][0];
      string down = equations[i][1];
      double k = values[i];
      if (!parents.count(up) && !parents.count(down)) {
        parents[up] = {down, k};
        parents[down] = {down, 1.0};
      } else if (!parents.count(up)) {
        parents[up] = {down, k};
      } else if (!parents.count(down)) {
        parents[down] = {up, 1.0 / k};
      } else {
        auto upP = find(up, parents);
        auto downP = find(down, parents);
        parents[upP.first] = {downP.first, k / upP.second * downP.second};
      }
    }
    vector<double> ans;
    for (int i = 0; i < queries.size(); ++i) {
      if (!parents.count(queries[i][0]) || !parents.count(queries[i][1])) {
        ans.push_back(-1.0);
        continue;
      }
      auto upP = find(queries[i][0], parents);
      auto downP = find(queries[i][1], parents);
      if (upP.first != downP.first) {
        ans.push_back(-1.0);
      } else {
        ans.push_back(upP.second / downP.second);
      }
    }
    return ans;
  }

 private:
  pair<string, double> find(
      string str, unordered_map<string, pair<string, double>>& parents) {
    if (str != parents[str].first) {
      auto p = find(parents[str].first, parents);
      parents[str].first = p.first;
      parents[str].second *= p.second;
    }
    return parents[str];
  }
};