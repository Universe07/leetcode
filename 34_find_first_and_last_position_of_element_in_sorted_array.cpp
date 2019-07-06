class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left = lowerBound(nums, target);
    int right = upperBound(nums, target);
    return {left, right};
  }
  int lowerBound(vector<int>& nums, int target) {
    int begin = 0, end = nums.size() - 1;
    while (begin <= end) {
      int mid = begin + (end - begin) / 2;
      if (nums[mid] == target) {
        if (mid == 0 || nums[mid - 1] < target) {
          return mid;
        }
        end = mid - 1;
      } else if (nums[mid] < target) {
        begin = mid + 1;
      } else if (nums[mid] > target) {
        end = mid - 1;
      }
    }
    return -1;
  }
  int upperBound(vector<int>& nums, int target) {
    int begin = 0, end = nums.size() - 1;
    while (begin <= end) {
      int mid = begin + (end - begin) / 2;
      if (nums[mid] == target) {
        if (mid == nums.size() - 1 || target < nums[mid + 1]) {
          return mid;
        }
        begin = mid + 1;
      } else if (nums[mid] < target) {
        begin = mid + 1;
      } else if (nums[mid] > target) {
        end = mid - 1;
      }
    }
    return -1;
  }
};