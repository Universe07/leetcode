// Time: O(n)
// Space: O(1)

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int far;
    for (int i = 0; i <= far && i < nums.size(); ++i) {
      far = max(far, i + nums[i]);
    }
    return (far >= nums.size() - 1);
  }
};