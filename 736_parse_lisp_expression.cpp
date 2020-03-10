// Time: O(n^2) in worst case, O(n) in practice
// Space: O(n)

class Solution {
 public:
  int evaluate(string expression) {
    scopes_.clear();
    int pos = 0;
    return parse(expression, pos);
  }

 private:
  int parse(const string& s, int& pos) {
    scopes_.push_front(unordered_map<string, int>());
    int value = 0;
    if (s[pos] == '(') ++pos;
    const string token = getToken(s, pos);
    if (token == "add") {
      int v1 = parse(s, ++pos);
      int v2 = parse(s, ++pos);
      value = v1 + v2;
    } else if (token == "mult") {
      int v1 = parse(s, ++pos);
      int v2 = parse(s, ++pos);
      value = v1 * v2;
    } else if (token == "let") {
      string var;
      while (s[pos] != ')') {
        ++pos;
        if (s[pos] == '(') {
          value = parse(s, ++pos);
          break;
        }
        var = getToken(s, pos);
        if (s[pos] == ')') {
          if (isalpha(var[0])) {
            value = getValue(var);
          } else {
            value = stoi(var);
          }
          break;
        }
        value = scopes_.front()[var] = parse(s, ++pos);
      }
    } else if (isalpha(token[0])) {
      value = getValue(token);
    } else {
      value = stoi(token);
    }
    if (s[pos] == ')') ++pos;
    scopes_.pop_front();
    return value;
  }
  int getValue(const string& token) {
    for (const auto& scope : scopes_) {
      if (scope.count(token)) return scope.at(token);
    }
    return 0;
  }
  string getToken(const string& s, int& pos) {
    string token;
    while (pos < s.length()) {
      if (s[pos] == ')' || s[pos] == ' ') break;
      token += s[pos++];
    }
    return token;
  }
  deque<unordered_map<string, int>> scopes_;
};