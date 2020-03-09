// Time: O(n)
// Space:O(1)

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

// Time: O(n)-O(n^2)
// Space:(n)

class Solution {
 public:
  int scoreOfParentheses(string S) {
    return scoreCounter(S, 0, S.length() - 1);
  }
  int scoreCounter(const string& S, int left, int right) {
    if (right - left == 1) return 1;
    int b = 0;
    for (int i = left; i < right; ++i) {
      if (S[i] == '(') ++b;
      if (S[i] == ')') --b;
      if (b == 0)
        return scoreCounter(S, left, i) + scoreCounter(S, i + 1, right);
    }
    return 2 * scoreCounter(S, left + 1, right - 1);
  }
};