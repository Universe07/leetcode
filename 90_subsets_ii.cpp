class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> item;
    set<vector<int>> res_set;
    result.push_back(item);
    sort(nums.begin(), nums.end());
    generate(0, nums, result, item, res_set);
    return result;
  }
  void generate(int i, vector<int>& nums, vector<vector<int>>& result,
                vector<int>& item, set<vector<int>>& res_set) {
    if (i >= nums.size()) {
      return;
    }
    item.push_back(nums[i]);
    if (res_set.find(item) == res_set.end()) {
      res_set.insert(item);
      result.push_back(item);
    }
    generate(i + 1, nums, result, item, res_set);
    item.pop_back();
    generate(i + 1, nums, result, item, res_set);
  }
};