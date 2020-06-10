class Solution {
 public:
  string rearrangeString(string s, int k) {
    if (k == 0) return s;
    int length = s.length();
    string res;
    unordered_map<char, int> dict;
    priority_queue<pair<int, char>> pq;
    for (char ch : s) dict[ch]++;
    for (auto it = dict.begin(); it != dict.end(); ++it)
      pq.push(make_pair(it->second, it->first));
    while (!pq.empty()) {
      vector<pair<int, char>> cache;
      int count = min(k, length);
      for (int i = 0; i < count; ++i) {
        if (pq.empty()) return "";
        auto tmp = pq.top();
        pq.pop();
        res.push_back(tmp.second);
        if (--tmp.first > 0) cache.push_back(tmp);
        length--;
      }
      for (auto p : cache) pq.push(p);
    }
    return res;
  }
};