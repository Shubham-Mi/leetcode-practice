class Solution {
public:
    long long binpow(long long a, long long p, long long mod) {
        a %= mod;
        long long res = 1;
        while (p > 0) {
            if (p & 1)
                res = res * a % mod;
            a = a * a % mod;
            p >>= 1;
        }
        return res;
    }
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int count = 0;
        int st = -1;
        int ed = -1;
        for (auto range: ranges) {
            if (range[0] <= ed) {
                st = min(st, range[0]);
                ed = max(ed, range[1]);
            } else {
                count++;
                st = range[0];
                ed = range[1];
            }
        }
        return binpow(2, count, 1e9+7);
    }
};