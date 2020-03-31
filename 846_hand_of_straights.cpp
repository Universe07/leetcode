// Time: O(MlogM + MW)

class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int W) {
    map<int, int> cnt;
    for (int& i : hand) ++cnt[i];
    for (auto it : cnt) {
      if (cnt[it.first] > 0) {
        for (int i = W - 1; i >= 0; --i) {
          if ((cnt[it.first + i] -= cnt[it.first]) < 0) return false;
        }
      }
    }
    return true;
  }
};