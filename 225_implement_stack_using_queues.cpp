// Time : push O(n), pop O(1), top O(1)
// Space: O(n)

class MyStack {
 public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) {
    que.emplace(x);
    for (int i = 0; i < que.size() - 1; ++i) {
      que.emplace(que.front());
      que.pop();
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int front = que.front();
    que.pop();
    return front;
  }

  /** Get the top element. */
  int top() { return que.front(); }

  /** Returns whether the stack is empty. */
  bool empty() { return que.empty(); }

 private:
  queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */