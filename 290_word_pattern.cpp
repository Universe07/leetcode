class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    str.push_back(' ');
    map<string, char> lookup;
    set<char> used;
    int k = 0;
    for (int i = 0; i < str.length();) {
      int j = str.find(' ', i);
      string word = str.substr(i, j - i);
      if (lookup.find(word) == lookup.end()) {
        if (used.find(pattern[k]) != used.end()) {
          return false;
        }
        lookup[word] = pattern[k];
        used.insert(pattern[k]);
      } else {
        if (lookup[word] != pattern[k]) {
          return false;
        }
      }
      i = j + 1;
      ++k;
    }
    if (k != pattern.length()) {
      return false;
    }
    return true;
  }
};