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
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int ptr = 0;
        // Creating the root node
        int root = 0;
        while (ptr < n && traversal[ptr] >= '0' && traversal[ptr] <= '9') {
            int curr = traversal[ptr] - '0';
            ptr++;
            root = (root * 10) + curr;
        }
        TreeNode* rootNode = new TreeNode(root);
        // level: {Node, left(0)/right(1)}
        unordered_map <int, pair <TreeNode*, int>> mp;
        mp[0] = {rootNode, 0};
        while (ptr < n) {
            // level = no of "-"
            int level = 0;
            while (ptr < n && traversal[ptr] == '-') {
                level++;
                ptr++;
            }
            // Getting the parent node
            pair <TreeNode*, int> p = mp[level - 1];
            // Getting the new node's value
            int val = 0;
            while (ptr < n && traversal[ptr] >= '0' && traversal[ptr] <= '9') {
                int curr = traversal[ptr] - '0';
                ptr++;
                val = (val * 10) + curr;
            }
            TreeNode* newNode = new TreeNode(val);

            if (p.second == 0) {
                // New node is the left node
                p.first -> left = newNode;
                mp[level - 1].second = 1;
            } else {
                // New node is the right node
                p.first -> right = newNode;
            }
            // Updating the level node
            mp[level] = {newNode, 0};
        }
        return rootNode;
    }
};