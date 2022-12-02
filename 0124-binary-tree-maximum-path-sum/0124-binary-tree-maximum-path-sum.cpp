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
    
    int findMax(TreeNode* root, int &ans) {
        if (root == NULL)
            return -40000000;
        
        int left_val = findMax(root -> left, ans);
        int right_val = findMax(root -> right, ans);
        ans = max(ans, root -> val);
        ans = max(ans, left_val + root -> val);
        ans = max(ans, right_val + root -> val);
        ans = max(ans, left_val + right_val + root -> val);
        
        int res = max(root -> val + left_val, root -> val + right_val);
        res = max(res, root -> val);
        return res;
    }
    
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        int curr = findMax(root, ans);
        return ans;
    }
};