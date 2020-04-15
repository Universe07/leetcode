class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> count;
    int res = 0;
    for (auto num : deck) ++count[num];
    for (auto d : count) res = __gcd(d.second, res);
    return res > 1;
  }
};