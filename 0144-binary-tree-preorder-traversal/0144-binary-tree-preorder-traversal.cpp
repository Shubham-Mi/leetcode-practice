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
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> ans;
        if (root == NULL) return ans;
        stack <TreeNode*> stk;
        TreeNode* curr = root;
        while (curr != NULL) {
            ans.push_back(curr -> val);
            if (curr -> right) stk.push(curr -> right);
            if (curr -> left) curr = curr -> left;
            else if (!stk.empty()) {
                curr = stk.top();
                stk.pop();
            }
            else curr = NULL;
        }
        return ans;
    }
};