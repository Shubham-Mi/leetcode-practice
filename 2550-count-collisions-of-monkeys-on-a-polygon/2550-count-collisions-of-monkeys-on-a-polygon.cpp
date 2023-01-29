class Solution {
public:
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    int monkeyMove(int n) {
        long long int mod = 1e9+7;
        long long int ans = binpow(2, n, mod);
        ans = (ans - 2 + mod) % mod;
        return ans;
    }
};