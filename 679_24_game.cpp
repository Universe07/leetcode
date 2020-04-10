class Solution {
 public:
  bool judgePoint24(vector<int>& nums) {
    return judge24({nums.begin(), nums.end()});
  }
  static bool judge24(vector<double> nums) {
    auto n = nums.size();
    if (n == 1) return abs(nums[0] - 24) < 1e-10;
    sort(nums.begin(), nums.end());
    do {
      vector<double> temp(nums.begin(), nums.end() - 1);
      auto a = nums[n - 1], b = nums[n - 2];
      for (auto num : {a + b, a - b, a * b, a ? b / a : 0}) {
        temp.back() = num;
        if (judge24(temp)) return true;
      }
    } while (next_permutation(nums.begin(), nums.end()));
    return false;
  }
};

class Solution {
 public:
  bool judgePoint24(vector<int>& nums) {
    vector<double> tmp;
    for (auto num : nums) {
      tmp.push_back(num);
    }
    return recurse(tmp, tmp.size());
  }

  bool recurse(vector<double>& nums, int n) {
    if (n == 1) {
      if (fabs(nums[0] - 24) < 0.00001) {
        return true;
      }
      return false;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        double val1 = nums[i];
        double val2 = nums[j];
        double res1 = val1 - val2;
        double res2 = val1 + val2;
        double res3 = val1 / val2;
        double res4 = val2 / val1;
        double res5 = val1 * val2;
        double res6 = val2 - val1;
        nums[j] = nums[n - 1];
        nums[i] = res1;
        bool ans1 = recurse(nums, n - 1);
        nums[i] = res2;
        bool ans2 = recurse(nums, n - 1);
        nums[i] = res3;
        bool ans3 = recurse(nums, n - 1);
        nums[i] = res4;
        bool ans4 = recurse(nums, n - 1);
        nums[i] = res5;
        bool ans5 = recurse(nums, n - 1);
        nums[i] = res6;
        bool ans6 = recurse(nums, n - 1);
        if (ans1 || ans2 || ans3 || ans4 || ans5 || ans6) {
          return true;
        }
        nums[i] = val1;
        nums[j] = val2;
      }
    }

    return false;
  }
};