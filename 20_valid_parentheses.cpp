class Solution {
 public:
  bool isValid(string s) {
    unordered_map<char, char> lookup{{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> valid;
    for (const auto& c : s) {
      auto it = lookup.find(c);
      if (it != lookup.end()) {
        if (valid.empty() || it->second != valid.top()) {
          return false;
        } else {
          valid.pop();
        }
      } else {
        valid.emplace(c);
      }
    }
    return valid.empty();
  }
};