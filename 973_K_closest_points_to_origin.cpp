class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    static const auto& dist = [](const vector<int>& v) {
      return v[0] * v[0] + v[1] * v[1];
    };

    struct Compare {
      bool operator()(const vector<int>& a, const vector<int>& b) {
        return dist(a) < dist(b);
      }
    };

    priority_queue<vector<int>, vector<vector<int>>, Compare> max_heap;
    for (int i = 0; i < points.size(); ++i) {
      max_heap.emplace(points[i]);
      if (max_heap.size() > K) {
        max_heap.pop();
      }
    }
    vector<vector<int>> result;
    while (!max_heap.empty()) {
      result.push_back(max_heap.top());
      max_heap.pop();
    }
    return result;
  }
};