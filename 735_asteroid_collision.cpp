class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> s;
    for (int i = 0; i < asteroids.size(); ++i) {
      if (asteroids[i] > 0 || s.empty() || s.back() < 0)
        s.push_back(asteroids[i]);
      else if (s.back() <= -asteroids[i]) {
        if (s.back() < -asteroids[i]) i--;
        s.pop_back();
      }
    }
    return s;
  }
};