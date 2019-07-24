class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int result = 0;
    int sum = 0;
    unordered_map<int, int> lookup;
    ++lookup[0];
    for (const auto& num : nums) {
      sum += num;
      result += lookup[sum - k];
      ++lookup[sum];
    }
    return result;
  }
};