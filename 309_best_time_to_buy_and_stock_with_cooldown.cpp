class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int sold = 0;
    int rest = 0;
    int hold = INT_MIN;
    for (const int price : prices) {
      int prev_sold = sold;
      sold = hold + price;
      hold = max(hold, rest - price);
      rest = max(rest, prev_sold);
    }
    return max(rest, sold);
  }
};