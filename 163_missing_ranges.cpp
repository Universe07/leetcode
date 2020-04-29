class Solution {
 public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> res;
    long next = lower;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < next) continue;
      if (nums[i] == next) {
        next++;
        continue;
      }
      res.push_back(getRange(next, nums[i] - 1));
      next = nums[i] + 1L;
    }
    if (next <= upper) res.push_back(getRange(next, upper));
    return res;
  }
  string getRange(long n1, long n2) {
    return n1 == n2 ? to_string(n1) : to_string(n1) + "->" + to_string(n2);
  }
};