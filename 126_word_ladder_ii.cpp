class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return {};
    dict.erase(beginWord);
    dict.erase(endWord);

    vector<vector<string>> ans;
    unordered_map<string, int> steps{{beginWord, 1}};
    unordered_map<string, vector<string>> parents;
    queue<string> q;
    q.push(beginWord);
    const int len = beginWord.length();
    int step = 0;
    bool found = false;

    while (!q.empty() && !found) {
      ++step;
      for (int size = q.size(); size > 0; --size) {
        const string word = q.front();
        q.pop();
        string child = word;
        for (int i = 0; i < len; ++i) {
          char ch = child[i];
          for (int j = 'a'; j <= 'z'; ++j) {
            child[i] = j;
            if (child == endWord) {
              found = true;
              parents[child].push_back(word);
            } else {
              if (steps.count(child) && step < steps.at(child)) {
                parents[child].push_back(word);
              }
            }
            if (!dict.count(child)) continue;
            dict.erase(child);
            q.push(child);
            steps[child] = step + 1;
            parents[child].push_back(word);
          }
          child[i] = ch;
        }
      }
    }
    if (found) {
      vector<string> curr{endWord};
      getPaths(endWord, beginWord, parents, curr, ans);
    }
    return ans;
  }

 private:
  void getPaths(const string& endWord, const string& beginWord,
                const unordered_map<string, vector<string>>& parents,
                vector<string>& curr, vector<vector<string>>& ans) {
    if (endWord == beginWord) {
      ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
      return;
    }
    for (const string& p : parents.at(endWord)) {
      curr.push_back(p);
      getPaths(p, beginWord, parents, curr, ans);
      curr.pop_back();
    }
  }
};

class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return {};
    dict.erase(endWord);
    unordered_set<string> q{beginWord}, p;
    vector<vector<string>> ans;
    const int len = beginWord.length();
    unordered_map<string, vector<string>> children;
    bool found = false;

    while (!found && !q.empty()) {
      for (const string& word : q) {
        dict.erase(word);
      }
      for (const string& word : q) {
        string curr = word;
        for (int i = 0; i < len; ++i) {
          char ch = curr[i];
          for (int j = 'a'; j <= 'z'; ++j) {
            curr[i] = j;
            if (curr == endWord) {
              found = true;
              children[word].push_back(curr);
            } else if (dict.count(curr) && !found) {
              p.insert(curr);
              children[word].push_back(curr);
            }
          }
          curr[i] = ch;
        }
      }
      swap(p, q);
      p.clear();
    }
    if (found) {
      vector<string> path{beginWord};
      getPaths(endWord, beginWord, children, path, ans);
    }
    return ans;
  }

 private:
  void getPaths(const string& endWord, const string& beginWord,
                const unordered_map<string, vector<string>>& children,
                vector<string>& path, vector<vector<string>>& ans) {
    if (beginWord == endWord) {
      ans.push_back(path);
      return;
    }
    const auto it = children.find(beginWord);
    if (it == children.end()) return;

    for (const string& word : it->second) {
      path.push_back(word);
      getPaths(endWord, word, children, path, ans);
      path.pop_back();
    }
  }
};

class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return {};
    vector<vector<string>> ans;
    unordered_set<string> q{beginWord};
    unordered_set<string> p{endWord};
    int len = beginWord.length();
    unordered_map<string, vector<string>> children;
    bool found = false;
    bool backward = false;

    while (!found && !q.empty() && !p.empty()) {
      if (q.size() > p.size()) {
        swap(q, p);
        backward = !backward;
      }
      for (const string& word : q) {
        dict.erase(word);
      }
      for (const string& word : p) {
        dict.erase(word);
      }
      unordered_set<string> temp;
      for (const string& word : q) {
        string curr = word;
        for (int i = 0; i < len; ++i) {
          char ch = curr[i];
          for (int j = 'a'; j <= 'z'; ++j) {
            curr[i] = j;

            const string* parent = &word;
            const string* child = &curr;

            if (backward) {
              swap(parent, child);
            }
            if (p.count(curr)) {
              found = true;
              children[*parent].push_back(*child);
            } else if (dict.count(curr) && !found) {
              temp.insert(curr);
              children[*parent].push_back(*child);
            }
          }
          curr[i] = ch;
        }
      }
      swap(q, temp);
    }
    if (found) {
      vector<string> path{beginWord};
      getPaths(beginWord, endWord, children, path, ans);
    }
    return ans;
  }

 private:
  void getPaths(const string& word, const string& endWord,
                const unordered_map<string, vector<string>>& children,
                vector<string>& path, vector<vector<string>>& ans) {
    if (word == endWord) {
      ans.push_back(path);
      return;
    }
    const auto it = children.find(word);
    if (it == children.end()) return;

    for (const string& nword : it->second) {
      path.push_back(nword);
      getPaths(nword, endWord, children, path, ans);
      path.pop_back();
    }
  }
};
