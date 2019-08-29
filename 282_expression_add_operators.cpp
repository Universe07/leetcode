class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    dfs(num, target, 0, "", 0, 0, &ans);
    return ans;
  }
  void dfs(const string& num, int target, int pos, string temp, int prev,
           int curr, vector<string>* ans) {
    if (pos == num.size()) {
      if (curr == target) {
        ans->push_back(temp);
        return;
      }
    }
    for (int len = 1; len <= num.size() - pos; ++len) {
      string expr = num.substr(pos, len);
      if (expr[0] == '0' && expr.size() > 1) break;
      long n = stol(expr);
      if (n > INT_MAX) break;
      if (pos == 0) {
        dfs(num, target, len, expr, n, n, ans);
        continue;
      }
      dfs(num, target, pos + len, temp + '+' + expr, n, curr + n, ans);
      dfs(num, target, pos + len, temp + '-' + expr, -n, curr - n, ans);
      dfs(num, target, pos + len, temp + '*' + expr, prev * n,
          curr - prev + prev * n, ans);
    }
  }
};