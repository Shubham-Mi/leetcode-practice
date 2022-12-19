class Solution {
    int n, m;
    int directions[5] = {0, 1, 0, -1, 0};
    vector <vector <char>> board;
public:
    void markCornerRegions(int i, int j) {
        board[i][j] = 'A';
        for (int k=0; k<4; ++k) {
            int x = i + directions[k];
            int y = j + directions[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O') markCornerRegions(x, y);
        }
    }
    void solve(vector<vector<char>>& matrix) {
        board = matrix;
        n = board.size();
        m = board[0].size();
        for (int i=0; i<n; ++i) {
            if (board[i][0] == 'O') markCornerRegions(i, 0);
            if (board[i][m - 1] == 'O') markCornerRegions(i, m - 1);
        }
        for (int i=0; i<m; ++i) {
            if (board[0][i] == 'O') markCornerRegions(0, i);
            if (board[n - 1][i] == 'O') markCornerRegions(n - 1, i);
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (board[i][j] != 'A') board[i][j] = 'X';
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
        matrix = board;
    }
};