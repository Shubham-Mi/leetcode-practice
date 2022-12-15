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
    void inorder(TreeNode* root, vector <TreeNode*>& order) {
        if (!root) return;
        inorder(root -> left, order);
        order.push_back(root);
        inorder(root -> right, order);
    }
    TreeNode* balance(vector <TreeNode*>& arr, int l, int r) {
        if (l > r) return NULL;
        int mid = (l + r) / 2;
        TreeNode* root = arr[mid];
        root -> left = balance(arr, l, mid - 1);
        root -> right = balance(arr, mid + 1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector <TreeNode*> arr;
        inorder(root, arr);
        return balance(arr, 0, arr.size() - 1);
    }
};