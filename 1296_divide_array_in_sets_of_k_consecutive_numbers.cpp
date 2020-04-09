class Solution {
 public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    map<int, int> count;
    for (int num : nums) count[num]++;
    for (auto it : count) {
      if (count[it.first] > 0) {
        for (int i = k - 1; i >= 0; --i) {
          if ((count[it.first + i] -= count[it.first]) < 0) {
            return false;
          }
        }
      }
    }
    return true;
  }
};