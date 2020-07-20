class Solution {
 public:
  int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> best(n, INT_MAX);
    int sum = 0, start = 0, ans = INT_MAX, best_so_far = INT_MAX;
    for (int i = 0; i < n; ++i) {
      sum += arr[i];
      while (sum > target) {
        sum -= arr[start];
        start++;
      }
      if (sum == target) {
        if (start > 0 && best[start - 1] != INT_MAX) {
          ans = min(ans, best[start - 1] + i - start + 1);
        }
        best_so_far = min(best_so_far, i - start + 1);
      }
      best[i] = best_so_far;
    }
    return ans == INT_MAX ? -1 : ans;
  }
};