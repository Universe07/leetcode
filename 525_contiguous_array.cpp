class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int size = nums.size(), bal = size, max_len = 0;
    vector<int> bals(2 * size + 1);
    for (auto i = 0; i < size; ++i) {
      bal += nums[i] == 0 ? -1 : 1;
      if (bal == size)
        max_len = max(max_len, i + 1);
      else {
        if (bals[bal] != 0)
          max_len = max(max_len, i - bals[bal] + 1);
        else
          bals[bal] = i + 1;
      }
    }
    return max_len;
  }
};