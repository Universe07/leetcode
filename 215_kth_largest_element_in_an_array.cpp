// Time:  O(n) ~ O(n^2)
// Space: O(1)

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};
// min_heap
// Time : O(nlogk)
// Space : O(k)

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < nums.size(); ++i) {
      if (i < k) {
        que.push(nums[i])
      } else if (nums[i] < que.top()) {
        que.push(nums[i]);
        que.pop();
      }
    }
    return que.top();
  }
};