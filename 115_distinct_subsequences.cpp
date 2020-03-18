// Time: O(ls * lt)
// Space: O(ls * lt)

class Solution {
 public:
  int numDistinct(string s, string t) {
    int ls = s.length();
    int lt = t.length();
    vector<vector<long>> dp(lt + 1, vector<long>(ls + 1));
    fill(begin(dp[0]), end(dp[0]), 1);
    for (int i = 1; i <= lt; ++i) {
      for (int j = 1; j <= ls; ++j) {
        dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
      }
    }
    return dp[lt][ls];
  }
};

// Time: O(ls * lt)
// Space: O(lt)
class Solution {
 public:
  int numDistinct(string s, string t) {
    int ls = s.length();
    int lt = t.length();
    vector<long> dp(lt + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= ls; ++i) {
      for (int j = lt; j >= 1; --j) {
        dp[j] += (s[i - 1] == t[j - 1] ? dp[j - 1] : 0);
      }
    }
    return dp[lt];
  }
};