// Time: O(Nlog1e9)
// Space: O(1)

class Solution {
 public:
  int maximizeSweetness(vector<int>& sweetness, int K) {
    int left = 1, right = (int)1e9 / (K + 1);
    while (left < right) {
      int mid = (left + right + 1) / 2;
      int cur = 0, cuts = 0;
      for (int sweet : sweetness) {
        if ((cur += sweet) >= mid) {
          cur = 0;
          if (++cuts > K) break;
        }
      }
      if (cuts > K)
        left = mid;
      else
        right = mid - 1;
    }
    return left;
  }
};