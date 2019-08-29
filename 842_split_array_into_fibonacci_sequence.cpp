class Solution {
 public:
  vector<int> splitIntoFibonacci(string S) {
    vector<int> ans;
    dfs(S, 0, ans);
    return ans;
  }

 private:
  bool dfs(const string& S, int pos, vector<int>& ans) {
    if (pos == S.size() && ans.size() >= 3) {
      return true;
    }
    for (int len = 1; len + pos <= S.size(); ++len) {
      if (S[pos] == '0' && len > 1) break;
      long long figure = stoll(S.substr(pos, len));
      if (figure > INT_MAX) break;
      if (ans.size() > 2 && figure - ans[ans.size() - 1] > ans[ans.size() - 2])
        return false;
      if (ans.size() <= 1 ||
          figure - ans[ans.size() - 1] == ans[ans.size() - 2]) {
        ans.push_back(int(figure));
        if (dfs(S, pos + len, ans)) return true;
        ans.pop_back();
      }
    }
    return false;
  }
};