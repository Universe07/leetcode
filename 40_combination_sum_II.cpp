// Time : O(n!)
// Space: O(1)

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> item;
    set<vector<int>> res_set;
    int sum = 0;
    sort(candidates.begin(), candidates.end());
    generate(0, target, 0, candidates, result, item, res_set);
    return result;
  }
  void generate(int i, int target, int sum, vector<int>& nums,
                vector<vector<int>>& result, vector<int>& item,
                set<vector<int>>& res_set) {
    if (i >= nums.size() || sum > target) {
      return;
    }
    item.push_back(nums[i]);
    sum += nums[i];
    if (target == sum && res_set.find(item) == res_set.end()) {
      result.push_back(item);
      res_set.insert(item);
    }
    generate(i + 1, target, sum, nums, result, item, res_set);
    sum -= nums[i];
    item.pop_back();
    generate(i + 1, target, sum, nums, result, item, res_set);
  }
};