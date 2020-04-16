class Solution {
 public:
  int strobogrammaticInRange(string low, string high) {
    unordered_map<char, char> mp = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    int count = 0;
    for (int len = low.length(); len <= high.length(); ++len) {
      string temp(len, '0');
      dfs(low, high, temp, 0, len - 1, count, mp);
    }
    return count;
  }
  void dfs(string low, string high, string str, int left, int right, int& count,
           unordered_map<char, char>& mp) {
    if (left > right) {
      if ((str.length() == low.length() && str.compare(low) < 0) ||
          (str.length() == high.length() && str.compare(high) > 0))
        return;
      count++;
      return;
    }
    for (auto p : mp) {
      str[left] = p.first;
      str[right] = p.second;
      if (str.size() != 1 && str[0] == '0') continue;
      if (left < right || left == right && p.first == p.second)
        dfs(low, high, str, left + 1, right - 1, count, mp);
    }
  }
};