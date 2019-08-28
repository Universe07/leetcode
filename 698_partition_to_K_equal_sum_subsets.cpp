class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    sort(nums.rbegin(), nums.rend());
    return dfs(nums, sum / k, k, 0, 0);
  }
  bool dfs(vector<int>& nums, int target, int k, int curr, int used) {
    if (k == 0) return used == (1 << nums.size()) - 1;
    for (int i = 0; i < nums.size(); ++i) {
      if (used & (1 << i)) continue;
      int ncurr = curr + nums[i];
      if (ncurr > target) break;
      int new_used = used | (1 << i);
      if (ncurr == target && dfs(nums, target, k - 1, 0, new_used))
        return true;
      else if (dfs(nums, target, k, ncurr, new_used))
        return true;
    }
    return false;
  }
};