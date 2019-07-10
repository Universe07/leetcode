class Solution {
 public:
  int reverse(int x) {
    long long result = 0;
    while (x) {
      auto prev = result;
      result *= 10;
      result += x % 10;
      if (result / 10 != prev) {
        break;
      }
      x /= 10;
    }
    return result > INT_MAX || result < INT_MIN ? 0 : result;
  }
};