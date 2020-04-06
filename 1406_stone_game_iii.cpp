// Solution 1: DP dp[i] means, if we ignore before A[i],
// what's the highest score that Alex can win over the Bob？

// There are three option for Alice to choose.
// Take A[i], win take - dp[i+1]
// Take A[i] + A[i+1], win take - dp[i+2]
// Take A[i] + A[i+1] + A[i+2], win take - dp[i+3]
// dp[i] equals the best outcome of these three solutions.

//Complexity: Time O(N^) Space O(N) 
class Solution {
 public:
  string stoneGameIII(vector<int>& stoneValue) {
		int n = stoneValue.size();
		vector<int> dp(n, INT_MIN);
		for(int i = n - 1; i >=0; --i) {
			for (int k = 0, take = 0; k < 3 && i + k < n; ++k) {
				take += stoneValue[i + k];
				dp[i] = max(dp[i], take - (i + k + 1 < n ? dp[i + k + 1] : 0));
			}
		}
		if (dp[0] > 0) return "Alice";
		if (dp[0] < 0) return "Bob";
		return "Tie";
	}
};