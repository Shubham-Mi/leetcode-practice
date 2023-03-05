class Solution {
    int MOD = 1e9+7;
    vector <vector <vector <int>>> dp;
public:
    int solveDp(vector<vector<int>>& types, int target, int supply, int i) {
        if (target < 0 or supply < 0 or i < 0) return 0;
        if (target == 0) return 1;
        if (dp[i][target][supply] != -1) return dp[i][target][supply];
        int answer = 0;
        if (target - types[i][1] >= 0 and supply > 0) answer = solveDp(types, target - types[i][1], supply - 1, i) % MOD;
        if (i > 0) answer = (answer + solveDp(types, target, types[i - 1][0], i - 1)) % MOD;
        dp[i][target][supply] = answer % MOD;
        return answer;
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        int mxFreq = 0;
        for (auto type: types) {
            mxFreq = max(mxFreq, type[0]);
        }
        dp = vector <vector <vector <int>>> (n, vector <vector <int>> (target + 1, vector <int> (mxFreq + 1, -1)));
        return solveDp(types, target, types[n - 1][0], n - 1);
    }
};