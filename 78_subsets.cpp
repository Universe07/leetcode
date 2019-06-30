// Time: (2^n)
// Space: O(1)

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> item;
    result.push_back(item);
    generate(0, nums, item, result);
    return result;
  }
  void generate(int i, vector<int>& nums, vector<int>& item,
                vector<vector<int>>& result) {
    if (i >= nums.size()) {
      return;
    }
    item.push_back(nums[i]);
    result.push_back(item);
    generate(i + 1, nums, item, result);
    item.pop_back();
    generate(i + 1, nums, item, result);
  }
};

// Time: O(n * 2 ^ n)
// Space: O(1)

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result(1);
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); ++i) {
      const size = result.size();
      for (size_t j = 0; j < size; ++j) {
        result.emplace_back(result[j]);
        result.back().emplace_back(nums[i]);
      }
    }
    return result;
  }
};

// Time: O(2^n * n)
// Space: O(1)

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    int all_set = 1 << nums.size();
    cout << all_set << endl;
    for (int i = 0; i < all_set; ++i) {
      vector<int> item;
      for (int j = 0; j < nums.size(); ++j) {
        if (i & (1 << j)) {
          item.push_back(nums[j]);
        }
      }
      result.push_back(item);
    }
    return res;
  }
};
