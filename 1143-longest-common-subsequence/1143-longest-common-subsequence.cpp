class Solution {
    int n, m;
    vector <vector <int>> memo;
    string text1, text2;
public:
    int dp(int i, int j) {
        if (i == n || j == m) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        if (text1[i] == text2[j]) ans = 1 + dp(i + 1, j + 1);
        else ans = max(dp(i + 1, j), dp(i, j + 1));
        memo[i][j] = ans;
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        this->text1 = text1;
        this->text2 = text2;
        memo = vector <vector <int>> (n, vector <int> (m, -1));
        return dp(0, 0);
    }
};