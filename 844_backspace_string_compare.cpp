// Time: O(n)
// Space: O(1)
// we can do a back string compare (just like the title of problem). If we do it
// backward, we meet a char and we can be sure this char won't be deleted. If we
// meet a '#', it tell us we need to skip next lowercase char.

class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    for (int i = S.length() - 1, j = T.length() - 1;; --i, --j) {
      for (int back = 0; i >= 0 && (back || S[i] == '#'); --i) {
        back += S[i] == '#' ? 1 : -1;
      }
      for (int back = 0; j >= 0 && (back || T[j] == '#'); --j) {
        back += T[j] == '#' ? 1 : -1;
      }
      if (i < 0 || j < 0 || S[i] != T[j]) return i == -1 && j == -1;
    }
  }
};