// Time: O(n)
// Space: O(n)

class Solution {
 public:
  string removeKdigits(string num, int k) {
    string res;
    for (const auto& c : num) {
      while (!res.empty() && res.back() > c && k > 0) {
        res.pop_back();
        --k;
      }
      res.push_back(c);
    }
    res.resize(res.size() - k);  // "9" k = 1
    auto it = res.find_first_not_of('0');
    if (it == string::npos || res == "0") {
      return "0";
    } else {
      return res.substr(it);
    }
  }
};