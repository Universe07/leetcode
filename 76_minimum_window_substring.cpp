class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.empty() || s.size() < t.size()) {
      return "";
    }

    const int ASCII_MAX = 256;
    vector<int> exp_cnt(ASCII_MAX, 0);
    vector<int> cur_cnt(ASCII_MAX, 0);

    int begin = 0;
    int min_start = 0;
    int min_width = numeric_limits<int>::max();
    int cnt = 0;

    for (const auto& c : t) {
      ++exp_cnt[c];
    }
    for (int i = 0; i < s.length(); ++i) {
      if (exp_cnt[s[i]] > 0) {
        ++cur_cnt[s[i]];
        if (cur_cnt[s[i]] <= exp_cnt[s[i]]) {
          ++cnt;
        }
      }
      if (cnt == t.size()) {
        while (exp_cnt[s[begin]] == 0 ||
               cur_cnt[s[begin]] > exp_cnt[s[begin]]) {
          --cur_cnt[s[begin]];
          ++begin;
        }
        if (min_width > i - begin + 1) {
          min_width = i - begin + 1;
          min_start = begin;
        }
      }
    }
    if (min_width == numeric_limits<int>::max()) {
      return "";
    }
    return s.substr(min_start, min_width);
  }
};