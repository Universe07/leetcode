class DSU {
 public:
  DSU(int size) : size_(size), parents_(size), ranks_(size) {
    iota(begin(parents_), end(parents_), 0);
  }

  int Find(int x, vector<int>& parents) {
    while (x != parents_[x]) {
      parents[x] = parents_[parents_[x]];
      x = parents_[x];
    }
    return x;
  }

  void Union(int x, int y) {
    int px = Find(x, parents_);
    int py = Find(y, parents_);
    if (px == py) return;
    if (ranks_[px] < ranks_[py])
      swap(px, py);
    else if (ranks_[px] == ranks_[py])
      ranks_[px]++;
    parents_[py] = px;
    --size_;
  }

  int getSize() const { return size_; }

 private:
  int size_;
  vector<int> parents_;
  vector<int> ranks_;
};

class Solution {
 public:
  int numSimilarGroups(vector<string>& A) {
    DSU dsu(A.size());
    for (int i = 0; i < A.size(); ++i) {
      for (int j = i + 1; j < A.size(); ++j) {
        if (similar(A[i], A[j])) {
          dsu.Union(i, j);
        }
      }
    }
    return dsu.getSize();
  }

 private:
  bool similar(string a, string b) {
    int diff = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i] && ++diff > 2) {
        return false;
      }
    }
    return true;
  }
};

class Solution {
 public:
  int numSimilarGroups(vector<string>& A) {
    vector<int> roots(A.size(), 0);
    for (int i = 0; i < A.size(); ++i) {
      roots[i] = i;
    }
    for (int i = 0; i < A.size(); ++i) {
      for (int j = i + 1; j < A.size(); ++j) {
        int pi = find(i, roots);
        int pj = find(j, roots);
        if (pi != pj && similar(A[i], A[j])) {
          roots[pj] = pi;
        }
      }
    }
    vector<bool> visited(A.size(), false);
    int res = 0;
    for (int i = 0; i < roots.size(); ++i) {
      if (!visited[find(i, roots)]) {
        visited[find(i, roots)] = true;
        ++res;
      }
    }
    return res;
  }

 private:
  int find(int x, vector<int>& roots) {
    while (x != roots[x]) {
      roots[x] = roots[roots[x]];
      x = roots[x];
    }
    return roots[x];
  }
  bool similar(string a, string b) {
    int diff = 0;
    for (int i = 0; i < a.length(); ++i) {
      if (a[i] != b[i] && ++diff > 2) {
        return false;
      }
    }
    return true;
  }
};