class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int H) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (canFinish(piles, H, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

 private:
  bool canFinish(vector<int>& piles, int H, int speed) {
    int time = 0;
    for (const auto& pile : piles) {
      time += (pile - 1) / speed + 1;
    }
    return time <= H;
  }
};