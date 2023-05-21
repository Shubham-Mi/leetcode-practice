class Solution {
    int directions[5] = {0, 1, 0, -1, 0};
public:
    bool validate(int x, int y, int n) {
        if (x >= 0 && x < n && y >= 0 && y < n) return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid, int n, int r, int c) {
        grid[r][c] = 2;
        for (int i=0; i<4; ++i) {
            int x = r + directions[i];
            int y = c + directions[i + 1];
            if (validate(x, y, n) && grid[x][y] == 1) dfs(grid, n, x, y);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool found = false;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, n, i, j);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        queue <pair <int, int>> q;
        vector <vector <bool>> visited(n, vector <bool> (n, false));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        q.push({-1, -1});
        int ans = 0;
        while (q.size() > 1) {
            pair <int, int> p = q.front();
            q.pop();
            if (p.first == -1) {
                ans++;
                q.push({-1, -1});
                continue;
            }
            if (grid[p.first][p.second] == 2) return ans - 1;
            for (int i=0; i<4; i++) {
                int x = p.first + directions[i];
                int y = p.second + directions[i + 1];
                if (validate(x, y, n) && visited[x][y] == false) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return -1;
    }
};