class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int directions[5] = {0, 1, 0, -1, 0};
        vector <vector <bool>> visited(n, vector <bool> (m, false));
        queue <pair <int, int>> q;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        q.push({-1, -1});
        int dist = 1;
        while (q.size() > 1) {
            pair <int, int> p = q.front();
            q.pop();
            if (p.first == -1) {
                dist++;
                q.push({-1, -1});
                continue;
            }
            for (int i=0; i<4; ++i) {
                int x = p.first + directions[i];
                int y = p.second + directions[i + 1];

                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    visited[x][y] = true;
                    mat[x][y] = dist;
                    q.push({x, y});
                }
            }
        }
        return mat;
    }
};