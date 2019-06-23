// Time: O(n)
// Space: O(n)

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int i = 0;
    vector<int> temp;
    for (const auto& push : pushed) {
      temp.emplace_back(push);
      while (!temp.empty() && temp.back() == popped[i]) {
        temp.pop_back();
        i++;
      }
    }
    return i == popped.size();
  }
};