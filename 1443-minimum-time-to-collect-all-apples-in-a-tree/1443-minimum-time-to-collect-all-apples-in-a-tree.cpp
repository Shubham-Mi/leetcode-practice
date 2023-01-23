class Solution {
    vector <vector <int>> adj;
    vector <bool> apples;
    vector <bool> visited;
public:
    bool dfs(int node, int& ans) {
        visited[node] = true;
        bool found = apples[node];
        for (int next: adj[node]) {
            if (!visited[next]) {
                bool curr = dfs(next, ans);
                if (curr) ans += 2;
                found = found || curr;
            }
        }
        return found;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int m = edges.size();
        visited = vector <bool> (n, false);
        adj = vector <vector <int>> (n);
        for (vector <int> edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        apples = hasApple;
        int ans = 0;
        dfs(0, ans);
        return ans;
    }
};