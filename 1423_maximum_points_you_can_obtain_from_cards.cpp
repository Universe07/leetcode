class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int N = A.size(), i = 0, j = N - k;
		auto sum = accumulate(A.begin() + j, A.end(), 0);
		max = sum;
		while (k --) max = max(max, sum += A[i++] - A[j++]);
		return max;
  }
};