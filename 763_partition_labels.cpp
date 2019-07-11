class Solution {
 public:
  vector<int> partitionLabels(string S) {
    unordered_map<int, int> lookup;
    for (int i = 0; i < S.length(); ++i) {
      lookup[S[i]] = i;
    }
    int begin = 0, end = 0;
    vector<int> ans;
    for (int i = 0; i < S.length(); ++i) {
      end = max(end, lookup[S[i]]);
      if (i == end) {
        ans.push_back(i - begin + 1);
        begin = i + 1;
      }
    }
    return ans;
  }
};