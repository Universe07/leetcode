class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    const int l1 = s1.length(), l2 = s2.length();
    if (l1 > l2) return false;
    vector<int> c1(26), c2(26);
    for (const char& c : s1) ++c1[c - 'a'];
    for (int i = 0; i < l2; ++i) {
      ++c2[s2[i] - 'a'];
      if (i >= l1) --c2[s2[i - l1] - 'a'];
      if (c1 == c2) return true;
    }
    return false;
  }
};