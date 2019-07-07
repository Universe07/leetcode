class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    map<string, vector<string>> graph;
    constructGraph(beginWord, wordList, graph);
    return BFS(beginWord, endWord, graph);
  }
  bool connect(const string& word1, const string& word2) {
    int cnt = 0;
    for (int i = 0; i < word1.length(); ++i) {
      if (word1[i] != word2[i]) {
        ++cnt;
      }
    }
    return cnt == 1;
  }
  void constructGraph(string& beginWord, vector<string>& wordList,
                      map<string, vector<string>>& graph) {
    wordList.push_back(beginWord);
    for (int i = 0; i < wordList.size(); ++i) {
      graph[wordList[i]] = vector<string>();
    }
    for (int i = 0; i < wordList.size(); ++i) {
      for (int j = i + 1; j < wordList.size(); ++j) {
        if (connect(wordList[i], wordList[j])) {
          graph[wordList[i]].push_back(wordList[j]);
          graph[wordList[j]].push_back(wordList[i]);
        }
      }
    }
  }
  int BFS(string& beginWord, string& endWord,
          map<string, vector<string>>& graph) {
    queue<pair<string, int>> que;
    set<string> visited;
    que.push(make_pair(beginWord, 1));
    visited.insert(beginWord);
    while (!que.empty()) {
      string word = que.front().first;
      int cnt = que.front().second;
      que.pop();
      if (word == endWord) {
        return cnt;
      }
      vector<string>& words = graph[word];
      for (int i = 0; i < words.size(); ++i) {
        if (visited.find(words[i]) == visited.end()) {
          que.push(make_pair(words[i], cnt + 1));
          visited.insert(words[i]);
        }
      }
    }
    return 0;
  }
};