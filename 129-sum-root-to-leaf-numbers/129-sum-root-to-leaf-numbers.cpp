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
    void find(TreeNode* root, int curr, int &ans) {
        curr = curr * 10 + root -> val;
        if (root -> left == root -> right) ans += curr;
        if (root -> left) find(root -> left, curr, ans);
        if (root -> right) find(root -> right, curr, ans);
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        find(root, 0, ans);
        return ans;
    }
};