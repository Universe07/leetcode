// Time: O(mn)
// Space: O(1)

class Solution {
 public:
  int shortestWay(string source, string target) {
    auto i = 0, j = 0, res = 0;
    while (i < target.size() && res <= i) {
      while (target[i] != source[j] && j < source.size()) ++j;
      if (j == source.size())
        j = 0, ++res;
      else
        ++i, ++j;
    }
    return res <= i ? res + 1 : -1;
  }
};

// Time: O(nlogm)
// Space: O(1)

class Solution {
 public:
  int shortestWay(string source, string target) {
    int res = 0;
    vector<int> ch_ids[26] = {};
    for (auto j = 0; j < source.size(); ++j)
      ch_ids[source[j] - 'a'].push_back(j);
    for (auto i = 0, j = -1; i < target.size();) {
      auto& ids = ch_ids[target[i] - 'a'];
      if (ids.empty()) return -1;
      auto it = upper_bound(begin(ids), end(ids), j);
      if (it == end(ids))
        ++res, j = -1;
      else
        ++i, j = *it;
    }
    return res + 1;
  }
};