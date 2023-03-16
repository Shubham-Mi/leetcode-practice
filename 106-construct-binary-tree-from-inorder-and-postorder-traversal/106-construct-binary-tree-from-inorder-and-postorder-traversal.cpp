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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int in_st, int in_end, int post_st, int post_end) {
        if (in_st > in_end) return NULL;
        TreeNode* root = new TreeNode(postorder[post_end]);
        int found = in_st;
        for (int i=in_st; i<=in_end; ++i) {
            if (inorder[i] == postorder[post_end]) {
                found = i;
                break;
            }
        }
        root -> left = build(inorder, postorder, in_st, found - 1, post_st, post_st + found - in_st - 1);
        root -> right = build(inorder, postorder, found + 1, in_end, post_st + found - in_st, post_end - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};