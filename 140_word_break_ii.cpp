class Solution {
 public:
  unordered_map<string, vector<string>> m;
  vector<string> combine(string word, vector<string> prev) {
    for (int i = 0; i < prev.size(); ++i) prev[i] += " " + word;
    return prev;
  }
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    if (m.count(s)) return m[s];
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<string> result;
    if (dict.count(s)) result.push_back(s);
    for (int i = 1; i < s.size(); ++i) {
      string word = s.substr(i);
      if (dict.count(word)) {
        string rem = s.substr(0, i);
        vector<string> prev = combine(word, wordBreak(rem, wordDict));
        result.insert(result.end(), prev.begin(), prev.end());
      }
    }
    m[s] = result;
    return result;
  }
};