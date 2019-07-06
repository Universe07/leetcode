class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> groups;
    for (const auto& str : strs) {
      string tmp{str};
      sort(tmp.begin(), tmp.end());
      groups[tmp].emplace_back(str);
    }
    for (const auto& kvp : groups) {
      vector<string> group;
      for (const auto& str : kvp.second) {
        group.emplace_back(str);
      }
      ans.emplace_back(group);
    }
    return ans;
  }
};