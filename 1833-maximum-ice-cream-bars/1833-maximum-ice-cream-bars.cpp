class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        for (int i=0; i<n; ++i) {
            if (costs[i] > coins) return i;
            coins -= costs[i];
        }
        return n;
    }
};