class Solution {
 public:
  vector<int> s;
  Solution(vector<int>& w) {
    for (auto n : w) s.push_back((s.empty() ? 0 : s.back()) + n);
  }

  int pickIndex() {
    return upper_bound(begin(s), end(s), rand() % s.back()) - begin(s);
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */