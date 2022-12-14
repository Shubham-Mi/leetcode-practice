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
    void inorder(TreeNode* root, vector <int>& ans) {
        if (!root) return;
        inorder(root -> left, ans);
        ans.push_back(root -> val);
        inorder(root -> right, ans);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        vector <vector <int>> ans;
        vector <int> arr;
        inorder(root, arr);
        for (int x: arr) {
            cout << x << " ";
        }
        cout << endl;
        for (int i=0; i<n; ++i) {
            int pos = lower_bound(arr.begin(), arr.end(), queries[i]) - arr.begin();
            cout << queries[i] << " " << pos << endl;
            if (pos == arr.size()) ans.push_back({arr[pos - 1], -1});
            else if (arr[pos] == queries[i]) ans.push_back({arr[pos], arr[pos]});
            else if (pos == 0) ans.push_back({-1, arr[0]});
            else ans.push_back({arr[pos - 1], arr[pos]});
        }
        return ans;
    }
};