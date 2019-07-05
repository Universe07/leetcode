class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int begin = 0, end = nums.size();
    int res = -1;
    while (res == -1) {
      int mid = begin + (end - begin) / 2;
      if (target == nums[mid]) {
        res = mid;
      } else if (target > nums[mid]) {
        if (mid == nums.size() - 1 || nums[mid + 1] > target) {
          res = mid + 1;
        }
        begin = mid + 1;
      } else if (target < nums[mid]) {
        if (mid == 0 || nums[mid - 1] < target) {
          res = mid;
        }
        end = mid - 1;
      }
    }
    return res;
  }
};