// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
 public:
  int search(const ArrayReader& reader, int target) {
    int left = 0, right = 19999;
    while (left < right) {
      auto mid = left + (right - left) / 2;
      auto midnum = reader.get(mid);
      if (midnum == target) {
        return mid;
      } else if (midnum > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
 public:
  int search(const ArrayReader& reader, int target) {
    int start = 0, end = 1;
    while (reader.get(end) != 2147483647) {
      start = end;
      end = end * 100;
    }
    while (start < end) {
      int mid = start + (end - start) / 2;
      if (reader.get(mid) == 2147483647) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    end = start;
    start = 0;
    while (start < end) {
      int mid = start + (end - start) / 2;
      if (reader.get(mid) == target) {
        return mid;
      } else if (reader.get(mid) > target) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    return -1;
  }
};