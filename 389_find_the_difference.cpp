class Solution {
 public:
  char findTheDifference(string s, string t) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < t.length(); ++i) {
      if (i < s.length()) a += s[i] - 'a';
      b = b + t[i] - 'a';
    }
    return 'a' + (b - a);
  }
};