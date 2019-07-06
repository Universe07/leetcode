class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    size_t res = 0;
    size_t begin = 0;
    unordered_map<char, int> last_occur;
    for (int i = 0; i < s.length(); ++i) {
      if (last_occur.find(s[i]) != last_occur.end()) {
        if (last_occur[s[i]] >= begin) {
          res = max(i - begin, res);
          begin = last_occur[s[i]] + 1;
        }
      }
      last_occur[s[i]] = i;
    }
    res = max(res, s.size() - begin);
    return res;
  }
};