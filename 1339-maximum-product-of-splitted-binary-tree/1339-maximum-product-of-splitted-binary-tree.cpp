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
    int totalSum (TreeNode* root) {
        if (!root) return 0;
        return root -> val + totalSum(root -> left) + totalSum(root -> right);
    }
    int findProduct(TreeNode* root, int sum, long long int& ans) {
        if (!root) return 0;
        int left = findProduct(root -> left, sum, ans);
        int right = findProduct(root -> right, sum, ans);
        ans = max(ans, (1LL) * left * (sum - left));
        ans = max(ans, (1LL)* right * (sum - right));
        return left + right + root -> val;
    }
    int maxProduct(TreeNode* root) {
        int sum = totalSum(root);
        long long int ans = 0;
        findProduct(root, sum, ans);
        int mod = 1e9+7;
        ans = ans % mod;
        return ans;
    }
};