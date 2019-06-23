class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (max_heap.empty() || num > max_heap.top()) {
      min_heap.emplace(num);
      if (min_heap.size() > max_heap.size() + 1) {
        max_heap.emplace(min_heap.top());
        max_heap.pop();
      }
    } else {
      max_heap.emplace(num);
      if (max_heap.size() > min_heap.size()) {
        min_heap.emplace(max_heap.top());
        min_heap.pop();
      }
    }
  }

  double findMedian() {
    return min_heap.size() == max_heap.size()
               ? (min_heap.top() + max_heap.top()) / 2.0
               : min_heap.top();
  }

 private:
  priority_queue<int, vector<int>, greater<int>> min_heap;
  priority_queue<int, vector<int>> max_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */