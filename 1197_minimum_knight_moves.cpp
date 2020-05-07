class Solution {
 public:
  int minKnightMoves(int x, int y) {
    unordered_map<string, int> lookup;
    lookup.emplace("0,0", 0);
    lookup.emplace("1,0", 3);
    lookup.emplace("1,1", 2);
    lookup.emplace("2,0", 2);
    return helper(x, y, lookup);
  }
  int helper(int x, int y, unordered_map<string, int>& lookup) {
    x = abs(x), y = abs(y);
    if (x < y) swap(x, y);
    string s = to_string(x) + ',' + to_string(y);
    if (lookup.count(s)) return lookup[s];
    int temp =
        min(helper(x - 1, y - 2, lookup), helper(x - 2, y - 1, lookup)) + 1;
    lookup[s] = temp;
    return temp;
  }
};