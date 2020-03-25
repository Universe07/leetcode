// Binary Search
// Time: O(log(sum(nums))*n)
// Space: O(1)

class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    long l = *max_element(begin(nums), end(nums));
    long r = accumulate(begin(nums), end(nums), 0L) + 1;
    while (l < r) {
      long limit = (r - l) / 2 + l;
      if (min_groups(nums, limit) > m) {
        l = limit + 1;
      } else {
        r = limit;
      }
    }
    return l;
  }

 private:
  int min_groups(const vector<int>& nums, long limit) {
    long sum = 0;
    int groups = 1;
    for (int num : nums) {
      if (sum + num > limit) {
        sum = num;
        ++groups;
      } else {
        sum += num;
      }
    }
    return groups;
  }
};