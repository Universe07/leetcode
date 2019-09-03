class Solution {
 public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    graph = vector<vector<int>>(N);
    for (int i = 0; i < dislikes.size(); ++i) {
      graph[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
      graph[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
    }
    colors = vector<int>(N, 0);
    for (int i = 0; i < N; ++i) {
      if (colors[i] == 0 && !dfs(i, 1)) return false;
    }
    return true;
  }

 private:
  vector<vector<int>> graph;
  vector<int> colors;
  bool dfs(int cur, int color) {
    colors[cur] = color;
    for (int nextCur : graph[cur]) {
      if (colors[nextCur] == color) return false;
      if (colors[nextCur] == 0 && !dfs(nextCur, -color)) return false;
    }
    return true;
  }
};

class Solution {
 public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(N);
    queue<int> que;
    vector<int> colors(N, 0);
    for (int i = 0; i < dislikes.size(); ++i) {
      graph[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
      graph[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
    }
    for (int i = 0; i < N; ++i) {
      if (colors[i] != 0) continue;
      que.push(i);
      colors[i] = 1;
      while (!que.empty()) {
        int front = que.front();
        que.pop();
        for (int nextCur : graph[front]) {
          if (colors[nextCur] == colors[front]) return false;
          if (colors[nextCur] != 0) continue;
          colors[nextCur] = -colors[front];
          que.push(nextCur);
        }
      }
    }
    return true;
  }
};