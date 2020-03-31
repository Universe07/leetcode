// Time: O(MlogM + MW)

class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int W) {
    map<int, int> cnt;
    for (int& i : hand) ++cnt[i];
    for (auto it : cnt) {
      if (cnt[it.first] > 0) {
        for (int group = W - 1; group >= 0; --group) {
          if ((cnt[it.first + group] -= cnt[it.first]) < 0) return false;
        }
      }
    }
    return true;
  }
};