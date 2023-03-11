class Solution {
    vector <vector <int>> children;
    vector <int> paths;
public:
    int dfs(int node, string& s) {
        vector <int> child;
        for (int next: children[node]) {
            int val = dfs(next, s);
            if (s[node] != s[next]) child.push_back(val);
        }
        sort(child.begin(), child.end());
        int m = child.size();
        paths[node] = 1;
        int mx = 0;
        if (m > 0) {
            paths[node] += child[m - 1];
            mx = max(mx, child[m - 1]);
        }
        if (m > 1) {
            paths[node] += child[m - 2];
            mx = max(mx, child[m - 2]);
        }
        return 1 + mx;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        children = vector <vector <int>> (n);
        paths = vector <int> (n, 1);
        for (int i=1; i<n; ++i) {
            children[parent[i]].push_back(i);
        }
        dfs(0, s);
        int ans = 0;
        for (int p: paths) ans = max(ans, p);
        return ans;
    }
};