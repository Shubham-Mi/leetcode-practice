class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int ans = -1;
        vector <pair <int, int>> distances(n, {-1, -1});
        for (int i=0; i<n; ++i) {
            int curr = i;
            int dist = 0;
            while (curr != -1) {
                if (distances[curr].first == -1) {
                    distances[curr] = {dist++, i};
                } else {
                    if (distances[curr].second == i) ans = max(ans, dist - distances[curr].first);
                    break;
                }
                curr = edges[curr];
            }
        }
        return ans;
    }
};