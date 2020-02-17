// Time: O(n^2)
// Space: O()

class Solution {
 public:
  int minMutation(string start, string end, vector<string>& bank) {
    queue<string> q;
    q.push(start);
    unordered_set<string> visited;
    visited.insert(start);
    int mutations = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        string curr = q.front();
        q.pop();
        if (curr == end) return mutations;
        for (const auto& str : bank) {
          if (visited.count(str) || !validMutation(str, curr)) continue;
          visited.insert(str);
          q.push(str);
        }
      }
      ++mutations;
    }
    return -1;
  }

 private:
  bool validMutation(const string& s1, const string& s2) {
    int count = 0;
    for (int i = 0; i < s1.length(); ++i) {
      if (s1[i] != s2[i] && count++) return false;
    }
    return true;
  }
};