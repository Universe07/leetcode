class Solution {
 public:
  string findReplaceString(string S, vector<int>& indexes,
                           vector<string>& sources, vector<string>& targets) {
    vector<pair<int, int>> sorted;
    for (int i = 0; i < indexes.size(); ++i) sorted.push_back({indexes[i], i});
    sort(sorted.rbegin(), sorted.rend());
    for (auto idx : sorted) {
      int i = idx.first;
      string s = sources[idx.second], t = targets[idx.second];
      if (S.substr(i, s.length()) == s) {
        S = S.substr(0, i) + t + S.substr(i + s.length());
      }
    }
    return S;
  }
};

// sort indexes in the descending order.Otherwise,
// we would have to maintain delta between original and replacement string
// length to adjust the next index.The complexity of this solution is O(n log n)
// | O(n),where n is the string size.
class Solution {
 public:
  string findReplaceString(string S, vector<int>& idx, vector<string>& src,
                           vector<string>& tg) {
    map<int, pair<int, string>, greater<int>> m;
    for (auto i = 0; i < idx.size(); ++i)
      if (S.compare(idx[i], src[i].size(), src[i]) == 0)
        m[idx[i]] = {src[i].size(), tg[i]};
    for (auto r : m) S.replace(r.first, r.second.first, r.second.second);
    return S;
  }
};

class Solution {
 public:
  string findReplaceString(string S, vector<int>& idx, vector<string>& src,
                           vector<string>& tg, string res = "") {
    vector<pair<int, string>> r(S.size());
    for (auto i = 0; i < idx.size(); ++i)
      if (S.compare(idx[i], src[i].size(), src[i]) == 0)
        r[idx[i]] = {src[i].size(), tg[i]};
    for (int i = 0; i < S.size(); ++i) {
      if (r[i].first == 0)
        res += S[i];
      else
        res += r[i].second, i += r[i].first - 1;
    }
    return res;
  }
};
// Complexity Analysis
// Runtime : O(n + m), where n is the size of the original string, and m is the
// size of all replacement strings. Memory: O(max(n, m)) to accommodate the
// resulting string.

class Solution {
 public:
  string findReplaceString(string S, vector<int>& idx, vector<string>& src,
                           vector<string>& tg, string res = "") {
    vector<pair<int, string>> r(S.size());
    for (auto i = 0; i < idx.size(); ++i)
      if (S.compare(idx[i], src[i].size(), src[i]) == 0)
        r[idx[i]] = {src[i].size(), tg[i]};
    for (int i = 0; i < S.size(); ++i) {
      if (r[i].first == 0)
        res += S[i];
      else
        res += r[i].second, i += r[i].first - 1;
    }
    return res;
  }
};