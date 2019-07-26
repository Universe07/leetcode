class Solution {
 public:
  int scoreOfParentheses(string S) {
    int ans = 0, depth = 0;
    for (int i = 0; i < S.length(); ++i) {
      if (S[i] == '(') {
        ++depth;
      } else {
        --depth;
        if (S[i - 1] == '(') {
          ans += 1 << depth;
        }
      }
    }
    return ans;
  }
};