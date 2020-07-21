class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int N = cardPoints.size(), i = 0, j = N - k;
    auto sum = accumulate(cardPoints.begin() + j, cardPoints.end(), 0),
         ans = sum;
    while (k--) ans = max(ans, sum += cardPoints[i++] - cardPoints[j++]);
    return ans;
  }
};