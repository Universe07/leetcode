class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.back() - nums.front() + 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (canFinish(nums, mid, k)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
  bool canFinish(vector<int>& nums, int mid, int k) {
    int count = 0, right = 0;
    for (int left = 0; left < nums.size(); ++left) {
      while (right < nums.size() && nums[right] - nums[left] <= mid) {
        ++right;
      }
      count += right - left - 1;
    }
    return count >= k;
  }
};