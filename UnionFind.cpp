class UnionFindSet {
 public:
  UnionFindSet(int n) {
    ranks = vector<int>(n + 1, 0);
    parents = vector<int>(n + 1, 0);

    for (int i = 0; i <= n; ++i) {
      parents[i] = i;
    }
  }

  int find(int u) {
    if (u != parents[u]) {
      parents[u] = find(parents[u]);
    }
    return parents[u];
  }

  // merge two sets
  // return true if merge successfully
  // return false if two sets are already in a tree
  bool union(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return false;

    if (ranks_[pv] < ranks_[pu]) {
      parents_[pv] = parents[pu];
    } else if (ranks_[pu] < ranks_[pv]) {
      parents_[pu] = parents[pv];
    } else {
      parents_[pv] = pu;
      ranks_[pv] += 1;
    }
    return true;
  }

 private:
  vector<int> ranks_;
  vector<int> parents_;
};