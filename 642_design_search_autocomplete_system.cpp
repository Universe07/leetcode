// AutocompleteSystem() takes O(k*l)O(k∗l) time. We need to iterate over ll
// sentences each of average length kk, to create the trie for the given set of
// sentencessentences.

// input() takes O\big(p+q+m \log m\big)O(p+q+mlogm) time. Here, pp refers to
// the length of the sentence formed till now, \text{cur\_sent}cur_sent. qq
// refers to the number of nodes in the trie considering the sentence formed
// till now as the root node. Again, we need to sort the listlist of length mm
// indicating the options available for the hot sentences, which takes O\big(m
// \log m\big)O(mlogm) time.

class AutocompleteSystem {
  class TrieNode {
   public:
    unordered_map<char, TrieNode*> child;
    string str;
    int count;
    TrieNode() : str(""), count(0){};
  };
  void insert(string& s, TrieNode* root, int times) {
    TrieNode* curr = root;
    for (int i = 0; i < s.size(); i++) {
      if (!curr->child.count(s[i])) curr->child[s[i]] = new TrieNode();
      curr = curr->child[s[i]];
    }
    curr->count += times;
    curr->str = s;
  }

 public:
  void dfs(TrieNode* temp) {
    if (temp->str != "") q.push({temp->str, temp->count});
    for (auto& ele : temp->child) {
      dfs(ele.second);
    }
  }
  TrieNode *root, *curr;
  struct cmp {
    bool operator()(pair<string, int>& a, pair<string, int>& b) {
      return a.second < b.second || a.second == b.second && a.first > b.first;
    }
  };
  priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> q;
  AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
    root = new TrieNode();
    for (int i = 0; i < sentences.size(); ++i) {
      insert(sentences[i], root, times[i]);
    }
    curr = root;
  }

  string s = "";
  vector<string> input(char c) {
    q = priority_queue<pair<string, int>, vector<pair<string, int>>, cmp>();
    if (c == '#') {
      insert(s, root, 1);
      s = "";
      curr = root;
      return {};
    }
    s += c;
    if (curr && curr->child.count(c)) {
      curr = curr->child[c];
    } else {
      curr = NULL;
      return {};
    }
    if (curr->str != "") q.push({curr->str, curr->count});
    for (auto& ele : curr->child) {
      dfs(ele.second);
    }
    vector<string> res;
    while (!q.empty() && res.size() < 3) {
      res.push_back(q.top().first);
      q.pop();
    }
    return res;
  }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */