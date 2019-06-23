// Time: O(1)
// Space: O(n)

class MyQueue {
 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { stkA.emplace(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int val = peek();
    stkB.pop();
    return val;
  }

  /** Get the front element. */
  int peek() {
    if (stkB.empty()) {
      while (!stkA.empty()) {
        stkB.emplace(stkA.top());
        stkA.pop();
      }
    }
    if (stkB.empty()) {
      throw length_error("empty queue");
    }
    return stkB.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return stkA.empty() && stkB.empty(); }

 private:
  stack<int> stkA, stkB;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */