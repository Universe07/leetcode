// Time: O(4^n) 4 is the maximum length of the one possiple input. n is the
// length of the input.
// Space : O(4 ^ n + n)
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

class Solution {
 public:
  const vector<string> keyboard{" ",   "",    "abc",  "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans{""};
    for (const auto& digit : digits) {
      vector<string> tmp;
      for (const string& str : ans) {
        for (char c : keyboard[digit - '0']) {
          tmp.push_back(str + c);
        }
      }
      ans.swap(tmp);
    }
    return ans;
  }
};