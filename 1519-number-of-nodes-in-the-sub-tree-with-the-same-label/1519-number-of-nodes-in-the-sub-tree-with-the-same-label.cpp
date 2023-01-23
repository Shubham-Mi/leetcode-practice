class Solution {
    vector <vector <int>> adj;
public:
    vector<int> dfs(int node, int parent, string& labels, vector<int>& ans) {
        vector<int> nodeCounts(26);
        nodeCounts[labels[node] - 'a'] = 1;
        for (auto& child : adj[node]) {
            if (child == parent) continue;
            vector<int> childCounts = dfs(child, node, labels, ans);
            for (int i=0; i<26; ++i) nodeCounts[i] += childCounts[i];
        }
        ans[node] = nodeCounts[labels[node] - 'a'];
        return nodeCounts;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj = vector <vector <int>> (n);
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector <int> ans(n, 1);
        dfs(0, -1, labels, ans);
        return ans;
    }
};