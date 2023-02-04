class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        banned.push_back(1e9);
        int sum = 0;
        int ans = 0;
        int ptr = 0;
        int m = banned.size();
        for (int i=1; i<=n; ++i) {
            while (ptr < m && banned[ptr] < i) {
                ptr++;
            }
            if (banned[ptr] != i) {
                if ((sum + i) <= maxSum) {
                    sum += i;
                    ans++;
                }
                else break;
            }
        }
        return ans;
    }
};