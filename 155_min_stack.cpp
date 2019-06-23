// Time: O(1)
// Space : O(n)

class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    stk.push(x);
    if (minS.empty()) {
      minS.push(x);
    } else {
      if (x > minS.top()) {
        x = minS.top();
      }
      minS.push(x);
    }
  }

  void pop() {
    stk.pop();
    minS.pop();
  }

  int top() { return stk.top(); }

  int getMin() { return minS.top(); }

 private:
  stack<int> stk;
  stack<int> minS;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */