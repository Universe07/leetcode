// Time: O(mn)
// Space: O(n)

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<int> dp1(n + 1);
    vector<int> dp2(n + 2);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (text1[i] == text2[j])
          dp2[j + 1] = dp1[j] + 1;
        else
          dp2[j + 1] = max(dp1[j + 1], dp2[j]);
      }
      swap(dp1, dp2);
    }
    return dp1[n];
  }
};