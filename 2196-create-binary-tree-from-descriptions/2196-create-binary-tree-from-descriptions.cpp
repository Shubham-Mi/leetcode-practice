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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        if (n == 0) return NULL;
        unordered_map <int, TreeNode*> mp;
        unordered_map <TreeNode*, bool> roots;
        for (int i=0; i<n; ++i) {
            if (mp.find(descriptions[i][0]) == mp.end()) {
                mp[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
            }
            if (mp.find(descriptions[i][1]) == mp.end()) {
                mp[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
            }
            TreeNode* parent = mp[descriptions[i][0]];
            TreeNode* child = mp[descriptions[i][1]];
            if (descriptions[i][2]) parent -> left = child;
            else parent -> right = child;
            if (roots.find(parent) == roots.end() || roots[parent]) roots[parent] = true;
            roots[child] = false;
        }
        TreeNode* root = NULL;
        for (auto r: roots) {
            if (r.second == true) {
                root = r.first;
                break;
            }
        }
        return root;
    }
};