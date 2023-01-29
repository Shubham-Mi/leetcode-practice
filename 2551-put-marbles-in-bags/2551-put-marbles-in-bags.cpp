class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector <int> pairs;
        for (int i=1; i<n; ++i) {
            pairs.push_back(weights[i] + weights[i - 1]);
        }
        int m = pairs.size();
        sort(pairs.begin(), pairs.end());
        long long int ans = 0;
        for (int i=0; i<k-1; ++i) {
            ans = (1LL) * (ans + pairs[m - i - 1] - pairs[i]);
        }
        return ans;
    }
};