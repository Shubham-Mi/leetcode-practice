class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt = 0;
        queue <pair <int, int>> q;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    q.push(make_pair(i, j));
                    cnt++;
                }
            }
        }
        if (cnt == 0 || cnt == (n * n)) return -1;
        int dir[5] = {0, 1, 0, -1, 0};
        q.push(make_pair(-1, -1));
        int ans = 0;
        while (q.size() > 1) {
            pair <int, int> p = q.front();
            q.pop();
            if (p.first == -1) {
                ans++;
                q.push(make_pair(-1, -1));
            }
            for (int i=0; i<4; ++i) {
                int r = p.first + dir[i];
                int c = p.second + dir[i + 1];
                if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0) {
                    grid[r][c] = 1;
                    q.push(make_pair(r, c));
                }
            }
        }
        return ans;
    }
};