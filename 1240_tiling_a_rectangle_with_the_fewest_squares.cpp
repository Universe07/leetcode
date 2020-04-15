class Solution {
 public:
  int tilingRectangle(int n, int m) {
    if (n > m) swap(n, m);
    vector<int> S;
    for (int i = 0; i < n; ++i) S.push_back(m);
    maxDepth = max(n, m);
    dfs(S, 0);
    return maxDepth;
  }
  int maxDepth;
  typedef long long Key;
  unordered_map<Key, int> dp;
  Key hash(vector<int>& vec) {
    Key r = 0;
    for (int n : vec) r = (r << 4LL) + n;
    return r;
  }
  void dfs(vector<int>& vec, int dfsDepth) {
    Key h = hash(vec);
    if (h == 0) {
      maxDepth = min(maxDepth, dfsDepth);
      return;
    }
    if (dfsDepth >= maxDepth or dp.count(h)) return;
    auto topleft = max_element(vec.begin(), vec.end());
    int width = 1;
    for (auto top = topleft + 1; top != vec.end() and *top == *topleft; top++)
      width++;
    for (int w = min(width, *topleft); w > 0; w--) {
      for (int i = 0; i < w; ++i) *(topleft + i) -= w;
      dfs(vec, dfsDepth + 1);
      for (int i = 0; i < w; ++i) *(topleft + i) += w;
    }
  }
};