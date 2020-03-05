class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    return max(robRange(nums, 0, nums.size() - 1),
               robRange(nums, 1, nums.size()));
  }
  int robRange(vector<int>& nums, int start, int end) {
    int nums_i = nums[start], nums_i_1 = 0, nums_i_2 = 0;
    for (int i = start + 1; i < end; ++i) {
      nums_i_2 = nums_i_1;
      nums_i_1 = nums_i;
      nums_i = max(nums[i] + nums_i_2, nums_i_1);
    }
    return nums_i;
  }
};