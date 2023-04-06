class Solution {
public:
    void dfs (vector <vector <int>> &grid, int n, int m, int x, int y) {
        grid[x][y] = 1;
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        for (int i=0; i<4; ++i) {
            int r = x + row[i];
            int c = y + col[i];
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 0) {
                dfs(grid, n, m, r, c);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i=0; i<n; ++i) {
            if (grid[i][0] == 0) dfs(grid, n, m, i, 0);
            if (grid[i][m - 1] == 0) dfs(grid, n, m, i, m - 1);
        }
        for (int i=0; i<m; ++i) {
            if (grid[0][i] == 0) dfs(grid, n, m, 0, i);
            if (grid[n - 1][i] == 0) dfs(grid, n, m, n - 1, i);
        }
        int ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j] == 0) {
                    ans++;
                    dfs(grid, n, m, i, j);
                }
            }
        }
        return ans;
    }
};