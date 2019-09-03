class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set<int> visited;
    dfs(rooms, 0, visited);
    return visited.size() == rooms.size();
  }
  void dfs(vector<vector<int>>& rooms, int i, unordered_set<int>& visited) {
    if (visited.count(i)) return;
    visited.insert(i);
    for (int nextCur : rooms[i]) {
      dfs(rooms, nextCur, visited);
    }
  }
};