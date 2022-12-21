class Solution {
    vector <vector <int>> adj;
    vector <int> visited;
public:
    bool dfs(int x, int color) {
        visited[x] = color;
        for (int next: adj[x]) {
            if (visited[next] == color) return false;
            if (visited[next] == -1 && !dfs(next, 1 - color)) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        adj = vector <vector <int>> (n + 1);
        visited = vector <int> (n + 1, -1);
        int m = dislikes.size();
        for (int i=0; i<m; ++i) {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for (int i=1; i<=n; ++i) {
            if (visited[i] == -1) {
                if (!dfs(i, 0)) return false;
            }
        }
        return true;
    }
};