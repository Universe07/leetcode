class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& c) {
    vector<pair<int, int>> ve;
    for (auto i : c) ve.push_back({i[1], i[0]});
    sort(ve.begin(), ve.end());
    int d = 0, cnt = 0;
    priority_queue<int> q;
    for (auto i : ve) {
      if (i.first < i.second) continue;
      if (d + i.second <= i.first) {
        q.push(i.second);
        d += i.second;
        ++cnt;
      } else {
        if (d + i.second - q.top() < d) {
          d = d + i.second - q.top();
          q.pop();
          q.push(i.second);
        }
      }
    }
    return cnt;
  }
};