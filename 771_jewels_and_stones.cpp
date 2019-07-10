class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    unordered_set<char> lookup;
    for (const auto& c : J) {
      lookup.insert(c);
    }
    int result = 0;
    for (const auto& c : S) {
      result += lookup.count(c);
    }
    return result;
  }
};