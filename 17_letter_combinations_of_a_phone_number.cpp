class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string path = "";
    dfs(digits, 0, path, ans);
    return ans;
  }

 private:
  const vector<string> keyboard{" ",   "",    "abc",  "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};
  void dfs(string digits, int cur, string& path, vector<string>& ans) {
    if (digits == "") {
      return;
    }
    if (cur == digits.size()) {
      ans.push_back(path);
      return;
    }
    for (const auto& c : keyboard[digits[cur] - '0']) {
      path += c;
      dfs(digits, cur + 1, path, ans);
      path.pop_back();
    }
  }
};