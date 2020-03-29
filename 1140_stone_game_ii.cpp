// Solution: Recursion + Memoization
// def solve(s, m) = max diff score between two players starting from s for the
// given M.
// cache[s][M] = max{sum(piles[s:s+x]) – solve(s+x, max(x, M)}, 1 <= x <= 2*M, s
// + x <= n
// Time complexity: O(n^3)
// Space complexity: O(n^2)

class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    const int n = piles.size();
    unordered_map<int, int> cache;
    function<int(int, int)> solve = [&](int s, int M) {
      if (s >= n) return 0;
      const int key = (s << 8) | M;
      if (cache.count(key)) return cache[key];
      int best = INT_MIN;
      int curr = 0;
      for (int x = 1; x <= 2 * M; ++x) {
        if (s + x > n) break;
        curr += piles[s + x - 1];
        best = max(best, curr - solve(s + x, max(x, M)));
      }
      return cache[key] = best;
    };
    int total = accumulate(begin(piles), end(piles), 0);
    return (total + solve(0, 1)) / 2;
  }
};