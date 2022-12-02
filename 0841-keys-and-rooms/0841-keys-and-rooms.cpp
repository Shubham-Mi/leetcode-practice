class Solution {
    vector <bool> visited;
    vector <vector <int>> adj;
public:
    void dfs(int i) {
        visited[i] = true;
        for (int next: adj[i]) {
            if (!visited[next]) dfs(next);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        adj= rooms;
        visited = vector <bool> (n, false);
        dfs(0);
        for (int i=0; i<n; ++i) {
            if (!visited[i]) return false;
        }
        return true;
    }
};