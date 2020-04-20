class Solution {
 public:
  int checkRecord(int n) {
    if (n == 1) return 3;
    int kMod = 1000000007;
    int *ab = new int[n];
    int *pre = new int[n];
    int *la = new int[n];
    pre[0] = 1;
    la[0] = 1;
    la[1] = 3;
    ab[0] = 1;
    ab[1] = 2;
    if (n > 2) ab[2] = 4;
    for (int i = 1; i < n; ++i) {
      ab[i - 1] %= kMod;
      pre[i - 1] %= kMod;
      la[i - 1] %= kMod;
      pre[i] = ((ab[i - 1] + pre[i - 1]) % kMod + la[i - 1]) % kMod;
      if (i > 1)
        la[i] = ((ab[i - 1] + pre[i - 1]) % kMod +
                 (ab[i - 2] + pre[i - 2]) % kMod) %
                kMod;
      if (i > 2) ab[i] = ((ab[i - 1] + ab[i - 2]) % kMod) + ab[i - 3] % kMod;
    }
    return ((ab[n - 1] % kMod + pre[n - 1] % kMod) % kMod + la[n - 1] % kMod) %
           kMod;
  }
};