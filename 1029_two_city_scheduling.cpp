class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int res = 0;
    nth_element(begin(costs), begin(costs) + costs.size() / 2, end(costs),
                [](vector<int>& a, vector<int>& b) {
                  return (a[0] - a[1] < b[0] - b[1]);
                });
    for (auto i = 0; i < costs.size() / 2; ++i) {
      res += costs[i][0] + costs[i + costs.size() / 2][1];
    }
    return res;
  }
};