class Solution {
 public:
  bool confusingNumber(int N) {
    const string s = to_string(N);
    vector<int> vec = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    string ans;
    for (char c : s) {
      if (vec[c - '0'] == -1)
        return false;
      else
        ans += to_string(vec[c - '0']);
    }
		int l = 0, r = ans.size() - 1;
		while (l < r) {
			swap(ans[l], ans[r]);
			++l;
			--r;
		}
    int tmp = stoi(ans);
    return tmp != N;
  }
};