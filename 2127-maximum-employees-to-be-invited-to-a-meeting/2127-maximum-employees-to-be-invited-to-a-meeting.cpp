class Solution {
    int n;
    vector <vector <int>> adj;
    vector <int> visited, indegree, depth, len;
public:
    void cycle (int i, int d, int& start, int& end, int& cycleLen) {
        visited[i] = true;
        depth[i] = d;
        for (int next: adj[i]) {
            if (visited[next] == 1) {
                cycleLen = max(cycleLen, depth[i] - depth[next] + 1);
                start = i;
                end = next;
            } else if (visited[next] == 0){
                cycle(next, d + 1, start, end, cycleLen);
            }
        }
        visited[i] = 2;
    }
    int maximumInvitations(vector<int>& favorite) {
        n = favorite.size();
        adj = vector <vector <int>> (n + 1);
        visited = vector <int> (n + 1, 0);
        indegree = vector <int> (n + 1, 0);
        depth = vector <int> (n + 1, 0);
        len = vector <int> (n + 1, 0);
        for (int i=0; i<n; ++i) {
            adj[i].push_back(favorite[i]);
            indegree[favorite[i]]++;
        }
        queue <int> q;
        for (int i=0; i<n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = 1;
            for (int next: adj[curr]) {
                len[next] = len[curr] + 1;
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }
        int largestCycle = 0;
        int twoCycleAndLen = 0;
        for (int i=0; i<n; ++i) {
            if (visited[i] == 0) {
                int start = -1, end = -1, cycleLen = 0;
                cycle(i, 0, start, end, cycleLen);
                if (cycleLen == 2) {
                    twoCycleAndLen += (2 + len[start] + len[end]);
                } else {
                    largestCycle = max(largestCycle, cycleLen);
                }
            }
        }
        return max(largestCycle, twoCycleAndLen);
    }
};