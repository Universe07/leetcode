class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    const int n = s.length();
    size_t max_len = 0;
    for (const auto& word : wordDict) {
      max_len = max(max_len, word.length());
    }
    vector<bool> canBreak(n + 1, false);
    canBreak[0] = true;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= max_len && i - j >= 0; ++j) {
        if (canBreak[i - j]) {
          string word = s.substr(i - j, j);
          if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
            canBreak[i] = true;
            break;
          }
        }
      }
    }
    return canBreak[n];
  }
};