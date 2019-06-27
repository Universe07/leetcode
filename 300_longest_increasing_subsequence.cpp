// Time: O(nlogn)
// Space: O(n)

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> LIS;
    for (const auto& num : nums) {
      insert(&LIS, num);
    }
    return LIS.size();
  }
  void insert(vector<int>* LIS, const int num) {
    auto it = lower_bound(LIS->begin(), LIS->end(), num);
    if (it == LIS->end()) {
      LIS->emplace_back(num);
    } else {
      *it = num;
    }
  }
};

// Time: O(n2)
// Space: O(n)

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
        }
      }
    }
    int res = 0;
    for (int i = 0; i < dp.size(); ++i) {
      res = max(res, dp[i]);
    }
    return res;
  }
};