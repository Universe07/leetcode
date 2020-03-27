// Time: O(n^3)
// Space : O(n^2)

class Solution {
 public:
  int strangePrinter(string s) {
    int l = s.length();
    t_ = vector<vector<int>>(l, vector<int>(l, 0));
    return turn(s, 0, l - 1);
  }

 private:
  vector<vector<int>> t_;
  int turn(const string& s, int i, int j) {
    if (i > j) return 0;
    if (t_[i][j] > 0) return t_[i][j];
    int ans = turn(s, i, j - 1) + 1;
    for (int k = i; k < j; ++k) {
      if (s[k] == s[j]) {
        ans = min(ans, turn(s, i, k) + turn(s, k + 1, j - 1));
      }
    }
    return t_[i][j] = ans;
  }
};