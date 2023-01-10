class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        int ans = 0;
        long long int curr = 0;
        for (int i=0; i<n; ++i) {
            curr = (1LL) * curr * 10 + (s[i] - '0');
            if (curr > k) {
                ans++;
                curr = s[i] - '0';
                if (curr > k) return -1;
            }
        }
        ans++;
        return ans;
    }
};