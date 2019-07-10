class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }
    vector<int> result(nums.size());
    result[0] = 1;
    for (int i = 1; i < nums.size(); ++i) {
      result[i] = result[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int j = nums.size() - 2; j > 0; --j) {
      right = right * nums[j + 1];
      result[j] = result[j] * right;
    }
    return result;
  }
};