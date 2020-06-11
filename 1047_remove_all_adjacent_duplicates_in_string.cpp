class Solution {
 public:
  string removeDuplicates(string S) {
    int i = 0, n = S.length();
    for (int j = 0; j < n; ++i, ++j) {
      S[i] = S[j];
      if (i > 0 && S[i - 1] == S[i]) i -= 2;
    }
    return S.substr(0, i);
  }
};