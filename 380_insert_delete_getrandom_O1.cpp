class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (map_.count(val)) {
      return false;
    } else {
      set_.push_back(val);
      map_[val] = set_.size() - 1;
      return true;
    }
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (!map_.count(val)) {
      return false;
    }
    map_[set_.back()] = map_[val];
    swap(set_[map_[val]], set_.back());

    map_.erase(val);
    set_.pop_back();
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() { return set_[rand() % set_.size()]; }

 private:
  vector<int> set_;
  unordered_map<int, int> map_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */