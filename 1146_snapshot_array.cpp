// Explanation: The idea is, the whole array can be large, and we may take the
// snap tons of times.(Like you may always ctrl + S twice). Instead of record
// the history of the whole array, we will record the history of each cell. And
// this is the minimum space that we need to record all information. For each
// A[i], we will record its history.With a snap_id and a its value.
// When we want to get the value in history, just binary search the time point.
// Complexity Time O(logS) Space O(S) where S is the number of set called.
// SnapshotArray(int length) is O(N) time
// set(int index, int val) is O(1) in Python and O(logSnap) in Java
// snap() is O(1) get(int index,int snap_id) is O(logSnap)

class SnapshotArray {
 public:
  SnapshotArray(int length) {
    for (int i = 0; i < length; ++i) {
      map<int, int> mp;
      mp[0] = 0;
      snaps[i] = mp;
    }
  }

  void set(int index, int val) { snaps[index][snapId] = val; }

  int snap() { return snapId++; }

  int get(int index, int snap_id) {
    auto it = snaps[index].upper_bound(snap_id);
    it--;
    return it->second;
  }

 private:
  map<int, map<int, int>> snaps;
  int snapId = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */