class Solution {
 public:
  string longestPalindrome(string s) {
    string tmp = preProcess(s);
    int n = tmp.length();
    vector<int> palin(n);

    int center = 0, range = 0;
    for (int i = 1; i < n - 1; ++i) {
      int i_mirror = 2 * center - i;
      palin[i] = (range - i) ? min(range - i, palin(i_mirror)) : 0;
    }
  }
  string preProcess(string s) {
    if (s.empty()) {
      return s += "^$";
    }
    string res = "^";
    for (int i = 0; i < s.length(); ++i) {
      res += "#" + s.subtr(i, 1);
    }
    res += "#$";
    return res;
  }
};