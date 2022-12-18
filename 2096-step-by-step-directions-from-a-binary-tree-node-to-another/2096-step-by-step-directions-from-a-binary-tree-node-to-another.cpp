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
    bool findAncestors(TreeNode* root, int value, vector <pair <int, int>>& ancestors) {
        if (!root) return false;
        if (root -> val == value) {
            ancestors.push_back({root -> val, 0});
            return true;
        }
        bool left = findAncestors(root -> left, value, ancestors);
        if (left) {
            ancestors.push_back({root -> val, 1});
            return true;
        }
        bool right = findAncestors(root -> right, value, ancestors);
        if (right) {
            ancestors.push_back({root -> val, 2});
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector <pair <int, int>> startAncestors;
        findAncestors(root, startValue, startAncestors);
        reverse(startAncestors.begin(), startAncestors.end());
        vector <pair <int, int>> destAncestors;
        findAncestors(root, destValue, destAncestors);
        reverse(destAncestors.begin(), destAncestors.end());
        int n = startAncestors.size();
        int m = destAncestors.size();
        int ptr = 0;
        while (ptr < n && ptr < m) {
            if (ptr < n - 1 && ptr < m - 1 && startAncestors[ptr + 1].first == destAncestors[ptr + 1].first) ptr++;
            else break;
        }
        string ans;
        for (int i=n-1; i>ptr; --i) ans += 'U';
        for (int i=ptr; i<m-1; ++i) {
            if (destAncestors[i].second == 1) ans += 'L';
            else ans += 'R';
        }
        return ans;
    }
};