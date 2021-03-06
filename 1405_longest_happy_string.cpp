class Solution {
 public:
  string longestDiverseString(int a, int b, int c, char aa = 'a', char bb = 'b',
                              char cc = 'c') {
    if (a < b) return longestDiverseString(b, a, c, bb, aa, cc);
    if (a < c) return longestDiverseString(c, b, a, cc, bb, aa);
    if (b < c) return longestDiverseString(a, c, b, aa, cc, bb);
    if (b == 0) return string(min(2, a), aa);
    auto use_b = a - min(2, a) >= b ? 1 : 0;
    return string(min(2, a), aa) + string(use_b, bb) +
           longestDiverseString(a - min(2, a), b - use_b, c, aa, bb, cc);
  }
};