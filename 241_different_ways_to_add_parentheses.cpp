namespace ops {
int add(int a, int b) { return a + b; }
int minus(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
}  // namespace ops

class Solution {
 public:
  vector<int> diffWaysToCompute(string input) { return ways(input); }

 private:
  unordered_map<string, vector<int>> lookup;
  const vector<int>& ways(string input) {
    if (lookup.count(input)) return lookup[input];
    vector<int> ans;
    for (int i = 0; i < input.size(); ++i) {
      char op = input[i];
      if (op == '+' || op == '-' || op == '*') {
        const string left = input.substr(0, i);
        const string right = input.substr(i + 1);
        const vector<int>& l = ways(left);
        const vector<int>& r = ways(right);
        function<int(int, int)> func;
        switch (op) {
          case '+':
            func = ops::add;
            break;
          case '-':
            func = ops::minus;
            break;
          case '*':
            func = ops::multiply;
            break;
        }
        for (int a : l) {
          for (int b : r) {
            ans.push_back(func(a, b));
          }
        }
      }
    }
    if (ans.empty()) {
      ans.push_back(stoi(input));
    }
    return lookup[input] = ans;
  }
};