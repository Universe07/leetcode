class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> map;
    int start = 0, end = 0, counter = 0, len = 0;
    while (end < s.size()) {
      if (map[s[end++]]++ == 0) counter++;
      while (counter > k) {
        if (map[s[start++]]-- == 1) counter--;
      }
      len = max(len, end - start);
    }
    return len;
  }
};