class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector <int> dp(n, 0);
        for (int i=0; i<n; ++i) {
            if (i < n - 1 && prizePositions[i] == prizePositions[i + 1]) continue;
            int fstIdx = upper_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i] - k - 1) - prizePositions.begin();
            dp[i] = fstIdx;
        }
        int ans = 0;
        vector <int> mxDp(n, 0);
        int mx = 0;
        mxDp[0] = dp[0];
        for (int i=0; i<n; ++i) {
            if (i < n - 1 && prizePositions[i] == prizePositions[i + 1]) continue;
            if (dp[i] == 0) ans = max(ans, i + 1);
            else ans = max(ans, i - dp[i] + 1 + mxDp[dp[i] - 1]);
            mx = max(mx, i - dp[i] + 1);
            mxDp[i] = mx;
        }
        return ans;
    }
};