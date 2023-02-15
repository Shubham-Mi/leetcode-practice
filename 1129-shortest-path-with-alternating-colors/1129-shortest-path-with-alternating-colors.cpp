class Solution {
    vector <vector <int>> adjRed, adjBlue;
public:
    void bfs(int n, int color, vector <int>& ans) {
        ans[0] = 0;
        // first -> last edge was red
        // second -> last edge was blue
        vector <pair <bool, bool>> visited(n, {false, false});
        queue <int> q;
        q.push(0);
        q.push(-1);
        int count = 1;
        while (q.size() > 1) {
            int curr = q.front();
            q.pop();
            if (curr == -1) {
                q.push(-1);
                color = 1 - color;
                count++;
                continue;
            }
            if (color) {
                for (auto next: adjRed[curr]) {
                    if (!visited[next].first) {
                        ans[next] = min(ans[next], count);
                        visited[next].first = true;
                        q.push(next);
                    }
                }
            } else {
                for (auto next: adjBlue[curr]) {
                    if (!visited[next].second) {
                        ans[next] = min(ans[next], count);
                        visited[next].second = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        adjRed = vector <vector <int>> (n);
        adjBlue = vector <vector <int>> (n);
        vector <int> ans(n, INT_MAX);
        for (auto edge: redEdges) {
            adjRed[edge[0]].push_back(edge[1]);
        }
        for (auto edge: blueEdges) {
            adjBlue[edge[0]].push_back(edge[1]);
        }
        bfs(n, 0, ans);
        bfs(n, 1, ans);
        for (auto &x: ans) {
            if (x == INT_MAX) x = -1;
        }
        return ans;
    }
};