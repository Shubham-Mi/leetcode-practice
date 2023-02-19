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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int>> ans;
        vector <int> temp;
        if (root == NULL) return ans;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (q.size() > 1) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL) {
                ans.push_back(temp);
                temp.clear();
                q.push(NULL);
                continue;
            }
            temp.push_back(curr -> val);
            if (curr -> left) q.push(curr -> left);
            if (curr -> right) q.push(curr -> right);
        }
        ans.push_back(temp);
        int n = ans.size();
        for (int i=1; i<n; i+=2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};