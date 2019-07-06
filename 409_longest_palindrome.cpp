class Solution {
 public:
  int longestPalindrome(string s) {
    map<char, int> lookup;
    int max_length = 0;
    int flag = 0;
    for (int i = 0; i < s.length(); ++i) {
      ++lookup[s[i]];
    }
    for (auto it = lookup.begin(); it != lookup.end(); ++it) {
      if (it->second % 2 == 0) {
        max_length += it->second;
      } else {
        max_length += it->second - 1;
        flag = 1;
      }
    }
    return max_length + flag;
  }
};