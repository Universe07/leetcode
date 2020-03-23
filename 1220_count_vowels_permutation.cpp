// DP solution
// Time:O(n)
// Space:O(n) -> O(1)

class Solution {
 public:
  int countVowelPermutation(int n) {
    constexpr int kMod = 1e9 + 7;
    vector<vector<long>> dp(n + 1, vector<long>(5));
    fill(begin(dp[1]), end(dp[1]), 1);
    // 0: a, 1: e, 2: i, 3: o, 4: u
    for (int i = 2; i <= n; ++i) {
      dp[i][1] += dp[i - 1][0];  // a -> e
      dp[i][0] += dp[i - 1][1];  // e -> a;
      dp[i][2] += dp[i - 1][1];  // e -> i;
      for (int j = 0; j < 5; ++j) {
        if (j == 2) continue;
        dp[i][j] += dp[i - 1][2];
      }
      dp[i][2] += dp[i - 1][3];  // o -> e
      dp[i][4] += dp[i - 1][3];  // o -> u
      dp[i][0] += dp[i - 1][4];  // u -> a
      for (int j = 0; j < 5; ++j) {
        dp[i][j] %= kMod;
      }
    }
    return accumulate(begin(dp[n]), end(dp[n]), 0L) % kMod;
  }
};

class Solution {
 public:
  int countVowelPermutation(int n) {
    constexpr int kMod = 1e9 + 7;
    long a = 1, e = 1, i = 1, o = 1, u = 1;
    for (int k = 2; k <= n; ++k) {
      long aa = (i + e + u) % kMod;
      long ee = (i + a) % kMod;
      long ii = (e + o) % kMod;
      long oo = i % kMod;
      long uu = (i + o) % kMod;
      a = aa;
      e = ee;
      i = ii;
      o = oo;
      u = uu;
    }
    return (a + e + i + o + u) % kMod;
  }
};

// Matrix Manipulation aka. DFS
// Time: O(logn)
// Space: O(1)
static vector<vector<int>> relations = {{1, 2, 4}, {0, 2}, {1, 3}, {2}, {2, 3}};
class Solution {
 public:
  int countVowelPermutation(int n) {
    int kMod = 1e9 + 7;
    vector<long long> vowels(5, 1), vowels_copy;
    long long result = 0;
    while (--n) {
      vowels_copy = vowels;
      for (int i = 0; i < 5; ++i) {
        vowels[i] = 0;
        for (int& r : relations[i]) {
          vowels[i] += vowels_copy[r], vowels[i] %= kMod;
        }
      }
    }
    for (long long& i : vowels) {
      result += i, result %= kMod;
    }
    return result;
  }
};
