class Solution {
 public:
  int myAtoi(string str) {
    if (str.empty()) {
      return 0;
    }
    int i = 0;
    int sign = 1;
    int ans = 0;

    while (str[i] == ' ' || str[i] == '\t') {
      ++i;
    }
    if (i == str.length()) {
      return 0;
    }

    if (str[i] == '+') {
      ++i;
    } else if (str[i] == '-') {
      sign = -1;
      ++i;
    }
    for (; i < str.length() && isdigit(str[i]); ++i) {
      if (ans > (INT_MAX - (str[i] - '0')) / 10) {
        return sign > 0 ? INT_MAX : INT_MIN;
      }
      ans *= 10;
      ans += str[i] - '0';
    }
    return sign * ans;
  }
};