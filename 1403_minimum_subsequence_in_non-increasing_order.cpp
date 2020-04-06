// Time: 16ms
class Solution {
 public:
  vector<int> minSubsequence(vector<int>& nums) {
    vector<int> res;
    auto sub_sum = 0, half_sum = accumulate(begin(nums), end(nums), 0) / 2;
    priority_queue<int> pq(begin(nums), end(nums));
    while (sub_sum <= half_sum) {
      res.push_back(pq.top());
      sub_sum += res.back();
      pq.pop();
    }
    return res;
  }
};
// Time: 12ms

class Solution {
 public:
  vector<int> minSubsequence(vector<int>& nums) {
    int max_sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int> ans;
    sort(nums.begin(), nums.end());
    if (nums.empty()) return ans;
    int sum = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      ans.push_back(nums[i]);
      sum += nums[i];
      if (sum > (max_sum / 2)) {
        return ans;
      }
    }
    return ans;
  }
};