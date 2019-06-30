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