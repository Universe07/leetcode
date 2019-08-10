class Solution {
 public:
  int mySqrt(int x) {
    long left = 1, right = static_cast<long>(x) + 1;
    while (left < right) {
      long mid = left + (right - left) / 2;
      if (mid * mid == x) return mid;
      if (mid * mid > x) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left - 1;
  }
};