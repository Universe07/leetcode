class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    dfs(s, 4, 0, "", ans);
    return ans;
  }
  void dfs(const string& s, int step, int pos, string path,
           vector<string>& ans) {
    if (pos == s.length() && step == 0) {
      path.pop_back();
      ans.push_back(path);
      return;
    }
    if (s.size() - pos < step || s.size() - pos > step * 3) return;

    int num = 0;
    for (int i = pos; i < pos + 3; ++i) {
      num = num * 10 + s[i] - '0';
      if (num > 255) break;
      path += s[i];
      dfs(s, step - 1, i + 1, path + '.', ans);
      if (num == 0) break;
    }
  }
};