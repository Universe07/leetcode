class TimeMap {
 public:
  /** Initialize your data structure here. */
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    tMap[key].emplace_back(make_pair(timestamp, value));
  }

  string get(string key, int timestamp) {
    if (!tMap.count(key)) {
      return "";
    }
    auto it = upper_bound(
        tMap[key].begin(), tMap[key].end(), make_pair(timestamp + 1, ""),
        [](const pair<int, string>& left, const pair<int, string>& right) {
          return left.first < right.first;
        });
    return it != tMap[key].cbegin() ? prev(it)->second : "";
  }

 private:
  unordered_map<string, vector<pair<int, string>>> tMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */