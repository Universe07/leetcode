// Time: O(nlogn)
// Space: O(1)

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) {
      return 0;
    }
    sort(points.begin(), points.end());
    int ans = 1;
    int short_begin = points[0][0], short_end = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] <= short_end) {
        short_begin = points[i][0];
        short_end = min(short_end, points[i][1]);
      } else {
        ++ans;
        short_begin = points[i][0];
        short_end = points[i][1];
      }
    }
    return ans;
  }
};