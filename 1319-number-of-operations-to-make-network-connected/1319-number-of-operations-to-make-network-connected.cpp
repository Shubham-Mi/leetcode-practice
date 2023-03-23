class Solution {
public:
    void dfs(vector <vector <int>>& adj, vector <bool>& visited, int x) {
        visited[x] = true;
        for (auto &a: adj[x]) {
            if (!visited[a]) dfs(adj, visited, a);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < n - 1) return -1;
        vector <vector <int>> adj(n);
        for (auto connection: connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        int count = 0;
        vector <bool> visited(n, false);
        for (int i=0; i<n; ++i) {
            if (visited[i] == false) {
                count++;
                dfs(adj, visited, i);
            }
        }
        return count - 1;
    }
};