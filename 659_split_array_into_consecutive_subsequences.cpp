// Time: O(n)
// Space: O(n)

class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int, int> cnt, tails;
    for (int& num : nums) ++cnt[num];
    for (int& num : nums) {
      if (!cnt[num]) continue;
      cnt[num]--;
      if (tails[num - 1] > 0) {
        --tails[num - 1];
        ++tails[num];
      } else if (cnt[num + 1] && cnt[num + 2]) {
        --cnt[num + 1];
        --cnt[num + 2];
        ++tails[num + 2];
      } else
        return false;
    }
    return true;
  }
};