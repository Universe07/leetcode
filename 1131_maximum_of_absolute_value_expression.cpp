class Solution {
 public:
  int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    vector<int> sum1(n, 0), diff1(n, 0), sum2(n, 0), diff2(n, 0);
    for (int i = 0; i < n; ++i) {
      sum1[i] = arr1[i] + arr2[i] + i;
      sum2[i] = arr1[i] + arr2[i] - i;
      diff1[i] = arr1[i] - arr2[i] + i;
      diff2[i] = arr1[i] - arr2[i] - i;
    }
    return max(max(help(sum1, n), help(diff1, n)),
               max(help(sum2, n), help(diff2, n)));
  }
  int help(vector<int>& arr, int n) {
    int max_sum = arr[0], min_sum = arr[0];
    for (int i = 0; i < n; ++i) {
      max_sum = max(max_sum, arr[i]);
      min_sum = min(min_sum, arr[i]);
    }
    return max_sum - min_sum;
  }
};

class Solution {
 public:
  int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    int res = 0, n = arr1.size(), closest, cur;
    for (int p : {1, -1}) {
      for (int q : {1, -1}) {
        closest = p * arr1[0] + q * arr2[0] + 0;
        for (int i = 1; i < n; ++i) {
          cur = p * arr1[i] + q * arr2[i] + i;
          res = max(res, cur - closest);
          closest = min(closest, cur);
        }
      }
    }
    return res;
  }
};