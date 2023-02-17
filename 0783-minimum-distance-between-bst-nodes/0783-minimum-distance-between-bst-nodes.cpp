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
    vector <int> findValues(TreeNode* root) {
        if (!root) return {INT_MIN, INT_MAX, INT_MAX};
        vector <int> leftValues = findValues(root -> left);
        vector <int> rightValues = findValues(root -> right);
        vector <int> ans;
        if (leftValues[0] == INT_MIN) ans.push_back(root -> val);
        else ans.push_back(leftValues[0]);
        if (rightValues[1] == INT_MAX) ans.push_back(root -> val);
        else ans.push_back(rightValues[1]);
        ans.push_back(INT_MAX);
        ans[2] = min(ans[2], leftValues[2]);
        ans[2] = min(ans[2], rightValues[2]);
        if (leftValues[1] != INT_MAX) ans[2] = min(ans[2], root -> val - leftValues[1]);
        if (rightValues[0] != INT_MIN) ans[2] = min(ans[2], rightValues[0] - root -> val);
        return ans;
    }
    
    int minDiffInBST(TreeNode* root) {
        // ans -> {minimum value in subtree, maximum value in subtree, minimum answer till root}
        vector <int> ans = findValues(root);
        return ans[2];
    }
};