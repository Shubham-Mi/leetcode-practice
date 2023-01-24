class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector <vector <int>> ans(n, vector <int> (n, 0));
        for (int i=0; i<m; ++i) {
            int rowst = queries[i][0];
            int colst = queries[i][1];
            int rowed = queries[i][2];
            int coled = queries[i][3];
            for (int j=rowst; j<=rowed; ++j) {
                ans[j][colst]++;
                if (coled < n-1) ans[j][coled + 1]--;
            }
        }
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (j > 0) ans[i][j] += ans[i][j - 1];
        return ans;
    }
};