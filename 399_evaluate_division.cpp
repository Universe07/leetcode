class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> lookup;
    for (int i = 0; i < equations.size(); ++i) {
      lookup[equations[i][0]].emplace(equations[i][1], values[i]);
      if (values[i] != 0) {
        lookup[equations[i][1]].emplace(equations[i][0], 1 / values[i]);
      }
    }

    vector<double> result;
    for (int i = 0; i < queries.size(); ++i) {
      unordered_set<string> visited;
      auto tmp = check(queries[i][0], queries[i][1], lookup, visited);
      if (tmp.first) {
        result.emplace_back(tmp.second);
      } else {
        result.emplace_back(-1);
      }
    }
    return result;
  }
  pair<bool, double> check(
      string up, string down,
      unordered_map<string, unordered_map<string, double>>& lookup,
      unordered_set<string>& visited) {
    if (lookup[up].find(down) != lookup[up].end()) {
      return {true, lookup[up][down]};
    }
    for (const auto& q : lookup[up]) {
      if (!visited.count(q.first)) {
        visited.insert(q.first);
        auto it = check(q.first, down, lookup, visited);
        if (it.first) {
          return {true, it.second * q.second};
        }
      }
    }
    return {false, 0.0};
  }
};