/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    vector <int> values;
    int curr;
    int size;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> ans;
        if (!root) return ans;
        stack <TreeNode*> stk;
        TreeNode* curr = root;
        while (curr != NULL || !stk.empty()) {
            while (curr != NULL) {
                stk.push(curr);
                curr = curr -> left;
            }
            curr = stk.top();
            stk.pop();
            ans.push_back(curr -> val);
            curr = curr -> right;
        }
        return ans;
    }

    BSTIterator(TreeNode* root) {
        values = inorderTraversal(root);
        curr = 0;
        size = values.size();
    }
    
    int next() {
        return values[curr++];
    }
    
    bool hasNext() {
        return curr != size;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */