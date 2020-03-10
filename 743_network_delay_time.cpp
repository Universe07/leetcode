// Time: O(NE)
// Space: O(N)

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    constexpr int max_time = 101 * 100;
    vector<int> dist(N, max_time);
    dist[K - 1] = 0;
    for (int i = 1; i < N; ++i) {
      for (const auto& time : times) {
        int u = time[0] - 1, v = time[1] - 1, w = time[2];
        dist[v] = min(dist[v], dist[u] + w);
      }
    }
    int max_dist = *max_element(dist.begin(), dist.end());
    return max_dist == max_time ? -1 : max_dist;
  }
};