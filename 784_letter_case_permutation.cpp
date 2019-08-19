class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans;
    dfs(S, 0, ans);
    return ans;
  }
  void dfs(string& S, int pos, vector<string>& ans) {
    if (pos == S.length()) {
      ans.push_back(S);
      return;
    }
    dfs(S, pos + 1, ans);
    if (!isdigit(S[pos])) {
      S[pos] ^= (1 << 5);
      dfs(S, pos + 1, ans);
      S[pos] ^= (1 << 5);
    }
  }
};