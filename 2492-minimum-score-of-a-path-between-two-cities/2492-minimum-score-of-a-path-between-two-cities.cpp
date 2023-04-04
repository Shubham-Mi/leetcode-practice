class Solution {
public:
    void dfs(int node, vector <vector <pair <int, int>>>& adj, vector <bool>& visited, int& ans) {
        visited[node] = true;
        for (pair <int, int> next: adj[node]) {
            ans = min(ans, next.second);
            if (!visited[next.first]) dfs(next.first, adj, visited, ans);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector <vector <pair <int, int>>> adj(n + 1);
        for (vector <int> road: roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        vector <bool> visited(n + 1, false);
        int ans = INT_MAX;
        dfs(1, adj, visited, ans);
        return ans;
    }
};