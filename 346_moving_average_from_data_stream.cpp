class MovingAverage {
 public:
  /** Initialize your data structure here. */
  MovingAverage(int size) : fullSize(size), sum(0.0) {}

  double next(int val) {
    sum += val;
    que.push(val);
    int cnt = que.size();
    if (cnt <= fullSize) {
      return sum / cnt;
    } else {
      sum -= que.front();
      que.pop();
      return sum / que.size();
    }
  }

 private:
  queue<int> que;
  int fullSize;
  double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */