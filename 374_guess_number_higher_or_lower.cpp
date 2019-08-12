// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution {
 public:
  int guessNumber(int n) {
    long start = 1, end = static_cast<long>(n) + 1;
    while (start < end) {
      int mid = start + (end - start) / 2;
      if (!guess(mid)) {
        return mid;
      } else if (guess(mid) == -1) {
        end = mid;
      } else if (guess(mid) == 1) {
        start = mid + 1;
      }
    }
    return -1;
  }
};
