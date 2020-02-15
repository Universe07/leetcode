// Time: O(n)
// Space: O(1)

class Solution {
 public:
  bool equationsPossible(vector<string>& equations) {
    iota(begin(parents), end(parents), 0);
    for (const auto& eq : equations) {
      if (eq[1] == '=') {
        parents[find(eq[0])] = parents[find(eq[3])];
      }
    }
    for (const auto& eq : equations) {
      if (eq[1] == '!' && find(eq[0]) == find(eq[3])) {
        return false;
      }
    }
    return true;
  }

 private:
  array<int, 128> parents;
  int find(int x) {
    if (x != parents[x]) {
      parents[x] = find(parents[x]);
    }
    return parents[x];
  }
};