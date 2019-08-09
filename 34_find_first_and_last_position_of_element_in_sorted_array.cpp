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

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2, -1);
    if (nums.empty()) {
      return ans;
    }
    ans[0] = lower_bound(nums, target);
    if (ans[0] != -1) ans[1] = upper_bound(nums, target);
    return ans;
  }
  int lower_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
      i int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    if (left != nums.size() && nums[left] == target) {
      return left;
    } else {
      return -1;
    }
  }
  int upper_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    if (left != 0 && nums[left - 1] == target) {
      return left - 1;
    } else {
      return -1;
    }
  }
};