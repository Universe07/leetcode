// Time: O(n)
// Space: O(1)

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    auto max_sum = INT_MIN, sum = 0;
    for (const auto& num : nums) {
      sum = max(sum + num, num);
      max_sum = max(max_sum, sum);
    }
    return max_sum;
  }
};