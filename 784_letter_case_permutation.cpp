class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans{""};
    for (const auto& c : S) {
      if (isalpha(c)) {
        const auto& size = ans.size();
        for (int i = 0; i < ans.size(); ++i) {
          ans.emplace_back(ans[i]);
          ans[i] += tolower[c];
          ans.back() += toupper(c);
        }
      } else {
        for (const auto& s : ans) {
          s += c;
        }
      }
    }
    return result;
  }
};