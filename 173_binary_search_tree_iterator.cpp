/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  stack<TreeNode*> myStack;

 public:
  BSTIterator(TreeNode* root) { pushAll(root); }

  /** @return the next smallest number */
  int next() {
    TreeNode* tmp = myStack.top();
    myStack.pop();
    pushAll(tmp->right);
    return tmp->val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !myStack.empty(); }

 private:
  void pushAll(TreeNode* node) {
    for (; node != nullptr; myStack.push(node), node = node->left)
      ;
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */