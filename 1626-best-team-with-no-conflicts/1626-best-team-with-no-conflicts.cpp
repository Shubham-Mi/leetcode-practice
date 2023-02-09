class Solution {
    int n;
    vector <pair <int, int>> players;
    vector <vector <int>> dp;
public:
    int findScore(int prev, int i) {
        if (i >= n) return 0;
        if (dp[prev + 1][i] != -1) return dp[prev + 1][i];
        dp[prev + 1][i] = findScore(prev, i + 1);
        if (prev == -1 || players[prev].second <= players[i].second) dp[prev + 1][i] = max(dp[prev + 1][i], players[i].second + findScore(i, i + 1));
        return dp[prev + 1][i];
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = scores.size();
        players.clear();
        dp = vector <vector <int>> (n, vector <int> (n, -1));
        for (int i=0; i<n; ++i) players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());
        return findScore(-1, 0);
    }
};