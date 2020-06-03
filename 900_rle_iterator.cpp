class RLEIterator {
 public:
  vector<int> A;
  int cur = 0;
  RLEIterator(vector<int>& A) { this->A = A; }

  int next(int n) {
    int num = 0;
    while (n > 0) {
      if (cur >= A.size()) return -1;
      n = n - A[cur];
      if (n <= 0) {
        num = A[cur + 1];
        A[cur] = -n;
      } else {
        cur += 2;
      }
    }
    return num;
  }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */