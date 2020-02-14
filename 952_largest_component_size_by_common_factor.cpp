// Time: O(n * sqrt(W))
// Space: O(W)

class DSU {
 private:
  vector<int> p;

 public:
  DSU(int n) : p(n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }
  void Union(int x, int y) { p[find(x)] = p[find(y)]; }
  int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  }
};

class Solution {
 public:
  int largestComponentSize(vector<int>& A) {
    int n = *max_element(begin(A), end(A));
    DSU dsu(n + 1);
    for (int a : A) {
      int t = sqrt(a);
      for (int k = 2; k <= t; ++k) {
        if (a % k == 0) {
          dsu.Union(a, k);
          dsu.Union(a, a / k);
        }
      }
    }
    unordered_map<int, int> c;
    int ans = 1;
    for (int a : A) {
      ans = max(ans, ++c[dsu.find(a)]);
    }
    return ans;
  }
};
