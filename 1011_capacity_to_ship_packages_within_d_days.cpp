class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int D) {
    int right = accumulate(begin(weights), end(weights), 0);
    int left = max(right / D, *max_element(begin(weights), end(weights)));
    while (left < right) {
      auto mid = (left + right) / 2;
      if (count(mid, weights) <= D)
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
  int count(int mid, vector<int>& weights) {
    int curr = 0, cnt = 1;
    for (int ws : weights) {
      curr += ws;
      if (curr > mid) {
        ++cnt;
        curr = ws;
      }
    }
    return cnt;
  }
};