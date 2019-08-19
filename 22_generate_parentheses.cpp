class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    generate("", ans, n, 0, 0);
    return ans;
  }
  void generate(string item, vector<string>& ans, int n, int l, int r) {
    if (l == n) {
      item.append(n - r, ')');
      ans.push_back(item);
      return;
    }
    generate(item + '(', ans, n, l + 1, r);
    if (l > r) generate(item + ')', ans, n, l, r + 1);
  }
};

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string cur;
    dfs(n, n, cur, ans);
    return ans;
  }
  void dfs(int left, int right, string& cur, vector<string>& ans) {
    if (left + right == 0) {
      ans.push_back(cur);
      return;
    }
    if (r < l) return;
    if (l > 0) {
      dfs(left - 1, right, cur += '(', ans);
      cur.pop_back();
    }
    if (r > 0) {
      dfs(left, right - 1, cur += ')', ans);
      cur.pop_back();
    }
  }
};