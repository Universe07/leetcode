class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum = (sum + nums[i]) * nums[i];
      if (max < sum) max = sum;
    }
    return max;
  }
};