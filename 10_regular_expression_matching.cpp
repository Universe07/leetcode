class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (p[j - 1] == '*')
          dp[i][j] = dp[i][j - 2] ||
                     (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') &&
                      dp[i - 1][j]);
        else
          dp[i][j] = i > 0 && dp[i - 1][j - 1] &&
                     (s[i - 1] == p[j - 1] || p[j - 1] == '.');
    return dp[m][n];
  }
};

class Solution {
 public:
  bool isMatch(string s, string p) { return isMatch(s.c_str(), p.c_str()); }

 private:
  bool isMatch(const char* s, const char* p) {
    if (*p == '\0') return *s == '\0';
    if (p[1] != '*' || p[1] == '\0') {
      if (*s == '\0') return false;
      if (*s == *p || *p == '.')
        return isMatch(s + 1, p + 1);
      else
        return false;
    } else {
      int i = -1;
      while (i == -1 || s[i] == p[0] || p[0] == '.') {
        if (isMatch(s + i + 1, p + 2)) return true;
        if (s[++i] == '\0') break;
      }
      return false;
    }
    return false;
  }
};