class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector <int> dp(n, 0);
        for (int i=0; i<n; ++i) {
            string curr = words[i];
            int p = curr.size();
            if ((curr[0] == 'a' || curr[0] == 'e' || curr[0] == 'i' || curr[0] == 'o' || curr[0] == 'u') && (curr[p - 1] == 'a' || curr[p - 1] == 'e' || curr[p - 1] == 'i' || curr[p - 1] == 'o' || curr[p - 1] == 'u')) dp[i] = 1;
            if (i > 0) dp[i] += dp[i - 1];
        }
        vector <int> ans;
        for (vector <int> query: queries) {
            int curr = dp[query[1]];
            if (query[0] > 0) curr -= dp[query[0] - 1];
            ans.push_back(curr);
        }
        return ans;
    }
};