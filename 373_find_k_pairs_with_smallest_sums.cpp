class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    vector<vector<int>> res;
    int m = nums1.size();
    int n = nums2.size();
    k = min(k, m * n);
    vector<int> indice(m, 0);
    while (k-- > 0) {
      int tmp_index = 0;
      long tmp_sum = LONG_MAX;
      for (int i = 0; i < m; ++i) {
        if (indice[i] < n && tmp_sum >= nums1[i] + nums2[indice[i]]) {
          tmp_index = i;
          tmp_sum = nums1[i] + nums2[indice[i]];
        }
      }
      vector<int> tmp(2);
      tmp[0] = nums1[tmp_index];
      tmp[1] = nums2[indice[tmp_index]];
      res.push_back(tmp);
      indice[tmp_index]++;
    }
    return res;
  }
};