class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<pair<int, int>> vec;
    vector<int> count;
    for (int i = 0; i < nums.size(); ++i) {
      vec.push_back(make_pair(nums[i], i));
      count.push_back(0);
    }
    mergeSort(vec, count);
    return count;
  }
  void mergeSort(vector<pair<int, int>>& vec, vector<int>& count) {
    if (vec.size() < 2) {
      return;
    }
    int mid = vec.size() / 2;
    vector<pair<int, int>> sub_vec1;
    vector<pair<int, int>> sub_vec2;
    for (int i = 0; i < mid; ++i) {
      sub_vec1.push_back(vec[i]);
    }
    for (int i = mid; i < vec.size(); ++i) {
      sub_vec2.push_back(vec[i]);
    }
    mergeSort(sub_vec1, count);
    mergeSort(sub_vec2, count);
    vec.clear();
    merge(sub_vec1, sub_vec2, vec, count);
  }
  void merge(vector<pair<int, int>>& sub_vec1, vector<pair<int, int>>& sub_vec2,
             vector<pair<int, int>>& vec, vector<int>& count) {
    int i = 0;
    int j = 0;
    while (i < sub_vec1.size() && j < sub_vec2.size()) {
      if (sub_vec1[i].first <= sub_vec2[j].first) {
        count[sub_vec1[i].second] += j;
        vec.push_back(sub_vec1[i]);
        i++;
      } else {
        vec.push_back(sub_vec2[j]);
        j++;
      }
    }
    for (; i < sub_vec1.size(); ++i) {
      count[sub_vec1[i].second] += j;
      vec.push_back(sub_vec1[i]);
    }
    for (; j < sub_vec2.size(); ++j) {
      vec.push_back(sub_vec2[j]);
    }
  }
};

class Solution {
 public:
  class BSTreeNode {
   public:
    int count, val;
    BSTreeNode* left;
    BSTreeNode* right;
    BSTreeNode(int count, int val) {
      this->count = count;
      this->val = val;
      this->left = this->right = nullptr;
    }
  };

  vector<int> countSmaller(vector<int>& nums) {
    vector<int> res(nums.size());
    BSTreeNode* root = nullptr;
    for (int i = nums.size() - 1; i >= 0; --i) {
      BSTreeNode* node = new BSTreeNode(0, nums[i]);
      root = insertNode(root, node);
      res[i] = query(root, nums[i]);
    }
    return res;
  }

  BSTreeNode* insertNode(BSTreeNode* root, BSTreeNode* node) {
    if (root == nullptr) {
      return node;
    }
    BSTreeNode* curr = root;
    while (curr) {
      if (node->val < curr->val) {
        ++curr->count;
        if (curr->left != nullptr) {
          curr = curr->left;
        } else {
          curr->left = node;
          break;
        }
      } else {
        if (curr->right != nullptr) {
          curr = curr->right;
        } else {
          curr->right = node;
          break;
        }
      }
    }
    return root;
  }

  int query(BSTreeNode* root, int val) {
    if (root == nullptr) {
      return 0;
    }
    int count = 0;
    BSTreeNode* curr = root;
    while (curr) {
      if (val < curr->val) {
        curr = curr->left;
      } else if (val > curr->val) {
        count += 1 + curr->count;
        curr = curr->right;
      } else {
        return count + curr->count;
      }
    }
    return 0;
  }
};