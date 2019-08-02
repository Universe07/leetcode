class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    const int m = board.size();
    const int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dfs(board, word, 0, i, j, visited)) {
          return true;
        }
      }
    }
    return false;
  }
  bool dfs(vector<vector<char>>& board, string word, int pos, int i, int j,
           vector<vector<bool>>& visited) {
    if (pos == word.size()) {
      return true;
    }
    if (i < 0 || i >= visited.size() || j < 0 || j >= visited[0].size() ||
        visited[i][j] || board[i][j] != word[pos]) {
      return false;
    }
    visited[i][j] = true;
    bool ret = dfs(board, word, pos + 1, i + 1, j, visited) ||
               dfs(board, word, pos + 1, i - 1, j, visited) ||
               dfs(board, word, pos + 1, i, j + 1, visited) ||
               dfs(board, word, pos + 1, i, j - 1, visited);
    visited[i][j] = false;
    return ret;
  }
};