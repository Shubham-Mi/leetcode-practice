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
    void check(TreeNode * root, int mn, int mx, int& ans) {
        if (!root) return;
        ans = max(ans, abs(mx - root -> val));
        ans = max(ans, abs(root -> val - mn));
        check(root -> left, min(mn, root -> val), max(mx, root -> val), ans);
        check(root -> right, min(mn, root -> val), max(mx, root -> val), ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        check(root -> left, root -> val, root -> val, ans);
        check(root -> right, root -> val, root -> val, ans);
        return ans;
    }
};