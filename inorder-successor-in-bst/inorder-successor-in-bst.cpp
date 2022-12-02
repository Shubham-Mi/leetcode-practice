/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p -> right) {
            TreeNode* ans = p -> right;
            while (ans -> left) ans = ans -> left;
            return ans;
        }
        TreeNode* parent = NULL;
        TreeNode* curr = root;
        while (curr != p) {
            if (curr -> val > p -> val) {
                parent = curr;
                curr = curr -> left;
            } else {
                curr = curr -> right;
            }
        }
        return parent;
    }
};