// Time: O(n)
// Space: O(n)

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> lookup;
    for (int i = 0; i < nums.size(); ++i) {
      if (lookup.count(target - nums[i])) {
        return {i, lookup[target - nums[i]]};
      }
      lookup[nums[i]] = i;
    }
    return {};
  }
};
