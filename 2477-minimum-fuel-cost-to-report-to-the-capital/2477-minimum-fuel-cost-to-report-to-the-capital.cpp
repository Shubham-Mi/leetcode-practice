class Solution {
    vector <vector <int>> adj;
public:
    int dfs(int node, int parent, int seats, long long& ans) {
        int cars = 1;
        for (int next: adj[node]) {
            if (next != parent) cars += dfs(next, node, seats, ans);
        }
        if (node) {
            ans += cars / seats;
            if (cars % seats) ans++;
        }
        return cars;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        adj = vector <vector <int>> (n);
        for (vector <int> road: roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        long long ans = 0;
        dfs(0, -1, seats, ans);
        return ans;
    }
};