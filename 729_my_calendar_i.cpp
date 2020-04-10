class MyCalendar {
 public:
  MyCalendar() {}

  bool book(int start, int end) {
    for (auto rec : record) {
      if (max(rec.first, start) < min(rec.second, end)) {
        return false;
      }
    }
    record.push_back({start, end});
    return true;
  }

 private:
  vector<pair<int, int>> record;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class MyCalendar {
 public:
  MyCalendar() {}

  bool book(int start, int end) {
    auto it = booked_.lower_bound(start);
    if (it != booked_.cend() && it->first < end) return false;
    if (it != booked_.cbegin() && (--it)->second > start) return false;
    booked_[start] = end;
    return true;
  }

 private:
  map<int, int> booked_;
};