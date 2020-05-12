class Solution {
 public:
  int numWays(int n, int k) {
    if (n == 0)
      return 0;
    else if (n == 1)
      return k;
    int diffC = k * (k - 1);
    int sameC = k;
    for (int i = 2; i < n; ++i) {
      int tmp = diffC;
      diffC = (diffC + sameC) * (k - 1);
      sameC = tmp;
    }
    return diffC + sameC;
  }
};