class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<vector<int>> mark;
    vector<string> location;
    for (int i = 0; i < n; ++i) {
      mark.push_back(vector<int>());
      for (int j = 0; j < n; ++j) {
        mark[i].push_back(0);
      }
      location.push_back("");
      location[i].append(n, '.');
    }
    generate(0, n, location, result, mark);
    return result;
  }
  void generate(int k, int n, vector<string>& location,
                vector<vector<string>>& result, vector<vector<int>>& mark) {
    if (k == n) {
      result.push_back(location);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (mark[k][i] == 0) {
        vector<vector<int>> tmp_mark = mark;
        location[k][i] = 'Q';
        put_down_the_queen(k, i, mark);
        generate(k + 1, n, location, result, mark);
        mark = tmp_mark;
        location[k][i] = '.';
      }
    }
  }

  void put_down_the_queen(int x, int y, vector<vector<int>>& mark) {
    static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    mark[x][y] = 1;
    for (int i = 1; i < mark.size(); ++i) {
      for (int j = 0; j < 8; ++j) {
        int newx = x + i * dx[j];
        int newy = y + i * dy[j];
        if (newx >= 0 && newx < mark.size() && newy >= 0 &&
            newy < mark.size()) {
          mark[newx][newy] = 1;
        }
      }
    }
  }
};

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    sol.clear();
    board = vector<string>(n, string(n, '.'));
    cols = vector<int>(n, 0);
    diag1 = vector<int>(n * 2 - 1, 0);
    diag2 = vector<int>(n * 2 - 1, 0);
    nqueens(n, 0);
    return sol;
  }

 private:
  vector<string> board;
  vector<int> cols;
  vector<int> diag1;
  vector<int> diag2;
  vector<vector<string>> sol;

  bool available(int row, int col, int n) {
    return !cols[col] && !diag1[row + col] && !diag2[row - col + n - 1];
  }
  void updateBoard(int row, int col, int n, bool is_put) {
    cols[col] = is_put;
    diag1[row + col] = is_put;
    diag2[row - col + n - 1] = is_put;
    board[row][col] = is_put ? 'Q' : '.';
  }
  void nqueens(int n, int row) {
    if (row == n) {
      sol.push_back(board);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (!available(row, col, n)) continue;
      updateBoard(row, col, n, true);
      nqueens(n, row + 1);
      updateBoard(row, col, n, false);
    }
  }
};