class Solution {
 public:
  int confusingNumberII(int N) {
		for (int x : {1, 6, 8, 9}) dfs(x, N);
		return count;
	}
	void dfs(long long x , int N) {
		if (x > N) return;
		if (isConfusing(x)) count++;
		for (auto y : v) dfs(x * 10 + y, N);
	}
	bool isConfusing(int x ) {
		int arr[10];
		int i = 0;
		while (x) {
			arr[i++] = x % 10;
			x /= 10;
		}
		for (int l = 0, r = i - 1; l <= r; l++, r--){
			if (arr[l] != mp[arr[r]]) return true;
		}
		return false;
	}
	int count = 0;
	const vector<int> mp = {0, 1, 2, 3, 4, 5, 9, 7, 8, 6};
	const vector<int> v = {0 ,1, 6, 8, 9};
};