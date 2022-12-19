class Solution {
    vector <vector <int>> adj;
    vector <bool> visited;
public:
    bool check(int curr, int dest) {
        if (curr == dest) return true;
        visited[curr] = true;
        bool ans = false;
        for (int next: adj[curr]) {
            if (!visited[next]) ans = check(next, dest);
            if (ans) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj = vector <vector <int>> (n);
        visited = vector <bool> (n, false);
        int m = edges.size();
        for (int i=0; i<m; ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return check(source, destination);
    }
};