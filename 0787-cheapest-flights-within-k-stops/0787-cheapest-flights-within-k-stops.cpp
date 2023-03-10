class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (src == dst) return 0;
        vector <int> prev(n, INT_MAX);
        vector <int> curr(n, INT_MAX);
        prev[src] = 0;
        for (int i=0; i<=k; ++i) {
            curr[src] = 0;
            for (vector <int> flight: flights) {
                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];
                if (prev[from] < INT_MAX) curr[to] = min(curr[to], prev[from] + cost);
            }
            prev = curr;
        }
        return curr[dst] == INT_MAX ? -1 : curr[dst];
    }
};