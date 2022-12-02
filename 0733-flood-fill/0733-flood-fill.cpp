class Solution {
    int n, m;
    vector <vector <int>> image;
    int directions[5] = {0, 1, 0, -1, 0};
public:
    void dfs(int i, int j, int oldColor, int newColor) {
        image[i][j] = newColor;
        for (int k=0; k<4; ++k) {
            int x = i + directions[k];
            int y = j + directions[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < m && image[x][y] == oldColor) {
                dfs(x, y, oldColor, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        this->image = image;
        n = image.size();
        m = image[0].size();
        dfs(sr, sc, image[sr][sc], color);
        return this->image;
    }
};