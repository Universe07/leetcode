class Solution {
 public:
  int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
      if (op == '+' || op == '-') {
        total += term;
        in >> term;
        term *= 44 - op;
      } else {
        in >> n;
        if (op == '*')
          term *= n;
        else
          term /= n;
      }
    }
    return total;
  }
};

class Solution {
 public:
  int calculate(string s) {
    stack<long long> stk;
    char sign = '+';
    long long res = 0, tmp = 0;
    for (unsigned int i = 0; i < s.length(); ++i) {
      if (isdigit(s[i])) tmp = tmp * 10 + s[i] - '0';
      if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {
        if (sign == '-')
          stk.push(-tmp);
        else if (sign == '+')
          stk.push(tmp);
        else {
          long long num;
          if (sign == '*') num = stk.top() * tmp;
          if (sign == '/') num = stk.top() / tmp;
          stk.pop();
          stk.push(num);
        }
        sign = s[i];
        tmp = 0;
      }
    }
    while (!stk.empty()) {
      res += stk.top();
      stk.pop();
    }
    return res;
  }
};