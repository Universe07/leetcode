class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }
    int num = n / 2;
    vector<bool> isPrime(n + 1, true);
    for (int i = 3; i * i < n; i += 2) {
      if (!isPrime[i]) {
        continue;
      }
      for (int j = i * i; j < n; j += 2 * i) {
        if (!isPrime[j]) {
          continue;
        }
        --num;
        isPrime[j] = false;
      }
    }
    return num;
  }
};