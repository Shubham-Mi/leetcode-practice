class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector <vector <int>> rowsLeft(n, vector <int> (m, 0));
        vector <vector <int>> rowsRight(n, vector <int> (m, 0));
        vector <vector <int>> colsTop(n, vector <int> (m, 0));
        vector <vector <int>> colsBottom(n, vector <int> (m, 0));

        for (int i=0; i<n; ++i) {
            if (grid[i][0] == 'E') rowsLeft[i][0]++;
            if (grid[i][m - 1] == 'E') rowsRight[i][m - 1]++;
        }
        for (int j=0; j<m; ++j) {
            if (grid[0][j] == 'E') colsTop[0][j]++;
            if (grid[n - 1][j] == 'E') colsBottom[n - 1][j]++;
        }
        
        for (int i=1; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j] == 'E') colsTop[i][j] = colsTop[i - 1][j] + 1;
                else if (grid[i][j] == '0') colsTop[i][j] = colsTop[i - 1][j];
            }
        }
        for (int i=n-2; i>=0; --i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j] == 'E') colsBottom[i][j] = colsBottom[i + 1][j] + 1;
                else if (grid[i][j] == '0') colsBottom[i][j] = colsBottom[i + 1][j];
            }
        }
        for (int j=1; j<m; ++j) {
            for (int i=0; i<n; ++i) {
                if (grid[i][j] == 'E') rowsLeft[i][j] = rowsLeft[i][j - 1] + 1;
                else if (grid[i][j] == '0') rowsLeft[i][j] = rowsLeft[i][j - 1];
            }
        }
        for (int j=m-2; j>=0; --j) {
            for (int i=0; i<n; ++i) {
                if (grid[i][j] == 'E') rowsRight[i][j] = rowsRight[i][j + 1] + 1;
                else if (grid[i][j] == '0') rowsRight[i][j] = rowsRight[i][j + 1];
            }
        }
        int ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                int curr = 0;
                if (grid[i][j] == '0') {
                    if (i > 0) curr += colsTop[i - 1][j];
                    if (i < n - 1) curr += colsBottom[i + 1][j];
                    if (j > 0) curr += rowsLeft[i][j - 1];
                    if (j < m - 1) curr += rowsRight[i][j + 1];
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};