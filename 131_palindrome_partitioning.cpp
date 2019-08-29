class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    dfs(s, 0, path, ans);
    return ans;
  }

 private:
  void dfs(const string& s, int pos, vector<string>& path,
           vector<vector<string>>& ans) {
    if (pos == s.size()) {
      ans.push_back(path);
      return;
    }
    for (int i = pos; i < s.size(); ++i) {
      string palin = s.substr(pos, i - pos + 1);
      if (isPalin(palin)) {
        path.push_back(palin);
        dfs(s, i + 1, path, ans);
        path.pop_back();
      }
    }
  }
  bool isPalin(string s) {
    if (s.size() == 0) return false;
    int i = 0, j = s.length() - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
};