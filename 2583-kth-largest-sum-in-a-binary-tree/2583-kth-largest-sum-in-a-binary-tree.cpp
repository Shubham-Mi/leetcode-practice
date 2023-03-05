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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector <long long> sums;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        long long sum = 0;
        while (q.size() > 1) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL) {
                q.push(NULL);
                sums.push_back(sum);
                sum = 0LL;
                continue;
            }
            sum = 1LL * (sum + curr -> val);
            if (curr -> left) q.push(curr -> left);
            if (curr -> right) q.push(curr -> right);
        }
        sums.push_back(sum);
        if (sums.size() < k) return -1;
        sort(sums.rbegin(), sums.rend());
        return sums[k - 1];
    }
};