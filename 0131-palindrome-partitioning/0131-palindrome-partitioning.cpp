class Solution {
public:
    bool checkPalindrome(string s) {
        int low = 0;
        int high = s.size() - 1;
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
    void solve(string s, int i, int n, vector <string>& curr, vector<vector <string>>& ans, string str) {
        if (i == n) {
            if (str == "") ans.push_back(curr);
            return;
        }
        str += s[i];
        if (checkPalindrome(str)) {
            curr.push_back(str);
            solve(s, i + 1, n, curr, ans, "");
            curr.pop_back();
        }
        solve(s, i + 1, n, curr, ans, str);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector <string> curr;
        solve(s, 0, s.size(), curr, ans, "");
        return ans;
    }
};