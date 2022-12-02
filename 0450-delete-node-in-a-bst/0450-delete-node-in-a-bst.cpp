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
class Solution {
public:
    int minVal(TreeNode* root) {
        if (!root) return INT_MAX;
        int ans = min(minVal(root -> left), minVal(root -> right));
        return min(ans, root -> val);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root -> val < key) root -> right = deleteNode(root -> right, key);
        if (root -> val > key) root -> left = deleteNode(root -> left, key);
        if (root -> val == key) {
            if (root -> left == root -> right) return NULL;
            if (!root -> left) return root -> right;
            if (!root -> right) return root -> left;
            int nextValue = minVal(root -> right);
            root -> val = nextValue;
            root -> right = deleteNode(root -> right, nextValue);
        }
        return root;
    }
};