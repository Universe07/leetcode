// Time: O(n)
// Space: O(1)
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    map<string, int> lookup;
    vector<string> res;
    for (int i = 0; i < s.length(); ++i) {
      string word = s.substr(i, 10);
      if (lookup.find(word) != lookup.end()) {
        lookup[word]++;
      } else {
        lookup[word] = 1;
      }
    }
    for (auto it = lookup.begin(); it != lookup.end(); ++it) {
      if (it->second > 1) {
        res.push_back(it->first);
      }
    }
    return res;
  }
};
