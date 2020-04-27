class Solution {
 public:
  int characterReplacement(string s, int k) {
    int len = s.length();
    vector<int> count(26);
    int start = 0, maxCnt = 0, maxLen = 0;
    for (int end = 0; end < len; ++end) {
      maxCnt = max(maxCnt, ++count[s[end] - 'A']);
      while (end - start + 1 - maxCnt > k) {
        --count[s[start] - 'A'];
        ++start;
      }
      maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
  }
};