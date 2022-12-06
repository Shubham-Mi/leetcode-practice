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
    int ans;
public:
    int postorder(TreeNode* root) {
        if (!root) return 0;
        int left = postorder((root -> left));
        int right = postorder((root -> right));
        int sum = left + right;
        if (root -> val > 0) sum += (root -> val - 1);
        else sum--;
        ans += abs(sum);
        return sum;
    }
    int distributeCoins(TreeNode* root) {
        ans = 0;
        int remaining = postorder(root);
        return ans;
    }
};