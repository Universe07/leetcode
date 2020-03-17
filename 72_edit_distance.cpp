// Time: O(l1 * l2)
// Space: O(l1 * l2) -> O(min(l1, l2))

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int l1 = word1.length();
    int l2 = word2.length();
    d_ = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, -1));
    return minDistance(word1, word2, l1, l2);
  }

 private:
  vector<vector<int>> d_;
  int minDistance(const string& word1, const string& word2, int l1, int l2) {
    if (l1 == 0) return l2;
    if (l2 == 0) return l1;
    if (d_[l1][l2] >= 0) return d_[l1][l2];
    int ans;
    if (word1[l1 - 1] == word2[l2 - 1])
      ans = minDistance(word1, word2, l1 - 1, l2 - 1);
    else
      ans = min(minDistance(word1, word2, l1 - 1, l2 - 1),
                min(minDistance(word1, word2, l1 - 1, l2),
                    minDistance(word1, word2, l1, l2 - 1))) +
            1;
    return d_[l1][l2] = ans;
  }
};

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int l1 = word1.length();
    int l2 = word2.length();
    vector<vector<int>> d(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 0; i <= l1; ++i) d[i][0] = i;
    for (int j = 0; j <= l2; ++j) d[0][j] = j;
    for (int i = 1; i <= l1; ++i) {
      for (int j = 1; j <= l2; ++j) {
        int c = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
        d[i][j] = min(d[i - 1][j - 1] + c, min(d[i - 1][j], d[i][j - 1]) + 1);
      }
    }
    return d[l1][l2];
  }
};