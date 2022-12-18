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
    bool findAncestors(TreeNode* root, TreeNode* node, vector <TreeNode*>& ancestors) {
        if (!root) return false;
        if (root == node) {
            ancestors.push_back(root);
            return true;
        }
        ancestors.push_back(root);
        bool found = findAncestors(root -> left, node, ancestors) || findAncestors(root -> right, node, ancestors);
        if (!found) ancestors.pop_back();
        return found;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector <TreeNode*> pAncestors;
        findAncestors(root, p, pAncestors);
        vector <TreeNode*> qAncestors;
        findAncestors(root, q, qAncestors);
        TreeNode* ans = pAncestors[0];
        for (int i=0; i < pAncestors.size() && i < qAncestors.size(); ++i) {
            if (pAncestors[i] == qAncestors[i]) ans = pAncestors[i];
            else break;
        }
        return ans;
    }
};