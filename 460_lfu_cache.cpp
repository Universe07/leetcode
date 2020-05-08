class LFUCache {
  int cap;
  int size;
  int minFreq;
  unordered_map<int, pair<int, int>> m;
  unordered_map<int, list<int>::iterator> mIter;
  unordered_map<int, list<int>> fm;

 public:
  LFUCache(int capacity) : cap(capacity), size(0) {}

  int get(int key) {
    if (m.count(key) == 0) return -1;
    fm[m[key].second].erase(mIter[key]);
    m[key].second++;
    fm[m[key].second].push_back(key);
    mIter[key] = --fm[m[key].second].end();
    if (fm[minFreq].size() == 0) minFreq++;
    return m[key].first;
  }

  void put(int key, int value) {
    if (cap <= 0) return;
    int storedValue = get(key);
    if (storedValue != -1) {
      m[key].first = value;
      return;
    }
    if (size >= cap) {
      m.erase(fm[minFreq].front());
      mIter.erase(fm[minFreq].front());
      fm[minFreq].pop_front();
      size--;
    }
    m[key] = {value, 1};
    fm[1].push_back(key);
    mIter[key] = --fm[1].end();
    minFreq = 1;
    size++;
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LFUCache {
 public:
  LFUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    auto it = vals.find(key);
    if (it == vals.end()) {
      return -1;
    }

    freq_map[it->second.second].erase(key_iter[it->first]);
    it->second.second++;
    freq_map[it->second.second].push_back(it->first);
    key_iter[it->first] = --freq_map[it->second.second].end();

    if (freq_map[min_freq].size() == 0) {
      min_freq++;
    }

    return it->second.first;
  }

  void put(int key, int value) {
    if (this->capacity == 0) {
      return;
    }
    auto it = vals.find(key);
    if (it == vals.end()) {
      if (vals.size() == capacity) {
        int key = freq_map[min_freq].front();
        vals.erase(key);
        key_iter.erase(key);
        freq_map[min_freq].pop_front();
      }
      vals.insert({key, {value, 1}});

      freq_map[1].push_back(key);
      key_iter[key] = --freq_map[1].end();
      min_freq = 1;
    } else {
      get(key);
      it->second.first = value;
    }
  }

 private:
  unordered_map<int, pair<int, int>> vals;
  unordered_map<int, list<int>::iterator> key_iter;
  unordered_map<int, list<int>> freq_map;
  int min_freq = 0;
  int capacity;
};