class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    const int m = board.size();
    const int n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dfs(board, word, 0, i, j)) {
          return true;
        }
      }
    }
    return false;
  }
  bool dfs(vector<vector<char>>& board, string word, int pos, int i, int j) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] != word[pos]) {
      return false;
    }
    if (pos == word.size() - 1) {
      return true;
    }
    char cur = board[i][j];
    board[i][j] = 0;
    bool ret = dfs(board, word, pos + 1, i + 1, j) ||
               dfs(board, word, pos + 1, i - 1, j) ||
               dfs(board, word, pos + 1, i, j + 1) ||
               dfs(board, word, pos + 1, i, j - 1);
    board[i][j] = cur;
    return ret;
  }
};
