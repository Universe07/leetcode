// Time: O(n)
// Space: O(n)

class Solution {
 public:
  int minFlipsMonoIncr(string S) {
    const int n = S.length();
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    l[0] = S[0] - '0';
    r[n - 1] = '1' - S[n - 1];
    for (int i = 1; i < n; ++i) l[i] = l[i - 1] + (S[i] - '0');
    for (int i = n - 2; i >= 0; --i) r[i] = r[i + 1] + ('1' - S[i]);
    int ans = r[0];
    for (int i = 1; i <= n; ++i) {
      ans = min(ans, l[i - 1] + r[i]);
    }
    return ans;
  }
};