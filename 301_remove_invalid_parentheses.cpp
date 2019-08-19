class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    int l = 0;
    int r = 0;
    for (const char ch : s) {
      l += (ch == '(');
      if (l == 0) {
        r += (ch == ')');
      } else {
        l -= (ch == ')');
      }
    }
    vector<string> ans;
    dfs(s, 0, l, r, ans);
    return ans;
  }

 private:
  bool isValid(string s) {
    int count = 0;
    for (const char ch : s) {
      if (ch == '(') ++count;
      if (ch == ')') --count;
      if (count < 0) return false;
    }
    return count == 0;
  }
  void dfs(const string& s, int pos, int l, int r, vector<string>& ans) {
    if (l == 0 && r == 0) {
      if (isValid(s)) {
        ans.push_back(s);
        return;
      }
    }
    for (int i = pos; i < s.length(); ++i) {
      if (i != pos && s[i - 1] == s[i]) continue;
      if (s[i] == '(' || s[i] == ')') {
        string curr = s;
        curr.erase(i, 1);
        if (s[i] == ')') {
          dfs(curr, i, l, r - 1, ans);
        } else if (l > 0 && s[i] == '(') {
          dfs(curr, i, l - 1, r, ans);
        }
      }
    }
  }
};
