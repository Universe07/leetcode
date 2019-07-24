class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int ans = nums[0], cnt = 0;
    for (const auto& num : nums) {
      if (ans == num) {
        ++cnt;
      } else if (--cnt == 0) {
        ans = num;
        cnt = 1;
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
  }
};

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    for (const auto& num : nums) {
      if (++count[num] > nums.size() / 2) {
        return num;
      }
    }
    return -1;
  }
};

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    return majorityHelper(nums, 0, nums.size() - 1);
  }

 private:
  int majorityHelper(vector<int>& nums, int left, int right) {
    if (left == right) {
      return nums[left];
    }
    int mid = left + (right - left) / 2;
    int mleft = majorityHelper(nums, left, mid);
    int mright = majorityHelper(nums, mid + 1, right);
    if (mleft == mright) {
      return mleft;
    }
    return count(nums.begin() + left, nums.begin() + right + 1, mleft) >
                   count(nums.begin() + left, nums.begin() + right + 1, mright)
               ? mleft
               : mright;
  }
};